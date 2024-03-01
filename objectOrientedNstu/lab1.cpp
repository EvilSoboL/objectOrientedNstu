#define _USE_MATH_DEFINES

#include <cmath>
#include <random>
#include <stdexcept>
#include <string>
#include <iostream>
/*
class HuberDistribution {
private:
    double shift;    // Параметр сдвига
    double scale;    // Параметр масштаба
    double shape;    // Параметр формы (v)
    std::string label;   // Текстовая метка

    static constexpr double pi = 3.14159265358979323846;

public:
    // Конструктор
    HuberDistribution(double shift, double scale, double shape, std::string label)
        : shift(shift), scale(scale), shape(shape), label(label) {
        if (scale <= 0 || shape <= 0) {
            throw std::invalid_argument("Scale and shape must be positive");
        }
    }

    // Setters and getters
    void setShift(double newShift) { shift = newShift; }
    double getShift() const { return shift; }

    void setScale(double newScale) {
        if (newScale <= 0) {
            throw std::invalid_argument("Scale must be positive");
        }
        scale = newScale;
    }
    double getScale() const { return scale; }

    void setShape(double newShape) {
        if (newShape <= 0) {
            throw std::invalid_argument("Shape must be positive");
        }
        shape = newShape;
    }
    double getShape() const { return shape; }

    void setLabel(const std::string& newLabel) { label = newLabel; }
    std::string getLabel() const { return label; }

    double phi(double x) const {
        return exp(-0.5 * x * x) / sqrt(2.0 * pi);
    }

    // Функция распределения для стандартного нормального распределения
    double Phi(double x) const {
        return 0.5 * (1.0 + erf(x / sqrt(2.0)));
    }

    // Функция для вычисления плотности распределения
    double density(double x) const {
        double z = (x - shift) / scale;
        double phi_z = exp(-0.5 * z * z) / sqrt(2.0 * pi);
        double Phi_z = 0.5 * (1.0 + erf(z / sqrt(2.0)));

        double K = 2 * phi_z / shape + 2 * Phi_z - 1;
        if (std::abs(z) <= shape) {
            return phi_z / (scale * K);
        }
        else {
            return exp(-0.5 * (shape * shape - 2 * shape * std::abs(z))) / (scale * K);
        }
    }

    // Метод для вычисления дисперсии
    double variance() const {
        double phiValue = this->phi(0); // Значение функции плотности в нуле
        double PhiValue = this->Phi(0); // Значение функции распределения в нуле
        double K = (2 / shape) * phiValue + 2 * PhiValue - 1;
        return 1 + (2 * phiValue * (shape * shape + 2)) / (shape * shape * shape * K);
    }

    // Метод для вычисления коэффициента эксцесса
    double kurtosis() const {
        double phiValue = this->phi(0); // Значение функции плотности в нуле
        double PhiValue = this->Phi(0); // Значение функции распределения в нуле
        double K = (2 / shape) * phiValue + 2 * PhiValue - 1;
        double gamma2 = (3 * (2 * PhiValue - 1) + 2 * phiValue * (24 / (shape * shape * shape * shape) + 24 / (shape * shape * shape) + 12 / shape + shape)) / (this->variance()*this->variance()*K);
        return gamma2 - 3;
    }

    // Другие функции для вычисления характеристик распределения...
};
*/
/*
int main() {
    std::vector<double> nu_values = { 0.5, 0.75, 1, 1.5, 2, 2.5, 3 };
    std::vector<double> sigma_squared_expected = { 8.08, 3.71, 2.24, 1.31, 1.08, 1.02, 1.00 };
    std::vector<double> gamma_2_expected = { 2.94, 2.75, 2.37, 1.30, 0.51, 0.16, 0.04 };
    std::vector<double> P_expected = { 0.214, 0.405, 0.585, 0.834, 0.946, 0.986, 0.997 };
    std::vector<double> f_0_expected = { 0.223, 0.296, 0.342, 0.384, 0.396, 0.398, 0.399 };

    for (size_t i = 0; i < nu_values.size(); ++i) {
        HuberDistribution distribution(0.0, 1.0, nu_values[i], "Huber");

        // Вычисление дисперсии и коэффициента эксцесса
        double variance = distribution.variance();
        double kurtosis = distribution.kurtosis();

        // Вычисление вероятности попадания в центральный интервал P и значения плотности при x = 0
        double PhiValue = distribution.Phi(0);
        double K = (2 / nu_values[i]) * distribution.phi(0) + 2 * PhiValue - 1;
        double P = (2 * PhiValue - 1) / K;
        double f_0 = distribution.density(0);

        // Вывод результатов и сравнение с ожидаемыми значениями
        std::cout << "For nu = " << nu_values[i] << ":\n";
        std::cout << "Variance: " << variance << " (expected: " << sigma_squared_expected[i] << ")\n";
        std::cout << "Kurtosis: " << kurtosis << " (expected: " << gamma_2_expected[i] << ")\n";
        std::cout << "P: " << P << " (expected: " << P_expected[i] << ")\n";
        std::cout << "Density at x = 0: " << f_0 << " (expected: " << f_0_expected[i] << ")\n\n";
    }

    return 0;
}
*/