#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <windows.h>


using namespace std;


unsigned int max(int x, int y) { return (x>y)?x:y; }


int main()
{
    //string nazwaPiku = "data.txt";
    ifstream inStr;
    int dlugosc;
    int komb;


    /* pomiar czas u */
    long int t;

    LARGE_INTEGER clockFreq;
    QueryPerformanceFrequency(&clockFreq);

    LARGE_INTEGER TimeStart;
    LARGE_INTEGER TimeEnd;
    LARGE_INTEGER diff;          //różnica czasu




    inStr.open("data20.txt");
    inStr >> dlugosc;

    int *P = new int[dlugosc];  //tablica zawierająca czasy wykonania poszczególnych zadań
    int *W = new int[dlugosc];  //tablica zawierająca wagi kar dla poszczególnych zadań
    int *D = new int[dlugosc];  //tablica zawierająca zamierzone czasy wykonania dla zadań

    //wczytaj wartości P,W,D z pliku
    for (int i=0; i < dlugosc; ++i) {
        inStr >> P[i] >> W[i] >> D[i];
    }

    inStr.close();

    for ( int v=0 ; v < dlugosc; ++v )
    {
        cout << P[v] << "\t" << W[v] << "\t" << D[v]  << endl;
    }

    //oblicz liczbe mozliwych kombinacji    2^dlugosc
    komb = 1 << dlugosc;

    int *G = new int[komb];

    //spoznienie
    int spoz;
    int zadania;

    int Cmax;
    int minSpoz;
    int kara;

    G[0] = 0;


    //czas pocz
    QueryPerformanceCounter(&TimeStart);


    //liczba wszytkich kombinacji
    for (int j=1; j < komb; ++j ) {
        //zadania = (int) (log(j)/log(2));               //liczba zadan w danej kombinacji
        // s=0;  for (c=k=1;c<=e;c<<=1,k++) if (e&c) s+=p[k];

        Cmax = 0;
        //obliczenie Cmax
        for (int k=0, bin=1; bin <= j;  bin<<=1 ,k++) {
            if (j&bin)
                Cmax += P[k];                //oblicz sume dlugosci wynonywania zadan dla danej kombinacji
        }

        minSpoz=99999;
        for (int k=0, bin=1; bin <= j;  bin<<=1 ,k++) {
            if (j&bin) {
                kara = G[j-bin] +   ( W[k] * max(0,Cmax-D[k]) );
                if ( kara < minSpoz )
                    minSpoz = kara;
            }
        }
        G[j]=minSpoz;

    }
    // pomiar czasu zakonczenia
    QueryPerformanceCounter(&TimeEnd);

    diff.QuadPart = TimeEnd.QuadPart - TimeStart.QuadPart;

    // zmierzony czas
    float diffTime = ( (float)diff.QuadPart ) / clockFreq.QuadPart;

    cout << endl << endl;
    cout << "witi: "  << G[komb-1] << endl;
    cout << "Czas: "  << diffTime << "s" << endl;


    system("pause");


    delete []P;
    delete []W;
    delete []D;
    delete []G;

}
