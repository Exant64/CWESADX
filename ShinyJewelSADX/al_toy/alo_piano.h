#pragma once
#include "SADXModLoader.h"
#include "alo_radio.h"

DataPointer(NJS_CNK_OBJECT, Piano, 0x0389A014);
void Piano_Display(ObjectMaster* a1);

void Piano_Main(ObjectMaster* a1);

void Piano_Load(ObjectMaster* a1);

void CreatePiano();
