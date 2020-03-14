#pragma once
#include "SADXModLoader.h"
#include "IniFile.hpp"
#include "chao.h"
#include "al_toy/alo_toy.h"
#include "Trampoline.h"
#include "ModelInfo.h"
FunctionPointer(void, SetNextChaoLevel, (int a1), 0x00715700);
DataPointer(int, dword_34BBA10, 0x34BBA10); // 
DataPointer(int, dword_34BBA0C, 0x34BBA0C);

DataPointer(NJS_CNK_OBJECT, Trumpet, 0x036B22E4);

#define ReplaceTextures(a,b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");

struct BlackMarketItemAttributes { int PurchasePrice; int SalePrice; short RequiredEmblems; short Name; short Description; short Unknown; };


FunctionPointer(signed int, sub_76F200, (NJS_VECTOR *a1), 0x76F200);

DataArray(int, dword_33B87E0, 0x33B87E0, 3);
DataArray(int, dword_33B87B4, 0x33B87B4, 10);

FunctionPointer(int, sub_719F70, (NJS_VECTOR *a1), 0x719F70);

DataArray(ChaoData, chaobases, 0x03C88878, 24); //All the chaodata	


FunctionPointer(bool, Chao_CheckSADXAnimal, (ObjectMaster *a1, char a2), 0x00734E90);
FunctionPointer(bool, Chao_CheckSA2Animal, (ObjectMaster *a1, char a2), 0x00734E10);
FunctionPointer(bool, sub_71A320, (ObjectMaster *a1), 0x71A320);
FunctionPointer(CharObj2 *, sub_4420C0, (unsigned __int8 a1), 0x4420C0);
FunctionPointer(int, sub_744810, (ObjectMaster *a1, ObjectMaster *a2), 0x744810);
//FunctionPointer(ObjectMaster *, __cdecl ALOField_Find2, (ChaoData1 *a1, unsigned __int8 a2), 0x0041C930);

FunctionPointer(bool, CheckAnimalPart, (ObjectMaster* a1, char a2), 0x734E90);
FunctionPointer(void, GardenFruit_Create, (int a1, NJS_VECTOR *position, Angle angle, NJS_VECTOR *a4, ChaoData *a5), 0x722DE0);
FunctionPointer(void, sub_408530, (NJS_OBJECT *a1), 0x408530);

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

DataPointer(NJS_CNK_OBJECT, BreedingFlower, 0x3895B2C);

ObjectFunc(sub_76EE00, (void*)0x76EE00);
FunctionPointer(void, sub_76EE70, (ObjectMaster *a1), (void*)0x76EE70);

void ChaoDebug_Init();