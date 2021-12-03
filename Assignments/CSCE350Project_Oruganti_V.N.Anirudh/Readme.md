# CSCE 350: V. N. Anirudh Oruganti, Project 1 

## Requirements 

### Required Dependencys

- C++: g++ compiler <br />
- Python for Graphing: Numpy and Matplotlib <br />


### Requried Folders inside Project dir
 
> `'bin/'` <br />
> `'FloatDataValues/InputData'` <br />
> `'FloatDataValues/OutputData'` <br />


## About The Project

## Sources
- I used all informaiton on https://www.cplusplus.com/ for completing this project.

### Assumptions

- The input files contain no other character other than floating point values.
- The Floating Precision is 6.
- For ploting the graph, python could be used.(confimed by professor.)

### File Generation

- Genereated input files are stored in 'FloatDataValues/InputData' dir with naming format of 'input_InputSize_nthFilein100'. <br />
For example 'input_10_57', denotes for input file with 10 Input size and 57th file out of 100. <br />
- Sorted outfile is stored in 'FloatDataValues/OutputData' dir with naming format of 'output_InputSize_nthFilein100'. <br />
For example 'output_10_57', denotes for output file with 10 Input size and 57th file out of 100. In the output file, the first line containes sorted values from the input file and the second line containes the execution time in miliseconds it took to sort. <br />
- File Genration cpp file contains a main method where input files are generaded with random float numbers. Then this class it calls quick sort and gets excution times from quick sort class and records it to two vectors where one vector has excution times for all genrated files. And other has the avg excution time. <br />
- Every time this program get excuted, it clears all the files in input and output directory <br />

### Quick Sort
- In quick sort class, it takes in input file path and output file path and sort the input file write it to output file in the first line. It also records time and in miliseconds adds it to second line. 


## How to Run the Project

### Quick Sort
- To run the Quick Sort follow the steps below: <br />
 		`$ make Oruganti_V.N.Anirudh_QuickSort
 		 $ ./Oruganti_V.N.Anirudh_QuickSort inputFilePath outputFilePath`
- The output file contains both sorted list of floating point values and quick sort excution time in lines 1 and 2 respectivly. 

### Ploting Avarage Time Graph
- To plot the avg. time graph, "Oruganti_V.N.Anirudh_averageExecutionTime.txt" file is required.
- To plot the graph run the following commands: `make Oruganti_V.N.Anirudh_plotAverageExecutionTime`

### File Generation
- To use File Generation: Uncomment following lines in the make file: <br />
>
	 Line 15: Oruganti_V.N.Anirudh_InputFileGenerator: bin/Oruganti_V.N.Anirudh_InputFileGenerator.o
	 Line 16: 	$(link) $@  $^ 
	 Line 17: bin/Oruganti_V.N.Anirudh_InputFileGenerator.o: src/Oruganti_V.N.Anirudh_InputFileGenerator.cpp  bin/Oruganti_V.N.Anirudh_NumberGenrator.o bin/Oruganti_V.N.Anirudh_QuickSort.o 
	 Line 18: 	$(compile) $< -o $@
- After making the changes, run `make Oruganti_V.N.Anirudh_InputFileGenerator` <br />
- To execute the application run, `./Oruganti_V.N.Anirudh_InputFileGenerator input_0 input_1 input_(n-1)`: Where "input_(n-1)" is an integer of number generated values and you need have at least one input and more if you want. <br />
- Example: <br /> 
	`$ make Oruganti_V.N.Anirudh_InputFileGenerator` <br />
	`$ ./Oruganti_V.N.Anirudh_InputFileGenerator 10 100 1000 10000 100000` <br />

### Cleaning Binarys 

- To clear the binary such as ".o" files and the excutable files the program creats run: `$ make cleanBinaries`.
- To clear all the files the program creats including files in both input and output directorys run: `$ make cleanAll`.


