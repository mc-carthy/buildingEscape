// Copyright Mick McCarthy 2016

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UPROPERTY(BlueprintAssignable)
	FOnOpenRequest OnOpenRequest;
		
private:
	UPROPERTY(VisibleAnywhere)
	float OpenAngle = -90.0f;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 0.5f;

	float LastDoorOpenTime;

	UPROPERTY(EditAnywhere)
	float PressurePlateThreshold = 40.0f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	AActor* Owner = nullptr;

	float GetTotalMassOfActorsOnPlate();
};
