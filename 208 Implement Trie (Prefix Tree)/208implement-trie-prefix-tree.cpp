class Node{
    public:
    char data;
    bool isTerminal;
    unordered_map<char,Node*>children;
    Node( char data){
        this->data = data;
        isTerminal = false;

      
    }
    void makeTerminal(){
        isTerminal = true;
    }
    bool aTerminal(Node*curr){
        return curr->isTerminal==true;
    }

};


class Trie {
public:
    Node*root;
    Trie() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node*curr = root;
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(curr->children.find(ch)!=curr->children.end()){
                curr = curr->children[ch];
            }
            else{
                Node*temp = new Node(ch);
                curr->children[ch] = temp;
                curr = curr->children[ch];
            }
        }
        curr->makeTerminal();
        
    }
    
    bool search(string word) {
        Node*curr = root;
        for(int i =0; i<word.size(); i++){
            char ch = word[i];
            if(curr->children.find(ch)!=curr->children.end()){
                curr = curr->children[ch];
            }
            else{
                return false;
            }
        }
        return  curr->aTerminal(curr);
        
    }
    
    bool startsWith(string prefix) {
         Node*curr = root;
        for(int i =0; i<prefix.size(); i++){
            char ch = prefix[i];
            if(curr->children.find(ch)!=curr->children.end()){
                curr = curr->children[ch];
            }
            else{
                return false;
            }
        }
        return true;

        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */