/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node*temp = head;
        while(temp){
            Node*a = temp->next;
            if(temp->child!=NULL){
                Node*c = flatten(temp->child);
                temp->next = c;
                c->prev = temp;
                temp->child=NULL;
                while(c->next){
                  
                    c=c->next;
                }
                c->next = a;
                if(a) a->prev = c;
                temp  =a;
            }
            else{
                temp->child = NULL;
                temp = temp->next;
            }
        }
        return head;
        
    }
};