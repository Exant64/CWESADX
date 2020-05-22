
#include "alo_radio.h"
#include "../eff/MusicParticle.h"

void Radio_Display(ObjectMaster* a1)
{
	float a1a = njSin(a1->Data1->Rotation.x) * 0.05000000074505806 + 1.0;
	if (ScaleObjectMaster_XYZ(a1, 3.0f, 3.0f, 1.0f)) {
		njPushMatrixEx();
		njSetTexture(&AL_TOY_TEXLIST);
		njControl3D_Add(NJD_CONTROL_3D_TRANS_MODIFIER | NJD_CONTROL_3D_SHADOW);

		njTranslate(0, a1->Data1->Position.x, a1->Data1->Position.y, a1->Data1->Position.z);
		njRotateY(0, a1->Data1->Rotation.y);
		njScale(0, a1a, 2.0 - a1a, 1);
		njCnkDrawObject(&Radio);
		njControl3D_Remove(NJD_CONTROL_3D_TRANS_MODIFIER | NJD_CONTROL_3D_SHADOW);
		njPopMatrixEx();
	}
}
int  sub_446960(int result, int a2, __int16 a3)
{
	result = (unsigned __int16)result;
	if ((signed __int16)(result - a3) > a2 || (signed __int16)(result - a3) < -a2)
	{
		if (((short)result - a3) & 0x8000)
		{
			result = (unsigned __int16)(a3 - a2);
		}
		else
		{
			result = (unsigned __int16)(a3 + a2);
		}
	}
	return result;
}
void Radio_Main(ObjectMaster* a1)
{

	ObjectMaster* v1; // esi
	EntityData1* v2; // edi
	int v3; // ecx
	double v4; // st7
	char* v5; // ebx
	ObjectMaster* v6; // eax
	ObjectMaster* v7; // eax
	ObjectMaster* v8; // eax
	ObjectMaster* v9; // eax
	__int16 v10; // ax
	ObjectMaster* v11; // eax
	float a1a; // [esp+18h] [ebp+4h]
	//AddToGlobalChaoThingMaybe(6, a1, 4, 0);
	ObjUnknownA* unknown = (ObjUnknownA*)a1->UnknownA_ptr;
	//unknown->field_4 = 5;
	v1 = a1;
	v2 = a1->Data1;
	v2->CharIndex++;
	if (v2->Scale.x > 10) {
		v2->Scale.x = 0;
		NJS_VECTOR position = a1->Data1->Position;
		position.x -= 2;
		position.x += rand() * 0.000030517578125f * 5;
		//MusicParticle_Load(&position, v2->CharIndex);
	}
	v2->Scale.x++;
	switch (v2->Action)
	{
	case 1:
		a1a = (double)rand() * 0.000030517578125;
		v4 = a1a;
		if (a1a < 0.25)
		{
			v5 = "chao_g_radicase1.adx";
			goto LABEL_22;
		}
		if (v4 < 0.5)
		{
			v2->Action = 4;
			v2->InvulnerableTime = 0;
			v5 = "chao_g_radicase2.adx";
			goto LABEL_24;
		}
		v2->NextAction = 0;
		v2->Index = 0;
		if (v4 >= 0.75)
		{
			v2->Action = 6;
			v2->InvulnerableTime = 0;
			v5 = "chao_g_radicase4.adx";
		}
		else
		{
			v3 = 0;
			v2->Action = 5;
			v2->InvulnerableTime = 0;
			v5 = "chao_g_radicase3.adx";
		}
		goto LABEL_25;
	case 2:
		//sub_4432D0(); inits jingle
		v2->Action = 0;
		v2->NextAction = 0;
		v2->InvulnerableTime = 0;
		v2->Index = 0;
		goto LABEL_30;
	case 3:
		v6 = ALOField_Find2(v2, 0xB1u);
		v3 = 0;
		if (!v6)
		{
			break;
		}
		v2->Action = 4;
		v2->NextAction = 0;
		v2->InvulnerableTime = 0;
		v2->Index = 0;
		v5 = "chao_g_radicase2.adx";
		goto LABEL_25;
	case 4:
		v7 = ALOField_Find2(v2, 0xB1u);
		if (!v7)
		{
			break;
		}
		v2->Action = 5;
		v5 = "chao_g_radicase3.adx";
		goto LABEL_23;
	case 5:
		v8 = ALOField_Find2(v2, 0xB1u);
		if (!v8)
		{
			break;
		}
		v2->Action = 6;
		v2->InvulnerableTime = 0;
		v5 = "chao_g_radicase4.adx";
		goto LABEL_24;
	case 6:
		v9 = ALOField_Find2(v2, 177u);
		if (v9)
		{
			v5 = "chao_g_radicase1.adx";
		LABEL_22:
			v2->Action = 3;
		LABEL_23:
			v3 = 0;
			v2->InvulnerableTime = 0;
		LABEL_24:
			v2->NextAction = 0;
			v2->Index = 0;
		LABEL_25:
			PrintDebug("playjingle leftover");
			//PlayMusicFile(v5, 0);
		}
		break;
	default:
		break;
	}
	if (v2->Action)
	{
		v10 = v2->InvulnerableTime;
		v2->InvulnerableTime = v10 + 1;
		if ((unsigned __int16)v10 > 3600u)
		{
			v2->Action = 2;
			v2->NextAction = 0;
			v2->InvulnerableTime = 0;
			v2->Index = 0;
		}
		v2->Rotation.x += 3072;

	}
	else
	{
	LABEL_30:

		v11 = ALOField_Find(a1, 0, 175);
		if (v11)
		{
			PrintDebug("found chao fo sho");
			v2->Action = 1;
			v2->NextAction = 0;
			v2->InvulnerableTime = 0;
			v2->Index = 0;

			ObjectMaster* field = ALOField_Load(a1, 202, &v2->Position, 25.5, 3600);

		}

		v2->Rotation.x = sub_446960(0, 3072, v2->Rotation.x);

	}
	Chao_AddToCollisionList(v1);
	a1->DisplaySub(a1);
	RunObjectChildren(a1);
}




void Radio_Load(ObjectMaster* a1)
{
	ObjectFunc(ALO_Delete, 0x71A6B0);
	AddToGlobalChaoThingMaybe(6, a1, 3, 0);
	a1->DeleteSub = ALO_Delete;

	a1->MainSub = (void(__cdecl*)(ObjectMaster*))Radio_Main;
	a1->DisplaySub = (void(__cdecl*)(ObjectMaster*))Radio_Display;
}
CollisionData radioCollision = { 0, 0xC77, 0, 32768,{ 0,0,0},{2,0,0},  0,0 };
void PlaceRadio()
{
	ObjectMaster* radio;
	EntityData1* radioData;

	radio = LoadObject(LoadObj_Data1, 4, Radio_Load);
	ALO_RadicaseExecutor_ptr = radio;

	radioData = radio->Data1;
	if (radioData)
	{
		radioData->Action = 0;
		if (!GetModuleHandle(L"DCMods_Main")) {
			radioData->Position.x = 1.47f;
			radioData->Position.y = -0.044f;
			radioData->Position.z = -251.27f;
		}
		else
		{
			radioData->Position.x = 72.47f;
			radioData->Position.y = 3;
			radioData->Position.z = -231.27f;
		}
		radioData->Rotation.y = 4096;
		radioData->Scale.x = 1;
		radioData->Scale.y = 1;
		radioData->Scale.z = 1;
		InitCollision(radio, &radioCollision, 1, 4);
		//SetCollisionInfoRadius(radio->Data1->CollisionInfo, 20.0);


	}
}
