#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// https://www.codingninjas.com/studio/problems/flatten-the-multi-level-linked-list_839810?leftPanelTab=1
// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) return head;
        Node *curr = head;
        while(curr != NULL){
            if(curr->child != NULL){
                Node *next = curr->next;
                curr->next = NULL;
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = NULL;
                Node *temp = curr->next;
                while(temp->next != NULL) temp = temp->next;
                if(next != NULL)temp->next = next;
                if(next != NULL) next->prev = temp;
            }
            curr = curr->next;
        }
        return head;
    }
};



//codestudio
template <typename T = int>

    class Node2 {
      public:
        T data;
        Node2<T> *next;
        Node2<T> *child;

        Node2(T data) {
            this->data = data;
            next = NULL;
            child = NULL;
        }
    };


Node2<int> *flattenMultiLinkedList(Node2<int> *head) {
    // Write your code here.
    if(head == NULL) return head;
    Node2<int>*res = new Node2<int>(-1);
    Node2<int> *curr = res;
    queue<Node2<int>*> qu;
    // qu.push(head);
    Node2<int> *temp = head;
    while(temp != NULL){
        curr->next = temp;
        curr = curr->next;
        if (temp->child != NULL) {
          qu.push(temp->child);
          temp->child = NULL;
        }
        temp = temp->next;
    }
    while(!qu.empty()){
        int size = qu.size();
        for(int i = 0;i<size;i++){
            Node2<int> *node = qu.front();
            qu.pop();
            temp = node;
            while(temp != NULL){
                curr->next = temp;
                curr = curr->next;
                if(temp->child != NULL){
                    qu.push(temp->child);
                    temp->child = NULL;
                }
                temp = temp->next;
            }
        }
    }
    return res->next;

}

//gfg



struct Node3{
	int data;
	struct Node3 * next;
	struct Node3 * bottom;
	
	Node3(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};


/*  Function which returns the  root of 
    the flattened linked list. */
Node3 * merge(Node3 *fir,Node3 *sec){
    Node3 *res = new Node3(-1);
    Node3 *curr = res;
    while(fir != NULL && sec != NULL){
        if(fir->data<sec->data){
            curr->bottom = fir;
            curr = curr->bottom;
            fir = fir->bottom;
        }
        else{
            curr->bottom = sec;
            curr = curr->bottom;
            sec = sec->bottom;
        }
    }
    if(fir != NULL) curr->bottom = fir;
    if(sec != NULL) curr->bottom = sec;
    return res->bottom;
}
Node3 *flatten(Node3 *root)
{
   // Your code here
    if(root == NULL) return root;
    Node3 *first = root;
    Node3 *second = root->next;
    while(second != NULL){
        first = merge(first,second);
        second = second->next;
    }
    return first;
}