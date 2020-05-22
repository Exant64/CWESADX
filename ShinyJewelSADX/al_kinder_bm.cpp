#include "SADXModLoader.h"
#include "al_kinder_bm.h"
#include <random>

BlackMarketItem PurchasedItems[4];
int PurchasedItemCount;

//get max object count sub_717650
//also this sub_7253C0

//7174B0 sets the held item type

//7174D0 checks purchaseditemcount || already holding chao
int CanIPurchase()
{
	if (PurchasedItemCount >= 4)
		return 0;
	else return -1;
}
#pragma pack(push, 8)
struct __declspec(align(2)) ITEM_SAVE_INFO
{
	__int16 Type;
	__int16 Garden;
	__int16 Size;
	__int16 Age;
	NJS_VECTOR position;
};
#pragma pack(pop)


ITEM_SAVE_INFO dummyItemHack;

ITEM_SAVE_INFO* ReturnDummyItem() { return &dummyItemHack; }

void PurchaseItem(int object, ITEM_SAVE_INFO* a2)
{
	PurchasedItems[PurchasedItemCount].Category = (ChaoItemCategory)object;
	PurchasedItems[PurchasedItemCount++].Type = a2->Type;
}
FunctionPointer(void, njQuadTextureStart,(bool enable), 0x0077DD90);
FunctionPointer(void, njQuadTextureEnd, (), 0x0077DDE0);
FunctionPointer(void, njDrawQuadTexture, (NJS_QUAD_TEXTURE* points, float scale), 0x0077E970);
float flt_1A13BE0 = 40.0f;
float flt_1A13BE4 = 16.0f;
float flt_1A13BE8 = 64.0;
float flt_1A13BEC = 16.0;
float flt_1A13BF0 = 0.0;
float flt_1A13BF4 = 424.0f;
float flt_1A13BD8 = -1.5f;
void DrawPurchasedItems()
{
	NJS_QUAD_TEXTURE v9;
	int v2 = 0;
	njQuadTextureStart(false);
	if (PurchasedItemCount > 0)
	{
		v9.u1 = 0.0;
		v9.u2 = 1.0;
		njSetTexture(&ChaoTexLists[1]);
		v9.v2 = 1.0;
		v9.v1 = 0.0;
		for (int i = 0; i < PurchasedItemCount; i++)
		{
			switch (PurchasedItems[i].Category)
			{
			case 1:
				v2 = 4;
				break;
			case 3:
				v2 = 5;
				break;
			case 7:
				v2 = 3;
				break;
			default: 
				v2 = 6;
				break;
			}
			*(int*)0x03D0FCE4 = 0xFFFFFFFF;
			njSetTextureNum(v2);
			float v3 = (double)i;
			float v4 = v3 * flt_1A13BE0 + flt_1A13BE8;
			v9.x1 = v4 - flt_1A13BE4;
			v9.x2 = v4 + flt_1A13BE4;
			float v5 = v3 * flt_1A13BF0 + flt_1A13BF4;
			v9.y1 = 480.0f - (flt_1A13BEC + v5);
			v9.y2 = 480.0f - (v5 - flt_1A13BEC);
			float v6 = -1.0 / flt_1A13BD8;
			njDrawQuadTexture(& v9, v6);
		}
	}
	njQuadTextureEnd();
}
VoidFunc(sub_732C40, 0x732C40);
void DrawPurchasedItems_Hook()
{
	sub_732C40();
	DrawPurchasedItems();
}

void AlItemIconTaskExec(ObjectMaster* a1) { a1->DisplaySub(a1); }
ObjectMaster* AlItemIconTaskExec_ptr = 0;
VoidFunc(sub_716460, 0x716460);
VoidFunc(LoadAnimalPVMs, 0x00722520);
void AlItemIconTaskExecKill()
{
	AlItemIconTaskExec_ptr = 0;
}
void AlItemIconTaskExecHook()
{
	LoadAnimalPVMs();
	if (!AlItemIconTaskExec_ptr)
	{
		AlItemIconTaskExec_ptr = AllocateObjectMaster(1, AlItemIconTaskExec);
		if (AlItemIconTaskExec_ptr)
		{
			AlItemIconTaskExec_ptr->DeleteSub = (ObjectFuncPtr)AlItemIconTaskExecKill;
			AlItemIconTaskExec_ptr->DisplaySub = (ObjectFuncPtr)DrawPurchasedItems;
		}
	}
}

FunctionPointer(int, AL_GetCurrGardenChaoCount,(),0x00715DF0);
FunctionPointer(ChaoDataBase*, AL_GetNewChaoSaveInfo, (), 0x00715E60);
FunctionPointer(ITEM_SAVE_INFO*, AL_GetNewItemSaveInfo,(int a1),0x00717760);
FunctionPointer(ObjectMaster*, GardenHat_Create, (int a1, NJS_VECTOR* a2, int a3, NJS_VECTOR* a4, ITEM_SAVE_INFO* a5), 0x007236F0);
FunctionPointer(void, GardenFruit_Create, (int a1, NJS_VECTOR* position, Angle angle, NJS_VECTOR* a4, ITEM_SAVE_INFO* a5), 0x722DE0);
FunctionPointer(void, MOV_SetVelo, (ObjectMaster* a1, NJS_VECTOR* a2), 0x0073FFE0);
void __cdecl sub_548F40(ObjectMaster* a2)
{
	EntityData1* v1; // esi
	__int16 v2; // ax
	EntityData1* v3; // edi
	float* v4; // ebx
	double v5; // st7
	float* v6; // ebx
	int v7; // eax
	int v8; // ebp
	int v9; // eax
	int v10; // esi
	ChaoDataBase* v11; // edi
	ObjectMaster* v12; // eax
	Float* v13; // eax
	Float v14; // edx
	Float v15; // ecx
	ChaoData* v16; // eax
	unsigned int v17; // eax
	DWORD* v18; // edx
	signed int v19; // eax
	short* v20; // ecx
	int v21; // eax
	unsigned int v22; // eax
	DWORD* v23; // edx
	signed int v24; // eax
	short* v25; // ecx
	int v26; // eax
	int v27; // eax
	int v28; // ecx
	int v29; // eax
	BlackMarketItem* v30; // esi
	BlackMarketItem* v31; // edi
	int v32; // [esp+8h] [ebp-D0h]
	NJS_VECTOR position; // [esp+Ch] [ebp-CCh]
	NJS_VECTOR output; // [esp+18h] [ebp-C0h]
	NJS_VECTOR result; // [esp+24h] [ebp-B4h]
	ChaoDNA a1; // [esp+30h] [ebp-A8h]

	v1 = (EntityData1*)a2->Data1;
	v1->Index++;
	if (v1->Index > 0xFu)
	{
		v1->Index = 0;

		position.x = PlayerPtrs[0]->Data1->Position.x;
		position.y = PlayerPtrs[0]->Data1->Position.y + 4.5;
		position.z = PlayerPtrs[0]->Data1->Position.z;

		result.x = 0.0;
		result.y = (0.5 - (double)rand() * 0.000030517578125) * 0.2000000029802322 * 1.600000023841858 + 0.960000052452088;
		result.z = (0.5 - (double)rand() * 0.000030517578125) * 0.25 * 1.600000023841858 + 0.559999998807907;

		njPushMatrixEx();
		njUnitMatrix(0);
		v5 = (0.5 - (double)rand() * 0.000030517578125) * 60.0 * -182.0444488525391;
		if (0x4000 - (signed int)v5 != PlayerPtrs[0]->Data1->Rotation.y)
		{
			njRotateY(0, 0x4000 - (signed int)v5 - PlayerPtrs[0]->Data1->Rotation.y);
		}
		njCalcVector(0,&result, &output);
		njPopMatrixEx();

		v7 = PurchasedItemCount;
		if (PurchasedItemCount <= 0)
		{
			a2->MainSub = DeleteObject_;
		}
		else
		{
			v8 = v7 - 1;
			v1->Rotation.x = v7 - 1;
			v9 = PurchasedItems[v7 - 1].Category;
			v10 = PurchasedItems[v8].Type;
			--PurchasedItemCount;
			v32 = v10;
			switch (v9)
			{
			case 1:
				if (AL_GetCurrGardenChaoCount() < 8)
				{
					v11 = (ChaoDataBase*)AL_GetNewChaoSaveInfo();
					InitChaoDNA(&a1);
					a1.field_1[0] = v32;
					if (v11)
					{
						v12 = CreateChaoEgg(&a1, v11, 0, &position, 3);
					}
					else
					{
						v12 = CreateChaoEgg(&a1, 0, 0, &position, 3);
					}
					if (v12)
					{
						MOV_SetVelo(v12, &output);
					}
					break;
				}
				++PurchasedItemCount;
				return;
			case 3:
				GardenFruit_Create(v10, &position, PlayerPtrs[0]->Data1->Rotation.y, &output, AL_GetNewItemSaveInfo(3));
				break;
			case 9:
				GardenHat_Create(v10, &position, PlayerPtrs[0]->Data1->Rotation.y, &output, AL_GetNewItemSaveInfo(9));
				break;
			default:
				goto LABEL_34;
			}

		LABEL_33:
			PurchasedItems[v8].Category = (ChaoItemCategory)-1;
		LABEL_34:
			if (v8 != PurchasedItemCount)
			{
				v27 = v8;
				if (v8 < PurchasedItemCount)
				{
					v28 = PurchasedItemCount - v8;
					v29 = PurchasedItemCount - v8;
					v30 = &PurchasedItems[v8 + 1];
					v31 = &PurchasedItems[v8];
					while (v28)
					{
						*v31 = *v30;
						++v30;
						++v31;
						--v28;
					}
					v27 = v8 + v29;
				}
				PurchasedItems[v27].Category = (ChaoItemCategory)-1;
			}
		}
	}
}

void al_kinder_bm_Init()
{
	//purchase item hack
	WriteCall((void*)0x00727D57, ReturnDummyItem); //makes sure the game doesnt allocate any space for the object
	WriteCall((void*)0x00727D8C, PurchaseItem);
	WriteData((char*)0x00727D3B, (char)0xEB); //hacks jump
	WriteCall((void*)0x00727D1F, CanIPurchase);

	//purchased items display
	WriteCall((void*)0x0072717B, DrawPurchasedItems_Hook);

	//purchased item display in garden too
	WriteCall((void*)0x007193F2, AlItemIconTaskExecHook);
	
	//spit out items hack
	WriteData((int*)0x007224C2, (int)sub_548F40);
}