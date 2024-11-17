#include <iostream>
#include <cstring>
#include <cstddef> // ��� ����������� ���� size_t
#include <windows.h>

using namespace std;

void trimRight(char* str);

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	const int MAX_SIZE = 1024; // ������������ ������ ������ ��� ��������� ������������� ������
	char string[MAX_SIZE];
	cout << "������� ������: ";
	cin.getline(string, MAX_SIZE);

	cout << "����� ��������: '" << string << "'" << endl;

	trimRight(string);

	cout << "����� ������� '" << string << "'" << endl;
}

void trimRight(char* str) 
{
	if (!str) return; // �������� �� nullptr

	char* end = str; // ��������� �� ������� �������
	while (*end != '\0')
	{
		++end; // ������� ����� ������
	}

	// ����� end ��������� �� ����� ������ ('\0'), ���� � �������� �������, ���� ��������� �������.
	while (end > str && *(end - 1) == ' ')
	{
		--end;
	}

	// ������������� ������� ������ � ����� ������� ����� ������
	*end = '\0';
}