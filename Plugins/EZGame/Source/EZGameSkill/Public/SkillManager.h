// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillManager.generated.h"

class USkillComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable)
class EZGAMESKILL_API USkillManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USkillManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	TArray<USkillComponent*> SkillArray;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	USkillComponent* NowAnimSkill;

	UFUNCTION(BlueprintCallable)
	virtual USkillComponent* AddSkill(TSubclassOf<USkillComponent> SkillClass);

	UFUNCTION(BlueprintCallable)
	virtual void BindSkill(USkillComponent*InBindSkill,USkillComponent* &TargetSkill);

	UFUNCTION(BlueprintCallable)
	virtual void CastSkill(USkillComponent* Skill);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USkillComponent* Skill1;

	UFUNCTION(BlueprintCallable)
	virtual void BindSkill1(USkillComponent* Skill) { BindSkill(Skill, Skill1); }

	UFUNCTION(BlueprintCallable)
	virtual void CastSkill1() { CastSkill(Skill1); }

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USkillComponent* Skill2;

	UFUNCTION(BlueprintCallable)
	virtual void BindSkill2(USkillComponent* Skill) { BindSkill(Skill, Skill2); }

	UFUNCTION(BlueprintCallable)
	virtual void CastSkill2() { CastSkill(Skill2); }

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USkillComponent* Skill3;

	UFUNCTION(BlueprintCallable)
	virtual void BindSkill3(USkillComponent* Skill) { BindSkill(Skill, Skill3); }

	UFUNCTION(BlueprintCallable)
	virtual void CastSkill3() { CastSkill(Skill3); }

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USkillComponent* Skill4;

	UFUNCTION(BlueprintCallable)
	virtual void BindSkill4(USkillComponent* Skill) { BindSkill(Skill, Skill4); }

	UFUNCTION(BlueprintCallable)
	virtual void CastSkill4() { CastSkill(Skill4); }

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USkillComponent* Skill5;

	UFUNCTION(BlueprintCallable)
	virtual void BindSkill5(USkillComponent* Skill) { BindSkill(Skill, Skill5); }

	UFUNCTION(BlueprintCallable)
	virtual void CastSkill5() { CastSkill(Skill5); }

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USkillComponent* Skill6;

	UFUNCTION(BlueprintCallable)
	virtual void BindSkill6(USkillComponent* Skill) { BindSkill(Skill, Skill6); }

	UFUNCTION(BlueprintCallable)
	virtual void CastSkill6() { CastSkill(Skill6); }


		
};
