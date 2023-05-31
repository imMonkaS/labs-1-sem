#include <iostream>

using namespace std;

int main() {
	// ¬ыставить в консоли кодировку ascii 1251, тк стандартный ascii не работает с русскими символами.
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	// ћаксимальна€ пам€ть дл€ выделени€ под слово, тк самое большое русское слово содержит 35 символов:
	// превысокомногорассмотрительствующий
	const unsigned int maxWordLength = 35;
	char* currentWord = new char[maxWordLength];
	char* maxWord = new char[maxWordLength];
	unsigned int currentVowels = 0, maxVowels = 0, i = 0, maxSize = 0;
	char ch;

	// ѕровер€ем, не €всл€етс€ ли введЄнный символ переносом строки, считывеаем символы
	while ((ch = getchar()) != '\n') {
		// если символ пробел - смотрим: нужно ли записать новое слово, в котором больше гласных, и обнул€ем
		// все переменные - не к чему хранить лишние слова
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
		// ≈сли пробел пока не встретилс€ - работаем в рамках одного слова и подсчитываем его гласные
		else {
			if (ch == 'а' || ch == 'е' || ch == 'и') {
				currentVowels++;
			}

			currentWord[i] = ch;
			i++;
		}
	}

	// Ќемного костыль, но while не обработает последнее слово, тк перенос строки закончит его выполнение.
	// дл€ этого здесь копипаста условного оператора из цикла
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
		cout << "¬ тексте нет слов содержащих гласные 'a' 'е' 'и'";
	}
	else {
		for (int j = 0; j < maxSize; j++) {
			cout << maxWord[j];
		}
	}

	// очищаем пам€ть
	delete[] maxWord;
	delete[] currentWord;

	return 0;
}