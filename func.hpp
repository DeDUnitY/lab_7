#pragma once
#include <vector>


namespace du {
	bool prostoeChislo(int& getNumber);

	void readFromFile(std::vector<std::vector<int>>& matrix);

	bool searchDuplicationColumn(std::vector<std::vector<int>>& matrix);

	bool Nalichie_prost_chisl(std::vector<std::vector<int>>& matrix);

	void cout_vector(std::vector<int> vec);

	void cout_matrix(std::vector<std::vector<int>>& matrix);

	void writeToFile(std::vector<std::vector<int>>& matrix);
}
