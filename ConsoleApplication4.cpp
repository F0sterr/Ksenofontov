#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n; // размерность системы
    double a[100][100]; // коэффициенты
    double b[100]; // свободные члены
    double x[100]; // решение
    // ввод размерности
    cout << "Введите размерность системы: ";
    cin >> n;

    // ввод коэффициентов и свободных членов
    cout << "Введите коэффициенты и свободные члены:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
        cin >> b[i];
    }
    // метод Гаусса
    for (int i = 0; i < n; i++) {
        // выбор ведущего элемента
        int max_row = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(a[j][i]) > abs(a[max_row][i])) {
                max_row = j;
            }
        }
        swap(a[i], a[max_row]);
        swap(b[i], b[max_row]);

        // прямой ход
        for (int j = i + 1; j < n; j++) {
            double factor = a[j][i] / a[i][i];
            for (int k = i; k < n; k++) {
                a[j][k] -= factor * a[i][k];
            }
            b[j] -= factor * b[i];
        }
    }

    // обратный ход
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
    // вывод результата
    cout << "Решение:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << setprecision(3) << x[i] << endl;
    }

    return 0;
}
