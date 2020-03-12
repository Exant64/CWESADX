#pragma once
#include "SADXModLoader.h"


enum MotionTableDataFlags
{
	MotionTableDataFlags_1 = 0x1,
	MotionTableDataFlags_Transitioning = 0x2,
	MotionTableDataFlags_4 = 0x4,
	MotionTableDataFlags_8 = 0x8,
	MotionTableDataFlags_10 = 0x10,
	MotionTableDataFlags_20 = 0x20,
};

void MotionTable_PlayAnim(MOTION_CTRL* motion, int a2);


void __cdecl MotionTable_PlayAnimationRegular(MOTION_CTRL* motiontable, int animid);

void MotionTable_Init(MOTION_CTRL* motion, MOTION_INFO* a2);
