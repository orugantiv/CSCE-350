/**
 * Programmer Name: V.N. Anriudh Oruganti
 * Class: CSCE 350
 * Application: Read and Writes Floats to Files from and to Vector
 * Excution:
 * Copyright 2021 V.N. Anirudh Oruganti
 **/

#include <CSCE350Project_Oruganti_V.N.Anirudh/src/Oruganti_V.N.Anirudh_NumberGenrator.cpp>
#include <CSCE350Project_Oruganti_V.N.Anirudh/src/Oruganti_V.N.Anirudh_QuickSort.cpp>

int main(int argc, char* argv[]) {
  // Makes sure input is length is grater than 2.
  assert(argc >= 2 && "Incorrect Number of Arguments ");
  std::vector<std::vector<float>> executionTime, averageExecutionTime;
  const int numFiles = 100;
  executionTime.resize(argc, std::vector<float>(argc * numFiles, 0));
  averageExecutionTime.resize(argc, std::vector<float>(argc, 0));

  FileReadWrite file;
  // Delets Existing Data in the following folders
  system("rm -rf FloatDataValues/InputData/* FloatDataValues/OutputData/*");

  for (int i = 1; i < argc; ++i) {
    std::string path = "FloatDataValues/";
    std::string typeInput = "InputData/input_" + std::string{argv[i]} + "_";
    std::string typeOutput = "OutputData/output_" + std::string{argv[i]} + "_";
    for (int ii = 0; ii < numFiles; ++ii) {
      // Genrates and Writes unsorted array to input files
      NumberGenrator randomDataSet(std::stoi(std::string{argv[i]}));
      auto dataset = randomDataSet.getGenratedValues();
      file.setDataVector(dataset);
      std::string newPath{std::to_string(ii + 1)};
      file.writeFile(path + typeInput + newPath);
      QuickSort sort(path + typeInput + newPath, path + typeOutput + newPath);
      executionTime[i - 1][ii] = sort.getExecutionTime();
      averageExecutionTime[i - 1][i - 1] += sort.getExecutionTime();
    }
    averageExecutionTime[i - 1][i - 1] /= numFiles;
  }
  file.writeFile(executionTime, averageExecutionTime, argv);
  return 0;
}