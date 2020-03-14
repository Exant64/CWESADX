#include "stdafx.h"
#include "..//chao.h"

signed int __cdecl BullyKnocked(ObjectMaster* a1)
{
	ChaoData1* v2;

	v2 = (ChaoData1*)a1->Data1;

	if (!v2->Behavior.Mode)
	{
		AL_SetMotionLink(a1, 37);
		AL_IconSet(a1, 5, 180);
		AL_FaceSetEye(a1, 1, -1);
		AL_FaceSetMouth(a1, 4, -1);
		++v2->Behavior.Mode;
	}
	v2->Behavior.Timer++;
	if (v2->Behavior.Timer >= 180)
		return 1;
	return 0;
}
signed int __cdecl BullyPunch(ObjectMaster* a1)
{
	ChaoData1* v2;

	v2 = (ChaoData1*)a1->Data1;
	//Chao_SetEmotionBall(a1, 4, 60);
	if (!v2->Behavior.Mode)
	{
		AL_FaceSetEye(a1, 10, -1);
		AL_SetMotionLink(a1, 442 - 3);
		++v2->Behavior.Mode;
	}
	v2->Behavior.Timer++;
	if (v2->Behavior.Timer >= 30)
	{
		ObjectMaster* obj = GetChaoObject(0, 1);
		AL_SetBehavior(obj, BullyKnocked);
		AL_EmotionAdd(a1, EM_ST_TEDIOUS, -5000); //chaoglobal todo
		//v2->pParamGC->Boredom -= 5000;
		return 1;
	}
	return 0;
}