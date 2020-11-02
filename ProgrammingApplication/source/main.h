#ifndef MAIN_H
#define MAIN_H

enum Phase
{
	title,
	battle,
	result
};
Phase phase = title;
Phase nextPhase;

Fade fade;
FadeType fadeType = fadeNot;
FadeSpeed fadeSpeed = normal;

#endif // !MAIN_H

