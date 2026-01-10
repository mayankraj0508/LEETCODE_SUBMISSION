/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int minr = 0;
        int minc = 0;
        int maxr = m-1;
        int maxc = n-1;
        ListNode*temp = head;
        vector<vector<int>>v(m,vector<int>(n,-1));
        while(temp!=NULL&&minr<=maxr&&minc<=maxc){
            for(int j = minc; j<=maxc; j++){
                 if(temp==NULL){
                    break;
                }
                v[minr][j]=temp->val;
                temp = temp->next;
            }
            minr++;
            if(temp&&minr<=maxr){
            for(int  i = minr; i<=maxr; i++){
                 if(temp==NULL){
                    break;
                }
                v[i][maxc]=temp->val;
                temp = temp->next;
            }
            maxc--;
            }
            if(temp&&minc<=maxc){
            for(int j = maxc; j>=minc; j--){
                 if(temp==NULL){
                    break;
                }
                v[maxr][j]=temp->val;
                temp = temp->next;
            }
            maxr--;
            }
            if(temp&& minr<=maxr){
            for(int i = maxr; i>=minr; i--){
                if(temp==NULL){
                    break;
                }
                v[i][minc]=temp->val;
                temp = temp->next;
            }
            minc++;
            }
        }
        return v;
        
    }
};