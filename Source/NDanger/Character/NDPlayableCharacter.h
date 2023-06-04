// Created by Bassel Mostafa https://bassel97.github.io/

#pragma once

#include "CoreMinimal.h"
#include "NDCharacter.h"
#include "NDPlayableCharacter.generated.h"

UCLASS()
class NDANGER_API ANDPlayableCharacter : public ANDCharacter
{
	GENERATED_BODY()

public:
	ANDPlayableCharacter();
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PawnClientRestart() override;

protected:
	virtual void BeginPlay() override;

private:
	void MoveDirectionIAHandler(const struct FInputActionValue& Value);
	void AimDirectionIAHandler(const struct FInputActionValue& Value);
	void JumpStartIAHandler();
	void JumpStopIAHandler();

private:
	UPROPERTY(Category = "NDCharacter Actions", EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* PlayerActionsInputContext;
	
	UPROPERTY(Category = "NDCharacter Actions", EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	class UInputAction* AimDirectionIA;

	UPROPERTY(Category = "NDCharacter Actions", EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveDirectionIA;

	UPROPERTY(Category = "NDCharacter Actions", EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpIA;
};