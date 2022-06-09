#include <iostream>
#include<math.h>

using namespace std;
class Node {
public :
int data;
Node *left,*right;
Node(int x ){
data=x;
left=right=NULL;
}
};
class queue{
public:
   int front,rear;
Node *arr[30];

queue(){
front =rear=0;
}

void push(Node *a){
if(rear>=30){
cout<<"queue is overflowed\n";

}
  else{
  arr[rear]=a;
  rear++;
  }
}
Node *pop(){
if(front ==rear){
cout<<"queue is empty\n";
return 0;
}
else{

                return(arr[front++]);
}

}
Node *peek(){
if(front==rear){
cout<<"queue is empty\n";
}
else{
               return (arr[front]);
}

}
int size(){
if(front =rear){
return 0;
}
else return ((rear-front)+1);
}
bool isEmpty(){
return (front==rear);
}

};
class BST{
public :
Node *root;
BST(){
root=NULL;
}

Node *rootval(){
return root;
}

void insert(int x){
Node *temp = new Node(x);
root=create(root,temp);

}
Node *create(Node *root,Node *temp){

if(root==NULL){
return temp;
}

if(temp->data<root->data){
root->left=create(root->left,temp);
}
else{
root->right=create(root->right,temp);
}
return root;
}
void insert_non_rec(Node *root,int key){
Node *temp = new Node(key);

Node *cur=root;
Node *par=NULL;

if(root==NULL){

root=temp;

return;
}
while(cur!=NULL){

par=cur;
if(key<cur->data){
cur=cur->left;
}
else{
cur=cur->right;
}
}
if(key<par->data){
par->left=temp;
}
else{
par->right=temp;
}
}

void inorder(Node *t){
if(t!=NULL){

inorder(t->left);
cout<<" "<<t->data;
inorder(t->right);
}
}
int search_non_rec(Node *root,int key){
if(root==NULL){
return 0;
}
Node *cur=root;
Node *par=NULL;
while(cur!=NULL){
par =cur;
if(key==cur->data){
return 1;
}
if(key<cur->data){
cur=cur->left;
}
else{
cur=cur->right;
}
}
return 0;
}
int search(Node *root,int key){
if(root==NULL){
return 0;
}
if(root->data==key){
return 1;
}
if(key<root->data){
search(root->left,key);
}
else{
search(root->right,key);
}

}
int height(Node *root){
if(root==NULL){
return 0;
}
return(fmax(height(root->left),height(root->right))+1);
}
Node *mirror(Node *root){
if(root==NULL){
return root;
}
Node *l=mirror(root->left);
Node *r=mirror(root->right);
return root;
}
void level_order(Node *root){
queue q;
Node *cur;
if(root==NULL){
return;
}

q.push(root);

while(q.isEmpty()!=true){

cur=q.pop();


if(cur!=NULL){

       cout<<cur->data<<" ";

}

if(cur->left){
q.push(cur->left);
}

if(cur->right){
q.push(cur->right);
}



}
}
Node *deleteNode(Node *root,int key){
if(root==NULL){
cout<<"\nNo such element present";
return root;
}
if(key<root->data){
root->left=deleteNode(root->left,key);
}
else if(key>root->data){
root->right=deleteNode(root->right,key);
}
else{
if(root->left==NULL){
Node *temp=root->right;
delete(root);
cout<<"\nNode deleted sucessfully";
return temp;
}
else if(root->right==NULL){
Node *temp =root->left;
delete(root);
cout<<"\nNode deleted sucessfully";
return temp;
}
else{
Node *parent =root;
Node *cur=root->right;
while(cur->left!=NULL){
parent =cur;
cur=cur->left;
}
if(parent !=root){
parent->left=cur->right;
}
else{
parent->right=cur->right;
}
root->data=cur->data;
delete(cur);
cout<<"\nNode deleted sucessfully";
return root;

}
}
}

};
int main (){
BST t;
Node *root1;
int choice;
do{
cout<<"\nMenu:\n1.Insert a Node (Recursive)  \n2.Insert a Node (Non-Recursive) \n3.Inorder Traversal \n4.Level Order Traversal\n5.Search Node(Recursive) \n6.Search Node(Non-Recursive) \n7.Delete Node \n8.Mirror of Tree \n9.Height of Tree\n10.Exit \nENTER YOUR CHOICE:";
cin>>choice;
switch(choice){
case 1:
int x;

    cout<<"Enter the data";
   cin>>x;
       t.insert(x);
    root1=t.rootval();
break;
case 2:
int y;

    cout<<"Enter the data";
   cin>>y;
   t.insert_non_rec(root1,y);
   root1=t.rootval();
break;
case 3:
t.inorder(root1);
break;
case 4:
cout<<"\nLevel order Traversal :\n";
t.level_order(root1);
break;
case 5:
int key ;
cout<<"Enter the key to be searched :";
cin>>key;
int ans;
ans=t.search(root1,key);
if(ans==1){
cout<<"Element found ";
}
else{
cout<<"Element not found";
}
break;
case 6:
int ke ;
cout<<"Enter the key to be searched :";
cin>>ke;
int sr;
sr=t.search_non_rec(root1,ke);
if(sr==1){
cout<<"Element found ";
}
else{
cout<<"Element not found";
}
break;
case 7:
cout<<"\nEnter the key to be deleted :";
int k;
cin>>k;
root1=t.deleteNode(root1,k);
break;
case 8:
root1=t.mirror(root1);
cout<<"\nThe inorder display of the mirrored tree :";
t.inorder(root1);
break;
case 9:
int h;
h=t.height(root1);
cout<<"\nHeight :"<<h;
break;
case 10:
cout<<"Thank You!";
break;
default:
cout<<"Enter a Valid Choice!!";
}
}while(choice !=10);
return 0;
}
