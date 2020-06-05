#pragma once
#include "Patients.h"

// Class nệnh nhân nội trú
class Inpatient :
    public Patients
{
private:
    // Ngày nhập viện
    Date hospitalizeDate;
    // Tên khoa
    string departmentName;
    // Số giường
    string bedId;
public:
    Inpatient();
    Inpatient(string id, string n, string dB, bool gen, string dia, string dD, string hD, string dN, string bI);
    // Khởi tạo đối tượng mới từ file
    Inpatient(fstream &data);
    // Hiện thị thông tin
    void display();
    // Ghi thông tin vào file;
    virtual void writeToFile(fstream& file);
    ~Inpatient();
};

