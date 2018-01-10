// Fill out your copyright notice in the Description page of Project Settings.

#include "UNeedsComponent.h"
#include "Stats/UStat.h"


// Sets default values for this component's properties
UNeedsComponent::UNeedsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UNeedsComponent::BeginPlay()
{
	Super::BeginPlay();

	for (auto& Need : Needs)
	{
		UStat* Stat = NewObject<UStat>(this);
		if (Stat)
		{
			Stat->ID = Need.Key;
			Stat->ConsumeMultiplier = Need.Value;
			Stats.Add(Stat);
		}
	}
	
}


// Called every frame
void UNeedsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	// Lower stats
	
}

