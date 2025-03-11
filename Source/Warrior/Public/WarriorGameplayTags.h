// Vince Petrelli All Rights Reseced

#pragma once

#include "NativeGameplayTags.h"

namespace WarriorGameplayTags
{
	// 게임플레이 태그를 사용하려면 매크로에 해당 프로젝트 이름 밑줄을 사용해야함
	// 해당 매크로는 다른 모듈에서 이러한 게임플레이 태그 접근성을 보장
	// Build.cs에 GameplayTags 추가하기

	/** Input Tags **/
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move)
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look)
}