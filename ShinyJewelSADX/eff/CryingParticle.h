#pragma once
#include "SADXModLoader.h"
#pragma pack(push, 8)
#pragma pack(push, 8)
struct __declspec(align(4)) ParticleUserData
{
	int a1;
	NJS_TEXLIST *texlist;
	int a2;
	int frames;
	float speed;
	float velocityLoss;
	float gravity;
	float scaleUp;
	void *functionPtr;
	float a7;
	int fill1;
	int fill2;
	int fill3;
	int fill4;
};
#pragma pack(pop)

struct __declspec(align(4)) ParticleData
{
	int rotY;
	float scale;
	NJS_VECTOR position;
	int color;
	float frame;
	int field_1C;
	NJS_VECTOR velocity;
	int rotYSpeed;
	float filler3;
	float filler4;
	float filler5;
};
#pragma pack(pop)
//78


void CryingParticle_Display(ObjectMaster *a1);
void CryingParticle_Main(ObjectMaster *a1);
void CryingParticle_Load(NJS_VECTOR *pos, NJS_VECTOR* vel, float scale);