#include "pch.h"
#include <iostream>
using namespace std;

void massiv(){
	int len, value, min, condition=0;
	cout << " Len >>> "; cin >> len; cout << "\n";
	int *mas = new int[len];

	for (int i = 0; i < len; i++) {
		cout << " [" << i << "] >>> ";
		cin >> value; mas[i] = value;
		if (value < 0) { condition++; }
	}
	if (condition >= 2) {
		for (int i = 0; i < len; i++) { mas[i] *= 2; }
	}
	else {
		min = mas[0];
		for (int i = 1; i < len; i++) { if (mas[i] < min) { min = mas[i]; } }
		for (int i = 0; i < len; i++) { mas[i] -= min; }
	}
	cout << "\n succ \n\n";
	for (int i = 0; i < len; i++) { cout << " [" << i << "]=" << mas[i]; }
	delete[] mas; system("pause");
}

void posl() {
	int len, value, pre_result=0, result=0;
	bool alpha_condition=false, beta_condition=false, full_condition=false;
	cout << " Len >>> "; cin >> len;
	for (int i = 0; i < len; i++) {
		cout << i << " >>> "; cin >> value;
		if (value % 2 == 0) { alpha_condition = true; }
		if (value < 0 && alpha_condition) { beta_condition = true; pre_result += value; }
		if (value % 2 == 0 && beta_condition) { result += pre_result; beta_condition = false; }
	}
	cout << "\n succ \n\n";
	cout << " result: " << result << endl; system("pause");
}

void matrix() {
	int len_y, len_x;
	int **mat, *mas;
	cout << " Y.len >>> "; cin >> len_y;
	cout << " X.len >>> "; cin >> len_x;
	mat = new int *[len_y];
	mas = new int[len_y];
	for (int i = 0; i < len_y; i++)
		mat[i] = new int[len_x];
	cout << "\n succ \n\n";

	for (int i = 0; i < len_y; i++) {
		for (int j = 0; j < len_x; j++) {
			cout << " m:: y=" << i + 1 << " x=" << j + 1 << " >>> "; cin >> mat[i][j];
		}
	}
	mas = mat[0];
	cout << "\n succ \n\n";

	for (int i = 0; i < len_y; cout << endl, i++) {
		for (int j = 0; j < len_x; j++) {
			cout << mat[i][j] << "\t";
		}
	}

	for (int i = 1; i < len_x; i++) {
		for (int j = 0; j < len_y; j++){
			if (mas[j] > mat[i][j]) { mas[j] = mat[i][j]; }
		}
	}
	cout << "\n succ \n\n";
	for (int j = 0; j < len_x; j++) { cout << " [" << j << "]=" << mas[j]; }

}

int main() {
	while (true) {
		int r;
		cout << "\n\n Ind - "; cin >> r;
		if (r == 1) { cout << " posledovatel'nost' - " << endl; posl(); }
		if (r == 2) { cout << " massiv" << endl; massiv(); }
		if (r == 3) { cout << " matrica" << endl; matrix(); }
	}
}