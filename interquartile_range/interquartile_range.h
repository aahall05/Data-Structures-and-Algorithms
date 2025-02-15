/*
    Interquartile Range

    Given a sorted singly linked list without a tail (e.g, head -> 1 -> 2 -> 3 -> 4), 
    return the interquartile range of the data set using the slow and fast pointer 
    approach OR using a methodology that does not iterate over the linked list 
    twice. You must not iterate over the entire linked list more than once and you 
    cannot use arrays, vectors, lists or an STL implementation of List ADT in this problem.

    Sample Input:
        2 4 4 5 6 7 8
    
    Sample Output:
        3.00 
*/

#include <iostream>
#include <iomanip>

class Node {
    public:
        int value;
        Node* next = nullptr;
};

Node* insertEnd(Node* head, int key)
{
    Node* temp = new Node();
    temp->value = key;
    if(head == nullptr)
        head = temp;
    else
    {
        Node* curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

float interQuartile(Node* head)
{
    if (head != NULL) {
        Node* q1, *q2, *q3, *q4;
   
        q1 = head;
        q2 = head->next;
        q3 = head->next->next;
        q4 = head->next->next->next;
        /*while q4 can be advanced, advance all pointers */
        while ((q4->next != NULL) && (q4->next->next != NULL) && (q4->next->next->next != NULL) && (q4->next->next->next->next != NULL)) {
            q1 = q1->next;
            q2 = q2->next->next;
            q3 = q3->next->next->next;
            q4 = q4->next->next->next->next;
        }
    
       /*check for the 4 possible list types then execute appropriate calculation*/
    
    
        if (q4->next == NULL)
        {
            return (float)((((double)q3->value + (double)q3->next->value) / 2.00) - (((double)q1->value + (double)q1->next->value) / 2.00));
        }
        else if (q4->next->next == NULL)
        {
            return (float)(((double)q3->next->value + (double)q3->next->next->value) / 2) - (((double)q1->value + (double)q1->next->value) / 2);
        }
        else if (q4->next->next->next == NULL)
        {
            return (float)((q3->next->next->value) - (q1->next->value));
        }
        else
        {
            return (float)((q3->next->next->next->value) - (q1->next->value));
        }
    }
    else
        return 0.00;
        
}
