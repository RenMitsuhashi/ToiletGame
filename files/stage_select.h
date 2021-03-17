#ifndef _STAGE_SELECT_H_
#define _STAGE_SELECT_H_

#include "main.h"

typedef enum
{
	STAGE_TUTORIAL = 0,	// チュートリアル
	STAGE_SCHOOL,		// スクール
	STAGE_CITY,			// シティ
	STAGE_HOME,			// ホーム
	STAGE_MAX
} StageSelect;

//プロトタイプ宣言
void InitStageSelect(void);		//初期化
void UninitStageSelect(void);	//終了
void UpdateStageSelect(void);	//更新
void DrawStageSelect(int num);	//描画

#endif //_STAGE_SELECT_H_