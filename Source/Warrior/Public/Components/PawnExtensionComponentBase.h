// Vince Petrelli All Rights Reseced

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARRIOR_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	// 컴포넌트의 소유권 주장하는데 쓰임
	// 특정 버전으로 사용해야 하는 경우 실행(영웅, 적)
	template <class T>
	T* GetOwningPawn() const
	{	
		static_assert(TPointerIsConvertibleFromTo<T,APawn>::Value,"'T' Template Parameter to GetPawn must be derived from APawn");
		return CastChecked<T>(GetOwner());
	}

	// 기본 버전 실행
	APawn* GetOwningPawn() const
	{
		return GetOwningPawn<APawn>();
	}


	// 이건 컨트롤러 소유권 확인용
	template <class T>
	T* GetOwningController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T,AController>::Value,"'T' Template Parameter to GetController must be derived from AController");
		return GetOwningPawn<APawn>()->GetController<T>();
	}
};
