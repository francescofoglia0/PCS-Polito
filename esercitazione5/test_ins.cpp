#include <iostream>
#include <vector>
#include "randfiller.h"
#include <string>
#include "print_vec.hpp"
#include "ordinamento.hpp"
#include "timecounter.h"

using namespace std;


int main(void)
{
    // int size = 7;
    // vector<char> vec{5,4,2,3,9,7,1};
    randfiller rf;
    vector<int> dim;
    dim.resize(100);
    rf.fill(dim, 1, 8000);
    for(size_t i = 0; i<dim.size();i++)
    {
        vector<int>vec;
        vec.resize(dim[i]);
        rf.fill(vec,-10000,10000);
        // print_vector(vec);
        // is_sorted(vec);
        // timecounter tc;
        // tc.tic();
        insertionsort(vec);
        // double secs = tc.toc();
        // print_vector(vec);
        // std::cout << "Ci ha messo "<< secs << " secondi\n";
        bool flag = is_sorted(vec);
        if(!flag)
        {   
            cout<< "Errore\n";
            return EXIT_FAILURE;
        }
    }
    vector<string> stringhe = {"mela", "zucchina", "banana", "kiwi", "albicocca", 
        "pera", "ciliegia", "pesca", "fragola", "limone", "ciao"};
    bubblesort(stringhe);
    bool flag = is_sorted(stringhe);
    if(!flag){
        cout << "Errore\n";
        return EXIT_FAILURE;
    }

    cout<<"Tutto giusto\n";
    return EXIT_SUCCESS;

}
