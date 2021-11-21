/**
 * Programmer Name: V.N. Anriudh Oruganti
 * Class: CSCE 350
 * Application:
 * Excution:
 * Copyright 2021 V.N. Anirudh Oruganti
 **/
#ifndef INC_QUICKSORT_H_
#define INC_QUICKSORT_H_

#include <vector>  // For vector 
#include <string>  // For string
#include <chrono>  // For time

 
class QuickSort {
 public:
  QuickSort(std::vector<float> DataVector) { _dataList = DataVector; }

  void swap(int leftIndex, int rightIndex);

  int median_of_three(int firstIndex,int middleIndex,int lastIndex);

  void doSort(int firstIndex, int lastIndex);

  int doPartition(int firstIndex, int lastIndex);
  // returns a vector that contains list of floats
  std::vector<float> getDataVector() { return _dataList; }

 private:
  std::vector<float> _dataList;
  std::string _dataString;
};

#endif  // INC_QUICKSORT_H_