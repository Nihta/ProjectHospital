#include "Hospital.h"

Hospital::Hospital() {
	this->readDataFromFile("dataInpatient");
	this->readDataFromFile("dataOutpatient");
	this->readDataFromFile("dataReferralPatients");

}

// fileName: dataInpatient, dataOutpatient, dataReferralPatients
void Hospital::readDataFromFile(string fileName) {
	fstream data(fileName + ".txt", ios::in);
	if (data.fail())
	{
		// Nếu mở file thất bại thì tạo một file mới
		fstream data(fileName + ".txt", ios::out);
		data << "0\n";
	}
	else
	{
		int num;
		data >> num;
		data.ignore();
		while (num--)
		{
			if (fileName == "dataInpatient") {
				this->listInpatient.push_back(new Inpatient(data));
			}
			else if (fileName == "dataOutpatient") {
				this->listOutpatient.push_back(new Outpatient(data));
			}
			else if (fileName == "dataReferralPatients") {
				this->listReferralPatients.push_back(new ReferralPatients(data));
			}
			string blankLine;
			getline(data, blankLine);
		}
	}
	data.close();
}

// fileName: dataInpatient, dataOutpatient, dataReferralPatients
void Hospital::writeDataToFile(string fileName, vector<Patients *> data) {
	fstream file(fileName + ".txt", ios::out);
	file << data.size() << "\n";
	for (auto elm : data) {
		elm->writeToFile(file);
		file << "\n";
	}
	file.close();
}

void Hospital::add() {
	cout << "[ Chon loai benh nhan can them ]\n"
		<< "\t1. Benh nhan noi tru\n"
		<< "\t2. Benh nhan ngoai tru\n"
		<< "\t3. Benh nhan chuyen vien\n";

	int option;
	cin >> option;
	cin.ignore();

	switch (option)
	{
	case 1:
	{
		system("cls");
		Patients* tmp = new Inpatient();
		this->listInpatient.push_back(tmp);
		this->writeDataToFile("dataInpatient", this->listInpatient);
	}
	break;
	case 2:
	{
		system("cls");
		Patients* tmp = new Outpatient();
		this->listOutpatient.push_back(tmp);
		this->writeDataToFile("dataOutpatient", this->listOutpatient);
	}
	break;
	case 3:
	{
		system("cls");
		Patients* tmp = new ReferralPatients();
		this->listReferralPatients.push_back(tmp);
		this->writeDataToFile("dataReferralPatients", this->listReferralPatients);
	}
	break;
	}
}

void Hospital::show() {
	cout << "[ Chon loai benh nhan can hien thi ]\n"
		<< "\t1. Benh nhan noi tru\n"
		<< "\t2. Benh nhan ngoai tru\n"
		<< "\t3. Benh nhan chuyen vien\n";

	int option;
	cin >> option;
	cin.ignore();

	string stringBar = "+" + string(78, '-') + "+";
	system("cls");
	switch (option)
	{
	case 1:
		if (this->listInpatient.size() == 0) {
			cout << "Khong co ho so nao de hien thi!" << endl;
		} else {
			cout << stringBar << endl;
			for (unsigned int i = 0; i < this->listInpatient.size(); i++) {
				this->listInpatient[i]->display();
				cout << stringBar << endl;
			}
		}
		break;
	case 2:
		if (this->listOutpatient.size() == 0) {
			cout << "Khong co ho so nao de hien thi!" << endl;
		}
		else {
			cout << stringBar << endl;
			for (unsigned int i = 0; i < this->listOutpatient.size(); i++) {
				this->listOutpatient[i]->display();
				cout << stringBar << endl;
			}
		}
		break;
	case 3:
		if (this->listReferralPatients.size() == 0) {
			cout << "Khong co ho so nao de hien thi!" << endl;
		}
		else {
			cout << stringBar << endl;
			for (unsigned int i = 0; i < this->listReferralPatients.size(); i++) {
				this->listReferralPatients[i]->display();
				cout << stringBar << endl;
			}
		}
		break;
	}
}
Patients* Hospital::findPatientsWithId(string id) {
	for (auto& pa : this->listInpatient)
	{
		if (pa->getId() == id) {
			return pa;
		}
	}
	for (auto& pa : this->listOutpatient)
	{
		if (pa->getId() == id) {
			return pa;
		}
	}
	for (auto& pa : this->listReferralPatients)
	{
		if (pa->getId() == id) {
			return pa;
		}
	}
	return NULL;
}

vector<Patients*> Hospital::findPatientsWithName(string name) {
	vector<Patients*> res;
	for (auto& pa : this->listInpatient)
	{
		if (pa->getName() == name) {
			res.push_back(pa);
		}
	}
	for (auto& pa : this->listOutpatient)
	{
		if (pa->getName() == name) {
			res.push_back(pa);
		}
	}
	for (auto& pa : this->listReferralPatients)
	{
		if (pa->getName() == name) {
			res.push_back(pa);
		}
	}
	return res;
}

void Hospital::find() {
	cout << "[ Chon cach thuc tim kiem ]\n"
		<< "\t1. Tim kiem theo ma ho so\n"
		<< "\t2. Tim kiem theo ten\n";

	int option;
	cin >> option;
	cin.ignore();

	system("cls");
	switch (option)
	{
	case 1:
	{
		string id;
		cout << "Nhap ma ho so can tim kiem: ";
		getline(cin, id);
		Patients *pa = this->findPatientsWithId(id);
		if (pa == NULL) {
			cout << "Khong tim thay!" << endl;
		}
		else {
			system("cls");
			cout << "+" << string(78, '-') << "+" << endl;
			pa->display();
			cout << "+" << string(78, '-') << "+" << endl;
		}
	}
		break;
	case 2:
	{
		string name;
		cout << "Nhap ten nguoi can tim kiem: ";
		getline(cin, name);
		vector<Patients *> vPa = this->findPatientsWithName(name);
		if (vPa.size() == 0) {
			cout << "Khong tim thay!" << endl;
		}
		else {
			system("cls");
			cout << "+" << string(78, '-') << "+" << endl;
			for (auto& pa : vPa)
			{
				pa->display();
				cout << "+" << string(78, '-') << "+" << endl;
			}
		}

	}
		break;
	}
}

bool Hospital::edit(string id) {
	for (unsigned int i = 0; i < this->listInpatient.size(); i++)
	{
		if (this->listInpatient[i]->getId() == id) {
			cout << "Nhap thong tin moi cho ho so " << id << ":\n";
			*this->listInpatient[i] = *new Inpatient();
			this->writeDataToFile("dataInpatient", this->listInpatient);
			return true;
		}

	}
	for (unsigned int i = 0; i < this->listOutpatient.size(); i++)
	{
		if (this->listOutpatient[i]->getId() == id) {
			cout << "Nhap thong tin moi cho ho so " << id << ":\n";
			*this->listOutpatient[i] = *new Outpatient();
			this->writeDataToFile("dataOutpatient", this->listOutpatient);
			return true;
		}
	}
	for (unsigned int i = 0; i < this->listReferralPatients.size(); i++)
	{
		if (this->listReferralPatients[i]->getId() == id) {
			cout << "Nhap thong tin moi cho ho so " << id << ":\n";
			*this->listReferralPatients[i] = *new ReferralPatients();
			this->writeDataToFile("dataReferralPatients", this->listReferralPatients);
			return true;
		}
	}
	return false;
}

bool Hospital::del(string id) {
	for (unsigned int i = 0; i < this->listInpatient.size(); i++)
	{
		if (this->listInpatient[i]->getId() == id) {
			this->listInpatient.erase(this->listInpatient.begin() + i);
			this->writeDataToFile("dataInpatient", this->listInpatient);
			return true;
		}

	}
	for (unsigned int i = 0; i < this->listOutpatient.size(); i++)
	{
		if (this->listOutpatient[i]->getId() == id) {
			this->listOutpatient.erase(this->listOutpatient.begin() + i);
			this->writeDataToFile("dataOutpatient", this->listOutpatient);
			return true;
		}
	}
	for (unsigned int i = 0; i < this->listReferralPatients.size(); i++)
	{
		if (this->listReferralPatients[i]->getId() == id) {
			this->listReferralPatients.erase(this->listReferralPatients.begin() + i);
			this->writeDataToFile("dataReferralPatients", this->listReferralPatients);
			return true;
		}
	}
	return false;
}

void Hospital::changeType() {
	string id;
	cout << "Nhap ma ho so benh nhan can chuyen: ";
	getline(cin, id);
	int index = -1;
	Patients* pa = NULL;
	string type;
	for (unsigned int i = 0; i < this->listInpatient.size(); i++)
	{
		if (this->listInpatient[i]->getId() == id) {
			index = i;
			pa = this->listInpatient[i];
			type = "Inpatient";
			break;
		}
	}
	for (unsigned int i = 0; i < this->listOutpatient.size() && index == -1; i++)
	{
		if (this->listOutpatient[i]->getId() == id) {
			index = i;
			pa = this->listOutpatient[i];
			type = "Outpatient";
			break;
		}
	}
	if (index == -1) {
		cout << "Khong tim thay benh nhan can chuyen vien! Dam bao da la benh nhan noi tru hoac ngoai tru" << endl;
	}
	else
	{
		// { Mã hồ sơ, họ tên, ngày sinh, giới tính, chuẩn đoán }
		vector<string> data = pa->getAllData();
		string id = data[0];
		string n = data[1];
		string dB = data[2];
		bool gen = (data[3] == "1");
		string dia = data[4];
		string tD;
		cout << "Nhap ngay chuyen vien (nhap 0 la ngay hom nay): ";
		getline(cin, tD);
		if (tD == "0") {
			tD = Date().toString();
		}
		cout << "Nhap noi chuyen den: ";
		string tP;
		getline(cin, tP);
		Patients* newRP = new ReferralPatients(id, n, dB, gen, dia, tD, tP);
		this->listReferralPatients.push_back(newRP);
		this->writeDataToFile("dataReferralPatients", this->listReferralPatients);
		if (type == "Inpatient") {
			this->listInpatient.erase(this->listInpatient.begin() + index);
			this->writeDataToFile("dataInpatient", this->listInpatient);
		}
		else if (type == "Outpatient")
		{
			this->listOutpatient.erase(this->listOutpatient.begin() + index);
			this->writeDataToFile("dataOutpatient", this->listOutpatient);
		}
		system("cls");
		cout << "Chuyen thanh cong!" << endl;
	}

}

void Hospital::statistical() {
	cout << "+------------------ Thong ke -----------------+\n" << std::right
		<< "|" << setw(40) << "So luong ho so benh nhan noi tru: " << setw(5) << this->listInpatient.size() << "|\n"
		<< "|" << setw(40) << "So luong ho so benh nhan ngoai tru: " << setw(5) << this->listOutpatient.size() << "|\n"
		<< "|" << setw(40) << "So luong ho so benh nhan chuyen vien: " << setw(5) << this->listReferralPatients.size() << "|\n"
		<< "+" << string(45, '-') << "+\n";
}

void Hospital::menu() {
	bool isExit = false;
	while (!isExit)
	{
		system("cls");
		cout << "+------------ Menu ------------+" << endl;
		cout << "| " << std::left << setw(29)   << "1. Them ho so benh nhan" << "|\n"
			<< "| " << std::left << setw(29)   << "2. Hien thi ho so benh an" << "|\n"
			<< "| " << std::left << setw(29)<< "3. Tim kiem" << "|\n"
			<< "| " << std::left << setw(29)<< "4. Sua ho so" << "|\n"
			<< "| " << std::left << setw(29)<< "5. Xoa ho so" << "|\n"
			<< "| " << std::left << setw(29) << "6. Chuyen vien" << "|\n"
			<< "| " << std::left << setw(29)<< "7. Thong ke" << "|\n"
			<< "| " << std::left << setw(29)<< "0. Thoat" << "|\n"
			<< "+" + string(30, '-') + "+" << endl;

		int option;
		cin >> option;
		cin.ignore();

		system("cls");
		switch (option)
		{
		case 1:
			this->add();
			getchar();
			break;
		case 2:
			this->show();
			getchar();
			break;
		case 3:
			this->find();
			getchar();
			break;
		case 4:
		{
			string id;
			cout << "Nhap ma ho so can xoa: ";
			getline(cin, id);
			system("cls");
			if (this->edit(id)) {
				cout << "Sua thong tin thanh cong!" << endl;
			}
			else {
				cout << "Khong tim thay ho so!" << endl;
			}
			getchar();
		}
			break;
		case 5:
		{
			string id;
			cout << "Nhap ma ho so can xoa: ";
			getline(cin, id);
			system("cls");
			if (this->del(id)) {
				cout << "Xoa thanh cong!" << endl;
			}
			else {
				cout << "Xoa that bai! Khong tim thay ho so." << endl;
			}
			getchar();
		}
			break;
		case 6:
			this->changeType();
			getchar();
			break;
		case 7:
			this->statistical();
			getchar();
			break;
		case 0:
			isExit = true;
			break;
		}

	}
}
