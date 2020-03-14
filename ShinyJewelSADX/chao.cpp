#include "stdafx.h"
#include "chao.h"
#include <cstdlib>

#include "albhv/albhv_hanabi.h"
#include "albhv/albhv_piano.h"
#include "albhv/albhv_console.h"
#include "albhv/albhv_float.h"
#include "albhv/albhv_fishing.h"
#include "albhv/albhv_ball.h"

#include "al_knowledge.h"

FunctionPointer(void, SetChunkColor, (int a1), 0x0078A320);
FunctionPointer(void, ApplyWSwitch, (int a1), 0x00717470);

static const void* const SwimControlPtr = (void*)0x73BB40;
void SwimControl(ObjectMaster* a1)
{
	__asm {
		mov esi, [a1]
		call SwimControlPtr
	}
}

signed int __cdecl Tantrum(ObjectMaster* a1)
{
	ObjectMaster* v1; // edi
	chaowk* v2; // esi
	int v3; // eax
	float v6; // ST2C_4
	//Data1Ptr v8; // esi
	v1 = a1;
	v2 = (chaowk*)a1->Data1;
	v3 = v2->Behavior.Mode;
	if (v3)
	{
		if (v3 == 1)
		{
			v2->Behavior.Timer--;
			if (v2->Behavior.Timer <= 0)
			{
				v6 = (10000 - AL_EmotionGetValue(a1, (EMOTION_ENUM)0xAu)) * 0.000099999997;

				AL_SetIntervalTimer(v1, 0xEu, ((rand() * 0.000030517578f + v6) * 10800 * 0.5f + 1200));
				return 1;
			}
		}
	}
	else
	{
		AL_FaceSetEye(a1, 1, -1);
		AL_FaceSetMouth(a1, 6, -1);
		AL_SetMotionLinkStep(a1, 479, 0x14u);
		++v2->Behavior.Mode;
		v2->Behavior.Timer = (240 - (rand() * 0.000030517578f * -201.0f));
	}
	/*
	if (v4->Timer % 8 < 4)
	{
		float v13 = v2->RightEyeTranslationPos.x;
		NJS_VECTOR v16;
		NJS_VECTOR v17;
		v16.y = v2->RightEyeTranslationPos.y;
		v14 = v2->RightEyeTranslationPos.z;
		v16.x = v13;
		v16.y = v16.y - 0.2000000029802322;
		v15 = v2->RightEyeUnitTransPortion.x;
		v16.z = v14;
		v17.x = v15 * 0.1000000014901161;
		v17.y = v2->RightEyeUnitTransPortion.y * 0.1000000014901161 + 0.1000000014901161;
		v17.z = 0.1000000014901161 * v2->RightEyeUnitTransPortion.z;
		CryingParticle_Load(&v17, &v16, 0.1);
		v16.y = v2->LeftEyeUnitTransPortion.y;
		v14 = v2->LeftEyeUnitTransPortion.z;
		v16.x = v13;
		v16.y = v16.y - 0.2000000029802322;
		v15 = v2->LeftEyeTranslationPos.x;
		v16.z = v14;
		v17.x = v15 * 0.1000000014901161;
		v17.y = v2->LeftEyeTranslationPos.y * 0.1000000014901161 + 0.1000000014901161;
		v17.z = 0.1000000014901161 * v2->LeftEyeTranslationPos.z;
		CryingParticle_Load(&v17, &v16, 0.1);
	}
	*/
	if (!(v2->Behavior.Timer % 60) && rand() * 0.000030517578125 < 0.5)
	{
		QueueSound_XYZ(1002, a1->Data1, 1, 120, a1->Data1->Position.x, a1->Data1->Position.y, a1->Data1->Position.z, 200);
	}
	return 0;
}

signed int __cdecl FartReaction(ObjectMaster* a1)
{
	ChaoData1* v2;

	v2 = (ChaoData1*)a1->Data1;
	if (!v2->Behavior.Mode)
	{
		AL_SetMotionLink(a1, 499 - 6);
		AL_IconSet(a1, 5, 180);
		AL_FaceSetEye(a1, 1, -1);
		AL_FaceSetMouth(a1, 4, -1);
		++v2->Behavior.Mode;
	}
	v2->Behavior.Timer++;
	if (v2->Behavior.Timer >= 60 * 5)
		return 1;
	return 0;
}

int(__cdecl* ALBHV_IllnessFunc[])(ObjectMaster*) =
{
  ALBHV_Seki,
  ALBHV_Kusyami,
  ALBHV_Kayui,
  ALBHV_Hanamizu,
  ALBHV_Syakkuri,
  ALBHV_Haraita
};
void AL_CalcIntention_Illness(ObjectMaster* a1, float* a2)
{
	ChaoData1* data1 = (ChaoData1*)a1->Data1;
	for (int i = 0; i < 6; i++) 
	{
		if (data1->pParamGC->Emotion.IllState[i] < 0)
		{
			if (((AL_EmotionGetValue(a1, EM_ST_CONDITION)) + 20000) < (rand() * 0.000030517578125f * 30000.0f))
			{
				AL_SetBehavior(a1, ALBHV_IllnessFunc[i]);
				*a2 = 0.99f;
			}
		}
	}
}

void ThinkControllerHook(ObjectMaster* a1, float* a2)
{
	ChaoData1* data1 = (ChaoData1*)a1->Data1;
	ChaoData2* data2 = (ChaoData2*)a1->Data2;

	//fart reaction restoration
	if (ALOField_Find(a1, 1, 151))
	{
		AL_SetBehavior(a1, FartReaction);
		*a2 = 1;
	}

	AL_CalcIntention_Illness(a1, a2);
	AL_CalcIntentionScore_Fear(a1, a2);
}

void HeroDarkRattle(ObjectMaster* a1, int a2, NJS_CNK_OBJECT* model, NJS_TEXLIST* texlist)
{
	DataPointer(NJS_CNK_OBJECT, NormalRattle, 0x36B6E6C);
	DataPointer(NJS_CNK_OBJECT, HeroRattle, 0x36B66B4);
	DataPointer(NJS_CNK_OBJECT, DarkRattle, 0x36B58EC);
	if (AL_IsHero2(a1))
	{
		AL_SetItem(a1, a2, &HeroRattle, &AL_TOY_TEXLIST);
	}
	else if (AL_IsDark2(a1))
	{
		AL_SetItem(a1, a2, &DarkRattle, &AL_TOY_TEXLIST);
	}
	else
	{
		AL_SetItem(a1, a2, &NormalRattle, &AL_TOY_TEXLIST);
	}
}

char __cdecl Chao_Evolve2(ObjectMaster* a1)
{
	DataPointer(float, HPosVPosMinimum, 0x034BBA0C);
	DataPointer(float, AlignmentMinimum, 0x034BBA10);
	ChaoDataBase* v1; // esi
	char type; // bl
	v1 = ((ChaoData1*)a1->Data1)->pParamGC;
	if (-HPosVPosMinimum >= v1->PowerRun || v1->PowerRun >= HPosVPosMinimum || -HPosVPosMinimum >= v1->FlySwim || v1->FlySwim >= HPosVPosMinimum)
	{
		if (v1->PowerRun >= v1->FlySwim)
		{
			type = ChaoType_Neutral_Power;
			if (-v1->PowerRun >= v1->FlySwim)
			{
				type = ChaoType_Neutral_Swim;
			}
		}
		else if (-v1->PowerRun >= v1->FlySwim)
		{
			type = ChaoType_Neutral_Run;
		}
		else
		{
			type = ChaoType_Neutral_Fly;
		}

		int i = 0;
		while (v1->SADXAnimalBehaviors & (1 << i))
		{
			if (++i >= 15)
			{
				if (v1->Happiness > 80 && v1->Reincarnations >= 2u)
				{
					if (type == ChaoType_Neutral_Fly)
						type = ChaoType_Tails;
					if (type == ChaoType_Neutral_Power)
						type = ChaoType_Knuckles;
					if (type == ChaoType_Neutral_Run)
						type = ChaoType_Amy;
				}
				break;
			}
		}
	}
	else
	{
		type = ChaoType_Neutral_Normal;
		int i = 0;
		while (v1->SADXAnimalBehaviors & (1 << i))
		{
			if (++i >= 15)
			{
				if (v1->Happiness > 80 && v1->Reincarnations >= 2u)
				{
					type = ChaoType_Neutral_Chaos;
				}
				break;
			}
		}
	}
	if ((-AlignmentMinimum >= v1->Alignment || v1->Alignment >= AlignmentMinimum)) //hero or dark
	{
		if ((type >= ChaoType_Tails && type <= ChaoType_Amy))
			type = ChaoType_Neutral_Normal;
		if (v1->Alignment <= 0.0) //if dark then
		{
			type += 2; //turn neutral into dark
			ApplyWSwitch(0x40);
			PlayJingle(118);
		}
		else //else if hero then
		{
			++type; //turn neutral into hero
			ApplyWSwitch(0x10);
			PlayJingle(117);
		}
	}
	else
	{
		if (type >= ChaoType_Tails && type <= ChaoType_Amy)
		{

			//PlayJingle("chao_new_garden.adx");
		}
	}
	v1->Type = (ChaoType)type;
	v1->EvolutionProgress = 0.0;
	v1->PowerRun = 0.0;
	v1->FlySwim = 0.0;
	Chao_IncrementTypeStat(&v1->DNA, v1);
	return type;
}

enum ChunkMaterialFlagsEnum
{
	DontUseTexture = 0x1,
	HasSecondTexture = 0x2,
	SecondTextureEnvironmentMap = 0x4,
	UseChunkObjectColor = 0x8,
};

void __cdecl ChaoColoring(int texture, int color, int shiny, int highlights, NJS_CNK_MODEL* model)
{
	int flag; // esi
	unsigned __int16 v6; // ax
	_BOOL1 noTexture; // zf
	unsigned __int16 v8; // ax


	flag = 0;
	if (model)
	{
		if (shiny)
		{
			flag = SecondTextureEnvironmentMap | HasSecondTexture;
			SetChunkTextureIndexB(34u);
			v6 = GetChunkTextureIndex(model);
			SetChunkTextureIndexA(v6);
		}
		else
		{
			noTexture = texture == 0;
			if (texture <= 0)
			{
			LABEL_7:
				if (noTexture)
				{
					if (color > 0)
					{
						flag |= UseChunkObjectColor;
						SetChunkColor(((int*)0x0389D828)[color]);
					}
					if (highlights)
					{
						flag |= DontUseTexture;
					}
					else
					{
						v8 = GetChunkTextureIndex(model);
						SetChunkTextureIndexA(v8);
					}
				}
				if (flag)
				{
					EnableChunkMaterialFlags();
					SetChunkMaterialFlags((ChunkMaterialFlagsEnum)flag);
				}
				else
				{
					DisableChunkMaterialFlags();
					SetChunkMaterialFlags(0);
				}
				return;
			}
			flag = UseChunkObjectColor | SecondTextureEnvironmentMap;
			SetChunkColor(-1);
			SetChunkTextureIndexA(texture + 17);
		}
		noTexture = texture == 0;
		goto LABEL_7;
	}
}

void AL_CalcParameter_Condition(ObjectMaster* a1, EMOTION_ENUM a2, int a3)
{
	//todo check if this works?
	AL_EmotionAdd(a1, a2, a3);

	if(AL_EmotionGetValue(a1,EM_ST_NOURISHMENT) > ChaoGlobal.ParamConditionTriggerAddN)
		AL_EmotionAdd(a1, EM_ST_CONDITION, ChaoGlobal.ParamAddConditionN);
	if (AL_EmotionGetValue(a1, EM_ST_NOURISHMENT) < ChaoGlobal.ParamConditionTriggerSubN)
		AL_EmotionAdd(a1, EM_ST_CONDITION, -ChaoGlobal.ParamSubConditionN);
	if (AL_EmotionGetValue(a1, EM_ST_STRESS) > ChaoGlobal.ParamConditionTriggerS)
		AL_EmotionAdd(a1, EM_ST_CONDITION, -ChaoGlobal.ParamSubConditionS);
	if (AL_EmotionGetValue(a1, EM_MD_PAIN) > ChaoGlobal.ParamConditionTriggerP)
		AL_EmotionAdd(a1, EM_ST_CONDITION, -ChaoGlobal.ParamSubConditionP);
}

void Chao_Init()
{
	//dont remember
	//WriteJump((void*)0x0078AE30, ChaoColoring);

	//character chao
	WriteJump((void*)0x0073C3A0, Chao_Evolve2);

	//sound restoration, todo restore particles
	WriteJump((void*)0x007622B0, Tantrum);

	//console restoration 
	WriteJump(ALBHV_GoToTV, ALBHV_GoToTV_);

	//temp debug hanabi
	WriteJump(ALBHV_Think, ALBHV_Hanabi_);

	//float toy
	WriteCall((void*)0x0073C13F, ALBHV_FloatCheck);

	//piano
	WriteData((int*)0x0075F2E1, (int)ALBHV_GoToPiano);
	//WriteData((int*)0x0075F2E8, (int)& Chao_BallJoinDecision);
	//WriteData((int*)0x0075F2EE, (int)& behaviour::ALBHV_GoToConsole);

	//distance timers restored
	WriteCall((void*)0x00731B35, AL_KW_Control);
	WriteCall((void*)0x00731B1F, AL_KW_Control);

	//brings back condition values increasing
	WriteCall((void*)0x00731A8F, AL_CalcParameter_Condition);

	//think controller custom
	WriteCall((void*)0x0073D4B1, ThinkControllerHook);

	//unused rattles
	WriteCall((void*)0x00763345, HeroDarkRattle); 
	
}
