#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "header_lab7.h"

using namespace std;

supplier::supplier() {
	name = new char[strlen("none") + 1];
	strcpy(name, "none");
	adress = new char[strlen("none") + 1];
	strcpy(adress, "none");
	saldo = 0;
}
supplier::supplier(char* entered_name, char* entered_adress, double entered_saldo) {
	name = new char[strlen(entered_name) + 1];
	strcpy(name, entered_name);
	adress = new char[strlen(entered_adress) + 1];
	strcpy(adress, entered_adress);
	saldo = entered_saldo;
}
supplier::supplier(const supplier& sup) {
	name = new char[strlen(sup.name) + 1];
	strcpy(name, sup.name);
	adress = new char[strlen(sup.adress) + 1];
	strcpy(adress, sup.adress);
	saldo = sup.saldo;
}
supplier::~supplier() {
	delete[] name;
	delete[] adress;
}
void supplier::operator = (const supplier& obj) {
	delete[] name;
	name = new char[strlen(obj.name) + 1];
	strcpy(name, obj.name);
	delete[] adress;
	adress = new char[strlen(obj.adress) + 1];
	strcpy(adress, obj.adress);
	saldo = obj.saldo;
}

void supplier::set_name() {
	delete[] name;
	char buff[500];
	while (true) {
		int i = 0;
		bool k = false;
		cout << "������� ����� �������� �����: ";
		cin.getline(buff, 500, '\n');
		while (buff[i]) {
			if (isalpha(buff[i])) i++;
			else {
				cout << "������� ������ �����!" << endl;
				k = true;
				break;
			}
		}
		if (k == false) break;
	}

	name = new char[strlen(buff) + 1];
	strcpy(name, buff);
}
void supplier::set_adress() {
	delete[] adress;
	char buff[500];
	while (true) {
		int i = 0;
		bool k = false;
		cout << "������� ����� �����: ";
		cin.getline(buff, 500, '\n');
		while (buff[i]) {
			if (isalnum(buff[i])) i++;
			else {
				cout << "������� ������ ����� � �����!" << endl;
				k = true;
				break;
			}
		}
		if (k == false) break;
	}
	adress = new char[strlen(buff) + 1];
	strcpy(adress, buff);
}
void supplier::set_saldo()
{
	double sal;
	while (true) {
		cout << "������� ������: ";
		cin >> sal;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������ �����, ���������� ��� ���" << endl;
		}
		else {
			cin.ignore(32767, '\n');
			break;
		}
	}
	saldo = sal;
}
void supplier::set_name(char* entered_name) {
	delete[] name;
	name = new char[strlen(entered_name) + 1];
	strcpy(name, entered_name);
}
void supplier::set_adress(char* entered_adress) {
	delete[] adress;
	adress = new char[strlen(entered_adress) + 1];
	strcpy(adress, entered_adress);
}
void supplier::set_saldo(double entered_saldo) {
	saldo = entered_saldo;
}
char* supplier::get_name() {
	return name;
}
char* supplier::get_adress() {
	return adress;
}
double supplier::get_saldo() {
	return saldo;
}

istream& operator>> (istream& in, supplier& A)
{
	char buff[4096];
	while (true) {
		int i = 0;
		bool k = false;
		cout << "������� ����� �������� �����: ";
		in >> buff;
		while (buff[i]) {
			if (isalpha(buff[i])) i++;
			else {
				cout << "������� ������ �����!" << endl;
				k = true;
				break;
			}
		}
		if (k == false) break;
	}
	A.set_name(buff);
	while (true) {
		int i = 0;
		bool k = false;
		cout << "������� ����� �����: ";
		in >> buff;
		while (buff[i]) {
			if (isalnum(buff[i])) i++;
			else {
				cout << "������� ������ ����� � �����!" << endl;
				k = true;
				break;
			}
		}
		if (k == false) break;
	}
	A.set_adress(buff);
	while (true) {
		cout << "������� ������: ";
		in >> A.saldo;
		if (in.fail()) {
			in.clear();
			in.ignore(32767, '\n');
			cout << "������ �����, ���������� ��� ���" << endl;
		}
		else {
			cin.ignore(32767, '\n');
			break;
		}
	}
	return in;
}
ostream& operator<< (ostream& out, supplier& A)
{
	cout <<"|"<< setw(20) << A.get_name() <<"|"<< setw(20) << A.get_adress() <<"|"<< setw(15) << A.get_saldo()<<"|" << endl;
	return out;
}
bool operator== (supplier& A, supplier& B)
{
	return ((strcmp(A.get_name(), B.get_name()) == 0) && (strcmp(A.get_adress(), B.get_adress()) == 0) && (A.get_saldo() == B.get_saldo()));
}

class Comp1		//�������� ��� ���������� �� ��������
{
public:
	bool operator()(supplier& p1, supplier& p2)
	{
		if (p1.get_saldo() > p2.get_saldo()) return 1;
		else return 0;
	}
};
list<supplier> add_supplier(list<supplier> l, int n, int par)
{
	// 1 - push_front, 2 - push_back, 3 - insert
	int pos;
	list<supplier>::iterator it = l.begin();
	if (par == 3) {
		while (true) {
			cout << "������� ������� ��� ����������\n";
			cin >> pos;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "������ �����, ���������� ��� ���\n";
			}
			else {
				cin.ignore(32767, '\n');
				break;
			}
		}
		for (int i = 0; i < pos; i++)
			it++;
	}
	for (int i = 0; i < n; i++) {
		supplier temp;
		cout << "--------------------------\n";
		cout << "������� ������ ��� " << i + 1 << " ����������:\n";
		temp.set_name();
		temp.set_adress();
		temp.set_saldo();
		switch (par) {
		case 1:
			l.push_front(temp);
			break;

		case 2:
			l.push_back(temp);
			break;

		case 3:
			l.insert(it, temp);
			break;
		}
	}
	return l;
}

void list_supplier(list<supplier> l)
{
	cout <<"|"<< setw(20) << "��������" << "|" << setw(20) << "����������� �����" << "|" << setw(15) << "������" << "|" << endl;
	cout << "-----------------------------------------------------------\n";

	for (list<supplier>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it;
	}
	cout << "-----------------------------------------------------------\n";
}
void save_supplier(list<supplier> l)
{
	ofstream fout;
	fout.open("data.txt", ofstream::trunc);
	if (!fout.is_open()) {
		cout << "������ �������� �����" << endl;
	}
	else {
		fout << l.size() << "\n";
		for (list<supplier>::iterator it = l.begin(); it != l.end(); it++) {
			fout << it->get_name() << "\n";
			fout << it->get_adress() << "\n";
			fout << it->get_saldo() << "\n";
		}
		cout << "���� ������� ��������!" << endl;
	}
	fout.close();
}
list<supplier> load_supplier(list<supplier> l) {

	ifstream fin;
	int size;
	fin.open("data.txt");
	if (!fin.is_open()) {
		cout << "������ �������� �����" << endl;
	}
	else {
		fin >> size;
		l.resize(size);
		for (list<supplier>::iterator it = l.begin(); it != l.end(); it++) {
			char* name = new char[100];
			char* adress = new char[100];
			fin >> name;
			double saldo;
			fin >> adress;
			fin >> saldo;
			it->set_name(name);
			it->set_adress(adress);
			it->set_saldo(saldo);
			delete[] name;
			delete[] adress;
		}

	}
	fin.close();
	return l;
}
void menu(list<supplier> l) {

	int choose;
	while (true) {

		cout << endl << "1)  �������� ����������\n";
		cout << "2)  �������� �����������\n";
		cout << "3)  ����� �����\n";
		cout << "4)  ���������� �� ������\n";
		cout << "5)  ��������� ������\n";
		cout << "6)  ������� ����������� �� ������\n";
		cout << "7)  ��������� ���������\n";
		cout << "-----------------------------------------\n";
		while (true) {
			cout << "������� ����� �������: ";
			cin >> choose;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "������ �����, ���������� ��� ���\n";
			}
			else {
				cin.ignore(32767, '\n');
				break;
			}
		}
		if (choose == 1) {
			//system("cls");
			int n, par;
			while (true) {
				cout << "������� ����������� �� ������ ��������?\n";
				cin >> n;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "������ �����, ���������� ��� ���\n";
				}
				else if (n <= 0)
					cout << "���� ������ ����� ������ 0!\n";
				else {
					cin.ignore(32767, '\n');
					break;
				}
			}
			//system("cls");
			while (true) {
				cout << "1 - �������� � ������\t2 - �������� � �����\t3 - �������� � ������ �������\n";
				if (n == 1)
					cout << "���� �� ������ �������� ����������?\n";
				else
					cout << "���� �� ������ �������� �����������?\n";
				cin >> par;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "������ �����, ���������� ��� ���\n";
				}
				else if (par != 1 && par != 2 && par != 3) {
					cout << "�� ����� ������������ ��������!";
				}
				else {
					cin.ignore(32767, '\n');
					break;
				}
			}
			//system("cls");
			l = add_supplier(l, n, par);			
		}
		if (choose == 2) {
			//system("cls");
			list_supplier(l);
			
		}
		if (choose == 3) {
			char buff[500];
			while (true) {
				int i = 0;
				bool k = false;
				cout << "������� �������� �����: ";
				cin.getline(buff, 500, '\n');
				while (buff[i]) {
					if (isalpha(buff[i])) i++;
					else {
						cout << "������� ������ �����!" << endl;
						k = true;
						break;
					}
				}
				if (k == false) break;
			}
			char* name = new char[strlen(buff) + 1];
			strcpy(name, buff);
			//system("cls");
			find_name(l, name);
			delete[] name;			
		}
		if (choose == 4) {
			l = sort_saldo(l);			
		}
		if (choose == 5) {
			save_supplier(l);			
		}
		if (choose == 6) {
			l = pop_front_supplier(l);			
		}
		if (choose == 7) {
			break;
		}
		else
			continue;
	}
};
void find_name(list<supplier> l, char* name) {

	cout << endl << "���������� � �����:  " <<"\""<< name << "\"" << endl;
	cout << "-------------------------------------" << endl;
	cout << "|" << setw(20) << "����������� �����" << "|" << setw(15) << "������" << "|" << endl;
	cout << "-------------------------------------" << endl;
	for (list<supplier>::iterator it = l.begin(); it != l.end(); it++) {
		if (strcmp(name, it->get_name()) == 0) {
			cout <<"|"<< setw(20) << it->get_adress() <<"|"<< setw(15) << it->get_saldo() << "|" << endl;
		}
	}

};
list<supplier>  sort_saldo(list<supplier> l)
{
	l.sort(Comp1());
	list_supplier(l);
	return l;
}
list<supplier> pop_front_supplier(list<supplier> l)
{
	int n;
	while (true) {
		cout << "������� ��������� �� ������ �������?\n";
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������ �����, ���������� ��� ���\n";
		}
		if (n > l.size())
			cout << "������� ����� ������ ������� ������ �����!\n";
		else {
			cin.ignore(32767, '\n');
			break;
		}
	}
	for (int i = 0; i < n; i++)
		l.pop_front();
	cout << "���������� �������!";
	return l;
}