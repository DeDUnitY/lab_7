#include <iostream>
#include "Func.hpp"
#include <fstream>
#include <vector>
#include <algorithm>

bool comp(std::vector<int>& a, std::vector<int>& b) {
	int sum_a = 0;
	int sum_b = 0;
	for (int i = 0; i < a.size(); i++) {
		sum_a = abs(a[i]);
	}
	for (int i = 0; i < b.size(); i++) {
		sum_b = abs(b[i]);
	}
	return a < b;
}

int main() {
	std::ifstream in("input.txt", std::ios::in);
	std::ofstream out("output.txt", std::ios::out);

	int numi;
	int numj;
	in >> numi;
	in >> numj;


	std::vector<std::vector<int>> matrix(numi);
	for (int i = 0; i < numi; i++) {
		matrix[i].resize(numj);
	}

	du::readFromFile(matrix);
	
	if (du::searchDuplicationColumn(matrix) and du::Nalichie_prost_chisl(matrix)) {
		sort(matrix.begin(), matrix.end(), comp);
	}

	du::cout_matrix(matrix);
	
	du::writeToFile(matrix);
	
    return 0;
}