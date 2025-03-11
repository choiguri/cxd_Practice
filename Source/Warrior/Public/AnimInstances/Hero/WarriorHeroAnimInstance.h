// Vince Petrelli All Rights Reseced

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorCharacterAnimInstance.h"
#include "WarriorHeroAnimInstance.generated.h"


class AWarriorHeroCharacter;
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorHeroAnimInstance : public UWarriorCharacterAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds);

protected:

	// 캐릭터 데이터 가져오기
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|References")
	AWarriorHeroCharacter* OwningHeroCharacter;

	// Relax 상태
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bShouldEnterRelaxState;

	// Relax 상태 돌입할 딜레이 시간
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float EnterRelaxtStateThreshold = 5.f;

	// Idle 상태 유지 시간 추적 변수
	float IdleElpasedTime;

};
