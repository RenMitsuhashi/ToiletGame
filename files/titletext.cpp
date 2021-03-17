#include "titletext.h"
#include "input.h"

//グローバル変数
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffTitleText = NULL;		//頂点バッファへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureTitleText[TITLE_MAX] = {};	//テクスチャへのポインタ

D3DXVECTOR2 fPosStart = D3DXVECTOR2(0.0f, 0.0f), fPosEnd = D3DXVECTOR2(0.0f, 0.0f);
bool bOnceScan2 = false;		//画面リセットするやつ
bool bTitleStop2 = false;		//画面移動を止めるやつ
int nTime96 = 0;				//96カウントするやつ
int nAlphaPressEnter = 0;		//PressEnterの透過度

//初期化処理
void InitTitleText(void)
{
	LPDIRECT3DDEVICE9 pDevice;			//デバイスのポインタ
	pDevice = GetDevice();				//デバイスを取得

	//テクスチャ読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\00_sensei.png",			//先生！
		&g_pTextureTitleText[TITLE_SENSEI]);

	//テクスチャ読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\01_toire.png",			//トイレに行っても
		&g_pTextureTitleText[TITLE_TOILET]);

	//テクスチャ読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\02_iidesuka.png",		//いいですか！？
		&g_pTextureTitleText[TITLE_IIDESU]);

	//テクスチャ読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\04_title.png",			//タイトル
		&g_pTextureTitleText[TITLE_MAIN]);

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * TITLE_MAX,	//タイトルのやつ
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffTitleText,
		NULL);

	VERTEX_2D *pVtx;	//頂点情報へのポインタ

	//頂点バッファをロックし、頂点データへのポインタを取得
	g_pVtxBuffTitleText->Lock(0, 0, (void**)&pVtx, 0);

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
	g_pVtxBuffTitleText->Unlock();

	fPosStart = D3DXVECTOR2(0.0f, 0.0f), fPosEnd = D3DXVECTOR2(0.0f, 0.0f);
	bOnceScan2 = false;
	bTitleStop2 = false;
	nTime96 = 0;
	nAlphaPressEnter = 0;
}

//終了処理
void UninitTitleText(void)
{
	//テクスチャ破棄
	for (int nCnt = 0; nCnt < TITLE_MAX; nCnt++)
	{
		if (g_pTextureTitleText[nCnt] != NULL)
		{
			g_pTextureTitleText[nCnt]->Release();
			g_pTextureTitleText[nCnt] = NULL;
		}
	}

	//頂点バッファ破棄
	if (g_pVtxBuffTitleText != NULL)
	{
		g_pVtxBuffTitleText->Release();
		g_pVtxBuffTitleText = NULL;
	}
}

//更新処理
void UpdateTitleText(int num)
{
	//-----------------------
	//テクスチャの位置設定
	if (bOnceScan2 == false)
	{
		fPosStart = D3DXVECTOR2(425.0f, 280.0f);
		fPosEnd = D3DXVECTOR2(425.0f, 280.0f);

		bOnceScan2 = true;
		bTitleStop2 = false;
		nTime96 = 0;
	}

	//-----------------------



	//-----------------------
	//画面移動
	switch (num)
	{
	case TITLE_MAIN:
		if (bTitleStop2 == false)
		{
			fPosStart.x -= 20.0f;
			fPosStart.y -= 11.0f;
			fPosEnd.x += 20.0f;
			fPosEnd.y += 11.0f;

			if (fPosEnd.x >= 900.0f)
			{
				bTitleStop2 = true;
			}
		}

		else
		{

		}
		break;

	default:
		nTime96++;

		if (bTitleStop2 == false)
		{
			fPosStart.x -= 20.0f;
			fPosStart.y -= 10.0f;
			fPosEnd.x += 20.0f;
			fPosEnd.y += 10.0f;

			if (fPosEnd.x >= 800.0f)
			{
				bTitleStop2 = true;
			}
		}

		if (nTime96 >= 96)
		{
			bOnceScan2 = false;
		}
		break;
	}

	if (GetKeyboardTrigger(DIK_RETURN) == true)
	{
		if (num == TITLE_MAIN)
		{

		}

		else
		{
			bOnceScan2 = false;
		}
	}

	//-----------------------
	VERTEX_2D *pVtx;	//頂点情報へのポインタ

						//頂点バッファをロックし、頂点データへのポインタを取得
	g_pVtxBuffTitleText->Lock(0, 0, (void**)&pVtx, 0);

	//テクスチャ座標の設定
	pVtx[0].pos = D3DXVECTOR3(fPosStart.x, fPosStart.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(fPosEnd.x, fPosStart.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(fPosStart.x, fPosEnd.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(fPosEnd.x, fPosEnd.y, 0.0f);

	//頂点バッファをアンロック
	g_pVtxBuffTitleText->Unlock();
}

//描画処理
void DrawTitleText(int num)
{
	if (bOnceScan2 == true)
	{
		LPDIRECT3DDEVICE9 pDevice;							//デバイスのポインタ
		pDevice = GetDevice();								//デバイスを取得

		//頂点バッファをデバイスのデータストリームに設定
		pDevice->SetStreamSource(
			0,
			g_pVtxBuffTitleText,
			0,
			sizeof(VERTEX_2D));

		pDevice->SetFVF(FVF_VERTEX_2D);						//頂点フォーマットの設定
		pDevice->SetTexture(0, g_pTextureTitleText[num]);	//テクスチャの設定

		//ポリゴンの描画
		pDevice->DrawPrimitive(
			D3DPT_TRIANGLESTRIP,		//プリミティブの種類
			0,							//開始する頂点のインデックス
			2);							//プリミティブの数
	}
}