#ifndef DIJSTRA_H
#define DIJSTRA_H


class Dijstra{
   public:
        list<int> fila;
        list <int> :: iterator primeiroFila, ultimoFila;

        Dijstra(TGrafo grafo, int VericeInicial){

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
        fila.pop_front();

        cout << "Visitou o "<< id << endl;

        for(int i = 0; i < grafo.getN(); i++){
             if((grafo.MAdj[id][i] == 1 || grafo.MAdj[i][id] == 1) && grafo.vertices[i].getCor() == "Branco"){
                int pesoAresta = grafo.MAPeso[i][id];
                int distanciaPredecessor = grafo.vertices[id].getDistancia();
                int distanciaAtual = distanciaPredecessor + pesoAresta;  /// pega a do predecessor atual mais o peso


                grafo.vertices[i].setCor("Cinza");
                grafo.vertices[i].setDistancia(distanciaAtual);
                grafo.vertices[i].setPredecessorId(id);

               organizarFilaEAdd(grafo.vertices, i);


                primeiroFila = fila.begin();
                ultimoFila = fila.end();

                cout << "Descobriu o vertice " << i <<endl;
             }

        }
        printf("\n");
        grafo.vertices[id].setCor("Preto");

        printFila(fila, grafo.getN(), grafo.vertices);


        primeiroFila = fila.begin();
        ultimoFila = fila.end();

        if(fila.size() > 0){
            visitar(grafo, *primeiroFila);
        }
    }

    organizarFilaEAdd(TVertice v[], int novo){
        list<int> aux;

        if(fila.size() > 0){
            for(list<int>::iterator i = fila.begin(); i!=fila.end(); i++){
                if(v[*i].getDistancia() < v[novo].getDistancia()){
                    aux.push_back(*i);
                }
                else{
                    aux.push_back(novo);
                    aux.push_back(*i);
                }
            }
        }
        else{
            aux.push_back(novo);
        }
        fila = aux;
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
            for(int i = 0; i < n; i++){/// percore todos os vertices e imprime o predessesor
                cout << " | " << v[i].getId() << ": " << v[i].getPredecessorId() << " | ";
            }
            cout << " ]" << endl;


            cout << "   Q[ ";
            //for(int i : fila){/// percore a fila de vertices e imprime os elementos que estão nela
            for(list<int>::iterator i = fila.begin(); i!=fila.end(); i++){
                cout << " [ " << v[*i].getId() << ": " << v[*i].getCor() << ": D = " << v[*i].getDistancia()<< " ] ";
            }
            cout << " ]\n\n" << endl;
        }

    }
};

#endif // DIJSTRA_H
