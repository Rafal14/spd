#include "schrage.h"




// N -> vector zadan nieuszeregowanych
// G -> vector zadan gotowych do realizacji
int Schrage(vector<proces> &N, vector<proces> &G)
{
    proces e; // aktualny proces
    // inicjalizacja zmiennym pomocniczych
    int t = 0, Cmax = 0;

	int licz = 0;
	
	int sizeN = N.size();

    proces currProc, l;

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
					Gqueue.push(l);
				}
			}
        	
        }
        if(Gqueue.empty())
        {
            t = Nqueue.top().r;
            continue;
        }
        e = Gqueue.top();
        Gqueue.pop();
    
    	l = e;
        t += e.p;
        Cmax = std::max(Cmax, t+e.q);
    }
    return Cmax;
}
