#include "Inpatient.h"

Inpatient::Inpatient() : Patients() {
	cout << "Nhap nhay nhap vien (Nhap 0 la ngay hom nay): ";
	string date;
	getline(cin, date);
	this->hospitalizeDate = (date == "0") ? Date() : Date(date);

	cout << "Nhap ten khoa dieu tri: ";
	getline(cin, this->departmentName);

	cout << "Nhap so giuong: ";
	getline(cin, this->bedId);
}

Inpatient::Inpatient(string id, string n, string dB, bool gen, string dia, string dD, string hD, string dN, string bI) :
	Patients(id, n, dB, gen, dia, dD) {
	this->hospitalizeDate = Date(hD);
	this->departmentName = dN;
	this->bedId = bI;
}

Inpatient::Inpatient(fstream& data) : Patients(data) {
	string date;
	getline(data, date);
	this->hospitalizeDate = Date(date);
	getline(data, date);
	this->dischargeDate = Date(date);
	getline(data, this->departmentName);
	getline(data, this->bedId);
}

void Inpatient::display() {
	Patients::display();
	cout << std::right << "|" << setw(20) << "Ngay nhap vien: " << std::left << setw(58) << this->hospitalizeDate << "|\n"
		<< std::right << "|" << setw(20) << "Ten khoa dieu tri: " << std::left << setw(58) << this->departmentName << "|\n"
		<< std::right << "|" << setw(20) << "So giuong: " << std::left << setw(58) << this->bedId << "|\n";
}

void Inpatient::writeToFile(fstream& file) {
	Patients::writeToFile(file);
	file << this->hospitalizeDate << "\n"
		<< this->dischargeDate << "\n"
		<< this->departmentName << "\n"
		<< this->bedId << "\n";
}

Inpatient::~Inpatient() {

}