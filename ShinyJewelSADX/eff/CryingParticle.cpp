#include "stdafx.h"
#include "CryingParticle.h"
ParticleUserData cryingUserData = { 1, 0, 0, 8, 0.5, 0.99800003, -0.029999999, 0.0099999998, 0, 75000.0, 0, 0, 0, 0 };

NJS_TEXANIM cryingTexAnim[] =
{ {0x20, 0x20, 0x10, 0x10, 0, 0x0FF, 0x0FF, 0, 78, 0} ,
{0x20, 0x20, 0x10, 0x10, 0, 0x0FF, 0x0FF, 0, 79, 0} ,
{0x20, 0x20, 0x10, 0x10, 0, 0x0FF, 0x0FF, 0, 80, 0} ,
{0x20, 0x20, 0x10, 0x10, 0, 0x0FF, 0x0FF, 0, 81, 0} ,
{0x20, 0x20, 0x10, 0x10, 0, 0x0FF, 0x0FF, 0, 82, 0} ,
{0x20, 0x20, 0x10, 0x10, 0, 0x0FF, 0x0FF, 0, 83, 0} ,
{0x20, 0x20, 0x10, 0x10, 0, 0x0FF, 0x0FF, 0, 84, 0} ,
{0x20, 0x20, 0x10, 0x10, 0, 0x0FF, 0x0FF, 0, 85, 0} ,
};
NJS_SPRITE cryingPart = { {0,0,0}, 1,1,0, (NJS_TEXLIST*)0x0094A2A8, &cryingTexAnim[0] };
void CryingParticle_Display(ObjectMaster * a1)
{
	ParticleData* v2 = (ParticleData *)a1->UnknownB_ptr;
	if(v2)
	{
		njPushMatrixEx();
		njTranslateEx(&v2->position);
		njScale(0, 0.01f, 0.01f, 0.01f);
		njDrawSprite3D_Queue(&cryingPart, v2->frame,  NJD_SPRITE_ALPHA, QueuedModelFlagsB_SomeTextureThing);
		njPopMatrixEx();
	}
}

void CryingParticle_Main(ObjectMaster * a1)
{
	ParticleData* v2 = (ParticleData *)a1->UnknownB_ptr;
	ParticleUserData* v3 = (ParticleUserData *)a1->UnknownA_ptr;
	v2->position.x += v2->velocity.x;
	v2->position.y += v2->velocity.y;
	v2->position.z += v2->velocity.z;
	v2->velocity.x *= v3->velocityLoss;
	v2->velocity.y *= v3->velocityLoss;
	v2->velocity.z *= v3->velocityLoss;

	v2->velocity.y += v3->gravity;

	//v2->frame += v3->speed;
	if (v2->frame > v3->frames)
		a1->MainSub = DeleteObject_;
	a1->DisplaySub(a1);
}

void CryingParticle_Load(NJS_VECTOR * vel, NJS_VECTOR * pos, float scale)
{
	ObjectMaster* particle = LoadObject(LoadObj_Data1, 3, CryingParticle_Main);
	particle->DisplaySub = CryingParticle_Display;

	if(particle)
	{
		ParticleData* v2 = (ParticleData *)AllocateArray(1, sizeof(ParticleData));
		particle->UnknownB_ptr = v2;
		ParticleUserData* v3 = &cryingUserData;
		particle->UnknownA_ptr = v3;
		v2->position = *pos;
		v2->velocity = *vel;
	}
	
}
