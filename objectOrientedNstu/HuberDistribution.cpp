#define _USE_MATH_DEFINES

#include <cmath>
#include <random>
#include <stdexcept>
#include <string>
#include <iostream>
#include "HuberDistribution.h"

using namespace std;
double pi = M_PI;

// Конструктор класса
HuberDistribution::HuberDistribution(double shift, double scale, double shape, string label) :
    shift(shift), scale(scale), shape(shape), label(label) {
};

// Сеттеры, геттеры
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

// Плотность нормального распредления
double HuberDistribution::phi(double x) const {
    return exp(-0.5 * x * x) / sqrt(2.0 * pi);
}

// Функция нормального распределения
double HuberDistribution::Phi(double x) const {
    return 0.5 * (1.0 + erf(x / sqrt(2.0)));
}

// Плотность распределения Хьюбера
double HuberDistribution::density(double x) const {
    double phi = this->phi(this->shape);
    double Phi = this->Phi(this->shape);
    double K = 2 / this->shape * phi + 2 * Phi;

    if (this->shape <= abs(x)) {
        return 1 / (sqrt(2 * pi) * K) * exp(-x * x / 2);
    }
    else {
        return 1 / (sqrt(2 * pi) * K) * exp((this->shape * this->shape) / 2 - this->shape * abs(x));
    };
};
