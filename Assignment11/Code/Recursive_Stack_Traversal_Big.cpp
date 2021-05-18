//Based on code by Professor Ross. Modified by Quinn Roemer.
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

//Struct holds stacks so that they can be saved for later use..
struct stackSave
{
    stack<int> savedStack;
    int size = 0;
};

//Graph Array.
int graph[100][100];

//Visited Array.
bool visited[100];

//The resulting tree is stored here.
int tree[100];

//Stack used to store longest sequence.
stackSave biggestStacks[100];
stack<int> sequence;
int maxSize[100] = {0};
int counter = 0;
int maxVal = 0;
int saveOrder = 0;
int OutCount = 0;

//Function prototypes.
void loadGraph();
void traverse(int);
void printNode(int);
void printTree();
void saveStack();
void printStack();

int main()
{
    //Intilizing visited and tree.
    for (int count = 0; count < 100; count++)
    {
        visited[count] = false;
        tree[count] = -1;
    }

    //Intilizing the graph.
    loadGraph();

    cout << "Traversal path:" << endl << endl;

    //Calling traverse: Starter node = A;
    traverse(0);

    //Printing the resulting tree.
    printTree();

    //Printing the longest sequence.
    printStack();
}

void loadGraph()
{
    //Loading file.
    string line;
    int index = 0;
    ifstream myfile;

    //Opening file.
    myfile.open("bigGraph.txt");

    //Reading until end of file.
    while (myfile.peek() != EOF)
    {
        getline(myfile, line);

        for (int count = 0; count < 100; count++)
        {
            graph[index][count] = line[count] - '0';
        }

        index++;
    }

    //Closing file.
    myfile.close();
}

void traverse(int startValue)
{
    //Incrementing counter.
    counter++;

    //Pushing the startValue.
    sequence.push(startValue);

    //If counter is larger than the recorded max this code executes.
    if (counter > maxVal)
    {
        //Calling saveStack and setting the new max.
        saveStack();
        maxVal = counter;
    }

    int nextNode = 0;
    visited[startValue] = true;

    //Printing the current node.
    printNode(startValue);

    //Finding an unvisited node to go to next.
    while (nextNode < 100)
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

    //Decrementing counter.
    counter--;
    //Removing top element from stack. sequence.pop();
}

void printTree()
{
    //This function prints the resulting tree.
    int parent;
    int counterLow = 0;
    int counterHigh = 50;

    cout << "\n\nThe resulting tree:" << endl << endl;
    cout << "Node\t\t Parent\t\tNode\t\tParent" << endl;

    for (int i = 0; i < 50; i++)
    {
        parent = tree[counterLow];

        if (parent == -1)
        {
            cout << " " << counterLow << "\t\t";
        }
        else
        {
            cout << " " << counterLow << "\t\t " << parent;
        }

        parent = tree[counterHigh];

        if (parent == -1)
        {
            cout << " " << counterHigh << endl;
        }
        else
        {
            cout << " \t\t " << counterHigh << "\t\t " << parent << endl;
        }

        counterHigh++;
        counterLow++;
    }
}

void printNode(int startValue)
{
    if (OutCount < 5)
    {
        printf("%3d ", startValue);
        OutCount++;
    }
    else
    {
        printf("\n%3d ", startValue);
        OutCount = 1;
    }
}

void saveStack()
{
    biggestStacks[saveOrder].size = sequence.size();
    biggestStacks[saveOrder].savedStack = sequence;
    saveOrder++;
}

void printStack()
{
    int size = -1;
    int place;
    biggestStacks;
    OutCount = 0;

    //Finding the biggest saved stack.
    for (int count = 0; count < 100; count++)
    {
        if (biggestStacks[count].size > size)
        {
            place = count;
            size = biggestStacks[count].size;
        }
    }

    //Printing the sequence and size.
    cout << "\nLongest sequence: size = " << biggestStacks[place].savedStack.size();
    cout << endl << endl;

    //Printing stack.
    while (!biggestStacks[place].savedStack.empty())
    {
        if (OutCount < 5)
        {
            printf("%3d ", biggestStacks[place].savedStack.top());
            OutCount++;
        }
        else
        {
            printf("\n%3d ", biggestStacks[place].savedStack.top());
            OutCount = 1;
        }

        biggestStacks[place].savedStack.pop();
    }

    cout << endl << endl;
}