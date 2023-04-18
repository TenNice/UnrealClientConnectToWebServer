// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LoginGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYDEDI_API ALoginGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void ConnectDedicatedServer();
	
	UPROPERTY(EditAnywhere, Category = "Login")
	class ALoginActor* MyLoginActor;

	UFUNCTION(BlueprintCallable, meta = (Keywords = "Sihoon"))
	void TryRegister();

	UFUNCTION(BlueprintCallable, meta = (Keywords = "Sihoon"))
	void TryLogin(FString ID, FString PW);

};
