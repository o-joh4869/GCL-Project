#include <DxLib.h>
#include"Input/Manager.h"
#include"Input/Key.h"
#include"Time/Manager.h"
#include"Sequence/Manager.h"
#include"MyGlobal.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤�ɐݒ�
	ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
	SetGraphMode(gWindowSize.x, gWindowSize.y, 32);//��ʃT�C�Y�w��
	SetMainWindowText("sample");//�E�C���h�E�ɕ\�������^�C�g�����w��
	SetAlwaysRunFlag(TRUE);//��A�N�e�B�u���������𑱍s
	if (DxLib_Init() == -1) { return -1; }//�������Ɏ��s���ɃG���[��f�����ďI��
	SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�
	SetWindowSizeChangeEnableFlag(TRUE); //�E�B���h�E�����R�Ɋg��k���ł���悤�ɐݒ�
	SetDrawMode(DX_DRAWMODE_BILINEAR); //�g��k���ŕ��ׂ��d�����Ă��ꂢ�ɕ`��ł���悤�ɂ���

	Sequence::Manager seqManager;

	while (ProcessMessage() == 0) {
		ClearDrawScreen();
		Time::Manager::update();
		Input::Manager::update();

		seqManager.update();
		if (Input::gKey[KEY_INPUT_ESCAPE] == -1) break;
		ScreenFlip();
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}