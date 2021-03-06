#include <DxLib.h>
#include"Input/Manager.h"
#include"Input/Key.h"
#include"Time/Manager.h"
#include"Sequence/Manager.h"
#include"MyGlobal.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);//Log.txtを生成しないように設定
	ChangeWindowMode(TRUE);//非全画面にセット
	SetGraphMode(gWindowSize.x, gWindowSize.y, 32);//画面サイズ指定
	SetMainWindowText("sample");//ウインドウに表示されるタイトルを指定
	SetAlwaysRunFlag(TRUE);//非アクティブ時も処理を続行
	if (DxLib_Init() == -1) { return -1; }//初期化に失敗時にエラーを吐かせて終了
	SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に
	SetWindowSizeChangeEnableFlag(TRUE); //ウィンドウを自由に拡大縮小できるように設定
	SetDrawMode(DX_DRAWMODE_BILINEAR); //拡大縮小で負荷を重くしてきれいに描画できるようにする

	Sequence::Manager seqManager;

	while (ProcessMessage() == 0) {
		ClearDrawScreen();
		Time::Manager::update();
		Input::Manager::update();

		seqManager.update();
		if (Input::gKey[KEY_INPUT_ESCAPE] == -1) break;
		ScreenFlip();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}