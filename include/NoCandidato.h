#ifndef NOCANDIDATO_H
#define NOCANDIDATO_H
#include <cstring>
#include <sstream>
#include "Candidato.h"

using namespace std;

class NoCandidato
{

    public:

        Candidato *conteudo;
        NoCandidato *next;

        //Construtor da classe NoCandidato
        NoCandidato(Candidato *c,NoCandidato *y ){
             conteudo = c;
             next = y;
        }

        string toString(){  //Aqui voce transforma o Nocandidato e o proximo Nocandidato para uma string

            //Transformando NOCANDIDATO em uma string
            stringstream stream;
            NoCandidato *aux = this;

            while(aux != NULL){
                stream << aux->conteudo->sobrenome << " " << aux->conteudo->nome << " " << aux->conteudo->nota << " -> ";
                aux = aux->next;
            }
            stream << " 0";
            return stream.str();

        }

};

#endif // NOCANDIDATO_H
