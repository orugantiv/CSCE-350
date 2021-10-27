/**
 * Programmer Name: V.N. Anriudh Oruganti
 * Class: CSCE 350
 * Application:
 * Excution:
 * Copyright 2021 V.N. Anirudh Oruganti
 **/
#ifndef INC_QUICKSORT_H_
#define INC_QUICKSORT_H_

#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

class FileReadWrite {
 public:
  // This method read in the input from a given path of file and saves the
  // values to vector.
  std::vector<float> readFile(std::string path) {
    std::string temp;
    std::fstream dataFile;
    dataFile.open(path.c_str());
    assert(dataFile.is_open() && "***Could Not Open The File***");
    while (dataFile >> temp) _dataList.push_back(std::stof(temp));
    return _dataList;
  }
  void writeFile(std::string path) {
    std::ofstream dataOutputFile;
    dataOutputFile.open(path.c_str());
    assert(dataOutputFile.is_open() && "***Could Not Open The File***");
    for (std::vector<float>::size_type i = 0; i < _dataList.size(); ++i)
      dataOutputFile << _dataList[i]
                     << ((i != (_dataList.size() - 1)) ? " " : "");
  }

  void setDataVector(std::vector<float> newDataVector) {
    _dataList = newDataVector;
  }
  std::vector<float> getDataVector() { return _dataList; }

 private:
  std::vector<float> _dataList;
};
class QuickSort {
 public:
  QuickSort(std::vector<float> DataVector) { _dataList = DataVector; }
  void swap(int leftIndex, int rightIndex) {
    float temp = 0;
    temp = _dataList[leftIndex];
    _dataList[leftIndex] = _dataList[rightIndex];
    _dataList[rightIndex] = temp;
  }
  void doSort(int firstIndex, int lastIndex) {
    int middleIndex = (firstIndex + lastIndex) / 2;
    int newIndex = 0;

    if (_dataList[lastIndex] < _dataList[middleIndex])
      swap(lastIndex, middleIndex);
    if (_dataList[middleIndex] < _dataList[firstIndex])
      swap(middleIndex, firstIndex);
    if (_dataList[lastIndex] < _dataList[middleIndex])
      swap(middleIndex, lastIndex);

    if (lastIndex - firstIndex <= 2)
      return;

    else {
      swap(middleIndex, lastIndex - 1);
      newIndex =
          doPartition(firstIndex, lastIndex - 1, _dataList[lastIndex - 1]);
      doSort(firstIndex, (newIndex - 1));
      doSort((newIndex + 1), lastIndex);
    }
  }
  int doPartition(int firstIndex, int lastIndex, float pivot) {
    int pivotInitialIndex = lastIndex;
    if (_dataList[firstIndex] < pivot)
      doPartition(++firstIndex, lastIndex, pivot);
    else if (_dataList[lastIndex] > pivot)
      doPartition(firstIndex, --lastIndex, pivot);
    else if (firstIndex >= lastIndex) {
      swap(firstIndex, pivotInitialIndex);
      return firstIndex;
    } else {
      swap(firstIndex, lastIndex);
      doPartition(firstIndex, lastIndex, pivot);
    }

    // while (true)
    // {
    //     while (_dataList[++firstIndex] < pivot)
    //         ;
    //     while (_dataList[--lastIndex] > pivot)
    //         ;
    //     if (firstIndex >= lastIndex)
    //         break;
    //     swap(firstIndex, lastIndex);
    // }

    //  swap(firstIndex, pivotInitialIndex);
  }

  // returns a vector that contains list of floats
  std::vector<float> getDataVector() { return _dataList; }

 private:
  std::vector<float> _dataList;
  std::string _dataString;
};

#endif  // INC_QUICKSORT_H_