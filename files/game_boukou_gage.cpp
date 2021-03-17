#include "game_boukou_gage.h"
#include "fade.h"
#include "input.h"
#include "databox.h"

//�O���[�o���ϐ�
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBoukouGage = NULL;	//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureBoukouGage = NULL;			//�e�N�X�`���ւ̃|�C���^
int nFrameCount = 0;									//���t���[��1�����A60�t���[����nSecCount��1����
int nSecCount = 0;										//���b1�����A200��MAX
int nColor = 255;										//�΁A�̐F��
int nOne = 5;											//�v�Z�p
bool bLockBoukouGage = false;

//����������
void InitBoukouGage(void)
{
	LPDIRECT3DDEVICE9 pDevice;			//�f�o�C�X�̃|�C���^
	pDevice = GetDevice();				//�f�o�C�X���擾

	//�e�N�X�`���ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\boukou_gage.png",
		&g_pTextureBoukouGage);

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffBoukouGage,
		NULL);

	VERTEX_2D *pVtx;	//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffBoukouGage->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(25.0, 675.0, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(175.0, 675.0, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(25.0, 675.0, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(175.0, 675.0, 0.0f);

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
	g_pVtxBuffBoukouGage->Unlock();

	nFrameCount = 0;
	nSecCount = 0;
	nColor = 255;
	nOne = 5;
	bLockBoukouGage = false;
}

//�I������
void UninitBoukouGage(void)
{
	//�e�N�X�`���j��
	if (g_pTextureBoukouGage != NULL)
	{
		g_pTextureBoukouGage->Release();
		g_pTextureBoukouGage = NULL;
	}

	//���_�o�b�t�@�j��
	if (g_pVtxBuffBoukouGage != NULL)
	{
		g_pVtxBuffBoukouGage->Release();
		g_pVtxBuffBoukouGage= NULL;
	}
}

//�X�V����
void UpdateBoukouGage(void)
{
	Data *pData;
	pData = GetData();

	if (nSecCount >= 200)
	{
		nFrameCount = 0;
		nSecCount = 200;
		SetFade(MODE_STAGE_SELECT);

		bLockBoukouGage = true;
	}

	if (pData->aPlayer.nMove == MOVE_DASH)
	{
		nSecCount++;
	}

	else
	{
		nFrameCount++;

		if (nFrameCount >= 60)
		{
			nFrameCount = 0;
			nSecCount++;
		}

		if (nSecCount >= 185)		//185�b�o�߂̉��o
		{
			nColor += nOne;

			if (nColor <= 0)	nOne *= -1, nColor = 0;
			if (nColor >= 255)	nOne *= -1, nColor = 255;

			nColor += nOne;
		}

		else if (nSecCount >= 150)	//150�b�o�߂̉��o
		{
			if (nColor <= 192)	nOne *= -1, nColor = 192;
			if (nColor >= 255)	nOne *= -1, nColor = 255;

			nColor += (nOne / 3);
		}
	}

	VERTEX_2D *pVtx;	//���_���ւ̃|�C���^

						//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffBoukouGage->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(25.0f, 675.0f - (float)nSecCount, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(175.0f, 675.0f - (float)nSecCount, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(25.0f, 675.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(175.0f, 675.0f, 0.0f);

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DCOLOR_RGBA(255, nColor, nColor, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, nColor, nColor, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, nColor, nColor, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, nColor, nColor, 255);

	//���_�o�b�t�@���A�����b�N
	g_pVtxBuffBoukouGage->Unlock();
}

//�`�揈��
void DrawBoukouGage(void)
{
	LPDIRECT3DDEVICE9 pDevice;							//�f�o�C�X�̃|�C���^
	pDevice = GetDevice();								//�f�o�C�X���擾

	//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(
		0,
		g_pVtxBuffBoukouGage,
		0,
		sizeof(VERTEX_2D));

	pDevice->SetFVF(FVF_VERTEX_2D);						//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetTexture(0, g_pTextureBoukouGage);			//�e�N�X�`���̐ݒ�

	//�|���S���̕`��
	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,		//�v���~�e�B�u�̎��
		0,							//�J�n���钸�_�̃C���f�b�N�X
		2);							//�v���~�e�B�u�̐�
}