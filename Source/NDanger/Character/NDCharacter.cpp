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


	// Handling rotation logic
	//The rotation direction is only equal to the movement direction if we aim is zero. 
	const float DiscreteXAimValue = FMath::Floor(AimValue.X + 0.5f);
	const float CharacterXDirection = (DiscreteXAimValue == 0) ? MoveXValue : DiscreteXAimValue;
	const FRotator CharacterFacingRotator = GetCharacterFacingRotator(CharacterXDirection);
	FaceRotation(CharacterFacingRotator);


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

FRotator ANDCharacter::GetCharacterFacingRotator(float DirectionWorldX)
{
	// #TODO(Bassel): Remove magic numbers from code
	return FRotator(0, -DirectionWorldX * 90.0f + 180.0f, 0);
}