/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       /* //create the deep copy without assigning the reandom pointer
        Node*c = new Node(100);
        Node*tempc = c;
        Node*temp = head;
        while(temp){
            Node*a = new Node(temp->val);
            tempc->next = a;
            tempc = tempc->next;
            temp = temp->next;

        }
        //make alternate connection means
        //merge both original and co-pied linked list 

        c  = c->next;
        Node*a = head;
        Node*b = c;
        Node*alpha  = new Node(50);
        Node*al = alpha;
        while(a!=NULL){
            al->next = a;
            al = al->next;
            a = a->next;
            al->next = b;
            al = al->next;
            b = b->next;
            al->next = a;
            al = al->next;
            if(a){
            a = a->next;
            }
        }
        alpha = alpha->next;
        //making alternate arando conmnnectrion
        Node*t1 = alpha;
        Node*t2 ;
        while(t1!=NULL){
            t2= t1->next;
            if(t1->random!=NULL){
                t2->random  = t1->random->next;
                t1= t1->next->next;
              
            }


        }
        //removing  connection or separating the connection/list
        Node*d1 = new Node(-1);//original
        Node*tempd1 = d1;
        Node*d2 = new Node(-2);//duplicate wala store hoga
        Node*tempd2 = d2;
        Node*t = alpha;
        while(t){
            tempd1->next = t;
            t = t->next;
            tempd1 = tempd1->next;
            tempd2->next = t;
            t = t->next;
            tempd2 = tempd2->next;

        }
        tempd1->next = NULL;
        tempd2->next = NULL;
        d1 = d1->next;
        d2 = d2->next;
        return d2;*/
        
        //USING HASHMAP
        //CREATING DEEP COPY
        Node*c = new Node(100);
        Node*tempc = c;
        Node*temp = head;
        while(temp){
            Node*P = new Node(temp->val);
            tempc->next = P;
            tempc = tempc->next;
            temp = temp->next;

        }
        Node*b= c->next;
        Node*a = head;
        unordered_map<Node*,Node*>m;
        Node*tempa = a;
        Node*tempb = b;
        while(tempa){
            m[tempa] = tempb;
            tempa = tempa->next;
            tempb = tempb->next;

        }
        for(auto x: m){
            if(x.first->random){
            Node*l = x.first->random;
            Node*r = x.second;
            Node*alpha = m[l];
            r->random = alpha;
            }
        }
        return b;


    


         



        
        
    }
};