#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std;

class BuscaEmLargura{

    public:
        list<int> fila;
        list <int> :: iterator primeiroFila, ultimoFila;

        BuscaEmLargura(TGrafo grafo, int VericeInicial){

            for (int i = 0; i < grafo.getN(); i++){ /// zerar os vetores antes pois após execulatar uma vez todos ficam com cor preta
                grafo.vertices[i].setId(i);
                grafo.vertices[i].setCor("Branco");
                grafo.vertices[i].setDistancia(-1);
                grafo.vertices[i].setPredecessorId(-1);
            }

            grafo.vertices[VericeInicial].setCor("Cinza");
            grafo.vertices[VericeInicial].setDistancia(0);
            grafo.vertices[VericeInicial].setPredecessorId(-1);

            fila.push_back(VericeInicial);
            primeiroFila = fila.begin();

            printFila(fila, grafo.getN(), grafo.vertices);

            visitar(grafo, *primeiroFila);

        }

    void visitar(TGrafo grafo, int id){

        cout << "Visitou o "<< id << endl;
        for(int i = 0; i < grafo.getN(); i++){
             if((grafo.MAdj[id][i] == 1 || grafo.MAdj[i][id] == 1) && grafo.vertices[i].getCor() == "Branco"){
                grafo.vertices[i].setCor("Cinza");
                grafo.vertices[i].setDistancia(grafo.vertices[id].getDistancia() + 1);
                grafo.vertices[i].setPredecessorId(grafo.vertices[id].getId());

                fila.push_back(grafo.vertices[i].getId());

                primeiroFila = fila.begin();
                ultimoFila = fila.end();

                cout << "Descobriu o vertice " << i <<endl;
             }

        }
        printf("\n");
        grafo.vertices[id].setCor("Preto");

        printFila(fila, grafo.getN(), grafo.vertices);

        cout << "Retirado o " << *primeiroFila << " da lista" << endl;
        fila.pop_front();
        primeiroFila = fila.begin();
        ultimoFila = fila.end();

        if(fila.size() > 0){
            visitar(grafo, *primeiroFila);
        }
    }

    void printFila(list<int> fila, int n, TVertice v[]){
        cout << "Tamanho da fila " << fila.size()<< endl;
        if(fila.size() > 0){
            cout << "   D[ ";
            for(int i = 0; i < n; i++){/// percore todos os vertices e imprime a distancia
                cout << " | " << v[i].getId() << ": " << v[i].getDistancia() << " | ";
            }
            cout << " ]" << endl;

            cout << "   P[ ";
            for(int i = 0; i < n; i++){ /// percore todos os vertices e imprime o predessesor
                cout << " | " << v[i].getId() << ": " << v[i].getPredecessorId() << " | ";
            }
            cout << " ]" << endl;


            cout << "   Q[ ";
            //for(int i : fila){/// percore a fila de vertices e imprime os elementos que estão nela
            for(list<int>::iterator i = fila.begin(); i!=fila.end(); i++){
                cout << " | " << v[*i].getId() << ": " << v[*i].getCor() << " | ";
            }
            cout << " ]\n\n" << endl;
        }

    }

};
