#pragma once
#include "Personnel.h" 
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PersonSaveLoadComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DESIGN1_API UPersonSaveLoadComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPersonSaveLoadComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable, Category = "Personnel")
	void SavePersonsToFile(TArray<UPersonnel*>Persons);

	// 从文件加载人员数据的方法
	UFUNCTION(BlueprintCallable, Category = "Personnel")
	TArray<UPersonnel*> LoadPersonsFromFile();

};


