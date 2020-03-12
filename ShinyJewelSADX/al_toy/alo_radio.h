#pragma once
#include "SADXModLoader.h"
#include <random>

DataPointer(NJS_CNK_OBJECT, Radio, 0x389B3E4);
DataPointer(ObjectMaster*, ALO_RadicaseExecutor_ptr, 0x3CE6CF0);

	void Radio_Main(ObjectMaster* a1);
	void Radio_Display(ObjectMaster* a1);
	void Radio_Load(ObjectMaster* a1);
	void PlaceRadio();
