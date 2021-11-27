#ifndef BUSCAEMPROFUNDIDADE_H
#define BUSCAEMPROFUNDIDADE_H


class BuscaEmProfundidade{
    public:
        list<int> fila;
        list <int> :: iterator primeiroLista, ultimoLista;
        int FinalFila, inicioFila;


        BuscaEmProfundidade(TGrafo grafo, int VericeInicial){
            FinalFila = 0;
            inicioFila = 0;

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
            primeiroLista = fila.begin();

            printFila(fila, grafo.getN(), grafo.vertices);

            visitar(grafo, *primeiroLista);

        }

    void visitar(TGrafo grafo, int id){

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

        if(fila.size() > 0){
            visitar(grafo, *primeiroLista);
        }
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
            //for(int i : fila){/// percore a fila de vertices e imprime os elementos que estão nela
            for(list<int>::iterator i = fila.begin(); i!=fila.end(); i++){
                cout << " | " << v[*i].getId() << ": " << v[*i].getCor() << " | ";
            }
            cout << " ]\n\n" << endl;
        }

    }

};

#endif // BUSCAEMPROFUNDIDADE_H
