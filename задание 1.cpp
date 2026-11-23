#include <iostream>
using namespace std;

// Рекурсивный бинарный поиск
// arr — отсортированный массив, left/right — границы поиска, target — искомый элемент
// Возвращает индекс найденного элемента или -1, если не найден
int binarySearch(const int arr[], int left, int right, int target) {
    if (left > right) {
        return -1; // базовый случай: элемент не найден
    }

    int mid = left + (right - left) / 2; // защита от переполнения

    if (arr[mid] == target) {
        return mid; // нашли
    } else if (arr[mid] < target) {
        return binarySearch(arr, mid + 1, right, target); // ищем в правой половине
    } else {
        return binarySearch(arr, left, mid - 1, target);  // ищем в левой половине
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\nВведите искомый элемент: ";
    cin >> target;

    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1)
        cout << "Элемент найден по индексу: " << result << endl;
    else
        cout << "Элемент не найден" << endl;

    return 0;
}