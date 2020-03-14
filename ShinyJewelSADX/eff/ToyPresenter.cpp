#include "stdafx.h"
#include "ToyPresenter.h"

NJS_OBJECT* objects[] = { &object_00F005A0 , &TVTest };

void ToyPresenter_Display(ObjectMaster* a1)
{
	if (a1->Data1->Action)
	{
		njPushMatrixEx();

		njTranslate(0, -84, 29.5, 366.0);
		njRotateY(0, a1->Data1->Rotation.y);
		njScale(0, a1->Data1->Scale.x, a1->Data1->Scale.x, a1->Data1->Scale.x);
		njSetTexture(&AL_TOY_TEXLIST);
		njCnkDrawObject(objects[a1->Data1->Status]);

		njPopMatrixEx();
	}
}

void ToyPresenter_Main(ObjectMaster* a1)
{
	EntityData1* v1; // esi
	char v2; // cl
	__int16 v3; // ax
	Float v5; // [esp+8h] [ebp+4h]

	v1 = a1->Data1;
	v2 = v1->Action;
	switch (v1->Action)
	{
	case 0:
		if (++v1->InvulnerableTime <= 20)
		{
			goto LABEL_12;
		}
		v1->Rotation.y += 512;
		v1->Action = v2 + 1;
		v1->NextAction = 0;
		break;
	case 1:
		v1->Scale.x += 0.08f;
		if (v1->Scale.x <= 1.0)
		{
			goto LABEL_12;
		}
		v1->Scale.x = 1.0;
		v1->Rotation.y += 512;
		v1->Action = v2 + 1;
		v1->NextAction = 0;
		v1->InvulnerableTime = 0;
		break;
	case 2:
		if (v1->InvulnerableTime == 30)
		{

		}
		v3 = v1->InvulnerableTime;
		v1->InvulnerableTime = v3 + 1;
		if ((unsigned __int16)v3 <= 0x14Au)
		{
			goto LABEL_12;
		}
		++v1->Action;
		v1->Rotation.y += 512;
		v1->NextAction = 0;
		v1->InvulnerableTime = 0;
		break;
	case 3:
		v5 = v1->Scale.x - 0.07999999821186066f;
		v1->Scale.x = v5;
		if (v5 >= 0.0f)
		{
			goto LABEL_12;
		}
		v1->Scale.x = 0.0f;
		v1->Rotation.y += 512;
		v1->Action = v2 + 1;
		v1->NextAction = 0;
		break;
	default:
	LABEL_12:
		v1->Rotation.y += 512;
		break;
	}
	a1->DisplaySub(a1);
}

void ToyPresenter_Load(int ID)
{
	ObjectMaster* toyPresenter = LoadObject(LoadObj_Data1, 5, ToyPresenter_Main);
	toyPresenter->DisplaySub = ToyPresenter_Display;
	toyPresenter->Data1->Status = ID;
}
