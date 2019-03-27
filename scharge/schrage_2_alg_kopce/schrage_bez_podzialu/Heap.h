#ifndef HEAP_H
#define HEAP_H


/*!
 * \file
 * \brief Definicja klasy Heap
 *
 * Plik zawiera definicje klasy metod tworzenia i dostępu do kopca
 * 
 *
 */

#include <iostream>

#include "rpq.h"

using namespace std;


struct Node {

  int waga;             //klucz dla danego wierzchołka
  int wierzcholek;
  
  proces pr;
};



/*!
 * \brief Modeluje pojęcie kopca
 *
 *
 * Klasa modeluje pojęcie kolejki priorytetowej z budowanej na kopcu
 * 
 */
class Heap {

private:

  //ilość elementów w kopcu
  int lenght;
  
  //czy rosnacy
  bool isIncreased;

  //wskaźnik na tablicę kopca zawierajaca wierzcholki
  Node *tab;


public:
  //konstruktor obiektu klasy kopiec
  Heap(const int &isInc);

  //destruktor obiektu klasy kopiec
  ~Heap();


 //zbuduj kopiec
  void BuildHeap(const int &wym);

  //zwrać indeks ojca dla danego elementu
  int IndFather (const int &elem);

  //zwróć indeks lewego syna 
  int IndLeftSon (const int &elem);

  //zwróć indeks prawego syna 
  int IndRightSon (const int &elem);


  //przywróć właściwości kopca
  void RestoreHeap (int indeks);


  //umieść wierzchołek o odpowiedniej wade w kopcu
  //zwraca lokalizację 
  int insert(const int &odleg, const int &wierzch,  const proces &proc );
  
  //usuń z kopca element o najmniejszej wadze
  int removeElem(proces &proc);
  
  
  //zamienia klucz dla danego elementu
  void replaceKey (const int &elem, const int &odl);

  //wyswietla zawartosc kopca
  void Wyswietl();

  //sprawdza czy kopiec jest pusty
  bool isEmpty();

  //zwraca ilość elementów na kopcu
  int Size ();
    
  //pierwszy element
  proces first();
};









#endif
