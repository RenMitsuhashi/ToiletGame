#include "title.h"
#include "titletext.h"
#include "input.h"
#include "fade.h"

//グローバル変数
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffTitle = NULL;		//頂点バッファへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureTitle = NULL;			//テクスチャへのポインタ

bool bLockTitle = false;		//画面遷移を2回以上行わないようにロックするやつ
int nNumTitle = TITLE_SENSEI;	//現在の演出
bool bOnceScan = false;			//画面リセットするやつ
D3DXVECTOR2 fTexStart = D3DXVECTOR2(0.0f, 0.0f), fTexEnd = D3DXVECTOR2(0.0f, 0.0f);
bool bTitleStop = false;		//画面移動を止めるやつ
int nTimeTitleStop = 0;			//次の演出までの時間

//初期化処理
void InitTitle(void)
{
	LPDIRECT3DDEVICE9 pDevice;			//デバイスのポインタ
	pDevice = GetDevice();				//デバイスを取得

	//テクスチャ読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\title.png",
		&g_pTextureTitle);

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffTitle,
		NULL);

	VERTEX_2D *pVtx;	//頂点情報へのポインタ

	//頂点バッファをロックし、頂点データへのポインタを取得
	g_pVtxBuffTitle->Lock(0, 0, (void**)&pVtx, 0);

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
	g_pVtxBuffTitle->Unlock();

	bLockTitle = false;
	bOnceScan = false;
	nNumTitle = TITLE_SENSEI;

	fTexStart = D3DXVECTOR2(0.0f, 0.0f), fTexEnd = D3DXVECTOR2(0.0f, 0.0f);
	nTimeTitleStop = 0;
	bTitleStop = false;

	InitTitleText();
}

//終了処理
void UninitTitle(void)
{
	//テクスチャ破棄
	if (g_pTextureTitle != NULL)
	{
		g_pTextureTitle->Release();
		g_pTextureTitle = NULL;
	}

	//頂点バッファ破棄
	if (g_pVtxBuffTitle != NULL)
	{
		g_pVtxBuffTitle->Release();
		g_pVtxBuffTitle = NULL;
	}

	UninitTitleText();
}

//更新処理
void UpdateTitle(void)
{
	//-----------------------
	//テクスチャの位置設定

	if (bOnceScan == false)
	{
		switch (nNumTitle)
		{
		case TITLE_SENSEI:							//先生！
			fTexStart = D3DXVECTOR2(0.0f, 0.0f);
			fTexEnd = D3DXVECTOR2(0.5f, 0.5f);
			bOnceScan = true;
			break;

		case TITLE_TOILET:							//トイレに行っても
			fTexStart = D3DXVECTOR2(0.5f, 0.0f);
			fTexEnd = D3DXVECTOR2(0.9f, 0.4f);
			bOnceScan = true;
			break;

		case TITLE_IIDESU:							//いいですか！？
			fTexStart = D3DXVECTOR2(0.3f, 0.3f);
			fTexEnd = D3DXVECTOR2(0.9f, 0.9f);
			bOnceScan = true;
			break;

		case TITLE_MAIN:							//メインタイトル画面
			fTexStart = D3DXVECTOR2(0.75f, 0.75f);
			fTexEnd = D3DXVECTOR2(0.75f, 0.75f);
			bOnceScan = true;
			break;
		}
	}

	//-----------------------



	//-----------------------
	//画面効果

	switch (nNumTitle)
	{
	case TITLE_SENSEI:
		if (bTitleStop == false)
		{
			fTexStart.x += 0.0075f;
			fTexStart.y += 0.0075f;
			fTexEnd.x += 0.0075f;
			fTexEnd.y += 0.0075f;
		}

		if (fTexEnd.x >= 0.9f)
		{
			bTitleStop = true;
			nTimeTitleStop++;

			UpdateTitleText(nNumTitle);
		}

		if (nTimeTitleStop >= 96)
		{
			nTimeTitleStop = 0;
			nNumTitle++;
			bTitleStop = !bTitleStop;
			bOnceScan = false;
		}
		break;

	case TITLE_TOILET:
		if (bTitleStop == false)
		{
			fTexStart.y += 0.01f;
			fTexEnd.y += 0.01f;
		}

		if (fTexEnd.y >= 0.9f)
		{
			bTitleStop = true;
			nTimeTitleStop++;

			UpdateTitleText(nNumTitle);
		}

		if (nTimeTitleStop >= 96)
		{
			nTimeTitleStop = 0;
			nNumTitle++;
			bTitleStop = !bTitleStop;
			bOnceScan = false;
		}
		break;

	case TITLE_IIDESU:
		if (bTitleStop == false)
		{
			fTexStart.x += 0.005f;
			fTexStart.y += 0.005f;
		}

		if (fTexStart.y >= 0.5f)
		{
			bTitleStop = true;
			nTimeTitleStop++;

			UpdateTitleText(nNumTitle);
		}

		if (nTimeTitleStop >= 96)
		{
			nTimeTitleStop = 0;
			nNumTitle++;
			bTitleStop = !bTitleStop;
			bOnceScan = false;
		}
		break;

	case TITLE_MAIN:
		if (bTitleStop == false)
		{
			fTexStart.x -= 0.0075f;
			fTexStart.y -= 0.0075f;
			fTexEnd.x += 0.0025f;
			fTexEnd.y += 0.0025f;
		}

		if (fTexStart.y <= 0.1f)
		{
			bTitleStop = true;

			UpdateTitleText(nNumTitle);
		}

		if (bTitleStop == true)
		{

		}
		break;
	}

	//-----------------------

	if (GetKeyboardTrigger(DIK_RETURN) == true)
	{
		if (nNumTitle == TITLE_MAIN && bTitleStop == true)
		{
			bLockTitle = true;
			SetFade(MODE_STAGE_SELECT);
		}

		else
		{
			fTexStart = D3DXVECTOR2(0.1f, 0.1f);
			fTexEnd = D3DXVECTOR2(0.9f, 0.9f);

			nTimeTitleStop = 0;
			nNumTitle = TITLE_MAIN;
			bTitleStop = true;
			bOnceScan = true;
		}
	}

	VERTEX_2D *pVtx;	//頂点情報へのポインタ

						//頂点バッファをロックし、頂点データへのポインタを取得
	g_pVtxBuffTitle->Lock(0, 0, (void**)&pVtx, 0);

	//テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(fTexStart.x, fTexStart.y);
	pVtx[1].tex = D3DXVECTOR2(fTexEnd.x, fTexStart.y);
	pVtx[2].tex = D3DXVECTOR2(fTexStart.x, fTexEnd.y);
	pVtx[3].tex = D3DXVECTOR2(fTexEnd.x, fTexEnd.y);

	//頂点バッファをアンロック
	g_pVtxBuffTitle->Unlock();
}

//描画処理
void DrawTitle(void)
{
	LPDIRECT3DDEVICE9 pDevice;							//デバイスのポインタ
	pDevice = GetDevice();								//デバイスを取得

	//頂点バッファをデバイスのデータストリームに設定
	pDevice->SetStreamSource(
		0,
		g_pVtxBuffTitle,
		0,
		sizeof(VERTEX_2D));

	pDevice->SetFVF(FVF_VERTEX_2D);						//頂点フォーマットの設定
	pDevice->SetTexture(0, g_pTextureTitle);			//テクスチャの設定

	//ポリゴンの描画
	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,		//プリミティブの種類
		0,							//開始する頂点のインデックス
		2);							//プリミティブの数

	if(bTitleStop == true)	DrawTitleText(nNumTitle);
}