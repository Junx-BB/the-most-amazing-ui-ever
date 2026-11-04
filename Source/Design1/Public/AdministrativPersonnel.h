#pragma once
#include "Personnel.h"

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/UnrealString.h"
#include "CoreGlobals.h"
#include "AdministrativPersonnel.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (DisplayName = "UC_AdministrativPersonnel"))

class DESIGN1_API UAdministrativPersonnel : public UPersonnel
{
	GENERATED_BODY()

public:
	UAdministrativPersonnel();
	UAdministrativPersonnel(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InpuPoliticalStatus, FString InputPosition);
	UFUNCTION(BlueprintCallable, Category = "PersonnelInfo¡úAdministrativPersonnelInfo")
	void AdministrativPersonnelInit(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InpuPoliticalStatus, FString InputPosition);

	int GetId();

	FString GetName();

	int GetSex();

	int GetAge();
	UFUNCTION(BlueprintCallable, Category = "PersonnelInfo¡úAdministrativPersonnelInfo")
	FString GetPoliticalStatus();
	UFUNCTION(BlueprintCallable, Category = "PersonnelInfo¡úAdministrativPersonnelInfo")
	FString GetPosition();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelInfo¡úAdministrativPersonnelInfo", meta = (DisplayName = "PoliticalStatus"))
	FString PoliticalStatus;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelInfo¡úAdministrativPersonnelInfo", meta = (DisplayName = "Position"))
	FString Position;
};
