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

    unsigned int size=0;
    stringstream(argv[1]) >>size;
    vector<int> randomVector;
    vector<int> numbers;
    vector<int> Copia;
    double t=0;
    double sommas=0;
    int media=0;

    for (int i = 1; i < argc; ++i) {
        int number = stoi(argv[i]);
        numbers.push_back(number);
    }

    for ( int i=0; i<numbers.size(); i++){

        size=numbers[i];
        randomVector.resize(size);

        unsigned int n=5;

        for(unsigned int j=0; j<n; j++)
        {
            randomVector.resize(size);
// assegnazione valori vettore
            for(unsigned int i=0; i<size; i++)
            {
                randomVector[i]=rand()%100;
                //cout  <<  randomVector[i] <<" ";
            }
            Copia=randomVector;
// time bubble
            auto startTime = chrono::steady_clock::now();
            SortLibrary::BubbleSort(randomVector);
            auto endTime = chrono::steady_clock::now();
            chrono::duration<double> bubbleSortTime = endTime - startTime;
            t+= bubbleSortTime.count();
 // time merge
            startTime = chrono::steady_clock::now();
            SortLibrary::MergeSort(Copia);
            endTime = chrono::steady_clock::now();
            chrono::duration<double> mergeSortTime = endTime - startTime;
            sommas+=mergeSortTime.count();

            // stampa vettore ordinato
            cout <<"il vettore ordinato con Bubblesort : [" ;
            for(unsigned int i=0; i<size-1; i++)
            {
                cout << randomVector[i] << "; " ;
            }
            cout <<randomVector[size-1] <<  "] ";
            cout << "il vettore ordinato con MergeSort: [";
            for(unsigned int i=0; i<size-1; i++)
            {
                cout << Copia[i] << "; ";
            }
            cout << Copia[size-1] << "]" << endl;

        }
        t=t/n;
        sommas=sommas/n;

        cout << "media algoritmo Bubblesort: " << t << " seconds" << endl;

        cout<< "media algoritmo MergeSort: " << sommas << " seconds" << endl;
        cout << endl;
        if (t<=sommas)
        {
            media+=1;
        }

    }

    if (media < numbers.size()/2)
        cout << " in media l'algoritmo MergeSort è più veloce"<< endl;
    else
        cout <<  "in media l'algoritmo BubbleSort è più veloce"<< endl;


    return 0;
}

