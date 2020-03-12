#pragma once

#include "SADXModLoader.h"
#include <random>

FunctionPointer(void, __cdecl sub_720A70, (NJS_CNK_OBJECT* a1, NJS_MOTION* a2, float a3), 0x720A70);
FunctionPointer(void, __cdecl SADXHeapFree, (LPVOID lpMem), 0x00780FB0);
FunctionPointer(void, __cdecl sub_73F6E0, (void* a1, MotionTableEntry* a2), 0x73F6E0);
FunctionPointer(void, __cdecl njAction_QueueObject, (NJS_OBJECT* a1, NJS_MOTION* a2, float a3), 0x00407040);
FunctionPointer(void, __cdecl MotionTableLoop, (MOTION_CTRL* a1), 0x73F830);
FunctionPointer(void, __cdecl LoadMotionTable, (MOTION_CTRL* a1, MOTION_TABLE* a2), 0x73F7E0);
FunctionPointer(ChaoData2*, __cdecl AllocateMove, (ObjectMaster* chao), 0x0073FE70);
FunctionPointer(LPVOID, __cdecl SADXHeapAlloc, (int count, int size), 0x00780F90);
FunctionPointer(void, __cdecl PlayMotionTable, (MOTION_CTRL* a1, int a2), 0x73F5A0);
signed int  sub_530690(ObjectMaster* a1);
void Horse_Main(ObjectMaster* a1);
void Horse_Display(ObjectMaster* a1);
void Horse_Load(ObjectMaster* a1);
void PlaceHorse();
