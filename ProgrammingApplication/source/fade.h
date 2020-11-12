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
	kFadeNot,
	//! フェードイン
	kFadeIn,
	//! フェードアウト
	kFadeOut,
};

/**
 * @brief フェードの状態
 */
enum FadeStatus
{
	//! フェードを行っていない
	kDonotFade,
	//! フェード中
	kDoingFade,
	//! フェードイン終了
	kFinishedFadeIn,
	//! フェードアウト終了
	kFinishedFadeOut,
};

/**
 * @brief フェードの速度
 */
enum FadeSpeed
{
	//! 4.2s
	kSlow = 1,
	//! 1.4s
	kNormal = 3,
	//! 0.8s
	kQuick = 5,
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
	bool MakeToFluctuateAlpha(FadeType fade_type, FadeSpeed fade_speed);

	/**
	 * @brief フェード実行関数
	 * @param fade_type フェードタイプ
	 * @param fade_speed フェードの速度
	 * @return FadeStatus フェードの状態
	 */
	FadeStatus RunFade(FadeType fade_type, FadeSpeed fade_speed);

	/**
	 * @brief フェード用矩形描画関数
	 */
	void Draw();

private:
	bool initCheck_Fade = false;
	int alpha = 0;
};

#endif // !FADE_H
