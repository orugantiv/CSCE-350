# CSCE 350: V. N. Anirudh Oruganti, Project 1 
---

## Required Dependencys
---
> C++: g++ compiler 
> Python for Graphing: Numpy and Matplotlib


## The Following Folders are Requried to Compile the Project inside Project Folder
--- 
> 'bin/'
> 'FloatDataValues/InputData'
> 'FloatDataValues/OutputData'


## About File Generation
---
> Genereated input files are stored in 'FloatDataValues/InputData' dir with naming format of 'input_InputSize_nthFilein100'. 
For example 'input_10_57', denotes for input file with 10 Input size and 57th file out of 100. 
> Sorted outfile is stored in 'FloatDataValues/OutputData' dir with naming format of 'output_InputSize_nthFilein100'.
For example 'output_10_57', denotes for output file with 10 Input size and 57th file out of 100. In the output file, the first line containes sorted values from the input file and the second line containes the execution time in miliseconds it took to sort.
> File Genration cpp file contains a main method where input files are generaded with random float numbers. Then this class it calls quick sort and gets excution times from quick sort class and records it to two vectors where one vector has excution times for all genrated files. And other has the avg excution time. 



## How to Run the Project
---
### Quick Sort
> 

### File Generation
> To use File Generation: Uncomment following lines:
	`Line 15: Oruganti_V.N.Anirudh_InputFileGenerator: bin/Oruganti_V.N.Anirudh_InputFileGenerator.o
	 Line 16: 	$(link) $@  $^
	 Line 17: bin/Oruganti_V.N.Anirudh_InputFileGenerator.o: src/Oruganti_V.N.Anirudh_InputFileGenerator.cpp  bin/Oruganti_V.N.Anirudh_NumberGenrator.o bin/Oruganti_V.N.Anirudh_QuickSort.o
	 Line 18: 	$(compile) $< -o $@`
> Run `./Oruganti_V.N.Anirudh_InputFileGenerator input_0 input_1 input_(n-1)': Where "input_(n-1)" is an integer of number generated values and you need have at least one input.
> Example: `./Oruganti_V.N.Anirudh_InputFileGenerator 10 100 1000 10000 100000`

### Cleaning Binarys 


