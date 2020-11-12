#ifndef MAIN_H
#define MAIN_H

enum Phase
{
	kTitle,
	kBattle,
	kResult
};
Phase phase = kTitle;
Phase nextPhase;

Fade fade;
FadeType fadeType = kFadeNot;
FadeStatus fadeStatus = kDonotFade;
FadeSpeed fadeSpeed = kNormal;

#endif // !MAIN_H

