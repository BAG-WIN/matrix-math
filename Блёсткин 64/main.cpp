#include "Header.h"

// ���������� ����������
char fname[20] = "file1.bin";
int len = sizeof(Product); 

char menu()
{
	setlocale(LC_ALL, "Russian");
	cout << endl << "\n\t1-> �������� ������"
		<< endl << "\t2-> ������ ���� �������"
		<< endl << "\t3-> ������ ������ � N �������"
		<< endl << "\t4-> �������� �� ��������"
		<< endl << "\t5-> ����� ������� �� ��������"
		<< endl << "\t6-> ������� ��������� ������"
		<< endl << "\t7-> ������ �����"
		<< endl << "\t0-> EXIT" << endl;
	char s;
	cout << "\n\t-> ";
	cin >> s;
	return s;
}

void main()
{
	fstream p(fname, ios::app); // ���������� ��������� ��� ������ � ����� �����
	setlocale(LC_ALL, "Russian"); // ����� ���� ���������

	if (p) // �������� ����� �� �������������
	{
		p.close();
		p.open(fname, ios::in | ios::out | ios::ate | // in - ��������, out - ������
			ios::binary); // :: - ������� ���������
	}
	int n;
	do
	{
		char s = menu();
		switch (s)
		{
		case '1':
			cout << "������� ���-�� �������: ";
			cin >> n;
			writeNzap(p, n);
			break;
		case '2':
			readAll(p);
			_getch();
			break;
		case '3':
			int nom;
			cout << "\n������� ����� ������: ";
			cin >> nom;
			readN(p, nom);
			_getch();
			break;
		case '4':
			int a;
			char name[10];
			cout << "\n\t������� ������������ ������: ";
			cin >> name;
			a = metkaDel(p, name);
			break;
		case '5':
			UNmetkaDel(p);
			system("cls");
			break;
		case '6':
			Delete(p);
			cout << ("\n\tDone!");
			break;
		case '7':
			spiski(p);
			break;
		case '0':
			p.close();
			exit(0);
		}
	} while (1);
	p.close();
	system("pause");
}

/*������������ �������� ��������� ����������� ������ �������� ��������� ���������
�������������� �������. � ����� � ������ �� ������� ��������� ������ ����������
����������: ������������ ������, ������, ���� ��������������, ����� ������������
������ � ������, ���� ������� ������. ��������� ���������� ������ �����, ����
�������������� ������ �� �������������� �������, � ��������� ������ ������ ��������
� ����� ���������. ��������� �������� �����, ������� �������� ���������� ����� �
����� �����������.*/



	    