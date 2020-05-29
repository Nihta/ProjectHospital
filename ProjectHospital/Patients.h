#pragma once
#include <iostream>
#include <iomanip>
#include "Date.h"
using namespace std;
// Class bệnh nhân
class Patients
{
protected:
	// Mã hồ sơ
	string id;
	// Họ tên
	string name;
	// Ngày sinh
	Date dateOfBirth;
	// Giới tính (true là nam)
	bool gender = true;
	// Chuẩn đoán bệnh
	string diagnosis;
public:
	Patients();
	Patients(string id, string name, string dateOfBirth, bool gender, string diagnosis);
	// Hiện thị thông tin
	virtual void display();
	~Patients();
};

