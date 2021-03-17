#include "game_stamina_gage.h"
#include "input.h"
#include "databox.h"

//グローバル変数
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffStaminaGage = NULL;	//頂点バッファへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureStaminaGage = NULL;		//テクスチャへのポインタ
int nFrameCount2 = 0;									//毎フレーム1増加、60フレームでnStaminaCountを1増加
int nStaminaCount = 0;									//走ると減少
bool bStaminaHeal = false;								//スタミナを使い切った後、再使用できるまでtrue
int nColor2 = 255;										//緑、青の色調
int nOne2 = 5;											//計算用

//初期化処理
void InitStaminaGage(void)
{
	LPDIRECT3DDEVICE9 pDevice;			//デバイスのポインタ
	pDevice = GetDevice();				//デバイスを取得

	//テクスチャ読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\stamina_gage.png",
		&g_pTextureStaminaGage);

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffStaminaGage,
		NULL);

	VERTEX_2D *pVtx;	//頂点情報へのポインタ

	//頂点バッファをロックし、頂点データへのポインタを取得
	g_pVtxBuffStaminaGage->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(3.0, 687.0, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(192.0, 687.0, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(3.0, 717.0, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(192.0, 717.0, 0.0f);

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
	g_pVtxBuffStaminaGage->Unlock();

	nFrameCount2 = 0;
	nStaminaCount = 100;
	bStaminaHeal = false;
	nColor2 = 255;
	nOne2 = 5;
}

//終了処理
void UninitStaminaGage(void)
{
	//テクスチャ破棄
	if (g_pTextureStaminaGage != NULL)
	{
		g_pTextureStaminaGage->Release();
		g_pTextureStaminaGage = NULL;
	}

	//頂点バッファ破棄
	if (g_pVtxBuffStaminaGage != NULL)
	{
		g_pVtxBuffStaminaGage->Release();
		g_pVtxBuffStaminaGage= NULL;
	}
}

//更新処理
void UpdateStaminaGage(void)
{
	Data *pData;
	pData = GetData();

	if (GetKeyboardPress(DIK_LSHIFT) == true && bStaminaHeal == false)
	{
		nStaminaCount--;
		pData->aPlayer.nMove = MOVE_DASH;

		if (nStaminaCount <= 0)
		{
			bStaminaHeal = true;
			nStaminaCount = 0;
			pData->aPlayer.nMove = MOVE_WALK;
		}
	}

	else
	{
		nFrameCount2++;

		if (nFrameCount2 >= 8)
		{
			nFrameCount2 = 0;
			nStaminaCount++;
		}

		if (nStaminaCount >= 190)
		{
			bStaminaHeal = false;
			nStaminaCount = 190;
		}

		pData->aPlayer.nMove = MOVE_WALK;
	}

	if (bStaminaHeal == true)
	{
		if (nColor2 <= 0)	nOne2 *= -1, nColor2 = 0;
		if (nColor2 >= 255)	nOne2 *= -1, nColor2 = 255;

		nColor2 += nOne2;
	}

	VERTEX_2D *pVtx;	//頂点情報へのポインタ

						//頂点バッファをロックし、頂点データへのポインタを取得
	g_pVtxBuffStaminaGage->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(3.0f, 688.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(3.0f + (float)nStaminaCount, 688.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(3.0f, 716.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(3.0f + (float)nStaminaCount, 716.0f, 0.0f);

	//頂点カラーの設定
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, nColor2);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, nColor2);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, nColor2);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, nColor2);

	//頂点バッファをアンロック
	g_pVtxBuffStaminaGage->Unlock();
}

//描画処理
void DrawStaminaGage(void)
{
	LPDIRECT3DDEVICE9 pDevice;							//デバイスのポインタ
	pDevice = GetDevice();								//デバイスを取得

	//頂点バッファをデバイスのデータストリームに設定
	pDevice->SetStreamSource(
		0,
		g_pVtxBuffStaminaGage,
		0,
		sizeof(VERTEX_2D));

	pDevice->SetFVF(FVF_VERTEX_2D);						//頂点フォーマットの設定
	pDevice->SetTexture(0, g_pTextureStaminaGage);			//テクスチャの設定

	//ポリゴンの描画
	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,		//プリミティブの種類
		0,							//開始する頂点のインデックス
		2);							//プリミティブの数
}