#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAXVERTICES 100
#define MAXARESTAS  1000

class TGrafo{
    private:
        int n;             //n�mero de v�rtices do grafo
        int e;             //n�mero de arestas do grafo
        int ultimo;       // indice do ultimo vertice inserido
    public:
        int MAdj[MAXVERTICES][MAXVERTICES];

        TGrafo(int n, int e, int ultimo);

        int getN();
        void setN(int _n);

        int getE();
        void setE(int _e);

        int getUltimo();
        void setUltimo(int _ultimo);

        int getGrau(int vertice);

        void insereVertice ();
        void imprimeGrafo ();
        void insereAresta (int a, int b);
};
/// Construtor ////////////////////////////////////////////
TGrafo::TGrafo(int _n, int _e, int _ultimo){ /// /////////
     n = _n;
     e = _e;
     ultimo = _ultimo;
}                                    ///  /////////////////
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

      for (i = 0; i <= n; i++){
         MAdj[n][i] = 0;
         MAdj[i][n] = 0;
      }
      n++;
      ultimo++;
}

void TGrafo::insereAresta (int a, int b){
      if (MAdj[a][b] == 0) {
         if (a != b) {
            e++;
            MAdj[a][b] = 1;
            MAdj[b][a] = 1;
         }
      }

}

void TGrafo::imprimeGrafo (){
     printf("Verice %d Aresta %d Ultimo %d \n", n, e, ultimo);
     int i,j;

      for (i = 0; i < n; i++)
       {
        printf("\n");
        for (j = 0; j < n; j++)
         printf(" %d ", MAdj[i][j]);
       }

}

