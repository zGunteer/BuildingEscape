// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float TotalMassOfActors() const;
	void FindAudioComponent();
	void PressurePlateCheck();

	//Tracks whether the sound has been played
	bool OpenDoorSound = false;
	bool CloseFeedBack = true;

private:
	bool DoorHasBeenOpened = false;  // mod nou test
	float InitialYaw;
	float CurrentYaw;

	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;
	
	float DoorLastOpened = 0.f;
	UPROPERTY(EditAnywhere)
	float DoorClosedDelay = 0.8f;

	UPROPERTY(EditAnywhere)
	float OpenDoorSpeed=1.0f;
	UPROPERTY(EditAnywhere)
	float CloseDoorSpeed=2.0f;

	UPROPERTY(EditAnywhere)
	float MassRequired = 0.f;

	UPROPERTY()
	UAudioComponent* AudioComponent = nullptr;
};
