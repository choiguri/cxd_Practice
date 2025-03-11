// Vince Petrelli All Rights Reserved
#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"

/**
 *
 */
UCLASS()
class WARRIOR_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserObject, typename CallbackFunc>

	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, 
		ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);
};

// alt + enter 했을 때 template 만들기로 만듦
// 해당 방식으로 포인터를 확인하여 어떤 이유로 불려졌는지 
template<class UserObject, typename CallbackFunc>
inline void UWarriorInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, 
ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	// 유효하지 않으면 의도적으로 오류를 발생시켜 프로그램 중단하도록 체크함
	// check로 했을 때는 포인터로 실행되는건 제대로 확인하기 어려움
	// check(InInputConfig);
	// checkf : 출력을 통해 체크가 제대로 이루어 졌는지 출력하는 함수로 확인
	checkf(InInputConfig, TEXT("Input config data asset is null,can not proceed with binding"));

	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		// EnhancedInputComponent에 있는 함수 (궁금하면 F12 go go)
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
	// 다하고 프로젝트 세팅에서 InputComponent를 변경해줘야함
}