#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

namespace du {

int prostoeChislo(int& N) {
    if (N == 0 || N == 1) {
        return false;
    }
    else {
        for (int i = 2; i <= sqrt(N); ++i) {
            if (N % i == 0) {
                return false;
            }
        }
    }
    return true;
}

bool Nalichie_prost_chisl(std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (prostoeChislo(matrix[i][j]))
                return true;
        }
    }
    return false;
}

void readFromFile(std::vector<std::vector<int>> &matrix) {

    std::ifstream in("input.txt", std::ios::in);
    int numi;
    int numj;
    in >> numi;
    in >> numj;
    int num = 0;

    for (int i = 0; i < numi; i++) {
        for (int j = 0; j < numj; j++) {
            in >> num;
            matrix[i][j] = num;
        }
    }
}

void writeToFile(std::vector<std::vector<int>>& matrix) {
    std::ofstream out("output.txt", std::ios::out);
    int num;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            num = matrix[i][j];
            out << num << " ";
        }
        out << "\n";
    }

}

void cout_vector(std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

void cout_matrix(std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        cout_vector(matrix[i]);
    }
}

bool searchDuplicationColumn(std::vector<std::vector<int>>& matrix) {
    std::vector<int> a(matrix.size());
    std::vector<int> b(matrix.size());

    for (int j = 0; j < matrix[0].size() - 1; j++) {
        for (int k = j + 1; k < matrix[0].size(); k++) {
            a.clear();
            b.clear();
            for (int i = 0; i < matrix.size(); i++) {
                a.push_back(matrix[i][j]);
                b.push_back(matrix[i][k]);
            }
            std::cout << "\n";
            if (a == b) {
                return true;
            }

        }
    }
    return false;
}
}
