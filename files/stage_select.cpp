#include "stage_select.h"
#include "input.h"
#include "databox.h"
#include "fade.h"

//�O���[�o���ϐ�
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffStageSelect = NULL;		//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureStageSelect[STAGE_MAX] = {};	//�e�N�X�`���ւ̃|�C���^
bool bLockSelect = false;

//����������
void InitStageSelect(void)
{
	LPDIRECT3DDEVICE9 pDevice;			//�f�o�C�X�̃|�C���^
	pDevice = GetDevice();				//�f�o�C�X���擾

	//�e�N�X�`���ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\10_tutorial.png",					//�`���[�g���A��
		&g_pTextureStageSelect[STAGE_TUTORIAL]);

	//�e�N�X�`���ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\11_school.png",						//�X�N�[��
		&g_pTextureStageSelect[STAGE_SCHOOL]);

	//�e�N�X�`���ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\12_city.png",						//�V�e�B
		&g_pTextureStageSelect[STAGE_CITY]);

	//�e�N�X�`���ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\13_home.png",						//�z�[��
		&g_pTextureStageSelect[STAGE_HOME]);

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffStageSelect,
		NULL);

	VERTEX_2D *pVtx;	//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffStageSelect->Lock(0, 0, (void**)&pVtx, 0);

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
	g_pVtxBuffStageSelect->Unlock();

	bLockSelect = false;
}

//�I������
void UninitStageSelect(void)
{
	for (int nCnt = 0; nCnt < STAGE_MAX; nCnt++)
	{
		//�e�N�X�`���j��
		if (g_pTextureStageSelect[nCnt] != NULL)
		{
			g_pTextureStageSelect[nCnt]->Release();
			g_pTextureStageSelect[nCnt] = NULL;
		}
	}

	//���_�o�b�t�@�j��
	if (g_pVtxBuffStageSelect != NULL)
	{
		g_pVtxBuffStageSelect->Release();
		g_pVtxBuffStageSelect = NULL;
	}
}

//�X�V����
void UpdateStageSelect(void)
{
	Data *pData;
	pData = GetData();

	if (bLockSelect == false)
	{
		if (GetKeyboardTrigger(DIK_DOWN) == true)	//��
		{
			pData->nStage++;

			if (pData->nStage > STAGE_HOME)	pData->nStage = STAGE_TUTORIAL;
		}

		if (GetKeyboardTrigger(DIK_UP) == true)		//��
		{
			pData->nStage--;

			if (pData->nStage < STAGE_TUTORIAL)	pData->nStage = STAGE_HOME;
		}
	}

	if (GetKeyboardTrigger(DIK_RETURN) == true)		//Enter
	{
		bLockSelect = true;
		SetFade(MODE_GAME);
	}
}

//�`�揈��
void DrawStageSelect(int num)
{
	LPDIRECT3DDEVICE9 pDevice;							//�f�o�C�X�̃|�C���^
	pDevice = GetDevice();								//�f�o�C�X���擾

	//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(
		0,
		g_pVtxBuffStageSelect,
		0,
		sizeof(VERTEX_2D));

	pDevice->SetFVF(FVF_VERTEX_2D);						//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetTexture(0, g_pTextureStageSelect[num]);	//�e�N�X�`���̐ݒ�

	//�|���S���̕`��
	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,		//�v���~�e�B�u�̎��
		0,							//�J�n���钸�_�̃C���f�b�N�X
		2);							//�v���~�e�B�u�̐�
}