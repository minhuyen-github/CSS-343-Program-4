//
//  bintree.cpp
//  Program 4
//
//  Created by Uyen Minh Hoang on 3/13/20.
//  Copyright © 2020 Uyen Minh Hoang. All rights reserved.
//

#include "bintree.h"

//---------------------- BinTree() --------------------
// Description: This is a default constructor which will create an empty BSTree.
// Post-condition: an empty tree is created
//---------------------------------------------------------------
BinTree::BinTree()
{
    this->root = nullptr;
}



//---------------------- ~BinTree() -----------------------------
// Description: This is the destructor which calls makeEmpty to delete a BSTree.
// Post-condition: the tree is properly deleted
//---------------------------------------------------------------
BinTree::~BinTree()
{
    makeEmpty();
}

//---------------------- makeEmpty ------------------------------
// Description: This function deletes an entire BST.
//---------------------------------------------------------------
void BinTree::makeEmpty()
{
    makeEmptyHelper(root); //call helper function
}

//---------------------- makeEmptyHelper ------------------------
// Description: This is the helper function for makeEmpty.
//              It deletes all nodes of a tree and sets every nodes to nullptr.
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
// --------------------------------------------------------------
//bool BinTree::isEmpty() const
//{
//    return (root == nullptr);
//}

//---------------------- retrieve -------------------------------
// Description: This function checks whether or not a NodeData is in a BST.
//              If found, it returns a pointer to that node
//              Else returns nullptr.
// Post-condition: a pointer to the correct Movie object.
//---------------------------------------------------------------
Movie* BinTree::retrieve(const Movie* movie)
{
    return retrieveBST(root, movie);
}

//---------------------- retrieveBST ------------------
// Description: This is the helper function for retrieve. If item is
//              found, will return a pointer to item
//              Else returns nullptr.
// Post-condition: a pointer to the correct Movie object.
// --------------------------------------------------------------
Movie* BinTree::retrieveBST(Node*& temp, const Movie* movie) const
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
        return retrieveBST(temp->left, movie);
    }
    // findMovie is greater, go right
    else
    {
        return retrieveBST(temp->right, movie);
    }
}

//--------------------- retrieveClassicMovie -------------------------
// Description: This function is used just for classic movies to find an alternate version
//              of the film which has same title, month, and year but not
//              the same major actor.
// Post-condition: a pointer to the correct classic movie object
//---------------------------------------------------------------
Movie* BinTree::retrieveClassicMovie(const Movie* movie)
{
    const Classics* rhsCopy = (const Classics*)movie;
    return retrieveClassicHelper(root, rhsCopy);
}

//--------------------- retrieveClassicHelper -------------------
// Description: This is the helper function that finds an alternate version of classic
//              movie that has same title, month, and year but not the same
//              major actor.
// Post-condition: a pointer to the correct classic movie object
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
// Description: This function inserts a new node containing movie
//              info into a BinTree.
// Post-condition: return true if movie info is inserted, return
//                  false if not
//---------------------------------------------------------------
bool BinTree::insert(Movie* val)
{
    return insertHelper(this->root, val);
}

//---------------------- insertHelper ---------------------------
// Description: This is the helper function to insert movie info.
// Post-condition: If NodeData does not already exsist in tree then it will
//                  insert and return true. Duplicates are not allowed.
//                  If duplicate is found then does nothing and returns false.
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


//---------------------- display -----------------------------
// Description: This function displays BST using inorder.
// Post-condition: inorder display of the tree.
//---------------------------------------------------------------
void BinTree::display() const
{
    inorderDisplay(root);
    cout << endl;
}

//---------------------- inorderDisplay--------------------------
// Description: This is the helper function for display
// Post-condition: inorder display of the tree.
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
