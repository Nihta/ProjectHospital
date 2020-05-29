#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
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
	// Thêm hồ sơ bệnh nhân
	void add();
	// Hiện thị hồ sơ bệnh án
	void show();
	void menu();

};

