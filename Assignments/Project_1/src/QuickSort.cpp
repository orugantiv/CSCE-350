/**
 * Programmer Name: V.N. Anriudh Oruganti
 * Class: CSCE 350
 * Application:
 * Excution:
 * Copyright 2021 V.N. Anirudh Oruganti
 **/

// Includes
#include <Project_1/inc/QuickSort.h>

  void QuickSort::swap(int leftIndex, int rightIndex) {
    float temp = 0;
    temp = _dataList[leftIndex];
    _dataList[leftIndex] = _dataList[rightIndex];
    _dataList[rightIndex] = temp;
  }

int main(int argc, char *argv[]) {
  // Makes sure input is length is 3.
  assert(argc == 3 && "Incorrect Number of Arguments ");
  FileReadWrite file;
  std::vector<float> dataList = file.readFile(argv[1]);
  QuickSort sort(dataList);
  for (int i = 0; i < dataList.size(); ++i) std::cout << dataList[i] << ' ';

  sort.doSort(0, dataList.size() - 1);

  dataList = sort.getDataVector();
  file.setDataVector(dataList);

  file.writeFile(argv[2]);


  std::cout << '\n' << std::endl;
  for (int i = 0; i < dataList.size(); ++i) std::cout << dataList[i] << ' ';

  return 0;
}