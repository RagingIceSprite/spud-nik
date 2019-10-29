// Fill out your copyright notice in the Description page of Project Settings.


#include "WallHugSpline.h"
#include "Components/SceneComponent.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AWallHugSpline::AWallHugSpline()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mCircleConstant = ((4.0f * (FMath::Sqrt(2.0f) - 1.0f)) / 3.0f) + 1.0f;

	USceneComponent *sceneRoot = CreateDefaultSubobject<USceneComponent>(FName(TEXT("Scene")));
	SetRootComponent(sceneRoot);

	mSpline = CreateDefaultSubobject<USplineComponent>(FName(TEXT("Spline")));
	mSpline->SetupAttachment(sceneRoot);

	if (bIsCircle || bIsRect)
		mSpline->SetClosedLoop(true);

	mBox = CreateDefaultSubobject<UBoxComponent>(FName(TEXT("Box")));
	mBox->SetupAttachment(sceneRoot);

	if (bIsCircle)
		MakeCircleSpline(radius);
	else if (bIsRect)
		MakeRectangle(xSize, ySize, borderRadius);
}

// Called when the game starts or when spawned
void AWallHugSpline::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWallHugSpline::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWallHugSpline::MakeCircleSpline(float radius)
{
	ESplineCoordinateSpace::Type splinePositionSpace = ESplineCoordinateSpace::Type::Local;

	mSpline->SetClosedLoop(true, false);
	// Clear the spline completely.
	mSpline->ClearSplinePoints(false);

	// Add four points for the circle
	mSpline->AddSplinePoint(FVector(radius, 0.0f, 0.0f), splinePositionSpace, false);
	mSpline->AddSplinePoint(FVector(0.0f, radius, 0.0f), splinePositionSpace, false);
	mSpline->AddSplinePoint(FVector(-radius, 0.0f, 0.0f), splinePositionSpace, false);
	mSpline->AddSplinePoint(FVector(0.0f, -radius, 0.0f), splinePositionSpace, false);

	mSpline->SetTangentAtSplinePoint(0, FVector(0.0f, radius * mCircleConstant, 0.0f), splinePositionSpace, false);
	mSpline->SetTangentAtSplinePoint(1, FVector(-1.0f * radius * mCircleConstant, 0.0f, 0.0f), splinePositionSpace, false);
	mSpline->SetTangentAtSplinePoint(2, FVector(0.0f, -1.0f * radius * mCircleConstant, 0.0f), splinePositionSpace, false);
	mSpline->SetTangentAtSplinePoint(3, FVector(radius * mCircleConstant, 0.0f, 0.0f), splinePositionSpace, true);

	mSpline->bInputSplinePointsToConstructionScript = true;
}

void AWallHugSpline::MakeRectangle(float xSize, float ySize, float borderRadius)
{
	float halfX = xSize / 2.0f;
	float halfY = ySize / 2.0f;
	ESplineCoordinateSpace::Type splinePositionSpace = ESplineCoordinateSpace::Type::Local;
	
	mSpline->SetClosedLoop(true, false);
	mSpline->ClearSplinePoints(false);

	mSpline->AddSplinePoint(FVector(halfX, 0.0f, 0.0f), splinePositionSpace, false);
	mSpline->AddSplinePoint(FVector(halfX - borderRadius, halfY, 0.0f), splinePositionSpace, false);
	mSpline->AddSplinePoint(FVector(halfX, halfY - borderRadius, 0.0f), splinePositionSpace, false);
	mSpline->AddSplinePoint(FVector(0.0f, halfY, 0.0f), splinePositionSpace, false);
	mSpline->AddSplinePoint(FVector(-halfX + borderRadius, halfY, 0.0f), splinePositionSpace, false);
	mSpline->AddSplinePoint(FVector(-halfX, halfY - borderRadius, 0.0f), splinePositionSpace, false);
	mSpline->AddSplinePoint(FVector(-halfX, 0.0f, 0.0f), splinePositionSpace, false);
	mSpline->AddSplinePoint(FVector(-halfX, -halfY + borderRadius, 0.0f), splinePositionSpace, false);
	mSpline->AddSplinePoint(FVector(-halfX + borderRadius, -halfY, 0.0f), splinePositionSpace, false);
	mSpline->AddSplinePoint(FVector(0.0f, -halfY, 0.0f), splinePositionSpace, false);
	mSpline->AddSplinePoint(FVector(halfX - borderRadius, -halfY, 0.0f), splinePositionSpace, false);
	mSpline->AddSplinePoint(FVector(halfX, -halfY + borderRadius, 0.0f), splinePositionSpace, false);

	for (int32 i = 0; i < 12; i += 3)
	{
		FVector tangentPoint((i % 2 == 0) ? 0.0f : halfX - borderRadius, (i % 2 == 0) ? halfY - borderRadius : 0.0f, 0.0f);
		mSpline->SetTangentAtSplinePoint(i, tangentPoint, splinePositionSpace, false);
	}

	for (int32 j = 1; j <= 11; j += ((j + 1) % 3 == 0 ? 2 : 1))
	{
		FVector tangentPoint((j % 2 == 0) ? borderRadius * mCircleConstant : 0.0f, (j % 2 == 0) ? 0.0f : borderRadius * mCircleConstant, 0.0f);
		mSpline->SetTangentAtSplinePoint(j, tangentPoint, splinePositionSpace, true);
	}

	mSpline->bInputSplinePointsToConstructionScript = true;
}



