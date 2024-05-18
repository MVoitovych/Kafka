//
// Created by mykhailo on 18.05.24.
//

#include "../include/CSVReader.hpp"
CSVReader::CSVReader(const std::string &filename) {
    file.open(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
}

std::string CSVReader::readRow() {

    std::string line;
    if (std::getline(file, line)) {
        std::stringstream ss(line);
    }

    return line;
}