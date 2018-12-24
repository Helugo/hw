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

void posl1() {
	int n, s = 0, A1 = NULL, A2 = NULL, A3 = NULL;
	cout << "Len >>> "; cin >> n;
	cout << "\n";
	for (int i = 1; i < n + 1; i++) {
		cout << i << " >>> "; cin >> A3;
		if (i > 2 && (A1 % 2 == 0) && (A3 % 2 == 0) && A2 < 0) { s = +A2; }
		A1 = A2; A2 = A3;
	}
	cout << "\nsucc\n\n";
	cout << "result: " << s << endl;
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
		if (r == 1) { cout << " posledovatel'nost' - " << endl; posl1(); }
		if (r == 2) { cout << " massiv" << endl; massiv(); }
		if (r == 3) { cout << " matrica" << endl; matrix(); }
	}
}