#include "llrec.h"

using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    
    if (head == NULL){
        smaller = NULL;
        larger = NULL;
        return;
    }
    else {
        llpivot(head->next,smaller,larger,pivot);
        Node* curr = head;
        Node* temp;
        if (curr->val <= pivot){
            temp = smaller;
            smaller = curr;
            smaller->next = temp;
            curr = NULL;
        }
        else {
            temp = larger;
            larger = curr;
            larger->next = temp;
            curr = NULL;
        }
    }
    head = NULL;
    
    /*
    if (head == NULL){
        smaller = NULL;
        larger = NULL;
        return;
    }
    else {
        if (head->val <= pivot){
            smaller = head;
            llpivot(head->next, smaller->next, larger, pivot);
        }
        else {
            larger = head;
            llpivot(head->next, smaller,larger->next, pivot);
        }
    }
    */
    
    /*
    if (head != nullptr){
        if (head->val <= pivot){
            smaller = head;
            //smaller->next = NULL;
            //larger = NULL;
            llpivot(head->next, smaller->next, larger, pivot);
        }
        else if (head->val > pivot){
            larger = head;
            //larger->next = NULL;
            //smaller = NULL;
            llpivot(head->next, smaller, larger->next, pivot);
        }

    }
    else {
        head = nullptr;
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    */
}


