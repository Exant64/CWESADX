#include "stdafx.h"
#include "MusicParticle.h"

//Planned to add some custom details to stuff

void MusicParticle_Display(ObjectMaster *a1)
{
	NJS_SPRITE _sp;
	_sp.p = a1->Data1->Position;
	_sp.sx = a1->Data1->Scale.x;
	_sp.sy = a1->Data1->Scale.x;
	_sp.ang = 0;
	_sp.tlist = (NJS_TEXLIST*)0x97E760;
	_sp.tanim = (NJS_TEXANIM*)0x97E768;
	NJS_ARGB *color = (NJS_ARGB*)a1->Data1->LoopData;
	SetMaterialAndSpriteColor_Float(a1->Data1->InvulnerableTime / 180.0f, color->r, color->g, color->b);
	njColorBlendingMode(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
	njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
	njDrawSprite3D_Queue(
		&_sp,
		0,
		NJD_SPRITE_ALPHA | NJD_SPRITE_SCALE | NJD_SPRITE_COLOR,
		QueuedModelFlagsB_SomeTextureThing);
	njColorBlendingMode(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
	njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);
}

void MusicParticle_Main(ObjectMaster *a1)
{
	a1->Data1->Position.y += 0.1f;
	a1->Data1->InvulnerableTime--;
	if (a1->Data1->InvulnerableTime <= 0)
		a1->MainSub = DeleteObjectMaster;
	a1->DisplaySub(a1);
}

void MusicParticle_Load2(ObjectMaster *musicParticle)
{
	musicParticle->MainSub = MusicParticle_Main;
	musicParticle->DisplaySub = MusicParticle_Display;
}

void MusicParticle_Load(NJS_VECTOR* pos, int timer)
{
	NJS_ARGB colors[3] = { (0, (float)186 / 255, (float)101 / 255), ((float)188 / 255, 0,  1), (0, 1, 1) };
	ObjectMaster* musicParticle = LoadObject(LoadObj_Data1, 3, MusicParticle_Load2);
	musicParticle->Data1->Position = *pos;
	musicParticle->Data1->Scale.x = 0.06f;
	musicParticle->Data1->InvulnerableTime = 180;
	musicParticle->Data1->LoopData = (Loop*)&colors[timer % 3];
}