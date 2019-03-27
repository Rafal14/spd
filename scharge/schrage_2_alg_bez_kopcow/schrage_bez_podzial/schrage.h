#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include "rpq.h"


using namespace std;

class CompareN
{
public:
    bool operator() (proces a, proces b)
    {
        if(a.r > b.r)
            return true;
        return false;
    }
};

class CompareG
{
public:
    bool operator() (proces a, proces b)
    {
        if(a.q < b.q)
            return true;
        return false;
    }
};

// N -> vector zadan nieuszeregowanych
// G -> vector zadan gotowych do realizacji
int Schrage(vector<proces> &N, vector<proces> &G);

