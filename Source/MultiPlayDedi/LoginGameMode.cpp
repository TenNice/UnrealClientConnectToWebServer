// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginGameMode.h"
#include "LoginActor.h"

void ALoginGameMode::ConnectDedicatedServer()
{
	UE_LOG(LogTemp, Warning, TEXT("ConnectDedicatedServer"));
	MyLoginActor = nullptr;
	
}

void ALoginGameMode::TryRegister()
{
	UE_LOG(LogTemp, Warning, TEXT("TryRegister"));
	if (MyLoginActor == nullptr)
	{
		MyLoginActor = NewObject<ALoginActor>();
	}

	if (MyLoginActor != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("DoRegister"));
		MyLoginActor->DoRegister();
	}

}

void ALoginGameMode::TryLogin(FString InputID, FString InputPW)
{
	UE_LOG(LogTemp, Warning, TEXT("TryLogin"));
	if (MyLoginActor == nullptr)
	{
		MyLoginActor = NewObject<ALoginActor>();
	}

	if (MyLoginActor != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("DoLogin"));
		MyLoginActor->DoLogin(InputID, InputPW);
	}
}
