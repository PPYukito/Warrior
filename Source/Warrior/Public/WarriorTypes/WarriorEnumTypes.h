#pragma once

UENUM()
enum class EWarriorConfirmType : uint8
{
	Yes,
	No
};

UENUM()
enum class EWarriorValidType : uint8
{
	Valid,
	InValid
};

UENUM()
enum class EWarriorSuccessTypes : uint8
{
	Successful,
	Failed
};

UENUM()
enum class EWarriorCountDownActionInput : uint8
{
	Start,
	Cancel
};

UENUM()
enum class EWarriorCountDownActionOutput : uint8
{
	Updated,
	Completed,
	Cancel
};

UENUM(BlueprintType)
enum class EWarriorGameDifficulty : uint8
{
	Easy,
	Normal,
	Hard,
	Impossible
};

UENUM(BlueprintType)
enum class EWarriorInputMode : uint8
{
	GameOnly,
	UIOnly
};