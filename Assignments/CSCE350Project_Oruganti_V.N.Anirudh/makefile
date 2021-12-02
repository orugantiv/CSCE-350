cpp = g++  # use g++ compiler
path = ..
standard = c++17
flags = -std=$(standard)  # compile with standard
flags += -Wall  # compile with all warnings
flags += -pedantic  # even more warnings
flags += -I $(path)  # add parent to preprocessor include path
flags += -g  # include gdb instrumentation

link = $(cpp) $(flags) -o  # final linked build to binary executable

compile = $(cpp) $(flags) -c  # compilation to intermediary .o files


Oruganti_V.N.Anirudh_InputFileGenerator: bin/Oruganti_V.N.Anirudh_InputFileGenerator.o
	$(link) $@  $^


bin/Oruganti_V.N.Anirudh_InputFileGenerator.o: src/Oruganti_V.N.Anirudh_InputFileGenerator.cpp  bin/Oruganti_V.N.Anirudh_NumberGenrator.o bin/Oruganti_V.N.Anirudh_QuickSort.o
	$(compile) $< -o $@

Oruganti_V.N.Anirudh_QuickSort: bin/Oruganti_V.N.Anirudh_QuickSortMain.o
	$(link) $@  $^

bin/Oruganti_V.N.Anirudh_QuickSortMain.o: src/Oruganti_V.N.Anirudh_QuickSortMain.cpp  bin/Oruganti_V.N.Anirudh_QuickSort.o
	$(compile) $< -o $@

bin/Oruganti_V.N.Anirudh_QuickSort.o: src/Oruganti_V.N.Anirudh_QuickSort.cpp inc/Oruganti_V.N.Anirudh_QuickSort.h bin/Oruganti_V.N.Anirudh_FileReadWrite.o
	$(compile) $< -o $@

bin/Oruganti_V.N.Anirudh_FileReadWrite.o: src/Oruganti_V.N.Anirudh_FileReadWrite.cpp inc/Oruganti_V.N.Anirudh_FileReadWrite.h 
	$(compile) $< -o $@

bin/Oruganti_V.N.Anirudh_NumberGenrator.o: src/Oruganti_V.N.Anirudh_NumberGenrator.cpp inc/Oruganti_V.N.Anirudh_NumberGenrator.h 
	$(compile) $< -o $@

Oruganti_V.N.Anirudh_plotAverageExecutionTime: src/Oruganti_V.N.Anirudh_PlotAvgExecutionTime.py
	python3	 $^

cleanBinaries:
	rm -f bin/* Oruganti_V.N.Anirudh_QuickSort Oruganti_V.N.Anirudh_EmpiricalAnalysis

cleanAll:
	rm -f bin/* Oruganti_*
