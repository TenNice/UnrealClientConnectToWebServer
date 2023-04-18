// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginActor.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Serialization/JsonSerializer.h"
#include "Dom/JsonObject.h"

// Sets default values
ALoginActor::ALoginActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALoginActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ALoginActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ALoginActor::DoLogin(FString InputID, FString InputPW)
{

	// Construct the login JSON payload
	TSharedPtr<FJsonObject> LoginJson = MakeShareable(new FJsonObject);
	LoginJson->SetStringField(TEXT("email"), InputID);
	LoginJson->SetStringField(TEXT("password"), InputPW);

	// Convert the JSON payload to a string
	FString RegisterString;
	TSharedRef<TJsonWriter<>> JsonWriter = TJsonWriterFactory<>::Create(&RegisterString);
	FJsonSerializer::Serialize(LoginJson.ToSharedRef(), JsonWriter);

	// URI Base + API
	FString UriBase = TEXT("http://192.168.0.117:8080");
	FString UriLogin = UriBase + TEXT("/api/login");

	// Create the HTTP request and set the content
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
	Request->SetVerb(TEXT("POST"));
	Request->SetURL(UriLogin);
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetContentAsString(RegisterString);

	// Delligate Recieve Response
	Request->OnProcessRequestComplete().BindUObject(this, &ALoginActor::ReceiveLoginResponse);

	// Send the request
	Request->ProcessRequest();


}

void ALoginActor::ReceiveLoginResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{

	if (bWasSuccessful && Response->GetResponseCode() == 200)
	{
		FString ResponseStr = Response->GetContentAsString();
		UE_LOG(LogTemp, Warning, TEXT("Login response received: %s"), *ResponseStr);

		// Parse the JSON response
		/*TSharedPtr<FJsonObject> JsonResponse;
		TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(ResponseStr);

		if (FJsonSerializer::Deserialize(JsonReader, JsonResponse))
		{
			FString AccessToken = JsonResponse->GetStringField(TEXT("access_token"));
			int32 ExpiresIn = JsonResponse->GetIntegerField(TEXT("expires_in"));
			UE_LOG(LogTemp, Warning, TEXT("Access Token: %s, Expires In: %d"), *AccessToken, ExpiresIn);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to parse login response"));
		}*/
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Login request failed"));
	}

}

void ALoginActor::DoRegister()
{
	// Construct the login JSON payload
	TSharedPtr<FJsonObject> RegisterJson = MakeShareable(new FJsonObject);
	RegisterJson->SetStringField(TEXT("email"), TEXT("TestEmail@naver.com"));
	RegisterJson->SetStringField(TEXT("password"), TEXT("TestPassword"));

	// Convert the JSON payload to a string
	FString RegisterString;
	TSharedRef<TJsonWriter<>> JsonWriter = TJsonWriterFactory<>::Create(&RegisterString);
	FJsonSerializer::Serialize(RegisterJson.ToSharedRef(), JsonWriter);

	// URI Base + API
	FString UriBase = TEXT("http://192.168.0.117:8080");
	FString UriRegister = UriBase + TEXT("/api/signup");

	// Create the HTTP request and set the content
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
	Request->SetVerb(TEXT("POST"));
	Request->SetURL(UriRegister);
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetContentAsString(RegisterString);

	// Send the request
	Request->ProcessRequest();

}