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

// alt + enter ���� �� template ������ ����
// �ش� ������� �����͸� Ȯ���Ͽ� � ������ �ҷ������� 
template<class UserObject, typename CallbackFunc>
inline void UWarriorInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, 
ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	// ��ȿ���� ������ �ǵ������� ������ �߻����� ���α׷� �ߴ��ϵ��� üũ��
	// check�� ���� ���� �����ͷ� ����Ǵ°� ����� Ȯ���ϱ� �����
	// check(InInputConfig);
	// checkf : ����� ���� üũ�� ����� �̷�� ������ ����ϴ� �Լ��� Ȯ��
	checkf(InInputConfig, TEXT("Input config data asset is null,can not proceed with binding"));

	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		// EnhancedInputComponent�� �ִ� �Լ� (�ñ��ϸ� F12 go go)
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
	// ���ϰ� ������Ʈ ���ÿ��� InputComponent�� �����������
}