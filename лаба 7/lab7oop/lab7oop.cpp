#define _CRT_SECURE_NO_WARNINGS
#include "header_lab7.h"

int main() {

	setlocale(LC_ALL, "Russian");

	ifstream fin;
	list<supplier> l;
	fin.open("data.txt");
	if (!fin.is_open()) {
		cout << "Файла нет, инициализация с клавиатуры!" << endl;
		l = add_supplier(l, 1, 2);
	}
	else {
		cout << "Идет загрузка из файла!\n";
		l = load_supplier(l);
	}

	list_supplier(l);
	menu(l);

	return 0;
}