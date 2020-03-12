#include "stdafx.h"
#include "SADXModLoader.h"
#include <string>
#include "motiontable.h"

void __cdecl DisplayDebugFloat_(int position, float value, signed int percision)
{
	char v3; // al
	char Format[4]; // [esp+8h] [ebp-8Ch]
	char Dest[50]; // [esp+10h] [ebp-84h]

	strcpy(Format, "%00f");
	v3 = percision;
	if (percision > 9)
	{
		v3 = 9;
	}
	Format[2] += v3;
	sprintf(Dest, Format, value);
	DisplayDebugString(position, Dest);
}

void ChaoDebug_MOTIONTABLE(ObjectMaster* a1)
{
	EnableControl();

	ObjectMaster* chao = GetChaoObject(0, a1->Data1->Rotation.x);

	if (ChaoDebug_Buttons[0] & Buttons_B)
		ChaoDebug_MenuBack(a1);
	
	if (chao) 
	{
		MOTION_CTRL* data = &((ChaoData1*)chao->Data1)->MotionCtrl;
		DisplayDebugString(NJM_LOCATION(10, 3), "FRM:");
		DisplayDebugString(NJM_LOCATION(10, 4), "LNK:");
		DisplayDebugString(NJM_LOCATION(10, 5), "FLG:");
		DisplayDebugString(NJM_LOCATION(10, 6), "SFE:");
		DisplayDebugFloat(NJM_LOCATION(17, 3), data->frame, 3);
		DisplayDebugFloat(NJM_LOCATION(17, 4), data->linkFrame, 3);
		PrintDebugNumber(NJM_LOCATION(17, 5), data->flag, 2);
		PrintDebugNumber(NJM_LOCATION(17, 6), data->SomeFlagThingInEntry2, 3);
	}
	//DisplayDebugString(NJM_LOCATION(10, 2), "CURR TYPE");
	//DisplayDebugString(NJM_LOCATION(10, 3), "CURR TYPE");
}

void ChaoDebug_EYEPOS(ObjectMaster* a1)
{
	EnableControl();

	ObjectMaster* chao = GetChaoObject(0, a1->Data1->Rotation.x);

	if (ChaoDebug_Buttons[0] & Buttons_B)
		ChaoDebug_MenuBack(a1);

	if (chao)
	{
		if (ChaoDebug_Buttons[0] & Buttons_Right)
			((ChaoData1*)chao->Data1)->Face.EyePosX += 0.05f;
		if (ChaoDebug_Buttons[0] & Buttons_Left)
			((ChaoData1*)chao->Data1)->Face.EyePosX -= 0.05f;
		DisplayDebugString(NJM_LOCATION(10, 2), "EYEX");
		DisplayDebugFloat(NJM_LOCATION(15, 2), ((ChaoData1*)chao->Data1)->Face.EyePosX, 3);
	}
	
	//DisplayDebugString(NJM_LOCATION(10, 3), "CURR TYPE");
}


//add new menu
void SetChaoDebugFunctionsHook()
{
	SetChaoDebugFunctions();
	SetChaoDebugFunction_Enabled(ChaoDebug_MOTIONTABLE, "MOTIONTABLE");
	SetChaoDebugFunction_Enabled(ChaoDebug_EYEPOS, "EYE POS");
}

FunctionPointer(float, Chao_MotiontableFrame, (ObjectMaster* a1), 0x00734FC0);
FunctionPointer(int, Chao_ReturnCurrentAnimation, (ObjectMaster* a1), 0x00734FE0);
FunctionPointer(void, SetMotionTableFrame, (ObjectMaster* a1, float a2), 0x00734FA0);
FunctionPointer(void, AL_SetMotionSkip, (ObjectMaster* a1, int a2), 0x734F60);
FunctionPointer(void, Chao_UpdateModel, (ObjectMaster* a1), 0x00741F20);
FunctionPointer(void, Chao_EmotionBallHandler, (ObjectMaster* a1), 0x00736140);
bool animDataToggle = false;
//add a little indicator, not actual restoration, just for testing
void __cdecl ChaoDebug_MOTION_(ObjectMaster* a1)
{
	ObjectMaster* chao; // edi
	int v2; // esi
	double v3; // st7
	float a2; // ST04_4
	int v5; // esi
	signed int v6; // esi
	float a1a; // [esp+10h] [ebp+4h]

	chao = GetChaoObject(0, a1->Data1->Rotation.x);
	
	if (ChaoDebug_Buttons[0] & Buttons_B)
	{
		ChaoDebug_MenuBack(a1);
	}
	a1a = Chao_MotiontableFrame(chao);
	v2 = Chao_ReturnCurrentAnimation(chao);
	DisplayDebugString(NJM_LOCATION(10, 3), "ANIM ID:");
	PrintDebugNumber(NJM_LOCATION(17, 3), v2, 3);

	if (ChaoDebug_Buttons[0] & Buttons_Left)
	{
		SetMotionTableFrame(chao, a1a - 0.050000001);
	}
	else if(ChaoDebug_Buttons[0] & Buttons_Right)
	{
		SetMotionTableFrame(chao, a1a + 0.050000001);
	}
	else if (ChaoDebug_Buttons[0] & Buttons_A)
	{
		animDataToggle = true;
	}
	
	if (!animDataToggle) 
	{
		if (ChaoDebug_Buttons[0] & Buttons_Up)
		{
			v5 = v2 - 1;
			if (v5 < 0)
			{
				v5 = 624;
			}
		LABEL_14:
			AL_SetMotionSkip(chao, v5);
			goto LABEL_15;
		}
		if (ChaoDebug_Buttons[0] & Buttons_Down)
		{
			v5 = v2 + 1;
			if (v5 > 624)
			{
				v5 = 0;
			}
			goto LABEL_14;
		}
	LABEL_15:
		v6 = 0;
		do
		{
			if (v6 == 5)
			{
				SetDebugFontColor(0xFFFFFFFF);
			}
			else
			{
				SetDebugFontColor(0xFFAFAFAF);
			}
			++v6;
		} while (v6 < 11);
	}
	Chao_UpdateModel(chao);
	Chao_EmotionBallHandler(chao);
}
void ChaoDebug_Init()
{
	//add new debug menus for REing

	//displaydebugfloat restoration
	WriteJump(DisplayDebugFloat, DisplayDebugFloat_);

	WriteCall((void*)0x0071A805, SetChaoDebugFunctionsHook);
	WriteJump((void*)ChaoDebug_MOTION, ChaoDebug_MOTION_);

	//my clean rewrite, not enabled for now
	//WriteJump((void*)0x0073F830, MotionTableLoop);
	
}
