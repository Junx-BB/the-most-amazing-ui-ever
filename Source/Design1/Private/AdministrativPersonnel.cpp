// Fill out your copyright notice in the Description page of Project Settings.


#include "AdministrativPersonnel.h"

UAdministrativPersonnel::UAdministrativPersonnel() :
    UPersonnel(0, TEXT(""), 0, 0), PoliticalStatus(TEXT("")), Position(TEXT("")) {
}

UAdministrativPersonnel::UAdministrativPersonnel(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InpuPoliticalStatus, FString InputPosition) :
    UPersonnel(InputId, InputName, InputSex, InputAge), PoliticalStatus(InpuPoliticalStatus), Position(InputPosition) {
}

void UAdministrativPersonnel::AdministrativPersonnelInit(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InpuPoliticalStatus, FString InputPosition)
{
    Id = InputId;
    Name = InputName;
    Sex = InputSex;
    Age = InputAge;
    PoliticalStatus = InpuPoliticalStatus;
    Position = InputPosition;
}

int UAdministrativPersonnel::GetId()
{
    return Id;
}

FString UAdministrativPersonnel::GetName()
{
    return Name;
}

int UAdministrativPersonnel::GetSex()
{
    return Sex;
}

int UAdministrativPersonnel::GetAge()
{
    return Age;
}

FString UAdministrativPersonnel::GetPoliticalStatus()
{
    return PoliticalStatus;
}

FString UAdministrativPersonnel::GetPosition()
{
    return Position;
}

