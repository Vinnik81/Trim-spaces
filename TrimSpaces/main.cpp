#include <iostream>
#include <cstring>
#include <cstddef> // Для определения типа size_t
#include <windows.h>

using namespace std;

void trimRight(char* str);

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	const int MAX_SIZE = 1024; // Максимальный размер строки для избежания перепольнения буфера
	char string[MAX_SIZE];
	cout << "Введите строку: ";
	cin.getline(string, MAX_SIZE);

	cout << "Перед обрезкой: '" << string << "'" << endl;

	trimRight(string);

	cout << "После обрезки '" << string << "'" << endl;
}

void trimRight(char* str) 
{
	if (!str) return; // проверка на nullptr

	char* end = str; // указатель на текущую позицию
	while (*end != '\0')
	{
		++end; // находим конец строки
	}

	// Когда end указывает на конец строки ('\0'), идем в обратную сторону, пока встречаем пробелы.
	while (end > str && *(end - 1) == ' ')
	{
		--end;
	}

	// Устанавливаем нулевой символ в новой позиции конца строки
	*end = '\0';
}