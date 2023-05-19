#include "Header.h"

void write(fstream& p, Product zap, int num)
{
	p.clear();
	if (num)
	{
		p.seekg((num - 1) * len, ios::beg);
	}
	p.write((char*)&zap, len);
}

void print(Product zap, int i)
{
	cout << endl << i;
	cout << setw(12) << zap.title;
	cout << setw(12) << zap.country;
	cout << setw(12) << zap.volume;
	cout << setw(17) << zap.price;
	cout << setw(5) << zap.metka << setw(5) << '|';
}

void print2(Product zap, int i)
{
	cout << endl << i;
	cout << setw(12) << zap.country;
	cout << setw(12) << zap.volume;
	cout << setw(12) << zap.price << setw(3) << '|';
}

Product vvod()
{
	Product new_zap;
	cout << "\n������� ������������ ������:\n";
	cin >> new_zap.title;
	cout << "������� ������, ���� ����� �������������:\n";
	cin >> new_zap.country;
	cout << "������� ����� - ����� ������������ ������ � ������:\n";
	cin >> new_zap.volume;
	cout << "�������� ����� - ���� �� ������� ������:\n";
	cin >> new_zap.price;
	strcpy_s(new_zap.metka, "+");
	return new_zap;
}

void writeNzap(fstream& p, int n)
{
	p.clear();
	p.seekg(0, ios::end); // ��������� ������� � ����� �����
	for (int i = 0; i < n; i++)
	{
		Product zap;
		zap = vvod();
		write(p, zap);
	}
}

fstream& read(fstream& p, Product& zap, int num)
{
	p.clear();
	if (num)
	{
		p.seekg((num - 1) * len, ios::beg);
		p.read((char*)&zap, len);
	}
	return p;
}

void readAll(fstream& p)
{
	p.clear();
	p.seekg(0, ios::beg);
	Product zap;
	cout << shapka;
	for (int i = 1; read(p, zap, i); i++)
		print(zap, i);
	cout << endl << FinishL;
}

void readN(fstream& p, int N)
{
	p.clear();
	p.seekg(0, ios::beg);
	Product zap;
	if (read(p, zap, N))
	{
		cout << shapka;
		print(zap, N);
		cout << endl << FinishL;
	}
	else cout << endl << "����� ������ ���";
	_getch();
}

int metkaDel(fstream& p, char* name)
{
	p.clear();
	Product zap;
	p.seekg(0, ios::beg);
	int kol = 0;
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.title, name) == 0)
		{
			strcpy_s(zap.metka, "-");
			write(p, zap, i);
			kol++;
		}
	}
	return kol;
}

void UNmetkaDel(fstream& p)
{
	p.clear();
	Product zap;
	p.seekg(0, ios::beg);
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.metka, "-") == 0)
		{
			strcpy_s(zap.metka, "+");
			write(p, zap, i);
		}
	}
	_getch();
}

int Delete(fstream& p)
{
	fstream p1("temp.bin", ios::app);
	p.clear();
	Product zap;
	p.seekg(0, ios::beg);
	int kol = 0;
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.metka, "+") == 0)
		{
			write(p1, zap);
			kol++;
		}
	}
	p.close();
	p1.close();
	remove(fname);
	rename("temp.bin", fname);
	p.open(fname, ios::in | ios::out | ios::ate | ios::binary);
	return kol;
}

// ������� max_profit ��������� ������������ ������� 
// �� ������� ���� ������ ������ �� �������� ����
// ����� ���� �������
double max_profit(fstream& p) {
	Product zap;
	p.clear();
	p.seekg(0, ios::beg);
	double max_price = 0, p_price; // max_price - ������������ �������
	for (int i = 1; read(p, zap, i); i++) // ���� �������� �� ���� �������
	{
		p_price = zap.volume * zap.price; // ������� ��� ������� ������
		if (p_price > max_price) // ������� ����� ������������ �������
		{
			max_price = p_price; // ���������� ����� ������������ �������
		}
	}
	return max_price;
}

void spiski(fstream& p)
{
	Product zap;
	cout << shapka2;
	double max_p = max_profit(p);
	p.clear();
	p.seekg(0, ios::beg);
	for (int i = 1; read(p, zap, i); i++)
	{
		if (zap.volume * zap.price == max_p)
			print2(zap, i);
	}
	cout << endl << FinishL2 << endl;
}