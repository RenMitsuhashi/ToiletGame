#ifndef _TITLETEXT_H_
#define _TITLETEXT_H_

#include "main.h"
#include "title.h"

//プロトタイプ宣言
void InitTitleText(void);		//初期化
void UninitTitleText(void);		//終了
void UpdateTitleText(int num);	//更新処理
void DrawTitleText(int num);	//描画

#endif //_TITLETEXT_H_