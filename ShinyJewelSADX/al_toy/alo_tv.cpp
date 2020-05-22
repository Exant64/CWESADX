
#include "alo_tv.h"
int TVChannel1;
int TVChannel2;
int TVChannel3;

CollisionData tvCollision = { 0, 0xC77, 0, 32768,{ 0,1,0},{2,0,0},  0,0 };
void  SetChunkTextureID(NJS_CNK_MODEL* a1, __int16 a2)
{
	signed int v2; // esi
	int v3; // eax
	NJS_CNK_MODEL* v4; // edx
	unsigned __int8 v5; // cl
	__int16 v6; // cx
	short* v7; // eax

	v2 = 0;
	if (a1)
	{
		v3 = (int)a1->plist;
		if (v3)
		{
			v4 = a1 + 1;
			while (1)
			{
				do
				{
					while (1)
					{
						while (1)
						{
							while (1)
							{
							LABEL_4:
								while (1)
								{
									v5 = *(char*)v3;
									if (*(char*)v3 >= 1u)
									{
										break;
									}
									v3 += 2;
								}
								if (v5 >= 8u)
								{
									break;
								}
								v3 += 2;
							}
							if (v5 >= 0x10u)
							{
								break;
							}
							if (v5 == 8)
							{
								v6 = *(short*)(v3 + 2);
								v7 = (short*)(v3 + 2);
								if (v2 < 4 && SLOWORD(v4->vlist) < 0)
								{
									*(short*)(v4->vlist) = v6 & 0x1FFF;
									++v2;
									v4 = (NJS_CNK_MODEL*)((char*)v4 + 2);
								}
								*v7 = a2 & 0x1FFF | v6 & 0xC000;
								v3 = (int)(v7 + 1);
							}
							else
							{
							LABEL_16:
								v3 += 4;
							}
						}
						if (v5 >= 0x20u)
						{
							break;
						}
						v3 += 4;
						switch (v5)
						{
						case 17u:
						case 18u:
						case 20u:
							goto LABEL_16;
						case 19u:
						case 21u:
						case 22u:
							v3 += 8;
							break;
						case 23u:
							v3 += 12;
							break;
						default:
							goto LABEL_4;
						}
					}
				} while (v5 < 0x38u || v5 < 0x40u);
				if (v5 >= 0xFFu)
				{
					break;
				}
				v3 += 2 + 2 * (unsigned __int16)(*(short*)(v3 + 2) + 1);
			}
		}
	}
}
void TV_Display(ObjectMaster* a1)
{
	if (ScaleObjectMaster_XYZ(a1, 3.0f, 3.0f, 1.0f)) {
		njPushMatrixEx();
		njSetTexture(&AL_TOY_TEXLIST);
		njControl3D_Add(NJD_CONTROL_3D_TRANS_MODIFIER | NJD_CONTROL_3D_SHADOW);

		njTranslate(0, a1->Data1->Position.x, a1->Data1->Position.y, a1->Data1->Position.z);
		njRotateY(0, a1->Data1->Rotation.y);
		njScale(0, 1, 1, 1);
		njCnkDrawObject(&TV);
		njControl3D_Remove(NJD_CONTROL_3D_TRANS_MODIFIER | NJD_CONTROL_3D_SHADOW);
		njPopMatrixEx();
	}
}
short word_12C1EF4[] = { 1,2,3,4,5,0 };
short word_12C226C[] = { 0x10, 0x11 };
short word_13047C4[] = { 6,7,8,0 };
short word_13047CC[] = { 9,0x0A, 0x0B, 0 };
short word_13047D4[] = { 0x0F, 0x0E, 0x0D, 0x0C };
short word_13047DC[] = { 0x0C, 0x0D, 0x0E, 0x0F };
void TV_Main(ObjectMaster* a1)
{
	ObjectMaster* v1; // esi
	EntityData1* v2; // ebp
	char v3; // al
	_BOOL1 v4; // zf
	_BOOL1 v5; // sf
	unsigned __int8 v6; // of
	int v7; // eax
	double v9; // st7
	char v10; // al
	unsigned __int16 v11; // ax
	char v12; // al
	__int16 v14; // di
	ObjectMaster* v15; // eax
	char v16; // al
	char v17; // al
	ObjectMaster* v18; // eax
	char v19; // al
	int v20; // eax
	ObjectMaster* v21; // eax
	ObjectMaster* v22; // eax
	float a1a; // [esp+24h] [ebp+4h]

	v1 = a1;
	v2 = a1->Data1;
	switch (v2->Action)
	{
	case 1:
		v2->Rotation.x = 0;
		if (TV.child->chunkmodel)
		{
			SetChunkTextureID(TV.child->chunkmodel, word_13047D4[0]);
		}
		++v2->Action;
		v2->NextAction = 0;
		goto LABEL_5;
	case 2:
	LABEL_5:
		v3 = v2->Index++;
		if ((unsigned __int8)v3 > 4u)
		{
			v6 = __OFSUB__(++v2->Rotation.x, 3);
			v4 = v2->Rotation.x == 3;
			v5 = v2->Rotation.x - 3 < 0;
			v2->Index = 0;
			if (!((unsigned __int8)(v5 ^ v6) | (unsigned __int8)v4))
			{
				v22 = ALOField_Find(a1, 0, 304);
				if (v22) //is playing wii
				{
					v2->Action = 13;
					v2->InvulnerableTime = 0;
					float test = (((float)rand() * 0.000030517578125f) * 4.0f);
					v2->field_A = test;
				}
				else
				{
					v7 = rand();
					v2->Rotation.x = 3;
					v2->NextAction = 0;
					v2->Index = 0;
					a1a = (double)v7 * 0.000030517578125f;
					v9 = a1a;
					if (a1a >= 0.30000001f)
					{
						if (v9 >= 0.60000002f)
						{
							if (v9 >= 0.8999999761581421f)
							{
								v2->Action = 5;
								v2->InvulnerableTime = 0;
							}
							else
							{
								v2->Action = 11;
								v2->InvulnerableTime = 0;
								//PlayJingle(TVChannel1);
							}
						}
						else
						{
							v2->Action = 9;
							v2->InvulnerableTime = 0;
							//PlayJingle(TVChannel2);
						}
					}
					else
					{
						v2->Action = 7;
						v2->InvulnerableTime = 0;
						//PlayJingle(TVChannel3);
					}
				}
			}
			//v2->Action = 9;

			if (TV.child->chunkmodel)
			{
				SetChunkTextureID(TV.child->chunkmodel, word_13047D4[v2->Rotation.x]);
			}
		}
		goto LABEL_24;
	case 3:
		v2->Rotation.x = 0;
		if (TV.child->chunkmodel)
		{
			SetChunkTextureID(TV.child->chunkmodel, word_13047DC[0]);
		}
		//InitJingle();
		++v2->Action;
		v2->NextAction = 0;
		goto LABEL_19;
	case 4:
	LABEL_19:
		v10 = v2->Index++;
		if ((unsigned __int8)v10 > 4u)
		{
			v6 = __OFSUB__(++v2->Rotation.x, 3);
			v4 = v2->Rotation.x == 3;
			v5 = v2->Rotation.x - 3 < 0;
			v2->Index = 0;
			if (!((unsigned __int8)(v5 ^ v6) | (unsigned __int8)v4))
			{
				v2->Rotation.x = 3;
				v2->Action = 0;
				v2->NextAction = 0;
				v2->InvulnerableTime = 0;
				v2->Index = 0;
			}
			if (TV.child->chunkmodel)
			{
				SetChunkTextureID(TV.child->chunkmodel, word_13047DC[v2->Rotation.x]);
			}
		}
		goto LABEL_24;
	case 5:
		v2->Rotation.x = 0;
		if (TV.child->chunkmodel)
		{
			SetChunkTextureID(TV.child->chunkmodel, word_12C226C[0]);
		}
		++v2->Action;
		v2->NextAction = 0;
		goto LABEL_30;
	case 6:
	LABEL_30:
		v12 = v2->Index++;
		if ((unsigned __int8)v12 <= 1u)
		{
			goto LABEL_36;
		}
		v6 = __OFSUB__(++v2->Rotation.x, 1);
		v4 = v2->Rotation.x == 1;
		v5 = v2->Rotation.x - 1 < 0;
		v2->Index = 0;
		if (!((unsigned __int8)(v5 ^ v6) | (unsigned __int8)v4))
		{
			v2->Rotation.x = 0;
		}

		if (!TV.child->chunkmodel)
		{
			goto LABEL_36;
		}
		v14 = word_12C226C[v2->Rotation.x];
		goto LABEL_35;
	case 7:
		v2->Rotation.x = 0;
		if (TV.child->chunkmodel)
		{
			SetChunkTextureID(TV.child->chunkmodel, word_12C1EF4[0]);
		}
		++v2->Action;
		v2->NextAction = 0;
		goto LABEL_43;
	case 8:
	LABEL_43:
		v16 = v2->Index++;
		if ((unsigned __int8)v16 > 8u)
		{
			v6 = __OFSUB__(++v2->Rotation.x, 4);
			v4 = v2->Rotation.x == 4;
			v5 = v2->Rotation.x - 4 < 0;
			v2->Index = 0;
			if (!((unsigned __int8)(v5 ^ v6) | (unsigned __int8)v4))
			{
				v2->Rotation.x = 0;
			}

			if (TV.child->chunkmodel)
			{
				v14 = word_12C1EF4[v2->Rotation.x];
			LABEL_35:
				SetChunkTextureID(TV.child->chunkmodel, v14);
			}
		}
	LABEL_36:
		v15 = ALOField_Find2(v2, 0xB1u);
		if (!v15 || !*((_DWORD*)v15 + 1))
		{
			goto LABEL_24;
		}
		v2->Action = 9;
		goto LABEL_39;
	case 9:
		v2->Rotation.x = 0;
		if (TV.child->chunkmodel)
		{
			SetChunkTextureID(TV.child->chunkmodel, word_13047C4[0]);
		}
		++v2->Action;
		v2->NextAction = 0;
		goto LABEL_51;
	case 10:
	LABEL_51:
		v17 = v2->Index++;
		if ((unsigned __int8)v17 > 0xCu)
		{
			v6 = __OFSUB__(++v2->Rotation.x, 2);
			v4 = v2->Rotation.x == 2;
			v5 = v2->Rotation.x - 2 < 0;
			v2->Index = 0;
			if (!((unsigned __int8)(v5 ^ v6) | (unsigned __int8)v4))
			{
				v2->Rotation.x = 0;
			}
			if (TV.child->chunkmodel)
			{
				SetChunkTextureID(TV.child->chunkmodel, word_13047C4[v2->Rotation.x]);
			}
		}
		v18 = ALOField_Find2(v2, 0xB1u);
		if (!v18 || !*((_DWORD*)v18 + 1))
		{
			goto LABEL_24;
		}
		v2->Action = 11;
		goto LABEL_39;
	case 11:
		v2->Rotation.x = 0;
		if (TV.child->chunkmodel)
		{
			SetChunkTextureID(TV.child->chunkmodel, word_13047CC[0]);
		}
		++v2->Action;
		v2->NextAction = 0;
		goto LABEL_62;
	case 12:
	LABEL_62:
		v19 = v2->Index++;
		if ((unsigned __int8)v19 > 0x96u)
		{
			v2->Index = 0;
			v20 = (unsigned __int16)(signed int)((double)rand() * 0.000030517578125 * 2.900000095367432);
			v2->Rotation.x = v20;
			if (TV.child->chunkmodel)
			{
				SetChunkTextureID(TV.child->chunkmodel, word_13047CC[v2->Rotation.x]);
			}
		}
		v21 = ALOField_Find2(v2, 0xB1u);
		if (!v21 || !*((_DWORD*)v21 + 1))
		{
			goto LABEL_24;
		}
		v2->Action = 7;
	LABEL_39:
		v2->NextAction = 0;
		v2->InvulnerableTime = 0;
		v2->Index = 0;
		goto LABEL_25;
	case 13:
		v2->Rotation.x = 0;
		if (TV.child->chunkmodel)
		{
			SetChunkTextureID(TV.child->chunkmodel, 121 + v2->Rotation.x + 4 * v2->field_A);
		}
		++v2->Action;
		v2->NextAction = 0;
		break;
	case 14:
		v12 = v2->Index++;
		if ((unsigned __int8)v12 <= 30)
		{
			goto LABEL_36;
		}
		v6 = __OFSUB__(++v2->Rotation.x, 3);
		v4 = v2->Rotation.x == 3;
		v5 = v2->Rotation.x - 3 < 0;
		v2->Index = 0;
		if (!((unsigned __int8)(v5 ^ v6) | (unsigned __int8)v4))
		{
			v2->Rotation.x = 0;
		}

		if (!TV.child->chunkmodel)
		{
			goto LABEL_36;
		}
		v14 = 121 + v2->Rotation.x + 4 * v2->field_A;
		goto LABEL_35;
	default:
	LABEL_24:
		if (v2->Action)
		{
		LABEL_25:
			v11 = v2->InvulnerableTime;
			v2->InvulnerableTime = v11 + 1;
			if (v11 > 0xE10u)
			{
				v2->Action = 3;
				v2->NextAction = 0;
				v2->InvulnerableTime = 0;
				v2->Index = 0;

				return;
			}
		}
		else
		{
			v22 = ALOField_Find(a1, 0, 175);
			if (v22)
			{
				v22 = ALOField_Find(a1, 0, 303);
				if (v22) //is playing wii
					ALOField_Load(a1, 304, &v2->Position, 25.5, 3600);

				v2->Action = 1;
				v2->NextAction = 0;
				v2->InvulnerableTime = 0;
				v2->Index = 0;

				ObjectMaster* field = ALOField_Load(a1, 201, &v2->Position, 25.5, 3600);

			}
		}


	}
	Chao_AddToCollisionList(a1);
	RunObjectChildren(a1);
	a1->DisplaySub(a1);
}
void TV_Load(ObjectMaster* a1)
{
	AddToGlobalChaoThingMaybe(6, a1, 2, 0);
	if (TV.child->chunkmodel)
	{
		SetChunkTextureID((NJS_CNK_MODEL*)0x389606C, 15);
	}
	ObjectFunc(ALO_Delete, 0x71A6B0);
	a1->MainSub = (void(__cdecl*)(ObjectMaster*))TV_Main;
	a1->DeleteSub = ALO_Delete;
	a1->DisplaySub = (void(__cdecl*)(ObjectMaster*))TV_Display;
}

void PlaceTV()
{
	ObjectMaster* tv;
	EntityData1* tvData;

	tv = LoadObject(LoadObj_Data1, 4, TV_Load);
	tv->DisplaySub = TV_Display;
	tvData = tv->Data1;
	TVObject = tv;
	if (tv)
	{
		if (!GetModuleHandle(L"DCMods_Main"))
			tvData->Position.x = -49;
		else tvData->Position.x = -40;
		tvData->Position.y = 0;
		tvData->Position.z = -120;
		tvData->Rotation.x = 15;
		tvData->Rotation.y = 0x8000;
		tvData->Scale.x = 1;
		tvData->Scale.y = 1;
		tvData->Scale.z = 1;
		InitCollision(tv, &tvCollision, 1, 4);
	}
}
