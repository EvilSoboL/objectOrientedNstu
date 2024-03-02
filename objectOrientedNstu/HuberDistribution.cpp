#define _USE_MATH_DEFINES

#include <cmath>
#include <random>
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include "HuberDistribution.h"

using namespace std;

// ����������� ������
HuberDistribution::HuberDistribution(double shift, double scale, double shape, string label) :
    shift(shift), scale(scale), shape(shape), label(label) {
};

// �������, �������
void HuberDistribution::setShift(double newShift) { shift = newShift; }
double HuberDistribution::getShift() const { return shift; }

void HuberDistribution::setScale(double newScale) {
    scale = newScale;
};
double HuberDistribution::getScale() const { return scale; }

void HuberDistribution::setShape(double newShape) {
    shape = newShape;
};

double HuberDistribution::getShape() const { return shape; }

void HuberDistribution::setLabel(const string & newLabel) { label = newLabel; }
string HuberDistribution::getLabel() const { return label; }

// ��������� ����������� ������������
double HuberDistribution::phi(double x) const {
    double mean = 0.0;
    double stddev = 1.0;

    return 1.0 / (stddev * sqrt(2.0 * M_PI)) * exp( - pow(((x - mean) / (2.0 * pow(stddev, 2))), 2));
};

// ������� ����������� �������������
double HuberDistribution::Phi(double x) const {
    return 0.5 * (1.0 + erf(x/sqrt(2.0)));
};

double HuberDistribution::K() const {
    double shape = this->shape;
    double phi = this->phi(shape);
    double Phi = this->Phi(shape);

    return 2.0 / shape * phi + 2.0 * Phi - 1;
};

// ��������� ������������� �������
double HuberDistribution::density(double x) const {
    double K = this->K();

    if (abs(x) <= shape) {
        return 1.0 / (sqrt(2.0 * M_PI) * K) * exp(-pow(x, 2) / 2.0);
    }
    else {
        return 1.0 / (sqrt(2.0 * M_PI) * K) * exp((pow(shape, 2) / 2.0 - shape * abs(x)));
    };
};

// ���������
double HuberDistribution::sqrt_dispersion() const {
    double phi = this->phi(shape);
    double K = this->K();

    return 1.0 + (2.0 * phi * (pow(shape, 2) + 2.0)) / (pow(shape, 3) * K);
};

// ����������� ��������
double HuberDistribution::kurtosis_coefficient() const {
    double dispersion = this->sqrt_dispersion();
    double K = this->K();
    double Phi = this->Phi(shape);
    double phi = this->phi(shape);

    return 1. / (pow(dispersion, 2) * K) * (3. * (2. * Phi - 1.) + 2. * phi * (24. / pow(shape, 5) + 24. / pow(shape, 3) + 12. / shape + shape)) - 3.;
};

// ����������� ��������� � ����������� ��������
double HuberDistribution::hitting_central_interval() const {
    double Phi = this->Phi(shape);
    double K = this->K();

    return (2 * Phi - 1) / K;
};

// ���������� ��������� ��������
double HuberDistribution::random_value(int seed) const {
    default_random_engine e(seed);

    double p0 = this->hitting_central_interval();
    double p1 = (1. - p0) / 2.;
    double p2 = p1;
    double lambda = shape;

    discrete_distribution<> discrete{p0, p1, p2};
    normal_distribution<> normal;
    exponential_distribution<> exp(shape);

    double z = discrete(e);  // ��� 1
    if (z == 0) {
        double x1 = normal(e);  // ��� 2
        int i = 0;

        while (x1 < -shape || x1 > shape) {  // ��� 3
            i += 1;
            e.seed(i);
            x1 = normal(e);
        }
        return x1;
    }
    else if (z == 1) {  // ��� 5
        double x2 = exp(e);
        return shape + x2;
    }
    else if (z == 2) {  // ��� 5
        double x2 = exp(e);
        return -shape - x2;
    };
};
