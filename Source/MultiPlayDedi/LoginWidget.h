// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoginWidget.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYDEDI_API ULoginWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Login")
	FString UserID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Login")
	FString UserPW;

	UFUNCTION(BlueprintCallable, meta = (Keywords = "Sihoon"))
	void CheckIDAndPW();
	
};
