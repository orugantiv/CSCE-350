/**
 * Programmer Name: V.N. Anriudh Oruganti
 * Class: CSCE 350
 * Application: Gathers both paths of input and output files and call to do quicksort.
 * Copyright 2021 V.N. Anirudh Oruganti
 **/

#include <CSCE350Project_Oruganti_V.N.Anirudh/src/Oruganti_V.N.Anirudh_QuickSort.cpp>

int main(int argc, char *argv[]) {
  // Makes sure input is length is 3.
  assert(argc == 3 && "Incorrect Number of Arguments ");
  QuickSort test(argv[1],argv[2]);
  return 0;
}