#include <iostream>
#include <Tree.h>
#include <../src/Tree.cpp>

using namespace std;

int main()
{

    Node<long long> *nd = NULL;
    Tree<long long> *A = new Tree<long long>();

    //nd = A->getNoeud();

    int nbElem = 1000000;

    for(int i = 1; i <= nbElem; i++)
        A->inserer(i);
    cout << nbElem << " element hase been inserted" << endl;

    ///A->print2D(); //Pour afficher l'arbre


    int choice = 1;
    long long int nb;

    while(choice)
    {
        cout << ".................................................................................................." << endl;
        cout << "\n1 : Get max elements of the Tree\n2 : Search for an element\n0 : exit" << endl;
        cout << "What is your choice? : ";
        cin >> choice;
        switch(choice)
        {
        case 1 :
            cout << "How many max elements you want? : ";
            cin >> nb;
            A->afficherMax(nb);
            break;

        case 2 :
            cout << "What is the element you are searching for? : ";
            cin >> nb;
            if(A->recherche(nb))
                cout << "==> The element " << nb << " is found" << endl;
            else
                cout << "==> The element " << nb << " is not found" << endl;
            break;

        case 0 :
            choice = 0;
            break;

        default :
            cout << "Your choice is not correct" << endl;
        }
    }

    return 0;
}
