#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#ifndef BUSCAEMLARGURA_H
#define BUSCAEMLARGURA_H


class BuscaEmLargura
{
    public:
        BuscaEmLargura() {}
        BuscaEmLargura(TGrafo grafo, int inicio);
        virtual ~BuscaEmLargura() {}

        void visitar(TGrafo grafo, int id);

    protected:

    private:
};

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


}

#endif // BUSCAEMLARGURA_H
