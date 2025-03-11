// Vince Petrelli All Rights Reseced


#include "AnimInstances/Hero/WarriorHeroAnimInstance.h"
#include "Characters/WarriorHeroCharacter.h"

void UWarriorHeroAnimInstance::NativeInitializeAnimation()
{
	// 이번에는 자체 함수를 재정의하기 때문에 Super를 호출해야함
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AWarriorHeroCharacter>(OwningCharacter);
	}
}

void UWarriorHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	// 이번에는 자체 함수를 재정의하기 때문에 Super를 호출해야함
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (bHasAcceleration)
	{
		IdleElpasedTime = 0.f;

		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElpasedTime += DeltaSeconds;

		bShouldEnterRelaxState = (IdleElpasedTime >= EnterRelaxtStateThreshold);
	}
}
