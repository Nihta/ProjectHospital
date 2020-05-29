#include "Inpatient.h"

Inpatient::Inpatient() : Patients() {
	cout << "Nhap nhay nhap vien (Nhap 0 la ngay hom nay): ";
	string date;
	getline(cin, date);
	this->hospitalizeDate = (date == "0") ? Date() : Date(date);

	cout << "Nhap ngay ra vien: ";
	getline(cin, date);
	this->dischargeDate = Date(date);

	cout << "Nhap ten khoa dieu tri: ";
	getline(cin, this->departmentName);

	cout << "Nhap so giuong: ";
	getline(cin, this->bedId);
}

Inpatient::Inpatient(string id, string n, string dB, bool gen, string dia, string hD, string dD, string dN, string bI) :
	Patients(id, n, dB, gen, dia) {
	this->hospitalizeDate = Date(hD);
	this->dischargeDate = Date(dD);
	this->departmentName = dN;
	this->bedId = bI;
}

void Inpatient::display() {
	Patients::display();
	cout << setw(20) << "Ngay nhap vien: " << this->hospitalizeDate << "\n"
		<< setw(20) << "Nhay ra vien: " << this->dischargeDate << "\n"
		<< setw(20) << "Ten khoa dieu tri: " << this->departmentName << "\n"
		<< setw(20) << "So giuong: " << this->bedId << "\n";
}

Inpatient::~Inpatient() {

}