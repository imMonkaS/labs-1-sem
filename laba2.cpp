#include <iostream>

using namespace std;

int main() {
	// ��������� � ������� ��������� ascii 1251, �� ����������� ascii �� �������� � �������� ���������.
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	// ������������ ������ ��� ��������� ��� �����, �� ����� ������� ������� ����� �������� 35 ��������:
	// �����������������������������������
	const unsigned int maxWordLength = 35;
	char* currentWord = new char[maxWordLength];
	char* maxWord = new char[maxWordLength];
	unsigned int currentVowels = 0, maxVowels = 0, i = 0, maxSize = 0;
	char ch;

	// ���������, �� ��������� �� �������� ������ ��������� ������, ���������� �������
	while ((ch = getchar()) != '\n') {
		// ���� ������ ������ - �������: ����� �� �������� ����� �����, � ������� ������ �������, � ��������
		// ��� ���������� - �� � ���� ������� ������ �����
		if (ch == ' ') {
			if (currentVowels > maxVowels) {
				maxVowels = currentVowels;

				delete[] maxWord;
				maxWord = new char[maxWordLength];
				maxSize = i;

				for (int j = 0; j < i; j++) {
					maxWord[j] = currentWord[j];
				}
			}

			delete[] currentWord;
			currentWord = new char[maxWordLength];

			i = 0;
			currentVowels = 0;
		}
		// ���� ������ ���� �� ���������� - �������� � ������ ������ ����� � ������������ ��� �������
		else {
			if (ch == '�' || ch == '�' || ch == '�') {
				currentVowels++;
			}

			currentWord[i] = ch;
			i++;
		}
	}

	// ������� �������, �� while �� ���������� ��������� �����, �� ������� ������ �������� ��� ����������.
	// ��� ����� ����� ��������� ��������� ��������� �� �����
	if (currentVowels > maxVowels) {
		maxVowels = currentVowels;

		delete[] maxWord;
		maxWord = new char[maxWordLength];
		maxSize = i;

		for (int j = 0; j < i; j++) {
			maxWord[j] = currentWord[j];
		}
	}

	if (maxVowels == 0) {
		cout << "� ������ ��� ���� ���������� ������� 'a' '�' '�'";
	}
	else {
		for (int j = 0; j < maxSize; j++) {
			cout << maxWord[j];
		}
	}

	// ������� ������
	delete[] maxWord;
	delete[] currentWord;

	return 0;
}