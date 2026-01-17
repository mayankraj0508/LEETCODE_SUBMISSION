class Solution {
public:
  
    void dfs(Node* p, Node* curr, unordered_map<Node*, Node*>& mp){
        for(auto neighbour : curr->neighbors){

            // agar neighbour ka clone pehle se bana hai
            if(mp.find(neighbour) != mp.end()){
                p->neighbors.push_back(mp[neighbour]);
            }
            else{
                Node* t = new Node(neighbour->val);
                mp[neighbour] = t;
                p->neighbors.push_back(t);
                dfs(t, neighbour, mp);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }

        Node* p = new Node(node->val);
        unordered_map<Node*, Node*> mp;
        mp[node] = p;

        dfs(p, node, mp);
        return p;
    }
};
