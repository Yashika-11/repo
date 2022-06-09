#include <iostream>

using namespace std;

class node
{
    public :
    int data;
    node *left,*right;
    int lth,rth;

    node(int x)    //constructor
    {
        data = x;
        lth=1;
        rth=1;
    }

};

class thread
{
    public:

    node *root,*dummy;

    thread()   //constructor
    {
        root = NULL;
        dummy = new node(-1);
        dummy-> rth=0;
        dummy ->lth=1;
        dummy-> left = dummy;
        dummy-> right = dummy;

    }

    	node *rootval()   //function to return root value
        {
		    return root;
	    }
	    node *dummyval()   //function to return root value
	    {
		    return dummy;
	    }

    void insertnode()
    {
        node *newnode;
        int data;
        cout<<"Enter the Node Data "<<endl;
        cin>>data;
        newnode = new node(data);

        if(dummy->lth==1) //Empty TBT
        {
            root=newnode;
            root->left=dummy;
            root->right=dummy;
            dummy->left=root;
            dummy->lth=0;


        }

        else
        {
            insert(root,newnode);

        }
    }


    void insert(node *root,node *newnode)
    {
        if(newnode->data<root->data)
        {
            if(root->lth==1)   //insert to left of root
            {
                newnode->lth=root->lth;
                newnode->left=root->left;
                newnode->right=root;
                newnode->rth=1;
                root->left=newnode;
                root->lth=0;
            }

            else
            {
                insert(root->left,newnode);
            }
        }

        else
        {
            if(root->rth==1) // insert to right of root
            {
                newnode->rth=root->rth;
                newnode->right=root->right;
                newnode->left=root;
                newnode->lth=1;
                root->right=newnode;
                root->rth=0;
            }
            else
            {
                insert(root->right,newnode);
            }
        }
    }



    node *presuc(node *temp){
		if(temp->lth==0){
			return (temp->left);
		}
		if(temp->rth==1){
			temp=temp->right;
		}
		return(temp->right);
	}
	void preorder(node *dummy){
		node *temp=dummy;
		dummy=dummy->left;
		while(dummy!=temp)
		{
			cout<<dummy->data<<" ";
			dummy=presuc(dummy);
		}
	}


	node *insuc(node *temp)
	{
		if(temp->rth==0){
			return(temp->right);
		}
		temp=temp->right;
		while(temp->lth==1){
			temp=temp->left;
		}
		return (temp);
	}

	void inorder(node *dummy){
		node *temp=dummy;
		dummy=dummy->left;
		while(dummy->lth!=1){
			dummy=dummy->left;
		}
		while(dummy!=temp){
			cout<<dummy->data<<" ";
			dummy=insuc(dummy);
		}
	}



};





int main (){
	thread t;
	node *root1,*dummy1;
	int choice;
	do{
		cout<<"\n\nMenu:\n1.INSERT A NODE  \n2.INORDER TRAVERSAL \n3.PREORDER TRAVELSAL  \n4.EXIT" ;
		cout<<"\nENTER YOUR CHOICE :";
		cin>>choice;
		switch(choice){
			case 1:
				t.insertnode();
		        root1=t.rootval();
			    dummy1=t.dummyval();
			break;
			case 2:
				cout<<"\nINORDER TRAVERSAL :\n";
				t.inorder(dummy1);
			break;
			case 3:
				cout<<"\nPRERDER TRAVERSAL :\n";
				t.preorder(dummy1);
			break;
			case 4:
			    cout<<"Thank You!";
			break;

			default:
			    cout<<"Enter valid Choice!!";

		}
	}while(choice !=4);
	return 0;
}
