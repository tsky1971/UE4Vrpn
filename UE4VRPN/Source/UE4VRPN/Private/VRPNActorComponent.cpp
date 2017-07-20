// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4VRPNPrivatePCH.h"
#include "VRPNActorComponent.h"

#include <sstream>

void VRPN_CALLBACK handle_analog(void* userData, const vrpn_ANALOGCB a)
{
	int nbChannels = a.num_channel;

	//cout << "Analog : ";
	UE_LOG(LogTemp, Warning, TEXT("handle_analog() UE4VRPN Analog : "));

	for (int i = 0; i < a.num_channel; i++)
	{
		//cout << a.channel[i] << " ";
		std::stringstream ss;
		ss << a.channel[i] << " ";

		UE_LOG(LogTemp, Warning, TEXT("handle_analog() UE4VRPN %s"), ANSI_TO_TCHAR(ss.str().c_str()));
	}

	//cout << endl;
}

void VRPN_CALLBACK handle_button(void* userData, const vrpn_BUTTONCB b)
{
	//cout << "Button '" << b.button << "': " << b.state << endl;
	std::stringstream ss;
	ss << "Button '" << b.button << "': " << b.state;
	UE_LOG(LogTemp, Warning, TEXT("handle_button() UE4VRPN %s"), ANSI_TO_TCHAR(ss.str().c_str()));
}


void VRPN_CALLBACK handle_tracker(void* userData, const vrpn_TRACKERCB t)
{
	//cout << "Tracker '" << t.sensor << "' : " << t.pos[0] << "," << t.pos[1] << "," << t.pos[2] << endl;
	std::stringstream ss;
	ss << "Tracker '" << t.sensor << "' : " << t.pos[0] << "," << t.pos[1] << "," << t.pos[2];
	UE_LOG(LogTemp, Warning, TEXT("handle_tracker() UE4VRPN %s"), ANSI_TO_TCHAR(ss.str().c_str()));
}



// Sets default values for this component's properties
UVRPNActorComponent::UVRPNActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
	// ...

}


// Called when the game starts
void UVRPNActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay() UE4VRPN create devices"));

	vrpnAnalog = new vrpn_Analog_Remote("Mouse0@localhost");
	vrpnButton = new vrpn_Button_Remote("Button0@localhost");
	vrpnTracker = new vrpn_Tracker_Remote("Tracker0@localhost");

	vrpnAnalog->register_change_handler(0, handle_analog);
	vrpnButton->register_change_handler(0, handle_button);
	vrpnTracker->register_change_handler(0, handle_tracker);
}


// Called every frame
void UVRPNActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	vrpnAnalog->mainloop();
	vrpnButton->mainloop();
	vrpnTracker->mainloop();

}

