// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillManager.h"
#include "SkillComponent.h"

// Sets default values for this component's properties
USkillManager::USkillManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USkillManager::BeginPlay()
{
	Super::BeginPlay();
	if (GetOwner() && GetOwner()->InputComponent)
	{
		GetOwner()->InputComponent->BindAction("Q", EInputEvent::IE_Pressed, this, &USkillManager::CastSkill1);
		GetOwner()->InputComponent->BindAction("W", EInputEvent::IE_Pressed, this, &USkillManager::CastSkill2);
		GetOwner()->InputComponent->BindAction("E", EInputEvent::IE_Pressed, this, &USkillManager::CastSkill3);
		GetOwner()->InputComponent->BindAction("A", EInputEvent::IE_Pressed, this, &USkillManager::CastSkill4);
		GetOwner()->InputComponent->BindAction("S", EInputEvent::IE_Pressed, this, &USkillManager::CastSkill5);
		GetOwner()->InputComponent->BindAction("D", EInputEvent::IE_Pressed, this, &USkillManager::CastSkill6);

	}
	// ...
	
}


// Called every frame
void USkillManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

USkillComponent* USkillManager::AddSkill(TSubclassOf<USkillComponent> SkillClass)
{
	USkillComponent* NewSkill = NewObject<USkillComponent>(GetOwner(), SkillClass);
	NewSkill->RegisterComponent();
	SkillArray.Add(NewSkill);
	NewSkill->OnInit(this);
	return NewSkill;
}

void USkillManager::BindSkill(USkillComponent* InBindSkill, USkillComponent*& TargetSkill)
{
	if (!InBindSkill)
		return;
	TargetSkill = InBindSkill;
}


void USkillManager::CastSkill(USkillComponent* Skill)
{
	if (!Skill)
		return;
	Skill->OnCast();
}