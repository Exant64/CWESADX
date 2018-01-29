// ShinyJewelSADX.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "SADXModLoader.h"
#include "ninja.h"

extern "C"
{
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer};
	DataPointer(int, dword_34BBA10, 0x34BBA10);
	DataPointer(int, dword_34BBA0C, 0x34BBA0C);
	FunctionPointer(bool, CheckAnimalPart, (ObjectMaster* a1, char a2), 0x734E90);
	FunctionPointer(void, sub_717470, (int a1), 0x717470);
	FunctionPointer(void, sub_425860, (int a1), 0x425860);

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
		v14 = *(float *)&dword_34BBA10;
		v4 = -*(float *)&dword_34BBA0C;
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
		if (v4 >= v2 || v2 >= *(float *)&dword_34BBA0C || v4 >= v3 || v3 >= *(float *)&dword_34BBA0C)
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
	
	struct Color
	{
		char r;
		char g;
		char b;
		char a;

		Color(char _b,char _g, char _r)		
		{
			r = _r;
			g = _g;
			b = _b;
			a = 0xff;
		}
	};
	
	DataArray(ChaoData, chaobases, 0x03C88878, 24);

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

	__declspec(dllexport) void Init()
	{

		//PatchShinyJewelPC();
		//Chaos Chao patch
		//WriteJump((void*)0x0073C3A0, Evolution);
	}
	
	//Commenting out stuff so I can make different dlls just incase people want to disable specific features.
	//TODO: INI config to enable/disable parts of the mod

	_declspec (dllexport) void OnFrame()
	{
		
		Color colors[] = { Color(255,255,255),Color(0, 255, 255), Color(255,255,255), Color(0x00, 0x64, 0x96), Color(0xFF, 0xFF, 0), Color(0xCB, 0xC0, 0xFF), Color(0xFF, 0, 0), Color(0x8C, 0x8C, 0x8C), Color(0, 0x80, 0), Color(0, 0, 0xFF), Color(0x90, 0xEE, 0x90),Color(0x80, 0, 0x80), Color(0, 0xA5, 0xFF), Color(0,0,0) };
		if (IsLevelChaoGarden())
		{

			for (char i = 0; i < 24; i++)
			{
				//Color Mixing				
				/*
				if (chaobases[i].data.DNA.Color1 > 0 && chaobases[i].data.DNA.Color2 > 0 && chaobases[i].data.DNA.Color1 != chaobases[i].data.DNA.Color2)
				{
					WriteData((char*)0x389D85C + i * 4, (char)(colors[chaobases[i].data.DNA.Color1].b * 0.5f + colors[chaobases[i].data.DNA.Color2].b * (1 - 0.5f)));
					WriteData((char*)0x389D85D + i * 4, (char)(colors[chaobases[i].data.DNA.Color1].g * 0.5f + colors[chaobases[i].data.DNA.Color2].g * (1 - 0.5f)));
					WriteData((char*)0x389D85E + i * 4, (char)(colors[chaobases[i].data.DNA.Color1].r * 0.5f + colors[chaobases[i].data.DNA.Color2].r * (1 - 0.5f)));
					WriteData((char*)0x389D85F + i * 4, (char)0xFF);
					chaobases[i].data.Color = 14 + i;
				}
				*/

				//And yes, I commented out comments. Innovative.

				//Monster evolution
				
				/*
				if (chaobases[i].data.Type > ChaoType_Child)
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
				*/

				//Random Mouth and Eye
				
				
				if(chaobases[i].data.Type == 1 && chaobases[i].data.Reincarnations == 0)
				{ 
					chaobases[i].data.MouthType++;
					if(chaobases[i].data.MouthType > 15)
						chaobases[i].data.MouthType = 0;
					chaobases[i].data.EyeType++;
					if (chaobases[i].data.EyeType > 13)
						chaobases[i].data.EyeType = 0;
				}
				
				
			}
		}
		
	}

	
}
