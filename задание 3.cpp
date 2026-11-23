#include <iostream>
#include <string>
#include <locale>
using namespace std;

bool isVowel(char c) {
    string vowels = "aeiouyаеёиоуыэюяAEIOUYАЕЁИОУЫЭЮЯ";
    return vowels.find(c) != string::npos;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8"); // Включаем поддержку русского языка

    string text;
    cout << "Введите строку: ";
    getline(cin, text);

    int count = 0;
    for (char c : text) {
        if (isVowel(c)) count++;
    }

    cout << "Количество гласных букв: " << count << endl;
    return 0;
}