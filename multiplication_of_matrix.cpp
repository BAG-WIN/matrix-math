#include <iostream>
using namespace std;

int main() {
	int n, m, p, r;
	cout << "������ ������ �������: ";
	cin >> n >> m;
	cout << "������ ������ �������: ";
	cin >> p >> r;
	int a[n][m], b[p][r];
	cout << "������ �������: " << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}	
	}
	cout << "������ �������: " << endl;
	for (int i = 0; i < p; ++i) {
		for (int j = 0; j < r; ++j) {
			cin >> b[i][j];
		}	
	}
	int c[n][r];
	cout << "����: " << endl;
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

