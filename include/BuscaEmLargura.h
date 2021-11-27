#include <iostream>
#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <list>
//#include "TGrafo.h"
//#include "TVertice.h"
using namespace std;
=======
#ifndef BUSCAEMLARGURA_H
#define BUSCAEMLARGURA_H
>>>>>>> parent of 1264040 (Busca em largura atualizado)


class BuscaEmLargura
{
    public:
        BuscaEmLargura() {}
        BuscaEmLargura(TGrafo grafo, int inicio);
        virtual ~BuscaEmLargura() {}

        void visitar(TGrafo grafo, int id);

    protected:

<<<<<<< HEAD
        cout << "Visitou o "<< id << endl;
        for(int i = 0; i < grafo.getN(); i++){
             if((grafo.MAdj[id][i] == 1 || grafo.MAdj[i][id] == 1) && grafo.vertices[i].getCor() == "Branco"){
                grafo.vertices[i].setCor("Cinza");
                grafo.vertices[i].setDistancia(grafo.vertices[id].getDistancia() + 1);
                grafo.vertices[i].setPredecessorId(grafo.vertices[id].getId());

                fila.push_back(grafo.vertices[i].getId());

                primeiroLista = fila.begin();
                ultimoLista = fila.end();

                cout << "Descobriu o vertice " << i <<endl;
                FinalFila++;
             }

        }
        printf("\n");
        grafo.vertices[id].setCor("Preto");

        printFila(fila, grafo.getN(), grafo.vertices);

        cout << "Retirado o " << *primeiroLista << " da lista" << endl;
        fila.pop_front();
        primeiroLista = fila.begin();
        ultimoLista = fila.end();
=======
    private:
};
>>>>>>> parent of 1264040 (Busca em largura atualizado)

BuscaEmLargura::BuscaEmLargura(TGrafo grafo, int inicio){
    for(int i = 0; i < grafo.getN(); i++){
        //printf("Vertice %d <<  Distancia  %d<<\n", grafo.vertices[i].getId(), grafo.vertices[i].getDistancia());
        cout
            << " Vertice " << grafo.vertices[i].getId()
            << " Cor " << grafo.vertices[i].getCor()
            << " Distancia " << grafo.vertices[i].getDistancia()
            << " PredecessorId " << grafo.vertices[i].getPredecessorId()<<
        endl;
    }
    visitar(grafo, inicio);
}

void BuscaEmLargura::visitar(TGrafo grafo, int id){
        grafo.vertices[id].setCor("Cinza");
        cout
            << " Vertice " << grafo.vertices[id].getId()
            << " Cor " << grafo.vertices[id].getCor()
            << " Distancia " << grafo.vertices[id].getDistancia()
            << " PredecessorId " << grafo.vertices[id].getPredecessorId()<<
        endl;

<<<<<<< HEAD
            cout << "   Q[ ";
            for(list<int>::iterator i = fila.begin(); i!=fila.end(); i++){
                cout << " | " << v[*i].getId() << ": " << v[*i].getCor() << " | ";
            }
            cout << " ]\n\n" << endl;
        }

    }

};
=======

}

#endif // BUSCAEMLARGURA_H
>>>>>>> parent of 1264040 (Busca em largura atualizado)
