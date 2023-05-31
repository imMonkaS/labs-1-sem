#include <iostream>

using namespace std;

// ������� ���� ������ � ������� �������
void toUpperCase(char* line, unsigned int size) {
	for (int i = 0; i < size; i++) {
		char current_character = int(line[i]);
		// ��� ��������
		if (current_character >= 97 && current_character <= 122) {
			line[i] = char(current_character - 32);
		}

		// ��� ���������. ��������, ���� ������ ���������� win 1251
		else if (256 + current_character >= 224 && 256 + current_character <= 255) {
			line[i] = char(256 + current_character - 32);
		}

		// ����� � ��������� ����. ��������, ���� ������ ���������� win 1251
		else if (256 + current_character == 184) {
			line[i] = char(256 + current_character - 16);
		}
	}
}

// ������� ������ � ������� ������� �� ������� start �� ������� finish �� ������� finish
void toUpperCase(char* line, unsigned int start, unsigned int finish) {
	for (int i = start - 1; i < finish - 1; i++) {
		char current_character = int(line[i]);
		if (current_character >= 97 && current_character <= 122) {
			line[i] = char(current_character - 32);
		}

		else if (256 + current_character >= 224 && 256 + current_character <= 255) {
			line[i] = char(256 + current_character - 32);
		}

		else if (256 + current_character == 184) {
			line[i] = char(256 + current_character - 16);
		}
	}
}

// ������� ���� ������ � ������ �������
void toLowerCase(char* line, unsigned int size) {
	for (int i = 0; i < size; i++) {
		char current_character = int(line[i]);
		if (current_character >= 65 && current_character <= 90) {
			line[i] = char(current_character + 32);
		}

		else if (256 + current_character >= 192 && 256 + current_character <= 223) {
			line[i] = char(256 + current_character + 32);
		}

		else if (256 + current_character == 168) {
			line[i] = char(256 + current_character + 16);
		}
	}
}

// ������� ������ � ������ ������� �� ������� start �� ������� finish �� ������� finish
void toLowerCase(char* line, unsigned int start, unsigned int finish) {
	for (int i = start - 1; i < finish - 1; i++) {
		char current_character = int(line[i]);
		if (current_character >= 65 && current_character <= 90) {
			line[i] = char(current_character + 32);
		}

		else if (256 + current_character >= 192 && 256 + current_character <= 223) {
			line[i] = char(256 + current_character + 32);
		}

		else if (256 + current_character == 168) {
			line[i] = char(256 + current_character + 16);
		}
	}
}

int main()
{
	// ������ ��������� win 1251 ��� ������� �������� � ��������� ��� ������� ����
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	char* line = new char[12];
	unsigned int length = 0;

	cout << "Enter your line" << endl;
	// ���� ��������� ������ ���� �� �������� ������� ������
	for (int i = 0; ; i++) {
		// ��������� ������ �� �������
		char ch = getchar();
		// ���� ��������� ������� ������, ���� �������������
		if (ch == '\n') break;

		// ���������� ������ ���� � �� �������
		if (i % 10 == 0 && i != 0) {
			// ��������� ������ ����� ��������� ������
			char* tmp = new char[i];
			for (int j = 0; j < i; j++) {
				tmp[j] = line[j];
			}
			// ���������� ������ � �������� ������ � ����� ��� ���������
			delete[] line;
			line = new char[i + 12];
			for (int j = 0; j < i; j++) {
				line[j] = tmp[j];
			}
			// ������� ������ ��������� ��� ������� ������
			delete[] tmp;
		}

		// ��������� ������� � ������ � ������� �����
		line[i] = ch;
		length++;
	}

	// WhatWouldYouPrefer ����������, ����� ������� ������������ �������� ��� �������������� (������� ��� ������ �������)
	char wwyp;
	cout << "Would you like to convert line to uppercase or to lowercase? (u/l)" << endl;
	do {
		cin >> wwyp;
	} while (wwyp != 'l' && wwyp != 'u');
	char answer;
	cout << "Would you like to convert the whole line? (y/n)" << endl;
	do {
		cin >> answer;
	} while (answer != 'y' && answer != 'n');


	// ������� ����������� ������
	if (wwyp == 'u') {
		if (answer == 'y') {
			toUpperCase(line, length);
		}
		else {
			unsigned int start, finish;
			cout << "Enter first and last index of line you want to convert. (Indexes should not be greater than the line's length + 1)" << endl;
			cin >> start >> finish;
			if (start > length) {
				start = length;
			}
			if (finish > length) {
				finish = length + 1;
			}
			toUpperCase(line, start, finish);
		}
	}
	else {
		if (answer == 'y') {
			toLowerCase(line, length);
		}
		else {
			unsigned int start, finish;
			cout << "Enter first and last index of line you want to convert. (Indexes should not be greater than the line's length + 1)" << endl;
			cin >> start >> finish;
			if (start > length) {
				start = length;
			}
			if (finish > length) {
				finish = length + 1;
			}
			toLowerCase(line, start, finish);
		}
	}

	// ������� ������
	for (int i = 0; i < length; i++) {
		cout << line[i];
	}

	// ������� ������
	delete[] line;

	return 0;
}