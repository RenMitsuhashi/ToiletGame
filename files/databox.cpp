#include "databox.h"

Data g_Data;

void Initdata(void)
{
	g_Data.bPause = false;
	g_Data.aItem.nItem = ITEM_NONE;
	g_Data.aItem.nTime = 0;
	g_Data.aPlayer.nGage = 0;
	g_Data.aPlayer.nStamina = 0;
	g_Data.aPlayer.bKey = false;
	g_Data.aPlayer.nMoney = 0;
	g_Data.aPlayer.nMove = MOVE_STOP;
}

void Resetdata(void)
{
	g_Data.nStage = 0;
	g_Data.bPause = false;
	g_Data.aItem.nItem = ITEM_NONE;
	g_Data.aItem.nTime = 0;
	g_Data.aPlayer.nGage = 0;
	g_Data.aPlayer.nStamina = 0;
	g_Data.aPlayer.bKey = false;
	g_Data.aPlayer.nMoney = 0;
	g_Data.aPlayer.nMove = MOVE_STOP;

	for (int nCnt = 0; nCnt < STAGE_MAX; nCnt++)
	{
		g_Data.nStageRank[nCnt] = RANK_NONE;
	}
}

Data *GetData(void)
{
	return &g_Data;
}