#pragma once
#include "Personnel.h" // 先包含基类头文件

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/UnrealString.h"
#include "CoreGlobals.h"
#include "Teacher.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (DisplayName = "UC_Teacher"))
class DESIGN1_API UTeacher : public UPersonnel
{
    GENERATED_BODY()

public:
    UTeacher();
    UTeacher(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InputDepartment, FString InputMajor, FString InputTitle);
    UFUNCTION(BlueprintCallable, Category = "PersonnelInfo→TeacherInfo")
    void TeacherInit(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InputDepartment, FString InputMajor, FString InputTitle);

    virtual int GetId();
    
    virtual FString GetName();
   
    virtual int GetSex();
    
    virtual int GetAge();
    UFUNCTION(BlueprintCallable, Category = "PersonnelInfo→TeacherInfo")
    virtual FString GetDepartment();
    UFUNCTION(BlueprintCallable, Category = "PersonnelInfo→TeacherInfo")
    virtual FString GetMajor();
    UFUNCTION(BlueprintCallable, Category = "PersonnelInfo→TeacherInfo")
    virtual FString GetTitle();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelInfo→TeacherInfo", meta = (DisplayName = "Department"))
    FString Department;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelInfo→TeacherInfo", meta = (DisplayName = "Major"))
    FString Major;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelInfo→TeacherInfo", meta = (DisplayName = "Title"))
    FString Title;
};