#ifndef _DATABOX_H_
#define _DATABOX_H_

#include "main.h"
#include "stage_select.h"

typedef enum
{
	RANK_NONE = 0,
	RANK_D,
	RANK_C,
	RANK_B,
	RANK_A,
	RANK_S,
	RANK_MAX
}StageRank;

//アイテム管理++++++++++++++++++++++++++

typedef enum
{
	ITEM_NONE = 0,	//アイテムなし
	ITEM_CIDER,		//サイダー
	ITEM_SPORTS,	//スポーツ
	ITEM_ENERGY,	//エナジー
	ITEM_MAX
}ItemType;			//アイテムの種類

typedef struct
{
	int nItem;		//アイテムの種類(ItemType)
	int nTime;		//残り使用時間
}Item;

//---------------------------------



//プレイヤー管理++++++++++++++++++++++++

typedef enum
{
	MOVE_STOP = 0,	//静止
	MOVE_WALK,		//歩行
	MOVE_DASH,		//走行
	MOVE_PUNCH,		//暴力
	MOVE_MAX
}PleyerMove;		//プレイヤーの動作

typedef struct
{
	int nGage;		//膀胱ゲージの量(1秒に1増加、MAX180)
	int nStamina;	//スタミナの量
	bool bKey;		//鍵を所有しているかどうか
	int nMoney;		//残金
	int nMove;		//現在の行動(PlayerMove)
}Player;

//---------------------------------



//総括データ++++++++++++++++++++++++++++

typedef struct
{
	int nStage;		//ステージ番号
	int nStageRank[STAGE_MAX];	//ステージごとの最高ランク
	bool bPause;	//ポーズ
	Item aItem;		//アイテム管理
	Player aPlayer;	//プレイヤー管理
}Data;

//---------------------------------

//プロトタイプ宣言
void Initdata(void);		//初期化
Data *GetData(void);

#endif //_DATABOX_H_