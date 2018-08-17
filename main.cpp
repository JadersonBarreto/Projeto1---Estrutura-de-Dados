#include <iostream>
#include"ListaCandidatos.h"

using namespace std;

int main(){

  ListaCandidatos* lista = new ListaCandidatos("candidatos/candidatsBourgogne.txt");
  cout << "lista de " << lista->tamanho() << " candidatos: " << lista->toString() << endl << endl;

  ListaCandidatos* lista1 = new ListaCandidatos("candidatos/candidatsPicardie.txt");
  cout << "lista de " << lista1->tamanho() << " candidatos: " << lista1->toString() << endl << endl;

  cout << "concatenacao" << endl;

  lista->concatena(lista1);

  cout << "lista de " << lista->tamanho() << " candidatos: " << lista->toString() << endl << endl;

}
