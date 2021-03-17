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

//�A�C�e���Ǘ�++++++++++++++++++++++++++

typedef enum
{
	ITEM_NONE = 0,	//�A�C�e���Ȃ�
	ITEM_CIDER,		//�T�C�_�[
	ITEM_SPORTS,	//�X�|�[�c
	ITEM_ENERGY,	//�G�i�W�[
	ITEM_MAX
}ItemType;			//�A�C�e���̎��

typedef struct
{
	int nItem;		//�A�C�e���̎��(ItemType)
	int nTime;		//�c��g�p����
}Item;

//---------------------------------



//�v���C���[�Ǘ�++++++++++++++++++++++++

typedef enum
{
	MOVE_STOP = 0,	//�Î~
	MOVE_WALK,		//���s
	MOVE_DASH,		//���s
	MOVE_PUNCH,		//�\��
	MOVE_MAX
}PleyerMove;		//�v���C���[�̓���

typedef struct
{
	int nGage;		//�N���Q�[�W�̗�(1�b��1�����AMAX180)
	int nStamina;	//�X�^�~�i�̗�
	bool bKey;		//�������L���Ă��邩�ǂ���
	int nMoney;		//�c��
	int nMove;		//���݂̍s��(PlayerMove)
}Player;

//---------------------------------



//�����f�[�^++++++++++++++++++++++++++++

typedef struct
{
	int nStage;		//�X�e�[�W�ԍ�
	int nStageRank[STAGE_MAX];	//�X�e�[�W���Ƃ̍ō������N
	bool bPause;	//�|�[�Y
	Item aItem;		//�A�C�e���Ǘ�
	Player aPlayer;	//�v���C���[�Ǘ�
}Data;

//---------------------------------

//�v���g�^�C�v�錾
void Initdata(void);		//������
Data *GetData(void);

#endif //_DATABOX_H_