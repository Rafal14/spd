#include "schrage.h"



// N -> vector zadan nieuszeregowanych
// G -> vector zadan gotowych do realizacji
int Schrage(std::vector<proces> &N, std::vector<proces> &G)
{
    proces e; // aktualny proces
    // inicjalizacja zmiennym pomocniczych
    int t = 0, Cmax = 0;

    int sizeN = N.size();

    proces currProc;

    // stworzenie kolejki priorytetowej z vectora N (priorytet - najmniejsze r)
    Heap Nqueue(0);

    // kolejka priorytetowa wektora G (piorytet - najwieksze q)
    Heap Gqueue(1);

    Nqueue.BuildHeap(sizeN+1);
    Gqueue.BuildHeap(sizeN+1);

    for(int i = 0; i < static_cast<int>(N.size()); i++)
    {
        currProc = N.at(i);
        Nqueue.insert(currProc.r, currProc.j, currProc);
    }

  //  cout << endl << "dsadasd++" << endl;
 //   Nqueue.Wyswietl();
 //   cout << endl << endl;

    while(!Gqueue.isEmpty() || !Nqueue.isEmpty())
    {

        while(!Nqueue.isEmpty() && (Nqueue.first()).r <= t)
        {
            Nqueue.removeElem(e);
            Gqueue.insert(e.q, e.j, e);
        }
        //cout << endl << "dsadasd++" << endl;
        //Gqueue.Wyswietl();
        //cout << endl << endl;
        if(Gqueue.isEmpty())
        {
            t = (Nqueue.first()).r;
            continue;
        }
        Gqueue.removeElem(e);
        G.push_back(e);
        t += e.p;
        Cmax = std::max(Cmax, t+e.q);
    }
    return Cmax;
}
