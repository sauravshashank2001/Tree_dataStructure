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



//Height of the Tree
int height(TreeNode *root){
    if(root==NULL){
        return 0;
        
    }
    int height_of_tree=0;
    for(int i=0;i<root->children.size();i++){
        int smallHeight=height(root->children[i]);
        height_of_tree=max(smallHeight,height_of_tree);
    }
    return height_of_tree+1;
    
}

//sum_of_all_node_in_a_tree

int sum_of_all_node_(TreeNode *root){
    if(root==NULL){
        return 0;
        
    }
    int small_sum=0;
    for(int i=0;i<root->children.size();i++){
        small_sum+=sum_of_all_node_(root->children[i]);
    }
    return small_sum+root->data;
}


//count_no_of_nodes_in_a_tree

int no_of_nodes(TreeNode *root){
    if(root==NULL){
        return 0;
    }
    int small_count=0;
    for(int i=0;i<root->children.size();i++){
        small_count+=no_of_nodes(root->children[i]);
    }
    return small_count+1;
}

//Maximum_of_all_node


int max_value_node(TreeNode *root){
    if(root==NULL){
        return 0;
    }
    int max_value=INT_MIN;
    for(int i=0;i<root->children.size();i++){
        int small_max=max_value_node(root->children[i]);
        max_value=max(max_value,small_max);
    }
    return max(root->data,max_value);
}

//print_k_level_nodes

void print_k_level_nodes(TreeNode *root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    for(int i=0;i<root->children.size();i++){
      print_k_level_nodes(root->children[i],k-1);
    }
    
}


//count_leaf_nodes

int count_leaf_nodes(TreeNode *root){
    if(root==NULL){
        return 0;
    }
    if(root->children.size()==0){
        return 1;
    }
    int small_count=0;
    for(int i=0;i<root->children.size();i++){
         small_count+=count_leaf_nodes(root->children[i]);
    }
    return small_count;
}

//print_leaf_node

void print_leaf_node(TreeNode *root){
    if(root==NULL){
        return;
    }
    if(root->children.size()==0){
        cout<<root->data<<" ";
        return;
    }
    for(int i=0;i<root->children.size();i++){
        print_leaf_node(root->children[i]);
        
    }
}

//Tree Traversal.......................

//1.PreOrder_Traversal

void PreOrder_Traversal(TreeNode *root){
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        PreOrder_Traversal(root->children[i]);
    }
    
    
    
    
}


//2.Post_Order_Traversal

void Post_Order_Traversal(TreeNode *root){
    if(root==NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        Post_Order_Traversal(root->children[i]);
    }
    cout<<root->data<<" ";
    
}


//Node_present_or_not

bool isNodePresent(TreeNode *root,int x){
    bool small;
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        small= true;
        return small;
    }
    bool ans=false;
    for(int i=0;i<root->children.size();i++){
        small=isNodePresent(root->children[i],x);
    }
    return small==1;
}

//main 
int main(){
    TreeNode *root=takeInput_levelwise();
    //operation call
}


