// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/DataTable.h"
#include "UCustomTypesLibrary.generated.h"


USTRUCT(BlueprintType)
struct FST_HexLayout : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	FST_HexLayout()
	{}
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	FString Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	TArray<FTransform> PrimaryTransforms;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	TArray<FTransform> SecondaryTransforms;
}

USTRUCT(BlueprintType)
struct FST_StatProvider : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	FST_StatProvider(
		int32 Range = 1,
		bool IsPasive = true,
		TMap<FString, int32> Stats = TMap<FString, int32>())
		: Range(Range)
		, IsPasive(IsPasive)
		, Stats(Stats)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Provider")
	int32 Range;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Provider")
	bool IsPasive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Provider")
	TMap<FString, int32> Stats;
};


USTRUCT(BlueprintType)
struct FST_Structure : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	FST_Structure(
		FString Id = "",
		FString Title = "",
		TMap<FString, int32> Stats = TMap<FString, int32>(),
		TArray<FST_StatProvider> StatProviders = TArray<FST_StatProvider>(),
		bool bIncludePathing = false)
		: Id(Id)
		, Title(Title)
		, Stats(Stats)
		, StatProviders(StatProviders)
		, bIncludePathing(bIncludePathing)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	FString Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	FString Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Provider")
	TMap<FString, int32> Stats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	TArray<FST_StatProvider> StatProviders;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	bool bIncludePathing;
};





/*
USTRUCT(BlueprintType)
struct FST_Structure : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	FST_Structure(
		FString Id = "",
		FString Title = "",
		FString Description = "",
		bool Burnable = false,
		//TSubclassOf<APOTLStructure> StructureClass = "BlueprintGeneratedClass'/Game/Blueprint/Actor/BP_Structure.BP_Structure_C'",
		TArray<FVector> CubeSizes = TArray<FVector>(),
		FVector Entrance = { 0, 0, 0 },
		int RotationDirection = 0,
		bool BlockConstruction = true,
		bool BlockPathing = true,
		float ConstructionTime = 10.f,
		TArray<FIdAmount> OperationCost = TArray<FIdAmount>(),
		TArray<FIdAmount> ConstructionCost = TArray<FIdAmount>(),
		TArray<FST_Gatherer> Gatherers = TArray<FST_Gatherer>(),
		TArray<FST_Factory> Factories = TArray<FST_Factory>())
		: Id(Id)
		, Title(Title)
		, Description(Description)
		, Burnable(Burnable)
		//, StructureClass(StructureClass)
		, CubeSizes(CubeSizes)
		, Entrance(Entrance)
		, RotationDirection(RotationDirection)
		, BlockConstruction(BlockConstruction)
		, BlockPathing(BlockPathing)
		, ConstructionTime(ConstructionTime)
		, OperationCost(OperationCost)
		, ConstructionCost(ConstructionCost)
		, Gatherers(Gatherers)
		, Factories(Factories)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	FString Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	FString Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	bool Burnable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	TSubclassOf<APOTLStructure> StructureClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	TAssetPtr<UStaticMesh> PreviewMesh;
	//TAssetPtr<UStaticMesh> PreviewMesh;
	//TSubclassOf<class UStaticMesh> PreviewMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	TArray<FString> AttachTo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	TArray<FVector> CubeSizes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	FVector Entrance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	int RotationDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	bool BlockConstruction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	bool BlockPathing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	float ConstructionTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	TArray<FIdAmount> OperationCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	TArray<FIdAmount> ConstructionCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	TArray<FST_Gatherer> Gatherers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	TArray<FST_Factory> Factories;

};
*/



UCLASS()
class KING_API UCustomTypesLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	
	
	
};
