#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int key;
    node*left;
    node*right;
};
int max_level=0;
void insert(node**root,int n){
    node* temp=new node;
    
    if(*root==NULL){
        (temp)->key=n;
        temp->left=NULL;
        temp->right=NULL;
        (*root)=temp;
        return;
    }
    if((*root)->key>n)
        insert(&(*root)->left,n);
    else if((*root)->key<n){
        insert(&(*root)->right,n);}
        else {
            cout<<"duplicate element"<<endl;
        }
        return ;
}
void inorder(node*root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}
void preorder(node*root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node*root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}
int find_height(node*root){
        if(root==NULL)
        return 0;
        return max(find_height(root->left),find_height(root->right))+1;
}
void print_k(node*root,int k){
    if(root==NULL)
    return ;
    if(k==0)
    cout<<root->key;
    print_k(root->left,k-1);
    print_k(root->right,k-1);
}
void level_order(node* root)
 {
    if(root==NULL)
    return ;
    queue<node*>q;
    q.push(root);
    while(q.empty()==false){
        node* current =q.front();
        cout<<current->key<<" ";
        q.pop();
        if(current->left!=NULL)
        {
            q.push(current->left);
        }
        if(current->right!=NULL){
            q.push(current->right);
        }
    }
}
void leve_lbl(node*root){
    if(root==NULL)
    return ;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        node*current=q.front();
        q.pop();
        if(current==NULL){
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<current->key<<" ";
        if(current->left!=NULL)q.push(current->left);
        if(current->right!=NULL)q.push(current->right);
    }
}
int iterative_size(node*root){
    if(root==NULL)
    return 0;
    queue<node*>q;
    q.push(root);
    int count=1;
    q.push(NULL);
    while(q.size()>1){
        node*current=q.front();
        q.pop();
        if(current==NULL){
            q.push(NULL);\
            continue;
        }
        count++;
        if(current->left!=NULL)q.push(root->left);
        if(current->right!=NULL)q.push(root->right);
    }
    return count;
}
int rec_size(node*root){
    if(root==NULL)
    return 0;
    return 1+rec_size(root->left)+rec_size(root->right);
    
}
int find_max(node*root)
{
    if(root==NULL)
    return INT_MIN;
    return max(root->key,max(find_max(root->left),find_max(root->right)));
}
void printleft(node*root,int level){
    if(root==NULL)
    return ;
    if(max_level<level){
        cout<<root->key<<" ";
        max_level=level;
    }
    printleft(root->left,level+1);
    printleft(root->right,level+1);
}
void printleftview(node*root){
    printleft(root,1);
}
int main()
{
    node*root=NULL;
    int ch,k,ab,x,y,z,m;
   
  //  cin>>ch;
    do
    {
         cout<<"enter 1 to insert \n2 to print inorder\n3 to print in preorder\n4 to print in postorder\n5 to find height\n6 to print k elements\n7 level order traversal\n8 forlevel order line by line traversal"<<endl;
         cout<<"enter 9 to print size\nenter 10 to print max\n11 for printing left view\n"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
            int n;
            cout<<"enter the value to insert"<<endl;
            cin>>n;
            insert(&root,n);
            break;
            case 2:
            inorder(root);
            break;
            case 3:
            preorder(root);
            break;
            case 4:
            postorder(root);
            break;
            case 5:
            ab=find_height(root);
            cout<<"height->"<<ab<<endl;
            break;
            case 6:
            cout<<"enter the k element"<<endl;
            cin>>k;
            print_k(root,k);
            break;
            case 7:
            level_order(root);
            case 8:
            leve_lbl(root);
            break;
            case 9:
            cout<<"enter 1 to find iterative \n2 to find recursively"<<endl;
            cin>>x;
            if(x==1){
                z=iterative_size(root);
                cout<<z<<endl;
            }
            else{
                y=rec_size(root);
                cout<<y<<endl;
            }
            break;
            case 10:
            m=find_max(root);
            cout<<m<<endl;
            break;
            case 11:
            printleftview(root);
        }
    }while(ch<12);
}


