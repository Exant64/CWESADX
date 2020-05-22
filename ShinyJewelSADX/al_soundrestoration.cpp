
#include "al_soundrestoration.h"
void ThinkOverwrite(ObjectMaster* a1, char a2, int a3) //think sound restored
{
	AL_IconSet(a1, a2, a3);
	PlaySoundXYZAlt(1145, //definitely not right sound
		a1->Data1,
		1,
		120,
		a1->Data1->Position.x,
		a1->Data1->Position.y,
		a1->Data1->Position.z);
}

void RunFromPlayerOverwrite(ObjectMaster* a1, int a2) //run from player sound restored
{
	AL_FaceSetMouth(a1, a2, -1);
	PlaySoundXYZAlt(1162,
		a1->Data1,
		1,
		120,
		a1->Data1->Position.x,
		a1->Data1->Position.y,
		a1->Data1->Position.z);
}

void TouchChinOverwrite() //unused for now, need to figure out sound
{
	ObjectMaster* a1;
	__asm {mov a1, esi}
	int v3;
	if ((double)rand() * 0.000030517578125 >= 0.5)
	{
		v3 = 1138;
	}
	else
	{
		v3 = 1137;
	}
	PlaySoundXYZAlt(v3,
		a1->Data1,
		1,
		120,
		a1->Data1->Position.x,
		a1->Data1->Position.y,
		a1->Data1->Position.z);


} //"touch chin" sounds

void ShiwerOverwrite() //unused for now, need to figure out sound
{
	ObjectMaster* a1;
	__asm {mov a1, edi}
	//1162 was running from player sound
	PlaySoundXYZAlt(1161,
		a1->Data1,
		1,
		120,
		a1->Data1->Position.x,
		a1->Data1->Position.y,
		a1->Data1->Position.z);


} //"touch chin" sounds

void GetFruitOverwrite()
{
	ObjectMaster* a1;
	__asm {mov a1, esi}
	int v3;
	if ((double)rand() * 0.000030517578125 >= 0.5)
		v3 = 1138;
	else
		v3 = 1137;
	PlaySoundXYZAlt(v3,
		a1->Data1,
		1,
		120,
		a1->Data1->Position.x,
		a1->Data1->Position.y,
		a1->Data1->Position.z);
} //crawl sounds

void SwimLandSound(ObjectMaster* a1, signed int(__cdecl* a2)(ObjectMaster*))
{
	PlaySoundXYZAlt(632, a1->Data1, 1, 120, a1->Data1->Position.x, a1->Data1->Position.y, a1->Data1->Position.z);
	AL_SetBehavior(a1, a2);
}

void SwimSound(ObjectMaster* a1, int a2)
{
	MOV_TurnToAim2(a1, a2);
	PlaySoundXYZAlt(631, a1->Data1, 1, 120, a1->Data1->Position.x, a1->Data1->Position.y, a1->Data1->Position.z);
	//QueueSound_XYZ(631, a1->Data1, 1, 120, a1->Data1->Position.x, a1->Data1->Position.y, a1->Data1->Position.z, 200);
}

void __cdecl AL_IconSetOverwrite(ObjectMaster* a1, char a2, int a3)
{
	chaowk* data1 = (chaowk*)a1->Data1;
	data1->Icon.NextType = a2;
	data1->Icon.Timer = 0;
	data1->Icon.NextTimer = a3;
	PlaySoundXYZAlt(614, a1->Data1, 1, 120, a1->Data1->Position.x, a1->Data1->Position.y, a1->Data1->Position.z);
}
void Chao_Tantrumalt(ObjectMaster* a1, int a2, int a3)
{
	AL_FaceSetMouth(a1, a2, a3);
	QueueSound_XYZ(1002, a1->Data1, 1, 120, a1->Data1->Position.x, a1->Data1->Position.y, a1->Data1->Position.z, 200);
}
