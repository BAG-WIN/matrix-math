#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void clearMemory(double** a, long long n) { 
    for (long long i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete [] a;        
}
        
double det(double** a, long long n) { 
    if (n == 1)
        return a[0][0];
    else if (n == 2)
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    else {
        int d = 0;
        for (long long k = 0; k < n; k++) {
            double** m = new double*[n-1];
            for (int i = 0; i < n - 1; i++)
                m[i] = new double[n - 1];
            for (long long i = 1; i < n; i++) {
                long long t = 0;
                for (long long j = 0; j < n; j++) {
                    if (j == k)
                        continue;
                    m[i-1][t] = a[i][j];
                    t++;
                }
            }
            d += pow(-1, k + 2) * a[0][k] * det(m, n - 1);
            clearMemory(m, n - 1); 
        }
        return d;
    }
}

int main() {
	long long n;
	cout << "Enter matrix size\nn = ";
	cin >> n;
	double** a = new double*[n];
    for (long long i = 0; i < n; i++)
        a[i] = new double[n];
    cout << "Enter the matrix:\n";
	for (long long i = 0; i < n; ++i) {
		for (long long j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	cout << "Matrix determinant A = " << det(a, n) << endl;
	cout << "The program 'det_of_matrix' is completed.\n";
	system("pause");
	return 0;
}
