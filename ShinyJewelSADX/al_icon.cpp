#include "stdafx.h"
#include "chao.h"
#include "al_icon.h"
#include "CWESADX.h"

#include "data/icon/ChaoBall1.nja"
#include "data/icon/SpikeBall.nja"
#include "data/icon/HeartEmote.nja"
#include "data/icon/HaloEmote.nja"
#include "data/icon/ExclamationEmote.nja"
#include "data/icon/SwirlEmote.nja"
#include "data/icon/QuestionEmote.nja"

FunctionPointer(void, njDrawTexture3DEx, (NJS_TEXTURE_VTX* a1, signed int count, int a3), 0x0077E940);
__int16 FireTexNum[16] =
{ 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57 };
DataArray(int, HeroIconNumberTable, 0x034BBCF8, 182);
#define AL_GetStageNumber GetCurrentChaoStage
void __cdecl AL_IconDrawSub(ObjectMaster* a1)
{
	ObjectMaster* v1; // ebp
	ChaoData1* v2; // esi
	double v3; // st7
	Uint32 v4; // edi
	double v5; // st7
	double v6; // st7
	double v7; // st7
	Float v8; // ST24_4
	Float v9; // ST28_4
	Float v10; // ST24_4
	char v11; // al
	double v12; // st7
	double v13; // st7
	ChaoDataBase* v14; // edi
	double v15; // st7
	unsigned __int8 v16; // cl
	Float v17; // ST24_4
	unsigned __int64 v18; // rax
	Float v19; // ST24_4
	Float v20; // ST24_4
	Float v21; // ST24_4
	Float v22; // ST24_4
	int v23; // eax
	Float v24; // ST0C_4
	Float v25; // ST08_4
	Float v26; // ST24_4
	float sx; // [esp+1Ch] [ebp-B8h]
	float sxa; // [esp+1Ch] [ebp-B8h]
	float sxb; // [esp+1Ch] [ebp-B8h]
	float sy; // [esp+20h] [ebp-B4h]
	float sya; // [esp+20h] [ebp-B4h]
	float syb; // [esp+20h] [ebp-B4h]
	NJS_VECTOR vd; // [esp+24h] [ebp-B0h]
	NJS_VECTOR p3; // [esp+30h] [ebp-A4h]
	NJS_VECTOR v; // [esp+3Ch] [ebp-98h]
	ChaoDataBase* v36; // [esp+48h] [ebp-8Ch]
	NJS_VECTOR vs; // [esp+4Ch] [ebp-88h]
	NJS_VECTOR v38; // [esp+58h] [ebp-7Ch]
	NJS_TEXTURE_VTX a1a[4]; // [esp+64h] [ebp-70h]
	NJS_POINT2 p2; // [esp+C4h] [ebp-10h]
	NJS_POINT2 v41; // [esp+CCh] [ebp-8h]
	
	v1 = a1;
	v2 = (ChaoData1*)a1->Data1;
	v36 = v2->pParamGC;
	vs.x = v2->Icon.Upper.Pos.x;
	vs.y = v2->Icon.Upper.Pos.y;
	vs.z = v2->Icon.Upper.Pos.z;
	v38.x = v2->Icon.Lower.Pos.x;
	v38.y = v2->Icon.Lower.Pos.y;
	v38.z = v2->Icon.Lower.Pos.z;
	p3.x = v2->Icon.Lower.Pos.x;
	p3.y = v2->Icon.Lower.Pos.y;
	p3.z = v2->Icon.Lower.Pos.z;
	if (AL_GetStageNumber() == 2 && a1->Data1->Position.z > -45.0 || AL_GetStageNumber() == 3)
	{
		v3 = 1.0 / HorizontalStretch;
		vs.x = (vs.x - v2->entity.Position.x) * v3 + v2->entity.Position.x;
		vs.y = (vs.y - v2->entity.Position.y) * v3 + v2->entity.Position.y;
		v38.x = (v38.x - v2->entity.Position.x) * v3 + v2->entity.Position.x;
		v38.y = (v38.y - v2->entity.Position.y) * v3 + v2->entity.Position.y;
		p3.x = (p3.x - v2->entity.Position.x) * v3 + v2->entity.Position.x;
		p3.y = (p3.y - v2->entity.Position.y) * v3 + v2->entity.Position.y;
	}
	if (v2->ChaoFlag & 0x100000)
	{
		v.x = p3.x + v2->Icon.Up.x;
		v.y = p3.y + v2->Icon.Up.y;
		v.z = p3.z + v2->Icon.Up.z;
		njProjectScreen(0, &p3, &p2);
		njProjectScreen(0, &v, &v41);
		v4 = v2->Icon.Color;
		njColorBlendingMode(0, NJD_COLOR_BLENDING_SRCALPHA);
		njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);
		a1a[0].x = -0.55000001;
		a1a[0].y = -0.55000001;
		a1a[0].z = 0.30000001;
		a1a[0].u = 0.0;
		a1a[0].v = 0.0;
		a1a[0].col = v4;
		a1a[1].x = -0.55000001;
		a1a[1].y = 0.55000001;
		a1a[1].z = 0.30000001;
		a1a[1].u = 0.0;
		a1a[1].v = 1.0;
		a1a[1].col = v4;
		a1a[2].x = 0.55000001;
		a1a[2].y = -0.55000001;
		a1a[2].z = 0.30000001;
		a1a[2].u = 1.0;
		a1a[2].v = 0.0;
		a1a[2].col = v4;
		a1a[3].x = 0.55000001;
		a1a[3].y = 0.55000001;
		a1a[3].z = 0.30000001;
		a1a[3].u = 1.0;
		a1a[3].v = 1.0;
		a1a[3].col = v4;
		//draw upper
		if (v2->Icon.Upper.TexNum != 10)
		{
			//njCalcPoint(0, &vs, &vd);
			vd = vs;
			v5 = vd.y;
			if (a1->Data1->Status & 0x1000)
			{
				v6 = v5 + 0.69999999;
			}
			else
			{
				v6 = v5 + 0.30000001;
			}
			vd.y = v6;
			njPushMatrix(0);
			v7 = (njSin(v2->Icon.PuniPhase + 0x4000) + 1.0) * 0.079999998 + 0.92000002;
			v8 = v7 * v2->Icon.Upper.Scl.x;
			v9 = (2.0 - v7) * v2->Icon.Upper.Scl.y;
			vd.x = vd.x + v2->Icon.Upper.Offset.x;
			njSetTexture(&ChaoTexLists[3]);
			njSetTextureNum(v2->Icon.Upper.TexNum);
			njTranslateV(0, &vd);
			njRotateY(0, a1->Data1->Rotation.y);
			njScale(0, v8, v9, 2);

			EnableChunkMaterialFlags();
			SetChunkTextureIndexA(0);
			SetChunkMaterialFlags(1 | 8);
			ColorChunkModel(v2->Icon.Color);

			njPushMatrixEx();
			switch (v2->Icon.Upper.TexNum)
			{
			case 1:
				njTranslate(0,0, -0.6f, 0);
				njCnkDrawObject(&batch_2);
				break;
			case 2:
				njTranslate(0, 0, -0.6f, 0);
				njCnkDrawObject(&batch_8);
				break;
			case 3:
				//njTranslate(0, 0, -0.6f, 0);
				njCnkDrawObject(&object_hearticon);
				break;
			case 4:
				njTranslate(0, 0, -0.6f, 0);
				njCnkDrawObject(&object_swirlicon);
				break;
			default:
				break;
			}
			njPopMatrixEx();

			DisableChunkMaterialFlags();
			
			njPopMatrixEx();
		}

		//draw lower
		v11 = v36->Headgear;
		if ((unsigned __int8)v11 >= 0xCu && (unsigned __int8)v11 <= 0xEu)
		{
			goto LABEL_33;
		}
		njCalcPoint(0, &v38, &vd);
		v12 = vd.y;
		if (a1->Data1->Status & 0x1000)
		{
			v13 = v12 + 0.69999999;
		}
		else
		{
			v13 = v12 - 0.30000001;
		}
		vd.y = v13;
		njPushMatrix(_nj_unit_matrix_);
		v14 = v2->pParamGC;
		v15 = (njSin(v2->Icon.PuniPhase) + 1.0) * 0.079999998 + 0.92000002;
		sy = v15 * v2->Icon.Lower.Scl.x;
		sx = (2.0 - v15) * v2->Icon.Lower.Scl.y;
		njTranslateV(0, &vd);
		njSetTexture(&ChaoTexLists[3]);
		//if has custom ball, do that
		if (v14->BallType)
		{
			if (v14->BallType != 1)
			{
			LABEL_32:
				njPopMatrixEx();
			LABEL_33:
				njColorBlendingMode(0, NJD_COLOR_BLENDING_SRCALPHA);
				njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);
				return;
			}
			njSetTextureNum((unsigned __int16)FireTexNum[v2->Icon.TexAnimNum]);
			njScale(0, sy, sx, 1.0);
			njColorBlendingMode(0, NJD_COLOR_BLENDING_SRCALPHA);
			njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
		}
		else
		{
			//if not check type
			v16 = v14->Type;
			if (v16 < ChaoType_Tails || v16 > ChaoType_Amy) //not character chao
			{
				if (v16 >= ChaoType_Hero_Normal)
				{
					if (!((v16 - 6) % 3)) //is hero
					{
						v.x = p3.x - camcont_wp.camxpos;
						v.y = p3.y - camcont_wp.camypos;
						v.z = p3.z - camcont_wp.camzpos;
						if (njScalor(&v) <= 0.0000001)
						{
							v.x = 0.0;
							v.y = 1.0;
							v.z = 0.0;
						}
						else
						{
							njUnitVector(&v);
						}
						sya = sy + sy;
						sxa = sx + sx;
						v36 = (ChaoDataBase*)(unsigned __int16)(unsigned __int64)(acos(-njInnerProduct(&v, &v2->Icon.Up))
							* 65536.0
							* 0.1591549762031479);
						njSetTextureNum(
							HeroIconNumberTable[(signed int)(unsigned __int64)((double)(signed int)v36 * 0.0054931640625 + 0.5) % 181]
							+ 6);
						v18 = (atan2((v41.x - p2.x) - 1, -(v41.y - p2.y)) * 65536.0f * 0.1591549762031479f);
						if (v18)
						{
							njRotateZ(0, v18);
						}
						njScale(0, sya, sxa, 1.0);
						if (v14->Type == 21)
						{
							njColorBlendingMode(0, NJD_COLOR_BLENDING_SRCALPHA);
							njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
							//njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);
						}
						if (AL_GetStageNumber() == 2 && a1->Data1->Position.z > -45.0 || AL_GetStageNumber() == 3)
						{
							//v19 = 1.0 / HorizontalStretch;
							//njScale(0, v19, v19, v19);
							//njDrawTexture3DEx(a1a, 4, 1);
							//goto LABEL_32;
						}
						EnableChunkMaterialFlags();
						SetChunkTextureIndexA(0);
						SetChunkMaterialFlags(1 | 8);
						ColorChunkModel(v2->Icon.Color);
//						*(float*)0x3D0857C = -0.1f;
						njScale(0, 0.5f, 0.5f, 0.5f); //model too large, todo fix this with the chunk model version
						njCnkDrawObject(&object_herohalo);

						DisableChunkMaterialFlags();

						goto LABEL_32;
					}
					v1 = a1;
				}
				if (v16 < 7u || (v16 - 7) % 3)
				{
					if (v16 != 20)
					{
						//regular ball code?
						njSetTextureNum(v2->Icon.Lower.TexNum);
						njScale(0, sy, sx, 1.0);
						if (AL_GetStageNumber() == 2 && v1->Data1->Position.z > -45.0 || AL_GetStageNumber() == 3)
						{
							v22 = 1.0 / HorizontalStretch;
							njScale(0, v22, v22, v22);
							//njDrawTexture3DEx(a1a, 4, 1);
							//goto LABEL_32;
						}

						EnableChunkMaterialFlags();
						SetChunkTextureIndexA(0);
						SetChunkMaterialFlags(1 | 8);
						ColorChunkModel(v2->Icon.Color);
						njCnkDrawObject(&batch_12);
						DisableChunkMaterialFlags();

						goto LABEL_32;
					}
					//neutral chaos chao code
					njSetTextureNum(6u);
					njColorBlendingMode(0, NJD_COLOR_BLENDING_SRCALPHA);
					njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
					v23 = v2->Icon.ang;
					if (v23)
					{
						njRotateZ(0, (unsigned __int16)v23);
					}
					v24 = sx * 1.5;
					v25 = sy * 1.5;
					njScale(0, v25, v24, 1.0);
					if ((AL_GetStageNumber() != 2 || v1->Data1->Position.z <= -45.0) && AL_GetStageNumber() != 3)
					{
					LABEL_31:
						//so both hero and neutral icons end up here when drawn. todo separate
						
						njDrawTexture3DEx(a1a, 4, 1);
						goto LABEL_32;
					}
					v26 = 1.0 / HorizontalStretch;
					njScale(0, v26, v26, v26);
				}
				else
				{
					syb = sy * 1.5;
					sxb = sx * 1.5;
					if (v16 == 22) //is dark chaos chao
					{
						njSetTextureNum((unsigned __int16)FireTexNum[v2->Icon.TexAnimNum]);
						njScale(0, syb, sxb, 1.0);
						njColorBlendingMode(0, NJD_COLOR_BLENDING_SRCALPHA);
						njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
						if (AL_GetStageNumber() == 2 && v1->Data1->Position.z > -45.0 || AL_GetStageNumber() == 3)
						{
							v21 = 1.0 / HorizontalStretch;
							njScale(0, v21, v21, v21);
							njDrawTexture3DEx(a1a, 4, 1);
							goto LABEL_32;
						}
						goto LABEL_31;
					}
					njSetTextureNum(5u);
					njScale(0, syb, sxb, 1.0);
					if (AL_GetStageNumber() == 2 && v1->Data1->Position.z > -45.0 || AL_GetStageNumber() == 3)
					{
						v20 = 1.0 / HorizontalStretch;
						njScale(0, v20, v20, v20);
						goto LABEL_56;
					}
				}

				EnableChunkMaterialFlags();
				SetChunkTextureIndexA(0);
				SetChunkMaterialFlags(1 | 8);
				ColorChunkModel(v2->Icon.Color);
				
				njScale(0, 0.5f, 0.5f, 0.5f); //model too large, todo fix this with the chunk model version
				njCnkDrawObject(&object_dark_icon);

				DisableChunkMaterialFlags();

				//njDrawTexture3DEx(a1a, 4, 1);
				goto LABEL_32;
			}
			njSetTextureNum(v2->Icon.Lower.TexNum);
			njScale(0, sy, sx, 1.0);
		}
		if (AL_GetStageNumber() == 2 && a1->Data1->Position.z > -45.0 || AL_GetStageNumber() == 3)
		{
			v17 = 1.0 / HorizontalStretch;
			njScale(0, v17, v17, v17);
			goto LABEL_31;
		}
	LABEL_56:
		njDrawTexture3DEx(a1a, 4, 1);
		goto LABEL_32;
	}
}