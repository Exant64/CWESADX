#include "stdafx.h"
#include "chao.h"
#include "al_knowledge.h"

void AL_KW_Control(ObjectMaster *a1)
{
	ChaoData1* data1 = (ChaoData1*)a1->Data1;
	if(data1->pParamGC->KnowledgeBTL.KwTimer++ >= 10)
	{
		data1->pParamGC->KnowledgeBTL.KwTimer = 0;
		for(int i =0; i < 6; i++)
		{
			data1->pParamGC->KnowledgeBTL.player[i].distance += 6;
			if (data1->pParamGC->KnowledgeBTL.player[i].distance > 50000) data1->pParamGC->KnowledgeBTL.player[i].distance = 50000;
			data1->pParamGC->KnowledgeDX.player[i].distance += 6;
			if (data1->pParamGC->KnowledgeDX.player[i].distance > 50000) data1->pParamGC->KnowledgeDX.player[i].distance = 50000;
		}
		for (int i = 0; i < 20; i++)
		{
			data1->pParamGC->KnowledgeBTL.chao[i].distance += 6;
			if (data1->pParamGC->KnowledgeBTL.chao[i].distance > 50000) data1->pParamGC->KnowledgeBTL.chao[i].distance = 50000;
		}
	}
}