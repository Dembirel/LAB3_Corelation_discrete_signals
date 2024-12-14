#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
//
double calculateCorrelation(const std::vector<double>& x, const std::vector<double>& y) {
    double meanX = 0, meanY = 0;
    for (int i = 0; i < x.size(); ++i) {
        meanX += x[i];
        meanY += y[i];
    }
    meanX /= x.size();
    meanY /= y.size();

    double numerator = 0, denominatorX = 0, denominatorY = 0;
    for (int i = 0; i < x.size(); ++i) {
        numerator += (x[i] - meanX) * (y[i] - meanY);
        denominatorX += std::pow(x[i] - meanX, 2);
        denominatorY += std::pow(y[i] - meanY, 2);
    }

    return numerator; // Обычная корреляция
}
 
//Нормализованная корреляция: 
double calculateNormalizedCorrelation(const std::vector<double>& x, const std::vector<double>& y) {
    double meanX = 0, meanY = 0;
    for (int i = 0; i < x.size(); ++i) {
        meanX += x[i];
        meanY += y[i];
    }
    meanX /= x.size();
    meanY /= y.size();

    double numerator = 0, denominatorX = 0, denominatorY = 0;
    for (int i = 0; i < x.size(); ++i) {
        numerator += (x[i] - meanX) * (y[i] - meanY);
        denominatorX += std::pow(x[i] - meanX, 2);
        denominatorY += std::pow(y[i] - meanY, 2);
    }

    return numerator / std::sqrt(denominatorX * denominatorY); // Нормализованная корреляция
}


// Функция для вывода таблицы корреляций
void printCorrelationTable(double corr_ab, double corr_ac, double corr_bc) {

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
    double corr_ab = calculateCorrelation(a, b);
    double corr_ac = calculateCorrelation(a, c);
    double corr_bc = calculateCorrelation(b, c);
    // Вывод результатов в таблице
    cout << "Корреляция между a, b и c:\n";
    printCorrelationTable(corr_ab, corr_ac, corr_bc);

    corr_ab = calculateNormalizedCorrelation(a, b);
    corr_ac = calculateNormalizedCorrelation(a, c);
    corr_bc = calculateNormalizedCorrelation(b, c);

    cout << "\nНормализованная корреляция между a, b и c:\n";
    printCorrelationTable(corr_ab, corr_ac, corr_bc);


    return 0;
}
