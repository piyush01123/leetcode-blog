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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
    {
        int i=0, j=0, di=0, dj=1;
        vector<vector<int>> M(m, vector<int>(n,-1));
        while(head)
        {
            M[i][j] = head->val;
            head = head->next;
            if (i+di<0 || i+di>=m || j+dj<0 || j+dj>=n || M[i+di][j+dj]!=-1)
            {
                int temp=di;
                di=dj;
                dj=-temp;
            }
            i+=di;
            j+=dj;
        }
        return M;
    }
};