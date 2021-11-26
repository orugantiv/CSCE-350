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


test-style : src/* inc/*
	cpplint --root=. $^

Oruganti_V.N.Anirudh_plotAverageExecutionTime: src/Oruganti_V.N.Anirudh_PlotAvgExecutionTime.py
	python3	 $^

Oruganti_V.N.Anirudh_EmpiricalAnalysis: bin/Oruganti_V.N.Anirudh_EmpiricalAnalysis.o
	$(link) $@  $^

Oruganti_V.N.Anirudh_QuickSort: bin/Oruganti_V.N.Anirudh_QuickSortMain.o
	$(link) $@  $^

bin/Oruganti_V.N.Anirudh_EmpiricalAnalysis.o: src/Oruganti_V.N.Anirudh_EmpiricalAnalysis.cpp  bin/Oruganti_V.N.Anirudh_NumberGenrator.o bin/Oruganti_V.N.Anirudh_QuickSort.o bin/Oruganti_V.N.Anirudh_FileReadWrite.o
	$(compile) $< -o $@

bin/Oruganti_V.N.Anirudh_QuickSortMain.o: src/Oruganti_V.N.Anirudh_QuickSortMain.cpp bin/Oruganti_V.N.Anirudh_FileReadWrite.o bin/Oruganti_V.N.Anirudh_QuickSort.o
	$(compile) $< -o $@

bin/Oruganti_V.N.Anirudh_QuickSort.o: src/Oruganti_V.N.Anirudh_QuickSort.cpp inc/Oruganti_V.N.Anirudh_QuickSort.h 
	$(compile) $< -o $@

bin/Oruganti_V.N.Anirudh_FileReadWrite.o: src/Oruganti_V.N.Anirudh_FileReadWrite.cpp inc/Oruganti_V.N.Anirudh_FileReadWrite.h 
	$(compile) $< -o $@

bin/Oruganti_V.N.Anirudh_NumberGenrator.o: src/Oruganti_V.N.Anirudh_NumberGenrator.cpp inc/Oruganti_V.N.Anirudh_NumberGenrator.h 
	$(compile) $< -o $@

clean:
	rm -f bin/* Oruganti_V.N.Anirudh_QuickSort Oruganti_V.N.Anirudh_EmpiricalAnalysis

cleanAll:
	rm -f bin/* Oruganti_*
