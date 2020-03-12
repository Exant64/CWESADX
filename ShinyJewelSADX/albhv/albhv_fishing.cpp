#include "stdafx.h"
#include "albhv_fishing.h"
#include "..//data/toy/alo_fishingrod.nja"
int ALBHV_GotItem(ObjectMaster* a1)
{
	ChaoData1* v1; // esi
	int v2; // eax
	int v3; // esi

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
		AL_SetMotionLink(a1, 1);
		AL_FaceSetEye(a1, 4, -1);

		++v1->Behavior.Mode;
	}
	if (AL_IsMotionStop(a1) && v1->Behavior.Mode != 2)
	{
		AL_SetItem(a1, 4, ChaoFruitModels[SADXFruit_PurpleFruit], &AL_OBJECT_TEXLIST);

		++v1->Behavior.Mode;
	}
	return 0;
}
signed int __cdecl ALBHV_Fishing(ObjectMaster* a1)
{
	ChaoData1* v1; // esi
	int v2; // eax
	int v3; // esi

	v1 = (ChaoData1*)a1->Data1;

	if (!v1->Behavior.Mode)
	{
		AL_SetMotionLink(a1, 0);
		AL_FaceSetEye(a1, 4, -1);
		AL_SetItem(a1, 4, &object_alo_fishingrod, &AL_TOY_TEXLIST);
		++v1->Behavior.Mode;
	}

	MOV_TurnToAim2(a1, 1024);
	//((ChaoData2*)a1->Data2)->field_20 = 256;
	v1->Behavior.SubTimer++;
	if (!(v1->Behavior.SubTimer % 40) && rand() * 0.000030517578 > 0.9)
	{
		//AL_SetBehavior(a1, (signed int(__cdecl *)(int))scriptingTest);
		return 0;
	}
	return 0;
}
