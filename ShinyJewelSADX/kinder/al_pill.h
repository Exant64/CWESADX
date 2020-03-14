/* NINJA Basic (with Sonic Adventure DX additions) model
 *
 * Generated by SAMDL
 *
 */

NJS_MATERIAL matlist_8D7C80F17694AC73CF6[] = {
	{ { 0xFFFFFFFF }, { 0x00FFFFFF }, 0, 51, NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFFFFFFF }, { 0x00FFFFFF }, 0, 51, NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 poly_8D7C80F176A348925A7[] = {
	12, 10, 7, 11, 22, 23, 20, 21, 2, 15, 14, 16, 8,
	3, 22, 19, 20,
	0x8000u | 11, 7, 22, 24, 19, 18, 19, 4, 19, 0, 20, 2,
	13, 16, 8, 10, 8, 7, 9, 24, 17, 18, 6, 4, 3, 0,
	0x8000u | 15, 3, 0, 1, 2, 1, 14, 12, 8, 12, 9, 13, 17, 13, 6, 5,
	8, 6, 5, 3, 5, 1, 5, 12, 13
};

Sint16 poly_8D7C80F176C080E3324[] = {
	12, 28, 25, 29, 43, 45, 44, 46, 36, 37, 32, 48, 26,
	3, 44, 43, 40,
	0x8000u | 11, 25, 43, 41, 40, 42, 40, 39, 40, 38, 44, 36,
	13, 48, 26, 28, 26, 25, 27, 41, 47, 42, 35, 39, 34, 38,
	0x8000u | 15, 34, 38, 30, 36, 30, 32, 31, 26, 31, 27, 49, 47, 49, 35, 33,
	8, 35, 33, 34, 33, 30, 33, 31, 49
};

NJS_MESHSET_SADX meshlist_8D7C80F17694AC7F452[] = {
	{ NJD_MESHSET_TRIMESH | 0, 6, poly_8D7C80F176A348925A7, NULL, NULL, NULL, NULL, NULL },
	{ NJD_MESHSET_TRIMESH | 1, 6, poly_8D7C80F176C080E3324, NULL, NULL, NULL, NULL, NULL }
};

NJS_VECTOR vertex_8D7C80F17694AC79FFB[] = {
	{ 1, -0.433013f, 0 },
	{ 1, -0.216506f, 0.375f },
	{ 0.75f, -0.5f, 0 },
	{ 1.183013f, -0.125f, 0.216506f },
	{ 1.183013f, -0.25f, 0 },
	{ 1.183013f, 0.125f, 0.216506f },
	{ 1.25f, 0, 0 },
	{ 0.75f, 0.5f, 0 },
	{ 0.75f, 0.25f, 0.433013f },
	{ 1, 0.433013f, 0 },
	{ 0, 0.25f, 0.433013f },
	{ 0, 0.5f, 0 },
	{ 1, 0.216507f, 0.375f },
	{ 1.183013f, 0.25f, 0 },
	{ 0.75f, -0.25f, 0.433013f },
	{ 0, -0.5f, 0 },
	{ 0, -0.25f, 0.433013f },
	{ 1.183013f, 0.125f, -0.216506f },
	{ 1.183013f, -0.125f, -0.216506f },
	{ 1, -0.216506f, -0.375f },
	{ 0.75f, -0.25f, -0.433013f },
	{ 0, -0.25f, -0.433013f },
	{ 0.75f, 0.25f, -0.433013f },
	{ 0, 0.25f, -0.433013f },
	{ 1, 0.216506f, -0.375f },
	{ -0.75f, -0.25f, 0.433013f },
	{ -0.75f, 0.25f, 0.433013f },
	{ -1, -0.216506f, 0.375f },
	{ 0, 0.25f, 0.433013f },
	{ 0, -0.25f, 0.433013f },
	{ -1, 0.433013f, 0 },
	{ -1, 0.216506f, 0.375f },
	{ -0.75f, 0.5f, 0 },
	{ -1.183013f, 0.125f, 0.216506f },
	{ -1.183013f, 0.25f, 0 },
	{ -1.25f, 0, 0 },
	{ -0.75f, 0.25f, -0.433013f },
	{ 0, 0.25f, -0.433013f },
	{ -1, 0.216506f, -0.375f },
	{ -1.183013f, 0.125f, -0.216506f },
	{ -1, -0.216506f, -0.375f },
	{ -1, -0.433013f, 0 },
	{ -1.183013f, -0.125f, -0.216506f },
	{ -0.75f, -0.5f, 0 },
	{ -0.75f, -0.25f, -0.433013f },
	{ 0, -0.5f, 0 },
	{ 0, -0.25f, -0.433013f },
	{ -1.183013f, -0.25f, 0 },
	{ 0, 0.5f, 0 },
	{ -1.183013f, -0.125f, 0.216506f }
};

NJS_VECTOR normal_8D7C80F17694AC7FBEF[] = {
	{ 0.46711f, -0.884199f, 0 },
	{ 0.46711f, -0.4421f, 0.765739f },
	{ 0.125451f, -0.9921f, 0 },
	{ 0.829477f, -0.279271f, 0.483711f },
	{ 0.829477f, -0.558541f, 0 },
	{ 0.829477f, 0.279271f, 0.483711f },
	{ 1, 0, 0 },
	{ 0.125451f, 0.9921f, 0 },
	{ 0.125451f, 0.49605f, 0.859184f },
	{ 0.46711f, 0.884199f, 0 },
	{ 0, 0.5f, 0.866025f },
	{ 0, 1, 0 },
	{ 0.46711f, 0.4421f, 0.765739f },
	{ 0.829477f, 0.558541f, 0 },
	{ 0.125451f, -0.49605f, 0.859184f },
	{ 0, -1, 0 },
	{ 0, -0.5f, 0.866025f },
	{ 0.829477f, 0.279271f, -0.483711f },
	{ 0.829477f, -0.279271f, -0.483711f },
	{ 0.46711f, -0.4421f, -0.765739f },
	{ 0.125451f, -0.49605f, -0.859184f },
	{ 0, -0.5f, -0.866025f },
	{ 0.12545f, 0.49605f, -0.859184f },
	{ 0, 0.5f, -0.866025f },
	{ 0.46711f, 0.4421f, -0.765739f },
	{ -0.125451f, -0.49605f, 0.859184f },
	{ -0.125451f, 0.49605f, 0.859184f },
	{ -0.46711f, -0.4421f, 0.765739f },
	{ 0, 0.5f, 0.866025f },
	{ 0, -0.5f, 0.866025f },
	{ -0.46711f, 0.884199f, 0 },
	{ -0.46711f, 0.4421f, 0.765739f },
	{ -0.125451f, 0.9921f, 0 },
	{ -0.829477f, 0.279271f, 0.483711f },
	{ -0.829477f, 0.558541f, 0 },
	{ -1, 0, 0 },
	{ -0.125451f, 0.49605f, -0.859184f },
	{ 0, 0.5f, -0.866025f },
	{ -0.46711f, 0.4421f, -0.765739f },
	{ -0.829477f, 0.279271f, -0.483711f },
	{ -0.46711f, -0.4421f, -0.765739f },
	{ -0.46711f, -0.884199f, 0 },
	{ -0.829477f, -0.279271f, -0.483711f },
	{ -0.125451f, -0.9921f, 0 },
	{ -0.125451f, -0.49605f, -0.859184f },
	{ 0, -1, 0 },
	{ 0, -0.5f, -0.866025f },
	{ -0.829477f, -0.558541f, 0 },
	{ 0, 1, 0 },
	{ -0.829477f, -0.27927f, 0.483711f }
};

NJS_MODEL_SADX attach_8D7C80A4F5244CE994C = { vertex_8D7C80F17694AC79FFB, normal_8D7C80F17694AC7FBEF, LengthOfArray<Sint32>(vertex_8D7C80F17694AC79FFB), meshlist_8D7C80F17694AC7F452, matlist_8D7C80F17694AC73CF6, LengthOfArray<Uint16>(meshlist_8D7C80F17694AC7F452), LengthOfArray<Uint16>(matlist_8D7C80F17694AC73CF6), { 0 }, 0, NULL };

NJS_OBJECT object_00E00D18 = { NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &attach_8D7C80A4F5244CE994C, 0, 0, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };