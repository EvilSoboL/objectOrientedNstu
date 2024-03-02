#define _USE_MATH_DEFINES

#include <iostream>
#include "HuberDistribution.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <conio.h>


using namespace std;


// �������� �������� ���������� �������������
static void check() {
	vector<double> shapes = { 0.5, 0.75, 1, 1.5, 2, 2.5, 3 };

	for (size_t i = 0; i < shapes.size(); ++i) {
		HuberDistribution dist(0.0, 1.0, shapes[i], "Note");

		cout << "For nu = " << shapes[i] << endl;
		cout << "Variance: " << dist.sqrt_dispersion() << endl;
		cout << "Kurtosis: " << dist.kurtosis_coefficient() << endl;
		cout << "P: " << dist.hitting_central_interval() << endl;
		cout << "f0: " << dist.density(0) << endl;
		cout << "z: " << dist.random_value(1) << endl;
	};
};

// ��������� �������
static vector<double> generate_sample(int sample_len) {
	HuberDistribution dist(0.0, 1.0, 0.5, "Note");
	vector<double> samples;

	for (int i = 0; i < sample_len; ++i)
		samples.push_back(dist.random_value(i));
	return samples;
};

static double my_mean(vector<double> sample) {
	int N = size(sample);
	double sum = accumulate(begin(sample), end(sample), 0.);

	return sum / N;
};

static double my_median(vector<double> sample) {
	int N = size(sample);

	auto pos = begin(sample) + N / 2;  // ���� [N/2+1]-� ���������� ����������
	nth_element(begin(sample), pos, end(sample));
	double median;
	if (N % 2)  // ��� ��������� N
		median = *pos;
	else {  // ��� ������� N
		auto pos1 = max_element(begin(sample), pos); // ���� [N/2]- � ���������� ���������� ������ � ������ �������� �������
		median = (*pos + *pos1) / 2.;
	}
	return median;
};

static pair<double, double> my_treamed_winsored_mean(double alpha, vector<double> sample) {
	int N = size(sample);
	auto pos = begin(sample) + N / 2;  // ���� [N/2+1]-� ���������� ����������

	int k = int(alpha * N);  // ���������� ���������� ������������� ���������
	auto tr_beg = begin(sample) + k;  // ���� ������ ������� �����
	nth_element(begin(sample), tr_beg, pos);
	auto tr_end = end(sample) - k;  // ���� �������, ��������� �� ��������� 
	nth_element(++pos, tr_end, end(sample)); // ��������� �����
	double tr_sum = accumulate(tr_beg, tr_end, 0.); // ���������
	double wi_sum = tr_sum += k * (*tr_beg + *(tr_end - 1));  // ������������ �����
	return make_pair((tr_sum / (N - 2 * k)), wi_sum / N);
};

static pair<double, double> my_min_max(double alpha, vector<double> sample) {
	int N = size(sample);
	double min, max;
	int k = int(alpha * N);
	auto tr_beg = begin(sample) + k;
	auto tr_end = end(sample) - k;

	min = *min_element(begin(sample), tr_beg); // ���� ������ � ������
	max = *max_element(tr_end, end(sample)); // ���� ������ � ����� 
	return make_pair(min, max);
};

// ���������� ���������� �������������
static void sample_analysis(vector<double> sample) {
	double alpha = 0.2;

	cout << "mean is: " << my_mean(sample) << endl;
	cout << "median is: " << my_median(sample) << endl;

	double treamed_mean = my_treamed_winsored_mean(alpha, sample).first;
	double winsored_mean = my_treamed_winsored_mean(alpha, sample).second;

	cout << alpha << "-trimmed mean is: " << treamed_mean << endl;
	cout << alpha << "-winsorized mean is: " << winsored_mean << endl;
	cout << "min is: " << my_min_max(alpha, sample).first << endl;
	cout << "max is: " << my_min_max(alpha, sample).second << endl;
};

void main() {
	// check();
	vector <double> sample = generate_sample(1000);
	sample_analysis(sample);
};