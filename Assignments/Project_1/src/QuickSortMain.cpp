#include <Project_1/src/QuickSort.cpp>
#include <Project_1/src/FileReadWrite.cpp>
int main(int argc, char *argv[]) {
  // Makes sure input is length is 3.

  assert(argc == 3 && "Incorrect Number of Arguments ");
  FileReadWrite file;
  std::vector<float> dataList = file.readFile(argv[1]);
  QuickSort sort(dataList);
  sort.doSort(0, dataList.size() - 1);
  dataList = sort.getDataVector();
  file.setDataVector(dataList);
  file.writeFile(argv[2]);


//   std::cout << '\n' << std::endl;
//   for (int i = 0; i < dataList.size(); ++i) std::cout << dataList[i] << ' ';

  return 0;
}