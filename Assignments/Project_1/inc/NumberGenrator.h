/**
 * Programmer Name: V.N. Anriudh Oruganti
 * Class: CSCE 350
 * Application:
 * Excution:
 * Copyright 2021 V.N. Anirudh Oruganti
 **/
#ifndef INC_NUMBERGENRATOR_H_
#define INC_NUMBERGENRATOR_H_

#include <vector>  // For vector 
#include <string>  // For string
#include <random>  // For Random Number

class NumberGenrator{
public:
    NumberGenrator(std::vector<float>::size_type numberLenth = 10);
    std::vector<float> getGenratedValues();
    void clearValues();
private:
    const int LEFT_BOUND = -100;
    const int RIGHT_BOUND = 100;
    std::vector<float> _genratedValues;
};





#endif  // INC_NUMBERGENRATOR_H_