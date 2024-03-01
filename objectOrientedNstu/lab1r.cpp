#define _USE_MATH_DEFINES

#include <cmath>
#include <random>
#include <stdexcept>
#include <string>
#include <iostream>

#include "HuberDistribution.h"

using namespace std;

int main() {
	HuberDistribution dist(1.0, 1.0, 0.0, "Note");
	return 0;
}