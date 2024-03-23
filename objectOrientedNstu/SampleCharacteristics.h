#ifndef SAMPLE_CHARACTERISTICS_H
#define SAMPLE_CHARACTERISTICS_H

#include <vector>
#include <string>
#include <utility>

using namespace std; // Обратите внимание: плохая практика для заголовочных файлов!

class SampleCharacteristics {
private:
    vector<double> sample;

public:
    // Конструктор с параметром для инициализации вектора
    SampleCharacteristics(const vector<double>& sampleData) : sample(sampleData) {}

    // Геттер для переменной sample
    vector<double> getSample() const { return sample; }

    // Сеттер для переменной sample
    void setSample(const vector<double>& sampleData) { sample = sampleData; }

    // Метод для вычисления среднего значения вектора
    double mean();

    // Метод для вычисления медианы вектора
    double median();

    // Метод для вычисления обрезанного и усеченного среднего
    pair<double, double> trimmedWinsorizedMean(double alpha);

    // Метод для нахождения минимального и максимального значений
    pair<double, double> minMax(double alpha);

    // Метод для проведения анализа выборки
    void sampleAnalysis();

    void saveToCsv(vector<double> vector, const string& filename);

    vector<double> generateDensity(double shift, double scale, double shape);

    void saveSampleAndDensity(double shift, double scale, double shape);
};

#endif // SAMPLE_CHARACTERISTICS_H