// Fill out your copyright notice in the Description page of Project Settings.


#include "WallHugSpline.h"
#include "Math/UnrealMathUtility.h"

void UWallHugSpline::MakeCircleSpline(float radius, TArray<FVector>& splinePoints, TArray<FVector>& tangentPoints)
{
	float circleConstant = ((4.0f * (FMath::Sqrt(2.0f) - 1.0f)) / 3.0f) + 1.0f;

	splinePoints.Add(FVector(radius, 0.0f, 0.0f));
	splinePoints.Add(FVector(0.0f, radius, 0.0f));
	splinePoints.Add(FVector(-radius, 0.0f, 0.0f));
	splinePoints.Add(FVector(0.0f, -radius, 0.0f));

	tangentPoints.Add(FVector(0.0f, radius * circleConstant, 0.0f));
	tangentPoints.Add(FVector(-radius * circleConstant, 0.0f, 0.0f));
	tangentPoints.Add(FVector(0.0f, -radius * circleConstant, 0.0f));
	tangentPoints.Add(FVector(radius * circleConstant, 0.0f, 0.0f));
}

void UWallHugSpline::MakeRectangleSpline(float xSize, float ySize, float borderRadius, TArray<FVector>& splinePoints, TArray<FVector>& tangentPoints)
{
	float circleConstant = ((4.0f * (FMath::Sqrt(2.0f) - 1.0f)) / 3.0f) + 1.0f;
	float halfX = xSize / 2.0f;
	float halfY = ySize / 2.0f;

	borderRadius = FMath::Clamp(borderRadius, 0.0f, halfX);

	splinePoints.Add(FVector(0.0f, -halfY, 0.0f));
	splinePoints.Add(FVector(halfX - borderRadius, -halfY, 0.0f));
	splinePoints.Add(FVector(halfX, -halfY + borderRadius, 0.0f));
	splinePoints.Add(FVector(halfX, 0.0f, 0.0f));
	splinePoints.Add(FVector(halfX, halfY - borderRadius, 0.0f));
	splinePoints.Add(FVector(halfX - borderRadius, halfY, 0.0f));
	splinePoints.Add(FVector(0.0f, halfY, 0.0f));
	splinePoints.Add(FVector(-halfX + borderRadius, halfY, 0.0f));
	splinePoints.Add(FVector(-halfX, halfY - borderRadius, 0.0f));
	splinePoints.Add(FVector(-halfX, 0.0f, 0.0f));
	splinePoints.Add(FVector(-halfX, -halfY + borderRadius, 0.0f));
	splinePoints.Add(FVector(-halfX + borderRadius, -halfY, 0.0f));
	
	for (int32 i = 0; i < 12; i++)
	{
		float sign;
		if (i == 11 || (i >= 0 && i <= 4))
		{
			sign = 1.0f;
			if (i % 3 == 0)
				tangentPoints.Add(FVector(
					(i % 2 == 0) ? (halfX - borderRadius) * sign : 0.0f,
					(i % 2 == 0) ? 0.0f : (halfY - borderRadius) * sign,
					0.0f
				));
			else
				tangentPoints.Add(FVector(
					(i % 2 == 0) ? 0.0f : borderRadius * circleConstant * sign,
					(i % 2 == 0) ? borderRadius * circleConstant * sign : 0.0f,
					0.0f
				));
		}
		else
		{
			sign = -1.0f;
			if (i % 3 == 0)
				tangentPoints.Add(FVector(
					(i % 2 == 0) ? (halfX - borderRadius) * sign : 0.0f,
					(i % 2 == 0) ? 0.0f : (halfY - borderRadius) * sign,
					0.0f
				));
			else
				tangentPoints.Add(FVector(
					(i % 2 == 0) ? 0.0f : borderRadius * circleConstant * sign,
					(i % 2 == 0) ? borderRadius * circleConstant * sign : 0.0f,
					0.0f
				));
		}
	}
}
