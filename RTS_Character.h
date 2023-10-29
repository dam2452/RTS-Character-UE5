//RTS_Character.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "RTS_Character.generated.h"

UCLASS()
class ENDEDWORLD_API ARTS_Character : public ACharacter
{
	GENERATED_BODY()

public:
	ARTS_Character();

protected:
	virtual void BeginPlay() override;

	// Initialize character components
	void InitializeComponents();

	virtual void Tick(float DeltaTime) override;

	// Update character movement, rotation, and zoom
	void UpdateMovement(float DeltaTime);
	void UpdateRotation(float DeltaTime);
	void UpdateZoom(float DeltaTime);

	// Setup the player input components
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Replicated properties
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

	// Handle input
	void HandleInput(const FVector& MoveInput, const float& RotateInput, const float& ZoomInput);

	// Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* RotateAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* ZoomAction;

	// Camera Components
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "UI")
	class UWidgetComponent* OverheadWidget;

	// Movement Variables
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector DesiredLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Movement_Interp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Movement_Speed;

	// Rotation Variables
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float DesiredYawRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float Rotation_Interp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float Rotation_Speed;

	// Zoom Variables
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Zoom")
	float DesiredZoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zoom")
	float ZoomSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zoom")
	float Zoom_Interp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zoom")
	float MinZoomDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zoom")
	float MaxZoomDistance;

private:
	// Network functions
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SetDesiredLocation(const FVector& NewDesiredLocation);

	virtual void Multicast_SetDesiredLocation_Implementation(const FVector& NewDesiredLocation);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_HandleInput(FVector MoveInput, float RotateInput, float ZoomInput);

	virtual bool Server_HandleInput_Validate(FVector MoveInput, float RotateInput, float ZoomInput);
	virtual void Server_HandleInput_Implementation(FVector MoveInput, float RotateInput, float ZoomInput);

	// Process input
	void ProcessInput(const FVector& MoveInput, const float& RotateInput, const float& ZoomInput);

	// Input actions
	void Move(const FInputActionValue& Value);
	void Rotate(const FInputActionValue& Value);
	void Zoom(const FInputActionValue& Value);
};
