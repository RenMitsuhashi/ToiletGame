#ifndef _TITLE_H_
#define _TITLE_H_

#include "main.h"

typedef enum
{
	TITLE_SENSEI = 0,	// 先生！
	TITLE_TOILET,		// トイレに行っても
	TITLE_IIDESU,		// いいですか！？
	TITLE_MAIN,			// タイトル画面のメイン
	TITLE_MAX
} TitleFade;

//プロトタイプ宣言
void InitTitle(void);		//初期化
void UninitTitle(void);		//終了
void UpdateTitle(void);		//更新
void DrawTitle(void);		//描画

#endif //_TITLE_H_