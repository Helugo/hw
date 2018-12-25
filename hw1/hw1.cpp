#include "pch.h"
#include <iostream>
using namespace std;

void massiv(){
	int len, value, min, condition=0, mas[100];
	cout << "Len >>> "; cin >> len; cout << "\n";

	for (int i = 0; i < len; i++) {
		cout << "[" << i << "] >>> ";
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
	cout << "\nsucc\n\n";
	for (int i = 0; i < len; i++) { cout << " [" << i << "]=" << mas[i]; }
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
	int const len_x = 3, len_y = 3;
	int mas[len_y], mat[len_x][len_y];
	for (int i = 0; i < len_y; i++) {
		for (int j = 0; j < len_x; j++) {
			cout << "m:: y=" << i + 1 << " x=" << j + 1 << " >>> "; 
			cin >> mat[i][j];
		}
	}
	for (int j = 0; j < len_y; j++) {
		mas[j] = mat[0][j];
	}

	cout << "\nsucc\n\n";

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
	cout << "\nsucc\n\n";
	for (int j = 0; j < len_x; j++) { cout << " [" << j << "]=" << mas[j]; }

}

void lin() {
	int n, result = 0, i_factor = 1, d_factor = 1;
	cout << "N >>> "; cin >> n;
	for (int i = 1; i <= n; i++) {
		i_factor *= i; d_factor = i_factor * (i + 1) * (i +2);
		result += ((3 * i + 1) * (3 * i + 1)) / d_factor;
	}
	cout << "R >>> " << result << endl;
}

int main() {
	while (true) {
		int r;
		cout << "\n\nInd - "; cin >> r;
		switch (r){
		case 1: { cout << "posledovatel'nost' - " << endl; posl1(); }; break;
		case 2: { cout << "massiv" << endl; massiv(); };               break;
		case 3: { cout << "matrica" << endl; matrix(); };              break;
		case 4: { cout << "riad" << endl; lin(); };					   break;
		}
	}
}