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

extern "C"
{
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer};

	DataPointer(int, dword_34BBA10, 0x34BBA10); // unknown
	DataPointer(int, dword_34BBA0C, 0x34BBA0C);
	DataArray(int, dword_33B87E0, 0x33B87E0, 3);
	DataArray(int, dword_33B87B4, 0x33B87B4, 10);

	DataPointer(NJS_OBJECT, ChaoNormalUnriped, 0x3606958); //The unriped version of fruit
	DataPointer(NJS_TEXLIST, ChaoNmlfruitTexlist, 0x33A1338); //Texlist of normal fruit

	FunctionPointer(bool, CheckAnimalPart, (ObjectMaster* a1, char a2), 0x734E90); 
	FunctionPointer(void, sub_717470, (int a1), 0x717470);
	FunctionPointer(void, sub_425860, (int a1), 0x425860);
	FunctionPointer(void, sub_408530, (NJS_OBJECT *a1), 0x408530);
	
	FunctionPointer(void, SetChunkMaterialFlag, (int a1), 0x78A2F0);
	FunctionPointer(void, EnableMatFlag, (), 0x78A2D0);
	FunctionPointer(void, DisableMatFlag, (), 0x78A2E0);

	FunctionPointer(void, ColorChunkModel, (int a1), 0x78A320);
	FunctionPointer(int, GetMaterialIndex, (NJS_CNK_MODEL* a1), 0x78ABE0);

	//Chao colors
	DataArray(int, ChaoColorArray, 0x389D824, 24); //Not necessarily 24 long, I just set a random value to make it work. Lazy stuff, I know.

	//I don't know what this does. I needed it for something but not anymore. Gonna keep it incase I'll need it again.
	struct DataPtr1
	{
		union 
		{
			void* Unknown;
			void* Entity;
			void* Chao;
			void* ChaoDebug;
		};
	};

	//Evolution code that checks for requirements and sets chaotype accordingly
	char __cdecl Evolution(ObjectMaster *a1)
	{
		ChaoDataBase *v1; // esi@1
		double v2; // st7@1
		double v3; // st6@1
		double v4; // st5@1
		char v5 = 0; // bl@5
		int v6 = 0; // edi@5
		__int16 v7; // fps@11
		double v8; // st7@11
		char v9; // ah@11
		bool v10; // c0@11
		bool v11; // c3@11
		int v13; // [sp+Ch] [bp-8h]@1
		float v14; // [sp+10h] [bp-4h]@1

		ChaoData1* data = (ChaoData1*)a1->Data1;
		v1 = data->ChaoDataBase_ptr;
		v2 = *(float *)&v1->PowerRun;
		v3 = *(float *)&v1->FlySwim;
		v14 = 0.5f;
		v4 = -0.5f;
		v13 = v1->Alignment;

		bool canChaos = false;
		bool flag1 = false;
		while (CheckAnimalPart(a1, v6))
		{
			if (++v6 >= 15)
			{
				canChaos = true;
				break;
			}
		}
		if (v4 >= v2 || v2 >= 0.5f || v4 >= v3 || v3 >= 0.5f)
		{
			v8 = -v2;
			v9 = HIBYTE(v7);
			v10 = v3 < v8;
			v11 = v3 == v8;
			if (v9 & 0x41)
			{
				v5 = 17;
				if (v10 || v11)
					v5 = 8;
			}
			else if (v10 || v11)
			{
				v5 = 14;
			}
			else
			{
				v5 = 11;
			}
			flag1 = true;
		}
		bool alreadyCharacter = false;
		if(!flag1 || canChaos)
		{
			v5 = 5;
			v6 = 0;
			while (CheckAnimalPart(a1, v6))
			{
				if (++v6 >= 15)
				{
					if (v1->Happiness > 80 && v1->Reincarnations >= 2u)
					{
						//modded so character chao can evolve
						if (v1->PowerRun == -1) 
						{
							v5 = 25;
							alreadyCharacter = true;
						}
						else if (v1->FlySwim == 1) {
							v5 = 23;
							alreadyCharacter = true;
						}
						else if (v1->PowerRun == 1) {
							v5 = 24;
							alreadyCharacter = true;
						}
						else {
							v5 = 20;
						}
					}
					break;
				}
			}
		}
		if (-v14 >= *(float *)&v13 && !alreadyCharacter|| *(float *)&v13 >= (double)v14 && !alreadyCharacter)
		{
			if (*(float *)&v13 <= 0.0)
			{
				v5 += 2;
				sub_717470(64);
				PlayJingle(118);
			}
			else
			{
				++v5;
				sub_717470(16);
				PlayJingle(117);
			}
		}
		v1->Type = (ChaoType)v5;
		v1->EvolutionProgress = 0;
		v1->PowerRun = 0;
		v1->FlySwim = 0;
		Chao_IncrementTypeStat(&v1->DNA, v1);
		return v5;
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
	
	//All the chaodata
	DataArray(ChaoData, chaobases, 0x03C88878, 24);

	void SeedTree(NJS_OBJECT *a1)
	{
		njSetTexture(&CHAO_OBJECT_TEXLIST);
		sub_408530(&object_0017F384);
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

	__declspec(dllexport) void Init(const char *path)
	{
		const IniFile *config = new IniFile(std::string(path) + "\\config.ini");

		//Was experimenting with custom tree fruit. Coming soon. 
		//WriteCall((void*)0x721040, SeedTree);

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
			WriteJump((void*)0x0073C3A0, Evolution);
		//Dreamcast Fruit
		if (config->getBool("Chao World Extended", "DreamcastFruit", true))
			WriteCall((void*)0x00722D3B, DreamcastFruitEdit);

		colorMixing = config->getBool("Chao World Extended", "ColorMixing", true);
		monsterEvo = config->getBool("Chao World Extended", "MonsterEvo", true);
		randomMouthAndEye = config->getBool("Chao World Extended", "RandomMEye", true);

		delete config;
	}

	_declspec (dllexport) void OnFrame(const char *path)
	{
		
		Color colors[] = { Color(255,255,255),Color(0, 255, 255), Color(255,255,255), Color(0x00, 0x64, 0x96), Color(0xFA, 0xD2, 0), Color(0xE6, 0x78, 0xFF), Color(0xFF, 0x46, 0x3C), Color(0x8C, 0x8C, 0x8C), 
			Color(0, 0x96, 0), Color(0, 0, 0xFF), Color(0, 0xFF, 0xAA),Color(0xFF, 0, 0xB4), Color(0, 0x7D, 0xFF), Color(0x37,0x37,0x37) };
		if (IsLevelChaoGarden())
		{

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
