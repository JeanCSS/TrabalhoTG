#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "TGrafo.h"

#define MAXVERTICES 100
#define MAXARESTAS  1000



void imprimeMenu()
{
     printf("\n\n\t1 - | Inserir Vertice");
     printf("\n\t2 - | Inserir Aresta");
     printf("\n\t3 - | Verificar Euleriano");
     printf("\n\t4 - | Verificar se o grafo eh completo");
     printf("\n\t5 - | completar o grafo");
     printf("\n\t6 - | Gerar grafo aleatorio");
     printf("\n\t9 - | Sair");
     printf("\n\tOpcao -> ");
}

int grau(TGrafo grafo, int vertice)
{
    int i, cont=0;
    for(i=0; i < grafo.getN(); i++)
      cont += grafo.MAdj[vertice][i];

    return cont;
}

int euleriano(TGrafo grafo)
{
    int i;
    for (i=0; i<grafo.getN(); i++)
     if (grau(grafo,i) % 2 != 0)
       return 0;

    return 1;
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
                grafo->MAdj[i][j] = 1;

            }
          }

       }
    }
}

int main(int argc, char *argv[])
{

  TGrafo grafo = TGrafo(0, 0, 0);

  int op, vert1, vert2, s;


  system("cls");
  system("COLOR f0");

 do
 {
  system("cls");
  printf("\t\t\tMATRIZ ADJACENCIAS\n");

  grafo.imprimeGrafo();
  imprimeMenu();
  scanf("%d", &op);

  if (op == 1) //Inserindo v�rtices
    grafo.insereVertice();

  if (op == 2) //Inserindo arestas
   {
         printf("\nInserindo aresta...");
         printf("\t1o. vertice: ");
         scanf("%d", &vert1);
         printf("\n\t\t\t2o. vertice: ");
         scanf("%d", &vert2);
         if ((vert1< 0) || (vert1>=grafo.getN()) || (vert2<0) || (vert2>=grafo.getN()))
          {
            printf("\n\tVertice inexistente!");
            system("pause");
          }
         else
          if (vert1 == vert2)
            {
            printf("\n\tImpossivel inserir loop!");
            system("pause");
            }
            else
             grafo.insereAresta(vert1,vert2);

   }

  if (op==3)
  {
    if (grafo.getN() == 0)
     printf("Nao existe grafo ainda...");
    else
    {
     if(euleriano(grafo) == 0)
      printf("Nao eh euleriano!");
     else
      printf("Eh euleriano!");
    }
    system("pause");
  }
  if (op==4){
    if (grafo.getN() == 0)
     printf("Nao existe grafo ainda...");
    else
    {
     if(isCompleto(grafo) == 0)
      printf("Nao e completo!");
     else
      printf("E completo!");
    }
    system("pause");
  }
  if (op==5){
      completarGrafo(&grafo);
  }

  if (op == 6){
    int nunAresta = rand() % 10 + 2;//rand(2, 40);
    grafo = TGrafo(nunAresta, nunAresta, nunAresta);

    for( int i = 0; i < nunAresta; i++){
        int maxVertice = rand() % nunAresta; ///
        for( int j = 0; j < maxVertice; j++){
            grafo.insereAresta(i, rand() % nunAresta - 1);
        }
    }
  }

 } while(op!=9);


// printf("\n\n");
 // system("PAUSE");
  return 0;
}
