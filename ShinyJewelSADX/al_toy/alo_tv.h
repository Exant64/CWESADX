#pragma once
#include "SADXModLoader.h"
#include "alo_radio.h"
DataPointer(NJS_CNK_OBJECT, TV, 0x3896F1C); 
DataPointer(ObjectMaster*, TVObject, 0x03CE6CEC);
#define SLOWORD(x)   (*((short*)&(x)))
//FunctionPointer(void, __cdecl SetChunkTextureID, (NJS_CNK_MODEL *a1, __int16 a2), 0x75B360);
template<class T> char __SETS__(T x)
{
	if (sizeof(T) == 1)
		return char(x) < 0;
	if (sizeof(T) == 2)
		return short(x) < 0;
	if (sizeof(T) == 4)
		return int(x) < 0;
	return INT64(x) < 0;
}
template<class T, class U> char __OFSUB__(T x, U y)
{
	if (sizeof(T) < sizeof(U))
	{
		U x2 = x;
		char sx = __SETS__(x2);
		return (sx ^ __SETS__(y)) & (sx ^ __SETS__(x2 - y));
	}
	else
	{
		T y2 = y;
		char sx = __SETS__(x);
		return (sx ^ __SETS__(y2)) & (sx ^ __SETS__(x - y2));
	}
}

	extern int TVChannel1;
	extern int TVChannel2;
	extern int TVChannel3;
	void TV_Display(ObjectMaster* a1);
	void TV_Main(ObjectMaster* a1);
	void TV_Load(ObjectMaster* a1);
	void PlaceTV();
