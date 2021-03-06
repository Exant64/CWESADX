#pragma once
NJS_MKEY_F motionTableAnimation_1_pos[] = {
	{ 0, 0, 0.020188f, 0.995777f },
	{ 4, 0, -0.215546f, 1.02692f },
	{ 13, 0, -0.00001f, 0.998444f }
};

NJS_MKEY_SA motionTableAnimation_3_rot[] = {
	{ 0, 325, 65462, 95 },
	{ 4, 51484, 63497, 62087 },
	{ 13, 154, 0, 103 }
};

NJS_MKEY_F motionTableAnimation_4_pos[] = {
	{ 0, -0.095019f, -1.09774f, 0.050228f },
	{ 4, -0.289315f, -1.14007f, 0.0739699f }
};

NJS_MKEY_SA motionTableAnimation_4_rot[] = {
	{ 0, 972, 409, 61408 },
	{ 4, 48036, 1239, 2237 },
	{ 5, 64024, 1426, 2401 }
};

NJS_MKEY_F motionTableAnimation_6_pos[] = {
	{ 0, 0, -0.000692f, 0 },
	{ 13, 0, -0.000692f, 0 }
};

NJS_MKEY_SA motionTableAnimation_6_rot[] = {
	{ 0, 0, 0, 0 },
	{ 4, 54401, 0, 0 },
	{ 13, 0, 0, 0 }
};

NJS_MKEY_SA motionTableAnimation_8_rot[] = {
	{ 13, 62721, 0, 0 }
};

NJS_MKEY_SA motionTableAnimation_10_rot[] = {
	{ 0, 65124, 67, 87 },
	{ 4, 16952, 2298, 61008 },
	{ 13, 65280, 0, 81 }
};

NJS_MKEY_F motionTableAnimation_13_pos[] = {
	{ 13, 0, 0.000692f, 0 }
};

NJS_MKEY_SA motionTableAnimation_13_rot[] = {
	{ 0, 498, 0, 0 },
	{ 4, 11205, 0, 0 },
	{ 13, 0, 0, 0 }
};

NJS_MKEY_SA motionTableAnimation_15_rot[] = {
	{ 13, 0, 0, 0 }
};

NJS_MKEY_SA motionTableAnimation_16_rot[] = {
	{ 0, 64898, 0, 0 },
	{ 4, 62361, 0, 0 }
};

NJS_MKEY_F motionTableAnimation_33_pos[] = {
	{ 13, 0, 0.000744f, 0.032633f }
};

NJS_MKEY_SA motionTableAnimation_37_rot[] = {
	{ 13, 0, 69, 0 }
};

NJS_MKEY_SA motionTableAnimation_39_rot[] = {
	{ 13, 0, 0, 0 }
};

NJS_MDATA2 motionTableAnimation_mdat[] = {
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, NULL, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, motionTableAnimation_3_rot, 0, LengthOfArray<Uint32>(motionTableAnimation_3_rot) },
	{ motionTableAnimation_4_pos, motionTableAnimation_4_rot, LengthOfArray<Uint32>(motionTableAnimation_4_pos), LengthOfArray<Uint32>(motionTableAnimation_4_rot) },
	{ NULL, NULL, 0, 0 },
	{ motionTableAnimation_6_pos, motionTableAnimation_6_rot, LengthOfArray<Uint32>(motionTableAnimation_6_pos), LengthOfArray<Uint32>(motionTableAnimation_6_rot) },
	{ NULL, NULL, 0, 0 },
	{ NULL, motionTableAnimation_8_rot, 0, LengthOfArray<Uint32>(motionTableAnimation_8_rot) },
	{ NULL, NULL, 0, 0 },
	{ NULL, motionTableAnimation_10_rot, 0, LengthOfArray<Uint32>(motionTableAnimation_10_rot) },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, motionTableAnimation_13_rot, NULL, LengthOfArray<Uint32>(motionTableAnimation_13_rot) },
	{ NULL, NULL, 0, 0 },
	{ NULL, motionTableAnimation_15_rot, 0, LengthOfArray<Uint32>(motionTableAnimation_15_rot) },
	{ NULL, motionTableAnimation_16_rot, 0, LengthOfArray<Uint32>(motionTableAnimation_16_rot) },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
	{ NULL, NULL, 0, 0 },
};

NJS_MOTION motionTableAnimation = { motionTableAnimation_mdat, 5, NJD_MTYPE_POS_0 | NJD_MTYPE_ANG_1, 2 };
