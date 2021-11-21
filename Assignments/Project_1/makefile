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

Oruganti_V.N.Anirudh_EmpiricalAnalysis: bin/EmpiricalAnalysis.o
	$(link) $@  $^

Oruganti_V.N.Anirudh_QuickSort: bin/QuickSortMain.o
	$(link) $@  $^

bin/EmpiricalAnalysis.o: src/EmpiricalAnalysis.cpp  bin/NumberGenrator.o bin/QuickSort.o bin/FileReadWrite.o
	$(compile) $< -o $@

bin/QuickSortMain.o: src/QuickSortMain.cpp bin/FileReadWrite.o bin/QuickSort.o
	$(compile) $< -o $@

bin/QuickSort.o: src/QuickSort.cpp inc/QuickSort.h 
	$(compile) $< -o $@

bin/FileReadWrite.o: src/FileReadWrite.cpp inc/FileReadWrite.h 
	$(compile) $< -o $@

bin/NumberGenrator.o: src/NumberGenrator.cpp inc/NumberGenrator.h 
	$(compile) $< -o $@

clean:
	rm -f bin/* Oruganti_V.N.Anirudh_QuickSort
