#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <type_traits>


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


// implemento mergesort e quicksort
template<typename T>
void merge(std::vector<T>& v,size_t p,size_t q,size_t r)
{
    size_t n1 = q-p+1;
    size_t n2 = r-q;
    std::vector<T> L(n1+1);
    std::vector<T> R(n2+1);
    for(size_t i = 0;i<n1;i++)
    {
        L[i] = v[p+i];
    }
    for(size_t j =0;j<n2;j++)
    {
        R[j] = v[q+j+1];
    }
    if constexpr(std::is_arithmetic_v<T>)
    {    
        L[n1] = std::numeric_limits<T>::max(); //numero piu grande per interi di ogni segno
        R[n2] =  std::numeric_limits<T>::max();
    }
    else 
    {
        L[n1] = std::string(1000,'\xff');
        R[n2] = std::string(1000,'\xff');
    }
    size_t i = 0;
    size_t j = 0;
    for(size_t k =p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
    }
}

template<typename T>
void mergesort_fake(std::vector<T>& v,size_t p,size_t r)
{
    if(p<r)
    {
        size_t q = (p+r)/2;
        mergesort_fake(v,p,q);
        mergesort_fake(v,q+1,r);
        merge(v,p,q,r);
    }
}

template<typename T>
void mergesort(std::vector<T>& v)
{
    if(v.size()>1)
    {
        mergesort_fake(v,0,v.size()-1);
    }
}

template<typename T>
size_t partizione(std::vector<T>& v, size_t p, size_t r)
{
    T x = v[r];
    size_t i = p;
    for(size_t j = p;j<r;j++)
    {
        if(v[j]<=x)
        {
            
            T temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            
        }
    }
    T temp = v[i];
    v[i] = v[r];
    v[r] = temp;
    return i;
}


template<typename T>
void quicksort_fake(std::vector<T>& v,size_t p,size_t r)
{
    if(p<r)
    {
        size_t q = partizione(v,p,r);
        if(q>p){quicksort_fake(v,p,q-1);}
        quicksort_fake(v,q+1,r);
    }    
}

template<typename T>
void quicksort(std::vector<T>& v)
{
    if(v.size()>1)
    {
        quicksort_fake(v,0,v.size()-1);
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


//QUICKSORT OTTIMIZZATO
template<typename T>
void quicksort_optimus_fake(std::vector<T>& v, size_t p, size_t r) {
    size_t n = r - p + 1;

    // Se la dimensione del vettore è minore di 33 esci e andra automaticamente
    //all'insertionsort
    if (n < 35) {
        return; 
    } 
    //altrmenti procediamo con il quicksort e quindi passo alla funzione partizione come
    //nel quicksort gia implementato
    if (p < r) {
        size_t q = partizione(v, p, r);
        if (q > p) { 
            quicksort_optimus_fake(v, p, q - 1); 
        }
        quicksort_optimus_fake(v, q + 1, r);
    }
}

template<typename T>
void quicksort_optimus(std::vector<T>& v) {
    if (v.size() < 2) return;

    //Chiamo il quicksort che si ferma a n < 33.
    quicksort_optimus_fake(v, 0, v.size() - 1);

    //Chiamo insertionsort una sola volta
    insertionsort(v); 
}

