
#include "alo_piano.h"
//#include "data/toy/alo_hanabi_d.nja"
//#include "data/toy/alo_hanabi_d.nja"

bool __cdecl Calc(ObjectMaster* a2, NJS_VECTOR* a1)
{
	EntityData1* v2; // edi
	float v3; // ST0C_4
	Angle v4; // esi
	float v5; // st7


	if (a2)
	{
		v2 = a2->Data1;
		v3 = (double)rand() * 0.000030517578f * 3.0f + 10.0f;
		v3 = 2;
		v4 = v2->Rotation.y + 0x8000;
		//- (unsigned __int64)(((double)rand() * 0.000030517578 * 80.0 - 40.0) * 65536.0 * -0.002777777777777778)
		//+ 0x8000;
		a1->x = njSin(v4) * v3 + v2->Position.x;
		a1->y = v2->Position.y;
		v5 = njCos(v4) * v3;

		a1->z = v5 * v3 + v2->Position.z
			+ 3;
	}
	return 1;
}


void Piano_Display(ObjectMaster* a1)
{

	if (ScaleObjectMaster_XYZ(a1, 5.1999998, 4.5, 2.9000001)) {
		njPushMatrixEx();
		njSetTexture(&AL_TOY_TEXLIST);
		njControl3D_Add(NJD_CONTROL_3D_TRANS_MODIFIER | NJD_CONTROL_3D_SHADOW);

		njTranslate(0, a1->Data1->Position.x, a1->Data1->Position.y, a1->Data1->Position.z);
		njRotateY(0, a1->Data1->Rotation.y);
		njScale(0, 1, 1, 1);
		//njCnkDrawObject(&object_0006972C);

		njControl3D_Remove(NJD_CONTROL_3D_TRANS_MODIFIER | NJD_CONTROL_3D_SHADOW);
		njPopMatrixEx();
	}
}

void Piano_Main(ObjectMaster* a1)
{
	if (ALOField_Find((ObjectMaster*)a1, 1, 225))
		a1->Data1->Action = 1;
	else a1->Data1->Action = 0;
	Chao_AddToCollisionList(a1);
	a1->DisplaySub(a1);
}

void Piano_Load(ObjectMaster* a1)
{
	ObjectFunc(ALO_Delete, 0x71A6B0);
	AddToGlobalChaoThingMaybe(6, a1, 4, 0);
	a1->DeleteSub = ALO_Delete;

	a1->MainSub = Piano_Main;
	a1->DisplaySub = Piano_Display;
}
CollisionData pianoCollision = { 0, 0xC77, 0, 32768,{ 0,0,0},{2,0,0},  0,0 }; //just radio collision
void CreatePiano()
{
	ObjectMaster* piano;
	EntityData1* pianoData;

	piano = LoadObject(LoadObj_Data1, 4, Piano_Load);



	pianoData = piano->Data1;
	if (pianoData)
	{
		pianoData->Action = 0;
		if (!GetModuleHandle(L"DCMods_Main")) {
			pianoData->Position.x = -64;
			pianoData->Position.y = 1.74;
			pianoData->Position.z = 213;
		}
		else
		{
			pianoData->Position.x = -107;
			pianoData->Position.y = 1.76;
			pianoData->Position.z = 132.6;
		}
		pianoData->Rotation.y = 4096;
		pianoData->Scale.x = 1;
		pianoData->Scale.y = 1;
		pianoData->Scale.z = 1;
		InitCollision(piano, &pianoCollision, 1, 4);
		//SetCollisionInfoRadius(radio->Data1->CollisionInfo, 20.0);


	}
}
