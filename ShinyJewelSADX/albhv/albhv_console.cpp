#include "stdafx.h"
#include "albhv_console.h"
#include "../al_toy/alo_console.h"

//wii
signed int __cdecl ALBHV_Touch_(ObjectMaster* a1)
{
	ChaoData1* v1; // esi
	float v4; // st7
	Angle v5; // ecx
	NJS_VECTOR a3; // [esp+8h] [ebp-Ch]

	v1 = (ChaoData1*)a1->Data1;
	if (v1->Behavior.Mode)
	{
		if (v1->Behavior.Mode != 1)
		{
		LABEL_3:
			AL_Brake(a1, 0.9f);
			return 0;
		}
	}
	else
	{
		AL_SetMotionLink(a1, 193);
		++v1->Behavior.Mode;
		v1->Behavior.Timer = 0;
	}

	v1->Behavior.Timer++;
	if (v1->Behavior.Timer <= 60)
	{
		goto LABEL_3;
	}
	v4 = njSin(v1->entity.Rotation.y);
	v5 = v1->entity.Rotation.y;
	a3.x = v4 * 3.0f + v1->entity.Position.x;
	a3.y = v1->entity.Position.y + 1.0f;
	a3.z = njCos(v5) * 3.0f + v1->entity.Position.z;
	ALOField_Load(a1, 175, &a3, 3.5f, 10);

	//wiifield
	ALOField_Load(a1, 303, &a3, 3.5f, 10);

	return 1;
}
int ALBHV_PlayOnConsole(ObjectMaster* a1)
{
	ChaoData1* v1; // esi
	int v2; // eax
	ObjectMaster* a1a; // [esp+Ch] [ebp+4h]

	v1 = (ChaoData1*)a1->Data1;
	v2 = v1->Behavior.Mode;
	if (v2)
	{
		if (v2 != 1)
		{
			return 0;
		}
	}
	else
	{
		consolePtr->Data1->Action = 1;

		//TV->Action = 13;
		//v2->InvulnerableTime = 0;
		//v2->field_A = (rand() * 0.000030517578125f) * 4;

		AL_SetMotionLink(a1, 333);
		AL_FaceSetEye(a1, 4, -1);
		AL_SetItem(a1, 11, &wii_remote_bhav, &AL_WII_TEXLIST);
		a1a = (ObjectMaster*)rand();
		++v1->Behavior.Mode;
		v1->Behavior.Timer = (unsigned __int16)(600 * 2
			- (unsigned __int64)((double)(signed int)a1a * 0.000030517578 * -201.0));
	}

	v1->Behavior.Timer++;
	if (v1->Behavior.Timer < 0 && !ALOField_Find(a1, 1, 201))
	{
		consolePtr->Data1->Action = 0;
		//set cooldown timer
		AL_SetIntervalTimer(
			a1,
			8u,
			(unsigned __int16)(1800 - (unsigned __int64)((double)(signed int)rand() * 0.000030517578 * -1801.0)));
		return 1;
	}
	return 0;
}
void ALBHV_GoToConsole(ObjectMaster* a1)
{
	//experimenting with how many behaviors can i reuse

	AL_SetBehavior(a1, ALBHV_PostureChangeStand);
	AL_SetNextBehavior(a1, ALBHV_Notice);
	AL_SetNextBehavior(a1, ALBHV_GoToLockOn);
	AL_SetNextBehavior(a1, ALBHV_Touch_);
	AL_SetNextBehavior(a1, ALBHV_GoToAim); //so this is the first TV thing
	AL_SetNextBehavior(a1, ALBHV_TurnToLockOn); //then theres this which handles the rotating towards TV and the sitting and shit
	AL_SetNextBehavior(a1, ALBHV_PlayOnConsole); //i thought this is only clapping but it seems like this is the main TV behav
}

//tv hook
FunctionPointer(bool, ALO_GetTVWatchPos, (NJS_VECTOR* a1), 0x0076F150);
signed int __cdecl ALBHV_GoToTV_(ObjectMaster* a1)
{
	ObjectMaster* v1; // edi
	NJS_VECTOR a2; // [esp+8h] [ebp-Ch]

	v1 = AL_GetFoundToyTask(a1);
	if (!v1 || !ALO_GetTVWatchPos(&a2))
	{
		return 1;
	}
	ALW_LockOn(a1, v1);
	MOV_SetAimPos(a1, &a2);

	if (consolePtr && ((double)rand() * 0.000030517578) < 0.05)	ALBHV_GoToConsole(a1);
	else
	{
		AL_SetBehavior(a1, ALBHV_PostureChangeStand);
		AL_SetNextBehavior(a1, ALBHV_Notice);
		AL_SetNextBehavior(a1, ALBHV_GoToLockOn);
		AL_SetNextBehavior(a1, ALBHV_Touch);
		AL_SetNextBehavior(a1, ALBHV_GoToAim);
		AL_SetNextBehavior(a1, ALBHV_TurnToLockOn);
		AL_SetNextBehavior(a1, ALBHV_WatchTV);
	}

	return 0;
}
