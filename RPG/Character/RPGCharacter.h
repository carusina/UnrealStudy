// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "RPGCharacter.generated.h"

// 선언
class USpringArmComponent;
class UCameraComponent;
class USkeletalMeshComponent;

class UInputMappingContext;
class UInputAction;

UCLASS()
class RPG_API ARPGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARPGCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Enhanced Input
	UPROPERTY(EditAnywhere, Category = EnhancedInput)
	UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, Category = EnhancedInput)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = EnhancedInput)
	UInputAction* LookAction;
	
	UPROPERTY(EditAnywhere, Category = EnhancedInput)
    UInputAction* SprintAction;

	// Movement
	void Move(const FInputActionValue& InputValue);
	void Look(const FInputActionValue& InputValue);
	void SprintBegin();
	void SprintEnd();

	// Speed
	UPROPERTY(EditAnywhere, Category = Movement)
	float WalkSpeed = 300.f;
	UPROPERTY(EditAnywhere, Category = Movement)
	float SprintSpeed = 600.f;
	
	

private:
	// 카메라
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArmComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComp;

	// 무기
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Weapon, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* WeaponSkeletal;
};
