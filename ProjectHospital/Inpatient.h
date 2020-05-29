#pragma once
#include "Patients.h"

// Class nệnh nhân nội trú
class Inpatient :
    public Patients
{
private:
    // Ngày nhập viện
    Date hospitalizeDate;
    // Ngày ra viện
    Date dischargeDate;
    // Tên khoa
    string departmentName;
    // Số giường
    string bedId;
public:
    Inpatient();
    Inpatient(string id, string n, string dB, bool gen, string dia, string hD, string dD, string dN, string bI);
    // Hiện thị thông tin
    void display();
    ~Inpatient();
};

