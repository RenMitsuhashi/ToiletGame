#include "PauseMenu.h"
#include "input.h"
#include "fade.h"
//#include "game.h"
#include "databox.h"
//#include "sound.h"

//�O���[�o���ϐ�
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffPauseMenu = NULL;		//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTexturePauseMenu[2] = {};			//�e�N�X�`���ւ̃|�C���^
int nCntPause = 0;
bool bLockPause = false;

//����������
void InitPauseMenu(void)
{
	LPDIRECT3DDEVICE9 pDevice;			//�f�o�C�X�̃|�C���^
	pDevice = GetDevice();				//�f�o�C�X���擾

		//�e�N�X�`���ǂݍ���
		D3DXCreateTextureFromFile(
			pDevice,
			"data\\texture\\pause00.png",
			&g_pTexturePauseMenu[0]);

		//�e�N�X�`���ǂݍ���
		D3DXCreateTextureFromFile(
			pDevice,
			"data\\texture\\pause01.png",
			&g_pTexturePauseMenu[1]);

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffPauseMenu,
		NULL);

	VERTEX_2D *pVtx;	//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffPauseMenu->Lock(0, 0, (void**)&pVtx, 0);

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
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N
	g_pVtxBuffPauseMenu->Unlock();

	nCntPause = 0;
	bLockPause = false;
}

//�I������
void UninitPauseMenu(void)
{
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		//�e�N�X�`���j��
		if (g_pTexturePauseMenu[nCnt] != NULL)
		{
			g_pTexturePauseMenu[nCnt]->Release();
			g_pTexturePauseMenu[nCnt] = NULL;
		}
	}

	//���_�o�b�t�@�j��
	if (g_pVtxBuffPauseMenu != NULL)
	{
		g_pVtxBuffPauseMenu->Release();
		g_pVtxBuffPauseMenu = NULL;
	}
}

//�X�V����
void UpdatePauseMenu(void)
{
	LPDIRECT3DDEVICE9 pDevice;			//�f�o�C�X�̃|�C���^
	pDevice = GetDevice();				//�f�o�C�X���擾

	Data *pData;
	pData = GetData();

	if (bLockPause == false)
	{
		if (GetKeyboardTrigger(DIK_UP) == true)
		{
			nCntPause++;
			//PlaySound(SOUND_LABEL_SECURSOR);

			if (nCntPause > 1)
			{
				nCntPause = 0;
			}
		}

		if (GetKeyboardTrigger(DIK_DOWN) == true)
		{
			nCntPause--;
			//PlaySound(SOUND_LABEL_SECURSOR);

			if (nCntPause < 0)
			{
				nCntPause = 1;
			}
		}

		if (GetKeyboardTrigger(DIK_RETURN) == true)
		{
			switch (nCntPause)
			{
			case 0:
				//PlaySound(SOUND_LABEL_SEENTER);
				pData->bPause = false;
				break;

			case 1:
				//StopSound();
				//PlaySound(SOUND_LABEL_SEENTER);
				SetFade(MODE_TITLE);
				bLockPause = true;
				break;
			}
		}

		if (GetKeyboardTrigger(DIK_ESCAPE) == true)
		{
			nCntPause = 0;
			pData->bPause = false;
		}
	}
}

//�`�揈��
void DrawPauseMenu(void)
{
	LPDIRECT3DDEVICE9 pDevice;							//�f�o�C�X�̃|�C���^
	pDevice = GetDevice();								//�f�o�C�X���擾

	//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(
		0,
		g_pVtxBuffPauseMenu,
		0,
		sizeof(VERTEX_2D));

	pDevice->SetFVF(FVF_VERTEX_2D);									//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetTexture(0, g_pTexturePauseMenu[nCntPause]);			//�e�N�X�`���̐ݒ�

	//�|���S���̕`��
	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,		//�v���~�e�B�u�̎��
		0,							//�J�n���钸�_�̃C���f�b�N�X
		2);							//�v���~�e�B�u�̐�
}