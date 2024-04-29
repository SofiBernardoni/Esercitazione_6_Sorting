#include <chrono>
#include<iostream>
#include <unistd.h>
#include <numeric>
#include <vector>
#include <algorithm>
#include <sstream>
#include "SortingAlgorithm.hpp"

using namespace std;

int main(int argc, char ** argv)
{
    if (argc != 2)
    {
        cerr << "Numeri argomenti passati: " << argv[0] << " <vector_size>" << endl;
        return 1;
    }

    int size = 0;
    stringstream(argv[1]) >> size;
    vector<int> randomVector;
    cout << size;

    randomVector.reserve(size);

    for(unsigned int i=0; i<size; i++)
    {
        randomVector[i]=rand()%1000;
        cout  <<  randomVector[i] << endl;
    }

    vector<int> Copia=randomVector;
    SortLibrary::BubbleSort(randomVector);
/*
    chrono::steady_clock::time_point t_begin =chrono::steady_clock::now();

    SortLibrary::BubbleSort(randomVector);

    chrono::steady_clock::time_point t_end =chrono::steady_clock::now();


    double timeElapsed = chrono::duration_cast<chrono::nanoseconds> (t_end-t_begin).count(); //con count trasformo un oggetto duration in double
    cout << timeElapsed << endl;*/



    // Test e confronto delle prestazioni di BubbleSort e MergeSort
    auto startTime = std::chrono::high_resolution_clock::now();
    SortLibrary::BubbleSort(randomVector);
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> bubbleSortTime = endTime - startTime;
    std::cout << "BubbleSort time: " << bubbleSortTime.count() << " seconds" << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    SortLibrary::MergeSort(randomVector, 0, randomVector.size() - 1);
    endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergeSortTime = endTime - startTime;
    std::cout << "MergeSort time: " << mergeSortTime.count() << " seconds" << std::endl;
    return 0;
}

