#pragma once
#include "Patients.h"

// Class bệnh nhân chuyển viện
class ReferralPatients :
    public Patients
{
private:
    // Ngày chuyển
    Date tranferDate;
    // Nơi chuyển
    string transferPlace;
    // Tình trạng
    string status;
public:
    ReferralPatients();
    ReferralPatients(string id, string n, string dB, bool gen, string dia, string dD, string tD, string tP, string st);
    // Khởi tạo từ file
    ReferralPatients(fstream& data);
    // Hiện thị thông tin
    void display();
    // Ghi thông tin vào tệp
    void writeToFile(fstream& file);
    ~ReferralPatients();
};

