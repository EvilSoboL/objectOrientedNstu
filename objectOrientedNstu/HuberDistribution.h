#pragma once


class HuberDistribution {
private:
    double shift;    // Параметр сдвига
    double scale;    // Параметр масштаба
    double shape;    // Параметр формы (v)
    std::string label;   // Текстовая метка

public:
    // Конструктор класса
    HuberDistribution(double shift, double scale, double shape, std::string label);

    // Сеттеры, геттеры
    void setShift(double newShift);
    double getShift() const;

    void setScale(double newScale);
    double getScale() const;

    void setShape(double newShape);
    double getShape() const;

    void setLabel(const std::string& newLabel);
    std::string getLabel() const;

    // Плотность нормального распредления
    double phi(double x) const;

    // Функция нормального распределения
    double Phi(double x) const;

    // Плотность распределения Хьюбера
    double density(double x) const;
};

