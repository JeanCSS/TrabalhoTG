#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "TVertice.h"
#define MAXVERTICES 100
#define MAXARESTAS  1000

class TGrafo{
    private:
        int n;             //n�mero de v�rtices do grafo
        int e;             //n�mero de arestas do grafo
        int ultimo;       // indice do ultimo vertice inserido
    public:
        TVertice * vertices;
        int MAdj[MAXVERTICES][MAXVERTICES];
        int MAPeso[MAXVERTICES][MAXVERTICES];


        TGrafo(int _n, int _e, int _ultimo);

        ~TGrafo(){
            cout << "Destructor called"<<endl;
            //free(vertices);
        }

        int getN();
        void setN(int _n);

        int getE();
        void setE(int _e);

        int getUltimo();
        void setUltimo(int _ultimo);

        int getGrau(int vertice);

        void insereVertice ();
        void imprimeGrafo ();
        std::string insereAresta (int a, int b, int peso);
};
/// Construtor e Destructor ////////////////////////////////////////////
TGrafo::TGrafo(int _n, int _e, int _ultimo){ /// /////////
    n = _n;
    e = _e;
    ultimo = _ultimo;
    vertices = (TVertice *) malloc( (n) * sizeof(TVertice));
}
/// ///////////////////////////////////////////////////////


/// Get & Set ////////////////////////////////////////////
int TGrafo::getN(){
    return n;
}

void TGrafo::setN(int _n){
    n = _n;
}

int TGrafo::getE(){
    return e;
}

void TGrafo::setE(int _e){
    e = _e;
}

int TGrafo::getUltimo(){
    return ultimo;
}

void TGrafo::setUltimo(int _ultimo){
    ultimo = _ultimo;
}

int TGrafo::getGrau(int vertice){
    int i, cont=0;
    for(i=0; i < n; i++)
      cont += MAdj[vertice][i];

    return cont;
}

/// ////////////////////////////////////////////////////////

void TGrafo::insereVertice(){
    int i;
    n++;
    ultimo++;

    printf("\nvalor de N: %d\n", n);
    vertices = (TVertice *) malloc( (n) * sizeof(TVertice));
    for (i = 0; i < n; i++){
        MAdj[n][i] = 0;
        MAdj[i][n] = 0;


        vertices[i].setId(i);
        vertices[i].setCor("Branco");
        vertices[i].setDistancia(-1);
        vertices[i].setPredecessorId(-1);
    }
}

std::string TGrafo::insereAresta (int a, int b, int peso){
    if (a == b){
        return "\n\tImpossivel inserir loop!";
    }
    if ((a < 0) || (a >= n) || (b < 0) || (b >= n)){
        return "\n\tVertice inexistente!";
    }
    if (MAdj[a][b] == 1) {
        return "\n\tA aresta já existente!";
    }
    e++;
    MAdj[a][b] = 1;
    MAdj[b][a] = 1;

    MAPeso[a][b]  = peso;
    MAPeso[b][a]  = peso;

    return "\n\tAresta inserida!";
}

void TGrafo::imprimeGrafo (){

    /*printf("\n TT | n | d");

    for(int i = 0; i < n; i++){
        printf("\n %d | %d | %d",vertices[i].getDistancia(), i, vertices[i].getPredecessorId());
    }*/

    printf("\n\n");
     printf("Verice %d Aresta %d Ultimo %d \t\tMatriz de pesos\n", n, e, ultimo);
     int i,j;

      for (i = 0; i < n; i++)
       {
        printf("\n");
        for (j = 0; j < n; j++)
          printf("|%d|", MAdj[i][j]);

        printf("\t\t\t");
        for (int k = 0; k < n; k++)
          printf("|%d|", MAPeso[i][k]);
       }

}

