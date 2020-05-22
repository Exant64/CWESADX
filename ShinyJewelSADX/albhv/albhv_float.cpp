
#include "albhv_float.h"
#include "../data/toy/alo_float.nja"

signed int __cdecl ALBHV_SwimFloat(ObjectMaster* a1)
{
	double v2; // st7

	AL_BEHAVIOR* v1 = &((ChaoData1*)a1->Data1)->Behavior;
	if (!v1->Mode)
	{
		v2 = (double)rand() * 0.000030517578;
		if (v2 >= 0.2)
		{
			if (v2 < 0.40000001)
			{
				AL_FaceSetEye(a1, 4, -1);
			}
		}
		else
		{
			AL_FaceSetEye(a1, 1, -1);
		}
		AL_SetMotionLink(a1, 148);
		++v1->Mode;
	}
	AL_SetItem(a1, 0x22, &object_00F005A0, &AL_TOY_TEXLIST); //0x22
	//SwimControlStop(a1);
	return 0;
}
void ALBHV_FloatCheck(ObjectMaster* a1, signed int(__cdecl* a2)(int))
{
	ChaoData1* data = (ChaoData1*)a1->Data1;
	if (data->pParamGC->gap_0[15] /*float flag*/ && data->pParamGC->Type == ChaoType_Child)
		AL_SetBehavior(a1, ALBHV_SwimFloat);
	else AL_SetBehavior(a1, ALBHV_SwimObore);
}