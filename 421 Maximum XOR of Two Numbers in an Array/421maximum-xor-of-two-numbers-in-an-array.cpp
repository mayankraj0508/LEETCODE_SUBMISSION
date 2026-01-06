class Node{
    public:
    Node*left;
    Node*right;
    int data;
    Node(int data){
        this->left =  NULL;
        this->right = NULL;
        this->data  = data;
    }

};
int getMax(int val,Node*head){
    Node*curr = head;
    int cur_xor = 0;
    for(int i =31; i>=0; i--){
       int bits = (val>>i)&1;
       if(bits==0){
        if(curr->right!=NULL){
            cur_xor+=(1<<i);
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
       }
       else{
           if(curr->left!=NULL){
            cur_xor+=(1<<i);
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }

       }
    }
    return cur_xor;
}
void insert(int val,Node*head){
    Node*curr = head;
    for(int i =31; i>=0; i--){
    int bits = (val>>i)&1;
    if(bits==0){
        if(curr->left!=NULL){
            curr = curr->left;

        }
        else{
            Node*temp = new Node(0);
            curr->left = temp;
            curr = curr->left;
        }
    }
    else{
        if(curr->right!=NULL){
            curr = curr->right;
        }
        else{
            Node*temp = new Node(1);
            curr->right = temp;
            curr = curr->right;
        }
    }
    }
}
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Node*head = new Node(-1);
        int ans = 0;
        insert(nums[0],head);
        for(int i=1; i<nums.size(); i++){
            ans  = max(ans,getMax(nums[i],head));
            insert(nums[i],head);

        }
        return ans;
        
    }
};