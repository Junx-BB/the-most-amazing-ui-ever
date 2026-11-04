#pragma once
#include "Teacher.h"
#include "Experimenter.h"
#include "AdministrativPersonnel.h"
#include "AcademicAdministrator.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/NoExportTypes.h"
#include "Containers/UnrealString.h"
#include "CoreGlobals.h"
#include "PersonnelMannager.generated.h"


UCLASS(Blueprintable, BlueprintType, meta = (DisplayName = "UC_PersonnelMannager"))
class DESIGN1_API APersonnelMannager : public AActor
{
	GENERATED_BODY()

public:
	APersonnelMannager();
	~APersonnelMannager();
	// 创建各个人员类的对象存放的数组
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelMannager")
	TArray<UPersonnel*> ArrPersonnels;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelMannager")
	TArray<UTeacher*> ArrTeachers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelMannager")
	TArray<UExperimenter*> ArrExperimenters;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelMannager")
	TArray<UAdministrativPersonnel*> ArrAdministrativPersonnels;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelMannager")
	TArray<UAcademicAdministrator*> ArrAcademicAdministrators;
	// 创建各个人员类的对象在Displayer界面的数组
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelMannager")
	TArray<UPersonnel*> ArrPersonnels_Display;
	// 各个成员类的对象的数量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelMannager")
	int32 PersonnelCount = ArrPersonnels.Num();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelMannager")
	int32 TeacherCount = ArrTeachers.Num();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelMannager")
	int32 ExperimenterCount = ArrExperimenters.Num();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelMannager")
	int32 AdministrativPersonnelCount = ArrAdministrativPersonnels.Num();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelMannager")
	int32 AcademicAdministratorCount = ArrAcademicAdministrators.Num();

	// 更新各个人员类数量的函数
	UFUNCTION(BlueprintCallable, Category = "PersonnelMannager")
	void UpdataAllPersonnelTypeCount();
	// 对各个人员类对象存放的数组按照Id进行从小到大排序的函数
	UFUNCTION(BlueprintCallable, Category = "PersonnelMannager")
	void MakeArrPersonnelsInRow();
	// 初始化ArrPersonnels_Display数组的函数
	UFUNCTION(BlueprintCallable, Category = "PersonnelMannager")
	void InitArrPersonnels_Display(int32 InputIndex);
	// 清空ArrPersonnels_Display数组的函数
	UFUNCTION(BlueprintCallable, Category = "PersonnelMannager")
	void CleanArrPersonnels_Display();
	// 获取ArrPersonnels_Display数组长度的函数
	UFUNCTION(BlueprintCallable, Category = "PersonnelMannager")
	int GetInitArrPersonnelsLength_Display();
	// 创建各个人员类的对象的函数
	UFUNCTION(BlueprintCallable, Category = "PersonnelMannager")
	void CreateNewTeacher(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InputDepartment, FString InputMajor, FString InputTitle);
	UFUNCTION(BlueprintCallable, Category = "PersonnelMannager")
	void CreateNewExperimenter(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InputLab, FString InputDuty);
	UFUNCTION(BlueprintCallable, Category = "PersonnelMannager")
	void CreateNewAdministrativPersonnel(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InpuPoliticalStatus, FString InputPosition);
	UFUNCTION(BlueprintCallable, Category = "PersonnelMannager")
	void CreateNewAcademicAdministrator(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InpuPoliticalStatus, FString InputPosition, FString InputDepartment, FString InputMajor, FString InputTitle);
	// 获取男性或女性员工总数的函数
	UFUNCTION(BlueprintCallable, Category = "PersonnelMannager")
	int GetMaleCount();
	UFUNCTION(BlueprintCallable, Category = "PersonnelMannager")
	int GetFemaleCount();
	// 获取某个年龄段内员工总数的函数
	UFUNCTION(BlueprintCallable, Category = "PersonnelMannager")
	int GetPersonnelBetween18to25Count();
};
