//
// Created by mykhailo on 18.05.24.
//

#ifndef LAB4_CSVREADER_HPP
#define LAB4_CSVREADER_HPP


#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

class CSVReader {
public:
    CSVReader(const std::string& filename);
    std::string readRow();

private:
    std::ifstream file;
};

#endif//LAB4_CSVREADER_HPP
