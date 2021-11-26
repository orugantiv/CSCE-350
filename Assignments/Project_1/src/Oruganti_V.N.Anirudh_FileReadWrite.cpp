#include <Project_1/inc/Oruganti_V.N.Anirudh_FileReadWrite.h>

  std::vector<float> FileReadWrite::readFile(std::string path) {
    std::string temp;
    std::fstream dataFile;

    dataFile.open(path.c_str());
    assert(dataFile.is_open() && "***Could Not Open The File***");
    while (dataFile >> temp) _dataList.push_back(std::stof(temp));

    return _dataList;
  }

    void FileReadWrite::writeFile(std::string path, float executionTime) {
    std::ofstream dataOutputFile;
    dataOutputFile.open(path.c_str());
    assert(dataOutputFile.is_open() && "***Could Not Open The File***");
    for (std::vector<float>::size_type i = 0; i < _dataList.size(); ++i){
      dataOutputFile << std::fixed<<std::setprecision(6)<<_dataList[i]
                     << ((i != (_dataList.size() - 1)) ? " " : "\n");}
      if(executionTime != -999)
      dataOutputFile << std::fixed<<std::setprecision(30)<< executionTime;     
  }

  void FileReadWrite::writeFile( std::vector<std::vector<float>> executionTime, 
                  std::vector<std::vector<float>> averageExecutionTime, char**& argv){
                
                  std::ofstream dataOutputFile;
                  
                  std::string executionTimePath = "Oruganti_V.N.Anirudh_executionTime.txt";
                  std::string averageExecutionTimePath = "Oruganti_V.N.Anirudh_averageExecutionTime.txt";

                  dataOutputFile.open(executionTimePath.c_str());
                  dataOutputFile<<"Input Size\t"<<"Execution Time\n";
                  for (std::vector<float>::size_type i = 0; i < executionTime.size()-1; ++i){
                     for (std::vector<float>::size_type ii = 0; ii < 100; ++ii){
                          dataOutputFile<< std::fixed<<std::setprecision(10)
                                        << argv[i+1]<<"\t"<<executionTime[i][ii]<<"\n";
                     }
                  }

                  dataOutputFile.close();
                  dataOutputFile.open(averageExecutionTimePath.c_str());
                  dataOutputFile<<"Input Size\t"<<"Average Execution Time\n";
                  for (std::vector<float>::size_type i = 0; i < averageExecutionTime.size()-1; ++i){
                          dataOutputFile<< std::fixed<<std::setprecision(10)
                                        << argv[i+1]<<"\t"<<averageExecutionTime[i][i]<<"\n";
                  }
                  dataOutputFile.close();

  }

  void FileReadWrite::setDataVector(std::vector<float> newDataVector) {
    _dataList = newDataVector;
  }
  std::vector<float> FileReadWrite::getDataVector() { return _dataList; }