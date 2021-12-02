/**
 * Programmer Name: V.N. Anriudh Oruganti
 * Class: CSCE 350
 * Copyright 2021 V.N. Anirudh Oruganti
 **/
#ifndef INC_ORUGANTI_V_N_ANIRUDH_FILEREADWRITE_H_
#define INC_ORUGANTI_V_N_ANIRUDH_FILEREADWRITE_H_

#include <cassert>  // For assertion
#include <fstream>  // For Read and Write File
#include <iomanip>  // For std::setprecision
#include <string>   // For string
#include <vector>   // For vector

class FileReadWrite {
 public:
  // This method read in the input from a given path of file and saves the
  // values to vector.
  std::vector<float> readFile(std::string path);
  void writeFile(std::string path, float executionTime = -999);
  void writeFile(std::vector<std::vector<float>> executionTime,
                 std::vector<std::vector<float>> averageExecutionTime,
                 char**& argv);
  void setDataVector(std::vector<float> newDataVector);
  std::vector<float> getDataVector();

 private:
  std::vector<float> _dataList;
};

#endif  // INC_ORUGANTI_V_NANIRUDH_FILEREADWRITE_H_