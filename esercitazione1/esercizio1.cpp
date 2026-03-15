#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc,const char *argv[])
{
    if (argc < 2)  //verifico che sia stato passato il parametro da terminale
    {
        cerr << "Non hai inserito il nome del file da leggere\n"; 
        return 1;
    }
    string nomefile = argv[1];
    
    ifstream file(nomefile);
    if (file.is_open())
    {
        while(!file.eof())
        {
            string citta;
            double temp0, temp6, temp12, temp18;
            file >> citta >> temp0 >> temp6 >> temp12 >> temp18;
            if (citta == "") // se il file è finito, citta sarà una stringa vuota, quindi usciamo dal ciclo
                break;      // altrimenti, stamperemmo una riga in piu errata    
            double media = (temp0 + temp6 + temp12 +temp18)/4;
            cout << citta << " " << media << "\n";
        }
    }
    else
    {
        cerr << "Impossibile aprire il file " << nomefile << "\n";
        return 1;
    }
    return 0;
}