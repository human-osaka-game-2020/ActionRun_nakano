#include "common.h"
#include "main.h"

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
	SetBackgroundColor(255, 255, 255);
	
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	while (true)
	{
		// メッセージループに代わる処理をする
		if (ProcessMessage() == -1 ||
			CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;        // エラーが起きたらループを抜ける
		}
		else
		{
			//ゲーム処理
			GameProcessing();
			
			ClearDrawScreen();
			clsDx();
			//描画処理
			DrawProcessing();
			ScreenFlip();
		}
	}

	DxLib_End();	// ＤＸライブラリ使用の終了処理
	return 0;		// ソフトの終了 
}

void  GameProcessing()
{
	switch (fade.RunFade(fadeType, fadeSpeed))
	{
	case kFinishedFadeOut:
		fadeType = kFadeIn;
		phase = nextPhase;
		break;
	case kFinishedFadeIn:
		fadeType = kFadeNot;
		break;
	}

	switch (phase)
	{
	case kTitle:
		if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			fadeType = kFadeOut;
			nextPhase = kBattle;
			fadeSpeed = kSlow;
		}
		break;
	case kBattle:
		if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			fadeType = kFadeOut;
			nextPhase = kResult;
			fadeSpeed = kNormal;
		}
		break;
	case kResult:
		if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			fadeType = kFadeOut;
			nextPhase = kTitle;
			fadeSpeed = kQuick;
		}
		break;
	}
}

void DrawProcessing()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	switch (phase)
	{
	case kTitle:
		DrawString(0, 0, "title", GetColor(255, 0, 0));
		break;
	case kBattle:
		DrawString(0, 0, "battle", GetColor(255, 0, 0));
		break;
	case kResult:
		DrawString(0, 0, "result", GetColor(255, 0, 0));
		break;
	}
	fade.Draw();
}
