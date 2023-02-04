#include <iostream>
using namespace std;

int main() {
	int n, m, p, r;
	cout << "Размер первой матрицы: ";
	cin >> n >> m;
	cout << "Размер второй матрицы: ";
	cin >> p >> r;
	int a[n][m], b[p][r];
	cout << "Первая матрица: " << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}	
	}
	cout << "Вторая матрица: " << endl;
	for (int i = 0; i < p; ++i) {
		for (int j = 0; j < r; ++j) {
			cin >> b[i][j];
		}	
	}
	int c[n][r];
	cout << "Итог: " << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < r; ++j) {
			int s = 0;
			for (int k = 0; k < m; ++k) {
				s += a[i][k] * b[k][j];
			}
			c[i][j] = s;
			cout << c[i][j] << ' ';
		}	
		cout << '\n';
	}
	return 0;
}

