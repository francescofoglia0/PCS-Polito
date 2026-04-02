#include "timecounter.h"
#include <iostream>
#include <vector>
#include "print_vec.hpp"
#include "ordinamento.hpp"
#include "randfiller.h"
#include <algorithm>

using namespace std;

int main(void)
{
    randfiller rf;
    vector<int> vec;
    vector<double> tempobub(12);
    vector<double> tempostd(12);
    vector<int> dim(12);
    vector<bool> confr(12);
    int j = 0;
    for(int i = 4; i <=8192; i*=2)
    {
        vec.resize(i);
        rf.fill(vec,-10000,10000);
        vector<int> vbub = vec;
        vector<int> vins = vec;
        vector<int> vsel = vec;
        vector<int> vstd = vec;
        
        timecounter tc;
        //tempo per bubble
        tc.tic();
        bubblesort(vbub);
        double secbub = tc.toc();
        std::cout <<"Vettore di dimensione: "<<i<< "\nBubblesort ci ha messo "<< secbub << " secondi\n";
        //tempo per insertion
        tc.tic();
        insertionsort(vins);
        double secins = tc.toc();
        std::cout << "Insertionsort ci ha messo "<< secins << " secondi\n";
        //tempo per selection
        tc.tic();
        selectionsort(vsel);
        double secsel = tc.toc();
        std::cout << "Selectionsort ci ha messo "<< secsel << " secondi\n";
        //tempo per stdsort
        tc.tic();
        sort(vstd.begin(),vstd.end());
        double secstd = tc.toc();
        std::cout << "Sort della libreria standard ci ha messo "<< secstd << " secondi\n\n";

        tempobub[j] = secbub;
        tempostd[j] = secstd;
        dim[j] = i;
        if(secins>secstd)
        {
            confr[j] = false;
        }
        else
        {
            confr[j] = true;
        }
        j++;

    }
    cout << "Confronto un algoritmo tra qualsiasi tra i tre (bubblesort in questo caso) con l'algoritmo std::sort, metto 1 dove l'algoritmo (bubblesort) è piu veloce di std::sort\n";
    print_vector(confr);
    cout <<"^ ^ ^....\n4 8 16... (dimensione del vettore confrontato)\n";
    print_ascii_graph(dim,tempobub,tempostd);
    return 0;
}


