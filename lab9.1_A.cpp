#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;enum Specialty {��, ��, ��, ��, ��};string strSpecialty[] = { "��","��","��","��","��" };struct Student{	string prizv;	Specialty specialty;	short unsigned kurs;	short unsigned physics;	short unsigned math;	short unsigned informatics;};void Create(Student* s, const int N);void Print(Student* s, const int N);double BestAverage(Student* s, const int N);double physics_five_four(Student* s, const int N);int main(){	SetConsoleCP(1251);	SetConsoleOutputCP(1251);	int N;	cout << "������ ������� ��������: "; cin >> N;	Student* s = new Student[N];	Create(s, N);	Print(s, N);	cout << "| ��������� ������� ���: " << fixed << setprecision(2) << BestAverage(s, N) << setw(51) << "|" << endl;	cout << "| ������� �������� �� �������� � ������ " << char(34) << "4" << char(34) << " ��� " << char(34) << "5" << char(34) << ": " << fixed << setw(6) << setprecision(2) << physics_five_four(s, N) << "%" << setw(18) << "|" << endl;	cout << "================================================================================" << endl;	delete[] s;}void Create(Student* s, const int N){	int kurs, specialty;	for (int i = 0; i < N; i++)	{		cout << "������� " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "  �������: "; getline(cin, s[i].prizv);
		cout << "  ����: "; cin >> s[i].kurs;
		cout << "  ������������ (0 - ��, 1 - ��, 2 - ��, 3 - ��, 4 - ��): "; cin >> specialty;
		s[i].specialty = (Specialty)specialty;
		cout << "  ������ � ������: "; cin >> s[i].physics;
		cout << "  ������ � ����������: "; cin >> s[i].math;
		cout << "  ������ � �����������: "; cin >> s[i].informatics;	}}void Print(Student* s, const int N)
{
	cout << "================================================================================"
		<< endl;
	cout << "| �  | �������     | ���� | ������������ | Գ���� | ���������� | ����������� |"
		<< endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " " 
			<< "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << "  "
			<< "| " << setw(8) << right << strSpecialty[s[i].specialty] << "      "
			<< "| " << setw(4) << right << s[i].physics << "   "
			<< "| " << setw(6) << right << s[i].math << "      "
			<< "| " << setw(6) << right << s[i].informatics << "     |" << endl;
	}
	cout << "================================================================================" << endl;
}double BestAverage(Student* s, const int N){	double best = 0;	for (int i = 0; i < N; i++)	{		double tmp = (s[i].physics + s[i].math + s[i].informatics) / 3.;		if (tmp > best)			best = tmp;	}	return best;}double physics_five_four(Student* s, const int N){	int k = 0;	for (int i = 0; i < N; i++)		if (s[i].physics == 4 || s[i].physics == 5)			k++;	return 100.0*k / N ;}