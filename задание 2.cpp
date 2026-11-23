#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// Проверка, является ли символ частью слова (буква/цифра/подчёркивание)
bool isWordChar(char c) {
    return isalnum((unsigned char)c) || c == '_';
}

int main() {
    string inputFile  = "input.txt";
    string outputFile = "output.txt";
    string oldWord, newWord;

    cout << "Введите слово для замены: ";
    cin >> oldWord;
    cout << "Введите новое слово: ";
    cin >> newWord;

    ifstream fin(inputFile);
    if (!fin.is_open()) {
        cerr << "Не удалось открыть файл " << inputFile << endl;
        return 1;
    }

    ofstream fout(outputFile);
    if (!fout.is_open()) {
        cerr << "Не удалось создать файл " << outputFile << endl;
        return 1;
    }

    // Читаем файл посимвольно, выделяя слова как целые токены,
    // чтобы заменять только целые вхождения (а не часть слова).
    string result;
    string word;
    char c;

    while (fin.get(c)) {
        if (isWordChar(c)) {
            word += c;           // накапливаем слово
        } else {
            if (!word.empty()) {
                // закончилось слово — проверяем на совпадение
                if (word == oldWord)
                    result += newWord;
                else
                    result += word;
                word.clear();
            }
            result += c;         // разделитель (пробел, пунктуация и т.д.)
        }
    }
    // Обработка последнего слова в файле
    if (!word.empty()) {
        if (word == oldWord)
            result += newWord;
        else
            result += word;
    }

    fout << result;

    fin.close();
    fout.close();

    cout << "Готово. Результат записан в " << outputFile << endl;
    return 0;
}