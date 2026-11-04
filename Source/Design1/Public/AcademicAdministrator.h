#pragma once
#include "Teacher.h"
#include "AdministrativPersonnel.h"

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/UnrealString.h"
#include "CoreGlobals.h"
#include "AcademicAdministrator.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (DisplayName = "UC_AcademicAdministrator"))
class DESIGN1_API UAcademicAdministrator : public UTeacher
{
	GENERATED_BODY()

public:
	UAcademicAdministrator();
	UAcademicAdministrator(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InpuPoliticalStatus, FString InputPosition, FString InputDepartment, FString InputMajor, FString InputTitle);
	UFUNCTION(BlueprintCallable, Category = "PersonnelInfo¡úAcademicAdministratorInfo")
	void AcademicAdministratorInit(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InpuPoliticalStatus, FString InputPosition, FString InputDepartment, FString InputMajor, FString InputTitle);

	int GetId();

	FString GetName();

	int GetSex();
	int GetAge();
	FString GetPoliticalStatus();
	UFUNCTION(Category = "PersonnelInfo¡úAcademicAdministratorInfo")
	FString GetPosition();

	FString GetDepartment();

	FString GetMajor();

	FString GetTitle();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelInfo¡úTeacherInfo", meta = (DisplayName = "PoliticalStatus"))
	FString PoliticalStatus;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelInfo¡úTeacherInfo", meta = (DisplayName = "Position"))
	FString Position;
};
