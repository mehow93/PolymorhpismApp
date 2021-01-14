#include "Operations.h"
#include <bits/stdc++.h>

std::string DeleteChar::deleteChar(std::string& inputString, char charToDelete){
    std::string result = inputString; //copy string to avoid overwritting orginal input

    for (auto& stringChar : result){
        if( stringChar == charToDelete)
            stringChar = '_';
    }
    return result;
}

std::string ReverseData::reverseData(std::string& inputData){
    std::string result = inputData;
    reverse(result.begin(), result.end());
    return result;
};
