#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
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
	// Ngày ra viện
	Date dischargeDate = Date("0/0/0");
public:
	Patients();
	Patients(string id, string name, string dateOfBirth, bool gender, string diagnosis, string dischargeDate);
	// Khởi tạo đối tượng mới từ file
	Patients(fstream &data);
	string getId();
	string getName();
	// Hiện thị thông tin
	virtual void display();
	// Ghi thông tin vào file;
	virtual void writeToFile(fstream& file);
	// Lấy tất cả thông tin
	vector<string> getAllData();
	~Patients();
};

