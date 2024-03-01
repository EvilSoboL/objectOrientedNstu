#pragma once


class HuberDistribution {
private:
    double shift;    // �������� ������
    double scale;    // �������� ��������
    double shape;    // �������� ����� (v)
    std::string label;   // ��������� �����

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

    void setLabel(const std::string& newLabel);
    std::string getLabel() const;

    // ��������� ����������� ������������
    double phi(double x) const;

    // ������� ����������� �������������
    double Phi(double x) const;

    // ��������� ������������� �������
    double density(double x) const;
};

