/**
 * @file main.h
 * @brief mainで使う定義
 */

#ifndef MAIN_H
#define MAIN_H

/**
* @brief シーンの状態
*/
enum Phase
{
	//! タイトルシーン
	kTitle,
	//! バトルシーン
	kAction,
	//! リザルトシーン
	kResult
};
Phase phase = kTitle;
Phase nextPhase;

Fade fade;
FadeType fadeType = kFadeNot;
FadeStatus fadeStatus = kDonotFade;
FadeSpeed fadeSpeed = kNormal;

#endif // !MAIN_H

