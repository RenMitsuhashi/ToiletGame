#include "titletext.h"
#include "input.h"

//�O���[�o���ϐ�
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffTitleText = NULL;		//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureTitleText[TITLE_MAX] = {};	//�e�N�X�`���ւ̃|�C���^

D3DXVECTOR2 fPosStart = D3DXVECTOR2(0.0f, 0.0f), fPosEnd = D3DXVECTOR2(0.0f, 0.0f);
bool bOnceScan2 = false;		//��ʃ��Z�b�g������
bool bTitleStop2 = false;		//��ʈړ����~�߂���
int nTime96 = 0;				//96�J�E���g������
int nAlphaPressEnter = 0;		//PressEnter�̓��ߓx

//����������
void InitTitleText(void)
{
	LPDIRECT3DDEVICE9 pDevice;			//�f�o�C�X�̃|�C���^
	pDevice = GetDevice();				//�f�o�C�X���擾

	//�e�N�X�`���ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\00_sensei.png",			//�搶�I
		&g_pTextureTitleText[TITLE_SENSEI]);

	//�e�N�X�`���ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\01_toire.png",			//�g�C���ɍs���Ă�
		&g_pTextureTitleText[TITLE_TOILET]);

	//�e�N�X�`���ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\02_iidesuka.png",		//�����ł����I�H
		&g_pTextureTitleText[TITLE_IIDESU]);

	//�e�N�X�`���ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\04_title.png",			//�^�C�g��
		&g_pTextureTitleText[TITLE_MAIN]);

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * TITLE_MAX,	//�^�C�g���̂��
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffTitleText,
		NULL);

	VERTEX_2D *pVtx;	//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffTitleText->Lock(0, 0, (void**)&pVtx, 0);

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
	g_pVtxBuffTitleText->Unlock();

	fPosStart = D3DXVECTOR2(0.0f, 0.0f), fPosEnd = D3DXVECTOR2(0.0f, 0.0f);
	bOnceScan2 = false;
	bTitleStop2 = false;
	nTime96 = 0;
	nAlphaPressEnter = 0;
}

//�I������
void UninitTitleText(void)
{
	//�e�N�X�`���j��
	for (int nCnt = 0; nCnt < TITLE_MAX; nCnt++)
	{
		if (g_pTextureTitleText[nCnt] != NULL)
		{
			g_pTextureTitleText[nCnt]->Release();
			g_pTextureTitleText[nCnt] = NULL;
		}
	}

	//���_�o�b�t�@�j��
	if (g_pVtxBuffTitleText != NULL)
	{
		g_pVtxBuffTitleText->Release();
		g_pVtxBuffTitleText = NULL;
	}
}

//�X�V����
void UpdateTitleText(int num)
{
	//-----------------------
	//�e�N�X�`���̈ʒu�ݒ�
	if (bOnceScan2 == false)
	{
		fPosStart = D3DXVECTOR2(425.0f, 280.0f);
		fPosEnd = D3DXVECTOR2(425.0f, 280.0f);

		bOnceScan2 = true;
		bTitleStop2 = false;
		nTime96 = 0;
	}

	//-----------------------



	//-----------------------
	//��ʈړ�
	switch (num)
	{
	case TITLE_MAIN:
		if (bTitleStop2 == false)
		{
			fPosStart.x -= 20.0f;
			fPosStart.y -= 11.0f;
			fPosEnd.x += 20.0f;
			fPosEnd.y += 11.0f;

			if (fPosEnd.x >= 900.0f)
			{
				bTitleStop2 = true;
			}
		}

		else
		{

		}
		break;

	default:
		nTime96++;

		if (bTitleStop2 == false)
		{
			fPosStart.x -= 20.0f;
			fPosStart.y -= 10.0f;
			fPosEnd.x += 20.0f;
			fPosEnd.y += 10.0f;

			if (fPosEnd.x >= 800.0f)
			{
				bTitleStop2 = true;
			}
		}

		if (nTime96 >= 96)
		{
			bOnceScan2 = false;
		}
		break;
	}

	if (GetKeyboardTrigger(DIK_RETURN) == true)
	{
		if (num == TITLE_MAIN)
		{

		}

		else
		{
			bOnceScan2 = false;
		}
	}

	//-----------------------
	VERTEX_2D *pVtx;	//���_���ւ̃|�C���^

						//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffTitleText->Lock(0, 0, (void**)&pVtx, 0);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(fPosStart.x, fPosStart.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(fPosEnd.x, fPosStart.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(fPosStart.x, fPosEnd.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(fPosEnd.x, fPosEnd.y, 0.0f);

	//���_�o�b�t�@���A�����b�N
	g_pVtxBuffTitleText->Unlock();
}

//�`�揈��
void DrawTitleText(int num)
{
	if (bOnceScan2 == true)
	{
		LPDIRECT3DDEVICE9 pDevice;							//�f�o�C�X�̃|�C���^
		pDevice = GetDevice();								//�f�o�C�X���擾

		//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
		pDevice->SetStreamSource(
			0,
			g_pVtxBuffTitleText,
			0,
			sizeof(VERTEX_2D));

		pDevice->SetFVF(FVF_VERTEX_2D);						//���_�t�H�[�}�b�g�̐ݒ�
		pDevice->SetTexture(0, g_pTextureTitleText[num]);	//�e�N�X�`���̐ݒ�

		//�|���S���̕`��
		pDevice->DrawPrimitive(
			D3DPT_TRIANGLESTRIP,		//�v���~�e�B�u�̎��
			0,							//�J�n���钸�_�̃C���f�b�N�X
			2);							//�v���~�e�B�u�̐�
	}
}