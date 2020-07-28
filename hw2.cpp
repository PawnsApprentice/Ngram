
/**
* Title: Trees
* Author: Hassam Abdullah
* ID: 21701610
* Assignment: 2
* Description: N-gram Tree main function
*/

#include "NgramTree.h"
#include <stdlib.h>

// main function
int main(int argc, char **argv)
{
    NgramTree tree;
    string fileName(argv[1]);
    int n = atoi(argv[2]);
    tree.generateTree(fileName, n);

    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;


      cout<<tree<<endl;

    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;

    //Before insertion of new n-grams

    cout<< n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;

    tree.addNgram("samp");

    tree.addNgram("samp");
    tree.addNgram("zinc");
    tree.addNgram("aatt");

    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;

    cout<<tree<< endl;

    cout<< n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;

    cout<< n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;

    return 0;
}


