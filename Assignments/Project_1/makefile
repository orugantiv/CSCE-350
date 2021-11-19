cpp = g++  # use g++ compiler
path = ..
standard = c++11

flags = -std=$(standard)  # compile with standard
flags += -Wall  # compile with all warnings
flags += -pedantic  # even more warnings
flags += -I $(path)  # add parent to preprocessor include path
flags += -g  # include gdb instrumentation

link = $(cpp) $(flags) -o  # final linked build to binary executable

compile = $(cpp) $(flags) -c  # compilation to intermediary .o files


test-style : src/* inc/*
	cpplint --root=. $^



Oruganti_V.N.Anirudh_QuickSort: bin/QuickSort.o
	$(link) $@  $^

bin/QuickSort.o : src/QuickSortMain.cpp src/QuickSort.cpp inc/QuickSort.h bin/FileReadWrite.o
	$(compile) $< -o $@

bin/FileReadWrite.o: src/FileReadWrite.cpp inc/FileReadWrite.h 
	$(compile) $< -o $@



clean:
	rm -f bin/* Oruganti_V.N.Anirudh_QuickSort
