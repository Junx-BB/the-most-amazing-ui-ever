// Fill out your copyright notice in the Description page of Project Settings.


#include "AcademicAdministrator.h"

UAcademicAdministrator::UAcademicAdministrator() :
    UTeacher(0, TEXT(""), 0, 0, TEXT(""), TEXT(""), TEXT("")), PoliticalStatus(TEXT("")), Position(TEXT("")) {
}
UAcademicAdministrator::UAcademicAdministrator(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InpuPoliticalStatus, FString InputPosition, FString InputDepartment, FString InputMajor, FString InputTitle) :
    UTeacher(InputId, InputName, InputSex, InputAge, InputDepartment, InputMajor, InputTitle), PoliticalStatus(InpuPoliticalStatus), Position(InputPosition) {
}

void UAcademicAdministrator::AcademicAdministratorInit(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InpuPoliticalStatus, FString InputPosition, FString InputDepartment, FString InputMajor, FString InputTitle)
{
    Id = InputId;
    Name = InputName;
    Sex = InputSex;
    Age = InputAge;
    PoliticalStatus = InpuPoliticalStatus;
    Position = InputPosition;
    Department = InputDepartment;
    Major = InputMajor;
    Title = InputTitle;
}

int UAcademicAdministrator::GetId()
{
    return Id;
}

FString UAcademicAdministrator::GetName()
{
    return Name;
}

int UAcademicAdministrator::GetSex()
{
    return Sex;
}

int UAcademicAdministrator::GetAge()
{
    return Age;
}

FString UAcademicAdministrator::GetPoliticalStatus()
{
    return PoliticalStatus;
}

FString UAcademicAdministrator::GetPosition()
{
    return Position;
}

FString UAcademicAdministrator::GetDepartment()
{
    return Department;
}

FString UAcademicAdministrator::GetMajor()
{
    return Major;
}

FString UAcademicAdministrator::GetTitle()
{
    return Title;
}