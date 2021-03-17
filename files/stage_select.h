#ifndef _STAGE_SELECT_H_
#define _STAGE_SELECT_H_

#include "main.h"

typedef enum
{
	STAGE_TUTORIAL = 0,	// �`���[�g���A��
	STAGE_SCHOOL,		// �X�N�[��
	STAGE_CITY,			// �V�e�B
	STAGE_HOME,			// �z�[��
	STAGE_MAX
} StageSelect;

//�v���g�^�C�v�錾
void InitStageSelect(void);		//������
void UninitStageSelect(void);	//�I��
void UpdateStageSelect(void);	//�X�V
void DrawStageSelect(int num);	//�`��

#endif //_STAGE_SELECT_H_