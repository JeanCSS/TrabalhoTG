#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "TGrafo.h"

#define MAXVERTICES 100
#define MAXARESTAS  1000

using namespace std;

void imprimeMenu(){

     printf("\n\n\t=======================================");
     printf("\n\t 1 - | Inserir Vertice");
     printf("\n\t 2 - | Inserir Aresta");
     printf("\n\t 3 - | Verificar Euleriano");
     printf("\n\t 4 - | Verificar se o grafo eh completo");
     printf("\n\t 5 - | completar o grafo");
     printf("\n\t 6 - | Verificar se o grafo eh arvore");
     printf("\n\t 7 - | Gerar grafo aleatorio");
     printf("\n\t 9 - | Sair");
     printf("\n\t=======================================");
     printf("\n\t Opcao -> ");
}

int euleriano(TGrafo grafo){

    int i;
    for (i = 0; i < grafo.getN(); i++)
     if (grafo.getGrau(i) % 2 != 0)
       return 0;

    return 1;
}

string isArvore(TGrafo grafo){
    int aresta = grafo.getE();
    int vertice = grafo.getN();
    if(aresta != vertice - 1){ /// um grafo tem que ter n - 1 de arestas
        return "Nao é arvore. O numero de aresta tem que ser n - 1";
    }

    for(int i = 0; i < grafo.getN(); i++){
        //printf("i %d | Grau %d \n", i, grafo.getGrau(i));
        if(grafo.getGrau(i) == 0){
            return "Nao é arvore. Grafo nao conexo";
        }
    }
    return "É arvore";
}

int isCompleto(TGrafo grafo){

    int i,j;
    for(i=0;i<grafo.getN();i++){
      for(j=0;j<grafo.getN();j++){
          if(i!=j){
            if(grafo.MAdj[i][j]==0){
                return 0;
            }
          }
       }
    }
    return 1;
}

void completarGrafo(TGrafo * grafo){

    int i, j;
    for(i = 0; i < grafo->getN(); i++){
      for(j = 0;j < grafo->getN(); j++){
          if(i != j){
            if(grafo->MAdj[i][j]==0){
                grafo->insereAresta(i, j);
            }
          }

       }
    }
}

void grafoAleatorio(TGrafo * grafo){
    int qtdVertice = rand() % 10 + 3;;
    *grafo = TGrafo(qtdVertice, 0, qtdVertice);

    for( int i = 0; i < qtdVertice; i++){
        int maxAresta = rand() % qtdVertice; ///
        for( int j = 0; j < maxAresta; j++){
            grafo->insereAresta(i, rand() % qtdVertice);
        }
    }
}

void buscaEmLargura(TGrafo grafo, int inicio){
    int i, j;
    int visitados[MAXVERTICES];
    int distancia[MAXVERTICES];
    int antecessor[MAXVERTICES];
    int vertice;
    int contador = 0;

    for(i = 0; i < grafo.getN(); i++){
        visitados[i] = 0;
        distancia[i] = 0;
        antecessor[i] = -1;
    }

    visitados[inicio] = 1;
    distancia[inicio] = 0;
    antecessor[inicio] = -1;

    for(i = 0; i < grafo.getN(); i++){
        for(j = 0; j < grafo.getN(); j++){
            if(grafo.MAdj[i][j] == 1){
                if(visitados[j] == 0){
                    visitados[j] = 1;
                    distancia[j] = distancia[i] + 1;
                    antecessor[j] = i;
                }
            }
        }
    }

    for(i = 0; i < grafo.getN(); i++){
        if(visitados[i] == 1){
            printf("Vertice %d | Distancia %d | Antecessor %d\n", i, distancia[i], antecessor[i]);
        }
    }
}

int main(int argc, char *argv[]){

    TGrafo grafo = TGrafo(0, 0, 0);

    int op, vert1, vert2, s;

    system("cls");
    system("COLOR f0");

    do{
        system("cls");
        printf("\t\t\tMATRIZ ADJACENCIAS\n");


        grafo.imprimeGrafo();
        imprimeMenu();
        scanf("%d", &op);

        if (op == 1){ //Inserindo v�rtices
            grafo.insereVertice();
        }

        if (op == 2){ //Inserindo arestas
            printf("\nInserindo aresta...");
            printf("\t1o. vertice: ");
            scanf("%d", &vert1);
            printf("\n\t\t\t2o. vertice: ");
            scanf("%d", &vert2);
            if ((vert1 < 0) || (vert1>=grafo.getN()) || (vert2<0) || (vert2>=grafo.getN())){
                printf("\n\tVertice inexistente!");
                system("pause");
            }
            else
                if (vert1 == vert2){
                    printf("\n\tImpossivel inserir loop!");
                    system("pause");
                }
                else
                    grafo.insereAresta(vert1,vert2);

        }

        if (op == 3){
            if (grafo.getN() == 0)
                printf("Nao existe grafo ainda...");
            else{
                if(euleriano(grafo) == 0)
                    printf("Nao eh euleriano!");
                else
                    printf("Eh euleriano!");
            }
            system("pause");
        }

        if (op == 4){
            if (grafo.getN() == 0)
                printf("Nao existe grafo ainda...");
            else{
                if(isCompleto(grafo) == 0)
                    printf("Nao e completo!");
                else
                    printf("E completo!");
            }
            system("pause");
        }

        if (op == 5){
            completarGrafo(&grafo);
        }

        if (op == 6){
            cout << isArvore(grafo) << endl;
            system("PAUSE");
        }

        if (op == 7){
            grafoAleatorio(&grafo);
        }

        if (op == 8){
            printf("\n\t\t\tBusca em largura\n");
            printf("\n\t\t\tInicio: ");
            scanf("%d", &s);
            buscaEmLargura(grafo, s);
            system("PAUSE");
        }

    }while(op!=9);
 //
    return 0;
}
