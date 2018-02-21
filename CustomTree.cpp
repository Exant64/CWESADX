#include "stdafx.h"
#include "CustomTree.h"

void Tree_Load(ObjectMaster *a1) 
{
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))Tree_Main;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))Tree_Display;
}

DataPointer(NJS_OBJECT, treeleaves, 0x36087EC);
FunctionPointer(void, sub_408530, (NJS_OBJECT *a1), 0x408530);
DataPointer(NJS_CNK_OBJECT, ChaoFruitModel9, 0x33BBFF4);

void Tree_Display(ObjectMaster *a1)
{
	EntityData1 *boi;

	boi = a1->Data1;

	njPushMatrixEx();
	njSetTexture(&AL_DX_OBJ_CMN_TEXLIST);
	
	njTranslate(0, boi->Position.x, boi->Position.y, boi->Position.z);
	DrawModel((NJS_MODEL_SADX*)0x036087C0);

	njTranslateV(0, (NJS_VECTOR*)treeleaves.child->pos);
	DrawModel((NJS_MODEL_SADX*)treeleaves.child->model);

	njPopMatrixEx();

	njPushMatrixEx();
	njSetTexture(&CHAO_OBJECT_TEXLIST);
	
	njTranslate(0, boi->Position.x, boi->Position.y + 10, boi->Position.z);
	njCnkDrawObject(&ChaoFruitModel9);
	njPopMatrixEx();

}
void Tree_Main(ObjectMaster *a1)
{
	a1->DisplaySub(a1);
}
