#include "game_boukou_gage.h"
#include "fade.h"
#include "input.h"
#include "databox.h"

//グローバル変数
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBoukouGage = NULL;	//頂点バッファへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureBoukouGage = NULL;			//テクスチャへのポインタ
int nFrameCount = 0;									//毎フレーム1増加、60フレームでnSecCountを1増加
int nSecCount = 0;										//毎秒1増加、200でMAX
int nColor = 255;										//緑、青の色調
int nOne = 5;											//計算用
bool bLockBoukouGage = false;

//初期化処理
void InitBoukouGage(void)
{
	LPDIRECT3DDEVICE9 pDevice;			//デバイスのポインタ
	pDevice = GetDevice();				//デバイスを取得

	//テクスチャ読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\boukou_gage.png",
		&g_pTextureBoukouGage);

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffBoukouGage,
		NULL);

	VERTEX_2D *pVtx;	//頂点情報へのポインタ

	//頂点バッファをロックし、頂点データへのポインタを取得
	g_pVtxBuffBoukouGage->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(25.0, 675.0, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(175.0, 675.0, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(25.0, 675.0, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(175.0, 675.0, 0.0f);

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
	g_pVtxBuffBoukouGage->Unlock();

	nFrameCount = 0;
	nSecCount = 0;
	nColor = 255;
	nOne = 5;
	bLockBoukouGage = false;
}

//終了処理
void UninitBoukouGage(void)
{
	//テクスチャ破棄
	if (g_pTextureBoukouGage != NULL)
	{
		g_pTextureBoukouGage->Release();
		g_pTextureBoukouGage = NULL;
	}

	//頂点バッファ破棄
	if (g_pVtxBuffBoukouGage != NULL)
	{
		g_pVtxBuffBoukouGage->Release();
		g_pVtxBuffBoukouGage= NULL;
	}
}

//更新処理
void UpdateBoukouGage(void)
{
	Data *pData;
	pData = GetData();

	if (nSecCount >= 200)
	{
		nFrameCount = 0;
		nSecCount = 200;
		SetFade(MODE_STAGE_SELECT);

		bLockBoukouGage = true;
	}

	if (pData->aPlayer.nMove == MOVE_DASH)
	{
		nSecCount++;
	}

	else
	{
		nFrameCount++;

		if (nFrameCount >= 60)
		{
			nFrameCount = 0;
			nSecCount++;
		}

		if (nSecCount >= 185)		//185秒経過の演出
		{
			nColor += nOne;

			if (nColor <= 0)	nOne *= -1, nColor = 0;
			if (nColor >= 255)	nOne *= -1, nColor = 255;

			nColor += nOne;
		}

		else if (nSecCount >= 150)	//150秒経過の演出
		{
			if (nColor <= 192)	nOne *= -1, nColor = 192;
			if (nColor >= 255)	nOne *= -1, nColor = 255;

			nColor += (nOne / 3);
		}
	}

	VERTEX_2D *pVtx;	//頂点情報へのポインタ

						//頂点バッファをロックし、頂点データへのポインタを取得
	g_pVtxBuffBoukouGage->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(25.0f, 675.0f - (float)nSecCount, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(175.0f, 675.0f - (float)nSecCount, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(25.0f, 675.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(175.0f, 675.0f, 0.0f);

	//頂点カラーの設定
	pVtx[0].col = D3DCOLOR_RGBA(255, nColor, nColor, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, nColor, nColor, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, nColor, nColor, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, nColor, nColor, 255);

	//頂点バッファをアンロック
	g_pVtxBuffBoukouGage->Unlock();
}

//描画処理
void DrawBoukouGage(void)
{
	LPDIRECT3DDEVICE9 pDevice;							//デバイスのポインタ
	pDevice = GetDevice();								//デバイスを取得

	//頂点バッファをデバイスのデータストリームに設定
	pDevice->SetStreamSource(
		0,
		g_pVtxBuffBoukouGage,
		0,
		sizeof(VERTEX_2D));

	pDevice->SetFVF(FVF_VERTEX_2D);						//頂点フォーマットの設定
	pDevice->SetTexture(0, g_pTextureBoukouGage);			//テクスチャの設定

	//ポリゴンの描画
	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,		//プリミティブの種類
		0,							//開始する頂点のインデックス
		2);							//プリミティブの数
}