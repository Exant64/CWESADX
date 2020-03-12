#pragma once
#include "chao.h"
FunctionPointer(Sint32, __cdecl PlaySoundXYZAlt, (int a1, EntityData1* a2, int a3, int a4, float x, float y, float z), 0x0424FC0);
void ThinkOverwrite(ObjectMaster* a1, char a2, int a3);
void RunFromPlayerOverwrite(ObjectMaster* a1, int a2);
void TouchChinOverwrite();
void ShiwerOverwrite();
void GetFruitOverwrite();
void SwimLandSound(ObjectMaster* a1, signed int(__cdecl* a2)(ObjectMaster*));
void SwimSound(ObjectMaster* a1, int a2);
void __cdecl AL_IconSetOverwrite(ObjectMaster* a1, char a2, int a3);
void Chao_Tantrumalt(ObjectMaster* a1, int a2, int a3);