//
//  bintree.cpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/13/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#include "bintree.h"

//---------------------- Default Constructor --------------------
// --Creates an empty BSTree.
//---------------------------------------------------------------
BinTree::BinTree()
{
    this->root = nullptr;
}



//---------------------- Destructor -----------------------------
// --Calls makeEmpty to delete a BSTree.
//---------------------------------------------------------------
BinTree::~BinTree()
{
    makeEmpty();
}

//---------------------- makeEmpty ------------------------------
// --Deletes entire BinTree.
// --Uses helper function makeEmptyHelpter.
//---------------------------------------------------------------
void BinTree::makeEmpty()
{
    makeEmptyHelper(root);
}

//---------------------- makeEmptyHelper ------------------------
// --Helper function for makeEmpty.
// --Deletes all nodes of a tree
//   and sets nodes to nullptr.
//---------------------------------------------------------------
void BinTree::makeEmptyHelper(Node*& temp)
{
    if (temp != nullptr)
    {
        // Post order traversal
        makeEmptyHelper(temp->left);
        makeEmptyHelper(temp->right);
        
        // Deletes NodeData
        delete temp->ptr;
        temp->ptr = nullptr;
        
        // Deletes Node
        delete temp;
        temp = nullptr;
    }
}

//------------------------ isEmpty --------------------------------
// --Checks whether a BinTree is empty or not
// --Returns true if empty, else returns false
// --------------------------------------------------------------
//bool BinTree::isEmpty() const
//{
//    return (root == nullptr);
//}

//---------------------- retrieve -------------------------------
// --Checks whether or not a NodeData is in a BinTree.
// --If found returns a pointer to that node else returns
//   nullptr.
// --Uses helper function retrieveHelper.
//---------------------------------------------------------------
Movie* BinTree::retrieve(const Movie* movie)
{
    return retriveBST(root, movie);
}

//---------------------- retrieveBSTreeElement ------------------
// --Helper function for retrieve.
// --If item is found, will return a pointer to item else returns
//   nullptr.
// --------------------------------------------------------------
Movie* BinTree::retriveBST(Node*& temp, const Movie* movie) const
{
    // base case 01:
    // item does not exist
    if (temp == nullptr)
    {
        delete movie;    // prevents memory leak
        return  nullptr;
    }
    // base case 02:
    // check if root contains the same data
    if (*temp->ptr == movie)
    {
        delete movie;    // prevents memory leak
        return temp->ptr;
    }
    // do binary search:
    // if findMovie is less than current->info go left
    else if (*temp->ptr > movie)
    {
        return retriveBST(temp->left, movie);
    }
    // findMovie is greater, go right
    else
    {
        return retriveBST(temp->right, movie);
    }
}

//--------------------- retrieveClassic -------------------------
// --Used just for Classics movies to find an alternate version
//     of the film that has same title, month, and year but not
//     the same major actor.
// --Uses helper method retrieveClassicHelper.
//---------------------------------------------------------------
Movie* BinTree::retrieveClassicMovie(const Movie* movie)
{
    const Classics* rhsCopy = (const Classics*)movie;
    return retrieveClassicHelper(root, rhsCopy);
}

//--------------------- retrieveClassicHelper -------------------
// --Helper function that finds an alternate version of Classics
//   movie that has same title, month, and year but not the same
//   major actor.
// --Uses Classics isEqual function instead of == operator.
//---------------------------------------------------------------
Movie* BinTree::retrieveClassicHelper(Node*& temp, const Classics* movie) const
{
    // base case 01:
    // item does not exist
    if (temp == nullptr)
    {
        return  nullptr;
    }
    // base case 02:
    // check if root contains the same data, but not same major Actor
    if (movie->isEqual(temp->ptr))
    {
        return temp->ptr;
    }
    // do binary search:
    // if findMovie is less than current->info go left
    else if (*temp->ptr > movie)
    {
        return retrieveClassicHelper(temp->left, movie);
    }
    // findMovie is greater, go right
    else
    {
        return retrieveClassicHelper(temp->right, movie);
    }
}

//---------------------- insert ---------------------------------
// --Inserts a new node containing NodeData into a BinTree.
// --Uses helper function insertHelper.
//---------------------------------------------------------------
bool BinTree::insert(Movie* val)
{
    return insertHelper(this->root, val);
}

//---------------------- insertHelper ---------------------------
// --Helper function to insert
// --If NodeData does not already exsist in tree then it will
//   insert and return true. Does not allow duplicates.
// --If duplicate is found then does nothing and returns false.
//---------------------------------------------------------------
bool BinTree::insertHelper(Node*& temp, Movie* val)
{
    // Insert new node here
    if (temp == nullptr)
    {
        temp = new Node(val);
        return true;
    }
    else if (*temp->ptr > val)
    {
        // Traverse left side of tree
        insertHelper(temp->left, val);
    }
    else if (*val > temp->ptr)
    {
        // Traverse right side of tree
        insertHelper(temp->right, val);
    }
    // Node is already in tree
    return false;
}


//---------------------- displayAll -----------------------------
// --Displays BinTree in order using helper function
//---------------------------------------------------------------
void BinTree::display() const
{
    inorderDisplay(root);
    cout << endl;
}

//---------------------- inorderDisplay--------------------------
// --Helper function for displayAll
// --Prints in order
//---------------------------------------------------------------
void BinTree::inorderDisplay(Node* temp) const
{
    if (temp != nullptr)
    {
        // Traverse left side of tree
        inorderDisplay(temp->left);
        // Print current data
        cout << temp->ptr->createMovie();
        // Traverse right side of tree
        inorderDisplay(temp->right);
    }
}
