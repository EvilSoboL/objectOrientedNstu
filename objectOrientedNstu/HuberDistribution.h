#pragma once

using namespace std;


class HuberDistribution {
private:
    double shift;    // �������� ������
    double scale;    // �������� ��������
    double shape;    // �������� ����� (v)
    string label;   // ��������� �����

public:
    // ����������� ������
    HuberDistribution(double shift, double scale, double shape, std::string label);

    // �������, �������
    void setShift(double newShift);
    double getShift() const;

    void setScale(double newScale);
    double getScale() const;

    void setShape(double newShape);
    double getShape() const;

    void setLabel(const string& newLabel);
    string getLabel() const;

    // ��������� ����������� ������������
    double phi(double x) const;

    // ������� ����������� �������������
    double Phi(double x) const;

    double K() const;

    // ��������� ������������� �������
    double density(double x) const;

    // ���������
    double sqrt_dispersion() const;

    // ����������� ��������
    double kurtosis_coefficient() const;

    // ����������� ��������� � ����������� ��������
    double hitting_central_interval() const;

    // ���������� ��������� ��������
    double random_value(int seed) const;
 };

