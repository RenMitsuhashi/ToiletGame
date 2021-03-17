#include "stage_select.h"
#include "input.h"
#include "databox.h"
#include "fade.h"

//グローバル変数
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffStageSelect = NULL;		//頂点バッファへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureStageSelect[STAGE_MAX] = {};	//テクスチャへのポインタ
bool bLockSelect = false;

//初期化処理
void InitStageSelect(void)
{
	LPDIRECT3DDEVICE9 pDevice;			//デバイスのポインタ
	pDevice = GetDevice();				//デバイスを取得

	//テクスチャ読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\10_tutorial.png",					//チュートリアル
		&g_pTextureStageSelect[STAGE_TUTORIAL]);

	//テクスチャ読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\11_school.png",						//スクール
		&g_pTextureStageSelect[STAGE_SCHOOL]);

	//テクスチャ読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\12_city.png",						//シティ
		&g_pTextureStageSelect[STAGE_CITY]);

	//テクスチャ読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\13_home.png",						//ホーム
		&g_pTextureStageSelect[STAGE_HOME]);

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffStageSelect,
		NULL);

	VERTEX_2D *pVtx;	//頂点情報へのポインタ

	//頂点バッファをロックし、頂点データへのポインタを取得
	g_pVtxBuffStageSelect->Lock(0, 0, (void**)&pVtx, 0);

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
	g_pVtxBuffStageSelect->Unlock();

	bLockSelect = false;
}

//終了処理
void UninitStageSelect(void)
{
	for (int nCnt = 0; nCnt < STAGE_MAX; nCnt++)
	{
		//テクスチャ破棄
		if (g_pTextureStageSelect[nCnt] != NULL)
		{
			g_pTextureStageSelect[nCnt]->Release();
			g_pTextureStageSelect[nCnt] = NULL;
		}
	}

	//頂点バッファ破棄
	if (g_pVtxBuffStageSelect != NULL)
	{
		g_pVtxBuffStageSelect->Release();
		g_pVtxBuffStageSelect = NULL;
	}
}

//更新処理
void UpdateStageSelect(void)
{
	Data *pData;
	pData = GetData();

	if (bLockSelect == false)
	{
		if (GetKeyboardTrigger(DIK_DOWN) == true)	//下
		{
			pData->nStage++;

			if (pData->nStage > STAGE_HOME)	pData->nStage = STAGE_TUTORIAL;
		}

		if (GetKeyboardTrigger(DIK_UP) == true)		//上
		{
			pData->nStage--;

			if (pData->nStage < STAGE_TUTORIAL)	pData->nStage = STAGE_HOME;
		}
	}

	if (GetKeyboardTrigger(DIK_RETURN) == true)		//Enter
	{
		bLockSelect = true;
		SetFade(MODE_GAME);
	}
}

//描画処理
void DrawStageSelect(int num)
{
	LPDIRECT3DDEVICE9 pDevice;							//デバイスのポインタ
	pDevice = GetDevice();								//デバイスを取得

	//頂点バッファをデバイスのデータストリームに設定
	pDevice->SetStreamSource(
		0,
		g_pVtxBuffStageSelect,
		0,
		sizeof(VERTEX_2D));

	pDevice->SetFVF(FVF_VERTEX_2D);						//頂点フォーマットの設定
	pDevice->SetTexture(0, g_pTextureStageSelect[num]);	//テクスチャの設定

	//ポリゴンの描画
	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,		//プリミティブの種類
		0,							//開始する頂点のインデックス
		2);							//プリミティブの数
}