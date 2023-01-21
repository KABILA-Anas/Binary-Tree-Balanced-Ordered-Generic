#ifndef TREE_H
#define TREE_H

template <class T>
struct Node
{
    T value;
    int height;
    Node *left;
    Node *right;

    Node()
    {
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

template <class T>
class Tree
{
    public:
        Tree();
        virtual ~Tree();
        Node<T>* getNoeud();
        void inserer(T);
        void prefixe(Node<T>*);
        bool recherche(T);
        Node<T>* supprimer();
        void afficherMax(int p);
        void afficherMin(int p);
        void print2D();

    private:
        Node<T> *R;
        Node<T>* inserer(Node<T>*, T);
        Node<T>* supprimer(Node<T>*);
        bool recherche(Node<T>*, T);
        void afficherMax(Node<T>*N, int* p);
        void afficherMin(Node<T>*N, int* p);
        void print2DUtil(Node<T>*, int);
        int getHeigth(Node<T>*);
        Node<T>* Equilibrer(Node<T>*);
        int hauteur(Node<T>*);
        Node<T>* rotateLeft(Node<T>* N);
        Node<T>* rotateRight(Node<T>* N);
};


#endif // TREE_H
