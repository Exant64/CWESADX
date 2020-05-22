
#include "alo_toy.h"
#include "alo_horse.h"
#include "alo_radio.h"
#include "alo_tv.h" 
#include "alo_piano.h"
#include "alo_ball.h"
#include "../SeedGameObject.h"

extern ObjectMaster* PlaceConsole(NJS_VECTOR* pos);

void LoadSSGardenNew()
{
	//ToyPresenter_Load();
//	LoadClassRoom();
	NJS_VECTOR pos = { -52.5f ,0,-120.5f };
	LoadSSGarden();
//	PlaceConsole(&pos);
	if (ChaoSaveFileTest[5])
		PlaceTV();
}
void LoadMRGardenNew()
{
	NJS_VECTOR position;
	NJS_VECTOR velocity;

	LoadMRGarden();
	PlaceHorse();
	//CreatePiano();
	position.x = -64;
	position.y = 1.74;
	position.z = 213;
	velocity.y = 1;
	//Seed_Create(0, &position, 0, &velocity, 0);
}
void LoadECGardenNew()
{
	LoadECGarden();
	PlaceRadio();
}
void Toys_Init()
{
	WriteCall((void*)0x007155D6, LoadSSGardenNew);
	WriteCall((void*)0x007155F6, LoadMRGardenNew);
	WriteCall((void*)0x007155E6, LoadECGardenNew);
}
