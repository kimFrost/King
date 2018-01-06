// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UKingTilesLibrary.generated.h"

/**
 * 
 */
UCLASS()
class KING_API UKingTilesLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "Util")
	static FVector DirectionToCube(int32 Direction);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Util")
	static int32 CubeToDirection(FVector Cube);

	UFUNCTION(BlueprintCallable, Category = "Util")
	static FVector DirectionToLocation(int32 Direction);

	//UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Util")
	//static int32 LocationToDirection(FVector Location);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Util")
	static FRotator DirectionToRotation(int32 Direction);

	UFUNCTION(BlueprintCallable, Category = "Util")
	static FVector RoundCube(FVector Cube);

	UFUNCTION(BlueprintCallable, Category = "Util")
	static FVector OffsetToCube(FVector2D Offset);

	UFUNCTION(BlueprintCallable, Category = "Util")
	static FVector2D CubeToOffset(FVector Cube);

	UFUNCTION(BlueprintCallable, Category = "Util")
	static FVector AxialToCube(float Q, float R);

	UFUNCTION(BlueprintCallable, Category = "Util")
	static FVector LocationToCube(float HexWidth, float HexHeight, FVector Location);
	
	UFUNCTION(BlueprintCallable, Category = "Util")
	static FVector CubeToLocation(FVector Cube);

	UFUNCTION(BlueprintCallable, Category = "Util")
	static TArray<FVector> GetCubeRing(FVector CubeCenter, int32 Distance);

	UFUNCTION(BlueprintCallable, Category = "Util")
	static TArray<FVector> GetCubeSpiralInRange(FVector CubeFrom, int32 Range, bool IncludeFrom);

	
};
