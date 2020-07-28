
/**
* Title: Trees
* Author: Hassam Abdullah
* ID: 21701610
* Assignment: 2
* Description: N-gram Tree .cpp
*/


#include "NgramTree.h"
#include <fstream>
#include <iostream>
#include <math.h>


using namespace std;


/**
//constructor
*/
NgramTree::NgramTree()
{
    root = NULL;
}

/**
//destructor
*/
NgramTree::~NgramTree()
{
    destructor(root);
}

//helper method for the destructor function
void NgramTree::destructor( TreeNode* &treePtr)
{
    //By doing postorder traversal deletes all the tree
    if ( treePtr != NULL)
    {
        destructor(treePtr -> leftPtr);
        destructor(treePtr -> rightPtr);

        delete treePtr;
        treePtr = NULL;
    }
}

/**
 //addNgram method that adds a string into the binary search tree and updates the counter for that node if repeated
*/
void NgramTree::addNgram(string ngram)
{

    TreeNode** parent = NULL;
    TreeNode* curr = root;

    bool repeat = false;

    if ( curr == NULL)
    {
        root = new TreeNode();
        root -> item = ngram;
        root -> count = 1;
    }

    else if (curr != NULL)
    {
        while ( curr != NULL)
        {

            if ( ngram.compare(curr -> item) < 0)
            {
                parent = &(curr -> leftPtr);
                curr = curr -> leftPtr;
            }
            else if (ngram.compare(curr -> item) > 0)
            {
                parent = &(curr -> rightPtr);
                curr = curr -> rightPtr;
            }

            else
            {
                repeat = true;
                (curr -> count)++;
                break;
            }
        }

        if (!repeat)
        {
            *parent = new TreeNode();
            (*parent) -> item = ngram;
            (*parent) -> count = 1;
        }
     }

}

/**
//return the number of nodes or "n-grams" in the binary search tree
*/
int NgramTree::getTotalNgramCount()
{
    int counter = 0;

    getTotalNgramCount( root, counter);

    return counter;
}

/**
//uses preorder transversal to navigate the tree and count the number of nodes or "n-grams"
*/
void NgramTree::getTotalNgramCount( TreeNode* treePtr, int &counter)
{
    //preorder transversal
    if ( treePtr != NULL)
    {
        counter ++;
        getTotalNgramCount( treePtr -> leftPtr, counter);
        getTotalNgramCount( treePtr -> rightPtr, counter);
    }
}

/**
//Gets the height of a specific node in the binary search tree.
//Uses the fact that the height of a node is 1 + maximum of the height of its left child tree or right child tree
*/
int NgramTree::getHeight( TreeNode* treePtr)
{
    int height = 0;

    if ( treePtr != NULL)
    {
        height = 1 + max( getHeight(treePtr -> leftPtr), getHeight(treePtr -> rightPtr));
    }

    return height;
}

/**
//isComplete method that checks if the binary search tree is complete
*/
bool NgramTree::isComplete()
{
    return isComplete(root);
}

/**
//helper method for isCompplete() method
*/

bool NgramTree::isComplete(TreeNode* treePtr)
{
    if ( treePtr != NULL)
    {
        int rHeight = getHeight( treePtr -> rightPtr); //right height
        int lHeight = getHeight( treePtr -> leftPtr); //left height

        if ( lHeight == rHeight)
        {
            if( isFull(treePtr -> leftPtr))
            {
                return isComplete( treePtr -> rightPtr);
            }

            return false;
        }

       else if ( lHeight != rHeight + 1 && lHeight != rHeight )
        {
             return false;
        }


        else
        {
            if ( isFull(treePtr -> rightPtr))
            {
                return isComplete( treePtr -> leftPtr);
            }

            return false;
        }
    }
    return true;
}

/**
isFull method that checks if the binary search tree is full i.e the number of nodes should be equal to 2^(height-1)
*/

bool NgramTree::isFull()
{
    return isFull( root);
}

/**
helper method for isFull() method
*/
//the number of nodes should be equal to 2^(height-1)
bool NgramTree::isFull( TreeNode* treePtr)
{

    if ( root != NULL)
    {
        int counter = 0;
        getTotalNgramCount( treePtr, counter);

        return (counter == (pow( 2, getHeight(treePtr)) - 1));
    }
    return true;
}


/**
//generateTree inputs the strings inside a text file into the nodes of the binary search tree depending on the n value
*/
void NgramTree::generateTree(string fileName, int n)
{
    ifstream file;
    file.open(fileName.c_str());

    string words;

    while (file >> words)
    {
        if (words.length() >= n)
        {
            for (int i = 0; i <= words.length() - n; i++) //combinations of the words
            {
                addNgram(words.substr(i,n));
            }
        }
    }
}



//helper method for ostream operator
void NgramTree::print(ostream& out, TreeNode* treePtr)
{
    if(treePtr == NULL)
    {
        //do nothing
    }
    else if ( treePtr != NULL)
    {
        print(out, treePtr -> leftPtr);

        out << "\"" << treePtr -> item << "\" " << "appears " << treePtr -> count << " time(s)" << endl;

        print(out, treePtr -> rightPtr);
    }
}

ostream& operator << ( ostream& out, NgramTree& tree )
 {
     tree.print(out, tree.root);
     return out;
 }






