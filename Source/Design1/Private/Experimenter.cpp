// Fill out your copyright notice in the Description page of Project Settings.


#include "Experimenter.h"

UExperimenter::UExperimenter() :
    UPersonnel(0, TEXT(""), 0, 0), Lab(TEXT("")), Duty(TEXT("")) {
}

UExperimenter::UExperimenter(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InputLab, FString InputDuty) :
    UPersonnel(InputId, InputName, InputSex, InputAge), Lab(InputLab), Duty(InputDuty) {
}

void UExperimenter::ExperimenterInit(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InputLab, FString InputDuty)
{
    Id = InputId;
    Name = InputName;
    Sex = InputSex;
    Age = InputAge;
    Lab = InputLab;
    Duty = InputDuty;
}

int UExperimenter::GetId()
{
    return Id;
}

FString UExperimenter::GetName()
{
    return Name;
}

int UExperimenter::GetSex()
{
    return Sex;
}

int UExperimenter::GetAge()
{
    return Age;
}

FString UExperimenter::GetLab()
{
    return Lab;
}

FString UExperimenter::GetDuty()
{
    return Duty;
}