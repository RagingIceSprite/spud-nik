// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "Components/BoxComponent.h"
#include "WallHugSpline.generated.h"

UENUM(BlueprintType)
enum class ESplineShape : uint8
{
	SS_Circle UMETA(DisplayName="Circle"),
	SS_Rectangle UMETA(DisplayName="Rectangle"),
	SS_Custom UMETA(DisplayName="Manual")
};

UCLASS()
class SPUDNIK_POCT_API AWallHugSpline : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWallHugSpline();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	float mCircleConstant;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, CallInEditor)
	void MakeCircleSpline(float radius);

	UFUNCTION(BlueprintCallable, CallInEditor)
	void MakeRectangle(float xSize, float ySize, float borderRadius);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wall Settings", meta=(DisplayName = "Circle Shape"))
	bool bIsCircle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wall Settings", meta=(DisplayName = "Rectangle Shape"))
	bool bIsRect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wall Settings", meta=(DisplayName = "Custom Shape"))
	bool bIsCustom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wall Settings", meta = (EditCondition="bIsCircle"))
	float radius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wall Settings", meta = (EditCondition="bIsRect"))
	float xSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wall Settings", meta = (EditCondition="bIsRect"))
	float ySize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wall Settings", meta = (EditCondition="bIsRect"))
	float borderRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USplineComponent* mSpline;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* mBox;
};
