//
// Created by shilo on 12/11/2022.
//
//#include "calculation//Distance.h"
#include <iostream>
#include <string>
#include "calculate/Distance.h"
#include "calculate/Euclidean.h"

using namespace std;

std::vector<std::string> splitString(std::string str) {
    std::vector<std::string> result;
    std::string delimiter  = " ", token;
    size_t position = 0;
    while ((str.find(delimiter) != std::string::npos)) {
        //taking the substring from starting position to the delimiter position.
        position = str.find(delimiter);
        token = str.substr(0, position);
        //std::cout << token <<std::endl;
        result.push_back(token);
        str.erase(0, position + delimiter.size());
        token = str;
    }
    //std::cout << token << std::endl;
    result.push_back(token);
    return result;
}

std::vector<double> convertStrVecToDoubleVec(std::vector<std::string> strVec) {
    std::vector<double> doubleVec;
    int vecLen = strVec.size();
    for (int i = 0 ; i < vecLen ; i++) {
        std::string correctString = strVec[i];
        std::string::const_iterator iterator = correctString.begin();
        while (iterator != correctString.end() && std ::isdigit(*iterator)) {
            ++iterator;
        }
        // is not a number, return empty vec.
        if (iterator != correctString.end()) {
            return {};
        }
        //we sure that this string can be converted to int
        doubleVec.push_back(std::stoi(correctString));
    }
    return doubleVec;
}

bool checkPropriety(std::string v1, std::string v2) {
    std::vector<std::string>  firstLine = splitString(v1);
    std::vector<std::string>  secondLine = splitString(v2);
    if (firstLine.size() != secondLine.size()) {
        return false;
    }
    //the size is equal
    std::vector<double> vec1 = convertStrVecToDoubleVec(firstLine);
    std::vector<double> vec2 = convertStrVecToDoubleVec(secondLine);
    if (vec1.empty() || vec2.empty()) {
        return false;
    }
    return true;

}

int main() {
    std::string vec1;
    std::string vec2;
    string input;

    std::cout << "Enter vectors: " << std::endl;
    getline(cin, vec1);
    getline(cin, vec2);

    if(!checkPropriety(vec1, vec2)) {
        // the string is holding invalid value.
        std::cout << "invalid value" << std::endl;
        return 0; // exit the program.
    }

    // creating a vector from the string;

    std::vector<std::string> vString1 = splitString(vec1);
    std::vector<std::string> vString2 = splitString(vec2);

    //converting to vector type double

    std::vector<double> v1 = convertStrVecToDoubleVec(vString1);
    std::vector<double> v2 = convertStrVecToDoubleVec(vString2);

    // initializing the distance array.

    Euclidean calculate;
    Distance* arr[5];

    // assign the array

    arr[0] = &calculate;


    for (int i = 0; i < 1; i++) {
        std::cout << arr[i]->operator()(v1, v2);
    }

    return 0;
}
