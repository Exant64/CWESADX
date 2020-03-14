#pragma once
#include "SADXModLoader.h"
#include "motiontable.h"
#include <random>
struct ChaoSetmedalThing
{
	char gap0[5500];
	short word157C;
};

struct ChaoSetmedalThing2
{
	char gap0[2256];
	ObjectMaster* dword8D0;
};
DataPointer(CHAO_GLOBAL, ChaoGlobal, 0x034BB9C0);
typedef ChaoData1 chaowk;
typedef int(__cdecl* BHV_FUNC)(ObjectMaster*);
#define BHVFunc(NAME, ADDRESS) FunctionPointer(int,NAME,(ObjectMaster*),ADDRESS);

enum
{
	ChaoBhavContinue,
	ChaoBhavFinished,
	ChaoBhavThinkController,
	ChaoBhavThinkActionDebug
};

void SwimControl(ObjectMaster* a1);
FunctionPointer(int, MOV_TurnToAim2, (ObjectMaster* a1, int a2), 0x00740160);
FunctionPointer(signed int, AL_MoveHoldingObject, (ObjectMaster* a1), 0x744600);
FunctionPointer(signed int, AL_EmotionAdd, (ObjectMaster* a1, EMOTION_ENUM a2, int a3), 0x00720030);
FunctionPointer(signed int, AL_EmotionGetValue, (ObjectMaster* a1, EMOTION_ENUM a2), 0x00720160);
FunctionPointer(void, AL_SetBehavior, (ObjectMaster* a1, signed int(__cdecl* a2)(ObjectMaster*)), 0x0071EF10);
FunctionPointer(void, AL_SetNextBehavior, (ObjectMaster* a1, signed int(__cdecl* a2)(ObjectMaster*)), 0x0071EF30);
FunctionPointer(void, AL_SetMotionLink, (ObjectMaster* a1, int a2), 0x00734F00);
FunctionPointer(void, AL_IconSet, (ObjectMaster* a1, int a2, int a3), 0x00736E90);
FunctionPointer(void, AL_FaceSetMouth, (ObjectMaster* a1, int a2, int a3), 0x00737190);
FunctionPointer(void, AL_FaceSetEye, (ObjectMaster* a1, int a2, int n), 0x007370A0);
FunctionPointer(void, AL_SetMotionLinkStep, (ObjectMaster* a1, int a2, unsigned __int16 a3), 0x00734F20);
FunctionPointer(int, MOV_SetAimPos, (ObjectMaster* a1, NJS_VECTOR* a2), 0x00740080);
FunctionPointer(bool, AL_IsHero2, (ObjectMaster* a1), 0x007306B0);
FunctionPointer(bool, AL_IsDark2, (ObjectMaster* a1), 0x007306F0);
FunctionPointer(int, AL_SetItem, (ObjectMaster* a1, int a2, NJS_CNK_OBJECT* model, NJS_TEXLIST* texlist), 0x00734AF0);
FunctionPointer(int, AL_SetItemOffset, (ObjectMaster* a1, int a2, AL_ITEM_INFO* pInfo), 0x00734B60);
FunctionPointer(void, AL_SetItemParallelLeftHand, (ObjectMaster* a1, NJS_CNK_OBJECT* a2, NJS_TEXLIST* a3), 0x00734C20);
FunctionPointer(ObjectMaster*, AL_GetFoundToyTask, (ObjectMaster* a1), 0x0073E6C0);
FunctionPointer(signed int, ALW_LockOn, (ObjectMaster* a1, ObjectMaster* a2), 0x71A380);
FunctionPointer(al_entry_work*, ALW_IsCommunicating, (ObjectMaster* retstr), 0x71A560);
FunctionPointer(void, AL_FixPosition, (ObjectMaster* a1), 0x00731D20);
FunctionPointer(int, MOV_SetVelo, (ObjectMaster* a1, NJS_VECTOR* a2), 0x0073FFE0);
FunctionPointer(void, AL_SetMotionSkip, (ObjectMaster* a1, int a2), 0x734F60);
FunctionPointer(bool, ALW_IsSheAttentionOtherOne, (ObjectMaster* a1, ObjectMaster* a2), 0x71A490);
FunctionPointer(signed int, ALW_CommunicationOn, (ObjectMaster* a1, ObjectMaster* a2), 0x71A4C0);
FunctionPointer(int, AL_SetIntervalTimer, (ObjectMaster* a1, unsigned __int16 a2, int a3), 0x73CF10);
FunctionPointer(double, AL_CalcScoreTypeA, (signed int value, signed int minimum), 0x0073CE10);
FunctionPointer(void, AL_CalcIntentionScore_JoinMusic, (ObjectMaster* a1, float* a2), 0x00761DA0);
FunctionPointer(void, AL_ScoreRandomize, (float* a1), 0x0073CEA0);
FunctionPointer(void, AL_CalcIntentionScore_Fear, (ObjectMaster* a1, float* a2), 0x0075E460);
FunctionPointer(bool, AL_IsMotionStop, (ObjectMaster* a1), 0x735040);
FunctionPointer(bool, AL_IsMotionEnd, (ObjectMaster* a1), 0x00735020);
FunctionPointer(void, AL_ForwardAcc, (ObjectMaster* a1, float a2), 0x00723F60);
FunctionPointer(void, AL_ForwardSpd, (ObjectMaster* a1, float a2), 0x00723F90);
FunctionPointer(void, AL_Brake, (ObjectMaster* tp, float brake), 0x00723FC0);

BHVFunc(ALBHV_OsanpoThrown, 0x71EB50)
BHVFunc(ALBHV_OdekakeEject, 0x71F0C0)
BHVFunc(ALBHV_SitSleep, 0x71F260)
BHVFunc(ALBHV_Akubi, 0x71F3E0)
BHVFunc(ALBHV_Tron, 0x71F630)
BHVFunc(ALBHV_Sleep, 0x71F920)
BHVFunc(ALBHV_SleepSelect, 0x71FED0)
BHVFunc(ALBHV_BornDamage, 0x738450)
BHVFunc(ALBHV_Damage, 0x738540)
BHVFunc(ALBHV_Thrown, 0x7387D0)
BHVFunc(ALBHV_Nade, 0x738B90)
BHVFunc(ALBHV_DakkoNormal, 0x738E70)
BHVFunc(ALBHV_DakkoDislike, 0x738EC0)
BHVFunc(ALBHV_DakkoLike, 0x739380)
BHVFunc(ALBHV_DakkoTron, 0x739510)
BHVFunc(ALBHV_Dakko, 0x7395D0)
BHVFunc(ALBHV_Capture, 0x739860)
BHVFunc(ALBHV_TurnToMinimal, 0x739C80)
BHVFunc(ALBHV_Eat, 0x739D80)
BHVFunc(ALBHV_PickUpLockOn, 0x73A7B0)
BHVFunc(ALBHV_GoToEat, 0x73A8A0)
BHVFunc(ALBHV_TurnToFruit, 0x73A920)
BHVFunc(ALBHV_HoldThink, 0x73AB20)
BHVFunc(ALBHV_WearObakeHead, 0x73ABB0)
BHVFunc(ALBHV_Throw, 0x73ACB0)
BHVFunc(ALBHV_TurnToObakeHead, 0x73AD80)
BHVFunc(ALBHV_Move, 0x73AF00)
BHVFunc(ALBHV_Koke, 0x73AF20)
BHVFunc(ALBHV_Climb, 0x73B030)
BHVFunc(ALBHV_Glide, 0x73B220)
BHVFunc(ALBHV_ChasePlayer, 0x73B370)
BHVFunc(ALBHV_NoticePlayer, 0x73B560)
BHVFunc(ALBHV_SwimObore, 0x73BD40)
BHVFunc(ALBHV_SwimBataashi, 0x73BE50)
BHVFunc(ALBHV_SwimCrawl, 0x73BED0)
BHVFunc(ALBHV_SwimSeoyogi, 0x73BF50)
BHVFunc(ALBHV_SwimPuha, 0x73BFD0)
BHVFunc(ALBHV_Swim, 0x73C110)
BHVFunc(ALBHV_BornPon, 0x73C320)
BHVFunc(ALBHV_BornKyoro, 0x73C360)
BHVFunc(ALBHV_Mayu, 0x73C890)
BHVFunc(ALBHV_Dead, 0x73CA70)
BHVFunc(ALBHV_Think, 0x73CCC0)
BHVFunc(ALBHV_Notice, 0x73D680)
BHVFunc(ALBHV_TurnToAim, 0x73D700)
BHVFunc(ALBHV_GoToAim, 0x73D750)
BHVFunc(ALBHV_TurnToLockOn, 0x73D850)
BHVFunc(ALBHV_Turn, 0x73D8E0)
BHVFunc(ALBHV_TurnRandom, 0x73D9F0)
BHVFunc(ALBHV_GoToLockOn, 0x73DB00)
BHVFunc(ALBHV_Touch, 0x73DBE0)
BHVFunc(ALBHV_Oshaburiburi, 0x7468F0)
BHVFunc(ALBHV_Tameiki, 0x75B440)
BHVFunc(ALBHV_MesoMeso, 0x75B4F0)
BHVFunc(ALBHV_Cry, 0x75B6C0)
BHVFunc(ALBHV_Sorrow, 0x75B870)
BHVFunc(ALBHV_PostureChangeStand, 0x75B980)
BHVFunc(ALBHV_PostureChangeSit, 0x75BA10)
BHVFunc(ALBHV_HaiHai, 0x75BC70)
BHVFunc(ALBHV_WalkNormal, 0x75BD00)
BHVFunc(ALBHV_Run, 0x75BDC0)
BHVFunc(ALBHV_Run2, 0x75BEB0)
BHVFunc(ALBHV_JumpToPond, 0x75BFE0)
BHVFunc(ALBHV_GoToWater, 0x75C0A0)
BHVFunc(ALBHV_NyokiNyoki, 0x75C0D0)
BHVFunc(ALBHV_Jyouro, 0x75C1C0)
BHVFunc(ALBHV_ApproachToJyouro, 0x75C3D0)
BHVFunc(ALBHV_Rest, 0x75C4E0)
BHVFunc(ALBHV_Nest, 0x75C810)
BHVFunc(ALBHV_ApproachNest, 0x75CB60)
BHVFunc(ALBHV_Greet, 0x75CF80)
BHVFunc(ALBHV_CalcMeetPlayer, 0x75D010)
BHVFunc(ALBHV_SuriSuri, 0x75D030)
BHVFunc(ALBHV_SuriSuriPlayer, 0x75D0F0)
BHVFunc(ALBHV_Anger, 0x75D4C0)
BHVFunc(ALBHV_Genkotu, 0x75D590)
BHVFunc(ALBHV_Kick, 0x75D600)
BHVFunc(ALBHV_Punch, 0x75D670)
BHVFunc(ALBHV_PokaPoka, 0x75D6E0)
BHVFunc(ALBHV_Akanbe, 0x75D750)
BHVFunc(ALBHV_AttackPlayer, 0x75D7B0)
BHVFunc(ALBHV_Pleasure, 0x75DB80)
BHVFunc(ALBHV_Pain, 0x75DE10)
BHVFunc(ALBHV_Awawa, 0x75E0C0)
BHVFunc(ALBHV_RunawayFromPlayer, 0x75E2C0)
BHVFunc(ALBHV_WatchTV, 0x75E6C0)
BHVFunc(ALBHV_ListenRadicase, 0x75E890)
BHVFunc(ALBHV_JumpFromHorse, 0x75EA60)
BHVFunc(ALBHV_RideHorse, 0x75EAF0)
BHVFunc(ALBHV_GoToTV, 0x75EDA0)
BHVFunc(ALBHV_GoToRadicase, 0x75EE50)
BHVFunc(ALBHV_GoToOrgan, 0x75EF00)
BHVFunc(ALBHV_GoToHorse, 0x75EF20)
BHVFunc(ALBHV_GoToBox, 0x75EFA0)
BHVFunc(ALBHV_Sing1, 0x75F370)
BHVFunc(ALBHV_Sing2, 0x75F4E0)
BHVFunc(ALBHV_Sing3, 0x75F670)
BHVFunc(ALBHV_Sing4, 0x75F800)
BHVFunc(ALBHV_Sing5, 0x75F990)
BHVFunc(ALBHV_SingNormal, 0x75FD20)
BHVFunc(ALBHV_SingOnchi, 0x75FEB0)
BHVFunc(ALBHV_ListenSing, 0x75FFF0)
BHVFunc(ALBHV_Urusai, 0x760120)
BHVFunc(ALBHV_FuriFuriDance, 0x7606C0)
BHVFunc(ALBHV_KuruKuruDance, 0x760790)
BHVFunc(ALBHV_BoxDance, 0x760860)
BHVFunc(ALBHV_GoGoDance, 0x7608C0)
BHVFunc(ALBHV_RadioDance, 0x760960)
BHVFunc(ALBHV_WatchDance, 0x760AD0)
BHVFunc(ALBHV_WatchDanceStand, 0x760C00)
BHVFunc(ALBHV_Maracas, 0x761050)
BHVFunc(ALBHV_Bell, 0x761230)
BHVFunc(ALBHV_Drum, 0x761330)
BHVFunc(ALBHV_Fue, 0x761560)
BHVFunc(ALBHV_Castanets, 0x761670)
BHVFunc(ALBHV_Rappa, 0x761830)
BHVFunc(ALBHV_Cymbal, 0x761960)
BHVFunc(ALBHV_Tambourine, 0x761AF0)
BHVFunc(ALBHV_ListenMusic, 0x761C70)
BHVFunc(ALBHV_GoToPlayerPleasure, 0x761F60)
BHVFunc(ALBHV_NeedFruit, 0x762070)
BHVFunc(ALBHV_Goo, 0x762140)
BHVFunc(ALBHV_HungryDada, 0x7622B0)
BHVFunc(ALBHV_Seki, 0x762610)
BHVFunc(ALBHV_Kusyami, 0x762790)
BHVFunc(ALBHV_Kayui, 0x7628D0)
BHVFunc(ALBHV_Hanamizu, 0x7629E0)
BHVFunc(ALBHV_Syakkuri, 0x762B20)
BHVFunc(ALBHV_Haraita, 0x762C80)
BHVFunc(ALBHV_Syabon, 0x763050)
BHVFunc(ALBHV_Houki, 0x763260)
BHVFunc(ALBHV_Garagara, 0x763300)
BHVFunc(ALBHV_Hanabi, 0x7633A0)
BHVFunc(ALBHV_Book, 0x763610)
BHVFunc(ALBHV_Minicar, 0x763760)
BHVFunc(ALBHV_Doll, 0x763910)
BHVFunc(ALBHV_Hopping, 0x7639E0)
BHVFunc(ALBHV_Kaoarau, 0x763B20)
BHVFunc(ALBHV_Bakuten, 0x763BB0)
BHVFunc(ALBHV_Draming, 0x763C00)
BHVFunc(ALBHV_BreakDance, 0x763D70)
BHVFunc(ALBHV_GoGoDanceMini, 0x763DC0)
BHVFunc(ALBHV_Dosukoi, 0x763E10)
BHVFunc(ALBHV_InoDash, 0x763EA0)
BHVFunc(ALBHV_Otakai, 0x763FC0)
BHVFunc(ALBHV_ShiriDance, 0x764060)
BHVFunc(ALBHV_BoxDanceDX, 0x7640E0)
BHVFunc(ALBHV_Onara, 0x764160)
BHVFunc(ALBHV_Fire, 0x7642E0)
BHVFunc(ALBHV_PyonPyon, 0x7643B0)
BHVFunc(ALBHV_Fukkin2, 0x764440)
BHVFunc(ALBHV_Fukkin, 0x7644D0)
BHVFunc(ALBHV_Denguri, 0x764500)
BHVFunc(ALBHV_GoroGoro, 0x7645B0)
BHVFunc(ALBHV_HaraSuberi, 0x764660)
BHVFunc(ALBHV_Shippo, 0x764700)
BHVFunc(ALBHV_Art, 0x76E890)

void Chao_Init();
