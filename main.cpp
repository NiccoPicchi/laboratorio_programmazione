#include <iostream>
#include "Note.h"
#include "NotepadObserver.h"
using namespace std;

string setName () {
    string name;
    getline (cin, name);
    return name;
}



int main() {
    Notepad notepad;
    NotepadObserver observer(&notepad);
    cout<<"Benvenuto nel blocco note!"<<endl;
    cout<<"Cosa desideri fare:"<<"\n"<< "1)Creare una nuova collezione      2)Creare una nuova nota       3)Modificare una nota       4)Leggere una nota      5)Eliminare una nota      6)Eliminare una collezione      7)Uscire"<<endl;
    int option=0;
    while (option != 7) {
        cout<< "Digitare il numero corrispondente all'azione desiderata" <<endl;
        cin>>option;
        if (option > 7 || option < 0){
            while (option<0 || option>5){
                cout<<"Il numero inserito non è corretto! Inserire un nuovo numero! "<<endl;
                cin>>option;
            }
        }

        if (option == 1){
            cin.ignore();
            std::cout<<"Inserire il nome della collezione:"<<std::endl;
            string collectionTitle = setName();
            notepad.setCollectionTitle(collectionTitle);
        }

        if (option == 2){
            cin.ignore();
            std::cout<<"Inserire il nome della collezione in cui si vuole inserire la nota:"<<std::endl;
            string collectionTitle = setName();
            notepad.createNote(collectionTitle);
        }

        if (option == 3){
            cin.ignore();
            cout<<"Inserire il nome della collezione in cui è presente la nota da modificare"<<endl;
            string collectionTitle = setName();
            cout<<"Inserire il titolo della nota da modificare"<<endl;
            string noteTitle = setName();
            notepad.modifyNote(collectionTitle, noteTitle);
        }
        if (option==4){
            cin.ignore();
            cout<<"Inserire il nome della collezione in cui è presente la nota da leggere"<<endl;
            string collectionTitle = setName();
            cout<<"Inserire il titolo della nota da leggere"<<endl;
            string noteTitle = setName();
            notepad.showNote(collectionTitle, noteTitle);
        }
        if (option==5){
            cin.ignore();
            cout<<"Inserire il nome della collezione in cui è presente la nota da eliminare"<<endl;
            string collectionTitle = setName();
            cout<<"Inserire il titolo della nota da eliminare"<<endl;
            string noteTitle = setName();
            notepad.removeNote(collectionTitle, noteTitle);
        }
        if (option == 6){
            cin.ignore();
            cout<<"Inserire il nome della collezione da eliminare"<<endl;
            string collectionTitle = setName();
            notepad.deleteCollection(collectionTitle);
        }
    }

    if (option ==7)
        return 0;

}
