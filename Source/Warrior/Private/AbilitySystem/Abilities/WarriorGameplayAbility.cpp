// Vince Petrelli All Rights Reseced


#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"

void UWarriorGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	/*
	매개변수 const FGameplayAbilityActorInfo* ActorInfo

	ActorInfo를 가보면 다양한 정보들이 저장되어 있어서 
	해당 정보들을 유용하게 사용 가능함
	*/

	// Given 형식 설정 해둠
	if (AbilityActivationPolicy == EWarriorAbilityActivationPolicy::OnGiven)
	{
		// 해당 유저의 정보 & 스펙(레벨, 능력치 인벤토리 등등)이 활성화 안되어 있으면 활성화 시키기
		if (ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

void UWarriorGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (AbilityActivationPolicy == EWarriorAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
}
