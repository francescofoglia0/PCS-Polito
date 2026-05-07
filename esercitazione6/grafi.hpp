#pragma once
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <iostream>

template<typename T>
class unidirected_edge
{
    private:
        T primo;
        T secondo;
    public:
        unidirected_edge() = default;
        unidirected_edge(const T& a, const T& b)
        {
            if(a>b)
            {
                primo = b; secondo = a;
            }
            else
            {
                primo = a; secondo= b;
            }
        }

        T from() const {return primo;}
        T to() const {return secondo;}

        bool operator<(const unidirected_edge<T>& other) const
        {
            // sintassi con this e other, i.e se a<b: a lo ho gia ed è (primo,secondo), other sarebbe b
            // se i primi nodi sono diversi allora sara maggiore quello col primo nodo piu grande
            if(primo != other.primo)
            {
                return primo<other.primo;
            }
            // se i primi nodi sono uguali confronto il secondo to
            return secondo<other.secondo;
        }   
        bool operator==(const unidirected_edge<T>& other) const
        {
            // sintassi this e other
            if(primo == other.primo)
            {
                if(secondo == other.secondo) return true;
                else return false;
                
            }
            else return false;
        }   


};

// se mettessimo dentro la classe unidirected_edge prenderebbe come elemento di sinistra un tipo arco
template<typename T>
std::ostream&
operator<<(std::ostream& os, const unidirected_edge<T>& a)
{
    os << "(" << a.from() << "," << a.to() << ")";
    return os;
}


using namespace std;
template<typename T>
class unidirected_graph
{
    private:
        set<unidirected_edge<T>> archi; //per alledges(), set(archi)
        set<T> nodi;    //per allnodes(), set(nodi)
        map<T,set<T>> nadiacenti; //per neighours(), chiave è nodo
        map<unidirected_edge<T>,int>  ednum;//per edge_number(), uso map perche vengono ordinati con < (creata su)
        unordered_map<int,unidirected_edge<T>> edat; //per edgeat(), per la ricerca ha O(1)
        int contatore = 0;
    public:
        unidirected_graph()=default;
        unidirected_graph(const unidirected_graph& other)
        {
            archi = other.archi;
            nodi = other.nodi;
            nadiacenti = other.nadiacenti;
            ednum = other.ednum;
            edat = other.edat;
            contatore = other.contatore;
        }

        set<T> neighours(const T& nodo) const
        {
            auto it = nadiacenti.find(nodo);
            //controllo se l'iteratore è diverso da end, in quel caso la chiave esiste
            if(it != nadiacenti.end())
                return it->second; //restituisco il valore trovato dall'iteratore
            else return set<T>();
        }
                     //passo sempre per riferimento ma come const cosi non posso modificare involontariamente
        void add_edge(const unidirected_edge<T>& newarc)
        {
            // insert su un set restituisce una coppia: iteratore e vero se l'ho inserito, 
            // falso se c'era già o altrimenti, per cui se l'ho inserito aggiungo il resto
            auto prova = archi.insert(newarc);
            if(prova.second)
            {
                nodi.insert(newarc.from());
                nodi.insert(newarc.to());
                nadiacenti[newarc.from()].insert(newarc.to());
                nadiacenti[newarc.to()].insert(newarc.from());
                ednum[newarc] = contatore;
                edat.insert({contatore,newarc});
                contatore++;
            }
        }

        set<unidirected_edge<T>> all_edges() const {return archi;}
        set<T> all_nodes() const {return nodi;}

        int edge_number(const unidirected_edge<T>& arco) const
        {//controllo se l'arco è presente nella mappa (grafo) e nel caso ritorno la sua
         // numerazione, altrimenti -1
            if(ednum.find(arco) != ednum.end()) return ednum.at(arco);
            else return -1;
        }
        unidirected_edge<T> edge_at(int num) const
        {//se non trova num lancia in automatico errore
            return edat.at(num);
        }

        unidirected_graph<T> operator-(const unidirected_graph<T>& other) const
        {
            unidirected_graph<T> risultato;
            int n = archi.size();
            for(int i=0; i<n; i++)
            {//controllo se il set archi di other non contiene l'arco di this, in quel caso aggiungo
             // quell'arco in risultato
                unidirected_edge<T> corrente = edat.at(i);
                if(other.archi.find(corrente) == other.archi.end())
                {
                   risultato.add_edge(corrente);
                }
            }
            return risultato;
        }

};


//creo un altro overload di << per stampare un grafo, ovvero i suoi archi uno dopo l'altro
template<typename T>
std::ostream&
operator<<(std::ostream& os, const unidirected_graph<T>& g)
{
    int n = g.all_edges().size();
    os<<"{";
    for(int i = 0; i<n;i++)
    {
        os << g.edge_at(i);
        if(i!=n-1) os << ", "; //evito di stampare la virgola dopo l'ultimo arco
    }
    os << "}\n";
    return os;
}


