#include <iostream>
#include <cmath>

int main()
{
    static const int N = 5;
    double a[N] = {1.1,2.2,3.3,4.4,5.5};
    double minimo = a[0],massimo = a[0],media= a[0],deviazione= 0.0;
    // for(int i = 0;i<N;i++)
    // {
    //     std::cout<< a[i]<< " "<< &a[i]<< "\n";
    // }
    for(int i = 1;i<N;i++)
    {
    minimo = std::min(a[i],minimo);
    massimo = std::max(a[i],massimo);
    media += a[i];
    }
    media = media/N;

    for (int i = 0; i < N; i++)
    {
        deviazione += (a[i]-media)*(a[i]-media);
    }
    deviazione = std::sqrt(deviazione/N);
    
    std::cout<<"Minimo: "<< minimo << "\nMassimo: "<<massimo<< "\nMedia: " <<media<< "\nDeviazione Standard: "<< deviazione <<"\n";
    
    // implemento bubblesort
    double primo = a[0];
    int flag = 0;
    while(!flag)
    {
        flag = 1;
        for(int i=0; i<N-1;i++)
        {
            if(a[i]>a[i+1])
            {
                primo = a[i+1];
                a[i+1] = a[i];
                a[i] = primo;
                flag = 0;
            }
        }
    }

    for(int i =0;i<N;i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";

    return 0;
}