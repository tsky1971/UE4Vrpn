// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

// @third party code - BEGIN
#include "AllowWindowsPlatformTypes.h"

#include "include/vrpn_Types.h"
#include "include/vrpn_Tracker.h"
#include "include/vrpn_Tracker.h"
#include "include/vrpn_Button.h"
#include "include/vrpn_Analog.h"

#include "HideWindowsPlatformTypes.h"
// @third party code - END

#include "VRPNActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE4VRPN_API UVRPNActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UVRPNActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
protected:
	vrpn_Analog_Remote* vrpnAnalog;
	vrpn_Button_Remote* vrpnButton;
	vrpn_Tracker_Remote* vrpnTracker;

};
