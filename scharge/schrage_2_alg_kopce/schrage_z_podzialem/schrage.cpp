#include "schrage.h"

// schrage z przedzialem

// N -> vector zadan nieuszeregowanych
// G -> vector zadan gotowych do realizacji
int Schrage(std::vector<proces> N, std::vector<proces> G)
{
    proces e; // aktualny proces
    // inicjalizacja zmiennym pomocniczych
    int t = 0, Cmax = 0;
	int licz = 0;

    int sizeN = N.size();

    proces currProc, l;
    
    //kopia vectora N
    vector<proces> kopiaN = N;
	


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

    while(!Gqueue.isEmpty() || !Nqueue.isEmpty())
    {

        while(!Nqueue.isEmpty() && (Nqueue.first()).r <= t)
        {
            Nqueue.removeElem(e);
            Gqueue.insert(e.q, e.j, e);
            
        	
        	if ( licz == 0)
        	{
        		l.r = 0;
        		l.q =  99999999;
			}
			++licz;
        	
            if ( e.q > l.q) {
            	l.p = t - e.r;
            	t   = e.r;

				if (l.p > 0) {
					Gqueue.insert(l.q, l.j, l);
				}
			}
        }
        
        if(Gqueue.isEmpty())
        {
            t = (Nqueue.first()).r;
            continue;
        }
        Gqueue.removeElem(e);
    
        l=e;
        t += e.p;
        Cmax = std::max(Cmax, t+e.q);
    }
    return Cmax;
}
