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

Patients::Patients(string id, string name, string dateOfBirth, bool gender, string diagnosis, string dischargeDate) {
	this->id = id;
	this->name = name;
	this->dateOfBirth = Date(dateOfBirth);
	this->gender = gender;
	this->diagnosis = diagnosis;
	this->dischargeDate = Date(dischargeDate);
}

string Patients::getId() {
	return this->id;
}

string Patients::getName() {
	return this->name;
}

Patients::Patients(fstream& data) {
	getline(data, this->id);
	getline(data, this->name);
	string date;
	getline(data, date);
	this->dateOfBirth = Date(date);
	string bl;
	getline(data, bl);
	this->gender = (bl == "1") ? true : false;
	getline(data, this->diagnosis);
	getline(data, date);
	this->dischargeDate = Date(date);
}

void Patients::display() {
	cout << std::right << "|" << setw(20) << "Ma ho so benh an: " << std::left  << setw(58) << this->id << "|\n"
		<< std::right << "|" << setw(20) << "Ho va ten: " << std::left << setw(58) << this->name << "|\n"
		<< std::right << "|" << setw(20) << "Ngay sinh: " << std::left << setw(58) << this->dateOfBirth << "|\n"
		<< std::right << "|" << setw(20) << "Gioi tinh: " << std::left << setw(58) << (this->gender ? "Nam" : "Nu") << "|\n"
		<< std::right << "|" << setw(20) << "Chuan doan benh: " << std::left << setw(58) << this->diagnosis << "|\n";
}

void Patients::writeToFile(fstream &file) {
	file << this->id << "\n"
		<< this->name << "\n"
		<< this->dateOfBirth << "\n"
		<< (this->gender ? "1" : "0") << "\n"
		<< this->diagnosis << "\n"
		<< this->dischargeDate << "\n";
}

// { Mã hồ sơ, họ tên, ngày sinh, giới tính, chuẩn đoán }
vector<string> Patients::getAllData() {
	vector<string> res;
	res.push_back(this->id);
	res.push_back(this->name);
	res.push_back(this->dateOfBirth.toString());
	res.push_back(this->gender? "1" : "0");
	res.push_back(this->diagnosis);
	res.push_back(this->dischargeDate.toString());
	return res;
}

Patients::~Patients() {

}