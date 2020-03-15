
#ifndef bintree_h
#define bintree_h

#include <stdio.h>
#include <string>
#include <iostream>
#include "classic.h"
#include "movie.h"

//--------------------------  class BinTree  --------------------------------
// Purpose: This class represents a tree data structure in which each node (root) has at
//      most two children (left and right), and each node contains a pointer to a Movie object.
//
// Notes:
//   - This is a binary search tree.
//   - BinTree doesn't allow duplicate data. If there is duplicate data being inserted,
//     it will be delete within insert method.
//   - Exception: two classic movies with same title, month, and year are not considered
//     duplicate if they have different major actors.
//---------------------------------------------------------------------------
class BinTree
{
public:
    
    BinTree();              //constructor
    ~BinTree();             //destructor
    void makeEmpty();       //empty the BST
    Movie* retrieve(const Movie*);      //retrieve a movie
    Movie* retrieveClassicMovie(const Movie*);      //retrieve a classic movie
    bool insert(Movie*);        //insert a movie
    void display() const;       //display
    
private:
    
    //structure for a node
    struct Node
    {
        Movie* ptr;  //a pointer to a Movie object
        Node* left;
        Node* right;
        Node(Movie* data) :ptr(data), left(nullptr), right(nullptr) {};     //constructor for a node
    };
    Node* root;   //root of the BST
    
    void makeEmptyHelper(Node*&);   //helper function
    void inorderDisplay(Node*) const;       //display BST using inorder
    Movie* retrieveBST(Node*&, const Movie*) const;      //helper function to get a movie
    Movie* retrieveClassicHelper(Node*&, const Classics*)const;     //helper function to get a classic movie
    bool insertHelper(Node*&, Movie*);          //helper function to insert a movie object
};


#endif /* bintree_h */
