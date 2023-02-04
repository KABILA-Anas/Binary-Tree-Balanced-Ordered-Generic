#include "Tree.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#define COUNT 10

using namespace std;

template <class T>
Tree<T>::Tree()
{
    R = new Node<T>();
    R = R->left = R->right = NULL;
}

template <class T>
Node<T>* Tree<T>::getNoeud(){
    return (Node<T>*)R;
}

/**
Recherche a un element d'apres un noeud
**/
template <class T>
bool Tree<T>::recherche(Node<T>*N, T p)
{
    if(!N)
        return false;
    if(N->value == p)
        //if(N->c == c)
            return true;
    if(p > N->value)
        recherche(N->right, p);
    else
        recherche(N->left, p);
}

/**
Recherche a un element d'apres la racine on utilisant la fonction precedente
**/
template <class T>
bool Tree<T>::recherche(T p)
{
    if(recherche(R, p))
        return true;
    return false;
}


/**
cherche et affiche les p max elements d'apres un noeud
**/
template <class T>
void Tree<T>::afficherMax(Node<T>*N, int* p, T& currVlue)
{
    if(!N)
        return;
    afficherMax(N->right, p, currVlue);
    if((*p) && (currVlue) != N->value)
    {
        cout << "==> " << N->value << endl;
        currVlue = N->value;
        (*p)--;
    }
    if((*p))
        afficherMax(N->left, p, currVlue);
}


template <class T>
void Tree<T>::afficherMin(Node<T>*N, int* p, T& currVlue)
{
    if(!N)
        return;
    afficherMin(N->left, p, currVlue);
    if((*p) && (currVlue) != N->value)
    {
        cout << "==> " << N->value << endl;
        currVlue = N->value;
        (*p)--;
    }
    if((*p))
        afficherMin(N->right, p, currVlue);
}

/**
cherche et affiche les p max elements d'apres la racine
**/
template <class T>
void Tree<T>::afficherMax(int p)
{
    T currValue = -1;
    afficherMax(R, &p, currValue);
}

template <class T>
void Tree<T>::afficherMin(int p)
{
    T currValue = -1;
    afficherMin(R, &p, currValue);
}

/**
retourne la hauteur d'un noeud
**/
template <class T>
int Tree<T>::getHeigth(Node<T>* N)
{
    if(!N)  return 0;
    return N->height;
}

/**
Calcule la hauteur d'un noeud
**/
template <class T>
int Tree<T>::hauteur(Node<T>* N)
{
    if(!N)
        return 0;
    return (max(hauteur(N->left), hauteur(N->right)) + 1);
}

/**
Fait une rotation a gauche d'apres le noeud en argument
**/
template <class T>
Node<T>* Tree<T>::rotateLeft(Node<T>* N)
{
  Node<T> *NewN = N->right;
  Node<T> *tmp = NewN->left;

  ///Rotation
  NewN->left = N;
  N->right = tmp;

  /// La nouvelle hauteur
  N->height = max(hauteur(N->left), hauteur(N->right)) + 1;
  NewN->height = max(hauteur(NewN->left), hauteur(NewN->right)) + 1;

  /// La nouvelle racine
  return NewN;
}

/**
Fait une rotation a droite d'apres le noeud en argument
**/
template <class T>
Node<T>* Tree<T>::rotateRight(Node<T>* N)
{
  Node<T> *NewN = N->left;
  Node<T> *tmp = NewN->right;

  ///Rotation
  NewN->right = N;
  N->left = tmp;

  /// La nouvelle hauteur
  NewN->height = std::max(hauteur(NewN->left), hauteur(NewN->right)) + 1;
  N->height = std::max(hauteur(N->left), hauteur(N->right)) + 1;

  /// La nouvelle racine
  return NewN;
}

/**
Equilibre les deux sous arbres d'un noeud
**/
template <class T>
Node<T>* Tree<T>::Equilibrer(Node<T>* N)
{
    N->height = std::max(getHeigth(N->left), getHeigth(N->right)) + 1;
    int hl, hr;
    hl = hr = 0;

    hl = getHeigth(N->left);
    hr = getHeigth(N->right);

    ///Rotation a droite
    if((hl - hr) > 1)
        return rotateRight(N);

    ///Rotation a gauche
    if((hl - hr) < -1)
        return rotateLeft(N);

    return N;
}

/**
Insere un element dans l'arbre
**/
template <class T>
Node<T>* Tree<T>::inserer(Node<T> *nd, T value)
{
    if (nd == NULL) {
        nd = new Node<T>();
        nd->value = value;
        return (Node<T>*)nd;
    }

    if (value < nd->value) {
        nd->left=inserer(nd->left, value);
    } else {
        nd->right=inserer(nd->right, value);
    }
    nd->height++;

    ///Equilibrer chaque noeud visite
    return Equilibrer(nd);
}

template <class T>
void Tree<T>::inserer(T freq)
{
    R = inserer(R, freq);
}


template <class T>
Node<T>* Tree<T>::supprimer()
{
    supprimer(R);
}

/**
Supprime le maximum element dans l'arbre
**/
template <class T>
Node<T>* Tree<T>::supprimer(Node<T>* N)
{
    if(!R)
        return nullptr;

    if(!N->right)
    {
        if(N == R)
            R = R->left;
        N->left = nullptr;
        return N;
    }

    if(!N->right->right)
    {
        Node<T>* tmp = N->right;
        N->right = N->right->left;
        tmp->left = nullptr;
        return tmp;
    }

    return supprimer(N->right);
}

/**
Affichage prefixe
**/
template <class T>
void Tree<T>::prefixe(Node<T> *N)
{
    if(!N)
        return;
    prefixe(N->left);
    cout << "{" << N->value << "}\n";
    prefixe(N->right);
}

/**
Affichage sous form d'un arbre
**/
template <class T>
void Tree<T>::print2DUtil(Node<T>* root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << "{" << root->height << " -- " << root->value << "}\n";

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
template <class T>
void Tree<T>::print2D()
{
    // Pass initial space count as 0
    print2DUtil(R, 0);
}

template <class T>
Tree<T>::~Tree()
{
    //dtor
}
