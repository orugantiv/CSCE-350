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

  void swap(int leftIndex, int rightIndex);

  void doSort(int firstIndex, int lastIndex) {
    if ( firstIndex < lastIndex){
      // if(_dataList[firstIndex]>_dataList[middleIndex] && _dataList[lastIndex]>_dataList[middleIndex] )
      //   pivot = middleIndex;
      // else if(_dataList[firstIndex]<_dataList[middleIndex] && _dataList[firstIndex]<_dataList[lastIndex] )
      //   pivot = firstIndex;
      // else pivot = lastIndex;

      // std::cout<<pivot<<std::endl;
      // swap(middleIndex, lastIndex - 1);
      int s = doPartition(firstIndex, lastIndex);
      doSort(firstIndex, (s - 1));
      doSort((s + 1), lastIndex);
    }
  }

  int median_of_three(int firstIndex,int middleIndex,int lastIndex){
    
    return  ((_dataList[firstIndex]<=_dataList[middleIndex] && _dataList[firstIndex]>= _dataList[lastIndex])||
             (_dataList[firstIndex]>=_dataList[middleIndex] && _dataList[firstIndex]<=_dataList[lastIndex]))?firstIndex:
            ((_dataList[middleIndex]<=_dataList[firstIndex] && _dataList[middleIndex]>=_dataList[lastIndex])||
            (_dataList[middleIndex]>=_dataList[firstIndex] && _dataList[middleIndex]<=_dataList[lastIndex]))?middleIndex:lastIndex;
            
  }

  int doPartition(int firstIndex, int lastIndex) {
    int middleIndex = (lastIndex+firstIndex)/2;
    int pivotIndex = median_of_three(firstIndex,middleIndex,lastIndex);
    if(pivotIndex!=firstIndex)
        swap(pivotIndex,firstIndex);
    float pivot =  _dataList[firstIndex];


    int i = firstIndex;
    int j = lastIndex+1;
        while (true)
    {
        while (!(_dataList[++i] >= pivot))
            ;
        while (!(_dataList[--j] <= pivot))
            ;
        if (i >= j)
            break;
            swap(i, j);

    }
    swap(firstIndex,j);
     return j;

  }

  // returns a vector that contains list of floats
  std::vector<float> getDataVector() { return _dataList; }

 private:
  std::vector<float> _dataList;
  std::string _dataString;
};

#endif  // INC_QUICKSORT_H_