#ifndef _TITLE_H_
#define _TITLE_H_

#include "main.h"

typedef enum
{
	TITLE_SENSEI = 0,	// �搶�I
	TITLE_TOILET,		// �g�C���ɍs���Ă�
	TITLE_IIDESU,		// �����ł����I�H
	TITLE_MAIN,			// �^�C�g����ʂ̃��C��
	TITLE_MAX
} TitleFade;

//�v���g�^�C�v�錾
void InitTitle(void);		//������
void UninitTitle(void);		//�I��
void UpdateTitle(void);		//�X�V
void DrawTitle(void);		//�`��

#endif //_TITLE_H_