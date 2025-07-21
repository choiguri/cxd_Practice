// Vince Petrelli All Rights Reseced

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "DataAsset_InputConfig.generated.h"

class UInputAction;
class UInputMappingContext;

// 움직임 관련 데이터 입력 관리할 총괄 데이터셋
USTRUCT(BlueprintType)
struct FWarriorInputActionConfig
{
	GENERATED_BODY()	// 해당 매크로를 안 넣어두면 컴파일 안됨

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputAction;
	// Enhancedinput 쓸거면 Module 에 추가하기 
};
/**
 *
 */
UCLASS()
class WARRIOR_API UDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FWarriorInputActionConfig> NativeInputActions;

	UInputAction* FindNativeInputActionByTag(const FGameplayTag& InInputTag) const;
	// 마지막 const 넣은 이유 : 상수 멤버 변수를 변경하지 않겠다는 보장을 해주기 위해
	// InputConfig가 const 포인터일 경우, const 함수만 호출 가능
	// 이로 인해서 코드 안정성과 신뢰성 증가
};
