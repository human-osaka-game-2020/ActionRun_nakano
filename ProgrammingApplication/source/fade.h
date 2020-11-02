#ifndef FADE_H
#define FADE_H

enum FadeType
{
	fadeNot,
	fadeIn,
	fadeOut,
	fadetype_max
};

enum fadeStatus
{
	donotFade,
	doingFade,
	finishedFadeIn,
	finishedFadeOut,
	fadestatus_max
};

enum FadeSpeed
{
	slow = 1,	//4.2s
	normal = 3,	//1.4s
	quick = 5,	//0.8s
	fadespeed_max
};

class Fade
{
public:
	/**
	 * @brief アルファー値の初期化
	 * @note フェード開始時にRunFade関数内で１度実行
	 */
	void InitFade(FadeType fade_type);

	/**
	 * @brief フェードタイプに応じてアルファー値の増減を行う関数
	 * @param fade_type フェードタイプ
	 * @param fade_speed フェードの速度
	 * @retval true フェード中
	 * @retval false フェード終了
	 * @note RunFade関数内で実行
	 */
	bool FluctuateAlpha(FadeType fade_type, FadeSpeed fade_speed);

	/**
	 * @brief フェード実行関数
	 * @param fade_type フェードタイプ
	 * @param fade_speed フェードの速度
	 * @retval donotFade フェードを行っていない
	 * @retval doingFade フェード中
	 * @retval finishedFadeIn フェードインの終了
	 * @retval finishedFadeOut フェードアウトの終了
	 */
	int RunFade(FadeType fade_type, FadeSpeed fade_speed);

	/**
	 * @brief フェード用矩形描画関数
	 */
	void DrawFade();

private:
	bool initCheck_Fade = false;
	int alpha = 0;
};

#endif // !FADE_H
