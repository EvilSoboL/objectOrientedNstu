#ifndef SAMPLE_CHARACTERISTICS_H
#define SAMPLE_CHARACTERISTICS_H

#include <vector>
#include <string>
#include <utility>

using namespace std; // �������� ��������: ������ �������� ��� ������������ ������!

class SampleCharacteristics {
private:
    vector<double> sample;

public:
    // ����������� � ���������� ��� ������������� �������
    SampleCharacteristics(const vector<double>& sampleData) : sample(sampleData) {}

    // ������ ��� ���������� sample
    vector<double> getSample() const { return sample; }

    // ������ ��� ���������� sample
    void setSample(const vector<double>& sampleData) { sample = sampleData; }

    // ����� ��� ���������� �������� �������� �������
    double mean();

    // ����� ��� ���������� ������� �������
    double median();

    // ����� ��� ���������� ����������� � ���������� ��������
    pair<double, double> trimmedWinsorizedMean(double alpha);

    // ����� ��� ���������� ������������ � ������������� ��������
    pair<double, double> minMax(double alpha);

    // ����� ��� ���������� ������� �������
    void sampleAnalysis();

    void saveToCsv(vector<double> vector, const string& filename);

    vector<double> generateDensity(double shift, double scale, double shape);

    void saveSampleAndDensity(double shift, double scale, double shape);
};

#endif // SAMPLE_CHARACTERISTICS_H