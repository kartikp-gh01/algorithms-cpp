all:
	g++ src/MergeSort.cpp -o MergeSort.exe
	g++ src/BinarySearch.cpp -o BinarySearch.exe
	g++ src/Knapsack.cpp -o Knapsack.exe

clean:
	del *.exe