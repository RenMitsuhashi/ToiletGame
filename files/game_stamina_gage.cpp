#include "game_stamina_gage.h"
#include "input.h"
#include "databox.h"

//�O���[�o���ϐ�
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffStaminaGage = NULL;	//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureStaminaGage = NULL;		//�e�N�X�`���ւ̃|�C���^
int nFrameCount2 = 0;									//���t���[��1�����A60�t���[����nStaminaCount��1����
int nStaminaCount = 0;									//����ƌ���
bool bStaminaHeal = false;								//�X�^�~�i���g���؂�����A�Ďg�p�ł���܂�true
int nColor2 = 255;										//�΁A�̐F��
int nOne2 = 5;											//�v�Z�p

//����������
void InitStaminaGage(void)
{
	LPDIRECT3DDEVICE9 pDevice;			//�f�o�C�X�̃|�C���^
	pDevice = GetDevice();				//�f�o�C�X���擾

	//�e�N�X�`���ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\stamina_gage.png",
		&g_pTextureStaminaGage);

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffStaminaGage,
		NULL);

	VERTEX_2D *pVtx;	//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffStaminaGage->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(3.0, 687.0, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(192.0, 687.0, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(3.0, 717.0, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(192.0, 717.0, 0.0f);

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
	g_pVtxBuffStaminaGage->Unlock();

	nFrameCount2 = 0;
	nStaminaCount = 100;
	bStaminaHeal = false;
	nColor2 = 255;
	nOne2 = 5;
}

//�I������
void UninitStaminaGage(void)
{
	//�e�N�X�`���j��
	if (g_pTextureStaminaGage != NULL)
	{
		g_pTextureStaminaGage->Release();
		g_pTextureStaminaGage = NULL;
	}

	//���_�o�b�t�@�j��
	if (g_pVtxBuffStaminaGage != NULL)
	{
		g_pVtxBuffStaminaGage->Release();
		g_pVtxBuffStaminaGage= NULL;
	}
}

//�X�V����
void UpdateStaminaGage(void)
{
	Data *pData;
	pData = GetData();

	if (GetKeyboardPress(DIK_LSHIFT) == true && bStaminaHeal == false)
	{
		nStaminaCount--;
		pData->aPlayer.nMove = MOVE_DASH;

		if (nStaminaCount <= 0)
		{
			bStaminaHeal = true;
			nStaminaCount = 0;
			pData->aPlayer.nMove = MOVE_WALK;
		}
	}

	else
	{
		nFrameCount2++;

		if (nFrameCount2 >= 8)
		{
			nFrameCount2 = 0;
			nStaminaCount++;
		}

		if (nStaminaCount >= 190)
		{
			bStaminaHeal = false;
			nStaminaCount = 190;
		}

		pData->aPlayer.nMove = MOVE_WALK;
	}

	if (bStaminaHeal == true)
	{
		if (nColor2 <= 0)	nOne2 *= -1, nColor2 = 0;
		if (nColor2 >= 255)	nOne2 *= -1, nColor2 = 255;

		nColor2 += nOne2;
	}

	VERTEX_2D *pVtx;	//���_���ւ̃|�C���^

						//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffStaminaGage->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(3.0f, 688.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(3.0f + (float)nStaminaCount, 688.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(3.0f, 716.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(3.0f + (float)nStaminaCount, 716.0f, 0.0f);

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, nColor2);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, nColor2);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, nColor2);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, nColor2);

	//���_�o�b�t�@���A�����b�N
	g_pVtxBuffStaminaGage->Unlock();
}

//�`�揈��
void DrawStaminaGage(void)
{
	LPDIRECT3DDEVICE9 pDevice;							//�f�o�C�X�̃|�C���^
	pDevice = GetDevice();								//�f�o�C�X���擾

	//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(
		0,
		g_pVtxBuffStaminaGage,
		0,
		sizeof(VERTEX_2D));

	pDevice->SetFVF(FVF_VERTEX_2D);						//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetTexture(0, g_pTextureStaminaGage);			//�e�N�X�`���̐ݒ�

	//�|���S���̕`��
	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,		//�v���~�e�B�u�̎��
		0,							//�J�n���钸�_�̃C���f�b�N�X
		2);							//�v���~�e�B�u�̐�
}