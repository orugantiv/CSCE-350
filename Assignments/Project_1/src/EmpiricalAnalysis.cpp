#include <Project_1/src/QuickSort.cpp>
#include <Project_1/src/FileReadWrite.cpp>
#include <Project_1/src/NumberGenrator.cpp>
#include <iostream>
#include <filesystem>
int main(int argc, char* argv[]) {
  // Makes sure input is length is grater than 2.
  assert(argc >= 2 && "Incorrect Number of Arguments ");
  std::vector<std::vector<float>> executionTime, averageExecutionTime;
  const int numFiles = 100;
  executionTime.resize(argc, std::vector<float>(argc*numFiles, 0));
  averageExecutionTime.resize(argc, std::vector<float>(argc, 0));


  FileReadWrite file;
  // Deletes All existing files in both FloatDataValues/InputData/ && FloatDataValues/OutputData/
  // Referance: https://en.cppreference.com/w/cpp/filesystem/directory_iterator
    for (auto FilePath: std::filesystem::directory_iterator("FloatDataValues/InputData/")) {
        std::filesystem::remove_all(FilePath);
    }
    for (auto FilePath: std::filesystem::directory_iterator("FloatDataValues/OutputData/")) {
        std::filesystem::remove_all(FilePath);
    }
    

  for(int i = 1; i < argc; ++i){
    std::string path = "FloatDataValues/";
    std::string typeInput = "InputData/input_"+std::string{argv[i]}+"_";
    std::string typeOutput = "OutputData/output_"+std::string{argv[i]}+"_";    
    for(int ii = 0;ii<numFiles;++ii){
        // Genrates and Writes unsorted array to input files
        NumberGenrator randomDataSet(std::stoi(std::string{argv[i]}));
        auto dataset = randomDataSet.getGenratedValues();
        file.setDataVector(dataset);
        std::string newPath{std::to_string(ii+1)};
        file.writeFile(path+typeInput+newPath);

        //Performs Quick Sort and writes the valus to output
        QuickSort sort(dataset);
        auto start = std::chrono::high_resolution_clock::now();
        sort.doSort(0, dataset.size() - 1);
        auto stop = std::chrono::high_resolution_clock::now();
        float duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
        dataset = sort.getDataVector();
        file.setDataVector(dataset);
        file.writeFile(path+typeOutput+newPath,duration/1000);
        executionTime[i-1][ii] = duration/1000;
        averageExecutionTime[i-1][i-1] += duration/1000;
    }
        averageExecutionTime[i-1][i-1]/= numFiles;
  }
    file.writeFile(executionTime,averageExecutionTime,argv);
  return 0;
}