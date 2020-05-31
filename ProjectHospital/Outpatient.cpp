#include "Outpatient.h"

Outpatient::Outpatient() : Patients() {
    cout << "Nhap ngay kham (nhap 0 la ngay hien tai): ";
    string date;
    getline(cin, date);
    this->examinationDate = (date == "0") ? Date() : Date(date);

    cout << "Nhap ma so bao hiem y te (nhap 0 neu khong co): ";
    getline(cin, this->healthInsurance);

    cout << "Nhap ma toa thuoc: ";
    getline(cin, this->prescription);
}

Outpatient::Outpatient(string id, string n, string dB, bool gen, string dia, string eD, string hI, string pr) :
Patients(id, n, dB, gen, dia) {
    this->examinationDate = Date(eD);
    this->healthInsurance = hI;
    this->prescription = pr;
}

Outpatient::Outpatient(fstream& data) : Patients(data) {
    string date;
    getline(data, date);
    this->examinationDate = Date(date);
    getline(data, this->healthInsurance);
    getline(data, this->prescription);
}

void Outpatient::display() {
    Patients::display();
    cout << std::right << "|" << setw(20) << "Ngay kham: " << std::left << setw(58) << this->examinationDate << "|\n"
        << std::right << "|" << setw(20) << "Bao hiem y te so: " << std::left << setw(58) << this->healthInsurance << "|\n"
        << std::right << "|" << setw(20) << "Ma toa thuoc: " << std::left << setw(58) << this->prescription << "|\n";
}

void Outpatient::writeToFile(fstream &file) {
    Patients::writeToFile(file);
    file << this->examinationDate << "\n"
        << this->healthInsurance << "\n"
        << this->prescription << "\n";
}

Outpatient::~Outpatient() {

}