// Created by Bassel Mostafa https://bassel97.github.io/

#include "NDPlayableCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ANDPlayableCharacter::ANDPlayableCharacter()
{
 	PrimaryActorTick.bCanEverTick = true;

}

void ANDPlayableCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANDPlayableCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* PlayerEnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (ensureMsgf(MoveDirectionIA, TEXT("MoveDirectionIA is not set")))
		{
			PlayerEnhancedInputComponent->BindAction(MoveDirectionIA, ETriggerEvent::Started, this, &ANDPlayableCharacter::MoveDirectionIAHandler);
			PlayerEnhancedInputComponent->BindAction(MoveDirectionIA, ETriggerEvent::Triggered, this, &ANDPlayableCharacter::MoveDirectionIAHandler);
			PlayerEnhancedInputComponent->BindAction(MoveDirectionIA, ETriggerEvent::Completed, this, &ANDPlayableCharacter::MoveDirectionIAHandler);
		}
		if (ensureMsgf(AimDirectionIA, TEXT("AimDirectionIA is not set")))
		{
			PlayerEnhancedInputComponent->BindAction(AimDirectionIA, ETriggerEvent::Started, this, &ANDPlayableCharacter::AimDirectionIAHandler);
			PlayerEnhancedInputComponent->BindAction(AimDirectionIA, ETriggerEvent::Triggered, this, &ANDPlayableCharacter::AimDirectionIAHandler);
			PlayerEnhancedInputComponent->BindAction(AimDirectionIA, ETriggerEvent::Completed, this, &ANDPlayableCharacter::AimDirectionIAHandler);
		}
		if (ensureMsgf(JumpIA, TEXT("JumpIA is not set")))
		{
			PlayerEnhancedInputComponent->BindAction(JumpIA, ETriggerEvent::Started, this, &ANDPlayableCharacter::JumpStartIAHandler);
			PlayerEnhancedInputComponent->BindAction(JumpIA, ETriggerEvent::Completed, this, &ANDPlayableCharacter::JumpStopIAHandler);
		}
	}
}

void ANDPlayableCharacter::PawnClientRestart()
{
	Super::PawnClientRestart();

	APlayerController* PC = Cast<APlayerController>(GetController());
	UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem =
		PC ? ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()) : nullptr;

	if (ensureMsgf(EnhancedInputSubsystem,TEXT("EnhancedInputSubsystem not set"))
		&& ensureMsgf(PlayerActionsInputContext, TEXT("PlayerActionsInputContext not set")))
	{
		EnhancedInputSubsystem->ClearAllMappings();
		EnhancedInputSubsystem->AddMappingContext(PlayerActionsInputContext, 1);
	}
}

void ANDPlayableCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANDPlayableCharacter::MoveDirectionIAHandler(const FInputActionValue& Value)
{
	MoveXValue = Value.Get<FVector2D>().X;
}

void ANDPlayableCharacter::AimDirectionIAHandler(const FInputActionValue& Value)
{
	AimValue = Value.Get<FVector2D>();
}

void ANDPlayableCharacter::JumpStartIAHandler()
{
	bStartJump = true;
}

void ANDPlayableCharacter::JumpStopIAHandler()
{
	bStopJump = true;
}