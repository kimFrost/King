// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UNeedsComponent.generated.h"


class UStat;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KING_API UNeedsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNeedsComponent();

	TMap<FString, int32> Needs;

	// Food/Hunger
	
	TArray<UStat*> Stats;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
