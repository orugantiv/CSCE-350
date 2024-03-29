/**
 * Programmer Name: V.N. Anriudh Oruganti
 * Class: CSCE 350
 * Copyright 2021 V.N. Anirudh Oruganti
 **/
#ifndef INC_ORUGANTI_V_N_ANIRUDH_NUMBERGENRATOR_H_
#define INC_ORUGANTI_V_N_ANIRUDH_NUMBERGENRATOR_H_

#include <random>  // For Random Number
#include <string>  // For string
#include <vector>  // For vector

class NumberGenrator {
 public:
  NumberGenrator(std::vector<float>::size_type numberLenth = 10);
  std::vector<float> getGenratedValues();
  void clearValues();

 private:
  const int LEFT_BOUND = -100;
  const int RIGHT_BOUND = 100;
  std::vector<float> _genratedValues;
};

#endif  // INC_ORUGANTI_V_N_ANIRUDH_NUMBERGENRATOR_H_