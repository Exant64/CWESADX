//#pragma warning(push)
//#pragma warning(disable:4838)

#include "stdafx.h"
#include "CWESADX.h"
#include "al_gba_manager.h"
#include "motiontable.h"
#include "eff/ToyPresenter.h"
#include "spartoi.h"
#include "ModelInfo.cpp"
#include "al_shape_basic.h"
#include "al_toy/alo_toy.h"
#include "al_motion/alm_dance_n.nam"
#include "al_motion/alm_dance_h.nam"
#include "al_motion/alm_dance_d.nam"
#include "al_motion/alm_hanabi_d.nam"
#include "al_soundrestoration.h"
#include "dreamcast.h"

#include "data/icon/ChaoBall1.nja"
#include "data/icon/SpikeBall.nja"
#include "data/icon/HeartEmote.nja"
#include "data/icon/HaloEmote.nja"
#include "data/icon/ExclamationEmote.nja"
#include "data/icon/SwirlEmote.nja"
#include "data/icon/QuestionEmote.nja"
#include <cassert>

#include "kinder/HealthCenter.h"
#include "kinder/Classroom.h"

extern "C"
{
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };


	FunctionPointer(int, sub_735000, (ObjectMaster* a1), 0x735000);
	FunctionPointer(ObjectMaster*, GardenHat_Create, (int a1, NJS_VECTOR* a2, int a3, NJS_VECTOR* a4, ChaoData* a5), 0x007236F0);
	FunctionPointer(ChaoData*, sub_717760, (int a1), 0x717760);
	FunctionPointer(void, Chao_SetMedal, (ChaoSetmedalThing* a1), 0x00730360);
	FunctionPointer(signed int, sub_7512D0, (int a1, signed int a2), 0x7512D0);
	DataPointer(char, CurrentChaoRaceType, 0x03CD3709); //ruby, etc
	DataPointer(char, CurrentChaoRace, 0x03CD370A); //beginner, etc

	FunctionPointer(int, sub_74F740, (int a1), 0x74F740);
	void RaceTest(ChaoSetmedalThing* a1)
	{
		Chao_SetMedal(a1);
		if (CurrentChaoRaceType == 0) //beginner
		{
			if (CurrentChaoRace < 2)
			{
				int v1 = sub_7512D0((int)& a1->gap0[5312], 0);
				ChaoSetmedalThing2* v3 = (ChaoSetmedalThing2*)sub_74F740((int)& a1->gap0[244 * v1 + 3264]);
				ChaoData1* data1 = (ChaoData1*)v3->dword8D0->Data1;
				ToyPresenter_Load(CurrentChaoRace);
				if (CurrentChaoRace == 0)
					data1->pParamGC->gap_0[15] = 1; //todo change this to SToyFlag or something
				else ChaoSaveFileTest[5] = 1;
			}
		}
	}

	void LoadMarketNew()
	{
		//LoadClassRoom();
		HealthCenter_Prolog();
		//PlaceRadio();
	}

	//Thanks PkR.
	void __cdecl EggColoring(NJS_CNK_MODEL* a1, int a2)
	{
		int v4; // ecx@6
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
			SetChunkTextureIndexA(GetChunkTextureIndex(a1));
			ColorChunkModel(dword_389D828[a2 - SADXEggColour_Yellow_TwoTone]);
			break;
		case SADXEggColour_NormalShiny:
			EnableChunkMaterialFlags();
			SetChunkMaterialFlags(6u);
			Direct3D_SetTexList(ChaoTexLists);
			SetChunkTextureIndexA(GetChunkTextureIndex(a1));
			//SetChunkTextureIndexB(0x22u);
			//Direct3D_Device->
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
			SetChunkTextureIndexA(GetChunkTextureIndex(a1));
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
			SetChunkTextureIndexA(GetChunkTextureIndex(a1));
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

	DataArray(NJS_BGRA, ShinyJewelColors, 0x0088A3D8, 28);

	//Shiny Jewel Patch SADX
	void PatchShinyJewelPC()
	{
		for (int i = 0; i < 28; i++)
			ShinyJewelColors[i].a = 0xA0;
	}

	void PatchShinyJewelGC()
	{
		WriteData((char*)0x0088A3DE, (char)63);
		WriteData((char*)0x0088A3DD, (char)255);
		WriteData((char*)0x0088A3DC, (char)63);
		WriteData((char*)0x0088A3DF, (char)0);

		WriteData((char*)0x0088A3E2, (char)127);
		WriteData((char*)0x0088A3E1, (char)255);
		WriteData((char*)0x0088A3E0, (char)127);
		WriteData((char*)0x0088A3E3, (char)127);

		WriteData((char*)0x0088A3EA, (char)255);
		WriteData((char*)0x0088A3E9, (char)255);
		WriteData((char*)0x0088A3E8, (char)127);
		WriteData((char*)0x0088A3EB, (char)127);

		WriteData((char*)0x0088A3EE, (char)127);
		WriteData((char*)0x0088A3ED, (char)255);
		WriteData((char*)0x0088A3EC, (char)127);
		WriteData((char*)0x0088A3EF, (char)255);

		WriteData((char*)0x0088A3F2, (char)127);
		WriteData((char*)0x0088A3F1, (char)255);
		WriteData((char*)0x0088A3F0, (char)255);
		WriteData((char*)0x0088A3F3, (char)127);

		WriteData((char*)0x0088A3F6, (char)0);
		WriteData((char*)0x0088A3F5, (char)255);
		WriteData((char*)0x0088A3F4, (char)255);
		WriteData((char*)0x0088A3F7, (char)0);

		WriteData((char*)0x0088A3FA, (char)255);
		WriteData((char*)0x0088A3F9, (char)255);
		WriteData((char*)0x0088A3F8, (char)0);
		WriteData((char*)0x0088A3FB, (char)127);

		WriteData((char*)0x0088A3FE, (char)76);
		WriteData((char*)0x0088A3FD, (char)255);
		WriteData((char*)0x0088A3FC, (char)0);
		WriteData((char*)0x0088A3FF, (char)200);

		WriteData((char*)0x0088A403, (char)0);

		WriteData((char*)0x0088A406, (char)0);
		WriteData((char*)0x0088A405, (char)255);
		WriteData((char*)0x0088A404, (char)255);
		WriteData((char*)0x0088A407, (char)200);

		WriteData((char*)0x0088A40A, (char)255);
		WriteData((char*)0x0088A409, (char)255);
		WriteData((char*)0x0088A408, (char)0);
		WriteData((char*)0x0088A40B, (char)200);

		WriteData((char*)0x0088A40E, (char)255);
		WriteData((char*)0x0088A40D, (char)255);
		WriteData((char*)0x0088A40C, (char)176);
		WriteData((char*)0x0088A40F, (char)128);

	}

	bool colorMixing;
	bool monsterEvo;
	bool randomMouthAndEye;
	bool shinyjewelegg;

	FunctionPointer(signed int, sub_7633A0, (ObjectMaster* a1), 0x7633A0);
	//sub_7645B0
	FunctionPointer(signed int, sub_7645B0, (ObjectMaster* a1), 0x7645B0);
	FunctionPointer(signed int, sub_736E90, (ObjectMaster* a1, int a2, int a3), 0x736E90);

	FunctionPointer(void, PossibleWaypoint, (ObjectMaster* a1, int a2), 0x00740160);

	DataPointer(NJS_CNK_OBJECT, egg, 0x03601B94);


	DataPointer(NJS_VECTOR, stru_3B2C660, 0x03B2C660);
	FunctionPointer(void, sub_77E940, (FVFStruct_H_B* a1, int a2, int a3), 0x0077E940);

	DataPointer(NJS_MATRIX, nj_unit_matrix_, 0x0389D650);
	//00763345
	FunctionPointer(int, sub_73AF20, (ObjectMaster* a1), 0x73AF20);
	FunctionPointer(int, sub_737610, (ObjectMaster* a1), 0x737610);

	FunctionPointer(bool, sub_41BEF0, (EntityData1* a1), 0x41BEF0);

	void TripExclamationDC(ObjectMaster* a1, int a2, int a3)
	{
		AL_IconSet(a1, 3, a3);
	}

	FunctionPointer(void, sub_78A000, (float a1), 0x78A000);

	void FixMouth(NJS_CNK_MODEL* a1)
	{
		njTranslate(0, 0, 0, 0.05f); //0.05f
		DrawCnkModel(a1);
	}

	FunctionPointer(void, DrawChaoHudThingB, (ChaoHudThingB* thing, float a2, float a3, float a4, float a5, float a6, int a7, __int16 a8, __int16 a9), 0x0078B070);
	FunctionPointer(void, sub_731C90, (char* a1, float a2, float a3, float a4, float a5, float a6, int a7, int a8), 0x0731C90);
	FunctionPointer(void, sub_78B010, (float a1, float a2, float a3, float a4), 0x78B010);
	FunctionPointer(void, DrawDigitsOfStats, (unsigned int a1, float a2, float a3, int a4, int a5, float a6), 0x00730E80);
	FunctionPointer(void, DrawAverageOfLevelRect, (unsigned int a1, int a2, int a3, float a4, float a5, int a6, int a7, float a8), 0x00730C60);
	FunctionPointer(void, DrawFractionRect, (int a1, int a2, int a3, int a4, float a5, float a6, int a7, int a8, float a9), 0x007312F0);
	FunctionPointer(void, sub_78AFE0, (), 0x78AFE0);
	FunctionPointer(void, sub_78AFF0, (), 0x78AFE0);
	DataArray(ChaoHudThingB, stru_36736A8, 0x036736A8, 16);
	DataArray(ChaoHudThingB, stru_3673930, 0x03673930, 16);
	//DataPointer(ChaoHudThingB*, stru_36736A8, 0x036736A8);

	void WaitDance(ObjectMaster* a1, int a2)
	{
		AL_SetMotionLink(a1, 206);
	}

	ObjectMaster* OverrideCreateRace(ChaoData* chaoData, int a2, void* buffer, NJS_VECTOR* position, Angle angle)
	{
		float v4;
		ObjectMaster* v1 = CreateChao(chaoData, a2, buffer, position, angle);
		AL_FaceSetEye(v1, 4, -1);
		v4 = rand() * 0.000030517578f;

		if (v4 >= 0.25)
		{
			if (v4 >= 0.5)
			{
				if (v4 >= 0.75)
				{
					AL_SetMotionLink(v1, 378);
				}
				else
				{
					AL_SetMotionLink(v1, 376);
				}
			}
			else
			{
				AL_SetMotionLink(v1, 374);
			}
		}
		else
		{
			AL_SetMotionLink(v1, 372);
		}
		return v1;
	}

	ObjectMaster* OverrideCreateRace2(ChaoData* chaoData, int a2, void* buffer, NJS_VECTOR* position, Angle angle)
	{
		ObjectMaster* v1 = CreateChao(chaoData, a2, buffer, position, angle);
		AL_FaceSetEye(v1, 7, -1);
		AL_SetMotionLink(v1, 20); //20
		return v1;
	}

	void __cdecl Chao_RaceAnimations(ObjectMaster* a1, int a2)
	{
		ObjectMaster* v2; // ecx

		v2 = (ObjectMaster*)a1[43].DisplaySub;
		switch (a2)
		{
		case 0:
			AL_SetMotionLink(v2, 101);
			break;
		case 1:
			AL_IconSet(v2, 1, 60);
			AL_SetMotionLink(v2, 162);
			break;
		case 4:
			AL_SetMotionLink(v2, 242);
			break;
		case 5:
			AL_SetMotionLink(v2, 80);
			break;
		case 6:
			AL_SetMotionLink(v2, 82);
			break;
		case 7:
			AL_SetMotionLink(v2, 20);
			break;
		case 8:
			AL_SetMotionLink(v2, 18);
			break;
		case 9:
			AL_SetMotionLink(v2, 27);
			break;
		case 10:
			AL_SetMotionLink(v2, 132);
			break;
		case 11:
			AL_SetMotionLink(v2, 495);
			break;
		case 12:
			AL_SetMotionLink(v2, 0);
			break;
		case 14:
			AL_SetMotionLink(v2, 133);
			break;
		case 15:
			AL_SetMotionLink(v2, 148);
			break;
		case 16:
			AL_SetMotionLink(v2, 146);
			break;
		case 20:
			AL_SetMotionLink(v2, 191);
			break;
		case 32:
			AL_SetMotionLink(v2, 372);
			break;
		case 33:
			AL_SetMotionLink(v2, 374);
			break;
		case 34:
			AL_SetMotionLink(v2, 376);
			break;
		case 35:
			AL_SetMotionLink(v2, 378);
			break;
		case 36:
			AL_SetMotionLink(v2, 145);
			break;
		case 37:
			AL_SetMotionLink(v2, 484);
			break;
		case 41:
			AL_SetMotionLink(v2, 363); //trumpet
			AL_SetItemParallelLeftHand(v2, &Trumpet, &AL_TOY_TEXLIST);
			break;
		case 46:
		case 47:
			AL_SetMotionLink(v2, 115);
			break;
		case 48:
			AL_SetMotionLink(v2, 120);
			break;
		case 49:
			AL_SetMotionLink(v2, 102);
			break;
		case 52:
			AL_SetMotionLink(v2, 216);
			break;
		case 55:
			AL_SetMotionLink(v2, 158);
			break;
		case 58:
			AL_SetMotionLink(v2, 174);
			break;
		case 62:
			AL_SetMotionLink(v2, 479);
			break;
		case 63:
			AL_SetMotionLink(v2, 450);
			break;
		case 76:
			AL_SetMotionLink(v2, 233); //shovel
			break;
		case 78:
			AL_SetMotionLink(v2, 37);
			break;
		case 82:
			AL_SetMotionLink(v2, 505);
			break;
		case 83:
			AL_SetMotionLink(v2, 526);
			break;
		case 84:
			AL_SetMotionLink(v2, 1);
			break;
		case 100:
			AL_SetMotionLink(v2, 150);
			break;
		case 116:
			AL_SetMotionLink(v2, 238); // watercan?
			AL_SetItemOffset(a1, 11, (AL_ITEM_INFO*)0x036B995C);
			break;
		case 128:
		case 159:
			AL_SetMotionLink(v2, 303);
			break;
		case 155:
			AL_SetMotionLink(v2, 58);
			break;
		case 160:
			AL_SetMotionLink(v2, 304);
			break;
		default:
			AL_SetMotionLink(v2, 153);
			break;
		}

		if (a2 != 76 && a2 != 116 && a2 != 41)
		{
			AL_SetItemParallelLeftHand(v2, 0, &AL_TOY_TEXLIST);
			AL_SetItemOffset(a1, 11, 0);
		}
	}

	FunctionPointer(void, sub_76D3D0, (char a1, float a2, float a3, unsigned __int16 a4, char a5), 0x76D3D0);
	DataPointer(char, dword_3CE0564, 0x3CE0564);
	DataPointer(char, dword_3CE0560, 0x3CE0560);
	FunctionPointer(void, sub_718020, (ObjectMaster* a1, ChaoDataBase* chaoData, int a3), 0x718020);
	FunctionPointer(void, sub_737030, (ObjectMaster* a1), 0x737030);
	FunctionPointer(void, sub_73F090, (ObjectMaster* a1), 0x73F090);
	FunctionPointer(void, sub_720AA0, (NJS_CNK_OBJECT* a1, int a2, int a3), 0x720AA0);


	void OdekakeButtons(char a1, float a2, float a3, unsigned __int16 a4, char a5)
	{
		sub_76D3D0(0, 320.0, 209.0 - 56.0 * 2, 22, dword_3CE0560);
		sub_76D3D0(1, 320.0, 209.0 - 56.0, 30, dword_3CE0564);
		sub_76D3D0(a1, a2, a3, a4, a5);
	}

	FunctionPointer(void, sub_789750, (NJS_CNK_MODEL* a3), 0x789750);
	//00792FEB

	DataArray(MotionTableAction, ChaoAnimations, 0x36A94E8, 625);

	FunctionPointer(int, sub_737080, (ObjectMaster* a1), 0x737080);
	FunctionPointer(int, ReturnBlinkValue, (ObjectMaster* a1), 0x00737060);
	FunctionPointer(void, sub_765010, (NJS_OBJECT* a1), 0x765010);
	DataPointer(char, ChaoNodeIndex, 0x03CE04E4);

	bool RunFromPlayerRestoration(ObjectMaster* a1) //not sure if it's needed lol
	{
		return ChaoDistanceFromPlayer(a1, 0) < 5;
	}

	DataPointer(SecondaryEntrance, SSGardenStartPoint, 0x339F888);

	NJS_MKEY_SA stru_381B7A0[20] =
	{
	  { 0, NJM_DEG_ANG(180),0,0 },
	  { 1, NJM_DEG_ANG(180),0,0  },
	  { 2, NJM_DEG_ANG(180),0,0  },
	  { 3, NJM_DEG_ANG(180),0,0  },
	  { 4, NJM_DEG_ANG(180),0,0  },
	  { 5, NJM_DEG_ANG(180),0,0  },
	  { 6, NJM_DEG_ANG(180),0,0  },
	  { 7, NJM_DEG_ANG(180),0,0  },
	  { 8, NJM_DEG_ANG(180),0,0  },
	  { 9, NJM_DEG_ANG(180),0,0  },
	  { 10, NJM_DEG_ANG(180),0,0  },
	  { 11, NJM_DEG_ANG(180),0,0  },
	  { 12, NJM_DEG_ANG(180),0,0  },
	  { 13, NJM_DEG_ANG(180),0,0  },
	  { 14, NJM_DEG_ANG(180),0,0  },
	  { 15, NJM_DEG_ANG(180),0,0  },
	  { 16, NJM_DEG_ANG(180),0,0  },
	  { 17, NJM_DEG_ANG(180),0,0  },
	  { 18, NJM_DEG_ANG(180),0,0  },
	  { 19, NJM_DEG_ANG(180),0,0  }
	};

#pragma pack(push, 1)
	struct ChaoDebugData1
	{
		char CurrentMenu;
		char MenuSelection;
		char field_2[18];
		__int16 ChaoID;
		char field_16[10];
	};
#pragma pack(pop)

#pragma pack(push, 1)
	struct DebugStringInfo
	{
		__int16 column;
		__int16 row;
		__int16 fontsize;
		char gap_6[2];
		int color;
		char* text;
	};
#pragma pack(pop)
	DataPointer(NJS_MDATA2*, ChaoMotionData, 0x03CE1358);
	DataPointer(float, ChaoCurrentFrame, 0x03CE135C);
	DataPointer(int, ChaoFrameCount, 0x03CE1360);
	DataPointer(NJS_MDATA2*, ChaoTransitionMotionData, 0x03CE1364);
	DataPointer(float, ChaoTransitionStartFrame, 0x03CE1368);
	DataPointer(int, ChaoTransitionFrameCount, 0x03CE136C);
	DataPointer(float, ChaoLinkFrame, 0x03CE1370);


	//0,1,2,4,5,8,12,13,14,15,74,24,34,21,23,25,28,29,33
	
	__declspec(naked) void DarkEyeHack()
	{
		__asm
		{
			xor eax,eax
			retn
		}
	}

	MusicInfo TVChannel1Info = { "chao_g_tv_drama.adx",0 };
	MusicInfo TVChannel2Info = { "chao_g_tv_cartoon.adx",0 };
	MusicInfo TVChannel3Info = { "chao_g_tv_drama.adx",0 };
#ifdef DCCHAO
	void __cdecl sub_723990(__int16* a1, __int16* a2, float a3, Rotation3* out)
	{
		double v4; // st7
		double v5; // st6
		double v6; // st5
		double v7; // st4
		double v8; // st3
		double v9; // st2

		v4 = (double)(unsigned __int16)* a1 * 0.0054931640625;// NJD_ANG_DEG
		v5 = (double)(unsigned __int16)a1[1] * 0.0054931640625;
		v6 = (double)(unsigned __int16)a1[2] * 0.0054931640625;
		v7 = (double)(unsigned __int16)* a2 * 0.0054931640625 - v4;
		v8 = (double)(unsigned __int16)a2[1] * 0.0054931640625 - v5;
		for (v9 = (double)(unsigned __int16)a2[2] * 0.0054931640625 - v6; v7 > 180.0; v7 = v7 - 360.0)
		{
			;
		}
		for (; v7 < -180.0; v7 = v7 + 360.0)
		{
			;
		}
		for (; v8 > 180.0; v8 = v8 - 360.0)
		{
			;
		}
		for (; v8 < -180.0; v8 = v8 + 360.0)
		{
			;
		}
		for (; v9 > 180.0; v9 = v9 - 360.0)
		{
			;
		}
		for (; v9 < -180.0; v9 = v9 + 360.0)
		{
			;
		}
		//v4 = key1
		//a3 = rate1
		//v7 = key2-key1
		out->x = (unsigned __int64)((v7 * a3 + v4) * 65536.0 * 0.002777777777777778);
		out->y = (unsigned __int64)((v8 * a3 + v5) * 65536.0 * 0.002777777777777778);
		out->z = (unsigned __int64)((v9 * a3 + v6) * 65536.0 * 0.002777777777777778);
	}
	void __cdecl LerpChaoRotation(Rotation3* rot1, Rotation3* rot2, float a1, Rotation3* output)
	{
		double v4; // st7
		double v5; // st6
		double v6; // st5
		double v7; // st4
		double v8; // st3
		double i; // st2

		v4 = (double)rot1->x * 0.0054931640625;
		v5 = (double)rot1->y * 0.0054931640625;
		v6 = (double)rot1->z * 0.0054931640625;
		v7 = (double)rot2->x * 0.0054931640625 - v4;
		v8 = (double)rot2->y * 0.0054931640625 - v5;
		for (i = (double)rot2->z * 0.0054931640625 - v6; v7 > 180.0; v7 = v7 - 360.0)
		{
			;
		}
		for (; v7 < -180.0; v7 = v7 + 360.0)
		{
			;
		}
		for (; v8 > 180.0; v8 = v8 - 360.0)
		{
			;
		}
		for (; v8 < -180.0; v8 = v8 + 360.0)
		{
			;
		}
		for (; i > 180.0; i = i - 360.0)
		{
			;
		}
		for (; i < -180.0; i = i + 360.0)
		{
			;
		}
		output->x = (unsigned __int64)((v7 * a1 + v4) * 65536.0 * 0.002777777777777778);
		output->y = (unsigned __int64)((v8 * a1 + v5) * 65536.0 * 0.002777777777777778);
		output->z = (unsigned __int64)((i * a1 + v6) * 65536.0 * 0.002777777777777778);
	}

	Uint32 _nuMotionSearchKey16(const void* key, int KeySize, Uint32 nbkeys, Uint16 frame)
	{
		Uint32		nb_a;
		Uint32		nb_b;
		Uint32		nb_mid;

		nb_a = 0;
		nb_b = nbkeys;
		while (nb_b - nb_a > 1) {
			nb_mid = (nb_a + nb_b) >> 1;

			if (frame >= *(Uint16*)(((unsigned char*)key) + (nb_mid * KeySize))) {
				nb_a = nb_mid;
			}
			else {
				nb_b = nb_mid;
			}
		}

		return	nb_a;
	}

	void Chao_GetMotionLinearKey(const void* key, int KeySize, Uint32 nbkeys, Float frame, Float frameCount,
		const void** pKey1, const void** pKey2, Float* pRate)
	{
		Uint32			keyno;
		Sint16			DiffKeyNo;
		Uint16			keyframe1;
		Uint16			keyframe2;
		Uint16* key1;
		Uint16* key2;

		keyno = _nuMotionSearchKey16(key, KeySize, nbkeys, (Uint16)frame);

		key1 = (Uint16*)(((unsigned char*)key) + keyno * KeySize);
		key2 = (Uint16*)(((unsigned char*)key) + (keyno + 1) * KeySize);
		if (*key1 == frameCount - 1)
		{
			key2 = (Uint16*)key;
			*pRate = (frame - *key1);
		}
		else
		{
			*pRate = (frame - *key1) / (*key2 - *key1);
		}

		*pKey1 = key1;
		*pKey2 = key2;
	}

	void RotateChao(al_object* a1)
	{
		NJS_MKEY_SA* key1;
		NJS_MKEY_SA* key2;
		float pRate;

		Rotation3 rot1; // [esp+10h] [ebp-24h]
		Rotation3 rot2; // [esp+1Ch] [ebp-18h]
		Rotation3 output; // [esp+28h] [ebp-Ch]

		if (ChaoMotionData->p[1])
		{
			Chao_GetMotionLinearKey(ChaoMotionData->p[1], sizeof(NJS_MKEY_SA), ChaoMotionData->nb[1], ChaoCurrentFrame, ChaoFrameCount, (const void**)& key1, (const void**)& key2, &pRate);
			sub_723990((short*)key1->key, (__int16*)(key2->key), pRate, &rot1);
		}
		else
		{
			rot1.x = a1->Ang[0];
			rot1.y = a1->Ang[1];
			rot1.z = a1->Ang[2];
		}
		if (ChaoTransitionMotionData)
		{
			if (ChaoTransitionMotionData->p[1])
			{
				Chao_GetMotionLinearKey(ChaoTransitionMotionData->p[1], sizeof(NJS_MKEY_SA), ChaoTransitionMotionData->nb[1], ChaoTransitionStartFrame, ChaoTransitionFrameCount, (const void**)& key1, (const void**)& key2, &pRate);
				sub_723990((short*)key1->key, (__int16*)(key2->key), pRate, &rot2);
			}
			else
			{
				rot2.x = a1->Ang[0];
				rot2.y = a1->Ang[1];
				rot2.z = a1->Ang[2];
			}
			LerpChaoRotation(&rot1, &rot2, ChaoLinkFrame, &output);
			njRotateXYZ(0, output.x, output.y, output.z);
		}
		else
		{
			njRotateXYZ(0, rot1.x, rot1.y, rot1.z);
		}
	}

	void PositionChao(al_object* a1)
	{
		NJS_MKEY_F* key1;
		NJS_MKEY_F* key2;
		float pRate;

		NJS_VECTOR pos1; // [esp+10h] [ebp-24h]
		NJS_VECTOR pos2; // [esp+1Ch] [ebp-18h]
		NJS_VECTOR output; // [esp+28h] [ebp-Ch]

		if (ChaoMotionData->p[0])
		{
			Chao_GetMotionLinearKey(ChaoMotionData->p[0], sizeof(NJS_MKEY_F), ChaoMotionData->nb[0], ChaoCurrentFrame, ChaoFrameCount, (const void**)& key1, (const void**)& key2, &pRate);
			pos1.x = key1->key[0] + (key2->key[0] - key1->key[0]) * pRate;
			pos1.y = key1->key[1] + (key2->key[1] - key1->key[1]) * pRate;
			pos1.z = key1->key[2] + (key2->key[2] - key1->key[2]) * pRate;
			njAddVector(&pos1, &a1->diff);
		}
		else
		{
			pos1.x = a1->Pos[0];
			pos1.y = a1->Pos[1];
			pos1.z = a1->Pos[2];
		}
		if (ChaoTransitionMotionData)
		{
			if (ChaoTransitionMotionData->p[0])
			{
				Chao_GetMotionLinearKey(ChaoTransitionMotionData->p[0], sizeof(NJS_MKEY_F), ChaoTransitionMotionData->nb[0], ChaoTransitionStartFrame, ChaoTransitionFrameCount, (const void**)& key1, (const void**)& key2, &pRate);
				pos2.x = key1->key[0] + (key2->key[0] - key1->key[0]) * pRate;
				pos2.y = key1->key[1] + (key2->key[1] - key1->key[1]) * pRate;
				pos2.z = key1->key[2] + (key2->key[2] - key1->key[2]) * pRate;
				njAddVector(&pos2, &a1->diff);
			}
			else
			{
				pos2.x = a1->Pos[0];
				pos2.y = a1->Pos[1];
				pos2.z = a1->Pos[2];
			}
			output.x = ChaoLinkFrame * pos2.x + pos1.x * (1.0f - ChaoLinkFrame);
			output.y = ChaoLinkFrame * pos2.y + pos1.y * (1.0f - ChaoLinkFrame);
			output.z = ChaoLinkFrame * pos2.z + pos1.z * (1.0f - ChaoLinkFrame);
		}
		else
		{
			output = pos1;
		}
		njTranslateV(0, &output);
	}

	const int CalcPosPtr = 0x00765110;
	void AL_CalcShadowPos(ObjectMaster *a1)
	{
		__asm
		{
			 mov eax, a1
			 call CalcPosPtr
		}
	}
	void AnimateChao(al_object *a1);
	DataPointer(unsigned short, word_3CE2BF8, 0x3CE2BF8);
	void CalculatePositions(ObjectMaster* a1, al_object* a2)
	{
		ChaoData1* v1; // esi
		Angle v2; // eax
		al_object* ptr = a2;
		v1 = (ChaoData1*)a1->Data1;
		while (1)
		{
			njPushMatrixEx();
			AnimateChao(ptr);
			AL_CalcShadowPos(a1);
			word_3CE2BF8++;
			if (ptr->base.child)
				CalculatePositions(a1, (ChunkObjectPointer*)ptr->base.child);
			njPopMatrixEx();
			if (!ptr->base.sibling)
				break;
			ptr = (ChunkObjectPointer*)ptr->base.sibling;
		}
	}

	void __cdecl Chao_SetAnimVars(ObjectMaster* a1);

	void __cdecl sub_7659A0(ObjectMaster* a1)
	{
		ChaoData1* v1; // esi
		Angle v2; // eax

		v1 = (ChaoData1*)a1->Data1;
		word_3CE2BF8 = 0;
		Chao_SetAnimVars(a1);
		njPushMatrixEx();
		njUnitMatrix(0);
		njTranslateV(0, &v1->entity.Position);
		v2 = v1->entity.Rotation.y;
		if (v2)
		{
			njRotateY(0, (unsigned __int16)v2);
		}
		CalculatePositions(a1, v1->ModelData.PointerToStructWithCnkObject);
		njPopMatrixEx();

	}

	void __cdecl Chao_UpdateModel(ObjectMaster* a1)
	{
		ChaoData1* v1; // esi
		char v2; // al
		ChaoModelData* v3; // esi
		int v4; // et1
		double v6; // st7
		unsigned __int8 v7; // c2
		unsigned __int8 v8; // c3
		double v9; // st7
		double v10; // st7
		int v11; // et1
		double v13; // st7
		unsigned __int8 v14; // c2
		unsigned __int8 v15; // c3
		double v16; // st7
		double v17; // st7

		v1 = (ChaoData1*)a1->Data1;
		v3 = &v1->ModelData;
		//if (v1->ModelData.modelFlags & 2)
		{
			sub_767790(a1);
		}
		if (ALOField_Find(a1, 1, 150))
		{
			v3->modelFlags |= 8u;
		}
		else
		{
			v3->modelFlags &= ~8u;
		}
		if (v3->LeftHandToyWeird.model)
		{
			v4 = v3->LeftHandToyWeird.what;
			v6 = v3->LeftHandToyWeird.scale;
			if (!v4)
			{
				v10 = v6 - 0.1;
				v3->LeftHandToyWeird.scale = v10;
				if (v10 < 0.0)
				{
					v3->LeftHandToyWeird.scale = 0.0;
					v3->LeftHandToyWeird.model = 0;
				}
			}
			else
			{
				v9 = v6 + 0.1;
				v3->LeftHandToyWeird.scale = v9;
				if (v9 > 1.0)
				{
					v3->LeftHandToyWeird.scale = 1.0;
				}
			}
		}
		if (v3->RightHandToyWeird.model)
		{
			v11 = v3->RightHandToyWeird.what;
			v13 = v3->RightHandToyWeird.scale;
			if (!v11)
			{
				v17 = v13 - 0.1;
				v3->RightHandToyWeird.scale = v17;
				if (v17 < 0.0)
				{
					v3->RightHandToyWeird.scale = 0.0;
					v3->RightHandToyWeird.model = 0;
				}
			}
			else
			{
				v16 = v13 + 0.1;
				v3->RightHandToyWeird.scale = v16;
				if (v16 > 1.0)
				{
					v3->RightHandToyWeird.scale = 1.0;
				}
			}
		}


		sub_7659A0(a1);
	}


	void AnimateChao(al_object* a1)
	{
		PositionChao(a1);
		if (ChaoNodeIndex == 36)
			njRotateY(0, 0x49DA - 0x1555);
		if (ChaoNodeIndex == 38)
			njRotateY(0, 0x3625 - 0x6AAA);
		RotateChao(a1);
		if (!(a1->base.evalflags & NJD_EVAL_UNIT_SCL))
		{
			njScale(0, a1->base.scl[0], a1->base.scl[1], a1->base.scl[2]);
		}
		ChaoMotionData++;
		if (ChaoTransitionMotionData)
		{
			ChaoTransitionMotionData++;
		}
	}
#endif
	FunctionPointer(void, sub_79F4D0, (CollisionInfo* a1), 0x79F4D0);
	DataPointer(NJS_COLOR, stru_3D08580, 0x3D08580);


//#define DCCHAO
#ifdef DCCHAO
	void DrawChao(ObjectMaster* a1, al_object* a2)
	{
		
		while (1)
		{
			njPushMatrixEx();
			//njTranslateEx((NJS_VECTOR*)a2->base.pos);
			//njRotateZ(0, a2->base.ang[2]);
			//njRotateY(0, a2->base.ang[1]);
			//njRotateX(0, a2->base.ang[0]);
			//njScaleEx((NJS_VECTOR*)a2->base.scl);
			AnimateChao(a2);

			ChaoData1* data1 = (ChaoData1*)a1->Data1;
			//chao coloring
			if(ChaoNodeIndex != 18 && ChaoNodeIndex != 21 && ChaoNodeIndex != 28)
				if(a2->model)
				{
					for (int i = 0; i < a2->base.basicdxmodel->nbMat; i++)
					{
						if (!data1->ChaoDataBase_ptr->Texture)
						{
							if (data1->ChaoDataBase_ptr->MonotoneHighlights)
								a2->base.basicdxmodel->mats[i].attrflags &= ~0x200000;
							else a2->base.basicdxmodel->mats[i].attrflags |= 0x200000;
						}
						else
						{
						
						}
					}
				}

			//Chao_CalculatePositions(a1);
			int eyelidRotX = ((ChaoData1*)a1->Data1)->FacialData.EyeLidExpressionCurrCloseAng + ((ChaoData1*)a1->Data1)->FacialData.EyeLidBlinkAng - 0x4000;
			
			if (a2->toy.model)
				{
					njSetTexture(a2->toy.texlist);
					//SetChunkMaterialFlags(SecondTextureEnvironmentMap);
					njPushMatrixEx();
					if (a2->useTransform)
					{
						njTranslateEx(&a2->position);
						njRotateXYZ(0, a2->rotation.x, a2->rotation.y, a2->rotation.z);
					}
					njScale(0, a2->toy.scale, a2->toy.scale, a2->toy.scale);
					njCnkDrawObject(a2->toy.model);
					njPopMatrixEx();
					//SetChunkMaterialFlags(0);
				}

			if (ChaoNodeIndex == 19)              // left eyelid
			{
				if (((ChaoData1*)a1->Data1)->FacialData.EyeLidExpressionCurrSlopeAng)
				{
					njRotateZ(0, (unsigned __int16)((ChaoData1*)a1->Data1)->FacialData.EyeLidExpressionCurrSlopeAng);
				}
				if (eyelidRotX)
				{
					njRotateX(0, (unsigned __int16)eyelidRotX);
				}
			}
			if (ChaoNodeIndex == 22)              // right eyelid
			{
				if (((ChaoData1*)a1->Data1)->FacialData.EyeLidExpressionCurrSlopeAng)
				{
					int rot = -((ChaoData1*)a1->Data1)->FacialData.EyeLidExpressionCurrSlopeAng;
					njRotateZ(0, (unsigned __int16)rot);
				}

				if (eyelidRotX)
				{
					njRotateX(0, (unsigned __int16)eyelidRotX);
				}
			}

			njSetTexture(&CHAO_TEXLIST);

			//if (ChaoNodeIndex == 18 || ChaoNodeIndex == 21) njSetTexture(&ChaoTexLists[2]);
			if (ChaoNodeIndex == 28) njSetTexture(&ChaoTexLists[5]);

			if (ChaoNodeIndex == 18)
			{
				njTranslate(0, ((ChaoData1*)a1->Data1)->FacialData.EyePosX, ((ChaoData1*)a1->Data1)->FacialData.EyePosY, 0.0);
				//njScale(0, ((ChaoData1*)a1->Data1)->FacialData.EyePosX, ((ChaoData1*)a1->Data1)->FacialData.EyePosX, ((ChaoData1*)a1->Data1)->FacialData.EyePosX);
			}
			else if (ChaoNodeIndex == 21)
			{
				//njScale(0, ((ChaoData1*)a1->Data1)->FacialData.EyePosX, ((ChaoData1*)a1->Data1)->FacialData.EyePosX, ((ChaoData1*)a1->Data1)->FacialData.EyePosX);
				njTranslate(0, -((ChaoData1*)a1->Data1)->FacialData.EyePosX, ((ChaoData1*)a1->Data1)->FacialData.EyePosY, 0.0);
			}


			if (ChaoNodeIndex == 19 || ChaoNodeIndex == 22)
			{
				if (eyelidRotX != 0xFFFFC000)
				{
					njDrawModel_SADX_Dynamic(a2->base.basicdxmodel);
				}
			}
			else
			{
				if (a2->animalPart) {
					njSetTexture((NJS_TEXLIST*)0x033A1340);
					DrawCnkModel(a2->animalPart->chunkmodel);
				}
				else
					if (a2->base.basicdxmodel)
						njDrawModel_SADX_Dynamic(a2->base.basicdxmodel);
			}


			ChaoNodeIndex++;
			if (a2->base.child)
				DrawChao(a1, (ChunkObjectPointer*)a2->base.child);
			njPopMatrixEx();
			if (!a2->base.sibling)
				break;
			a2 = (ChunkObjectPointer*)a2->base.sibling;
		}
	}

	void __cdecl Chao_SetAnimVars(ObjectMaster* a1)
	{
		MotionTableData* v1; // eax
		ChaoData1* v2; // eax
		NJS_MOTION* v3; // ecx
		NJS_MOTION* v4; // ecx

		v2 = (ChaoData1*)a1->Data1;
		v3 = v2->MotionTable.LastNJS_Motion;
		v1 = &v2->MotionTable;
		ChaoMotionData = (NJS_MDATA2*)v3->mdata;
		ChaoFrameCount = v3->nbFrame;
		ChaoCurrentFrame = v1->frame;
		if (v1->flag & 2)
		{
			v4 = v1->NJS_MOTION;
			ChaoTransitionMotionData = (NJS_MDATA2*)v4->mdata;
			ChaoTransitionFrameCount = v4->nbFrame;
			ChaoTransitionStartFrame = v1->LinkStartFrame;
			ChaoLinkFrame = v1->linkFrame;
		}
		else
		{
			ChaoTransitionMotionData = 0;
		}
	}
	//ObjectFunc(sub_737030, 0x737030);
	void Chao_Display_(ObjectMaster* a1)
	{
		Chao_SetAnimVars(a1);
		njPushMatrixEx();
		njTranslateEx(&a1->Data1->Position);
		njRotateY(0, a1->Data1->Rotation.y);
		njSetTexture(&ChaoTexLists[0]);
		//SetChaoTexturePalette(a1, 0); //modified because headers
		ChaoNodeIndex = 0;
		DrawChao(a1, (ChunkObjectPointer*)((ChaoData1*)a1->Data1)->ModelData.PointerToStructWithCnkObject);//a1->Data1.Chao->ModelData.PointerToStructWithCnkObject);
		//njCnkDrawObject(&a1->Data1.Chao->ModelData.PointerToStructWithCnkObject->base);
		njPopMatrixEx();
		njPushMatrixEx();
		njTranslate(0, 0, 2, 0);
		sub_737030(a1);
		njPopMatrixEx();
	}


	NJS_OBJECT* LoadChaoModel(const char* path, const char* name)
	{
		std::string str = std::string(path);
		str += "\\";
		str += name;
		ModelInfo* modelInfo = new ModelInfo(str);
		return modelInfo->getmodel();
	}

	NJS_OBJECT* LoadEvoChaoModel(const char* path, const char* evo, const char* subevo)
	{
		std::string str = std::string(path);
		str += "\\";
		str += evo;
		str += "_";
		str += subevo;
		str += ".sa1mdl";
		ModelInfo* modelInfo = new ModelInfo(str);
		return modelInfo->getmodel();
	}

	DataArray(NJS_OBJECT*, Al_RootObject, 0x034BD4A8,100);
	
	void SetTexID(NJS_OBJECT* a1, int a2)
	{
		if(a1)
			a1->basicdxmodel->mats[0].attr_texId = 164 + a2;
	}
	DataArray(uint16_t, word_88733C, 0x88733C, 26);
	void __cdecl Chao_SetMouth_(ObjectMaster* a1, ChaoMouth a2, int timer)
	{
		ChaoData1* data1 = (ChaoData1*)a1->Data1;
		data1->FacialData.MouthTimer = timer;
		uint16_t* a2a;
		if ((unsigned __int8)data1->ChaoDataBase_ptr->Type < ChaoType_Neutral_Chaos || (unsigned __int8)data1->ChaoDataBase_ptr->Type > ChaoType_Dark_Chaos)
			a2a = &word_88733C[2 * a2];
		else
			a2a = word_88733C;
		if (data1->ModelData.baseChaoNodes[28]) 
		{
			data1->ModelData.baseChaoNodes[28]->basicdxmodel->mats[0].attr_texId = a2a[0];
			data1->ModelData.baseChaoNodes[28]->basicdxmodel->mats[1].attr_texId = a2a[1];
		}
	}

	void LoadEvoChao(const char* path, const char* evo, int index)
	{
		Al_RootObject[index] = LoadEvoChaoModel(path, evo, "Base");
		Al_RootObject[index + 1] = LoadEvoChaoModel(path, evo, "Normal");
		Al_RootObject[index + 2] = LoadEvoChaoModel(path, evo, "Swim");
		Al_RootObject[index + 3] = LoadEvoChaoModel(path, evo, "Fly");
		Al_RootObject[index + 4] = LoadEvoChaoModel(path, evo, "Run");
		Al_RootObject[index + 5] = LoadEvoChaoModel(path, evo, "Power");

		for (int i = 0; i < 7; i++) //override hero slots
			Al_RootObject[index + 6 + i] = Al_RootObject[i];

		for (int i = 0; i < 7; i++) //override dark slots
			Al_RootObject[index + 12 + i] = Al_RootObject[i];
	}

	void LoadTempHeroEvo(const char* path, const char* name, int index)
	{

		Al_RootObject[index ] = LoadChaoModel(path, name);
		Al_RootObject[index + 1 ] = Al_RootObject[index];
		Al_RootObject[index + 2  ] = Al_RootObject[index];
		Al_RootObject[index + 3 ] = Al_RootObject[index];
		Al_RootObject[index + 4 ] = Al_RootObject[index];
		Al_RootObject[index + 5 ] = Al_RootObject[index];
	}

	void LoadChaosEvo(const char* path, const char* name, int index)
	{
		Al_RootObject[index] = LoadChaoModel(path, name);
		Al_RootObject[index + 1] = Al_RootObject[index];
		Al_RootObject[index + 2] = Al_RootObject[index];
		Al_RootObject[index + 3] = Al_RootObject[index];
		Al_RootObject[index + 4] = Al_RootObject[index];
		Al_RootObject[index + 5] = Al_RootObject[index];
		
		for (int i = 0; i < 7; i++) //override hero slots
			Al_RootObject[index + 6 + i] = Al_RootObject[i];

		for (int i = 0; i < 7; i++) //override dark slots
			Al_RootObject[index + 12 + i] = Al_RootObject[i];
	}

	void LoadChildChao(const char* path)
	{
		Al_RootObject[0] = LoadChaoModel(path, "Base.sa1mdl");
		Al_RootObject[1] = LoadChaoModel(path, "Normal.sa1mdl");
		Al_RootObject[2] = LoadChaoModel(path, "Swim.sa1mdl");
		Al_RootObject[3] = LoadChaoModel(path, "Fly.sa1mdl");
		Al_RootObject[4] = LoadChaoModel(path, "Run.sa1mdl");
		Al_RootObject[5] = LoadChaoModel(path, "Power.sa1mdl");

		for (int i = 0; i < 7; i++)
			Al_RootObject[6 + i] = Al_RootObject[i];

		for (int i = 0; i < 7; i++)
			Al_RootObject[12 + i] = Al_RootObject[i];
	}

	void __cdecl FreeSomeChaoData_(ObjectMaster* a1)
	{
		ChaoData1* v1; // esi
		ChaoEvos* v2; // eax
		ChaoModelData* v3; // esi

		v1 = (ChaoData1*)a1->Data1;
		v2 = v1->ModelData.NormalModels;
		v3 = &v1->ModelData;
		if (v2)
		{
			_HeapFree(v2);
		}
		if (v3->HeroModels)
		{
			_HeapFree(v3->HeroModels);
		}
		if (v3->DarkModels)
		{
			_HeapFree(v3->DarkModels);
		}
		_HeapFree(v1->ModelData.chaoPalette);
		DeleteChunkObjectPointer((BasicObjectPointer*)v3->PointerToStructWithCnkObject);
	}
#endif

	__declspec(dllexport) void Init(const char* path, const HelperFunctions& helperFunctions)
	{
		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");
		//TVChannel1 = helperFunctions.RegisterMusicFile(TVChannel1Info);
		//TVChannel2 = helperFunctions.RegisterMusicFile(TVChannel2Info);
		//TVChannel3 = helperFunctions.RegisterMusicFile(TVChannel3Info);
		PrintDebug(sizeof(CHAO_GLOBAL) == 0x2B8 ? "yes" : "FUCK ASS");
		//hanabi test
		ChaoAnimations[0x77].NJS_MOTION = &animation_00BD2C80;
		ChaoAnimations[0x77].FlagThing1 = 3;
		ChaoAnimations[0x77].TransitionToID = -1;
		ChaoAnimations[0x77].StartFrame = 0.0f;
		ChaoAnimations[0x77].EndFrame = animation_00BD2C80.nbFrame - 1;
		ChaoAnimations[0x77].PlaySpeed /= 2;
	
#ifdef DCCHAO
		WriteJump((void*)0x00765010, AnimateChao);
		//WriteJump((void*)Chao_Display, Chao_Display_);
		for (int i = 0; i < 100; i++) Al_RootObject[i] = nullptr;
		LoadChildChao(path);
		LoadEvoChao(path, "Normal", 18);
		LoadEvoChao(path, "Swim", 6 * (ChaoType_Neutral_Swim - 2));
		LoadEvoChao(path, "Fly", 6 * (ChaoType_Neutral_Fly - 2));
		LoadEvoChao(path, "Run", 6 * (ChaoType_Neutral_Run - 2));
		LoadEvoChao(path, "Power", 6 * (ChaoType_Neutral_Power - 2));
		LoadChaosEvo(path, "Light Chao.sa1mdl", 6 * (ChaoType_Neutral_Chaos - 2));
		//LoadTempHeroEvo(path, "60.sa1mdl", 6 * (ChaoType_Neutral_Normal - 2));
		WriteJump((void*)0x0075B360, SetTexID);
		WriteJump(SetMouth,    Chao_SetMouth_);
		WriteJump((void*)0x00741F20, Chao_UpdateModel);
		WriteJump((void*)0x00741C80, Chao_LoadModels);
		//WriteJump((void*)0x0074136A, DeleteChunkObjectPointer); 
		WriteJump((void*)0x0075AF20, Chao_SetVertexColor);
		WriteJump((void*)0x0073E730, DrawChao);
		WriteJump((void*)FreeSomeChaoData, FreeSomeChaoData_);

		int index = 364; // did it like this for debugging purposes
		ChaoAnimations[index].NJS_MOTION = &_109ca0;
		ChaoAnimations[index].FlagThing1 = 7;
		ChaoAnimations[index].field_6 = 0;
		ChaoAnimations[index].TransitionToID = -1;
		ChaoAnimations[index].field_C = 0;
		ChaoAnimations[index].StartFrame = 0;
		ChaoAnimations[index].EndFrame = _109ca0.nbFrame - 1;
#endif
		//hero normal replaced with spartoi test
#ifdef SPARTOI
		int type = 6 * ((unsigned __int8)ChaoType_Hero_Normal - 2);
		int type_ = 6 * ((unsigned __int8)ChaoType_Dark_Normal - 2);
		NJS_OBJECT** chaoModels = (NJS_OBJECT * *)(0x34BD4A8);
		
		for (int i = type; i < type_; i++)
			chaoModels[i] = &_0_Chao_Pos;
#endif

		WriteCall((void*)0x0072E729, RaceTest); //custom toy unlocks
		WriteCall((void*)0x00715606, LoadMarketNew); //classroomtest

		WriteData((char*)0x00751B1A, (char)0xEB); //recovers the medal display in races

		ChaoDebug_Init();

		//SADX tree progress speedup
		*(float*)0x034BBADC = 0.000049999999f;

		//Crayon fix
		NJS_MDATA2* data2 = (NJS_MDATA2*)ChaoAnimations[328].NJS_MOTION->mdata;
		data2[11].p[1] = &stru_381B7A0;
		data2[11].nb[1] = data2[10].nb[1];

		Chao_Init();
		Toys_Init();

		//disp field reenabled, debug, not even sure if it does anything
		*(int*)0x034BB9D0 = 1;

		//Sound restoration
		WriteJump((void*)0x00736E90, AL_IconSetOverwrite);
		WriteCall((void*)0x0073BC47, SwimSound);
		WriteCall((void*)0x0073C292, SwimLandSound);
		WriteCall((void*)0x0075E31F, RunFromPlayerOverwrite);
		WriteCall((void*)0x0073CD4D, ThinkOverwrite);
		WriteCall((void*)0x0075E169, ShiwerOverwrite);
		//WriteCall((void*)0x075BCD7, GetFruitOverwrite); //crawl

		if (config->getBool("Chao World Extended", "DarkEye", false))
		{
			WriteCall((void*)0x00737505, DarkEyeHack);
		}

		//not available for now, needs a huge rewrite
		if (config->getBool("Chao World Extended", "3DEmotion", true))
		{
			//WriteJump((void*)0x007364D0, EmotionBall_Display);
		}

		//Button restoration, unneeded for now
		//WriteCall((void*)0x0074D7BA, OdekakeButtons);
		//WriteData((char*)0x0074D839, (char)0);
		//WriteData((char*)0x0074D858, (char)0);

		//0x75465C - createchao for races, just incase needed
		//WriteJump((void*)0x00754D00, KillAnimation);
		//WriteCall((void*)0x00719DCD, OverrideRace);

		//restoring dances somewhere? not sure anymore
		WriteCall((void*)0x00767FCC, OverrideCreateRace);
		WriteCall((void*)0x00746908, WaitDance);
		WriteCall((void*)0x00769235, OverrideCreateRace2);

		//patch for clipping mouths
		WriteCall((void*)0x0073EE3E, FixMouth);

		//debug trigger field thing
		if (config->getBool("Chao World Extended", "DebugTriggerField", false))
		{
			//WriteJump((void*)0x764900, ALOField_Display);
			//WriteJump((void*)0x007648D0, ALOField_Main);
		}

		//Shiny Jewel egg patch.
		if (config->getBool("Chao World Extended", "ShinyJewelEgg", true))
		{
			shinyjewelegg = true;
			WriteJump((void*)0x78AC80, EggColoring);
		}

		//Shiny Jewels are now transparent [TODO: REWRITE]
		if (config->getBool("Chao World Extended", "ShinyJewelPC", true))
			PatchShinyJewelPC();
		if (config->getBool("Chao World Extended", "ShinyJewelGC", false))
			PatchShinyJewelGC();

		if (config->getBool("Chao World Extended", "Dreamcast", true))
		{
			ReplaceTextures("CHAO", "CHAO_DCCWE");

			WriteJump((void*)0x0076EF10, Flower_Load);
			WriteCall((void*)0x0076EED8, BreedingFlower1);
			WriteCall((void*)0x0076EEF0, BreedingFlower2);
			WriteData((char*)0x034BBACA, (char)0x09); //amount of flowers that pop up
			WriteCall((void*)0x0073F2E0, DrawDCToys);
			WriteCall((void*)0x0073E7DB, DrawDCToys2);
		}

		colorMixing = config->getBool("Chao World Extended", "ColorMixing", true);
		monsterEvo = config->getBool("Chao World Extended", "MonsterEvo", true);
		randomMouthAndEye = config->getBool("Chao World Extended", "RandomMEye", true);

		delete config;
	}
	Color colors[] = { Color(255,255,255),Color(0, 255, 255), Color(255,255,255), Color(0x00, 0x64, 0x96), Color(0xFA, 0xD2, 0), Color(0xE6, 0x78, 0xFF), Color(0xFF, 0x46, 0x3C), Color(0x8C, 0x8C, 0x8C),
			Color(0, 0x96, 0), Color(0, 0, 0xFF), Color(0, 0xFF, 0xAA),Color(0xFF, 0, 0xB4), Color(0, 0x7D, 0xFF), Color(0x37,0x37,0x37) };
	_declspec (dllexport) void OnFrame(const char* path)
	{
		//chao colors
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
					if (chaobases[i].data.StatPoints[0] >= 2000 && chaobases[i].data.FlySwim == -1 && chaobases[i].data.EvolutionProgress >= 1.0f)
					{
						chaobases[i].data.EvolutionProgress = 1.2f;
						chaobases[i].data.FlySwim = -1.5f;
					}
					if (chaobases[i].data.StatPoints[1] >= 2000 && chaobases[i].data.FlySwim == 1 && chaobases[i].data.EvolutionProgress >= 1.0f)
					{
						chaobases[i].data.EvolutionProgress = 1.2f;
						chaobases[i].data.FlySwim = 1.5f;
					}
					if (chaobases[i].data.StatPoints[2] >= 2000 && chaobases[i].data.PowerRun == -1 && chaobases[i].data.EvolutionProgress >= 1.0f)
					{
						chaobases[i].data.EvolutionProgress = 1.2f;
						chaobases[i].data.PowerRun = -1.5f;
					}
					if (chaobases[i].data.StatPoints[3] >= 2000 && chaobases[i].data.PowerRun == 1 && chaobases[i].data.EvolutionProgress >= 1.0f)
					{
						chaobases[i].data.EvolutionProgress = 1.2f;
						chaobases[i].data.PowerRun = 1.5f;
					}
				}

				//Random Mouth and Eye	
				if (randomMouthAndEye && chaobases[i].data.Type == 1 && chaobases[i].data.Reincarnations == 0)
				{
					chaobases[i].data.MouthType++;
					if (chaobases[i].data.MouthType > 15)
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