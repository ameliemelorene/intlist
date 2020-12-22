#include<iostream>
using namespace std;

class IntCell {
    friend class IntList;
private :
    IntCell(): Before(nullptr),After(nullptr),valeur(0){}
    int valeur;
    IntCell * Before;
    IntCell * After;
};

class IntList {
public:
    IntList (): Top(nullptr),Bot(nullptr),taille(0){}
    //~IntList();
    bool is_empty(){
        return taille==0;
    }
    int size(){
        return taille;
    }
    int get_element_at (int place);
    void add_back(int value){
        if (is_empty()){
            IntCell* cell = new IntCell;
            (*cell).valeur=value;
            Top=cell;
            Bot=cell;
            taille=taille+1;
        }
        else{
            IntCell* cell=new IntCell;
            (*cell).valeur=value;
            IntCell* Pointeur_precedent=Bot;
            (*Pointeur_precedent).After=cell;
            (*cell).Before=Pointeur_precedent;
            Bot=cell;
            taille=taille+1;
        }
    }
    void add_front(int value){
        if (is_empty()){
            IntCell* cell = new IntCell;
            (*cell).valeur=value;
            Top=cell;
            Bot=cell;
            taille=taille+1;
        }
        else{
            IntCell* cell=new IntCell;
            (*cell).valeur=value;
            IntCell* Pointeur_suivant=Top;
            (*Pointeur_suivant).Before=cell;
            (*cell).After=Pointeur_suivant;
            Top=cell;
            taille=taille+1;
        }
    }

    void print(){
        cout<<'{';
        IntCell* adr=Top;
        for (int i=0;i<taille;i++) {
            cout<<(*adr).valeur<<',';
            adr=((*adr).After);
        }
        cout<<'}'<<endl;
    }
        void remove_front(){
        if (not (is_empty())){
            if (taille==1){
                IntCell* front=Top;
                delete front;
                Top=nullptr;
                Bot=nullptr;
            }
            else{
                IntCell* front=Top;
                IntCell* new_front=(*front).After;
                (*new_front).Before=nullptr;
                delete front;
                Top=new_front;
            }
        }
    }
    void remove_back(){
        if (not (is_empty())){
            if (taille==1){
                IntCell* front=Top;
                delete front;
                Top=nullptr;
                Bot=nullptr;
            }
            else{
                IntCell* back=Bot;
                IntCell* new_back=(*back).Before;
                (*new_back).After=nullptr;
                delete back;
                Top=new_back;
            }      
        }
    }
    void remove(int value);
    bool search(int value){
        if (is_empty()){
            return 0;
        }
        else {
            IntCell* cell=Top;
            for (int i=0; i<taille;i++){
                if ((*cell).valeur==value){
                    return 1;
                }
                else{
                    cell=(*cell).After;
                }
            }
            return 0;
        }
    }

private:
    int taille;
    IntCell* Top;
    IntCell* Bot;
};
