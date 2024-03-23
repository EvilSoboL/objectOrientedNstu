#define _USE_MATH_DEFINES

#include <iostream>
#include "HuberDistribution.h"
#include "SampleCharacteristics.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <conio.h>
#include <fstream>
#include <sstream>

using namespace std;


// Проверка основных параметров распределения
static void check() {
	vector<double> shapes = { 0.5, 0.75, 1, 1.5, 2, 2.5, 3 };

	for (size_t i = 0; i < shapes.size(); ++i) {
		HuberDistribution dist(0., 1., shapes[i], "Note");

		cout << "For nu = " << shapes[i] << endl;
		cout << "Variance: " << dist.sqrt_dispersion() << endl;
		cout << "Kurtosis: " << dist.kurtosis_coefficient() << endl;
		cout << "P: " << dist.hitting_central_interval() << endl;
		cout << "f0: " << dist.density(0) << endl;
		cout << "z: " << dist.random_value(1) << endl;
	};
};

// Генерация выборки
static vector<double> generate_sample(double shift, double scale, double shape, int sample_len) {
	HuberDistribution dist(shift, scale, shape, "Note");
	vector<double> samples;

	for (int i = 0; i < sample_len; ++i)
		samples.push_back(dist.random_value(i));
	return samples;
};

int main() {
	vector<double> sample = generate_sample(0, 1, 0.5, 50);
	SampleCharacteristics sc(sample);
	sc.saveSampleAndDensity(0, 1, 0.5);
};