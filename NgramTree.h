
/**
* Title: Trees
* Author: Hassam Abdullah
* ID: 21701610
* Assignment: 2
* Description: N-gram Tree header
*/

#include <iostream>

#ifndef NGT_H
#define NGT_H

using namespace std;



class NgramTree
{

    struct TreeNode{
        string item;
        TreeNode *leftPtr, *rightPtr;
        int count;

        TreeNode(){
         item = "";
        leftPtr = NULL;
        rightPtr = NULL;
        count = 0;
        }

        };

public:
    NgramTree();
    ~NgramTree();

    void addNgram(string ngram);
    int getTotalNgramCount();
    void printNgramFrequencies();
    int getHeight( TreeNode* treePtr);
    bool isFull();
    void generateTree(string fileName, int n);
    void print(ostream& out, TreeNode* treePtr);
    bool isComplete();


private:

    //helper methods for recursion
    void getTotalNgramCount( TreeNode* treePtr, int &count);
    void printNgramFrequencies( TreeNode* treePtr);
    bool isComplete( TreeNode* treePtr);
    bool isFull( TreeNode* treePtr);
    //helper method for destructor
    void destructor( TreeNode* &treePtr);
    friend ostream& operator <<( ostream& out, NgramTree& tree );

    TreeNode* root;
};




#endif
