#pragma once
/* NINJA Basic (with Sonic Adventure DX additions) model
*
* Generated by SAMDL
*
*/
#include "stdafx.h"
#include "ninja.h"
#include "SADXModLoader.h"

enum CHAOTexName
{
	CHAOTexName_beem,
	CHAOTexName_doramu_kawa,
	CHAOTexName_yari,
	CHAOTexName_eda_happa,
	CHAOTexName_jouro0,
	CHAOTexName_rappa_gold,
	CHAOTexName_sukoppu_totte,
	CHAOTexName_doramu_naka,
	CHAOTexName_rappa_hata,
	CHAOTexName_jouro1,
	CHAOTexName_sukoppu_ue,
	CHAOTexName_yari_bou,
	CHAOTexName_jouro2,
	CHAOTexName_yari_wakka,
	CHAOTexName_jouro_kuti,
	CHAOTexName_jouro_top,
	CHAOTexName_alp_pen04,
	CHAOTexName_alp_pen01,
	CHAOTexName_alp_pen02,
	CHAOTexName_alp_pen03,
	CHAOTexName_alp_gp01,
	CHAOTexName_alp_az01,
	CHAOTexName_alp_az02,
	CHAOTexName_alp_tu03,
	CHAOTexName_alp_tu02,
	CHAOTexName_alp_tu01,
	CHAOTexName_alp_tu04,
	CHAOTexName_alp_om05,
	CHAOTexName_alp_om02,
	CHAOTexName_alp_om03,
	CHAOTexName_alp_om04,
	CHAOTexName_alp_om01,
	CHAOTexName_alp_pen05,
	CHAOTexName_alp_om06,
	CHAOTexName_alp_om07,
	CHAOTexName_alp_usa04,
	CHAOTexName_alp_usa02,
	CHAOTexName_alp_usa03,
	CHAOTexName_alp_usa01,
	CHAOTexName_alp_usa05,
	CHAOTexName_alp_wb08,
	CHAOTexName_alp_wb02,
	CHAOTexName_alp_wb03,
	CHAOTexName_alp_wb04,
	CHAOTexName_alp_wb05,
	CHAOTexName_alp_wb06,
	CHAOTexName_alp_wb07,
	CHAOTexName_alp_wb01,
	CHAOTexName_alp_bb04,
	CHAOTexName_alp_bb02,
	CHAOTexName_alp_bb03,
	CHAOTexName_alp_bb01,
	CHAOTexName_alp_bb05,
	CHAOTexName_alp_mo03,
	CHAOTexName_alp_mo02,
	CHAOTexName_alp_mo01,
	CHAOTexName_alp_mo04,
	CHAOTexName_alp_mo05,
	CHAOTexName_alp_zo06,
	CHAOTexName_alp_zo02,
	CHAOTexName_alp_zo03,
	CHAOTexName_alp_zo04,
	CHAOTexName_alp_zo05,
	CHAOTexName_alp_zo01,
	CHAOTexName_alp_zo07,
	CHAOTexName_alp_kal05,
	CHAOTexName_alp_kal02,
	CHAOTexName_alp_kal03,
	CHAOTexName_alp_kal04,
	CHAOTexName_alp_kal01,
	CHAOTexName_alp_kal06,
	CHAOTexName_alp_kal07,
	CHAOTexName_alp_kj06,
	CHAOTexName_alp_leo07,
	CHAOTexName_alp_leo02,
	CHAOTexName_alp_leo03,
	CHAOTexName_alp_leo04,
	CHAOTexName_alp_leo05,
	CHAOTexName_alp_kj03,
	CHAOTexName_alp_leo06,
	CHAOTexName_alp_kj04,
	CHAOTexName_alp_leo01,
	CHAOTexName_alp_leo08,
	CHAOTexName_alp_leo09,
	CHAOTexName_alp_leo10,
	CHAOTexName_alp_gori04,
	CHAOTexName_alp_gori02,
	CHAOTexName_alp_gori03,
	CHAOTexName_alp_gori01,
	CHAOTexName_alp_gori05,
	CHAOTexName_alp_gori06,
	CHAOTexName_alp_sk08,
	CHAOTexName_alp_sk02,
	CHAOTexName_alp_sk03,
	CHAOTexName_alp_sk04,
	CHAOTexName_alp_sk05,
	CHAOTexName_alp_sk06,
	CHAOTexName_alp_sk07,
	CHAOTexName_alp_sk01,
	CHAOTexName_alp_sk09,
	CHAOTexName_alp_rk06,
	CHAOTexName_alp_rk02,
	CHAOTexName_alp_rk03,
	CHAOTexName_alp_rk04,
	CHAOTexName_alp_rk05,
	CHAOTexName_alp_rk01,
	CHAOTexName_alp_rk07,
	CHAOTexName_alp_rk08,
	CHAOTexName_alp_gaz02,
	CHAOTexName_alp_gaz01,
	CHAOTexName_alp_gtu02,
	CHAOTexName_alp_gtu01,
	CHAOTexName_alp_gom04,
	CHAOTexName_alp_gom03,
	CHAOTexName_alp_gom02,
	CHAOTexName_alp_gusa02,
	CHAOTexName_alp_gusa01,
	CHAOTexName_alp_gwb02,
	CHAOTexName_alp_gwb03,
	CHAOTexName_alp_gwb04,
	CHAOTexName_alp_gwb01,
	CHAOTexName_alp_gbb02,
	CHAOTexName_alp_gbb01,
	CHAOTexName_alp_gbb03,
	CHAOTexName_alp_gmo02,
	CHAOTexName_alp_gmo01,
	CHAOTexName_alp_gmo03,
	CHAOTexName_alp_gmo04,
	CHAOTexName_alp_gzo02,
	CHAOTexName_alp_gzo03,
	CHAOTexName_alp_gzo04,
	CHAOTexName_alp_gzo01,
	CHAOTexName_alp_gkl02,
	CHAOTexName_alp_gkl03,
	CHAOTexName_alp_gkl04,
	CHAOTexName_alp_gkl01,
	CHAOTexName_alp_gle02,
	CHAOTexName_alp_gle03,
	CHAOTexName_alp_gle04,
	CHAOTexName_alp_gle05,
	CHAOTexName_alp_gle01,
	CHAOTexName_alp_ggr01,
	CHAOTexName_alp_gsk04,
	CHAOTexName_alp_gsk02,
	CHAOTexName_alp_gsk03,
	CHAOTexName_alp_gsk01,
	CHAOTexName_alp_grk02,
	CHAOTexName_alp_grk03,
	CHAOTexName_alp_grk01,
	CHAOTexName_alp_kj01,
	CHAOTexName_alp_kj02,
	CHAOTexName_alp_gkj01,
	CHAOTexName_alp_gkji02,
	CHAOTexName_alp_kj05,
	CHAOTexName_alp_gkji03,
	CHAOTexName_cr_egg,
	CHAOTexName_cr_ware2,
	CHAOTexName_cg_gold,
	CHAOTexName_chao_gold,
	CHAOTexName_cg_begg,
	CHAOTexName_cr_ware1,
	CHAOTexName_pal,
	CHAOTexName_hana2_hanaw,
	CHAOTexName_hana2_happa,
	CHAOTexName_al_eye00,
	CHAOTexName_al_eye01,
	CHAOTexName_al_eye02,
	CHAOTexName_al_eye03,
	CHAOTexName_al_eye04,
	CHAOTexName_al_eye05,
	CHAOTexName_al_eye06,
	CHAOTexName_al_eye07,
	CHAOTexName_al_eye08,
	CHAOTexName_al_eye09,
	CHAOTexName_al_kuchi00,
	CHAOTexName_al_kuchi01,
	CHAOTexName_al_kuchi02,
	CHAOTexName_al_kuchi03,
	CHAOTexName_al_kuchi04,
	CHAOTexName_al_kuchi05,
	CHAOTexName_al_kuchi06,
	CHAOTexName_al_kuchi07,
	CHAOTexName_al_kuchi08,
	CHAOTexName_al_hane00,
	CHAOTexName_al00,
	CHAOTexName_al01,
	CHAOTexName_al02,
	CHAOTexName_al03,
	CHAOTexName_al04,
	CHAOTexName_al05,
	CHAOTexName_al06,
	CHAOTexName_al07,
	CHAOTexName_al08,
	CHAOTexName_al09,
	CHAOTexName_al10,
	CHAOTexName_al_11,
	CHAOTexName_al_12,
	CHAOTexName_al_13,
	CHAOTexName_al_14,
	CHAOTexName_al16,
	CHAOTexName_al17,
	CHAOTexName_al18,
	CHAOTexName_al19,
	CHAOTexName_al20,
	CHAOTexName_al21,
	CHAOTexName_al23,
	CHAOTexName_al24,
	CHAOTexName_al25,
	CHAOTexName_al26,
	CHAOTexName_al_iconc01,
	CHAOTexName_sukebo_taiya,
	CHAOTexName_sukebo_ue,
	CHAOTexName_boru,
	CHAOTexName_hana,
	CHAOTexName_hana_kuki,
	CHAOTexName_hana_kusa,
	CHAOTexName_hana2_hana,
	CHAOTexName_ame,
	CHAOTexName_eme,
	CHAOTexName_rub,
	CHAOTexName_saf
};

NJS_MATERIAL matlist_00154250[] = {
	{ { 0xFFFFFFFF },{ 0xFFFFFFFF }, 11, CHAOTexName_hana2_happa, NJD_D_075 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_ALPHA | NJD_FLAG_USE_TEXTURE | NJD_FLAG_DOUBLE_SIDE | NJD_DA_INV_SRC | NJD_SA_SRC },
{ { 0xFFFFFFFF },{ 0xFFFFFFFF }, 11, CHAOTexName_hana2_hana, NJD_D_075 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_ALPHA | NJD_FLAG_USE_TEXTURE | NJD_FLAG_DOUBLE_SIDE | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 poly_00154278[] = {
	8, 0, 1, 2, 3, 4, 5, 6, 7,
	6, 20, 17, 21, 18, 22, 19,
	6, 26, 23, 27, 24, 28, 25,
	6, 29, 32, 30, 33, 31, 34,
	6, 35, 38, 36, 39, 37, 40,
	6, 43, 46, 42, 45, 41, 44,
	6, 50, 47, 51, 48, 52, 49,
	6, 54, 53, 56, 55, 58, 57,
	6, 71, 68, 72, 69, 73, 70,
	6, 77, 74, 78, 75, 79, 76
};

Sint16 poly_00154308[] = {
	3, 11, 8, 9,
	4, 12, 13, 15, 16,
	0x8000u | 7, 14, 15, 11, 12, 9, 13, 10,
	3, 62, 59, 60,
	4, 63, 64, 66, 67,
	0x8000u | 7, 65, 66, 62, 63, 60, 64, 61
};

NJS_TEX uv_0015434C[] = {
	{ 207, 95 },
{ 159, 95 },
{ 207, 102 },
{ 159, 102 },
{ 207, 109 },
{ 159, 109 },
{ 207, 111 },
{ 159, 111 },
{ 0, 7 },
{ 0, 255 },
{ 123, 7 },
{ 123, 255 },
{ 247, 7 },
{ 247, 255 },
{ 0, 7 },
{ 0, 255 },
{ 123, 7 },
{ 128, 255 },
{ 247, 7 },
{ 247, 255 },
{ 0, 255 },
{ 0, 7 },
{ 128, 255 },
{ 123, 7 },
{ 247, 255 },
{ 247, 7 },
{ 0, 255 },
{ 0, 7 },
{ 128, 255 },
{ 123, 7 },
{ 247, 255 },
{ 247, 7 },
{ 247, 255 },
{ 247, 7 },
{ 128, 255 },
{ 123, 7 },
{ 0, 255 },
{ 0, 7 },
{ 0, 7 },
{ 0, 255 },
{ 123, 7 },
{ 128, 255 },
{ 247, 7 },
{ 247, 255 },
{ 207, 103 },
{ 143, 103 },
{ 207, 109 },
{ 143, 109 },
{ 207, 111 },
{ 143, 111 },
{ 0, 7 },
{ 0, 255 },
{ 123, 7 },
{ 128, 255 },
{ 247, 7 },
{ 247, 255 },
{ 0, 7 },
{ 0, 255 },
{ 123, 7 },
{ 128, 255 },
{ 247, 7 },
{ 247, 255 }
};

NJS_TEX uv_00154444[] = {
	{ 125, 255 },
{ 0, 255 },
{ 0, 129 },
{ 125, 129 },
{ 125, 3 },
{ 251, 129 },
{ 251, 3 },
{ 251, 255 },
{ 251, 129 },
{ 125, 255 },
{ 125, 129 },
{ 0, 129 },
{ 125, 3 },
{ 0, 3 },
{ 125, 255 },
{ 0, 255 },
{ 0, 129 },
{ 125, 129 },
{ 125, 3 },
{ 251, 129 },
{ 251, 3 },
{ 251, 255 },
{ 251, 129 },
{ 125, 255 },
{ 125, 129 },
{ 0, 129 },
{ 125, 3 },
{ 0, 3 }
};

NJS_MESHSET_SADX meshlist_001544B4[] = {
	{ NJD_MESHSET_TRIMESH | 0, 10, poly_00154278, NULL, NULL, NULL, uv_0015434C, NULL },
{ NJD_MESHSET_TRIMESH | 1, 6, poly_00154308, NULL, NULL, NULL, uv_00154444, NULL }
};

NJS_VECTOR vertex_001544E4[] = {
	{ 0.014075f, 0, 0.043515f },
{ -0.01575f, 0, -0.069817f },
{ 0.014075f, 0.941984f, -0.08922499f },
{ -0.01575f, 0.941984f, -0.202557f },
{ 0.014075f, 1.808964f, 0.07414699f },
{ -0.01575f, 1.808964f, -0.039185f },
{ 0.07925899f, 2.089665f, 0.187819f },
{ 0.006516f, 2.089665f, -0.08859999f },
{ -1.305324f, 2.511282f, -0.472948f },
{ -0.897541f, 2.615157f, 0.444004f },
{ -0.526614f, 2.454264f, 1.368345f },
{ -0.376177f, 2.506024f, -0.86606f },
{ -0.043841f, 2.067911f, 0.066016f },
{ 0.402532f, 2.449006f, 0.975233f },
{ 0.516113f, 2.235999f, -1.251785f },
{ 0.923896f, 2.339874f, -0.334832f },
{ 1.294823f, 2.17898f, 0.589509f },
{ -0.376919f, 0.871748f, -1.402676f },
{ -0.7162949f, 0.905486f, -0.872716f },
{ -0.886263f, 0.793912f, -0.35254f },
{ 0.321625f, 1.166816f, -1.12768f },
{ 0.101362f, 1.06987f, -0.6146539f },
{ -0.010778f, 0.793912f, -0.138295f },
{ 1.265527f, 0.721117f, 0.05733f },
{ 0.910174f, 0.772701f, -0.460586f },
{ 0.494474f, 0.677545f, -0.821223f },
{ 0.74778f, 1.019084f, 0.599369f },
{ 0.358571f, 0.938701f, 0.195432f },
{ -0.043212f, 0.677545f, -0.09785099f },
{ -0.116157f, 0.65631f, 1.378316f },
{ -0.5304469f, 0.672173f, 0.9036739f },
{ -0.7740999f, 0.544282f, 0.417673f },
{ 0.5307119f, 0.948214f, 0.994904f },
{ 0.238207f, 0.834795f, 0.523007f },
{ 0.060082f, 0.544282f, 0.07633f },
{ -1.613682f, 0.474513f, -0.546838f },
{ -0.914491f, 0.448915f, -0.955068f },
{ -0.252948f, 0.243046f, -1.142972f },
{ -1.295356f, 0.643815f, 0.364344f },
{ -0.638728f, 0.456094f, 0.111141f },
{ -0.023693f, 0.243046f, -0.007376f },
{ 0.981731f, 0.236152f, -1.387459f },
{ 0.17792f, 0.256541f, -1.289235f },
{ -0.472441f, 0.09215599f, -1.033625f },
{ 1.287123f, 0.390615f, -0.473003f },
{ 0.602149f, 0.244832f, -0.272831f },
{ 0.0323f, 0.09215599f, 0.009147f },
{ 0.234335f, 0.414863f, 1.655813f },
{ 0.752857f, 0.328119f, 1.039546f },
{ 1.042764f, 0.068115f, 0.436486f },
{ -0.604242f, 0.5609339f, 1.173081f },
{ -0.250283f, 0.318372f, 0.584534f },
{ -0.038009f, 0.068115f, 0.019275f },
{ -0.590588f, 0.006223f, 0.561969f },
{ -0.509919f, 0.006223f, 0.645797f },
{ -0.75393f, 0.873203f, 0.558832f },
{ -0.673261f, 0.873203f, 0.64266f },
{ -0.84457f, 1.139033f, 0.469351f },
{ -0.64918f, 1.191689f, 0.673405f },
{ -0.348897f, 1.695425f, -0.664578f },
{ -1.259395f, 1.517704f, -0.267983f },
{ -2.095101f, 1.085307f, 0.096034f },
{ 0.013048f, 1.822763f, 0.268514f },
{ -0.744348f, 1.123713f, 0.59842f },
{ -1.733156f, 1.212645f, 1.029125f },
{ 0.449785f, 1.695425f, 1.169027f },
{ -0.460713f, 1.517704f, 1.565622f },
{ -1.296419f, 1.085307f, 1.929639f },
{ -0.403174f, 0.026248f, 2.286799f },
{ 0.09474099f, 0.153371f, 1.660624f },
{ 0.38166f, 0.087822f, 1.005865f },
{ -1.271649f, 0.196438f, 1.874319f },
{ -0.921995f, 0.150286f, 1.237041f },
{ -0.711141f, 0.087822f, 0.621258f },
{ -2.309094f, 0.040437f, 0.149477f },
{ -1.944419f, 0.144826f, 0.865221f },
{ -1.470092f, 0.057924f, 1.397002f },
{ -1.567701f, 0.218669f, -0.463832f },
{ -1.134959f, 0.151024f, 0.118121f },
{ -0.665607f, 0.057924f, 0.5633709f }
};

NJS_VECTOR normal_001548A4[] = {
	{ 0.9664519f, -0.03584f, -0.254335f },
{ 0.9664519f, -0.03584f, -0.254335f },
{ 0.967052f, 0.006578f, -0.254493f },
{ 0.967059f, 0.005374f, -0.254495f },
{ 0.96579f, -0.051506f, -0.254161f },
{ 0.966456f, -0.035706f, -0.254336f },
{ 0.960012f, -0.120624f, -0.25264f },
{ 0.960012f, -0.120624f, -0.25264f },
{ -0.035386f, 0.994661f, -0.09694099f },
{ 0.256648f, 0.963295f, -0.07871f },
{ 0.066923f, 0.98717f, 0.144974f },
{ 0.187934f, 0.9776779f, 0.09395099f },
{ 0.137821f, 0.990072f, -0.027628f },
{ 0.085304f, 0.985193f, -0.148724f },
{ 0.20392f, 0.958493f, -0.199267f },
{ 0.01659f, 0.999576f, 0.023937f },
{ 0.306229f, 0.9510019f, 0.042648f },
{ -0.218738f, 0.954886f, -0.200866f },
{ -0.17876f, 0.983893f, -0.000341f },
{ -0.140432f, 0.976486f, 0.163563f },
{ -0.218738f, 0.954886f, -0.200866f },
{ -0.184731f, 0.98239f, -0.028013f },
{ -0.140432f, 0.976487f, 0.163563f },
{ 0.293028f, 0.9501629f, -0.106418f },
{ 0.09349699f, 0.984714f, -0.146955f },
{ -0.072542f, 0.981814f, -0.17544f },
{ 0.293028f, 0.9501629f, -0.106418f },
{ 0.121268f, 0.982449f, -0.141734f },
{ -0.072542f, 0.981814f, -0.17544f },
{ -0.197505f, 0.958749f, 0.204433f },
{ -0.187914f, 0.9821849f, -0.000527f },
{ -0.174133f, 0.97028f, -0.168029f },
{ -0.197505f, 0.958749f, 0.204433f },
{ -0.189715f, 0.981447f, 0.027754f },
{ -0.174133f, 0.97028f, -0.168029f },
{ -0.013136f, 0.9962969f, -0.08497199f },
{ 0.149733f, 0.985805f, -0.075945f },
{ 0.279038f, 0.957931f, -0.06712499f },
{ -0.013136f, 0.9962969f, -0.08497199f },
{ 0.131949f, 0.9882579f, -0.077042f },
{ 0.279038f, 0.957931f, -0.06712499f },
{ 0.015559f, 0.996708f, -0.079569f },
{ -0.108142f, 0.993955f, 0.018924f },
{ -0.207112f, 0.973298f, 0.09897f },
{ 0.015559f, 0.996708f, -0.079569f },
{ -0.09535199f, 0.995406f, 0.008661999f },
{ -0.207112f, 0.973298f, 0.09897f },
{ 0.101316f, 0.993356f, -0.054574f },
{ 0.121869f, 0.96971f, -0.211685f },
{ 0.136363f, 0.931862f, -0.336211f },
{ 0.101316f, 0.993356f, -0.054574f },
{ 0.119892f, 0.973304f, -0.195718f },
{ 0.136363f, 0.931862f, -0.336211f },
{ 0.714241f, 0.132079f, -0.6873249f },
{ 0.714241f, 0.132079f, -0.6873249f },
{ 0.719206f, 0.062309f, -0.691997f },
{ 0.718702f, 0.07251599f, -0.6915269f },
{ 0.720589f, 0.012341f, -0.693252f },
{ 0.720589f, 0.012341f, -0.693252f },
{ -0.212564f, 0.97583f, -0.050717f },
{ -0.224607f, 0.944026f, 0.24159f },
{ -0.441986f, 0.895671f, 0.049215f },
{ -0.39231f, 0.903821f, 0.170882f },
{ -0.279679f, 0.952334f, 0.121822f },
{ -0.162168f, 0.9842319f, 0.070637f },
{ -0.107631f, 0.97583f, 0.190188f },
{ -0.32987f, 0.944026f, -0.0007099999f },
{ -0.337053f, 0.895671f, 0.290119f },
{ -0.00101f, 0.980164f, 0.198184f },
{ 0.017039f, 0.998964f, 0.0422f },
{ 0.031456f, 0.995807f, -0.085907f },
{ -0.00101f, 0.980164f, 0.198184f },
{ 0.015174f, 0.99817f, 0.058537f },
{ 0.031456f, 0.995807f, -0.085907f },
{ -0.167894f, 0.984098f, -0.057985f },
{ -0.030361f, 0.99928f, 0.022757f },
{ 0.082764f, 0.992641f, 0.08839399f },
{ -0.167894f, 0.984098f, -0.057985f },
{ -0.044594f, 0.9989009f, 0.014449f },
{ 0.082764f, 0.992641f, 0.08839399f }
};

NJS_MODEL_SADX attach_00154C64 = { vertex_001544E4, normal_001548A4, LengthOfArray<Sint32>(vertex_001544E4), meshlist_001544B4, matlist_00154250, LengthOfArray<Uint16>(meshlist_001544B4), LengthOfArray<Uint16>(matlist_00154250),{ -0.507136f, 1.307578f, 0.442062f }, 2.578781f, NULL };

NJS_OBJECT object_00154C8C = { NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &attach_00154C64, 0, 0, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };
