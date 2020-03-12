#include "stdafx.h"
#include "motiontable.h"
#include <math.h>

void sub_793CB0(MOTION_CTRL* result)
{
	MOTION_TABLE* v1; // ecx
	int v2; // edx
	MOTION_TABLE* v3; // ecx
	double v4; // st7

	v1 = result->PointerToAnimations;
	v2 = v1[result->AnimID].field_C;
	v3 = &v1[result->TransitionToID];
	if (v2 >= 0)
	{
		v4 = (double)v3->field_C;
	}
	else
	{
		v4 = (double)-v2;
	}
	result->transitionSpeed = 1.0 / v4;
	result->linkFrame = 0.0;
	result->SomeFlagThingInEntry = v3->FlagThing1;
	result->LinkStartFrame = v3->StartFrame;
	result->StartFrame_ = v3->StartFrame;
	result->EndFrame = v3->EndFrame;
	result->PlaySpeed = v3->PlaySpeed;
	result->NJS_MOTION = v3->NJS_MOTION;
	result->flag = 2;
}
void MotionTable_PlayAnim(MOTION_CTRL* motion, int a2)
{
	MOTION_TABLE* v2; // esi
	MOTION_TABLE* v3; // ecx

	motion->AnimID = a2;
	v2 = motion->PointerToAnimations;
	motion->TransitionToID = v2[a2].TransitionToID;
	v3 = &v2[a2];
	motion->pose = v2[a2].field_6;
	motion->transitionSpeed = 0.0;
	motion->linkFrame = 0.0;
	motion->SomeFlagThingInEntry2 = v3->FlagThing1;
	motion->frame = v3->StartFrame;
	motion->StartFrame2 = v3->StartFrame;
	motion->EndFrame2 = v3->EndFrame;
	motion->PlaySpeed2 = v3->PlaySpeed;
	motion->LastNJS_Motion = v3->NJS_MOTION;
	motion->flag = 0;
}
void sub_793EA0(MOTION_CTRL* result, int a2)
{
	MOTION_TABLE* v2; // esi
	MOTION_TABLE* v3; // ecx
	double v4; // st7

	result->AnimID = a2;
	v2 = result->PointerToAnimations;
	result->TransitionToID = v2[a2].TransitionToID;
	v3 = &v2[a2];
	result->pose = v2[a2].field_6;
	result->transitionSpeed = 0.0;
	result->linkFrame = 0.0;
	v4 = result->frame;
	result->SomeFlagThingInEntry2 = v3->FlagThing1;
	result->frame = v4 + v3->StartFrame - result->EndFrame2;
	result->StartFrame2 = v3->StartFrame;
	result->EndFrame2 = v3->EndFrame;
	result->PlaySpeed2 = v3->PlaySpeed;
	result->LastNJS_Motion = v3->NJS_MOTION;
	result->flag = 0;
}
void sub_793F10(MOTION_CTRL* result, int a2)
{
	MOTION_TABLE* v2; // esi

	result->AnimID = a2;
	v2 = result->PointerToAnimations;
	result->TransitionToID = v2[a2].TransitionToID;
	result->pose = v2[a2].field_6;
	result->transitionSpeed = 0.0;
	result->linkFrame = 0.0;
	result->SomeFlagThingInEntry2 = result->SomeFlagThingInEntry;
	result->frame = result->LinkStartFrame;
	result->StartFrame2 = result->StartFrame_;
	result->EndFrame2 = result->EndFrame;
	result->PlaySpeed2 = result->PlaySpeed;
	result->LastNJS_Motion = result->NJS_MOTION;
	result->flag = 0;
}

void MotionTableLoop(MOTION_CTRL* a1)
{
	__int16 v1; // cx
	float v2; // ST00_4
	double v3; // st5
	double v4; // st4
	double v5; // st6
	double v6; // st5
	int v7; // ecx
	double v8; // st6
	int v9; // edx
	__int16 v10; // cx
	float v11; // ST00_4
	double frameIncremented; // st7
	double EndFrame2; // st4
	double v14; // st6
	double v15; // st7
	int v16; // edx
	int v17; // edx
	float v18; // ST00_4
	float v19; // [esp+0h] [ebp-4h]
	float v20; // [esp+0h] [ebp-4h]

	a1->flag &= ~(MOTION_CTRLFlags_8 | MOTION_CTRLFlags_1);
	v1 = a1->flag;
	if (!(a1->flag & MOTION_CTRLFlags_Transitioning))
	{
		v10 = a1->SomeFlagThingInEntry2;
		v11 = a1->PlaySpeed2 * a1->speedMultiplier + a1->frame;
		frameIncremented = v11;
		a1->frame = v11;
		EndFrame2 = a1->EndFrame2;
		if (a1->PlaySpeed2 < 0.0)
		{
			if (v10 == 1)
			{
				EndFrame2 = EndFrame2 - 1.0;
			}
			if (EndFrame2 < frameIncremented)
			{
				goto LABEL_26;
			}
		}
		else if (v10 == 1)
		{
			if (EndFrame2 + 1.0 > frameIncremented)
			{
				goto LABEL_26;
			}
		}
		else if (EndFrame2 > frameIncremented)
		{
		LABEL_26:
			a1->speedMultiplier = 1.0;
			return;
		}
		switch (v10)
		{
		case 0:
			a1->frame = frameIncremented - (a1->EndFrame2 - a1->StartFrame2);
			a1->flag |= MOTION_CTRLFlags_1;
			a1->speedMultiplier = 1.0;
			break;
		case 1:
			if (a1->PlaySpeed2 < 0.0)
			{
				v14 = a1->EndFrame2 - 1.0 - a1->StartFrame2;
			}
			else
			{
				v14 = a1->EndFrame2 + 1.0 - a1->StartFrame2;
			}
			a1->frame = frameIncremented - v14;
			a1->flag |= 1u;
			a1->speedMultiplier = 1.0;
			break;
		case 2:
			if (a1->PlaySpeed2 <= 0.0)
			{
				a1->transitionSpeed = -a1->PlaySpeed2;
				v15 = -(a1->frame - a1->EndFrame2);
			}
			else
			{
				a1->transitionSpeed = a1->PlaySpeed2;
				v15 = a1->frame - a1->EndFrame2;
			}
			a1->linkFrame = v15;
			a1->SomeFlagThingInEntry = a1->SomeFlagThingInEntry2;
			a1->LinkStartFrame = a1->StartFrame2;
			a1->StartFrame_ = a1->StartFrame2;
			a1->EndFrame = a1->EndFrame2;
			a1->PlaySpeed = a1->PlaySpeed2;
			a1->NJS_MOTION = a1->LastNJS_Motion;
			a1->speedMultiplier = 1.0;
			a1->flag = MOTION_CTRLFlags_10 | MOTION_CTRLFlags_Transitioning | MOTION_CTRLFlags_1;
			break;
		case 3:
			a1->frame = a1->EndFrame2;
			a1->flag |= MOTION_CTRLFlags_8 | MOTION_CTRLFlags_1;
			a1->speedMultiplier = 1.0;
			break;
		case 4:
			a1->frame = a1->EndFrame2;
			if (a1->TransitionToID != -1)
			{
				sub_793CB0(a1);
			}
			a1->flag |= 1u;
			a1->speedMultiplier = 1.0;
			break;
		case 5:
			v16 = a1->TransitionToID;
			if (v16 != -1)
			{
				MotionTable_PlayAnim(a1, v16);
			}
			a1->flag |= 1u;
			a1->speedMultiplier = 1.0;
			break;
		case 6:
			v17 = a1->TransitionToID;
			if (v17 != -1)
			{
				sub_793EA0(a1, v17);
			}
			a1->flag |= MOTION_CTRLFlags_1;
			a1->speedMultiplier = 1.0;
			break;
		case 7:
			a1->frame = a1->EndFrame2;
			v18 = a1->StartFrame2;
			a1->StartFrame2 = a1->EndFrame2;
			a1->EndFrame2 = v18;
			a1->PlaySpeed2 = a1->PlaySpeed2 * -1.0;
			a1->flag |= 1u;
			a1->speedMultiplier = 1.0;
			break;
		default:
			goto LABEL_26;
		}
		return;
	}
	if (a1->transitionSpeed < 0.0)
	{
		a1->transitionSpeed = a1->transitionSpeed * -1.0;
	}
	v2 = a1->transitionSpeed * a1->speedMultiplier + a1->linkFrame;
	v3 = v2;
	a1->linkFrame = v2;
	if (v1 & MOTION_CTRLFlags_4)
	{
		v19 = a1->PlaySpeed2 * a1->speedMultiplier + a1->frame;
		a1->frame = v19;
		v4 = a1->EndFrame2;
		if (a1->PlaySpeed2 < 0.0)
		{
			if (v4 < v19)
			{
				goto LABEL_7;
			}
		}
		else if (v4 > v19)
		{
		LABEL_7:
			v5 = 0.0;
			goto LABEL_8;
		}
		v5 = 0.0;
		a1->frame = v19 - (a1->EndFrame2 - a1->StartFrame2);
	LABEL_8:
		v20 = a1->speedMultiplier * a1->PlaySpeed + a1->LinkStartFrame;
		a1->LinkStartFrame = v20;
		v6 = a1->EndFrame;
		if (v5 > a1->PlaySpeed)
		{
			if (v6 < v20)
			{
				goto LABEL_10;
			}
		}
		else if (v6 > v20)
		{
			goto LABEL_10;
		}
		a1->LinkStartFrame = v20 - (a1->EndFrame - a1->StartFrame_);
	LABEL_10:
		if (a1->linkFrame >= 1.0)
		{
			v7 = a1->TransitionToID;
			a1->linkFrame = 1.0;
			sub_793F10(a1, v7);
			a1->speedMultiplier = 1.0;
			return;
		}
		goto LABEL_26;
	}
	if (v3 < 1.0)
	{
		a1->speedMultiplier = 1.0;
	}
	else if (v1 & MOTION_CTRLFlags_10)
	{
		if (a1->PlaySpeed2 <= 0.0)
		{
			v8 = a1->StartFrame2 - (v3 - 1.0);
		}
		else
		{
			v8 = v3 - 1.0 + a1->StartFrame2;
		}
		a1->frame = v8;
		a1->flag &= ~(MOTION_CTRLFlags_10 | MOTION_CTRLFlags_Transitioning);
		a1->linkFrame = 1.0;
		a1->speedMultiplier = 1.0;
	}
	else
	{
		v9 = a1->TransitionToID;
		a1->linkFrame = 1.0;
		MotionTable_PlayAnim(a1, v9);
		a1->speedMultiplier = 1.0;
	}
}
void sub_793610(float* a1)
{
	double v1; // st7
	long double v2; // st7
	long double v3; // st6
	long double v4; // st5
	float v5; // ST04_4
	long double v6; // st5
	float v7; // ST08_4
	long double v8; // st6
	long double v9; // st5
	double v10; // st7
	long double v11; // st5
	double v12; // st3
	double v13; // st2
	float v14; // ST00_4
	double v15; // rt1
	long double v16; // st2
	float v17; // ST0C_4
	float v18; // ST14_4
	float v19; // ST10_4
	long double v20; // st4
	double v21; // st5
	long double v22; // st4
	float v23; // [esp+0h] [ebp-58h]
	float v24; // [esp+Ch] [ebp-4Ch]
	NJS_MATRIX a2; // [esp+18h] [ebp-40h]

	v24 = *a1;
	v1 = v24 * v24;
	v23 = v1;
	if (v1 <= 0.0)
	{
		v2 = 1.0;
		v3 = 1.0;
	}
	else if (v23 >= 1.0)
	{
		v2 = 0.0;
		v23 = 1.0;
		v3 = 0.0;
	}
	else
	{
		v2 = sqrt(1.0 - v23);
		v3 = 1.0 / v2;
	}
	v4 = v3 * a1[1];
	a2[3] = 0.0;
	a2[7] = 0.0;
	a2[11] = 0.0;
	v5 = v4;
	a2[12] = 0.0;
	a2[13] = 0.0;
	a2[14] = 0.0;
	v6 = v3 * a1[2];
	a2[15] = 1.0;
	v7 = v6;
	v8 = v3 * a1[3];
	v9 = v2;
	v10 = v23 + v23 - 1.0;
	v11 = v9 * v24 + v9 * v24;
	a2[0] = v5 * (1.0 - v10) * v5 + v10;
	v12 = v7 * (1.0 - v10);
	v13 = v5 * v12;
	v14 = v11 * v8;
	a2[1] = v11 * v8 + v13;
	v15 = v13;
	v16 = (1.0 - v10) * v8;
	v17 = v16;
	v18 = v16 * v5;
	v19 = v11 * v7;
	a2[2] = v18 - v19;
	a2[4] = v15 - v14;
	a2[5] = v12 * v7 + v10;
	v20 = v11;
	v21 = v17 * v7;
	v22 = v20 * v5;
	a2[6] = v22 + v21;
	a2[8] = v19 + v18;
	a2[9] = v21 - v22;
	a2[10] = v17 * v8 + v10;
	njMultiMatrix(0, a2);
}
void __cdecl MotionTable_PlayAnimationRegular(MOTION_CTRL* motiontable, int animid)
{
	MOTION_TABLE* v2; // eax

	v2 = &motiontable->PointerToAnimations[animid];
	motiontable->TransitionToID = animid;
	if (v2->field_C >= 0)
	{
		motiontable->transitionSpeed = 1.0 / (double)v2->field_C;
	}
	else
	{
		motiontable->transitionSpeed = 0.06666667;
	}
	motiontable->linkFrame = 0.0;
	motiontable->SomeFlagThingInEntry = v2->FlagThing1;
	motiontable->LinkStartFrame = v2->StartFrame;
	motiontable->StartFrame_ = v2->StartFrame;
	motiontable->EndFrame = v2->EndFrame;
	motiontable->PlaySpeed = v2->PlaySpeed;
	motiontable->NJS_MOTION = v2->NJS_MOTION;
	motiontable->flag = 2;
}

void __cdecl MotionTable_PlayAnimation_Speed(MOTION_CTRL* a1, int a2, unsigned __int16 a3)
{
	MOTION_TABLE* v3; // ecx

	a1->TransitionToID = a2;
	a1->linkFrame = 0.0;
	v3 = &a1->PointerToAnimations[a2];
	a1->transitionSpeed = 1.0 / (double)a3;
	a1->SomeFlagThingInEntry = v3->FlagThing1;
	a1->LinkStartFrame = v3->StartFrame;
	a1->StartFrame_ = v3->StartFrame;
	a1->EndFrame = v3->EndFrame;
	a1->PlaySpeed = v3->PlaySpeed;
	a1->NJS_MOTION = v3->NJS_MOTION;
	a1->flag = 2;
}

void MotionTable_Init(MOTION_CTRL* motion, MOTION_TABLE* a2)
{
	motion->flag = 0;
	motion->AnimID = 0;
	motion->TransitionToID = -1;
	motion->pose = 0;
	motion->speedMultiplier = 0.0;
	motion->transitionSpeed = 0.0;
	motion->linkFrame = 0.0;
	motion->LastNJS_Motion = 0;
	motion->frame = 0.0;
	motion->StartFrame2 = 0.0;
	motion->EndFrame2 = 0.0;
	motion->NJS_MOTION = 0;
	motion->LinkStartFrame = 0.0;
	motion->StartFrame_ = 0.0;
	motion->EndFrame = 0.0;
	motion->PointerToAnimations = (MOTION_TABLE*)a2;
	MotionTable_PlayAnim(motion, 0);
}