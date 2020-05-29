#pragma once
#include "Patients.h"
class Outpatient :
    public Patients
{
private:
    // Ngày khám
    Date examinationDate;
    // Sổ bảo hiểm y tế (0 nếu không có)
    string healthInsurance; 
    // Mã toa thuốc
    string prescription;
public:
    Outpatient();
    Outpatient(string id, string n, string dB, bool gen, string dia, string eD, string hI, string pr);
    void display();
    ~Outpatient();
};

