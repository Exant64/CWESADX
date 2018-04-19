#pragma once
#include "stdafx.h"
#include "ninja.h"
#include "SADXModLoader.h"
#include "Flower1.h"

/* NINJA Basic (with Sonic Adventure DX additions) model
*
* Generated by SAMDL
*
*/



NJS_MATERIAL matlist_0014BA78[] = {
	{ { 0xFFFFFFFF },{ 0xFFFFFFFF }, 11, CHAOTexName_doramu_naka, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
{ { 0xFFFFFFFF },{ 0xFFFFFFFF }, 11, CHAOTexName_doramu_kawa, NJD_D_075 | NJD_FILTER_BILINEAR | NJD_FLAG_FLIP_V | NJD_FLAG_FLIP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 poly_0014BAA0[] = {
	0x8000u | 8, 4, 5, 0, 1, 2, 3, 4, 5,
	3, 0, 4, 2
};

Sint16 poly_0014BABA[] = {
	4, 13, 11, 12, 10,
	4, 15, 13, 14, 12,
	0x8000u | 11, 15, 13, 16, 11, 9, 10, 8, 12, 6, 14, 15,
	0x8000u | 5, 9, 8, 7, 6, 15,
	4, 15, 7, 16, 9
};

NJS_TEX uv_0014BAFC[] = {
	{ 231, 183 },
{ 231, 7 },
{ 247, 183 },
{ 245, 7 },
{ 231, 183 },
{ 231, 7 },
{ 231, 183 },
{ 231, 7 },
{ 247, 183 },
{ 231, 183 },
{ 231, 183 }
};

NJS_TEX uv_0014BB28[] = {
	{ -47, 187 },
{ 326, 302 },
{ -7, 159 },
{ 311, 257 },
{ 0, -187 },
{ 0, 187 },
{ 0, -159 },
{ 0, 159 },
{ -47, -187 },
{ -47, 187 },
{ 223, 2 },
{ 326, 302 },
{ 557, 0 },
{ 311, 257 },
{ 507, 0 },
{ -7, 159 },
{ 311, -257 },
{ -7, -159 },
{ -47, -187 },
{ 557, 0 },
{ 507, 0 },
{ 326, -302 },
{ 311, -257 },
{ -47, -187 },
{ -47, -187 },
{ 326, -302 },
{ 223, 2 },
{ 557, 0 }
};

NJS_MESHSET_SADX meshlist_0014BB98[] = {
	{ NJD_MESHSET_TRIMESH | 0, 2, poly_0014BAA0, NULL, NULL, NULL, uv_0014BAFC, NULL },
{ NJD_MESHSET_TRIMESH | 1, 5, poly_0014BABA, NULL, NULL, NULL, uv_0014BB28, NULL }
};

NJS_VECTOR vertex_0014BBC8[] = {
	{ 0.134074f, -0.386311f, 0 },
{ 0.110086f, 0.720426f, 0 },
{ -0.113566f, -0.386311f, -0.142975f },
{ -0.101572f, 0.720426f, -0.122201f },
{ -0.113566f, -0.386311f, 0.142975f },
{ -0.101572f, 0.720426f, 0.122201f },
{ 0.054339f, 0.690793f, 0.262705f },
{ 0.069362f, 1.118384f, 0.308941f },
{ 0.245205f, 0.690793f, 0 },
{ 0.29382f, 1.118384f, 0 },
{ 0.054339f, 0.690793f, -0.262705f },
{ 0.069362f, 1.118384f, -0.308941f },
{ -0.25449f, 0.690793f, -0.162361f },
{ -0.29382f, 1.118384f, -0.190936f },
{ -0.25449f, 0.690793f, 0.162361f },
{ -0.29382f, 1.118384f, 0.190936f },
{ -0.030798f, 1.248128f, -0.002161f }
};

NJS_VECTOR normal_0014BC94[] = {
	{ 0.837258f, -0.5468079f, 0 },
{ 0.999765f, 0.021669f, 0 },
{ -0.418629f, -0.5468079f, -0.725087f },
{ -0.499883f, 0.021669f, -0.865822f },
{ -0.418629f, -0.5468079f, 0.725087f },
{ -0.499882f, 0.021669f, 0.865822f },
{ 0.237988f, -0.637867f, 0.732453f },
{ 0.278329f, 0.433648f, 0.8570189f },
{ 0.770147f, -0.637867f, 0 },
{ 0.901457f, 0.432869f, 0.000315f },
{ 0.237988f, -0.637867f, -0.732453f },
{ 0.278731f, 0.432187f, -0.857627f },
{ -0.623062f, -0.637867f, -0.452681f },
{ -0.729576f, 0.432558f, -0.529728f },
{ -0.623062f, -0.637867f, 0.452681f },
{ -0.728927f, 0.433459f, 0.529885f },
{ 0.000299f, 0.9999959f, -0.002924f }
};

NJS_MODEL_SADX attach_0014BD60 = { vertex_0014BBC8, normal_0014BC94, LengthOfArray<Sint32>(vertex_0014BBC8), meshlist_0014BB98, matlist_0014BA78, LengthOfArray<Uint16>(meshlist_0014BB98), LengthOfArray<Uint16>(matlist_0014BA78),{ 0, 0.430909f, 0 }, 0.873666f, NULL };

NJS_OBJECT object_0014BD88 = { NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &attach_0014BD60, 0, 0, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };
