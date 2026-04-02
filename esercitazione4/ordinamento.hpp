#pragma once
#include <vector>
#include <string>
#include <iostream>


template<typename T>
void bubblesort(std::vector<T>& v)
{
    if(v.size()<2){return;}

    for(size_t i=0; i<v.size()-1;i++)
    {
        for(size_t j = v.size()-1; j>i;j--)
        {
            if(v[j]<v[j-1])
            {
                T a = v[j];
                v[j] = v[j-1];
                v[j-1] = a;
            }
        }
    }
}

template<typename T>
void insertionsort(std::vector<T>& v)
{
    if(v.size()<2){return;}
    for(size_t j=1; j<v.size();j++)
    {
        T key = v[j];
        size_t i = j;
        while(i>0 && v[i-1]>key)
        {
            v[i] = v[i-1];
            i--;
        }
        v[i] = key;
    }
}

template<typename T>
void selectionsort(std::vector<T>& v)
{
    if(v.size()<2){return;}
    for(size_t i = 0; i<v.size()-1;i++)
    {
        size_t min = i;
        for(size_t j = i+1; j<v.size(); j++)
        {
            if(v[j]<v[min])
            {
                min = j;
            }
        }
        if(min!=i)
        {
        T a = v[i];
        v[i] = v[min];
        v[min] = a;
    }
    }
}


template<typename T>

bool is_sorted(const std::vector<T>& v)
{
    if (v.size() < 2) return true;

    for (size_t i = 0; i < v.size() - 1; i++) 
    {
        if (v[i] > v[i + 1]) 
        {   
            // std::cout << "Il vettore NON è ordinato\n";
            return false;
        }
    }
    // std::cout << "Il vettore è ordinato\n";
    return true;
}



using namespace std;
//funzione per disegnare due curve sullo stesso grafico
void print_ascii_graph(vector<int>& dim, vector<double>& tempobub, vector<double>& tempostd) 
{
    int altezza = 20;   
    int larghezza = 60; 

    //trovo il tempo massimo per bubble sort
    double maxtempo = 0;
    for(size_t i = 0; i < tempobub.size(); i++) 
    {
        if(tempobub[i] > maxtempo) 
        {
            maxtempo = tempobub[i];
        }
    }
    
    //l'ultimo elemento della dimensione è il più grande
    int maxdim = dim[dim.size() - 1]; 

    if(maxtempo == 0) 
    {
        maxtempo = 0.0001;
    }

    //creo il grafico vuoto
    vector<string> grafico(altezza, string(larghezza, ' '));

    for(size_t i = 0; i < dim.size(); i++) 
    {
        //posizione x per la dimensione
        int x = (dim[i] * (larghezza - 1)) / maxdim;
        if(x >= larghezza) 
        {
            x = larghezza - 1;
        }

        //posizione y per bubble sort
        int ybub = (tempobub[i] * (altezza - 1)) / maxtempo;
        if(ybub >= altezza) 
        {
            ybub = altezza - 1;
        }
        
        //posizione y per std::sort
        int ystd = (tempostd[i] * (altezza - 1)) / maxtempo;
        if(ystd >= altezza) 
        {
            ystd = altezza - 1;
        }

        //inverto l'asse y
        int rigabub = (altezza - 1) - ybub;
        int rigastd = (altezza - 1) - ystd;

        //disegno sul grafico
        grafico[rigabub][x] = 'B'; 
        
        //se si sovrappongono metto X
        if(grafico[rigastd][x] == 'B') 
        {
            grafico[rigastd][x] = 'X'; 
        } 
        else 
        {
            grafico[rigastd][x] = 'S'; 
        }
    }

    //stampo tutto
    cout << "\n=== CONFRONTO O(n^2) vs O(n log n) ===\n";
    cout << "Asse Y: Tempo (Max " << maxtempo << " s) | Asse X: Dimensione n (Max " << maxdim << ")\n";
    cout << "Legenda: [B] = Bubble Sort | [S] = std::sort | [X] = Entrambi\n\n";
    
    cout << "  ^\n";
    for(int r = 0; r < altezza; r++) 
    {
        cout << "  | " << grafico[r] << "\n";
    }
    
    cout << "  +";
    for(int c = 0; c < larghezza; c++) 
    {
        cout << "-";
    }
    cout << ">\n\n";
}

