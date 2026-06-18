#include <iostream>
#include "timecounter.h"
#include <vector>
#include "print_vec.hpp"
#include "ordinamento.hpp"
#include "randfiller.h"
#include <algorithm>


using namespace std;
int main(void)
{
    randfiller rf;
    timecounter tc;
    const int N = 100; //numero richiesto per fare la media
    //riempio i vettori 
    cout << left << setw(10) << "Dim"
             << setw(20) << "INSERTION"
             << setw(20) << "SELECTION"
             << setw(20) << "BUBBLE"
             << setw(20) << "QUICKSORT"
             << setw(20) << "MERGESORT"<< endl;
    for(int i=2;i<=N;i++)
    {
        //creo un vettore di vettori che ha 100 vettori di dimensione i
        vector<vector<int>> vettori(N,vector<int>(i));
        for(int j =0;j<N;j++)
        {
            rf.fill(vettori[j],-10000,10000);
        }
        //copie dei vettori
        vector<vector<int>> vec_quick  = vettori;
        vector<vector<int>> vec_ins  = vettori; 
        vector<vector<int>> vec_sor = vettori;  
        vector<vector<int>> vec_bub = vettori; 
        vector<vector<int>> vec_sel = vettori; 
        vector<vector<int>> vec_merg = vettori; 
         
        //test insertionsort
        tc.tic();
        for (int i = 0; i < N; i++) 
        {
            insertionsort(vec_ins[i]);
        }
        double tempo_insert = tc.toc() / N;
        // test quicksort
        tc.tic();
        for (int i = 0; i < N; i++)
        {
            quicksort(vec_quick[i]);
        }
        double tempo_quick = tc.toc() / N;
        tc.tic();
        for (int i = 0; i < N; i++)
        {
            bubblesort(vec_bub[i]);
        }
        double tempo_bub = tc.toc() / N;
        tc.tic();
        for (int i = 0; i < N; i++)
        {
            selectionsort(vec_sel[i]);
        }
        double tempo_sel = tc.toc() / N;
        tc.tic();
        for (int i = 0; i < N; i++)
        {
            mergesort(vec_merg[i]);
        }
        double tempo_merg = tc.toc() / N;
        //formatto il testo per una visualizzazione piu chiara
        cout << left << setw(10) << i 
             << setw(20) << tempo_insert 
             << setw(20) << tempo_sel
             << setw(20) << tempo_bub
             << setw(20) << tempo_quick
             << setw(20) << tempo_merg;
            //  << setw(20) << tempo_sort;
        double minimo = std::min({tempo_bub,tempo_insert,tempo_sel,tempo_quick,tempo_merg});
        // Evidenziamo chi vince per facilitare la lettura
        if(minimo == tempo_bub){cout<<"<- BUBBLE vince"<< endl;}
        else if(minimo == tempo_sel){cout<<"<- SELECTION vince"<< endl;}
        else if(minimo == tempo_insert){cout<<"<- INSERTION vince"<< endl;}
        else if(minimo == tempo_quick){cout<<"<- QUICK vince"<< endl;}
        else {cout<<"<- MERGE vince"<< endl;}
        //noto che il quicksort vince da 33 in poi sempre e che l'insertion sort è il più veloce
        // tra gli algoritmi n^2

        //dopo aver gia implementato tutto controllo anche il quicksort ottimizzato
        vector<vector<int>> vec_opt = vettori;
        tc.tic();
        for (int i = 0; i < N; i++)
        {
            quicksort_optimus(vec_opt[i]);
        }
        double tempo_opt = tc.toc() / N;
        cout << left<< setw(20)<< "Tempo con quicksort ottimizzato: " <<tempo_opt <<"  ";
        //il risultato è ovviamente che il quicksort ottimizzato è il piu veloce
        tc.tic();
        for (int i = 0; i < N; i++)
        {
            sort(vec_sor.begin(),vec_sor.end());
        }
        double tempo_sor = tc.toc() / N;
        cout<<"Tempo sort standard: "<<tempo_sor<<"\n"<<endl;
        
    }



    return 0;
}
