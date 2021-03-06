#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "TGrafo.h"
#include "BuscaEmLargura.h"
#include "BuscaEmProfundidade.h"
#include "Dijstra.h"

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
     printf("\n\t 8 - | Busca em Largura");
     printf("\n\t 9 - | Busca em Profundidade");
     printf("\n\t 10- | Dijstra");
     printf("\n\t 0 - | Sair");
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
                grafo->insereAresta(i, j, i);
            }
          }

       }
    }
}

void grafoAleatorio(TGrafo * grafo){
    srand(time(NULL));
    int qtdVertice = rand() % 9 + 1;;
    *grafo = TGrafo(0, 0, 0);

    for( int i = 0; i < qtdVertice; i++){
        grafo->insereVertice();
        int maxAresta = rand() % qtdVertice; ///
        int peso = rand() % 21 + 2; ///
        for( int j = 0; j < maxAresta; j++){
            string r = grafo->insereAresta(i, rand() % qtdVertice, peso + j);
        }
    }
}

int main(int argc, char *argv[]){

    TGrafo grafo = TGrafo(0, 0, 0);

    int op, vert1, vert2, s, peso;

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
            printf("\t1o. vertice: ");                  scanf("%d", &vert1);
            printf("\n\t\t\t2o. vertice: ");            scanf("%d", &vert2);
            printf("\n\t\t\t    Peso: ");               scanf("%d", &peso);

            string responce = grafo.insereAresta(vert1,vert2, peso);

            cout << responce << endl;

            system("pause");

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

        if (op == 10){
            printf("\n\t\t\tDijstra\n");
            printf("\n\tInicio: ");
            scanf("%d", &s);

            Dijstra dfs = Dijstra(grafo, s);

            system("PAUSE");

        }
        if (op == 9){
            printf("\n\t\t\tBusca em Profundidade\n");
            printf("\n\tInicio: ");
            scanf("%d", &s);
            BuscaEmProfundidade dfs = BuscaEmProfundidade(grafo, s);
            system("PAUSE");
        }
        if (op == 8){
            printf("\n\t\t\tBusca em Profundidade\n");
            printf("\n\tInicio: ");
            scanf("%d", &s);
            BuscaEmProfundidade dfs = BuscaEmProfundidade(grafo, s);
            system("PAUSE");
        }

    }while(op!=0);
 //
    return 0;
}
