class Node{
    public:
        Node* left;
        Node* right;
        Node(){
            this->left = this->right = NULL;
        }
};
class Solution {
public:
    int maxPair(Node* head, int val){
        Node* curr = head;
        int res = 0;
        for(int i =31; i>=0; i--){
            int bit = (val>>i)&1;
            if(bit == 0){
                if(curr->right!=NULL){
                    curr = curr->right;
                    res += (1<<i);
                }
                else{
                    curr = curr->left;
                }
            }
            else{
                if(curr->left!=NULL){
                    curr = curr->left;
                    res += (1<<i);
                }
                else{
                    curr = curr->right;
                }
            }
        }
        return res;
    }
    void insert(Node* head, int val){
        Node* curr = head;
        int res = 0;
        for(int i =31; i>=0; i--){
            int bit = (val>>i)&1;
            if(bit == 0){
                if(curr->left == NULL){
                    curr->left = new Node();
                }
                curr = curr->left;
            }
            else{
                if(curr->right == NULL){
                    curr->right = new Node();
                }
                curr = curr->right;
            }
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Node* head = new Node();
        insert(head, nums[0]);
        int ans = INT_MIN;

        for(int i=0;i<n;i++){
            ans = max(ans, maxPair(head,nums[i]));
            insert(head, nums[i]);
        }
        return ans;
    }
};
