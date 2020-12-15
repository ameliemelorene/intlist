#include<iostream>
using namespace std;

class IntList {
public:
    IntList (): adrTop(nullptr),adrBot(nullptr),taille(0){}
    //~IntList();
    bool is_empty(){
        return taille==0;
    }
    int size(){
        return taille;
    }
    int get_element_at (int place);
    void add_back(int valeur);
    void add_front();
    void print();
    void remove_front();
    void remove_back();
    void remove(int valeur);
    bool search(int valeur);

private:
    int taille;
    int* adrTop;
    int* adrBot;
};

class IntCell {
    friend class IntList;
private :
    IntCell(int value,int* av,int* ap):valeur(value),adrB(av),adrA(ap) {
    }
    int valeur;
    int* adrB;
    int* adrA; 
};
