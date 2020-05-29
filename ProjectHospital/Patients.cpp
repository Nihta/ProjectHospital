#include "Patients.h"

Patients::Patients() {
	cout << "Nhap ma ho so: ";
	getline(cin, this->id);

	cout << "Nhap ten banh nhan: ";
	getline(cin, this->name);

	cout << "Nhap ngay sinh benh nhan: ";
	string date;
	getline(cin, date);
	this->dateOfBirth = Date(date);

	cout << "Nhap gioi tinh benh nhan (1 -> Nam, 0 -> Nu): ";
	string tmp;
	getline(cin, tmp);
	this->gender = (tmp == "0")? false : true;

	cout << "Nhap chuan doan benh: ";
	getline(cin, this->diagnosis);
}

Patients::Patients(string id, string name, string dateOfBirth, bool gender, string diagnosis) {
	this->id = id;
	this->name = name;
	this->dateOfBirth = Date(dateOfBirth);
	this->gender = gender;
	this->diagnosis = diagnosis;
}

void Patients::display() {
	cout << setw(20) << "Ma ho so benh an: " << this->id << "\n"
		<< setw(20) << "Ho va ten: " << this->name << "\n"
		<< setw(20) << "Ngay sinh: " << this->dateOfBirth << "\n"
		<< setw(20) << "Gioi tinh: " << (this->gender ? "Nam" : "Nu") << "\n"
		<< setw(20) << "Chuan doan benh: " << this->diagnosis << "\n";
}

Patients::~Patients() {

}