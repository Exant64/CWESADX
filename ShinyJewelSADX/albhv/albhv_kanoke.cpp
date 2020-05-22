
#include "..//chao.h"
signed int __cdecl ALBHV_GoToKanoke(ObjectMaster* a1)
{
	ObjectMaster* v1 = AL_GetFoundToyTask(a1);
	if (!v1 || ALOField_Find(a1, 1, 233) || ALW_IsSheAttentionOtherOne(a1, v1))
	{
		return 1;
	}
	MOV_SetAimPos(a1, &v1->Data1->Position);
	ALW_CommunicationOn(a1, v1);

	AL_SetBehavior(a1, ALBHV_PostureChangeStand);
	AL_SetNextBehavior(a1, ALBHV_Notice);
	AL_SetNextBehavior(a1, ALBHV_GoToAim);
	AL_SetNextBehavior(a1, ALBHV_TurnToAim);
	//AL_SetNextBehavior(a1, ALBHV_Ball);
	return 0;

}