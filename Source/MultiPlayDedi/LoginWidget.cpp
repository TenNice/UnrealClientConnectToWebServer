// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginWidget.h"

void ULoginWidget::CheckIDAndPW()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *UserID);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *UserPW);
}
