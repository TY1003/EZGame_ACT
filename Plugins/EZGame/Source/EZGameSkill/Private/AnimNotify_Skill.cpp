// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_Skill.h"
#include "SkillManager.h"
#include "SkillComponent.h"

void UAnimNotify_Skill::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	if (!MeshComp)
		return;
	TInlineComponentArray<USkillManager*> Components(MeshComp->GetOwner());
	for (USkillManager* a : Components)
	{
		USkillComponent* NowSkill = a->NowAnimSkill;
		if (!NowSkill)
			return;
		UFunction* tFunc = NowSkill->FindFunction(FunctionName);
		if (tFunc)
			NowSkill->ProcessEvent(tFunc, nullptr);
	}
}