#include "Personnel.h"

// 构造函数实现
UPersonnel::UPersonnel() :
    // 默认初始化
    Id(0), Name(TEXT("")), Sex(0), Age(0) {
}

UPersonnel::UPersonnel(int32 InputId, FString InputName, int32 InputSex, int32 InputAge) :
    Id(InputId), Name(InputName), Sex(InputSex), Age(InputAge) {
}

int UPersonnel::GetId()
{
    return Id;
}

FString UPersonnel::GetName()
{
    return Name;
}

int UPersonnel::GetSex()
{
    return Sex;
}

int UPersonnel::GetAge()
{
    return Age;
}