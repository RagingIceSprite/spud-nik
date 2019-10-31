// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WallHugSpline.generated.h"

UENUM(BlueprintType)
enum class ESplineShape : uint8
{
	SS_Circle UMETA(DisplayName="Circle"),
	SS_Rectangle UMETA(DisplayName="Rectangle"),
	SS_Custom UMETA(DisplayName="Manual")
};

UCLASS()
class SPUDNIK_POCT_API UWallHugSpline : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintPure)
	static void MakeCircleSpline(float radius, TArray<FVector> &splinePoints, TArray<FVector> &tangentPoints);

	UFUNCTION(BlueprintPure)
	static void MakeRectangleSpline(float xSize, float ySize, float borderRadius, TArray<FVector> &splinePoints, TArray<FVector> &tangentPoints);
};