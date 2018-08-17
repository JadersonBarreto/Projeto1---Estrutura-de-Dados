#include <cstring>
#include <sstream>
#include <fstream>
#ifndef LISTACANDIDATOS_H
#define LISTACANDIDATOS_H
#include "NoCandidato.h"
#include "Candidato.h"

using namespace std;
class ListaCandidatos
{
    public:
        NoCandidato *head;

        ListaCandidatos(){
            head = NULL;
        }
        bool estaVazia(){
            return head == NULL; // retorna true se a lista estiver vazia, se nao, retorna false;
        }

        void adicioneComoHead(Candidato* c){
            head = new NoCandidato(c, head);
        }


        int tamanho(){

            if(estaVazia()){
                return 0;
            }

            NoCandidato *aux = head;
            int tam = 0;

            while(aux != NULL){
                aux = aux -> next;
                tam++;
            }

            return tam;
        }

          string toString(){

            if(estaVazia()){
                return "0";
            }else{
                return head->toString();
            }
        }

        ListaCandidatos(string nomeDoArquivo){
           head = NULL;
            ifstream fcin(nomeDoArquivo);
                  string dados;
                  getline(fcin,dados);
                  cout << "criacao da lista de candidatos de: " << dados << endl;

                  while(getline(fcin,dados)){

                    Candidato *c = new Candidato(dados);
                    adicioneComoHead(c);

              }
        }

        bool remover(string nome, string sobrenome){

            NoCandidato *aux = head;
            NoCandidato *ant;

            // Verifica se a lista está vazia, se estiver retorna "false"
            if(estaVazia()){
                return false;
            }

            // Verifica se o nó buscado é a cabeça da lista, se for, remove ele
            if( (head->conteudo->nome == nome) && (head->conteudo->sobrenome == sobrenome)){
                head = head->next;
                free (aux);
                return true;
            }

            while(aux){
                ant = aux;
                aux = aux->next;

                if((aux != NULL) && (aux->conteudo->nome == nome) && (aux->conteudo->sobrenome == sobrenome)){
                    ant->next = aux->next;
                    free(aux);
                    return true;
                }
            }
        }

        void filtrarCandidatos(int nota){

            NoCandidato *aux = head;

            // Percorrer a lista para verificar a nota e remover aquela não desejada
            while(aux){

                if((aux->conteudo->nota != nota) && ((aux->conteudo->nota <= nota))){
                    remover(aux->conteudo->nome, aux->conteudo->sobrenome);
                }
                aux = aux->next;

            }
        }

        void concatena(ListaCandidatos* l){
            NoCandidato *aux = head;

            while(aux->next != NULL){
                aux = aux->next;
            }
            aux->next = l->head;
        }

};

#endif // LISTACANDIDATOS_H
