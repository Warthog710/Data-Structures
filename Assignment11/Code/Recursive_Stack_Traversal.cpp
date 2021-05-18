//Based on code by Professor Ross. Modified by Quinn Roemer.
#include <iostream>
#include <string>

using namespace std;

int graph[8][8] = {
    0, 1, 1, 1, 0, 0, 1, 0, //A
    1, 0, 1, 0, 1, 0, 1, 0, //B
    1, 1, 0, 0, 0, 1, 0, 1, //C
    1, 0, 0, 0, 0, 1, 0, 0, //D
    0, 1, 0, 0, 0, 0, 0, 1, //E
    0, 0, 1, 1, 0, 0, 1, 1, //F
    1, 1, 0, 0, 0, 1, 0, 1, //G
    0, 0, 1, 0, 1, 1, 1, 0  //H
};
// A B C D E F G H

// where I've been
bool visited[] = {false, false, false, false, false, false, false, false};

// the resulting tree. Each node's parent is stored
int tree[] = {-1, -1, -1, -1, -1, -1, -1, -1};

//Function Prototypes.
void traverse(int);
void printNode(int);
void printTree();

int main()
{
    cout << "Traversal path:" << endl;
    //Calling traverse: Starter node = A.
    traverse(0); //Printing the resulting tree.
    printTree();
}

void traverse(int startValue)
{
    int nextNode = 0;
    visited[startValue] = true;

    //Printing the current node.
    printNode(startValue);

    //Finding an unvisited node to go to next.
    while (nextNode < 8)
    {
        if (visited[nextNode] == false && graph[startValue][nextNode] == 1)
        {
            //Recording the parent of this node.
            tree[nextNode] = startValue;

            //Recursively calling traverse.
            traverse(nextNode);
        }

        nextNode++;
    }
}

void printTree()
{
    char letter = 'A';
    char parent;

    cout << "\nThe resulting tree:" << endl << endl;
    cout << "Node \t\t Parent" << endl;

    for (int i = 0; i < 8; i++)
    {
        parent = tree[i] + 'A';

        if (parent == '@')
        {
            parent = ' ';
        }

        cout << " " << letter << "\t\t " << parent << endl;
        letter++;
    }
}

void printNode(int startValue)
{
    char letter = startValue + 'A';
    cout << letter << endl;
}
