
#include "albhv_ball.h"

NJS_VECTOR* __cdecl ALO_GetBallPos(ObjectMaster* a2)
{
	EntityData1* v2; // edi
	float v3; // ST0C_4
	Angle v4; // esi
	float v5; // st7
	NJS_VECTOR a1;

	if (a2)
	{
		v2 = a2->Data1;
		//v3 = (double)rand() * 0.000030517578 * 3.0 + 10.0;
		v3 = 4;
		v4 = v2->Rotation.y + 0x8000
			- (unsigned __int64)(((double)rand() * 0.000030517578 * 80.0 - 40.0) * 65536.0 * -0.002777777777777778)
			+ 0x8000;
		a1.x = njSin(v4) * v3 + v2->Position.x;
		a1.y = v2->Position.y;
		v5 = njCos(v4) * v3;

		a1.z = v5 + v2->Position.z;

	}
	return  &a1;
}
signed int __cdecl ALBHV_Ball(ObjectMaster* a1) //copy of horse action
{
	ObjectMaster* v1; // edi
	ChaoData1* v2; // esi
	ChaoData2* v3; // ebx
	signed int v7; // edx
	NJS_VECTOR* v8; // ecx
	int v10; // eax
	_BOOL1 v11; // zf
	int v12; // eax
	NJS_VECTOR a2; // [esp+Ch] [ebp-Ch]
	ObjectMaster* a1a; // [esp+1Ch] [ebp+4h]

	v1 = a1;
	v2 = (ChaoData1*)a1->Data1;
	v3 = (ChaoData2*)a1->Data2;
	switch (v2->Behavior.Mode)
	{
	case 0:
		AL_SetMotionLink(a1, 135);

		AL_FaceSetEye(a1, 1, -1);


		AL_FaceSetMouth(a1, 0, -1);

		AL_FixPosition(a1);
		a2.y = 0.95f;
		a2.x = njSin(v2->entity.Rotation.y) * 0.08f;
		a2.z = njCos(v2->entity.Rotation.y) * 0.08f;
		MOV_SetVelo(a1, &a2);
		++v2->Behavior.Mode;
		break;
	case 1:
		if (v3->Speed.y < 0.0)
		{
			//AL_SetMotionLinkStep(a1, 347, 0x1Eu);
			v2->ChaoFlag &= ~2;
			v2->Behavior.Timer = 29;
			++v2->Behavior.Mode;
		}
		break;
	case 2:
		v2->Behavior.Timer--;
		if (!v2->Behavior.Timer)
		{
			AL_SetMotionSkip(a1, 101);
			ALOField_Load(a1, 233, &v2->entity.Position, 20, 1800);
			v2->Behavior.Timer = 1800;
			++v2->Behavior.Mode;
		}
		break;
	case 3:
		v2->Behavior.Timer--;
		if (!v2->Behavior.Timer)
		{
			a1a = (ObjectMaster*)rand();
			AL_SetIntervalTimer(
				v1,
				8u,
				(unsigned __int16)(1800 - (unsigned __int64)((double)(signed int)a1a * 0.000030517578 * -1801.0)));
			v2->ChaoFlag |= 2u;
			AL_SetBehavior(v1, ALBHV_JumpFromHorse);
			return 1;
		}
		break;
	}
	al_entry_work* v6 = ALW_IsCommunicating(a1);
	if (v6)
	{
		v7 = v2->Behavior.Mode;
		if (v7 != 1)
		{
			if (v7 <= 1 || v7 > 3)
			{
				return 0;
			}
			v2->entity.Position.x = (v6->tp->Data1->Position.x - v2->entity.Position.x) * 0.1f + v2->entity.Position.x;
			v2->entity.Position.y = (v6->tp->Data1->Position.y - v2->entity.Position.y) * 0.1f + v2->entity.Position.y + 0.2f;
			v2->entity.Position.z = (v6->tp->Data1->Position.z - v2->entity.Position.z) * 0.1f + v2->entity.Position.z;
		}
		v2->entity.Rotation.y = BAMS_SubWrap(v2->entity.Rotation.y, v6->tp->Data1->Rotation.y, 1024);
		return 0;
	}
	else
	{
		AL_SetBehavior(a1, ALBHV_Touch);
		return 1;
	}
}
signed int __cdecl ALBHV_GoToBall(ObjectMaster* a1)
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
	AL_SetNextBehavior(a1, ALBHV_Ball);
	return 0;

}

void __cdecl Chao_BallJoinDecision(ObjectMaster* a1, float* a2)
{
	ChaoData1* data1 = (ChaoData1*)a1->Data1;
	float boredom = AL_EmotionGetValue(a1, EM_ST_TEDIOUS);
	float boredomMin = 1000;
	float boredomMinAdjust = boredomMin;
	float resultBoredomCalc = 0.0f;
	ObjectMaster* field = ALOField_Find(a1, 1, 233);

	if (field)
	{
		if (boredom > boredomMin)
		{
			if (boredom < 7000)
			{
				boredomMinAdjust = boredom + 3000;
			}
			resultBoredomCalc = 0.99f * (float)AL_CalcScoreTypeA(boredomMinAdjust, boredomMin);
			AL_ScoreRandomize(&resultBoredomCalc);

		}
		if (resultBoredomCalc > * a2)
		{
			ObjectMaster* chao = field->Parent;
			if (chao)
			{
				MOV_SetAimPos(a1, ALO_GetBallPos(chao));
			}
			AL_SetBehavior(a1, ALBHV_TurnToAim);//sets rotation
			AL_SetNextBehavior(a1, ALBHV_PostureChangeSit); //crawl anim
			//AL_SetNextBehavior((ObjectMaster*)a1, (int)Chao_BallClap); //wait until ends,then clap
			 
			*a2 = 0.99f;
		}
	}
}
