#ifndef _MAIN_H_
#define _MAIN_H_
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#define DIRECTINPUT_VERSION (0x0800)

#include <windows.h>
#include "d3dx9.h"
#include "dinput.h"
#include "xaudio2.h"
#include <stdio.h>

//���C�u�����̃����N
#pragma comment(lib,"d3d9.lib")			//�`��ɕK�v
#pragma comment(lib,"d3dx9.lib")		//[d3d9.lib]�̊g�����C�u����
#pragma comment(lib,"dxguid.lib")		//DirectX�R���|�[�l���g(���i�̃R�g)�g�p�ɕK�v
#pragma comment(lib,"dinput8.lib")		//���͏����ɕK�v
#pragma comment(lib,"winmm.lib")

//�}�N����`
#define SCREEN_WIDTH (1280)															//�E�B���h�E�̕�
#define SCREEN_HEIGHT (720)															//�E�B���h�E�̍���
#define FVF_VERTEX_2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)				//���_�t�H�[�}�b�g
#define FVF_VERTEX_3D (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1)	//���_�t�H�[�}�b�g

//�\���̒�`
typedef struct
{
	D3DXVECTOR3 pos;	//���_���W
	float rhw;			//1.0f�Œ�
	D3DCOLOR col;		//���_�J���[
	D3DXVECTOR2 tex;	//�e�N�X�`�����W
} VERTEX_2D;

typedef struct
{
	D3DXVECTOR3 pos;	//���_���W
	D3DXVECTOR3 nor;	//�@���x�N�g��
	D3DCOLOR col;		//���_�J���[
	D3DXVECTOR2 tex;	//�e�N�X�`�����W
} VERTEX_3D;

typedef enum
{
	MODE_TITLE = 0,
	MODE_STAGE_SELECT,
	MODE_GAME,
	MODE_RESULT,
	MODE_MAX
} MODE;

//�v���g�^�C�v�錾
LPDIRECT3DDEVICE9 GetDevice(void);
void SetMode(MODE mode);
MODE GetMode(void);

#endif //_MAIN_H_