#include "SampleCharacteristics.h"
#include "HuberDistribution.h"
#include <algorithm>
#include <numeric>
#include <cmath>
#include <fstream>
#include <iostream>

// Предполагается, что класс HuberDistribution уже определён где-то
// и имеет метод random_value(int seed) для генерации случайного значения

double SampleCharacteristics::mean() {
	int N = size(sample);
	double sum = accumulate(begin(sample), end(sample), 0.);

	return sum / N;
}

double SampleCharacteristics::median() {
	int N = size(sample);

	auto pos = begin(sample) + N / 2;  // ищем [N/2+1]-ю порядковую статистику
	nth_element(begin(sample), pos, end(sample));
	double median;
	if (N % 2)  // для нечетного N
		median = *pos;
	else {  // для четного N
		auto pos1 = max_element(begin(sample), pos); // ищем [N/2]- ю порядковую статистику только в первой половине выборки
		median = (*pos + *pos1) / 2.;
	}
	return median;
}

pair<double, double> SampleCharacteristics::trimmedWinsorizedMean(double alpha) {
	int N = size(sample);
	auto pos = begin(sample) + N / 2;  // ищем [N/2+1]-ю порядковую статистику

	int k = int(alpha * N);  // определяем количество отбрасываемых элементов
	auto tr_beg = begin(sample) + k;  // ищем первый элемент суммы
	nth_element(begin(sample), tr_beg, pos);
	auto tr_end = end(sample) - k;  // ищем элемент, следующий за последним 
	nth_element(++pos, tr_end, end(sample)); // элементом суммы
	double tr_sum = accumulate(tr_beg, tr_end, 0.); // суммируем
	double wi_sum = tr_sum += k * (*tr_beg + *(tr_end - 1));  // модифицируем сумму
	return make_pair((tr_sum / (N - 2 * k)), wi_sum / N);
}

pair<double, double> SampleCharacteristics::minMax(double alpha) {
	int N = size(sample);
	double min, max;
	int k = int(alpha * N);
	auto tr_beg = begin(sample) + k;
	auto tr_end = end(sample) - k;

	min = *min_element(begin(sample), tr_beg); // ищем только в начале
	max = *max_element(tr_end, end(sample)); // ищем только в конце 
	return make_pair(min, max);
}

void SampleCharacteristics::sampleAnalysis() {
	double alpha = 0.2;

	cout << "mean is: " << mean() << endl;
	cout << "median is: " << median() << endl;

	double treamed_mean = trimmedWinsorizedMean(alpha).first;
	double winsored_mean = trimmedWinsorizedMean(alpha).second;

	cout << alpha << "-trimmed mean is: " << treamed_mean << endl;
	cout << alpha << "-winsorized mean is: " << winsored_mean << endl;
	cout << "min is: " << minMax(alpha).first << endl;
	cout << "max is: " << minMax(alpha).second << endl;
}

void SampleCharacteristics::saveToCsv(const string& filename) {
	// Открытие файла для записи (и создание, если не существует)
	ofstream file(filename, ios::trunc);

	// Проверка, открыт ли файл
	if (!file.is_open()) {
		cerr << "Error while openning file" << endl;
		return;
	}

	// Запись данных выборки в файл в формате CSV
	for (const auto& value : sample) {
		file << value << "\n";
	}

	// Закрытие файла
	file.close();

	cout << "Sample saved '" << filename << "'." << endl;
}

vector<double> SampleCharacteristics::generateDensity(double shift, double scale, double shape) {
	HuberDistribution dist(shift, scale, shape, "Note");
	vector<double> density;

	for (int i = 0; i < sample.size(); ++i)
		density.push_back(dist.density(sample[i]));
	return density;
}
