// PanutatR Right Reserved.


#include "Components/Combat/EnemyCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "WarriorGameplayTags.h"
#include "WarriorFunctionLibrary.h"

#include "WarriorDebugHelper.h"

void UEnemyCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	/*if (HitActor)
	{
		Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT(" is hitting") + HitActor->GetActorNameOrLabel());
	}*/

	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}

	OverlappedActors.AddUnique(HitActor);

	bool bIsValidBlock = false;

	const bool bIsPlayerBlocking = UWarriorFunctionLibrary::NativeDoesActorHaveTag(HitActor, WarriorGameplayTags::Player_Status_Blocking);
	const bool bIsMyAttackUnblockable = UWarriorFunctionLibrary::NativeDoesActorHaveTag(GetOwningPawn(), WarriorGameplayTags::Enemy_Status_UnBlockable);

	if (bIsPlayerBlocking && !bIsMyAttackUnblockable)
	{
		// todo :: check if block is valid;
		bIsValidBlock = UWarriorFunctionLibrary::IsValidBlock(GetOwningPawn(), HitActor);
	}

	FGameplayEventData EventData;
	EventData.Instigator = GetOwningPawn();
	EventData.Target = HitActor;

	if (bIsValidBlock)
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
			HitActor,
			WarriorGameplayTags::Player_Event_SucessfulBlock,
			EventData
		);
	}
	else
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
			GetOwningPawn(),
			WarriorGameplayTags::Shared_Event_MeleeHit,
			EventData
		);
	}
}