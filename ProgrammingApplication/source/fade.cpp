#include "common.h"

void Fade::InitFade(FadeType fade_type)
{
	switch (fade_type)
	{
	case fadeOut:
		alpha = 0;
		break;
	case fadeIn:
		alpha = 255;
		break;
	}
	initCheck_Fade = true;
}

bool Fade::FluctuateAlpha(FadeType fade_type, FadeSpeed fade_speed)
{
	switch (fade_type)
	{
	case fadeOut:
		alpha += fade_speed;
		break;
	case fadeIn:
		alpha -= fade_speed;
		break;
	}
	if (alpha == 255 || alpha == 0)
	{
		return false;
	}
	return true;
}

int Fade::RunFade(FadeType fade_type, FadeSpeed fade_speed)
{
	if (fade_type == fadeNot)
	{
		return donotFade;
	}

	if (!initCheck_Fade)
	{
		InitFade(fade_type);
	}

	if (FluctuateAlpha(fade_type, fade_speed) == false)
	{
		initCheck_Fade = false;
		if (fade_type == fadeIn)
		{
			return finishedFadeIn;
		}
		else if (fade_type == fadeOut)
		{
			return finishedFadeOut;
		}

	}
	else
	{
		return doingFade;
	}
}

void Fade::DrawFade()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawBox(0, 0, 640, 480, GetColor(0,0,0), TRUE);
}
