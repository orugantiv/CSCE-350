/**
 * Programmer Name: V.N. Anriudh Oruganti
 * Class: CSCE 350
 * Application:
 * Excution:
 * Copyright 2021 V.N. Anirudh Oruganti
 **/
#ifndef INC_FILEREADWRITE_H_
#define INC_FILEREADWRITE_H_

#include <cassert> // For assertion 
#include <fstream> // For Read and Write File
#include <iomanip> // For std::setprecision
#include <vector>  // For vector
#include <string>  // For string

class FileReadWrite {
 public:
  // This method read in the input from a given path of file and saves the
  // values to vector.
  std::vector<float> readFile(std::string path);
  void writeFile(std::string path);
  void setDataVector(std::vector<float> newDataVector);
  std::vector<float> getDataVector();

 private:
  std::vector<float> _dataList;
};

#endif  // INC_FILEREADWRITE_H_