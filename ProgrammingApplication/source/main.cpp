#include "common.h"

void  GameProcessing();
void DrawProcessing();

int WINAPI WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, 
	int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(640, 480, 16);
	SetWindowText("run");
	
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	while (true)
	{
		// ���b�Z�[�W���[�v�ɑ��鏈��������
		if (ProcessMessage() == -1 ||
			CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;        // �G���[���N�����烋�[�v�𔲂���
		}
		else
		{
			//�Q�[������
			GameProcessing();
			
			ClearDrawScreen();
			clsDx();
			//�`�揈��
			DrawProcessing();
			ScreenFlip();
		}
	}

	DxLib_End();	// �c�w���C�u�����g�p�̏I������
	return 0;		// �\�t�g�̏I�� 
}

void  GameProcessing()
{

}

void DrawProcessing()
{

}