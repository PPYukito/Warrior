// PanutatR Right Reserved.


#include "Components/UI/EnemyUIComponent.h"
#include "Widgets/WarriorWidgetBase.h"

void UEnemyUIComponent::RegisterEnemyDrawingWidget(UWarriorWidgetBase* InWidgetToRegister)
{
	EnemyDrawingWidgets.Add(InWidgetToRegister);
}

void UEnemyUIComponent::RemoveEnemyDrawingWidgetIfAny()
{
	if (EnemyDrawingWidgets.IsEmpty())
	{
		return;
	}

	for (UWarriorWidgetBase* DrawingWidget : EnemyDrawingWidgets)
	{
		if (DrawingWidget)
		{
			DrawingWidget->RemoveFromParent();
		}
	}

	EnemyDrawingWidgets.Empty();
}
