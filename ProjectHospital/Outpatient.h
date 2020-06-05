#pragma once
#include "Patients.h"
// Class bệnh nhân ngoại trú
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
    Outpatient(string id, string n, string dB, bool gen, string dia, string dD, string eD, string hI, string pr);
    // Khởi tạo từ file
    Outpatient(fstream& data);
    // Hiện thị 
    void display();
    // Ghi thông tin vào file;
    void writeToFile(fstream& file);
    ~Outpatient();
};

