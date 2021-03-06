
#include "SeedGameObject.h"
//probably wont implement this in the end, im just experimenting with it
FunctionPointer(void, __cdecl sub_73EF10, (NJS_VECTOR *a1, float a2), 0x73EF10); 
FunctionPointer(ChaoData2 *, __cdecl AllocateMove, (ObjectMaster *chao), 0x0073FE70);
FunctionPointer(signed int, __cdecl sub_71A340, (ObjectMaster *a1, float a2), 0x71A340);
FunctionPointer(signed int, __cdecl sub_71A360, (ObjectMaster *a1, float a2), 0x71A360); 
FunctionPointer(void, __cdecl sub_740040, (ObjectMaster *a1, float a2), 0x740040);
FunctionPointer(signed int, __cdecl FruitX, (ObjectMaster *a1), 0x007229E0);
void Piano_Display(ObjectMaster * a1);
const int sub_722760Ptr = 0x722760;
void sub_722760(ObjectMaster *a1)
{
	__asm 
	{
		mov edi, a1
		call sub_722760Ptr
	}
}
const int sub_7225F0Ptr = 0x7225F0;
void sub_7225F0(ObjectMaster *a1)
{
	__asm
	{
		mov edi, a1
		call sub_7225F0Ptr
	}
}

const int sub_7227C0Ptr = 0x007227C0;
void sub_7227C0(ObjectMaster *a1)
{
	__asm
	{
		mov eax, a1
		call sub_7227C0Ptr
	}
}

const int sub_722670Ptr = 0x722670;
void sub_722670(ObjectMaster *a1)
{
	__asm
	{
		mov edi, a1
		call sub_722670Ptr
	}
}
void __cdecl Seed_Main(ObjectMaster *a1)
{
	
	ChaoData1 *v2; // esi
	unsigned int v3; // eax
	
	v2 = (ChaoData1*)a1->Data1;
	v3 = v2->entity.Action;
	if (v3 <= 4)
	{
		switch (v3)
		{
		case 0u:
			sub_722760(a1);
			break;
		case 1u:
			sub_7225F0(a1);
			break;
		case 2u:
			sub_722670(a1);
			break;
		case 3u:
		//	FruitHeldEat(a1);
			sub_7227C0(a1);
			break;
		case 4u:
			FruitX(a1);
			break;
		default:
			break;
		}
	}

	Chao_CopyPositionToOtherPosition(a1);
	Chao_AddToCollisionList(a1);
	sub_73EF10(&v2->entity.Position, 0.23999999);
	a1->DisplaySub(a1);
	
}
Sint32 vertex_00F14588[] = { 0xF70029, 0x290000, 0x0, 0x3F968A61, 0x3445D2EB, 0x3F7BF4C0, 0x3E354A75, 0x34AF19F6, 0x0, 0x3F968A61, 0x3445D2EB, 0xBEFBF4BDu, 0x3E354A5A, 0x3F5A334C, 0x0, 0x3F968A61, 0x3445D2EB, 0xBEFBF4B5u, 0x3E354A79, 0xBF5A334Du, 0x0, 0xBCD06CBEu, 0xB450759Fu, 0x32DBCD3E, 0xBF800000u, 0xB4D1E2A2u, 0x3EAA785C, 0x3F2679AB, 0x33413679, 0x3F1F2814, 0x3F488327, 0x34A134EC, 0x3EEC6BEB, 0x3ED170C6, 0xB3252FAAu, 0x3F7E116E, 0x3DFB2140, 0x344C6D8F, 0x3ECB207E, 0x3E20F1D5, 0xB4109168u, 0x3F4032DB, 0xBF291A42u, 0xB40FF693u, 0x3E2A785C, 0x3F2679A9, 0x3E93A1A5, 0x3E9F2811, 0x3F488326, 0x3F09D56B, 0x3E6C6BE8, 0x3ED170C2, 0x3ECCBF43, 0x3EFE116E, 0x3DFB2136, 0x3F5C0787, 0x3E4B207E, 0x3E20F1C9, 0x3EAFE9C0, 0x3EC032DB, 0xBF291A48u, 0x3F2672E5, 0xBE2A7860u, 0x3F2679A9, 0x3E93A1A5, 0xBE9F2812u, 0x3F488326, 0x3F09D56A, 0xBE6C6BEEu, 0x3ED170C2, 0x3ECCBF42, 0xBEFE1171u, 0x3DFB2137, 0x3F5C0787, 0xBE4B2082u, 0x3E20F1C9, 0x3EAFE9C0, 0xBEC032DDu, 0xBF291A48u, 0x3F2672E4, 0xBEAA785Cu, 0x3F2679AB, 0xB26BB2B5u, 0xBF1F2813u, 0x3F488328, 0x3400F723, 0xBEEC6BEEu, 0x3ED170C6, 0xB3F01CE0u, 0xBF7E116Eu, 0x3DFB213D, 0xB3FD19F1u, 0xBECB207Fu, 0x3E20F1D5, 0xB45BAD81u, 0xBF4032D9u, 0xBF291A43u, 0xB4D58B9Eu, 0xBE2A785Cu, 0x3F2679AB, 0xBE93A1A8u, 0xBE9F280Eu, 0x3F48832A, 0xBF09D566u, 0xBE6C6BE6u, 0x3ED170CC, 0xBECCBF46u, 0xBEFE1169u, 0x3DFB2185, 0xBF5C0788u, 0xBE4B207Bu, 0x3E20F1DD, 0xBEAFE9CCu, 0xBEC032D7u, 0xBF291A3Fu, 0xBF2672F0u, 0x3E2A7865, 0x3F2679AB, 0xBE93A1A4u, 0x3E9F2817, 0x3F48832A, 0xBF09D563u, 0x3E6C6BF3, 0x3ED170CC, 0xBECCBF44u, 0x3EFE1176, 0x3DFB218A, 0xBF5C0784u, 0x3E4B208B, 0x3E20F1DD, 0xBEAFE9C9u, 0x3EC032E1, 0xBF291A40u, 0xBF2672EDu, 0xBE4761CBu, 0x3F228813, 0x32280342, 0xBEFBF4BDu, 0x3E354A5A, 0x3F5A334C, 0xBE4761CBu, 0x3F228813, 0x32280342, 0xBEFBF4B5u, 0x3E354A79, 0xBF5A334Du, 0x3DC761DA, 0x3F228813, 0xBE2CAB77u, 0x3F7BF4C0, 0x3E354A75, 0x34AF19F6, 0x3DC761DA, 0x3F228813, 0xBE2CAB77u, 0xBEFBF4B5u, 0x3E354A79, 0xBF5A334Du, 0x3DC761CB, 0x3F228813, 0x3E2CAB7A, 0x3F7BF4C0, 0x3E354A75, 0x34AF19F6, 0x3DC761CB, 0x3F228813, 0x3E2CAB7A, 0xBEFBF4BDu, 0x3E354A5A, 0x3F5A334C, 0x0, 0x3F411869, 0xB277FF50u, 0x32B8DAD5, 0x3F800000, 0x3468738B, 0xBF204C09u, 0x3FBE51C6, 0xBE2CBB84u, 0xBE22BD43u, 0xBF6366E5u, 0xBEDCA099u, 0x3D0BAA64, 0x3F9717B8, 0xBE3F79FCu, 0xBF1B50B8u, 0xBF2D466Cu, 0xBED57006u, 0xBF31BFF9u, 0x3FA8A8CE, 0x3E523781, 0xBE22BD43u, 0xBF6366E5u, 0xBEDCA099u, 0xBD0B949Au, 0x3F816EC6, 0x3E3F7909, 0xBF1B50B8u, 0xBF2D466Cu, 0xBED57006u, 0xBE7FD135u, 0x3FB3C252, 0xBE0CB507u, 0xBECA4DDCu, 0xBF4EC833u, 0xBEE00350u, 0xBEA2D07Au, 0x3F9E195A, 0x3E723DFD, 0xBECA4DDCu, 0xBF4EC833u, 0xBEE00350u, 0x3F2537D4, 0x3FA058A2, 0xBEBA3F3Au, 0x3E767121, 0xBF4931FAu, 0x3F11CF6D, 0x3ACF3086, 0x3F795A97, 0xBE2CBB39u, 0x3F2D4D56, 0xBF17FF73u, 0x3EDEB3B1, 0x3F246759, 0x3FBF849A, 0xBCD82A33u, 0x3E767121, 0xBF4931FAu, 0x3F11CF6D, 0xBAD1C45Du, 0x3F9BD93E, 0x3E2CBDF5, 0x3F2D4D56, 0xBF17FF73u, 0x3EDEB3B1, 0x3E8A5957, 0x3F9679E0, 0xBE9F8F4Au, 0x3EF277D8, 0xBF3646C7u, 0x3F04B759, 0x3E88B862, 0x3FB5A5D8, 0x3CD2D4D3, 0x3EF277D8, 0xBF3646C7u, 0x3F04B759, 0xFF, 0x0 };

Sint16 poly_00F143A0[] = { 0x2513, 0x4, 0xFFB2u, 0xFFCEu, 0x7F7F, 0x7F, 0x1408, 0x4026, 0x241, 0xB5, 0x9, 0x3, 0x1A, 0x248, 0xAC, 0x18, 0x148, 0xAC, 0x0, 0x1A4, 0xFF, 0xFFF8u, 0x3, 0x48, 0x0, 0x9, 0x80, 0x26, 0x6, 0x0, 0x26, 0x8, 0x80, 0x5C, 0x5, 0x0, 0x5C, 0x7, 0x80, 0x8F, 0x4, 0x0, 0x8F, 0x1C, 0x41, 0xA5, 0xFFF8u, 0x1C, 0x239, 0xA5, 0x10, 0x200, 0x8F, 0x13, 0x280, 0x8F, 0x11, 0x200, 0x5C, 0x14, 0x280, 0x5C, 0x12, 0x200, 0x26, 0x15, 0x280, 0x26, 0x3, 0x240, 0x0, 0xFFF8u, 0x3, 0xC0, 0x0, 0xC, 0x100, 0x26, 0x9, 0x80, 0x26, 0xB, 0x100, 0x5C, 0x8, 0x80, 0x5C, 0xA, 0x100, 0x8F, 0x7, 0x80, 0x8F, 0x1C, 0xB9, 0xA5, 0x3, 0x16, 0x48, 0xAC, 0x1B, 0x248, 0xAC, 0x1, 0x1A4, 0xFF, 0xFFF8u, 0x3, 0x138, 0x0, 0xF, 0x180, 0x26, 0xC, 0x100, 0x26, 0xE, 0x180, 0x5C, 0xB, 0x100, 0x5C, 0xD, 0x180, 0x8F, 0xA, 0x100, 0x8F, 0x1C, 0x149, 0xA5, 0x3, 0x19, 0x148, 0xAC, 0x17, 0x48, 0xAC, 0x2, 0x1A4, 0xFF, 0xFFF8u, 0x3, 0x1C8, 0x0, 0x12, 0x200, 0x26, 0xF, 0x180, 0x26, 0x11, 0x200, 0x5C, 0xE, 0x180, 0x5C, 0x10, 0x200, 0x8F, 0xD, 0x180, 0x8F, 0x1C, 0x1C1, 0xA5, 0xFFF8u, 0x1C, 0x2C9, 0xA5, 0x13, 0x280, 0x8F, 0x4, 0x300, 0x8F, 0x14, 0x280, 0x5C, 0x5, 0x300, 0x5C, 0x15, 0x280, 0x26, 0x6, 0x300, 0x26, 0x3, 0x2B8, 0x0, 0x2515, 0x4, 0xB2B2u, 0xFFB2u, 0xFFFFu, 0xBFF, 0x3408, 0x4032, 0x1841, 0x27, 0x2, 0xFFFAu, 0x20, 0x100, 0xFF, 0x1E, 0x0, 0xFF, 0x22, 0x100, 0x7F, 0x21, 0x0, 0x7F, 0x1F, 0x100, 0x0, 0x1D, 0x0, 0x0, 0xFFFAu, 0x24, 0x0, 0xFF, 0x26, 0x100, 0xFF, 0x27, 0x0, 0x7F, 0x28, 0x100, 0x7F, 0x23, 0x0, 0x0, 0x25, 0x100, 0x0, 0xFF };

NJS_CNK_MODEL attach_00F1496C = { vertex_00F14588, poly_00F143A0, { -0.024476f, 0.735396f, 0 }, 1.011944f };

NJS_OBJECT object_00F14984 = { NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &attach_00F1496C, 0, 0, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };

NJS_TEXNAME AL_OBJECT_SA2_TEXNAMES[86];
NJS_TEXLIST AL_OBJECT_SA2_TEXLIST = { arrayptrandlength(AL_OBJECT_SA2_TEXNAMES) };

void Seed_Display(ObjectMaster *a1)
{
	njPushMatrixEx();
	njTranslateV(0, &a1->Data1->Position);
	njRotateY(0, a1->Data1->Rotation.y);
	njSetTexture(&AL_OBJECT_SA2_TEXLIST);
	njCnkDrawObject(&object_00F14984);
	njPopMatrixEx();
}

void Seed_Load(ObjectMaster *a1)
{
	ObjectFunc(OF1, 0x007236C0);
	ObjectFunc(Fruit_Main, 0x00722B70);
	a1->MainSub = Fruit_Main;
	a1->DisplaySub = Seed_Display;
	a1->DeleteSub = OF1;
}
ObjectMaster *__cdecl Seed_Create(int a1, NJS_VECTOR *position, Angle angle, NJS_VECTOR *a4, ChaoData *a5)
{
	ObjectMaster *v5; // esi
	ChaoData1 *v6; // edi
	ChaoData2 *v7; // ebx
	NJS_VECTOR *v8; // ecx
	float v9; // edx
	Angle v10; // ecx

	v5 = LoadObject(LoadObj_Data1, 4, Seed_Load);
	v6 = (ChaoData1*)v5->Data1;
	LoadPVM("al_object_sa2", &AL_OBJECT_SA2_TEXLIST);
	InitCollision(v5, (CollisionData*)0x885268, 3, 5u);
	v7 = AllocateMove(v5);
	DoStatusThing(&v6->entity, (EntityData2 *)v5->Data2, 4);
	v8 = &v6->entity.Position;
	v8->x = position->x;
	v8->y = position->y;
	v9 = position->z;
	v6->entity.Rotation.y = angle;
	v8->z = v9;
	if (a4)
	{
		v7->velocity = *a4;
	}
	v6->entity.Rotation.x = a1;
	//v7->field_48 = -0.05;
	sub_740040(v5, -0.050000001);
	v7->field_AC = 3.0;
	v7->field_C8 = 0.64999998;
	v7->field_D0 = 0.69999999;
	v6->entity.Action = 0;
	v6->entity.NextAction = 0;
	if (a5)
	{
		if (*(short *)a5->data.gap_0 == -1)
		{
			*(short *)&a5->data.gap_0[4] = 4;
		}
		v10 = *(signed __int16 *)&a5->data.gap_0[4];
		*(short *)a5->data.gap_0 = a1;
		v6->entity.Rotation.z = v10;
	}
	else
	{
		v6->entity.Rotation.z = 4;
	}
	AddToGlobalChaoThingMaybe(19, v5, 9, a5);
	sub_71A340(v5, 0.2);
	sub_71A360(v5, 0.34);
	return v5;
}