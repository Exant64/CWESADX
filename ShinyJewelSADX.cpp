// ShinyJewelSADX.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "SADXModLoader.h"
#include "ninja.h"
#include "IniFile.hpp"

#include "StarnutObject.h"
#include "LifenutObject.h"
#include "ChaonutObject.h"
#include "HastnutObject.h"

#include "CherryObject.h"
#include "GrapeObject.h"
#include "LemonObject.h"
#include "PlumObject.h"

#include "CustomTree.h"
#include "Flower1.h"
#include "Flower2.h"

extern "C"
{
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer};

	struct BlackMarketItemAttributes { int PurchasePrice; int SalePrice; short RequiredEmblems; short Name; short Description; short Unknown; };

	DataPointer(int, dword_34BBA10, 0x34BBA10); // unknown
	DataPointer(int, dword_34BBA0C, 0x34BBA0C);
	DataPointer(LPVOID, dword_3CA6E90, 0x3CA6E90);
	DataArray(int, dword_33B87E0, 0x33B87E0, 3);
	DataArray(int, dword_33B87B4, 0x33B87B4, 10);

	DataPointer(NJS_OBJECT, ChaoNormalUnriped, 0x3606958); //The unriped version of fruit
	DataPointer(NJS_TEXLIST, ChaoNmlfruitTexlist, 0x33A1338); //Texlist of normal fruit
															 
	DataArray(ChaoData, chaobases, 0x03C88878, 24); //All the chaodata	

	FunctionPointer(bool, CheckAnimalPart, (ObjectMaster* a1, char a2), 0x734E90); 
	FunctionPointer(void, GardenFruit_Create, (int a1, NJS_VECTOR *position, Angle angle, NJS_VECTOR *a4, ChaoData *a5), 0x722DE0);
	FunctionPointer(void, sub_717470, (int a1), 0x717470);
	FunctionPointer(void, sub_425860, (int a1), 0x425860);
	FunctionPointer(void, sub_408530, (NJS_OBJECT *a1), 0x408530);
	FunctionPointer(void, sub_7179F0, (int a1), 0x7179F0);
	//sub_7290B0
	FunctionPointer(void, sub_7290B0, (), 0x7290B0);
	//sub_72A750
	//LoadAnimalPVMs
	FunctionPointer(void, LoadAnimalPVMs, (), 0x722520);
	FunctionPointer(void, sub_72A750, (), 0x72A750);
	FunctionPointer(void, sub_72A570, (), 0x72A750);
	FunctionPointer(void, sub_724E60, (), 0x724E60);
	FunctionPointer(void, sub_728DD0, (float a1, float a2, float a3, float a4), 0x728DD0);
	//sub_72C010
	//sub_715F20
	FunctionPointer(void, sub_722500, (), 0x722500);
	FunctionPointer(void, sub_715F20, (), 0x715F20);
	FunctionPointer(void, sub_72C010, (ObjectMaster *a1), 0x72C010);
	FunctionPointer(void, SetChunkMaterialFlag, (int a1), 0x78A2F0);
	FunctionPointer(void, EnableMatFlag, (), 0x78A2D0);
	FunctionPointer(void, DisableMatFlag, (), 0x78A2E0);
	//sub_72BDD0
	ObjectFunc(sub_72BDD0, 0x72BDD0);
	FunctionPointer(void, ColorChunkModel, (int a1), 0x78A320);
	FunctionPointer(int, GetMaterialIndex, (NJS_CNK_MODEL* a1), 0x78ABE0);

	//Chao colors
	DataArray(int, ChaoColorArray, 0x389D824, 24); //Not necessarily 24 long, I just set a random value to make it work. Lazy stuff, I know.
	
	DataArray(BlackMarketItemAttributes, FruitItemAttr, 0x00884728,24);

	DataPointer(NJS_CNK_OBJECT, TV, 0x3896F1C); //chao
												//0389B3E4
	DataPointer(NJS_CNK_OBJECT, Radio, 0x389B3E4); //chao
	DataPointer(NJS_CNK_OBJECT, BreedingFlower, 0x3895B2C);

	
	ObjectFunc(sub_76EE00, (void*)0x76EE00);
	FunctionPointer(void, sub_76EE70, (ObjectMaster *a1),(void*)0x76EE70);

	//Introducing, the messiest cpp of the year.
	void __cdecl NewFlowerObject(ObjectMaster *a1)
	{
		EntityData1 *v1; // ecx
		double v2; // st7
		double v3; // st7
		double v4; // st7

		v1 = a1->Data1;
		v2 = v1->Scale.x;
		if (a1->Parent->Data1->Rotation.x)
		{
			v3 = v2 + 0.03;
			v1->Scale.x = v3;
			if (v3 > 1.0)
			{
				v1->Scale.x = 1.0;
				a1->DisplaySub(a1);
				return;
			}
		}
		else
		{
			v4 = v2 - 0.03;
			v1->Scale.x = v4;
			if (v4 < 0.0)
			{
				v1->Scale.x = 0.0;
				CheckThingButThenDeleteObject(a1);
			}
		}
		a1->DisplaySub(a1);
	}
	ObjectMaster *__cdecl Flower_Load(ObjectMaster *a1, NJS_VECTOR *a2)
	{
		ObjectMaster *v2; // eax
		ObjectMaster *v3; // esi
		EntityData1 *v4; // edi
		double v5; // st7
		ObjectMaster *result; // eax
		NJS_VECTOR *v6;
		int r = (rand() % 12) - 4; //5 - old value

		v6 = a2;
		v2 = LoadChildObject(LoadObj_Data1, NewFlowerObject, a1);
		v3 = v2;
		v4 = v2->Data1;
		v6->x = a2->x + r;
		int r2 = (rand() % 12) - 4;
		v6->z = a2->z + r2;
		v6->y = a2->y;
		v2->DisplaySub = sub_76EE70;
		v2->DeleteSub = (void(__cdecl *)(ObjectMaster *))nullsub;
		v4->Position = *v6;
		v4->Rotation.y = (unsigned __int64)((double)rand() * 0.000030517578 * 360.0 * 65536.0 * 0.002777777777777778);
		v5 = (double)rand() * 0.000030517578;
		result = v3;
		v4->NextAction = v5 >= 0.5;
		return result;
	}

	void TV_Display(ObjectMaster *a1)
	{
		EntityData1 *boi;

		boi = a1->Data1;

		njPushMatrixEx();
		njSetTexture(&AL_TOY_TEXLIST);
		//njControl3D_Add(NJD_CONTROL_3D_TRANS_MODIFIER | NJD_CONTROL_3D_SHADOW);
		njTranslate(0, boi->Position.x, boi->Position.y, boi->Position.z);
		njCnkDrawObject(&TV);
		//njControl3D_Remove(NJD_CONTROL_3D_TRANS_MODIFIER | NJD_CONTROL_3D_SHADOW);
		njPopMatrixEx(); 
	}
	void TV_Main(ObjectMaster *a1) 
	{
		//Custom code here maybe one day.
		a1->DisplaySub(a1);
	}
	void TV_Load(ObjectMaster *a1) 
	{
		a1->MainSub = (void(__cdecl *)(ObjectMaster *))TV_Main;
		a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))TV_Display;
	}
	void PlaceTV()
	{
		ObjectMaster *tv;
		EntityData1 *tvData;
		ObjectFunc(OF0, TV_Load);

		tv = LoadObject(LoadObj_Data1, 1, OF0);
		tv->DisplaySub = TV_Display;
		tvData = tv->Data1;
		if (tv)
		{
			tvData->Position.x = -49;
			tvData->Position.y = 0;
			tvData->Position.z = -120;
			tvData->Scale.x = 1;
			tvData->Scale.y = 1;
			tvData->Scale.z = 1;
		}
	}

	void PlaceCustomTree() 
	{
		ObjectMaster *tv;
		EntityData1 *tvData;
		ObjectFunc(OF0, Tree_Load);

		tv = LoadObject(LoadObj_Data1, 1, OF0);
		tvData = tv->Data1;
		if (tv)
		{
			tvData->Position.x = -49;
			tvData->Position.y = 0;
			tvData->Position.z = -120;
			tvData->Scale.x = 1;
			tvData->Scale.y = 1;
			tvData->Scale.z = 1;
		}
	}

	//TODO: Project cleanup with headers and stuff so I can actually look at it.
	void Radio_Display(ObjectMaster *a1)
	{
		EntityData1 *boi;

		boi = a1->Data1;

		njPushMatrixEx();
		njSetTexture(&AL_TOY_TEXLIST);
		//njControl3D_Add(NJD_CONTROL_3D_TRANS_MODIFIER | NJD_CONTROL_3D_SHADOW);
		njTranslate(0, boi->Position.x, boi->Position.y, boi->Position.z);
		njCnkDrawObject(&Radio);
		//njControl3D_Remove(NJD_CONTROL_3D_TRANS_MODIFIER | NJD_CONTROL_3D_SHADOW);
		njPopMatrixEx();
	}
	void Radio_Main(ObjectMaster *a1)
	{
		//Custom code here maybe one day.
		a1->DisplaySub(a1);
	}
	void Radio_Load(ObjectMaster *a1)
	{
		a1->MainSub = (void(__cdecl *)(ObjectMaster *))Radio_Main;
		a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))Radio_Display;
	}
	void PlaceRadio()
	{
		ObjectMaster *radio;
		EntityData1 *radioData;
		ObjectFunc(OF0, Radio_Load);

		radio = LoadObject(LoadObj_Data1, 1, OF0);
		radio->DisplaySub = TV_Display;
		radioData = radio->Data1;
		if (radio)
		{
			radioData->Position.x = -85;
			radioData->Position.y = 2;
			radioData->Position.z = 43;
			radioData->Scale.x = 1;
			radioData->Scale.y = 1;
			radioData->Scale.z = 1;
		}
	}


	void LoadSSGardenNew()
	{
		PrintDebug("ChaoStgGarden00SS Prolog begin\n");
		LoadObject(LoadObj_Data1, 2, ChaoStgGarden00SS_Load);
		SetChaoLandTable(&Geo_SSGarden);
		PlaceTV();
		PlaceCustomTree();
		NJS_VECTOR vec;
		vec.x = -49;
		vec.y = 0;
		vec.z = -120;
		
		
		ObjectMaster *obj = CreateChao(&chaobases[0], 0, 0, &vec, (unsigned __int64)((double)rand()* 0.000030517578 * 360.0 * 65536.0 * 0.002777777777777778));
		ChaoData2 *data = (ChaoData2*)obj->Data2;    
		NJS_VECTOR* idk1 = (NJS_VECTOR*)data->field_0[4];
		NJS_VECTOR* idk2 = (NJS_VECTOR*)data->field_0[10];
		idk2 = &vec;
		PrintDebug("ChaoStgGarden00SS Prolog end\n");
	}
	
	void __cdecl LoadECGardenNew()
	{
		PrintDebug("ChaoStgGarden01EC Prolog begin\n");
		LoadObject(LoadObj_Data1, 2, ChaoStgGarden01EC_Load);
		PlaceRadio();
		SetChaoLandTable(&Geo_ECGarden);
		PrintDebug("ChaoStgGarden01EC Prolog end\n");
	}

	void __cdecl Chao_LoadTreesCustom()
	{
		int v0; // eax
		int stage; // eax
		int v2; // esi
		NJS_VECTOR *v3; // edi
		signed int i; // ebx
		Uint8 *v5; // eax
		
		ObjectMaster *obj;

		v0 = GetCurrentChaoStage();
		if (v0 >= SADXChaoStage_StationSquare && v0 <= SADXChaoStage_MysticRuins)
		{
			stage = v0 - 4;
			v2 = 0x28 * stage;
			v3 = &ChaoTreeSpawns[stage].a;
			i = 5;
			do
			{
				v5 = GetChaoSaveAddress();
				obj = Chao_CreateTree(v3, (int)&v5[v2 + 28]);
				
				v2 += 8;
				++v3;
				--i;
			} while (i);
			sub_7179F0(2); //I'm pretty sure this initializes specific types of garden objects.
			sub_7179F0(3); //2 - animal, 3-fruit, 9-hat
			sub_7179F0(9);
		}
	}

	FunctionPointer(void, sub_720DF0, (int a1, NJS_OBJECT *a2), 0x720DF0);
	void DrawSeedTree(NJS_OBJECT *a1, int a2)
	{
		NJS_OBJECT *v2; // esi
		NJS_OBJECT *v3; // esi

		v2 = a1;
		njSetTexture(&AL_DX_OBJ_CMN_TEXLIST);
		njPushMatrixEx();
		njTranslateV(0, (NJS_VECTOR *)v2->pos);
		njRotateXYZ(0, v2->ang[0], v2->ang[1], v2->ang[2]);
		DrawModel((NJS_MODEL_SADX*)v2->model);
		if (v2->child)
		{
			sub_720DF0(a2, v2->child);
		}
		njPopMatrixEx();
		v3 = v2->sibling;
		if (v3)
		{
			sub_720DF0(a2, v3);
		}
	}
	//Evolution code that checks for requirements and sets chaotype accordingly
	void __cdecl Evolution(ObjectMaster *a1, ChaoType type)
	{
		ChaoType typeA = type;
		ChaoData1* data = (ChaoData1*)&a1->Data1;
		float runpower = data->ChaoDataBase_ptr->PowerRun;
		float swimfly  = data->ChaoDataBase_ptr->FlySwim;
		if (typeA >= ChaoType_Neutral_Chaos) 
		{
			if(runpower == 1)
			{
				typeA = ChaoType_Knuckles;
			}
			else typeA = ChaoType_Amy;
			if (swimfly == 1) typeA = ChaoType_Tails;
		}
		ResetChao(a1, typeA);
	}

	void Chao_ChangeWaypoint(ObjectMaster *a1)
	{
		NJS_VECTOR vec;
		vec.x = -49;
		vec.y = 0;
		vec.z = -120;


		ChaoData2 *data = (ChaoData2*)a1->Data2;
		NJS_VECTOR* idk1 = (NJS_VECTOR*)data->field_0[4];
		NJS_VECTOR* idk2 = (NJS_VECTOR*)data->field_0[10];
		idk2 = &vec;
		idk1 = &vec;
		data->some_vector = vec;
	}

	/*00 00 00 00 | 00 00 00 00 |  00 00 00 00  | 64 90 3B 03  | 44 9A 3B 03  | 5C 9E 3B 03  | 04 A3 3B 03  | 54 AC 3B 03  | 14 B5 3B 03 - done  | F4 BF 3B 03  | 74 C5 3B 03  | C4 CB 3B 03  | 4C D1 3B 03  | 04 D7 3B 03  | 
	74 DE 3B 03  | 7C E5 3B 03  | CC F7 3B 03  | EC F2 3B 03  | 94 EC 3B 03  | 9C FE 3B 03  | 6C 05 3C 03  | 6C 05 3C 03  | 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 74 8C 3B 03 54 95 3B 03 5C 9E 3B 03 04 A3 3B 03 54 AC 3B 03 14 B5 3B 03 F4 BF 3B 03 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00*/
	//Offsets of fruits above, used for reference so I don't need to open HxD each time.
	DataPointer(NJS_CNK_OBJECT, ChaoFruitModel3, 0x33B9064);
	DataPointer(NJS_CNK_OBJECT, ChaoFruitModel4, 0x33B9A44);
	DataPointer(NJS_CNK_OBJECT, ChaoFruitModel5, 0x33B9E5C); //hero
	DataPointer(NJS_CNK_OBJECT, ChaoFruitModel6, 0x33BA304); //dark
	DataPointer(NJS_CNK_OBJECT, ChaoFruitModel7, 0x33BAC54); //round
	DataPointer(NJS_CNK_OBJECT, ChaoFruitModel8, 0x33BB514); //triangular
	DataPointer(NJS_CNK_OBJECT, ChaoFruitModel9, 0x33BBFF4); //square
	DataPointer(NJS_CNK_OBJECT, ChaoFruitModel10, 0x33BC574); //heart
	DataPointer(NJS_CNK_OBJECT, ChaoFruitModel11, 0x33BCBC4); //chao

	//Fruit edit.
	void DreamcastFruitEdit(NJS_CNK_OBJECT *a1)
	{
		njSetTexture(&CHAO_OBJECT_TEXLIST);
		njScale(0, 0.7f, 0.7f, 0.7f);
		
		if (a1 == &ChaoFruitModel5) sub_408530(&object_0017D57C);

		else if (a1 == &ChaoFruitModel7) sub_408530(&object_0017E918);
		else if (a1 == &ChaoFruitModel8) sub_408530(&object_0017EDE8);
		else if (a1 == &ChaoFruitModel9) sub_408530(&object_0017DF78);

		else if (a1 == &ChaoFruitModel6) sub_408530(&object_0017DAA8);
		else if (a1 == &ChaoFruitModel10) sub_408530(&object_0017F384);
		else if (a1 == &ChaoFruitModel11) sub_408530(&object_0017D068);
		else { njSetTexture(&AL_OBJECT_TEXLIST); njCnkDrawObject(a1); } //for fruit that isn't modified
		
	}

	//Bright chao testing. Not used in builds for now, but I might make a mod for those who prefer it
	void __cdecl ChaoColoring(int texture, int color, int shiny, int monotone, NJS_CNK_MODEL *a5)
	{
		signed int v5; // esi@1
		__int16 v6; // ax@3
		bool v7; // zf@4
		__int16 v8; // ax@12

		v5 = 0;
		if (!a5)
			return;
		if (shiny)
		{
			v5 = 6;
			
			v6 = GetMaterialIndex(a5);
			SetChunkTextureIndexA(34);
			SetChunkTextureIndexA((unsigned __int16)v6);
			
		LABEL_6:
			v7 = texture == 0;
			goto LABEL_7;
		}
		v7 = texture == 0;
		if (texture > 0)
		{
			v5 = 12;
			ColorChunkModel(-1);
			SetChunkTextureIndexA(texture + 17);
			goto LABEL_6;
		}
	LABEL_7:
		if (v7)
		{
			if (color > 0)
			{
				v5 |= 8u;
				ColorChunkModel(ChaoColorArray[color]);
			}
			if (monotone)
			{
				v5 |= 1u;
			}
			else
			{
				v8 = GetMaterialIndex(a5);
				SetChunkTextureIndexA((unsigned __int16)v8);
			}
		}
		if (v5)
		{
			EnableMatFlag();
			SetChunkMaterialFlag(v5);
		}
		else
		{
			DisableMatFlag();
			SetChunkMaterialFlag(0);
		}
	}

	//Thanks PkR.
	void __cdecl EggColoring(NJS_CNK_MODEL *a1, int a2)
	{
		__int16 v2; // ax@4
		__int16 v3; // ax@5
		int v4; // ecx@6
		__int16 v5; // ax@8
		DataArray(int, off_389D780, 0x389D780, 4);
		DataArray(int, off_389D7B8, 0x389D7B8, 4);
		DataArray(int, dword_389D7B8, 0x389D7B8, 6);
		DataPointer(D3DMATRIX, stru_389D7E8, 0x0389D7E8);
		DataArray(NJS_TEXLIST, ChaoTexLists, 0x033A1038, 7);
		DataArray(int, dword_389D828, 0x389D828, 13);
		DataArray(int, dword_088A3D8, 0x088A3D8, 13);	
		switch (a2)
		{
		case SADXEggColour_Black_TwoTone:
		case SADXEggColour_Normal:
			DisableChunkMaterialFlags();
			break;
		case SADXEggColour_Yellow_MonoTone:
		case SADXEggColour_White_MonoTone:
		case SADXEggColour_Brown_MonoTone:
		case SADXEggColour_Aqua_MonoTone:
		case SADXEggColour_Pink_MonoTone:
		case SADXEggColour_Blue_MonoTone:
		case SADXEggColour_Grey_MonoTone:
		case SADXEggColour_Green_MonoTone:
		case SADXEggColour_Red_MonoTone:
		case SADXEggColour_LightGreen_MonoTone:
		case SADXEggColour_Purple_MonoTone:
		case SADXEggColour_Orange_MonoTone:
		case SADXEggColour_Black_MonoTone:
			EnableChunkMaterialFlags();
			SetChunkMaterialFlags(9u);
			ColorChunkModel(dword_389D828[a2 - SADXEggColour_Yellow_MonoTone]);
			break;
		case SADXEggColour_Yellow_TwoTone:
		case SADXEggColour_White_TwoTone:
		case SADXEggColour_Brown_TwoTone:
		case SADXEggColour_Aqua_TwoTone:
		case SADXEggColour_Pink_TwoTone:
		case SADXEggColour_Blue_TwoTone:
		case SADXEggColour_Green_TwoTone:
		case SADXEggColour_Red_TwoTone:
		case SADXEggColour_LightGreen_TwoTone:
		case SADXEggColour_Purple_TwoTone:
		case SADXEggColour_Orange_TwoTone:
		case SADXEggColour_Grey_TwoTone:
			EnableChunkMaterialFlags();
			SetChunkMaterialFlags(8u);
			v2 = GetChunkTextureIndex(a1);
			SetChunkTextureIndexA((unsigned __int16)v2);
			ColorChunkModel(dword_389D828[a2 - SADXEggColour_Yellow_TwoTone]);
			break;
		case SADXEggColour_NormalShiny:
			EnableChunkMaterialFlags();
			SetChunkMaterialFlags(6u);
			Direct3D_SetTexList(ChaoTexLists);
			v3 = GetChunkTextureIndex(a1);
			SetChunkTextureIndexA((unsigned __int16)v3);
			SetChunkTextureIndexB(0x22u);
			break;
		case SADXEggColour_YellowShiny_MonoTone:
		case SADXEggColour_WhiteShiny_MonoTone:
		case SADXEggColour_BrownShiny_MonoTone:
		case SADXEggColour_AquaShiny_MonoTone:
		case SADXEggColour_PinkShiny_MonoTone:
		case SADXEggColour_BlueShiny_MonoTone:
		case SADXEggColour_GreyShiny_MonoTone:
		case SADXEggColour_GreenShiny_MonoTone:
		case SADXEggColour_RedShiny_MonoTone:
		case SADXEggColour_LightGreenShiny_MonoTone:
		case SADXEggColour_PurpleShiny_MonoTone:
		case SADXEggColour_OrangeShiny_MonoTone:
		case SADXEggColour_BlackShiny_MonoTone:
			EnableChunkMaterialFlags();
			SetChunkMaterialFlags(15u);
			Direct3D_SetTexList(ChaoTexLists);
			v4 = dword_389D828[a2 - SADXEggColour_YellowShiny_MonoTone];
			goto LABEL_8;
		case SADXEggColour_YellowShiny_TwoTone:
		case SADXEggColour_WhiteShiny_TwoTone:
		case SADXEggColour_BrownShiny_TwoTone:
		case SADXEggColour_AquaShiny_TwoTone:
		case SADXEggColour_PinkShiny_TwoTone:
		case SADXEggColour_BlueShiny_TwoTone:
		case SADXEggColour_GreyShiny_TwoTone:
		case SADXEggColour_GreenShiny_TwoTone:
		case SADXEggColour_RedShiny_TwoTone:
		case SADXEggColour_LightGreenShiny_TwoTone:
		case SADXEggColour_PurpleShiny_TwoTone:
		case SADXEggColour_OrangeShiny_TwoTone:
		case SADXEggColour_BlackShiny_TwoTone:
			EnableChunkMaterialFlags();
			SetChunkMaterialFlags(0xEu);
			Direct3D_SetTexList(ChaoTexLists);
			v4 = off_389D780[a2 + 1];
		LABEL_8:
			ColorChunkModel((int)v4);
			v5 = GetChunkTextureIndex(a1);
			SetChunkTextureIndexA((unsigned __int16)v5);
			SetChunkTextureIndexB(0x22u);
			break;
		case SADXEggColour_YellowJewel:
		case SADXEggColour_WhiteJewel:
		case SADXEggColour_PinkJewel:
		case SADXEggColour_BlueJewel:
		case SADXEggColour_GreenJewel:
		case SADXEggColour_PurpleJewel:
		case SADXEggColour_AquaJewel:
		case SADXEggColour_RedJewel:
		case SADXEggColour_BlackJewel:
		case SADXEggColour_LightGreenJewel:
		case SADXEggColour_OrangeJewel:
		case SADXEggColour_Pearl:
		case SADXEggColour_Metal1:
		case SADXEggColour_Metal2:
		case SADXEggColour_Glass:
			EnableChunkMaterialFlags();
			SetChunkMaterialFlags(4u);
			Direct3D_SetTexList(ChaoTexLists);
			ColorChunkModel(-1);
			SetChunkTextureIndexA(a2 - 36);
			break;
		//Edited part, added shiny jewel eggs.
		case 69:
		case 71:
		case 72:
		case 73:
		case 74:
		case 75:
		case 76:
		case 77:
		case 78:
		case 79:
		case 80:
		case 81:
		case 82:
			EnableChunkMaterialFlags();
			SetChunkMaterialFlags(0xEu);
			Direct3D_SetTexList(ChaoTexLists);
			v4 = dword_088A3D8[a2 - SADXEggColour_Glass];
			ColorChunkModel((int)v4);
			v5 = GetChunkTextureIndex(a1);
			SetChunkTextureIndexA((unsigned __int16)v5);
			SetChunkTextureIndexB(0x22u);
		default:
			return;
		}
	}

	//Used this for color mixing, there's probably a lot easier solution, I just prefered this.
	struct Color
	{
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;

		Color(unsigned char _b, unsigned char _g, unsigned char _r)
		{
			r = _r;
			g = _g;
			b = _b;
			a = 0xff;
		}
	};


	void SeedTree(NJS_OBJECT *a1)
	{
		njSetTexture(&CHAO_OBJECT_TEXLIST);
		//sub_408530(&object_0017F384);
		
	}

	//Shiny Jewel Patch SADX
	void PatchShinyJewelPC()
	{
		WriteData((char*)0x088A3DB, (char)0xA0);
		WriteData((char*)0x088A3DF, (char)0xA0);
		WriteData((char*)0x088A3E3, (char)0xA0);
		WriteData((char*)0x088A3E7, (char)0xA0);
		WriteData((char*)0x088A3EB, (char)0xA0);
		WriteData((char*)0x088A3EF, (char)0xA0);
		WriteData((char*)0x088A3F3, (char)0xA0);
		WriteData((char*)0x088A3F7, (char)0xA0);
		WriteData((char*)0x088A3FB, (char)0xA0);
		WriteData((char*)0x088A3FF, (char)0xA0);
		WriteData((char*)0x088A403, (char)0xA0);
		WriteData((char*)0x088A407, (char)0xA0);
		WriteData((char*)0x088A40B, (char)0xA0);
		WriteData((char*)0x088A40F, (char)0xA0);
		WriteData((char*)0x088A413, (char)0xA0);
		WriteData((char*)0x088A417, (char)0xA0);
		WriteData((char*)0x088A41B, (char)0xA0);
		WriteData((char*)0x088A41F, (char)0xA0);
		WriteData((char*)0x088A423, (char)0xA0);
		WriteData((char*)0x088A427, (char)0xA0);
		WriteData((char*)0x088A42B, (char)0xA0);
		WriteData((char*)0x088A42F, (char)0xA0);
		WriteData((char*)0x088A433, (char)0xA0);
		WriteData((char*)0x088A437, (char)0xA0);
		WriteData((char*)0x088A43B, (char)0xA0);
		WriteData((char*)0x088A43F, (char)0xA0);
		WriteData((char*)0x088A443, (char)0xA0);
		WriteData((char*)0x088A447, (char)0xA0);
		WriteData((char*)0x088A44B, (char)0xA0);
	}

	bool colorMixing;
	bool monsterEvo;
	bool randomMouthAndEye;
	bool shinyjewelegg;

	void BreedingFlower2(NJS_CNK_OBJECT *a1)
	{
		njSetTexture(&CHAO_TEXLIST);		
		PrintDebug("Flower2");
		sub_408530(&Flower);
	}

	void BreedingFlower1(NJS_CNK_OBJECT *a1)
	{
		njSetTexture(&CHAO_TEXLIST);
		PrintDebug("Flower1");
		sub_408530(&object_00154C8C);
	}

	FunctionPointer(signed int, sub_7633A0, (ObjectMaster *a1), 0x7633A0);
	//sub_7645B0
	FunctionPointer(signed int, sub_7645B0, (ObjectMaster *a1), 0x7645B0);

	FunctionPointer(bool, HeroTypeCheck, (ObjectMaster *a1), 0x007306B0);
	FunctionPointer(bool, DarkTypeCheck, (ObjectMaster *a1), 0x007306F0);
	FunctionPointer(int, DrawToy, (ObjectMaster *a1, int a2, NJS_CNK_OBJECT *model, NJS_TEXLIST *texlist), 0x00734AF0);

	FunctionPointer(void, Chao_Rattle, (ObjectMaster *a1), 0x00763300);

	//00763345
	void CaptureChaoMain(ObjectMaster *a1) 
	{
		//debug for now, but add custom actions here
		Chao_Rattle(a1); //I just added this for debugging reason
	}
	
	DataPointer(NJS_CNK_OBJECT, NormalRattle, 0x36B6E6C);
	DataPointer(NJS_CNK_OBJECT, HeroRattle, 0x36B66B4);
	DataPointer(NJS_CNK_OBJECT, DarkRattle, 0x36B58EC);

	void HeroDarkRattle(ObjectMaster *a1, int a2, NJS_CNK_OBJECT *model, NJS_TEXLIST *texlist)
	{
		if(HeroTypeCheck(a1))
		{
			DrawToy(a1, a2, &HeroRattle, &AL_TOY_TEXLIST);
		}
		else if (DarkTypeCheck(a1))
		{
			DrawToy(a1, a2, &DarkRattle, &AL_TOY_TEXLIST);
		}
		else
		{
			DrawToy(a1, a2, &NormalRattle, &AL_TOY_TEXLIST);
		}
	}

	FunctionPointer(void, Chao_SetMouth, (ObjectMaster *a1, int a2, int a3), 0x00737190);

	void Chao_Tantrum(ObjectMaster *a1, int a2, int a3)
	{
		Chao_SetMouth(a1, a2, a3);
		QueueSound_XYZ(1002, a1->Data1, 1, 120, a1->Data1->Position.x, a1->Data1->Position.y, a1->Data1->Position.z, 200);
	}
	__declspec(dllexport) void Init(const char *path)
	{
		const IniFile *config = new IniFile(std::string(path) + "\\config.ini");

		//Was experimenting with custom tree fruit. Coming soon. 
		//WriteCall((void*)0x721040, SeedTree);
		//ChaoFruitModel5.model= TV.model;
			
		//WriteCall((void*)0x76EED8, OverrideBreeding);
		//WriteCall((void*)0x76EEF0, OverrideBreeding);
		
		WriteJump((void*)0x00719600, LoadSSGardenNew); //tv
		WriteJump((void*)0x007191D0, LoadECGardenNew); //radio
		WriteCall((void*)0x0076237E, Chao_Tantrum); //first custom sound
		WriteCall((void*)0x00763345, HeroDarkRattle); //unused rattles
		WriteCall((void*)0x00720304, CaptureChaoMain); //debug
	
		

		/*
		for (int i = 13; i < 20; i++) 
		{
			if (i < 18) 
			{
				FruitItemAttr[i].SalePrice = 200;
				FruitItemAttr[i].Name = 74 + i - 13;
				FruitItemAttr[i].Description = 74 + i - 13;
			}
			else
			{
				FruitItemAttr[i].SalePrice = 200;
				FruitItemAttr[i].Name = 106 + i - 13;
				FruitItemAttr[i].Description = 106 + i - 13;
			}
		}
		*/
		//I was experimenting with recreating brights in sadx to find out the issue in sa2. This is extremely WIP and doesn't work exactly like in SA2.
		if (config->getBool("Chao World Extended", "BrightChao", true))
		{
			WriteJump((void*)0x78AE30, ChaoColoring);
		}
		//Shiny Jewel egg patch.
		if (config->getBool("Chao World Extended", "ShinyJewelEgg", true))
		{
			shinyjewelegg = true;
			WriteJump((void*)0x78AC80, EggColoring);
		}
		//Shiny Jewels are now transparent
		if (config->getBool("Chao World Extended", "ShinyJewelPC", true))
			PatchShinyJewelPC();
		//Chaos Chao patch
		if (config->getBool("Chao World Extended", "CharacterEvolve", true))
			PrintDebug("Character Chao evolution not available yet");//WriteCall ((void*)0x0073C957, Evolution);
		//Dreamcast stuff
		if (config->getBool("Chao World Extended", "Dreamcast", true)) 
		{
			WriteCall((void*)0x00722D3B, DreamcastFruitEdit);
			WriteJump((void*)0x0076EF10, Flower_Load);
			WriteCall((void*)0x0076EED8, BreedingFlower1);
			WriteCall((void*)0x0076EEF0, BreedingFlower2);
			WriteData((char*)0x034BBACA, (char)0x09); //amount of flowers that pop up, in dreamcast there are 9. gotta go for that accuracy
		}

		colorMixing = config->getBool("Chao World Extended", "ColorMixing", true);
		monsterEvo = config->getBool("Chao World Extended", "MonsterEvo", true);
		randomMouthAndEye = config->getBool("Chao World Extended", "RandomMEye", true);

		delete config;
	}

	FunctionPointer(int, sub_71A2D0, (int a1), 0x71A2D0);


	_declspec (dllexport) void OnFrame(const char *path)
	{
		
		Color colors[] = { Color(255,255,255),Color(0, 255, 255), Color(255,255,255), Color(0x00, 0x64, 0x96), Color(0xFA, 0xD2, 0), Color(0xE6, 0x78, 0xFF), Color(0xFF, 0x46, 0x3C), Color(0x8C, 0x8C, 0x8C), 
			Color(0, 0x96, 0), Color(0, 0, 0xFF), Color(0, 0xFF, 0xAA),Color(0xFF, 0, 0xB4), Color(0, 0x7D, 0xFF), Color(0x37,0x37,0x37) };
		if (IsLevelChaoGarden())
		{
			/*
			for (int i = 13; i < 20; i++) 
		{
			if (i < 18) 
			{
				FruitItemAttr[i].SalePrice = 200;
				FruitItemAttr[i].Name = 74 + i - 13;
				FruitItemAttr[i].Description = 74 + i - 13;
			}
			else
			{
				FruitItemAttr[i].SalePrice = 200;
				FruitItemAttr[i].Name = 106 + i - 13;
				FruitItemAttr[i].Description = 106 + i - 13;
			}
		}*/
			for (char i = 0; i < 24; i++)
			{
				//Color Mixing				
				if (colorMixing && chaobases[i].data.DNA.Color1 > 0 && chaobases[i].data.DNA.Color2 > 0 && chaobases[i].data.DNA.Color1 != chaobases[i].data.DNA.Color2 && chaobases[i].data.Texture == 0)
				{
					WriteData((char*)0x389D85C + i * 4, (char)(colors[chaobases[i].data.DNA.Color1].b * 0.5f + colors[chaobases[i].data.DNA.Color2].b * (1 - 0.5f)));
					WriteData((char*)0x389D85D + i * 4, (char)(colors[chaobases[i].data.DNA.Color1].g * 0.5f + colors[chaobases[i].data.DNA.Color2].g * (1 - 0.5f)));
					WriteData((char*)0x389D85E + i * 4, (char)(colors[chaobases[i].data.DNA.Color1].r * 0.5f + colors[chaobases[i].data.DNA.Color2].r * (1 - 0.5f)));
					WriteData((char*)0x389D85F + i * 4, (char)0xFF);
					chaobases[i].data.Color = 14 + i;
				}
				
				//Monster evolution	
				if (monsterEvo && chaobases[i].data.Type > ChaoType_Child)
				{
					if (chaobases[i].data.SwimStat >= 2000 && chaobases[i].data.FlySwim == -1 && chaobases[i].data.EvolutionProgress >= 1.0f)
					{
						chaobases[i].data.EvolutionProgress = 1.2f;
						chaobases[i].data.FlySwim = -1.5f;
					}
					if (chaobases[i].data.FlyStat >= 2000 && chaobases[i].data.FlySwim == 1 && chaobases[i].data.EvolutionProgress >= 1.0f)
					{
						chaobases[i].data.EvolutionProgress = 1.2f;
						chaobases[i].data.FlySwim = 1.5f;
					}
					if (chaobases[i].data.RunStat >= 2000 && chaobases[i].data.PowerRun == -1 && chaobases[i].data.EvolutionProgress >= 1.0f)
					{
						chaobases[i].data.EvolutionProgress = 1.2f;
						chaobases[i].data.PowerRun = -1.5f;
					}
					if (chaobases[i].data.PowerStat >= 2000 && chaobases[i].data.PowerRun == 1 && chaobases[i].data.EvolutionProgress >= 1.0f)
					{
						chaobases[i].data.EvolutionProgress = 1.2f;
						chaobases[i].data.PowerRun = 1.5f;
					}
				}
				

				//Random Mouth and Eye	
				if(randomMouthAndEye && chaobases[i].data.Type == 1 && chaobases[i].data.Reincarnations == 0)
				{ 
					chaobases[i].data.MouthType++;
					if(chaobases[i].data.MouthType > 15)
						chaobases[i].data.MouthType = 0;
					chaobases[i].data.EyeType++;
					if (chaobases[i].data.EyeType > 13)
						chaobases[i].data.EyeType = 0;
				}
				
				if (shinyjewelegg && chaobases[i].data.Shiny == 1 && chaobases[i].data.Texture > 0) 
				{
					chaobases[i].data.EggColor = SADXEggColour_Glass + chaobases[i].data.Color;
				}
				
			}
		}
		
	}

	
}
