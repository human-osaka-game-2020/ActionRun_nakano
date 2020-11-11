/**
 * @file fade.h
 * @brief フェード処理
 */

#ifndef FADE_H
#define FADE_H

 /**
  * @brief フェードタイプ
  */
enum FadeType
{
	//! フェードを行っていない
	fadeNot,
	//! フェードイン
	fadeIn,
	//! フェードアウト
	fadeOut,
	fadetype_max
};
/**
 * @brief フェードの状態
 */
enum FadeStatus
{
	//! フェードを行っていない
	donotFade,
	//! フェード中
	doingFade,
	//! フェードイン終了
	finishedFadeIn,
	//! フェードアウト終了
	finishedFadeOut,
	fadestatus_max
};
/**
 * @brief フェードの速度
 */
enum FadeSpeed
{
	//! 4.2s
	slow = 1,
	//! 1.4s
	normal = 3,
	//! 0.8s
	quick = 5,
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
