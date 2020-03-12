#pragma once
#include "SADXModLoader.h"
extern NJS_OBJECT object_00F005A0;

DataPointer(NJS_CNK_OBJECT, TVTest, 0x3896F1C);
FunctionPointer(void, __cdecl someUIProjectionCode, (NJS_VECTOR *vs, NJS_VECTOR *vd), 0x00720B10);
namespace al_race 
{
	void ToyPresenter_Display(ObjectMaster* a1);
	void ToyPresenter_Main(ObjectMaster* a1);
	void ToyPresenter_Load(int ID);
}
