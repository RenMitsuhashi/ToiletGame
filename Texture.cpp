#include "Texture.h"

#define MAX_NUM_TEXTURE (60)
#define MAX_TEXTURE_TEXTURE (40)

typedef struct{
	int nType;
	int nPosType;
	bool bUse;
	float fPosX, fPosY;
	float fWidth, fHeight;
	D3DXCOLOR col;
} Texture;

LPDIRECT3DTEXTURE9 g_apTextureTexture[MAX_TEXTURE_TEXTURE] = {}; //テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffTexture = NULL; //頂点バッファへのポインタ
Texture g_aTexture[MAX_NUM_TEXTURE];

void InitTexture(void) {
	LPDIRECT3DDEVICE9 pDevice;
	VERTEX_2D *pVtx; //頂点情報へのポインタ
	pDevice = GetDevice();

	for (int nCntTexture = 0; nCntTexture < MAX_NUM_TEXTURE; nCntTexture++) {
		g_aTexture[nCntTexture].bUse = false;
		g_aTexture[nCntTexture].nPosType = TEXTUREPOS_FRONT;
		g_aTexture[nCntTexture].nType = NULL;
	}

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"",
		&g_apTextureTexture[TEXTURETYPE_NULL]);
	D3DXCreateTextureFromFile(pDevice,
		"",
		&g_apTextureTexture[TEXTURETYPE_NULLFRONT]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/titlebg.png",
		&g_apTextureTexture[TEXTURETYPE_TITLEBG]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/title.png",
		&g_apTextureTexture[TEXTURETYPE_TITLETEXT]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/button_a.png",
		&g_apTextureTexture[TEXTURETYPE_BUTTON_A]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/button_b.png",
		&g_apTextureTexture[TEXTURETYPE_BUTTON_B]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/button_x.png",
		&g_apTextureTexture[TEXTURETYPE_BUTTON_X]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/button_rt.png",
		&g_apTextureTexture[TEXTURETYPE_BUTTON_RT]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/button_start.png",
		&g_apTextureTexture[TEXTURETYPE_BUTTON_START]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/level_1.png",
		&g_apTextureTexture[TEXTURETYPE_LEVEL_1]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/level_2.png",
		&g_apTextureTexture[TEXTURETYPE_LEVEL_2]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/level_3.png",
		&g_apTextureTexture[TEXTURETYPE_LEVEL_3]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/level_4.png",
		&g_apTextureTexture[TEXTURETYPE_LEVEL_4]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/level_max.png",
		&g_apTextureTexture[TEXTURETYPE_LEVEL_MAX]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/score_frame.png",
		&g_apTextureTexture[TEXTURETYPE_SCOREFRAME]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/level_gauge.png",
		&g_apTextureTexture[TEXTURETYPE_EXP]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/pause_menu.png",
		&g_apTextureTexture[TEXTURETYPE_PAUSEMENU]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/pause_arrow.png",
		&g_apTextureTexture[TEXTURETYPE_PAUSEARROW]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/title_gamestart.png",
		&g_apTextureTexture[TEXTURETYPE_TITLESTART]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/title_tutorial.png",
		&g_apTextureTexture[TEXTURETYPE_TITLETUTORIAL]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/title_quit.png",
		&g_apTextureTexture[TEXTURETYPE_TITLEQUIT]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/timeup.png",
		&g_apTextureTexture[TEXTURETYPE_TIMEUP]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/resultbg.jpg",
		&g_apTextureTexture[TEXTURETYPE_RESULTBG]);
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ranking.png",
		&g_apTextureTexture[TEXTURETYPE_RANKING]);

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_NUM_TEXTURE,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffTexture,
		NULL);

	//頂点バッファをロックし、頂点データへのポインタを取得
	g_pVtxBuffTexture->Lock(0, 0, (void**)&pVtx, 0);
	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);
	//頂点バッファをアンロックする
	g_pVtxBuffTexture->Unlock();
}

void UninitTexture(void) {
	//テクスチャの破棄
	for (int nCntTexture = 0; nCntTexture < MAX_TEXTURE_TEXTURE; nCntTexture++) {
		if (g_apTextureTexture[nCntTexture] != NULL) {
			g_apTextureTexture[nCntTexture]->Release();
			g_apTextureTexture[nCntTexture] = NULL;
		}
	}

	//頂点バッファの破棄
	if (g_pVtxBuffTexture != NULL) {
		g_pVtxBuffTexture->Release();
		g_pVtxBuffTexture = NULL;
	}
}

void UpdateTexture(void) {

}

void DrawTexture(int ntype) {
	LPDIRECT3DDEVICE9 pDevice; //デバイスのポインタ

	pDevice = GetDevice(); //デバイスを取得する

	//頂点バッファをデバイスのデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffTexture, 0, sizeof(VERTEX_2D));
	pDevice->SetFVF(FVF_VERTEX_2D); //頂点フォーマットの設定

	for (int nCntTexture = 0; nCntTexture < MAX_NUM_TEXTURE; nCntTexture++) {
		if (g_aTexture[nCntTexture].bUse == true && g_aTexture[nCntTexture].nPosType == ntype) {
			//テクスチャ
			pDevice->SetTexture(0, g_apTextureTexture[g_aTexture[nCntTexture].nType]);
			//ポリゴンの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, //プリミティブの種類
				nCntTexture * 4,
				2);
		}
	}
}

int SetTexture(int ntype, float posX, float posY, float fWidth, float fHeight, D3DXCOLOR col) {
	VERTEX_2D *pVtx; //頂点情報へのポインタ

	g_pVtxBuffTexture->Lock(0, 0, (void**)&pVtx, 0);
	for (int nCntTexture = 0; nCntTexture < MAX_NUM_TEXTURE; nCntTexture++) {
		if (g_aTexture[nCntTexture].bUse == false) {
			g_aTexture[nCntTexture].nType = ntype;
			if (ntype == TEXTURETYPE_TITLEBG || ntype == TEXTURETYPE_RESULTBG) {
				g_aTexture[nCntTexture].nPosType = TEXTUREPOS_BACK;
			}
			if (ntype == TEXTURETYPE_PAUSEMENU || ntype == TEXTURETYPE_PAUSEARROW || ntype == TEXTURETYPE_NULLFRONT) {
				g_aTexture[nCntTexture].nPosType = TEXTUREPOS_PAUSE;
			}
			g_aTexture[nCntTexture].fPosX = posX;
			g_aTexture[nCntTexture].fPosY = posY;
			g_aTexture[nCntTexture].fWidth = fWidth;
			g_aTexture[nCntTexture].fHeight = fHeight;
			g_aTexture[nCntTexture].col = col;

			//頂点バッファをロックし、頂点データへのポインタを取得
			pVtx[0].pos = D3DXVECTOR3(posX, posY, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(posX + fWidth, posY, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(posX, posY + fHeight, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(posX + fWidth, posY + fHeight, 0.0f);

			pVtx[0].rhw = 1.0f;
			pVtx[1].rhw = 1.0f;
			pVtx[2].rhw = 1.0f;
			pVtx[3].rhw = 1.0f;

			pVtx[0].col = col;
			pVtx[1].col = col;
			pVtx[2].col = col;
			pVtx[3].col = col;

			pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
			pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
			pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
			pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

			g_pVtxBuffTexture->Unlock();
			
			g_aTexture[nCntTexture].bUse = true;

			return nCntTexture;
		}
		pVtx += 4;
	}
}

void DeleteTexture(int nIdx) {
	if (nIdx == -1) {
		for (int nCntTexture = 0; nCntTexture < MAX_NUM_TEXTURE; nCntTexture++) {
			g_aTexture[nCntTexture].bUse = false;
			g_aTexture[nCntTexture].nPosType = TEXTUREPOS_FRONT;
		}
	}
	else {
		g_aTexture[nIdx].bUse = false;
	}
}

void SetPosTexture(int nIdx, float fPosX, float fPosY) {
	VERTEX_2D *pVtx; //頂点情報へのポインタ
	g_aTexture[nIdx].fPosX = fPosX;
	g_aTexture[nIdx].fPosY = fPosY;

	g_pVtxBuffTexture->Lock(0, 0, (void**)&pVtx, 0);

	pVtx += nIdx * 4;
	
	pVtx[0].pos = D3DXVECTOR3(fPosX, fPosY, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(fPosX + g_aTexture[nIdx].fWidth, fPosY, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(fPosX, fPosY + g_aTexture[nIdx].fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(fPosX + g_aTexture[nIdx].fWidth, fPosY + g_aTexture[nIdx].fHeight, 0.0f);

	g_pVtxBuffTexture->Unlock();
}

void SetSizeTexture(int nIdx, float fWidth, float fHeight) {
	VERTEX_2D *pVtx; //頂点情報へのポインタ
	g_aTexture[nIdx].fWidth = fWidth;
	g_aTexture[nIdx].fHeight = fHeight;

	g_pVtxBuffTexture->Lock(0, 0, (void**)&pVtx, 0);

	pVtx += nIdx * 4;
	
	pVtx[0].pos = D3DXVECTOR3(g_aTexture[nIdx].fPosX, g_aTexture[nIdx].fPosY, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(g_aTexture[nIdx].fPosX + fWidth, g_aTexture[nIdx].fPosY, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(g_aTexture[nIdx].fPosX, g_aTexture[nIdx].fPosY + fHeight, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(g_aTexture[nIdx].fPosX + fWidth, g_aTexture[nIdx].fPosY + fHeight, 0.0f);

	g_pVtxBuffTexture->Unlock();
}

void SetColTexture(int nIdx, D3DXCOLOR col) {
	VERTEX_2D *pVtx; //頂点情報へのポインタ
	g_aTexture[nIdx].col = col;

	g_pVtxBuffTexture->Lock(0, 0, (void**)&pVtx, 0);

	pVtx += nIdx * 4;

	pVtx[0].col = col;
	pVtx[1].col = col;
	pVtx[2].col = col;
	pVtx[3].col = col;

	g_pVtxBuffTexture->Unlock();
}

void SetTypeTexture(int nIdx, int ntype) {
	g_aTexture[nIdx].nType = ntype;
}