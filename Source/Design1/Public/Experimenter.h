#pragma once
#include "Personnel.h"

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/UnrealString.h" // 包含FString
#include "CoreGlobals.h"             // 包含TOptional
#include "Experimenter.generated.h" // 最后包含！

UCLASS(Blueprintable, BlueprintType, meta = (DisplayName = "UC_Experimenter"))
class DESIGN1_API UExperimenter : public UPersonnel
{
	GENERATED_BODY()

public:
	UExperimenter();
	UExperimenter(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InputLab, FString InputDuty);
	UFUNCTION(BlueprintCallable, Category = "PersonnelInfo→ExperimenterInfo")
	void ExperimenterInit(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InputLab, FString InputDuty);

	int GetId();

	FString GetName();

	int GetSex();
	
	int GetAge();
	UFUNCTION(BlueprintCallable, Category = "PersonnelInfo→ExperimenterInfo")
	FString GetLab();
	UFUNCTION(BlueprintCallable, Category = "PersonnelInfo→ExperimenterInfo")
	FString GetDuty();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelInfo", meta = (DisplayName = "Lab"))
	FString Lab;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelInfo", meta = (DisplayName = "Duty"))
	FString Duty;
};
