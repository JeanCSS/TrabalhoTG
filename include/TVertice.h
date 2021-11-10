#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class TVertice{
    private:
        int id;
        string cor;
        int distancia;
        int predecessorId;

    public:
        TVertice(int id, string cor, int distancia, int predecessorId);

        int getId();
        void setId(int _id);

        string getCor();
        void setCor(string _cor);

        int getDistancia();
        void setDistancia(int _distancia);

        int getPredecessorId();
        void setPredecessorId(int _predecessorId);
};

TVertice::TVertice(int _id, string _cor, int _distancia, int _predecessorId){
    id = _id;
    cor = _cor;
    distancia = _distancia;
    predecessorId = _predecessorId;
}

int TVertice::getId(){
    return id;
}
void TVertice::setId(int _id){
    id = _id;
}

string TVertice::getCor(){
    return cor;
}
void TVertice::setCor(string _cor){
    cor = _cor;
}

int TVertice::getDistancia(){
    return distancia;
}
void TVertice::setDistancia(int _distancia){
    distancia = _distancia;
}

int TVertice::getPredecessorId(){
    return predecessorId;
}
void TVertice::setPredecessorId(int _predecessorId){
    predecessorId = _predecessorId;
}
