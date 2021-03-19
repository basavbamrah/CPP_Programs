/**
 * @file Class_linkedList.cpp
 * @author Basav Bamrah
 * @brief Creating a Linked list, traversal, adding, deleting,find data
 * @version 0.1
 * @date 2020-10-18
 * 
 */

#include <iostream>
using namespace std;

class Node // Node class for nodes of linked list
{
public:
    int data;   // store data
    Node *next; // pointer object to store the address of next node
};              // class node

Node *head = new Node; // head node very first node of linked list
int n;                 // total number of nodes

void traverse() // function for Travarsal of the linked list
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "  ";
        ptr = ptr->next; // traversing the list
    }
}

Node *newNode(int data) // function to create new node for the existing list
{
    Node *nptr = new Node;
    nptr->data = data;
    nptr->next = NULL;
    return nptr;
} // newNode

void addNode(int pos, int num) // function to add a new node to the list
{
    Node *nptr = newNode(num);
    Node *ptr = head;
    if (pos == 1) // Add a new node at the first
    {
        nptr->next = head;
        head = nptr;
    }
    else if (pos > n) // Add a node at the last
    {
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = nptr;
    }
    else // Add a node int the middle of the list
    {
        int t = 1;
        while (pos - 1 != t)
        {
            ptr = ptr->next;
            t++;
        }
        nptr->next = ptr->next;
        ptr->next = nptr;
    }
    n++;
} // addNode

void delNode(int pos) // Delete an existing node
{
    Node *ptr = head;
    int t = 1;
    if (pos == 1) //delete 1st node
        head = head->next;
    else if (pos >= n) // delete last node
    {
        while (pos - 1 != t++)
            ptr = ptr->next;
        ptr->next = NULL;
    }
    else // delete node in between
    {
        while (pos - 1 != t++)
            ptr = ptr->next;
        ptr->next = ptr->next->next;
    }

    n--;
} //delNode

void findData(int s) // function to search an element using linear search concept
{
    Node *ptr = head;
    int x = 0; // flag variable
    while (ptr != NULL)
    {
        if (ptr->data == s)
        {
            cout << "found" << endl;
            x = 1;
        }
        ptr = ptr->next;
    }
    if (x == 0)
        cout << "Not found" << endl;
}

int main()
{
    Node *ptr = head;

    cout << "\nEnter the number of nodes to be created: \n";
    cin >> n;
    cout << "Enter a number:\n";
    int num;
    cin >> num;
    head->data = num;
    for (int i = 1; i <= n - 1; i++)
    {
        cout << "Enter a number:\n";
        cin >> num;
        Node *nptr = newNode(num); // creating the list
        ptr->next = nptr;
        ptr = nptr;
    }
    cout << "LIST HAS :\n";
    traverse();

    int pos, ch = 0;
    cout << "\nIf You want to Insert a new Node Press 1 else 0:\n"; // choice to add node
    cin >> ch;

    while (ch == 1)
    {

        cout << "Enter the number to be added and position :\n";
        cin >> num >> pos;
        addNode(pos, num);
        cout << "Press 1 to continue and 0 to exit:\n";
        cin >> ch;
    }

    cout << "LIST AFTER Adding node:\n";
    traverse();

    cout << "\nIf You want to Delete a new Node Press 1 else 0:\n"; //choice delete node
    cin >> ch;
    while (ch == 1)
    {
        cout << "Enter the pos of the node you want to delete:\n";
        cin >> pos;
        delNode(pos);
        cout << "Press 1 to continue and 0 to exit:\n";
        cin >> ch;
    }

    cout << "Enter the element to be searched:\n";
    cin >> ch;
    findData(ch);

    cout << "FINAL LIST\n";
    traverse();
    cout<<endl;
    return 0;
} // main