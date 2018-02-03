/* NINJA Basic (with Sonic Adventure DX additions) model
*
* Generated by SAMDL
*
*/
#include "stdafx.h"
#include "ninja.h"
#include "SADXModLoader.h"
#include "StarnutObject.h"

NJS_MATERIAL matlist_0017CA98[] = {
	{ { 0xFFB2B2B2 },{ 0xFFFFFFFF }, 11, CHAO_OBJECTTexName_alm_sgo04, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_FLIP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
{ { 0xFFB2B2B2 },{ 0xFFFFFFFF }, 11, CHAO_OBJECTTexName_alm_sgo03, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_FLIP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_ALPHA | NJD_FLAG_USE_TEXTURE | NJD_FLAG_DOUBLE_SIDE | NJD_DA_INV_SRC | NJD_SA_SRC },
{ { 0xFFB2B2B2 },{ 0xFFFFFFFF }, 11, CHAO_OBJECTTexName_alm_sgo01, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
{ { 0xFFB2B2B2 },{ 0xFFFFFFFF }, 11, CHAO_OBJECTTexName_alm_sgo02, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 poly_0017CAE8[] = {
	0x8000u | 6, 1, 2, 0, 3, 1, 2
};

Sint16 poly_0017CAF6[] = {
	4, 7, 5, 4, 6
};

Sint16 poly_0017CB00[] = {
	5, 10, 21, 8, 25, 13,
	0x8000u | 14, 30, 23, 32, 12, 19, 14, 17, 9, 24, 31, 13, 23, 26, 30,
	0x8000u | 9, 13, 26, 25, 29, 11, 20, 21, 16, 10,
	0x8000u | 5, 13, 8, 24, 10, 15,
	3, 11, 25, 21,
	6, 24, 17, 15, 19, 22, 32,
	5, 31, 23, 9, 12, 14,
	0x8000u | 7, 26, 30, 29, 27, 20, 28, 16
};

Sint16 poly_0017CB7C[] = {
	0x8000u | 6, 32, 22, 30, 18, 27, 28,
	6, 28, 16, 18, 10, 22, 15
};

NJS_TEX uv_0017CB98[] = {
	{ 321, 254 },
{ 255, 3 },
{ 510, 0 },
{ 0 },
{ 321, 254 },
{ 255, 3 }
};

NJS_TEX uv_0017CBB0[] = {
	{ 115, 251 },
{ 3, 155 },
{ 251, 155 },
{ 115, 3 }
};

NJS_TEX uv_0017CBC0[] = {
	{ 255, 254 },
{ 219, 100 },
{ 219, 254 },
{ 127, 100 },
{ 127, 254 },
{ 255, 254 },
{ 200, 173 },
{ 223, 167 },
{ 156, 90 },
{ 127, 76 },
{ 127, 0 },
{ 98, 90 },
{ 127, 97 },
{ 54, 173 },
{ 127, 175 },
{ 127, 255 },
{ 200, 173 },
{ 219, 254 },
{ 255, 254 },
{ 127, 254 },
{ 35, 254 },
{ 127, 100 },
{ 35, 100 },
{ 127, 41 },
{ 127, 0 },
{ 219, 100 },
{ 254, 101 },
{ 255, 254 },
{ 127, 255 },
{ 35, 254 },
{ 54, 173 },
{ 0, 254 },
{ 31, 167 },
{ 127, 41 },
{ 127, 100 },
{ 219, 100 },
{ 54, 173 },
{ 98, 90 },
{ 31, 167 },
{ 127, 76 },
{ 127, 167 },
{ 223, 167 },
{ 127, 175 },
{ 200, 173 },
{ 127, 97 },
{ 156, 90 },
{ 127, 0 },
{ 35, 254 },
{ 0, 254 },
{ 35, 100 },
{ 0, 101 },
{ 127, 0 },
{ 127, 100 },
{ 254, 101 }
};

NJS_TEX uv_0017CC98[] = {
	{ 223, 0 },
{ 127, 0 },
{ 255, 107 },
{ 127, 107 },
{ 254, 254 },
{ 127, 255 },
{ 127, 255 },
{ 0, 254 },
{ 127, 107 },
{ 0, 107 },
{ 127, 0 },
{ 31, 0 }
};

NJS_MESHSET_SADX meshlist_0017CCC8[] = {
	{ NJD_MESHSET_TRIMESH | 0, 1, poly_0017CAE8, NULL, NULL, NULL, uv_0017CB98, NULL },
{ NJD_MESHSET_TRIMESH | 1, 1, poly_0017CAF6, NULL, NULL, NULL, uv_0017CBB0, NULL },
{ NJD_MESHSET_TRIMESH | 2, 8, poly_0017CB00, NULL, NULL, NULL, uv_0017CBC0, NULL },
{ NJD_MESHSET_TRIMESH | 3, 2, poly_0017CB7C, NULL, NULL, NULL, uv_0017CC98, NULL }
};

NJS_VECTOR vertex_0017CD28[] = {
	{ -0.078526f, 2.76483f, 0.059203f },
{ 0.039832f, 1.711423f, -0.037587f },
{ -0.302576f, 2.728673f, -0.071826f },
{ -0.078526f, 2.76483f, -0.202855f },
{ 0.819315f, 2.334003f, -0.370914f },
{ 0.561813f, 2.692002f, 0.193163f },
{ 1.338574f, 2.322891f, 0.264133f },
{ -0.04592f, 1.966672f, -0.044873f },
{ -0.984529f, 0.407072f, 1.091323f },
{ -0.00006f, 1.46373f, 0.239424f },
{ -1.367984f, 0.410704f, -0.575305f },
{ -0.0009939999f, -0.695928f, 1.013665f },
{ 0.307896f, 1.509358f, -0.174045f },
{ -0.00001f, 0.405685f, 1.354237f },
{ -0.00008999999f, 2.121025f, -0.047774f },
{ -1.027584f, 0.9946049f, -0.449024f },
{ -1.366713f, -0.386208f, -0.572993f },
{ -0.307909f, 1.509358f, -0.174048f },
{ -0.00007f, 0.411352f, -1.31807f },
{ -0.0001f, 1.607029f, -0.605419f },
{ -0.00001f, -0.909013f, -0.045573f },
{ -0.98225f, -0.386459f, 1.136106f },
{ -0.00004f, 0.9963689f, -1.042593f },
{ 0.778361f, 0.954229f, 0.86859f },
{ -0.778367f, 0.954228f, 0.86859f },
{ -0.00001f, -0.390094f, 1.394774f },
{ 0.984529f, 0.407072f, 1.091323f },
{ 1.366709f, -0.386209f, -0.572991f },
{ -0.00006f, -0.389852f, -1.226019f },
{ 0.98225f, -0.386459f, 1.136107f },
{ 1.367978f, 0.410702f, -0.575304f },
{ -0.00003f, 0.940305f, 1.127061f },
{ 1.027519f, 0.9946949f, -0.448988f }
};

NJS_VECTOR normal_0017CEB4[] = {
	{ 0.338544f, 0.5786059f, 0.742026f },
{ 0.18194f, -0.982789f, 0.031995f },
{ -0.936685f, 0.349912f, -0.013495f },
{ 0.336034f, 0.55773f, -0.758959f },
{ -0.034108f, 0.8367029f, -0.546595f },
{ -0.07027999f, 0.8273979f, -0.557202f },
{ 0.429099f, 0.838361f, -0.336192f },
{ -0.492997f, 0.615023f, -0.6153859f },
{ -0.704069f, 0.230447f, 0.6716999f },
{ -0.00001f, 0.830803f, 0.556567f },
{ -0.8850549f, 0.245748f, -0.395331f },
{ -0.000412f, -0.919646f, 0.392748f },
{ 0.670011f, 0.740053f, 0.058373f },
{ 0.004755f, 0.228199f, 0.973603f },
{ -0.00003f, 0.978835f, 0.20465f },
{ -0.708931f, 0.6361319f, -0.304554f },
{ -0.791086f, -0.491498f, -0.36416f },
{ -0.67003f, 0.740036f, 0.058362f },
{ -0.00001f, 0.165402f, -0.986226f },
{ -0.00007f, 0.769478f, -0.6386729f },
{ 0.000014f, -0.997062f, -0.076603f },
{ -0.64342f, -0.465429f, 0.607772f },
{ 0.000002f, 0.501332f, -0.865255f },
{ 0.5567819f, 0.651653f, 0.5151139f },
{ -0.554117f, 0.6445079f, 0.526843f },
{ -0.000445f, -0.384434f, 0.923152f },
{ 0.70754f, 0.238749f, 0.665121f },
{ 0.790404f, -0.493532f, -0.362888f },
{ 0, -0.53611f, -0.844148f },
{ 0.642068f, -0.466332f, 0.6085089f },
{ 0.885712f, 0.244134f, -0.394858f },
{ 0.006344f, 0.63665f, 0.771127f },
{ 0.708918f, 0.636157f, -0.304532f }
};

NJS_MODEL_SADX attach_0017D040 = { vertex_0017CD28, normal_0017CEB4, LengthOfArray<Sint32>(vertex_0017CD28), meshlist_0017CCC8, matlist_0017CA98, LengthOfArray<Uint16>(meshlist_0017CCC8), LengthOfArray<Uint16>(matlist_0017CA98),{ -0.00003f, 0.9279079f, 0.038352f }, 3.996045f, NULL };

NJS_OBJECT object_0017D068 = { NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_BREAK, &attach_0017D040, 0, 0, 0, 0, 0, 0, 1.75f, 1.75f, 1.75f, NULL, NULL };
