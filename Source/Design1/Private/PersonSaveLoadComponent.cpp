// PersonSaveLoadComponent.cpp
#include "PersonSaveLoadComponent.h" // 必须第一位！
#include "Personnel.h" 
#include "Teacher.h"
#include "Experimenter.h"
#include "AdministrativPersonnel.h"
#include "AcademicAdministrator.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonSerializer.h"

UPersonSaveLoadComponent::UPersonSaveLoadComponent()
{
}

void UPersonSaveLoadComponent::BeginPlay()
{
}

void UPersonSaveLoadComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
}

// 保存人员数据到 JSON 文件
void UPersonSaveLoadComponent::SavePersonsToFile(TArray<UPersonnel*> Persons)
{
    // 创建 JSON 对象数组
    TArray<TSharedPtr<FJsonValue>> JsonPersons;
    for (UPersonnel* Person : Persons)
    {
        TSharedPtr<FJsonObject> JsonObj = MakeShareable(new FJsonObject());
        JsonObj->SetNumberField(TEXT("ID"), Person->Id);
        JsonObj->SetStringField(TEXT("Name"), Person->Name);
        JsonObj->SetNumberField(TEXT("Gender"), Person->Sex);
        JsonObj->SetNumberField(TEXT("Age"), Person->Age);

        // 如果是教师，额外存子类字段
        if (UTeacher* Teacher = Cast<UTeacher>(Person))
        {
            JsonObj->SetStringField(TEXT("Department"), Teacher->Department);
            JsonObj->SetStringField(TEXT("Major"), Teacher->Major);
            JsonObj->SetStringField(TEXT("Title"), Teacher->Title);
            JsonObj->SetStringField(TEXT("Type"), TEXT("Teacher")); // 标记类型，方便读取识别
        }
        else if (UExperimenter* Experimenter = Cast<UExperimenter>(Person))
        {
            JsonObj->SetStringField(TEXT("Lab"), Experimenter->Lab);
            JsonObj->SetStringField(TEXT("Duty"), Experimenter->Duty);
            JsonObj->SetStringField(TEXT("Type"), TEXT("Experimenter")); // 标记类型，方便读取识别
        }
        else if (UAdministrativPersonnel* AdministrativPersonnel = Cast<UAdministrativPersonnel>(Person))
        {
            JsonObj->SetStringField(TEXT("PoliticalStatus"), AdministrativPersonnel->PoliticalStatus);
            JsonObj->SetStringField(TEXT("Position"), AdministrativPersonnel->Position);
            JsonObj->SetStringField(TEXT("Type"), TEXT("AdministrativPersonnel")); // 标记类型，方便读取识别
        }

        else if (UAcademicAdministrator* AcademicAdministrator = Cast<UAcademicAdministrator>(Person))
        {
            JsonObj->SetStringField(TEXT("Department"), AcademicAdministrator->Department);
            JsonObj->SetStringField(TEXT("Major"), AcademicAdministrator->Major);
            JsonObj->SetStringField(TEXT("Title"), AcademicAdministrator->Title);
            JsonObj->SetStringField(TEXT("PoliticalStatus"), AcademicAdministrator->PoliticalStatus);
            JsonObj->SetStringField(TEXT("Position"), AcademicAdministrator->Position);
            JsonObj->SetStringField(TEXT("Type"), TEXT("AcademicAdministrator")); // 标记类型，方便读取识别
        }


        JsonPersons.Add(MakeShareable(new FJsonValueObject(JsonObj)));
    }

    // 整体 JSON 结构
    TSharedPtr<FJsonObject> RootObj = MakeShareable(new FJsonObject());
    RootObj->SetArrayField(TEXT("Persons"), JsonPersons);

    // 转成字符串
    FString JsonStr;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonStr);
    FJsonSerializer::Serialize(RootObj.ToSharedRef(), Writer);

    // 写入文件
    FString SavePath = FPaths::ProjectSavedDir() + TEXT("PersonData.json");
    FFileHelper::SaveStringToFile(JsonStr, *SavePath);
}

// 从 JSON 文件读取人员数据
TArray<UPersonnel*> UPersonSaveLoadComponent::LoadPersonsFromFile()
{
    TArray<UPersonnel*> LoadedPersons;
    FString LoadPath = FPaths::ProjectSavedDir() + TEXT("PersonData.json");

    // 读取文件内容
    FString JsonStr;
    if (!FFileHelper::LoadFileToString(JsonStr, *LoadPath))
    {
        UE_LOG(LogTemp, Warning, TEXT("文件不存在或读取失败：%s"), *LoadPath);
        return LoadedPersons;
    }

    // 解析 JSON
    TSharedPtr<FJsonObject> RootObj;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonStr);
    if (!FJsonSerializer::Deserialize(Reader, RootObj))
    {
        
        return LoadedPersons;
    }

    // 遍历人员数组
    TArray<TSharedPtr<FJsonValue>> JsonPersons = RootObj->GetArrayField(TEXT("Persons"));
    for (TSharedPtr<FJsonValue> JsonVal : JsonPersons)
    {
        TSharedPtr<FJsonObject> JsonObj = JsonVal->AsObject();
        if (!JsonObj.IsValid()) continue;

        FString Type = JsonObj->GetStringField(TEXT("Type")); // 读取类型标记
        if (Type == TEXT("Teacher"))
        {
            UTeacher* Teacher = NewObject<UTeacher>(GetTransientPackage(), UTeacher::StaticClass());
            Teacher->Id = JsonObj->GetNumberField(TEXT("ID"));
            Teacher->Name = JsonObj->GetStringField(TEXT("Name"));
            Teacher->Sex = JsonObj->GetNumberField(TEXT("Gender"));
            Teacher->Age = JsonObj->GetNumberField(TEXT("Age"));
            Teacher->Department = JsonObj->GetStringField(TEXT("Department"));
            Teacher->Major = JsonObj->GetStringField(TEXT("Major"));
            Teacher->Title = JsonObj->GetStringField(TEXT("Title"));
            LoadedPersons.Add(Teacher);
        }
        else  if (Type == TEXT("Experimenter"))
        {
            UExperimenter* Experimenter = NewObject<UExperimenter>(GetTransientPackage(), UExperimenter::StaticClass());
            Experimenter->Id = JsonObj->GetNumberField(TEXT("ID"));
            Experimenter->Name = JsonObj->GetStringField(TEXT("Name"));
            Experimenter->Sex = JsonObj->GetNumberField(TEXT("Gender"));
            Experimenter->Age = JsonObj->GetNumberField(TEXT("Age"));
            Experimenter->Lab = JsonObj->GetStringField(TEXT("Lab"));
            Experimenter->Duty = JsonObj->GetStringField(TEXT("Duty"));
            LoadedPersons.Add(Experimenter);
        }
        else  if (Type == TEXT("AdministrativPersonnel"))
        {
            UAdministrativPersonnel* AdministrativPersonnel = NewObject<UAdministrativPersonnel>(GetTransientPackage(), UAdministrativPersonnel::StaticClass());
            AdministrativPersonnel->Id = JsonObj->GetNumberField(TEXT("ID"));
            AdministrativPersonnel->Name = JsonObj->GetStringField(TEXT("Name"));
            AdministrativPersonnel->Sex = JsonObj->GetNumberField(TEXT("Gender"));
            AdministrativPersonnel->Age = JsonObj->GetNumberField(TEXT("Age"));
            AdministrativPersonnel->PoliticalStatus = JsonObj->GetStringField(TEXT("PoliticalStatus"));
            AdministrativPersonnel->Position = JsonObj->GetStringField(TEXT("Position"));
            LoadedPersons.Add(AdministrativPersonnel);
        }
        else if (Type == TEXT("AcademicAdministrator"))
        {
            UAcademicAdministrator* AcademicAdministrator = NewObject<UAcademicAdministrator>(GetTransientPackage(), UAcademicAdministrator::StaticClass());
            AcademicAdministrator->Id = JsonObj->GetNumberField(TEXT("ID"));
            AcademicAdministrator->Name = JsonObj->GetStringField(TEXT("Name"));
            AcademicAdministrator->Sex = JsonObj->GetNumberField(TEXT("Gender"));
            AcademicAdministrator->Age = JsonObj->GetNumberField(TEXT("Age"));
            AcademicAdministrator->Department = JsonObj->GetStringField(TEXT("Department"));
            AcademicAdministrator->Major = JsonObj->GetStringField(TEXT("Major"));
            AcademicAdministrator->Title = JsonObj->GetStringField(TEXT("Title"));
            AcademicAdministrator->PoliticalStatus = JsonObj->GetStringField(TEXT("PoliticalStatus"));
            AcademicAdministrator->Position = JsonObj->GetStringField(TEXT("Position"));
            LoadedPersons.Add(AcademicAdministrator);
        }
        // 其他类型（实验员、行政人员等）同理判断...
    }

    return LoadedPersons;
}