class Node{
    public:
    Node* link[2];
    bool ispresent(int bit){
        return link[bit] != NULL;
    }
    void insert(int bit,Node* node){
        link[bit] = node;
    }
    Node* getnext(int bit){
        return link[bit];
    }
};


class Solution {
public:
    Node* root;
    Solution(){
        root = new Node();
    }
    int findMaximumXOR(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int g = nums[i];
            Node* node = root;
            for(int i=31;i>=0;i--){
                int bit = (g>>i) & 1;
                if(!node->ispresent(bit)){
                    node->insert(bit,new Node());
                }
                node = node->getnext(bit);
            }
        }
        int result = 0;
        for(int i=0;i<nums.size();i++){
            int g = nums[i];
            Node *node = root;
            int ans = 0;
            for(int i=31;i>=0;i--){
                int bit = (g>>i) & 1;
                if(node->ispresent(1-bit)){
                    ans += 1<<i;
                    node = node->getnext(1-bit);
                }
                else{
                node = node->getnext(bit);
                }
            }
            result = max(ans,result);
        }
        return result;
    }
};