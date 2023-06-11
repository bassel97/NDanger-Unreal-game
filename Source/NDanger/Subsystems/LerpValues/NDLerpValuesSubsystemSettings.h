// Created by Bassel Mostafa https://bassel97.github.io/

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "NDLerpValuesSubsystemSettings.generated.h"

/**
 * 
 */
UCLASS(Config = Game, defaultconfig, meta = (DisplayName = "Lerp Values Subsystem Settings"))
class NDANGER_API UNDLerpValuesSubsystemSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Lerp Values")
	float GlobalLerpSpeed = 1.0f;
};
