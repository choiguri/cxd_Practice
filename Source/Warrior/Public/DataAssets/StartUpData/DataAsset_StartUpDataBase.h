// Vince Petrelli All Rights Reseced

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UWarriorGameplayAbility;
class UWarriorAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()
	
public:
	// ApplyLevel이 이 게임의 난이도가 될 수 있음
	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
	// 플레이어, 적 둘다 가질만한 기본적 데이터 설정

	// 활성화용 (스폰 등)
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray< TSubclassOf < UWarriorGameplayAbility > > ActivateOnGivenAbilities;

	// 리액트용 (사망, 피격 등등)
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray< TSubclassOf < UWarriorGameplayAbility > > ReactiveAbilities;

	// 어빌리티 부여 함수
	void GrantAbilities(const TArray< TSubclassOf < UWarriorGameplayAbility > >& InAbilitiesToGive, UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
};
