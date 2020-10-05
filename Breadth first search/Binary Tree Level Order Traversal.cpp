/*
 * HAVE TOKEN THE LOGIC IMPLENTATION FROM C++ PRIMER BOOK
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    { vector<vector<int>>ans;
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
     q.push(NULL);vector<int>v;
        while(!q.empty())
        {
            auto node=q.front();q.pop();
         if(node!=NULL)
         {v.push_back(node->val);
             if(node->left){q.push(node->left);}
          if(node->right){q.push(node->right);}
         }
         else
         {
             ans.push_back(v);
             v.resize(0);
             if(!q.empty()){q.push(NULL);}
         }
         
        }
        return ans;
    }
};
