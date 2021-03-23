#include "stage_select_rank.h"
#include "input.h"
#include "databox.h"

typedef enum
{
	SCHOOL = 1,
	CITY,
	HOME,
	MAX
} Stage;

typedef struct
{
	float xStart = 1145, xEnd = 1245;
	float yStart, yEnd;
	bool bUse;
	float fSize = 50;
} Rank;

//グローバル変数
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffStageSelectRank = NULL;		//頂点バッファへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureStageSelectRank[MAX] = {};			//テクスチャへのポインタ
bool bLockSelectRank = false;
Rank g_aRank[MAX];

//初期化処理
void InitStageSelectRank(void)
{
	LPDIRECT3DDEVICE9 pDevice;			//デバイスのポインタ
	pDevice = GetDevice();				//デバイスを取得

	//テクスチャ読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\rank.png",
		&g_pTextureStageSelectRank[SCHOOL]);

	//テクスチャ読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\rank.png",
		&g_pTextureStageSelectRank[CITY]);

	//テクスチャ読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\rank.png",
		&g_pTextureStageSelectRank[HOME]);

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffStageSelectRank,
		NULL);

	VERTEX_2D *pVtx;					//頂点情報へのポインタ

	//頂点バッファをロックし、頂点データへのポインタを取得
	g_pVtxBuffStageSelectRank->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(0.0, 0.0, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDTH, 0.0, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0, SCREEN_HEIGHT, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f);

	//rhwの設定(1.0f固定)
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//頂点カラーの設定
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(0.0, 0.0);
	pVtx[1].tex = D3DXVECTOR2(1.0, 0.0);
	pVtx[2].tex = D3DXVECTOR2(0.0, 1.0);
	pVtx[3].tex = D3DXVECTOR2(1.0, 1.0);

	//頂点バッファをアンロック
	g_pVtxBuffStageSelectRank->Unlock();

	bLockSelectRank = false;

	g_aRank[SCHOOL].yStart = 310.0f;
	g_aRank[SCHOOL].yEnd = 410.0f;

	g_aRank[CITY].yStart = 447.5f;
	g_aRank[CITY].yEnd = 547.5f;

	g_aRank[HOME].yStart = 585.0f;
	g_aRank[HOME].yEnd = 685.0f;

	SetStageSelectRank();
}

//終了処理
void UninitStageSelectRank(void)
{
	//テクスチャ破棄
	for (int nCnt = 0; nCnt < MAX; nCnt++)
	{
		if (g_pTextureStageSelectRank[nCnt] != NULL)
		{
			g_pTextureStageSelectRank[nCnt]->Release();
			g_pTextureStageSelectRank[nCnt] = NULL;
		}
	}

	//頂点バッファ破棄
	if (g_pVtxBuffStageSelectRank != NULL)
	{
		g_pVtxBuffStageSelectRank->Release();
		g_pVtxBuffStageSelectRank = NULL;
	}
}

//更新処理
void UpdateStageSelectRank(void)
{

}

//描画処理
void DrawStageSelectRank(void)
{
	LPDIRECT3DDEVICE9 pDevice;							//デバイスのポインタ
	pDevice = GetDevice();								//デバイスを取得

	//頂点バッファをデバイスのデータストリームに設定
	pDevice->SetStreamSource(
		0,
		g_pVtxBuffStageSelectRank,
		0,
		sizeof(VERTEX_2D));

	pDevice->SetFVF(FVF_VERTEX_2D);						//頂点フォーマットの設定

	for (int nCnt = 1; nCnt < MAX; nCnt++)
	{
		if (g_aRank[nCnt].bUse == true)
		{
			pDevice->SetTexture(0, g_pTextureStageSelectRank[nCnt]);	//テクスチャの設定

			//ポリゴンの描画
			pDevice->DrawPrimitive(
				D3DPT_TRIANGLESTRIP,		//プリミティブの種類
				nCnt * 4,					//開始する頂点のインデックス
				2);							//プリミティブの数
		}
	}
}

void SetStageSelectRank(void)
{
	Data *pData;
	pData = GetData();

	VERTEX_2D *pVtx;					//頂点情報へのポインタ

	//頂点バッファをロックし、頂点データへのポインタを取得
	g_pVtxBuffStageSelectRank->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < MAX; nCnt++)
	{
		if(pData->nStageRank[nCnt] != RANK_NONE)	g_aRank[nCnt].bUse = true;

		//頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(g_aRank[nCnt].xStart, g_aRank[nCnt].yStart, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(g_aRank[nCnt].xEnd, g_aRank[nCnt].yStart, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(g_aRank[nCnt].xStart, g_aRank[nCnt].yEnd, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(g_aRank[nCnt].xEnd, g_aRank[nCnt].yEnd, 0.0f);

		//rhwの設定(1.0f固定)
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//頂点カラーの設定
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

		//テクスチャ座標の設定
		pVtx[0].tex = D3DXVECTOR2(pData->nStageRank[nCnt] * 0.2f - 0.2f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(pData->nStageRank[nCnt] * 0.2f - 0.2f + 0.2f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(pData->nStageRank[nCnt] * 0.2f - 0.2f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(pData->nStageRank[nCnt] * 0.2f - 0.2f + 0.2f, 1.0f);

		pVtx += 4;
	}
	//頂点バッファをアンロック
	g_pVtxBuffStageSelectRank->Unlock();
}