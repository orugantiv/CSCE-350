#include <Project_1/inc/FileReadWrite.h>

  std::vector<float> FileReadWrite::readFile(std::string path) {
    std::string temp;
    std::fstream dataFile;

    dataFile.open(path.c_str());
    assert(dataFile.is_open() && "***Could Not Open The File***");
    while (dataFile >> temp) _dataList.push_back(std::stof(temp));

    return _dataList;
  }

    void FileReadWrite::writeFile(std::string path) {
    std::ofstream dataOutputFile;
    dataOutputFile.open(path.c_str());
    assert(dataOutputFile.is_open() && "***Could Not Open The File***");
    for (std::vector<float>::size_type i = 0; i < _dataList.size(); ++i)
      dataOutputFile << std::fixed<<std::setprecision(6)<<_dataList[i]
                     << ((i != (_dataList.size() - 1)) ? " " : "");
  }
  void FileReadWrite::setDataVector(std::vector<float> newDataVector) {
    _dataList = newDataVector;
  }
  std::vector<float> FileReadWrite::getDataVector() { return _dataList; }