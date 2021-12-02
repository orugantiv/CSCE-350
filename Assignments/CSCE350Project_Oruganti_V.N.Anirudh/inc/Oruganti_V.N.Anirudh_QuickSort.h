/**
 * Programmer Name: V.N. Anriudh Oruganti
 * Class: CSCE 350
 * Copyright 2021 V.N. Anirudh Oruganti
 **/
#ifndef INC_ORUGANTI_V_N_ANIRUDH_QUICKSORT_H_
#define INC_ORUGANTI_V_N_ANIRUDH_QUICKSORT_H_

#include <CSCE350Project_Oruganti_V.N.Anirudh/src/Oruganti_V.N.Anirudh_FileReadWrite.cpp>
#include <chrono>  // For time
#include <string>  // For string
#include <vector>  // For vector

class QuickSort {
 public:
  QuickSort(std::vector<float> DataVector);

  QuickSort(std::string inputFilePath, std::string outputFilePath);

  void swap(int leftIndex, int rightIndex);

  int median_of_three(int firstIndex, int middleIndex, int lastIndex);

  void doSort(int firstIndex, int lastIndex);

  int doPartition(int firstIndex, int lastIndex);
  // returns a vector that contains list of floats
  std::vector<float> getDataVector() { return _dataList; }

  float getExecutionTime() { return executionTime; }

 private:
  std::vector<float> _dataList;
  std::string _dataString;
  FileReadWrite _file;
  float executionTime;
};

#endif  // INC_ORUGANTI_V_N_ANIRUDH_QUICKSORT_H_