


#include <iostream>

#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* Head = NULL;

struct Node* Last = NULL;



void push(int value) {
    //cout << Head << endl;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (!Head) {

        //cout << Head << endl;
        //cout << newNode << endl;
        Head = newNode;

        //cout << Head << endl;
        newNode->next = Head;
        //cout << newNode->next << endl;
        //cout << newNode << endl;
    }
    else {
        struct Node* current = Head;
        
        while (current->next != Head) {
            current = current->next;

            //cout << current << endl;
        }

        newNode->next = Head;
        //cout << newNode << endl;
        current->next = newNode;
        //cout << current << endl;

        Head = newNode;
        //cout << Head << endl;
        
    }
    //cout << value << endl;
    
}


void Josephus(struct Node* start, int kill, int index)
{
    
    struct Node* oBefore = start;
    for (int i = 1; i < kill; i++) {
        oBefore = oBefore->next;
    }


    //cout << oBefore->next->data << "\n\n" ;


    struct Node* oAfter = oBefore->next->next;
    start = oAfter;
    oBefore->next = oAfter;

    /*cout << oBefore->data << endl;
    cout << oAfter->data << '\n' << endl;*/

    //// recursive call for n-1 persons
    if(oAfter != oBefore){
    Josephus(start, kill, index);
    }
    else {
        cout << "the remaining number in the game is: " << oAfter->data << endl;
    }
}


int main()
{
    int n = 41; // specific n and k  values for original
                // josephus problem
    int kill = 3;
    kill--; // (k-1)th person will be killed
    int index
        = 0; // The index where the person which will die

    //vector<int> person;
    // fill the person vector
    for (int i = n; i >= 1; i--) {
        push(i);
        //person.push_back(i);
    }

    Josephus(Head, kill, index);
    
}



