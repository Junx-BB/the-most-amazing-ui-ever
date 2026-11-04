// Fill out your copyright notice in the Description page of Project Settings.


#include "Teacher.h"

UTeacher::UTeacher() :
    UPersonnel(0, TEXT(""), 0, 0), Department(TEXT("")), Major(TEXT("")), Title(TEXT("")) {}

UTeacher::UTeacher(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InputDepartment, FString InputMajor, FString InputTitle) :
    UPersonnel(InputId, InputName, InputSex, InputAge), Department(InputDepartment), Major(InputMajor), Title(InputTitle) {
}

void UTeacher::TeacherInit(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InputDepartment, FString InputMajor, FString InputTitle)
{
    Id = InputId;
    Name = InputName;
    Sex = InputSex;
    Age = InputAge;
    Department = InputDepartment;
    Major = InputMajor;
    Title = InputTitle;
}

int UTeacher::GetId()
{
    return Id;
}

FString UTeacher::GetName()
{
    return Name;
}

int UTeacher::GetSex()
{
    return Sex;
}

int UTeacher::GetAge()
{
    return Age;
}

FString UTeacher::GetDepartment()
{
    return TEXT("");
}

FString UTeacher::GetMajor()
{
    return TEXT("");
}

FString UTeacher::GetTitle()
{
    return TEXT("");
}




