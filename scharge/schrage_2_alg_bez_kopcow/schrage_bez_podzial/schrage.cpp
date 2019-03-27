#include "schrage.h"




// N -> vector zadan nieuszeregowanych
// G -> vector zadan gotowych do realizacji
int Schrage(vector<proces> &N, vector<proces> &G)
{
    proces e; // aktualny proces
    // inicjalizacja zmiennym pomocniczych
    int t = 0, Cmax = 0;

    // stworzenie kolejki priorytetowej z vectora N (priorytet - najmniejsze r)
    std::priority_queue<proces, std::vector<proces>, CompareN> Nqueue;
    for(int i = 0; i < static_cast<int>(N.size()); i++)
    {
        Nqueue.push(N.at(i));
    }

    // kolejka priorytetowa wektora G (piorytet - najwieksze q)
    std::priority_queue<proces, std::vector<proces>, CompareG> Gqueue;

    while(!Gqueue.empty() || !Nqueue.empty())
    {
        while(!Nqueue.empty() && Nqueue.top().r <= t)
        {
            e = Nqueue.top();
            Nqueue.pop();
            Gqueue.push(e);
        }
        if(Gqueue.empty())
        {
            t = Nqueue.top().r;
            continue;
        }
        e = Gqueue.top();
        Gqueue.pop();
        G.push_back(e);
        t += e.p;
        Cmax = std::max(Cmax, t+e.q);
    }
    return Cmax;
}
