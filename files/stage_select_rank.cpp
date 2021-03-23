#include "stage_select_rank.h"
#include "input.h"
#include "databox.h"

typedef enum
{
	SCHOOL = 1,
	CITY,
	HOME,
	MAX
} Stage;

typedef struct
{
	float xStart = 1145, xEnd = 1245;
	float yStart, yEnd;
	bool bUse;
	float fSize = 50;
} Rank;

//�O���[�o���ϐ�
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffStageSelectRank = NULL;		//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureStageSelectRank[MAX] = {};			//�e�N�X�`���ւ̃|�C���^
bool bLockSelectRank = false;
Rank g_aRank[MAX];

//����������
void InitStageSelectRank(void)
{
	LPDIRECT3DDEVICE9 pDevice;			//�f�o�C�X�̃|�C���^
	pDevice = GetDevice();				//�f�o�C�X���擾

	//�e�N�X�`���ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\rank.png",
		&g_pTextureStageSelectRank[SCHOOL]);

	//�e�N�X�`���ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\rank.png",
		&g_pTextureStageSelectRank[CITY]);

	//�e�N�X�`���ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"data\\texture\\rank.png",
		&g_pTextureStageSelectRank[HOME]);

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffStageSelectRank,
		NULL);

	VERTEX_2D *pVtx;					//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffStageSelectRank->Lock(0, 0, (void**)&pVtx, 0);

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
	g_pVtxBuffStageSelectRank->Unlock();

	bLockSelectRank = false;

	g_aRank[SCHOOL].yStart = 310.0f;
	g_aRank[SCHOOL].yEnd = 410.0f;

	g_aRank[CITY].yStart = 447.5f;
	g_aRank[CITY].yEnd = 547.5f;

	g_aRank[HOME].yStart = 585.0f;
	g_aRank[HOME].yEnd = 685.0f;

	SetStageSelectRank();
}

//�I������
void UninitStageSelectRank(void)
{
	//�e�N�X�`���j��
	for (int nCnt = 0; nCnt < MAX; nCnt++)
	{
		if (g_pTextureStageSelectRank[nCnt] != NULL)
		{
			g_pTextureStageSelectRank[nCnt]->Release();
			g_pTextureStageSelectRank[nCnt] = NULL;
		}
	}

	//���_�o�b�t�@�j��
	if (g_pVtxBuffStageSelectRank != NULL)
	{
		g_pVtxBuffStageSelectRank->Release();
		g_pVtxBuffStageSelectRank = NULL;
	}
}

//�X�V����
void UpdateStageSelectRank(void)
{

}

//�`�揈��
void DrawStageSelectRank(void)
{
	LPDIRECT3DDEVICE9 pDevice;							//�f�o�C�X�̃|�C���^
	pDevice = GetDevice();								//�f�o�C�X���擾

	//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(
		0,
		g_pVtxBuffStageSelectRank,
		0,
		sizeof(VERTEX_2D));

	pDevice->SetFVF(FVF_VERTEX_2D);						//���_�t�H�[�}�b�g�̐ݒ�

	for (int nCnt = 1; nCnt < MAX; nCnt++)
	{
		if (g_aRank[nCnt].bUse == true)
		{
			pDevice->SetTexture(0, g_pTextureStageSelectRank[nCnt]);	//�e�N�X�`���̐ݒ�

			//�|���S���̕`��
			pDevice->DrawPrimitive(
				D3DPT_TRIANGLESTRIP,		//�v���~�e�B�u�̎��
				nCnt * 4,					//�J�n���钸�_�̃C���f�b�N�X
				2);							//�v���~�e�B�u�̐�
		}
	}
}

void SetStageSelectRank(void)
{
	Data *pData;
	pData = GetData();

	VERTEX_2D *pVtx;					//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffStageSelectRank->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < MAX; nCnt++)
	{
		if(pData->nStageRank[nCnt] != RANK_NONE)	g_aRank[nCnt].bUse = true;

		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(g_aRank[nCnt].xStart, g_aRank[nCnt].yStart, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(g_aRank[nCnt].xEnd, g_aRank[nCnt].yStart, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(g_aRank[nCnt].xStart, g_aRank[nCnt].yEnd, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(g_aRank[nCnt].xEnd, g_aRank[nCnt].yEnd, 0.0f);

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
		pVtx[0].tex = D3DXVECTOR2(pData->nStageRank[nCnt] * 0.2f - 0.2f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(pData->nStageRank[nCnt] * 0.2f - 0.2f + 0.2f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(pData->nStageRank[nCnt] * 0.2f - 0.2f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(pData->nStageRank[nCnt] * 0.2f - 0.2f + 0.2f, 1.0f);

		pVtx += 4;
	}
	//���_�o�b�t�@���A�����b�N
	g_pVtxBuffStageSelectRank->Unlock();
}