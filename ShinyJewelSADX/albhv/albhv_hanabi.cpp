#include "stdafx.h"
#include "albhv_hanabi.h"
#include "../data/toy/alo_hanabi_d.nja"
void Hanabi_Display(ObjectMaster* a1)
{
	njPushMatrixEx();

	njTranslateV(0, &a1->Data1->Position);
	njScale(0, a1->Data1->Scale.x, a1->Data1->Scale.x, a1->Data1->Scale.x);

	njSetTexture(&AL_TOY_TEXLIST);
	njCnkDrawObject(object_alo_hanabi_n_hanabi_n__3PAUcnkobj__A);

	njPopMatrixEx();
}

void Hanabi_Main(ObjectMaster* a1)
{
	if (a1->Data1->Action == 0)
	{
		a1->Data1->Scale.x += 0.075f;
		if (a1->Data1->Scale.x > 1.0f)
			a1->Data1->Scale.x = 1.0f;
	}
	else if (a1->Data1->Action == 1)
	{
		a1->Data1->Position.y += a1->Data1->Scale.y;
		a1->Data1->Scale.y -= 0.075f;
		if (a1->Data1->Position.y < 0)
		{
			a1->Data1->Position.y = 0;
			a1->Data1->Action = 2;
		}

		a1->Data1->Position.z += a1->Data1->Scale.z;
		if (a1->Data1->Scale.z > 0)
			a1->Data1->Scale.z -= 0.05f;
		else a1->Data1->Scale.z = 0;


	}
	else if (a1->Data1->Action == 2)
	{
		if (a1->Data1->Index == 0) {
			QueueSound_XYZ(
				0x273,
				a1->Data1,
				1,
				120,
				a1->Data1->Position.x,
				a1->Data1->Position.y,
				a1->Data1->Position.z,
				440.0);
		}
		if (a1->Data1->Index++ > 120)
			a1->Data1->Action = 3;
	}
	else if (a1->Data1->Action == 3)
	{
		a1->Data1->Scale.x += 0.1f;
		if (a1->Data1->Scale.x > 2)
		{
			QueueSound_XYZ(
				0x281,
				a1->Data1,
				1,
				120,
				a1->Data1->Position.x,
				a1->Data1->Position.y,
				a1->Data1->Position.z,
				440.0);
			//explode

			a1->Data1->Action = 4;
		}
	}
	else if (a1->Data1->Action == 4)
	{
		a1->Data1->Index = 0;
		a1->Data1->Scale.x -= 0.25f;
		if (a1->Data1->Scale.x <= 0)
			a1->Data1->Action = 5;
	}
	else if (a1->Data1->Action == 5)
	{
		a1->Data1->Index++;
		if (a1->Data1->Index >= 60)
		{
			a1->Data1->Action = 6;
		}
	}
	a1->DisplaySub(a1);
}

ObjectMaster* CreateHanabi()
{
	ObjectMaster* task = LoadObject(LoadObj_Data1, 4, Hanabi_Main);
	task->DisplaySub = Hanabi_Display;
	task->Data1->Scale.x = 0;
	task->Data1->Scale.y = 0.5f;
	task->Data1->Scale.z = 0.5f;
	return task;
}

AL_ITEM_INFO HanabiInfo = { object_alo_hanabi_n_hanabi_n__3PAUcnkobj__A, &AL_TOY_TEXLIST ,{}, {} };
int ALBHV_Hanabi_(ObjectMaster* a1)
{
	ChaoData1* v2 = (ChaoData1*)a1->Data1;
	if (v2->Behavior.Mode == 0)
	{
		StopMusic();
		AL_FaceSetMouth(a1, ChaoMouth_ClosedSmile, -1);
		AL_SetMotionSkip(a1, 0x77);
		v2->Behavior.Mode++;
		v2->Behavior.Timer = 0;
	}
	else if (v2->Behavior.Mode == 1)
	{
		if (v2->MotionCtrl.frame > 5.0f)
		{
			v2->pAnyTask = CreateHanabi();
			v2->Behavior.Mode++;
		}
	}
	else if (v2->Behavior.Mode == 2)
	{
		if (!v2->pAnyTask->Data1->Action)
		{
			if (v2->MotionCtrl.frame > 15.0f)
				v2->pAnyTask->Data1->Action = 1;
			else
				v2->pAnyTask->Data1->Position = v2->Shape.RightHandPos;
		}
		else
			if (v2->pAnyTask->Data1->Action == 6)
				return 2; //return 1
	}
	SetDebugFontColor(0xFFFFFFFF);
	DisplayDebugFloat(NJM_LOCATION(20, 20), v2->MotionCtrl.frame, 3);

	return 0;
	/*
	ObjectMaster* otherChao = GetChaoObject(0, 0);

	if (v4->Index == 0) //bhav init phase
	{
		if (rand() * 0.000030517578 > 0.5f) //50% chance to run the
		{
			AL_SetBehavior(a1, ALBHV_Think);
			return 0;
		}
		AL_SetMotionLink(a1, 392 + 3 ); //+ 3 because SADX
		v4->Index++;
		//v2->Flags &= ~8u; //remove chao-object collision
		AL_FixPosition(a1);
		AL_SetBehavior(otherChao, Chao_HoldHands_Partner);
		//hmm, 152 maybe? hopefully its unused

	}
	else //main phase
	{

		//set other chao's position
		otherChao->Data1->Position.x = njSin(v2->entity.Rotation.y) * 0.05f + a1->Data1->Position.x - 3;
		otherChao->Data1->Position.z = njCos(v2->entity.Rotation.y) * 0.05f + a1->Data1->Position.z;
		otherChao->Data1->Rotation.y = a1->Data1->Rotation.y;
		//this chao walk forward
		AL_ForwardSpd(a1, 0.1f);
		if (!ALOField_Find(a1, 1, 152)) //if other chao not found, die
			return 1;
	}

	return 2;*/
}
