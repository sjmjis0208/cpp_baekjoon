#include <iostream>
#include<math.h>
using namespace std;



void print_star(char** mat, int r, int c, int num) {
	if (num == 1) {
		mat[r][c] = '*';
		return;
	}
	int div = num / 3;
	int cint = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cint++;
			if (cint != 5) {
				print_star(mat, r + i * div, c + j * div, div);
			}
		}
	}
}

int main() {
	int b;
	cin >> b;
	char** mat = new char*[b];
	for (int i =0; i < b; i++) {
		mat[i] = new char[b];
	}
	for (int i = 0; i < b;i++) {
		for (int j = 0; j < b; j++) {
			mat[i][j] = ' ';
		}
	}
	
	print_star(mat, 0, 0, b);

	for (int i = 0; i < b;i++) {
		for (int j = 0; j < b;j++) {
			cout << mat[i][j];
		}
		cout << '\n';
	}

	for (int i = 0; i < b; i++) {
		delete[] mat[i];
	}
	delete[] mat;
	
	
}