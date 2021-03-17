#include "title.h"
#include "titletext.h"
#include "input.h"
#include "fade.h"

//�O���[�o���ϐ�
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffTitle = NULL;		//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureTitle = NULL;			//�e�N�X�`���ւ̃|�C���^

bool bLockTitle = false;		//��ʑJ�ڂ�2��ȏ�s��Ȃ��悤�Ƀ��b�N������
int nNumTitle = TITLE_SENSEI;	//���݂̉��o
bool bOnceScan = false;			//��ʃ��Z�b�g������
D3DXVECTOR2 fTexStart = D3DXVECTOR2(0.0f, 0.0f), fTexEnd = D3DXVECTOR2(0.0f, 0.0f);
bool bTitleStop = false;		//��ʈړ����~�߂���
int nTimeTitleStop = 0;			//���̉��o�܂ł̎���

//����������
void InitTitle(void)
{
	LPDIRECT3DDEVICE9 pDevice;			//�f�o�C�X�̃|�C���^
	pDevice = GetDevice();				//�f�o�C�X���擾

	//�e�N�X�`���ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\title.png",
		&g_pTextureTitle);

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffTitle,
		NULL);

	VERTEX_2D *pVtx;	//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffTitle->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(0.0, 0.0, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDTH, 0.0, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0, SCREEN_HEIGHT, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f);

	//rhw�̐ݒ�(1.0f�Œ�)
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0, 0.0);
	pVtx[1].tex = D3DXVECTOR2(1.0, 0.0);
	pVtx[2].tex = D3DXVECTOR2(0.0, 1.0);
	pVtx[3].tex = D3DXVECTOR2(1.0, 1.0);

	//���_�o�b�t�@���A�����b�N
	g_pVtxBuffTitle->Unlock();

	bLockTitle = false;
	bOnceScan = false;
	nNumTitle = TITLE_SENSEI;

	fTexStart = D3DXVECTOR2(0.0f, 0.0f), fTexEnd = D3DXVECTOR2(0.0f, 0.0f);
	nTimeTitleStop = 0;
	bTitleStop = false;

	InitTitleText();
}

//�I������
void UninitTitle(void)
{
	//�e�N�X�`���j��
	if (g_pTextureTitle != NULL)
	{
		g_pTextureTitle->Release();
		g_pTextureTitle = NULL;
	}

	//���_�o�b�t�@�j��
	if (g_pVtxBuffTitle != NULL)
	{
		g_pVtxBuffTitle->Release();
		g_pVtxBuffTitle = NULL;
	}

	UninitTitleText();
}

//�X�V����
void UpdateTitle(void)
{
	//-----------------------
	//�e�N�X�`���̈ʒu�ݒ�

	if (bOnceScan == false)
	{
		switch (nNumTitle)
		{
		case TITLE_SENSEI:							//�搶�I
			fTexStart = D3DXVECTOR2(0.0f, 0.0f);
			fTexEnd = D3DXVECTOR2(0.5f, 0.5f);
			bOnceScan = true;
			break;

		case TITLE_TOILET:							//�g�C���ɍs���Ă�
			fTexStart = D3DXVECTOR2(0.5f, 0.0f);
			fTexEnd = D3DXVECTOR2(0.9f, 0.4f);
			bOnceScan = true;
			break;

		case TITLE_IIDESU:							//�����ł����I�H
			fTexStart = D3DXVECTOR2(0.3f, 0.3f);
			fTexEnd = D3DXVECTOR2(0.9f, 0.9f);
			bOnceScan = true;
			break;

		case TITLE_MAIN:							//���C���^�C�g�����
			fTexStart = D3DXVECTOR2(0.75f, 0.75f);
			fTexEnd = D3DXVECTOR2(0.75f, 0.75f);
			bOnceScan = true;
			break;
		}
	}

	//-----------------------



	//-----------------------
	//��ʌ���

	switch (nNumTitle)
	{
	case TITLE_SENSEI:
		if (bTitleStop == false)
		{
			fTexStart.x += 0.0075f;
			fTexStart.y += 0.0075f;
			fTexEnd.x += 0.0075f;
			fTexEnd.y += 0.0075f;
		}

		if (fTexEnd.x >= 0.9f)
		{
			bTitleStop = true;
			nTimeTitleStop++;

			UpdateTitleText(nNumTitle);
		}

		if (nTimeTitleStop >= 96)
		{
			nTimeTitleStop = 0;
			nNumTitle++;
			bTitleStop = !bTitleStop;
			bOnceScan = false;
		}
		break;

	case TITLE_TOILET:
		if (bTitleStop == false)
		{
			fTexStart.y += 0.01f;
			fTexEnd.y += 0.01f;
		}

		if (fTexEnd.y >= 0.9f)
		{
			bTitleStop = true;
			nTimeTitleStop++;

			UpdateTitleText(nNumTitle);
		}

		if (nTimeTitleStop >= 96)
		{
			nTimeTitleStop = 0;
			nNumTitle++;
			bTitleStop = !bTitleStop;
			bOnceScan = false;
		}
		break;

	case TITLE_IIDESU:
		if (bTitleStop == false)
		{
			fTexStart.x += 0.005f;
			fTexStart.y += 0.005f;
		}

		if (fTexStart.y >= 0.5f)
		{
			bTitleStop = true;
			nTimeTitleStop++;

			UpdateTitleText(nNumTitle);
		}

		if (nTimeTitleStop >= 96)
		{
			nTimeTitleStop = 0;
			nNumTitle++;
			bTitleStop = !bTitleStop;
			bOnceScan = false;
		}
		break;

	case TITLE_MAIN:
		if (bTitleStop == false)
		{
			fTexStart.x -= 0.0075f;
			fTexStart.y -= 0.0075f;
			fTexEnd.x += 0.0025f;
			fTexEnd.y += 0.0025f;
		}

		if (fTexStart.y <= 0.1f)
		{
			bTitleStop = true;

			UpdateTitleText(nNumTitle);
		}

		if (bTitleStop == true)
		{

		}
		break;
	}

	//-----------------------

	if (GetKeyboardTrigger(DIK_RETURN) == true)
	{
		if (nNumTitle == TITLE_MAIN && bTitleStop == true)
		{
			bLockTitle = true;
			SetFade(MODE_STAGE_SELECT);
		}

		else
		{
			fTexStart = D3DXVECTOR2(0.1f, 0.1f);
			fTexEnd = D3DXVECTOR2(0.9f, 0.9f);

			nTimeTitleStop = 0;
			nNumTitle = TITLE_MAIN;
			bTitleStop = true;
			bOnceScan = true;
		}
	}

	VERTEX_2D *pVtx;	//���_���ւ̃|�C���^

						//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffTitle->Lock(0, 0, (void**)&pVtx, 0);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(fTexStart.x, fTexStart.y);
	pVtx[1].tex = D3DXVECTOR2(fTexEnd.x, fTexStart.y);
	pVtx[2].tex = D3DXVECTOR2(fTexStart.x, fTexEnd.y);
	pVtx[3].tex = D3DXVECTOR2(fTexEnd.x, fTexEnd.y);

	//���_�o�b�t�@���A�����b�N
	g_pVtxBuffTitle->Unlock();
}

//�`�揈��
void DrawTitle(void)
{
	LPDIRECT3DDEVICE9 pDevice;							//�f�o�C�X�̃|�C���^
	pDevice = GetDevice();								//�f�o�C�X���擾

	//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(
		0,
		g_pVtxBuffTitle,
		0,
		sizeof(VERTEX_2D));

	pDevice->SetFVF(FVF_VERTEX_2D);						//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetTexture(0, g_pTextureTitle);			//�e�N�X�`���̐ݒ�

	//�|���S���̕`��
	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,		//�v���~�e�B�u�̎��
		0,							//�J�n���钸�_�̃C���f�b�N�X
		2);							//�v���~�e�B�u�̐�

	if(bTitleStop == true)	DrawTitleText(nNumTitle);
}