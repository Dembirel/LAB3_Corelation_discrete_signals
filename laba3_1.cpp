#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Функция для вычисления корреляции
double correlation(const vector<double>& x, const vector<double>& y) {
    double mean_x = 0.0, mean_y = 0.0;
    double numerator = 0.0, denominator_x = 0.0, denominator_y = 0.0;
    
    // Вычисление средних значений
    for (size_t i = 0; i < x.size(); ++i) {
        mean_x += x[i];
        mean_y += y[i];
    }
    mean_x /= x.size();
    mean_y /= y.size();

    // Вычисление числителя и знаменателей для корреляции
    for (size_t i = 0; i < x.size(); ++i) {
        numerator += (x[i] - mean_x) * (y[i] - mean_y);
        denominator_x += (x[i] - mean_x) * (x[i] - mean_x);
        denominator_y += (y[i] - mean_y) * (y[i] - mean_y);
    }

    return numerator / sqrt(denominator_x * denominator_y);
}

// Функция для вывода таблицы корреляций
void printCorrelationTable(double corr_ab, double corr_ac, double corr_bc) {
    cout << "Корреляция между a, b и c:\n";
    cout << "\t| a  | b  | c  |\n";
    cout << "a  | -  | " << corr_ab << " | " << corr_ac << " |\n";
    cout << "b  | " << corr_ab << " | -  | " << corr_bc << " |\n";
    cout << "c  | " << corr_ac << " | " << corr_bc << " | -  |\n";

    cout << "\nНормализованная корреляция между a, b и c:\n";
    cout << "\t| a  | b  | c  |\n";
    cout << "a  | -  | " << corr_ab << " | " << corr_ac << " |\n";
    cout << "b  | " << corr_ab << " | -  | " << corr_bc << " |\n";
    cout << "c  | " << corr_ac << " | " << corr_bc << " | -  |\n";
}

int main() {
    // Данные
    vector<double> a = {2, 3, 6, -1, -4, -2, 2, 5};
    vector<double> b = {4, 6, 8, -2, -6, -4, 2, 7};
    vector<double> c = {-3, -1, 3, -7, 2, -8, 5, -1};

    // Вычисление корреляции между массивами
    double corr_ab = correlation(a, b);
    double corr_ac = correlation(a, c);
    double corr_bc = correlation(b, c);

    // Вывод результатов в таблице
    printCorrelationTable(corr_ab, corr_ac, corr_bc);

    return 0;
}
