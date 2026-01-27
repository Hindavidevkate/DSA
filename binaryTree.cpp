#include <iostream> 
#include<queue>
#include <vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
    
};
    static int idx = -1;
    Node* buildTree(vector<int> preOrder){
        idx++;
        Node* root = new Node(preOrder[idx]);
        if(preOrder[idx] == -1){
            return NULL ;
        }
        root -> left = buildTree(preOrder);
        root -> right = buildTree(preOrder);
        return root;
    }

    void pretraversal(Node* root){
        if(root == NULL){
            return;
        }
        cout<<root -> data<<"   ";
        pretraversal(root -> left );
        pretraversal(root -> right);
        
    }
    void inorder(Node* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        cout<<root -> data<<"   ";
        inorder(root -> right);
        
    }
    void postorder(Node* root){
        if(root == NULL){
            return;
        }
        postorder(root->left );
        postorder(root->right);
        cout<<root-> data<<"   ";
        
    }
    //This function return level wise values 
    void levelOrder(Node* root){
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(q.size() > 0){
            Node* curr = q.front();
            q.pop();
            
            
            if(curr == NULL){
                if(!q.empty()){
                    cout<<endl;
                    q.push(NULL);
                    continue;
                }
                else{
                    break;
                }
            }
            cout<<curr -> data<<"   ";
            if(curr -> left !=NULL){
                q.push(curr -> left);
            }
            if(curr -> right != NULL){
                q.push(curr -> right);
            }

        }
        cout<<endl;

    }

    // This is the Problem to calculate height of the binary tree
    int heightBT(Node* root){
        if(root == NULL)return 0;
        int lh = heightBT(root -> left);
        int rh = heightBT(root -> right);
        return max(lh,rh) + 1;
    }

    //This function return count of nodes
    int count(Node* root){
        if(root == NULL)return 0;
        int lc = count(root -> left);
        int rc = count(root -> right);

        return lc+ rc + 1;
    }
    int sum(Node* root){
        if(root == NULL)return 0;
        int ls = sum(root -> left);
        int rs = sum(root -> right);

        return ls+ rs + (root -> data);
    }
int main(){
    vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preOrder);
    cout<<"Root :"<<root -> data<<endl;
    cout<<"Left :"<<root-> left ->data<<endl;
    cout<<"Right :"<<root -> right->data<<endl;
    cout<<"Pre-Order : ";
    pretraversal(root);
    cout<<endl;
    cout<<"In-Order :";
    inorder(root);
    cout<<endl;
    cout<<"Post-Order :";
    postorder(root);
    cout<<endl;
    cout<<"Level Order Traversal  : \n";
    levelOrder(root);
    cout<<endl;
    cout<<"Height of Tree: ";
    cout<<heightBT(root);
    cout<<endl;
    cout<<"Count of Nodes ";
    cout<<count(root);
    cout<<endl;
    cout<<"Sum of Nodes : ";
    cout<<sum(root);
    return 0;
}