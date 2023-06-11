// Created by Bassel Mostafa https://bassel97.github.io/

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "NDLerpValues.h"
#include "NDLerpValuesSubsystem.generated.h"

/**
 * This subsystem is responsible for keeping track of all LerpedValues and updating them.
 */
UCLASS()
class NDANGER_API UNDLerpValuesSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()
	
public:
	TStatId GetStatId() const override;
	virtual void Tick(float DeltaTime) override;

	TWeakPtr<LerpedValue<float>> CreateLerpedFloat(float LerpSpeedMultiplier = 1.0f);

private:
	TSharedPtr<LerpedValue<float>> t;
	TArray<TSharedPtr<LerpedValue<float>>> LerpedFloats;
};
