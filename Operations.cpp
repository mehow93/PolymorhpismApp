#include "Operations.h"
#include <bits/stdc++.h>

std::string DeleteChar::deleteChar(std::string inputString, char charToDelete){
    for (auto& stringChar : inputString){
        if( stringChar == charToDelete)
            stringChar = '_';
    }
    return inputString;
}

std::string ReverseData::reverseData(std::string inputData){
    reverse(inputData.begin(), inputData.end());
    return inputData;
};


