#include <Project_1/src/Oruganti_V.N.Anirudh_QuickSort.cpp>
#include <Project_1/src/Oruganti_V.N.Anirudh_FileReadWrite.cpp>
#include <iostream>
int main(int argc, char *argv[]) {
  // Makes sure input is length is 3.

  assert(argc == 3 && "Incorrect Number of Arguments ");
  FileReadWrite file;
  std::vector<float> dataList = file.readFile(argv[1]);
  QuickSort sort(dataList);
  auto start = std::chrono::high_resolution_clock::now();
  sort.doSort(0, dataList.size() - 1);
  auto stop = std::chrono::high_resolution_clock::now();
  float duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  dataList = sort.getDataVector();
  file.setDataVector(dataList);
  file.writeFile(argv[2],duration/1000);

  return 0;
}