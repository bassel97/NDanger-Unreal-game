// Created by Bassel Mostafa https://bassel97.github.io/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NDCharacter.generated.h"

UCLASS()
class NDANGER_API ANDCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ANDCharacter();

	virtual void Tick(float DeltaTime) override;

protected:
	/** Gets the character rotator corresponding to a specific value. */
	FRotator GetCharacterFacingRotator(float DirectionWorldX);

protected:
	// Replace with a lerped float
	float MoveXValue = 0.0f;

	FVector2D AimValue = FVector2D::ZeroVector;
	
	/** True the frame the character starts jumping. */
	bool bStartJump = false;
	/** True the frame the character stops jumping. */
	bool bStopJump = false;
	/** True when the character is jumping. */
	bool bIsJumping = false;
};