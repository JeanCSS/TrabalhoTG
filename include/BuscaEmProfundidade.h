#ifndef BUSCAEMPROFUNDIDADE_H
#define BUSCAEMPROFUNDIDADE_H


class BuscaEmProfundidade{
    public:
        list<int> fila;
        list <int> :: iterator primeiroLista, ultimoLista;
        int time;


        BuscaEmProfundidade(TGrafo grafo, int VericeInicial){

            for (int i = 0; i < grafo.getN(); i++){ /// zerar os vetores antes pois após execulatar uma vez todos ficam com cor preta
                grafo.vertices[i].setId(i);
                grafo.vertices[i].setCor("Branco");
                grafo.vertices[i].setDistancia(-1);
                grafo.vertices[i].setPredecessorId(-1);
            }
            time = 0;
            fila.push_back(VericeInicial);
            primeiroLista = fila.begin();
            ultimoLista = fila.end();

            visitar(grafo, VericeInicial);
        }

    void visitar(TGrafo grafo, int id){
        time++;
        cout << "Visitou o "<< id << endl;
        grafo.vertices[id].setCor("Cinza");
        grafo.vertices[id].setDistancia(time);

        printFila(fila, grafo.getN(), grafo.vertices);
        //grafo.vertices[id].setPredecessorId(-1);

        for(int i = 0; i < grafo.getN(); i++){
             if((grafo.MAdj[id][i] == 1 || grafo.MAdj[i][id] == 1) && grafo.vertices[i].getCor() == "Branco"){
                cout << "Descobriu o vertice " << i <<endl;
                grafo.vertices[i].setPredecessorId(id);
                fila.push_back(i);
                primeiroLista = fila.begin();
                ultimoLista = fila.end();

                visitar(grafo, i);
             }
        }

        printf("\n");
        grafo.vertices[id].setCor("Preto");

        cout << "Retirado o " << id << " da pilha" << endl;
        printFila(fila, grafo.getN(), grafo.vertices);
        fila.pop_back();


        primeiroLista = fila.begin();
        ultimoLista = fila.end();
    }

    void printFila(list<int> fila, int n, TVertice v[]){
        cout << fila.size()<< endl;
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
            /// for(int i : fila){/// percore a fila de vertices e imprime os elementos que estão nela
            for(list<int>::iterator i = fila.begin(); i != fila.end(); i++){
                cout << " | " << v[*i].getId() << ": " << v[*i].getCor() << " | ";
            }
            cout << " ]\n\n" << endl;
        }
    }
};

#endif // BUSCAEMPROFUNDIDADE_H
