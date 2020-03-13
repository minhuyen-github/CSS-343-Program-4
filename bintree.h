//
//  bintree.hpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/13/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#ifndef bintree_h
#define bintree_h

#include <stdio.h>
#include <string>
#include <iostream>
#include "classic.h"
#include "movie.h"

class BinTree
{
    
public:
    
    BinTree();
    ~BinTree();
    void makeEmpty();
    Movie* retrieve(const Movie*);
    Movie* retrieveClassicMovie(const Movie*);
    bool insert(Movie*);
    void display() const;
    
private:
    struct Node
    {
        Movie* ptr;
        Node* left;
        Node* right;
        Node(Movie* data) :ptr(data), left(nullptr), right(nullptr) {};
    };
    Node* root;
    
    void makeEmptyHelper(Node*&);
    void inorderDisplay(Node*) const;
    Movie* retriveBST(Node*&, const Movie*) const;
    Movie* retrieveClassicHelper(Node*&, const Classics*)const;
    bool insertHelper(Node*&, Movie*);
};


#endif /* bintree_h */
