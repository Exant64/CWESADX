
#include "dreamcast.h"
#include "CWESADX.h"
#include "data/Flower1.h"
#include "data/Flower2.h"
#include "data/DrumDC.h"
#include "data/DrumStickDC.h"
#include "data/TrumpetToy.h"
#include <random>
void __cdecl NewFlowerObject(ObjectMaster* a1)
{
	EntityData1* v1; // ecx

	v1 = a1->Data1;
	if (a1->Parent->Data1->Rotation.x)
	{
		v1->Scale.x += 0.03f;
		if (v1->Scale.x > 1.0f)
		{
			v1->Scale.x = 1.0f;
			a1->DisplaySub(a1);
			return;
		}
	}
	else
	{
		v1->Scale.x -= 0.03f;
		if (v1->Scale.x < 0.0f)
		{
			v1->Scale.x = 0.0f;
			CheckThingButThenDeleteObject(a1);
		}
	}
	a1->DisplaySub(a1);
}
ObjectMaster* __cdecl Flower_Load(ObjectMaster* a1, NJS_VECTOR* a2)
{
	ObjectMaster* v2; // eax
	EntityData1* v4; // edi
	NJS_VECTOR v6;
	int r = (rand() % 12) - 4; //5 - old value
	v2 = LoadChildObject(LoadObj_Data1, NewFlowerObject, a1);
	v4 = v2->Data1;
	int r2 = (rand() % 12) - 4;
	v6.x = a2->x + r;
	v6.z = a2->z + r2;
	v6.y = a2->y;
	v2->DisplaySub = sub_76EE70;
	v2->DeleteSub = (void(__cdecl*)(ObjectMaster*))nullsub;
	v4->Position = v6;
	v4->Rotation.y = rand() * 0.000030517578f * 360.0f * 65536.0f * 0.002777777777777778f;

	v4->NextAction = ((double)rand() * 0.000030517578f) >= 0.5f;
	return v2;
}


void BreedingFlower2(NJS_CNK_OBJECT* a1)
{
	njSetTexture(&CHAO_TEXLIST);
	sub_408530(&Flower);
}

void BreedingFlower1(NJS_CNK_OBJECT* a1)
{
	njSetTexture(&CHAO_TEXLIST);
	sub_408530(&object_00154C8C);
}

void DrawDCToys(NJS_CNK_OBJECT* a1)
{
	if (!a1)
		return;

	if (a1 == &Trumpet)
	{
		njSetTexture(&CHAO_TEXLIST);
		sub_408530(&object_0014E8E8);
	}
	else
		njCnkDrawObject(a1);
}

DataPointer(NJS_CNK_OBJECT, Drum, 0x036B03C4);
DataPointer(NJS_CNK_OBJECT, DrumStick, 0x036B0AB4);
DataPointer(NJS_CNK_OBJECT, DrumStick2, 0x036B0744);

void DrawDCToys2(NJS_CNK_OBJECT* a1)
{
	if (!a1)
		return;

	if (a1 == &Drum) { njSetTexture(&CHAO_TEXLIST); sub_408530(&object_0014BA44); }
	else if (a1 == &DrumStick || a1 == &DrumStick2) { njSetTexture(&CHAO_TEXLIST); sub_408530(&object_0014BD88); }
	else njCnkDrawObject(a1);
}
