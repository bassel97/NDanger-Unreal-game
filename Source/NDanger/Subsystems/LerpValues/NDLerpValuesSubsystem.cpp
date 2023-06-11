// Created by Bassel Mostafa https://bassel97.github.io/

#include "NDLerpValuesSubsystem.h"
#include "NDLerpValues.h"
#include "NDLerpValuesSubsystemSettings.h"

TStatId UNDLerpValuesSubsystem::GetStatId() const
{
	return Super::GetStatID();
}

void UNDLerpValuesSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (TSharedPtr<LerpedValue<float>>& LerpedFloat : LerpedFloats)
	{
		if (LerpedFloat.IsValid())
		{
			LerpedFloat.Get()->UpdateValue(DeltaTime);
		}
	}
}

TWeakPtr<LerpedValue<float>> UNDLerpValuesSubsystem::CreateLerpedFloat(float LerpSpeedMultiplier /*= 1.0f*/)
{
	return LerpedFloats.Add_GetRef(MakeShared<LerpedValue<float>>(
			GetDefault<UNDLerpValuesSubsystemSettings>()->GlobalLerpSpeed * LerpSpeedMultiplier)
		);
}