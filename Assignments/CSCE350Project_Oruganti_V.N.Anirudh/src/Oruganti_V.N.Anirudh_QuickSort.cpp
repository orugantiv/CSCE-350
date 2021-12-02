/**
 * Programmer Name: V.N. Anriudh Oruganti
 * Class: CSCE 350
 * Application:Perform Quick Sort to a given inputfile and calculates executionTime and writes to given output file path 
 * Excution: 
 * Copyright 2021 V.N. Anirudh Oruganti
 **/

// Includes
#include <CSCE350Project_Oruganti_V.N.Anirudh/inc/Oruganti_V.N.Anirudh_QuickSort.h>
QuickSort::QuickSort(std::string inputFilePath, std::string outputFilePath) {
  _dataList = _file.readFile(inputFilePath);
  auto start = std::chrono::high_resolution_clock::now();
  doSort(0, _dataList.size() - 1);
  auto stop = std::chrono::high_resolution_clock::now();
  executionTime =
      std::chrono::duration_cast<std::chrono::microseconds>(stop - start)
          .count();
  executionTime /= 1000;
  _file.setDataVector(_dataList);
  _file.writeFile(outputFilePath, executionTime);
}

void QuickSort::swap(int leftIndex, int rightIndex) {
  float temp = 0;
  temp = _dataList[leftIndex];
  _dataList[leftIndex] = _dataList[rightIndex];
  _dataList[rightIndex] = temp;
}

int QuickSort::median_of_three(int firstIndex, int middleIndex, int lastIndex) {
  return ((_dataList[firstIndex] <= _dataList[middleIndex] &&
           _dataList[firstIndex] >= _dataList[lastIndex]) ||
          (_dataList[firstIndex] >= _dataList[middleIndex] &&
           _dataList[firstIndex] <= _dataList[lastIndex]))
             ? firstIndex
         : ((_dataList[middleIndex] <= _dataList[firstIndex] &&
             _dataList[middleIndex] >= _dataList[lastIndex]) ||
            (_dataList[middleIndex] >= _dataList[firstIndex] &&
             _dataList[middleIndex] <= _dataList[lastIndex]))
             ? middleIndex
             : lastIndex;
}
void QuickSort::doSort(int firstIndex, int lastIndex) {
  if (firstIndex < lastIndex) {
    int s = doPartition(firstIndex, lastIndex);
    doSort(firstIndex, (s - 1));
    doSort((s + 1), lastIndex);
  }
}
int QuickSort::doPartition(int firstIndex, int lastIndex) {
  int middleIndex = (lastIndex + firstIndex) / 2;
  int pivotIndex = median_of_three(firstIndex, middleIndex, lastIndex);
  swap(pivotIndex, firstIndex);
  pivotIndex = firstIndex;
  float pivot = _dataList[pivotIndex];
  int i = firstIndex;
  int j = lastIndex;

  while (1) {
    while ((_dataList[i] < pivot || i == pivotIndex) && (i + 1) <= lastIndex &&
           (i + 1) >= firstIndex)
      ++i;
    while ((_dataList[j] > pivot || j == pivotIndex) && (j - 1) >= firstIndex &&
           (j - 1) <= lastIndex)
      --j;
    if (i >= j) {
      break;
    }
    swap(i, j);
    ++i;
    --j;
  }
  swap(pivotIndex, j);
  return j;
}
