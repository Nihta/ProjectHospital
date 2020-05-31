#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <conio.h>
#include "Patients.h"
#include "Inpatient.h"
#include "Outpatient.h"
#include "ReferralPatients.h"
using namespace std;

class Hospital
{
private:
	vector<Patients *> listInpatient;
	vector<Patients *> listOutpatient;
	vector<Patients *> listReferralPatients;

public:
	Hospital();
	// Đọc thông từ file
	void readDataFromFile(string fileName);
	// Ghi thông tin vào file
	void writeDataToFile(string fileName, vector<Patients*> data);
	// Thêm hồ sơ
	void add();
	// Hiện thị hồ sơ bệnh án
	void show();
	// Tìm kiếm hồ sơ theo id
	Patients* findPatientsWithId(string id);
	// Tìm kiếm hồ sơ theo tên
	vector<Patients* > findPatientsWithName(string name);
	// Tìm kiếm hồ sơ
	void find();
	// Sửa hồ sơ
	bool edit(string id);
	// Xóa hồ sơ
	bool del(string id);
	// Chuyển viện
	void changeType();
	// Thống kê
	void statistical();
	void menu();

};

