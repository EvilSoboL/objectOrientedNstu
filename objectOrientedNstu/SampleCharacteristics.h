#ifndef SAMPLE_CHARACTERISTICS_H
#define SAMPLE_CHARACTERISTICS_H

#include <vector>
#include <utility>

using namespace std; // �������� ��������: ������ �������� ��� ������������ ������!

class SampleCharacteristics {
private:
    vector<double> sample;

public:
    // ����������� � ���������� ��� ������������� �������
    explicit SampleCharacteristics(const vector<double>& sampleData) : sample(sampleData) {}

    // ������ ��� ���������� sample
    vector<double> getSample() const { return sample; }

    // ������ ��� ���������� sample
    void setSample(const vector<double>& sampleData) { sample = sampleData; }

    // ����� ��� ���������� �������� �������� �������
    double mean() const;

    // ����� ��� ���������� ������� �������
    double median() const;

    // ����� ��� ���������� ����������� � ���������� ��������
    pair<double, double> trimmedWinsorizedMean(double alpha) const;

    // ����� ��� ���������� ������������ � ������������� ��������
    pair<double, double> minMax(double alpha) const;

    // ����� ��� ���������� ������� �������
    void sampleAnalysis(double alpha) const;
};

#endif // SAMPLE_CHARACTERISTICS_H