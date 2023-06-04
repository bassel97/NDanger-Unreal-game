// Created by Bassel Mostafa https://bassel97.github.io/

#include "NDCharacter.h"

ANDCharacter::ANDCharacter()
{
 	PrimaryActorTick.bCanEverTick = true;
}

void ANDCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Handling movement logic
	AddMovementInput(FVector(0, MoveXValue, 0));
	FaceRotation(GetCharacterFacingRotator(MoveXValue));

	// Handling Jumping logic
	if (bStartJump)
	{
		Jump();
		bIsJumping = true;
	}
	if (bStopJump)
	{
		StopJumping();
		bIsJumping = false;
	}
	bStartJump = false;
	bStopJump = false;
}

FRotator ANDCharacter::GetCharacterFacingRotator(float Value)
{
	return FRotator(0, - Value * 90.0f + 180.0f, 0);
}