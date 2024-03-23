#ifndef SAMPLE_CHARACTERISTICS_H
#define SAMPLE_CHARACTERISTICS_H

#include <vector>
#include <utility>

using namespace std; // Обратите внимание: плохая практика для заголовочных файлов!

class SampleCharacteristics {
private:
    vector<double> sample;

public:
    // Конструктор с параметром для инициализации вектора
    explicit SampleCharacteristics(const vector<double>& sampleData) : sample(sampleData) {}

    // Геттер для переменной sample
    vector<double> getSample() const { return sample; }

    // Сеттер для переменной sample
    void setSample(const vector<double>& sampleData) { sample = sampleData; }

    // Метод для вычисления среднего значения вектора
    double mean() const;

    // Метод для вычисления медианы вектора
    double median() const;

    // Метод для вычисления обрезанного и усеченного среднего
    pair<double, double> trimmedWinsorizedMean(double alpha) const;

    // Метод для нахождения минимального и максимального значений
    pair<double, double> minMax(double alpha) const;

    // Метод для проведения анализа выборки
    void sampleAnalysis(double alpha) const;
};

#endif // SAMPLE_CHARACTERISTICS_H