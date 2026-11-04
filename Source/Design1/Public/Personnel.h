#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/UnrealString.h" // 包含FString
#include "CoreGlobals.h"             // 包含TOptional
#include "Personnel.generated.h" // 最后包含！

UCLASS(Abstract, Blueprintable, BlueprintType, meta = (DisplayName = "UBC_Personnel"))
class DESIGN1_API UPersonnel : public UObject
{
    GENERATED_BODY()

public:
    UPersonnel();
    UPersonnel(int32 InputId,FString InputName,int32 InputSex,int32 InputAge);
    UFUNCTION(BlueprintCallable, Category = "PersonnelInfo")
    virtual int GetId();
    UFUNCTION(BlueprintCallable, Category = "PersonnelInfo")
    virtual FString GetName();
    UFUNCTION(BlueprintCallable, Category = "PersonnelInfo")
    virtual int GetSex();
    UFUNCTION(BlueprintCallable, Category = "PersonnelInfo")
    virtual int GetAge();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelInfo", meta = (DisplayName = "Id"))
    int32 Id;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelInfo", meta = (DisplayName = "Name"))
    FString Name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelInfo", meta = (DisplayName = "Sex"))
    int32 Sex; // 1为男性，2为女性，默认为0
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PersonnelInfo", meta = (DisplayName = "Age"))
    int32 Age;

};