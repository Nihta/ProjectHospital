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

ReferralPatients::ReferralPatients(fstream& data) : Patients(data) {
    string date;
    getline(data, date);
    this->tranferDate = Date(date);
    getline(data, this->transferPlace);
}

void ReferralPatients::display() {
    Patients::display();
    cout << std::right << "|" << setw(20) << "Ngay chuyen vien: " << std::left << setw(58) << this->tranferDate << "|\n"
        << std::right << "|" << setw(20) << "Noi chuyen vien: " << std::left << setw(58) << this->transferPlace << "|\n";
}

void ReferralPatients::writeToFile(fstream &file) {
    Patients::writeToFile(file);
    file << this->tranferDate << "\n"
        << this->transferPlace << "\n";
}

ReferralPatients::~ReferralPatients() {

}