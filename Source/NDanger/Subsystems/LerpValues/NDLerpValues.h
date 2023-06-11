// Created by Bassel Mostafa https://bassel97.github.io/

#pragma once

#include "Kismet/GameplayStatics.h"

// Choosing to keep it as a template class instead of a virtual class to save the V-Table
// size for each created variable.
// Repeated code on the other hand can be replaced by #define
template<typename T>
class LerpedValue
{
public:
	LerpedValue(/*const UObject* WorldContextObject*/) {}
	LerpedValue(float OverrideGlobalLerpSpeed) { GlobalLerpSpeed = OverrideGlobalLerpSpeed; }

	inline T GetValue() const { return Value; }
	inline void UpdateValue(float DeltaTime) {}
	inline void operator=(const T& NewTarget) { Target = NewTarget; }
	operator T() const { return Value; }

private:
	T Value;
	T Target;

	float GlobalLerpSpeed;
};

/************************************** Float class functions ****************************/
LerpedValue<float>::LerpedValue()
{
	Value = 0.0f;
	Target = 0.0f;
}
LerpedValue<float>::LerpedValue(float OverrideGlobalLerpSpeed)
{ 
	GlobalLerpSpeed = OverrideGlobalLerpSpeed;
	Value = 0.0f;
	Target = 0.0f;
}

inline void LerpedValue<float>::UpdateValue(float DeltaTime)
{
	Value = FMath::Lerp(Value, Target, DeltaTime * GlobalLerpSpeed);
}
/************************************** Float class functions ****************************/