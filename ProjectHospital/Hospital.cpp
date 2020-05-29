#include "Hospital.h"

void Hospital::menu() {
	bool isExit = false;
	while (!isExit)
	{
		system("cls");
		cout << "--------------------- Menu ---------------------" << endl;
		cout << "1. Them ho so benh nhan\n"
			<< "2. Hien thi ho so benh an\n";

		int option;
		cin >> option;
		cin.ignore();

		switch (option)
		{
		case 1:
			system("cls");
			this->add();
			getchar();
			break;
		case 2:
			system("cls");
			this->show();
			getchar();
			break;
		default:
			break;
		}

	}
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
	}
	break;
	case 2:
	{
		system("cls");
		Patients* tmp = new Outpatient();
		this->listOutpatient.push_back(tmp);
	}
	break;
	case 3:
	{
		system("cls");
		Patients* tmp = new ReferralPatients();
		this->listReferralPatients.push_back(tmp);
	}
	break;
	}
}

void Hospital::show() {
	cout << "[ Chon loai benh nhan can hien thi]\n"
		<< "\t1. Benh nhan noi tru\n"
		<< "\t2. Benh nhan ngoai tru\n"
		<< "\t3. Benh nhan chuyen vien\n";

	int option;
	cin >> option;
	cin.ignore();

	switch (option)
	{
	case 1:
		for (int i = 0; i < this->listInpatient.size(); i++) {
			this->listInpatient[i]->display();
			cout << string(30, '-') << endl;
		}
		break;
	case 2:
		for (int i = 0; i < this->listOutpatient.size(); i++) {
			this->listOutpatient[i]->display();
			cout << string(30, '-') << endl;
		}
		break;
	case 3:
		for (int i = 0; i < this->listReferralPatients.size(); i++) {
			this->listReferralPatients[i]->display();
			cout << string(30, '-') << endl;
		}
		break;
	}
}