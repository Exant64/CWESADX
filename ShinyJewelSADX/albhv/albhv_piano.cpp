#include "stdafx.h"
#include "..//chao.h"
bool __cdecl ALO_GetPianoPlayPos(ObjectMaster* a2, NJS_VECTOR* a1)
{
	EntityData1* v2; // edi
	float v3; // ST0C_4
	Angle v4; // esi
	float v5; // st7


	if (a2)
	{
		v2 = a2->Data1;
		//v3 = (double)rand() * 0.000030517578 * 3.0 + 10.0;
		v3 = 2;
		v4 = v2->Rotation.y + 0x8000;
		//- (unsigned __int64)(((double)rand() * 0.000030517578 * 80.0 - 40.0) * 65536.0 * -0.002777777777777778)
		//+ 0x8000;
		a1->x = njSin(v4) * v3 + v2->Position.x;
		a1->y = v2->Position.y;
		v5 = njCos(v4) * v3;

		a1->z = v5 * v3 + v2->Position.z;

	}
	return 1;
}
int ALBHV_PlayPiano(ObjectMaster* a1)
{
	ChaoData1* data1 = (ChaoData1*)a1->Data1;
	ChaoData2* data2 = (ChaoData2*)a1->Data2;
	if (data1->Behavior.Mode)
	{
		return !ALOField_Find((ObjectMaster*)a1, 1, 165);
	}
	else
	{
		NJS_VECTOR position;
		ObjectMaster* toy = (ObjectMaster*)AL_GetFoundToyTask((ObjectMaster*)a1);
		ALO_GetPianoPlayPos(toy, &position);

		a1->Data1->Position = position;
		a1->Data1->Rotation.y = -toy->Data1->Rotation.y;
		AL_SetMotionLink(a1, 343);
		AL_FaceSetEye(a1, ChaoEyes_ClosedUp, -1);
		AL_FaceSetMouth(a1, ChaoMouth_ClosedSmile, -1);
		++data1->Behavior.Mode;
		int timer = (unsigned __int16)(1800 - (unsigned __int64)((double)(signed int)rand() * 0.000030517578 * -800));

		data1->pAnyTask = ALOField_Load(
			a1,
			165,
			&a1->Data1->Position,
			20.0,
			timer);
		data1->pBookTask = ALOField_Load( //165 is shared with bands, so that shouldn't stop the pianist to join, which is why i created 225
			a1,
			225,
			&a1->Data1->Position,
			20.0,
			timer);
	}
	//AL_MoveHoldingObject(a1);
	return 0;
}
signed int __cdecl ALBHV_GoToPiano(ObjectMaster* a1)
{

	ObjectMaster* v1; // edi
	NJS_VECTOR a2; // [esp+8h] [ebp-Ch]

	v1 = AL_GetFoundToyTask(a1);
	if (!v1 || ALOField_Find(a1, 1, 225))
	{
		return 1;
	}
	ALO_GetPianoPlayPos(v1, &a2);
	ALW_LockOn(a1, v1);
	MOV_SetAimPos(a1, &a2);
	AL_SetBehavior(a1, ALBHV_PostureChangeStand);
	AL_SetNextBehavior(a1, ALBHV_Notice);
	AL_SetNextBehavior(a1, ALBHV_GoToLockOn);
	AL_SetNextBehavior(a1, ALBHV_PlayPiano);
	return 0;
}