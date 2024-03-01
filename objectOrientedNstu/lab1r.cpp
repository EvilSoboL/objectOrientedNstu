#define _USE_MATH_DEFINES

#include <iostream>
#include "HuberDistribution.h"
#include <vector>

using namespace std;

void check() {
	vector<double> shapes = { 0.5, 0.75, 1, 1.5, 2, 2.5, 3 };


	for (size_t i = 0; i < shapes.size(); ++i) {
		HuberDistribution dist(0.0, 1.0, shapes[i], "Note");

		cout << "For nu = " << shapes[i] << endl;
		cout << "Variance: " << dist.sqrt_dispersion() << endl;
		cout << "Kurtosis: " << dist.kurtosis_coefficient() << endl;
		cout << "P: " << dist.hitting_central_interval() << endl;
		cout << "f0: " << dist.density(0) << endl;
	};
};

void main() {
	check();
};