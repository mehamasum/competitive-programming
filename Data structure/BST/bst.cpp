#include <iostream>
#include <cstdlib>
using namespace std;

#define FREOPEN freopen("input.txt","r",stdin);

// NODE DEFINITION

struct bst_node
{
	int key;
	struct bst_node * left, * right ;
};

typedef struct bst_node node; 


// FUNCTION FOR SEARCHING A KEY

node* search(node* root, int value)
{
    if (root == 0) return 0; 
	if(root->key == value)
       return root;
    
    if (root->key < value)
       return search(root->right, value);
 
    return search(root->left, value);
}

  
// FUNCTIONS FOR TRAVERSING BST

void in_order(node *root)
{
	if(root==0) return;
	in_order(root->left);
	printf("%d ", root->key);
	in_order(root->right);
}
void pre_order(node *root)
{
	if(root==0) return;
	printf("%d ", root->key);
	pre_order(root->left);
	pre_order(root->right);
}
void post_order(node *root)
{
	if(root==0) return;
	post_order(root->left);
	post_order(root->right);
	printf("%d ", root->key);
}


// FUNCTION FOR ALLOCATING MEMORY FOR A NEW NODE

node *createNode(int item)
{
    node *temp =  (node *)malloc(sizeof(node));
    temp->key = item;
    temp->left = temp->right = 0;
    return temp;
}

// FUNCTION FOR INSERTING A NEW NODE

node* insert(node* root, int value)
{
    if (root == 0) return createNode(value);
    
	if (value < root->key)
	{
        root->left  = insert(root->left, value);
		return root;
	}
    
	else if (value > root->key)
    {
		root->right = insert(root->right, value);   
		return root;
	}	
}



// FUNCTION TO GET THE NODE WITH MINIMUM KEY VALUE

node * getMin(node* head)
{
    node* current = head;

    while (current->left != 0)
        current = current->left;
 
    return current;
}

// FUNCTIONS TO DELETE A NODE HOLDING KEY VALUE

node* deleteNode(node* root, int key)
{
    if (root == 0) return root;
 
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    else //match
    {
        if (root->left == 0)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == 0)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
 
        node* temp = getMin(root->right); //min of the maxes
 
        root->key = temp->key;
 
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
  
int main()
{
	//FREOPEN;
    node *root = 0;
	cout<<"1 to insert, 2 to delete, 3 to search\n4 for inorder, 4 for preorder, 6 for postorder traversal\n0 to exit"<<endl;
   
	while(1)
	{
		int n;
		cin>>n;

		switch(n)
		{
			case(1):
				int m;
				cin>>m;
				if(root==0)
					root=insert(root, m);
				else
					insert(root, m);
				break;
			case(2):
				cin>>m;
				deleteNode(root,m);
				break;

			case(3):
				cin>>m;
				if(search(root,m)) cout<<"Key found at address: "<<search(root,m)<<endl;
				else cout<<"Key not found"<<endl;
				break;

			case(4):
				in_order(root);
				cout<<endl;
				break;
			case(5):
				pre_order(root);
				cout<<endl;
				break;
			case(6):
				post_order(root);
				cout<<endl;
				break;
			case(0):
				return 0;
		}	
	}
}
	