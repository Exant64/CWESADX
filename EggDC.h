#pragma once
#include "stdafx.h"
#include "ninja.h"
#include "SADXModLoader.h"
#include "Flower1.h"

#pragma region EggModel




NJS_MATERIAL matlist_0014776C[] = {
	{ { 0xFFB2B2B2 },{ 0xFFFFFFFF }, 11, CHAOTexName_cr_egg, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_ALPHA | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 poly_00147780[] = {
	0x8000u | 6, 4, 8, 3, 7, 2, 0,
	9, 5, 9, 10, 14, 15, 19, 20, 24, 25,
	4, 8, 7, 12, 0,
	0x8000u | 24, 13, 8, 9, 4, 5, 40, 41, 36, 1, 31, 26, 30, 25, 29, 24, 28, 23, 27, 22, 0, 17, 12, 13, 8,
	7, 9, 13, 14, 18, 19, 23, 24,
	0x8000u | 5, 16, 11, 1, 6, 41,
	0x8000u | 5, 23, 22, 18, 17, 13,
	4, 26, 1, 21, 16,
	11, 36, 31, 35, 30, 34, 29, 33, 28, 32, 27, 0,
	0x8000u | 10, 36, 40, 35, 39, 34, 38, 33, 37, 32, 0,
	0x8000u | 8, 40, 4, 39, 3, 38, 2, 37, 0,
	11, 41, 5, 6, 10, 11, 15, 16, 20, 21, 25, 26
};

NJS_TEX uv_00147868[] = {
	{ 255, 137 },
{ 210, 192 },
{ 245, 192 },
{ 184, 236 },
{ 208, 236 },
{ 127, 255 },
{ 234, 67 },
{ 217, 137 },
{ 203, 67 },
{ 127, 137 },
{ 127, 67 },
{ 37, 137 },
{ 51, 67 },
{ 0, 137 },
{ 20, 67 },
{ 210, 192 },
{ 184, 236 },
{ 127, 236 },
{ 127, 255 },
{ 127, 192 },
{ 210, 192 },
{ 217, 137 },
{ 255, 137 },
{ 234, 67 },
{ 203, 67 },
{ 178, 20 },
{ 127, 20 },
{ 127, 0 },
{ 76, 20 },
{ 55, 20 },
{ 51, 67 },
{ 20, 67 },
{ 37, 137 },
{ 0, 137 },
{ 44, 192 },
{ 9, 192 },
{ 70, 236 },
{ 46, 236 },
{ 127, 255 },
{ 70, 236 },
{ 127, 236 },
{ 127, 192 },
{ 210, 192 },
{ 217, 137 },
{ 127, 192 },
{ 127, 137 },
{ 44, 192 },
{ 37, 137 },
{ 9, 192 },
{ 0, 137 },
{ 127, 20 },
{ 178, 20 },
{ 127, 0 },
{ 199, 20 },
{ 178, 20 },
{ 9, 192 },
{ 46, 236 },
{ 44, 192 },
{ 70, 236 },
{ 127, 192 },
{ 55, 20 },
{ 127, 0 },
{ 76, 20 },
{ 127, 20 },
{ 127, 20 },
{ 76, 20 },
{ 127, 67 },
{ 51, 67 },
{ 127, 137 },
{ 37, 137 },
{ 127, 192 },
{ 44, 192 },
{ 127, 236 },
{ 70, 236 },
{ 127, 255 },
{ 127, 20 },
{ 203, 67 },
{ 127, 67 },
{ 217, 137 },
{ 127, 137 },
{ 210, 192 },
{ 127, 192 },
{ 184, 236 },
{ 127, 236 },
{ 127, 255 },
{ 203, 67 },
{ 255, 137 },
{ 217, 137 },
{ 245, 192 },
{ 210, 192 },
{ 208, 236 },
{ 184, 236 },
{ 127, 255 },
{ 178, 20 },
{ 234, 67 },
{ 199, 20 },
{ 203, 67 },
{ 178, 20 },
{ 127, 67 },
{ 127, 20 },
{ 51, 67 },
{ 76, 20 },
{ 20, 67 },
{ 55, 20 }
};

NJS_MESHSET_SADX meshlist_00147A08[] = {
	{ NJD_MESHSET_TRIMESH | 0, 12, poly_00147780, NULL, NULL, NULL, uv_00147868, NULL }
};

NJS_VECTOR vertex_00147A20[] = {
	{ 0, -0.062524f, 0 },
{ 0, 5.532808f, 0 },
{ 1.531448f, 0.339411f, 0 },
{ 2.225787f, 1.301642f, 0 },
{ 2.410984f, 2.506843f, 0 },
{ 2.021251f, 4.061417f, 0 },
{ 1.361181f, 5.077713f, 0 },
{ 1.082897f, 0.339411f, -1.099346f },
{ 1.573869f, 1.301642f, -1.597776f },
{ 1.704823f, 2.506843f, -1.730719f },
{ 1.42924f, 4.061417f, -1.45095f },
{ 0.9625f, 5.077713f, -0.977121f },
{ 0, 0.339411f, -1.55471f },
{ 0, 1.301642f, -2.259596f },
{ 0, 2.506843f, -2.447606f },
{ 0, 4.061417f, -2.051953f },
{ 0, 5.077713f, -1.381857f },
{ -1.082897f, 0.339411f, -1.099346f },
{ -1.573869f, 1.301642f, -1.597776f },
{ -1.704823f, 2.506843f, -1.730719f },
{ -1.42924f, 4.061417f, -1.45095f },
{ -0.9625f, 5.077713f, -0.977121f },
{ -1.531448f, 0.339411f, 0 },
{ -2.225787f, 1.301642f, 0 },
{ -2.410984f, 2.506843f, 0 },
{ -2.021251f, 4.061417f, 0 },
{ -1.361181f, 5.077713f, 0 },
{ -1.082897f, 0.339411f, 1.099346f },
{ -1.573869f, 1.301642f, 1.597776f },
{ -1.704823f, 2.506843f, 1.730719f },
{ -1.42924f, 4.061417f, 1.45095f },
{ -0.9625f, 5.077713f, 0.977121f },
{ 0, 0.339411f, 1.55471f },
{ 0, 1.301642f, 2.259596f },
{ 0, 2.506843f, 2.447606f },
{ 0, 4.061417f, 2.051953f },
{ 0, 5.077713f, 1.381857f },
{ 1.082897f, 0.339411f, 1.099346f },
{ 1.573869f, 1.301642f, 1.597776f },
{ 1.704823f, 2.506843f, 1.730719f },
{ 1.42924f, 4.061417f, 1.45095f },
{ 0.9625f, 5.077713f, 0.977121f }
};

NJS_VECTOR normal_00147C18[] = {
	{ 0, -1, 0 },
{ 0, 1, 0 },
{ 0.616806f, -0.787115f, 0 },
{ 0.932728f, -0.36058f, 0 },
{ 0.99901f, 0.044498f, 0 },
{ 0.922696f, 0.385528f, 0 },
{ 0.657798f, 0.753194f, 0 },
{ 0.43805f, -0.788297f, -0.432089f },
{ 0.662344f, -0.362354f, -0.655745f },
{ 0.709747f, 0.044767f, -0.703033f },
{ 0.655221f, 0.387611f, -0.648416f },
{ 0.467067f, 0.754545f, -0.460987f },
{ 0, -0.789485f, -0.6137699f },
{ 0, -0.36413f, -0.931348f },
{ 0, 0.045038f, -0.998985f },
{ 0, 0.389706f, -0.920939f },
{ 0, 0.755902f, -0.654685f },
{ -0.43805f, -0.788297f, -0.432089f },
{ -0.662344f, -0.362354f, -0.655745f },
{ -0.709747f, 0.044767f, -0.703033f },
{ -0.655221f, 0.387611f, -0.648416f },
{ -0.467067f, 0.754545f, -0.460987f },
{ -0.616806f, -0.787115f, 0 },
{ -0.932728f, -0.36058f, 0 },
{ -0.99901f, 0.044498f, 0 },
{ -0.922696f, 0.385528f, 0 },
{ -0.657798f, 0.753194f, 0 },
{ -0.43805f, -0.788297f, 0.432089f },
{ -0.662344f, -0.362354f, 0.655745f },
{ -0.709747f, 0.044767f, 0.703033f },
{ -0.655221f, 0.387611f, 0.648416f },
{ -0.467067f, 0.754545f, 0.460987f },
{ 0, -0.789485f, 0.6137699f },
{ 0, -0.36413f, 0.931348f },
{ 0, 0.045038f, 0.998985f },
{ 0, 0.389706f, 0.920939f },
{ 0, 0.755902f, 0.654685f },
{ 0.43805f, -0.788297f, 0.432089f },
{ 0.662344f, -0.362354f, 0.655745f },
{ 0.709747f, 0.044767f, 0.703033f },
{ 0.655221f, 0.387611f, 0.648416f },
{ 0.467067f, 0.754545f, 0.460987f }
};

NJS_MODEL_SADX attach_00147E10 = { vertex_00147A20, normal_00147C18, LengthOfArray<Sint32>(vertex_00147A20), meshlist_00147A08, matlist_0014776C, LengthOfArray<Uint16>(meshlist_00147A08), LengthOfArray<Uint16>(matlist_0014776C),{ 0, 2.735142f, 0 }, 3.717218f, NULL };

NJS_OBJECT object_00147E38 = { NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &attach_00147E10, 0, 0, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };

#pragma endregion