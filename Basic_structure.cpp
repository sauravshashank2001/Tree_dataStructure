#include<bits/stdc++.h>
using namespace std;
//TreeNode class
class TreeNode{
    public:
    int data;
    vector<TreeNode*> children;
    TreeNode(int data){
        this->data=data;
    }
    
};


//printing the TreeNode

void print(TreeNode *root){
    if(root==NULL){
        return;
    }
    //printing the root data
    cout<<root->data<<"->";
    //printing first level children 
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<" ";
    }
    //changing line
    cout<<endl;
    //going at each and every children of root and repeating the above steps
    for(int i=0;i<root->children.size();i++){
        print(root->children[i]);
    }
}

//Taking input levelwise
TreeNode *takeInput_levelwise(){
    //Taking rootdata as input
    int rootdata;
    cout<<"enter the rootdata;"<<endl;
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    //Making node around it
    TreeNode *root=new TreeNode(rootdata);
    
    //taking a queue to take input levelwise
    queue<TreeNode *> q;
    //pushing root in the queue
    q.push(root);
    
    while(q.size()!=0){
        //accessing the first elem of queue
        TreeNode *front=q.front();
        q.pop();
        //No of child present
        int n;
        cout<<"enter the number of child of"<<front->data<<endl;
        cin>>n;
        //taking input for n no. of child and making TreeNode aroud each child
        for(int i=0;i<n;i++){
            int data;
            cout<<"enter the "<<i<<"th child of "<<front->data<<endl;
            cin>>data;
            TreeNode *newNode=new TreeNode(data);
            //pushing TreeNode into children vector and queue
            front->children.push_back(newNode);
            q.push(newNode);
        }
    }
    return root;
    
}


//main 
int main(){
    TreeNode *root=takeInput_levelwise();
    print(root);
}
