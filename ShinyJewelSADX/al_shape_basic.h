#pragma once
#include <SADXModLoader.h>

struct  ChaoToyChunk
{
	NJS_OBJECT* model;
	NJS_TEXLIST* texlist;
	float scale;
	int exists;
};


struct JiggleFactor
{
	NJS_VECTOR jiggleValue;
	NJS_VECTOR someVector;
};




struct BasicObjectPointerModel
{
	NJS_MODEL_SADX model;
	
};

struct BasicObjectPointer
{
	NJS_OBJECT base;
	BasicObjectPointer* parent;
	NJS_VECTOR differenceOrigOther;
	int field_44;
	int field_48;
	int field_4C;
	NJS_VECTOR originalPosition;
	NJS_VECTOR field_5C;
	float field_68;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	int field_88;
	int field_8C;
	int field_90;
	NJS_OBJECT* animalPart;
	ChaoToyChunk toy;
	int useTransform;
	NJS_VECTOR position;
	Rotation3 rotation;
	NJS_MATRIX_PTR Matrix;
	void* field_C8;
	int field_CC;
};


void Chao_LoadModels(ObjectMaster* a1);


void __cdecl sub_767790(ObjectMaster* a1);

void __cdecl DeleteChunkObjectPointer(BasicObjectPointer* a1);

void __cdecl Chao_SetVertexColor(BasicObjectPointer* a1, NJS_BGRA a2);
