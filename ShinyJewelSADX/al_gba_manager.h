#pragma once
#include "SADXModLoader.h"

struct GBAManagerThing
{
	int thing;
	int field_4;
	int field_8;
	int mode;
	int field_10;
	int field_14;
	int field_18[11];
	int field_44[11];
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	ChaoData chaoData1;
	ChaoData chaoData2;
};

struct GBAManagerData
{
	int dword0;
	int gap4;
	int dword8;
	ObjectMaster* objectPtr;
	int field_10;
	int field_14;
	GBAManagerThing field_18[4];
};

DataPointer(GBAManagerData*, gbaManagerDataPtr, 0x3C88048);