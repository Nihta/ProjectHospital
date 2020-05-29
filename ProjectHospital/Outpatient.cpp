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

void Outpatient::display() {
    Patients::display();
    cout << setw(20) << "Ngay kham: " << this->examinationDate << "\n"
        << setw(20) << "Bao hiem y te so: " << this->healthInsurance << "\n"
        << setw(20) << "Ma toa thuoc: " << this->prescription << "\n";
}

Outpatient::~Outpatient() {

}