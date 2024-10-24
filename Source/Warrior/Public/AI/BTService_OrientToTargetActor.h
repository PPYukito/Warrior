// PanutatR Right Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"

#include "BTService_OrientToTargetActor.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UBTService_OrientToTargetActor : public UBTService
{
	GENERATED_BODY()
	
	UBTService_OrientToTargetActor();

	//~ Begin UBTNode interface;
	virtual void InitializeFromAsset(UBehaviorTree& Asset) override;
	virtual FString GetStaticDescription() const override;
	//~ End UBTNode interface;

	//~ Begin UBTService interface;
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	//~ End UBTService interface;

	UPROPERTY(EditAnywhere, Category = "Target")
	FBlackboardKeySelector InTargetActorKey;

	UPROPERTY(EditAnywhere, Category = "Target")
	float RotationInterpSpeed;
};