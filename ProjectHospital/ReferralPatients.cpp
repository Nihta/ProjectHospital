#include "ReferralPatients.h"

ReferralPatients::ReferralPatients() : Patients() {
    cout << "Nhap ngay chuyen vien (nhap 0 de chon ngay hien tai): ";
    string date;
    getline(cin, date);
    this->tranferDate = (date == "0") ? Date() : Date(date);
    
    cout << "Nhap noi chuyen: ";
    getline(cin, this->transferPlace);
}

ReferralPatients::ReferralPatients(string id, string n, string dB, bool gen, string dia, string tD, string tP) : 
    Patients(id, n, dB, gen, dia) {
    this->tranferDate = Date(tD);
    this->transferPlace = tP;
}

void ReferralPatients::display() {
    Patients::display();
    cout << setw(20) << "Ngay chuyen vien: " << this->tranferDate << "\n"
        << setw(20) << "Noi chuyen vien: " << this->transferPlace << "\n";
}

ReferralPatients::~ReferralPatients() {

}