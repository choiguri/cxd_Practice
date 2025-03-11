// Vince Petrelli All Rights Reseced

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorBaseAnimInstance.h"
#include "WarriorCharacterAnimInstance.generated.h"

class AWarriorBaseCharacter;
class UCharacterMovementComponent;
/**
 *
 */
UCLASS()
class WARRIOR_API UWarriorCharacterAnimInstance : public UWarriorBaseAnimInstance
{
	GENERATED_BODY()

public:
	// Animinstance 에서 컨트롤 T로 검색해보면 빈 함수들임
	// 걔 중에 NativeThreadSafeUpdateAnimation은 주석을 확인해보면 
	// worker thread에서 관리하는걸 알 수 있어서 더 유용한 함수이다.
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds);

protected:
	UPROPERTY()
	AWarriorBaseCharacter* OwningCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAcceleration;

};