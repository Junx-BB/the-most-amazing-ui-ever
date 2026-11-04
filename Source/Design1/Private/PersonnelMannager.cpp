// Fill out your copyright notice in the Description page of Project Settings.


#include "PersonnelMannager.h"

APersonnelMannager::APersonnelMannager()
{
}

APersonnelMannager::~APersonnelMannager()
{
}

void APersonnelMannager::UpdataAllPersonnelTypeCount()
{
	PersonnelCount = ArrPersonnels.Num();
	TeacherCount = ArrTeachers.Num();
	ExperimenterCount = ArrExperimenters.Num();
	AdministrativPersonnelCount = ArrAdministrativPersonnels.Num();
	AcademicAdministratorCount = ArrAcademicAdministrators.Num();
}

void APersonnelMannager::MakeArrPersonnelsInRow()
{
	if (ArrPersonnels.Num() != 0)
	{
		TArray<UPersonnel*> GetArrPersonnels = ArrPersonnels;
		TArray<UPersonnel*> TempArrPersonnels = ArrPersonnels;

		for (int i = 0; i < GetArrPersonnels.Num() - 1; i++)
		{
			for (int j = 0; j < GetArrPersonnels.Num() - 1; j++)
			{
				if (GetArrPersonnels[j]->Id > GetArrPersonnels[j + 1]->Id)
				{
					TempArrPersonnels[0] = GetArrPersonnels[j];
					GetArrPersonnels[j] = GetArrPersonnels[j + 1];
					GetArrPersonnels[j + 1] = TempArrPersonnels[0];
				}
			}
		}

		ArrPersonnels = GetArrPersonnels;
	}
}

void APersonnelMannager::InitArrPersonnels_Display(int32 InputIndex)
{
	ArrPersonnels_Display.Add(ArrPersonnels[InputIndex]);
}

void APersonnelMannager::CleanArrPersonnels_Display()
{
	TArray<UPersonnel*> TempArrPersonnels_Display;
	ArrPersonnels_Display = TempArrPersonnels_Display;
}

int APersonnelMannager::GetInitArrPersonnelsLength_Display()
{
	return ArrPersonnels_Display.Num();
}

void APersonnelMannager::CreateNewTeacher(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InputDepartment, FString InputMajor, FString InputTitle)
{
	// 创建新对象
	UTeacher* NewTeacher = NewObject<UTeacher>();

	// 对新创建的对象进行初始化 
	NewTeacher->TeacherInit(InputId, InputName, InputSex, InputAge, InputDepartment, InputMajor, InputTitle);

	// 将新对象添加到数组中
	ArrTeachers.Add(NewTeacher);  // 将指针存入数组
	ArrPersonnels.Add(NewTeacher); //  将指针存入总数组
}

void APersonnelMannager::CreateNewExperimenter(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InputLab, FString InputDuty)
{
	// 创建新对象
	UExperimenter* NewExperimenter = NewObject<UExperimenter>();

	// 对新创建的对象进行初始化 
	NewExperimenter->ExperimenterInit(InputId, InputName, InputSex, InputAge, InputLab,InputDuty);

	// 将新对象添加到数组中
	ArrExperimenters.Add(NewExperimenter);  // 将指针存入数组
	ArrPersonnels.Add(NewExperimenter); //  将指针存入总数组
}

void APersonnelMannager::CreateNewAdministrativPersonnel(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InpuPoliticalStatus, FString InputPosition)
{
	// 创建新对象
	UAdministrativPersonnel* NewAdministrativPersonnel = NewObject<UAdministrativPersonnel>();

	// 对新创建的对象进行初始化 
	NewAdministrativPersonnel->AdministrativPersonnelInit(InputId, InputName, InputSex, InputAge, InpuPoliticalStatus,InputPosition);

	// 将新对象添加到数组中
	ArrAdministrativPersonnels.Add(NewAdministrativPersonnel);  // 将指针存入数组
	ArrPersonnels.Add(NewAdministrativPersonnel); //  将指针存入总数组
}

void APersonnelMannager::CreateNewAcademicAdministrator(int32 InputId, FString InputName, int32 InputSex, int32 InputAge, FString InpuPoliticalStatus, FString InputPosition, FString InputDepartment, FString InputMajor, FString InputTitle)
{
	// 创建新对象
	UAcademicAdministrator* NewAcademicAdministrator = NewObject<UAcademicAdministrator>();

	// 对新创建的对象进行初始化 
	NewAcademicAdministrator->AcademicAdministratorInit(InputId, InputName, InputSex, InputAge, InpuPoliticalStatus, InputPosition,InputDepartment,InputMajor,InputTitle);

	// 将新对象添加到数组中
	ArrAcademicAdministrators.Add(NewAcademicAdministrator);  // 将指针存入数组
	ArrPersonnels.Add(NewAcademicAdministrator); //  将指针存入总数组
}

int APersonnelMannager::GetMaleCount()
{
	int32 MaleCount = 0;
	for (int i = 0; i < ArrPersonnels.Num(); i++)
	{
		if (ArrPersonnels[i]->Sex == 1)
		{
			MaleCount++;
		}
	}
	return MaleCount;
}

int APersonnelMannager::GetFemaleCount()
{
	int32 FemaleCount = 0;
	for (int i = 0; i < ArrPersonnels.Num(); i++)
	{
		if (ArrPersonnels[i]->Sex == 2)
		{
			FemaleCount++;
		}
	}
	return FemaleCount;
}

int APersonnelMannager::GetPersonnelBetween18to25Count()
{
	int32 PersonnelBetween18to25Count = 0;
	for (int i = 0; i < ArrPersonnels.Num(); i++)
	{
		if (ArrPersonnels[i]->Age <= 25 && ArrPersonnels[i]->Age >= 18)
		{
			PersonnelBetween18to25Count++;
		}
	}
	return PersonnelBetween18to25Count;
}
