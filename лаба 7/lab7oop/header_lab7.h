#define _CRT_SECURE_NO_WARNINGS
#ifndef LAB7_FUNC_H
#define LAB7_FUNC_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <clocale>
#include <list>
#include <algorithm>

using namespace std;



class supplier {

private:
	char* name;
	char* adress;
	double saldo;

public:
	supplier();
	supplier(char* entered_name, char* entered_adress, double entered_saldo);
	supplier(const supplier& sup);
	~supplier();
	void operator = (const supplier& obj);
	friend istream& operator>> (istream& in, supplier& A);
	friend bool operator== (supplier& A, supplier& B);
	void set_name();
	void set_adress();
	void set_saldo();
	void set_name(char* entered_name);
	void set_adress(char* entered_adress);
	void set_saldo(double entered_saldo);
	char* get_name();
	char* get_adress();
	double get_saldo();

};

list<supplier> add_supplier(list<supplier> l, int n, int par);
void list_supplier(list<supplier> l);
void save_supplier(list<supplier> l);
list<supplier> load_supplier(list<supplier> l);
void menu(list<supplier> l);
void find_name(list<supplier> l, char* name);
list<supplier> sort_saldo(list<supplier> l);
list<supplier> pop_front_supplier(list<supplier> l);
#endif