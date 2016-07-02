#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

struct node
{
	char data;
	int freq;
	int visited;
	struct node * left, * right;
};
char code[1000][10000];

int isLeaf(struct node * root)
{
	if((root->left)==0 && (root->right)==0) return true ;
	else return false;
}
void printCodes(struct node* root, int arr[], int top)
{
	if (isLeaf(root))
	{
		if(root->visited!=1)
		{
			strcpy(code[root->data],"");
			//printf("%c: ", root->data);
			for(int i=1;i<top;i++)
			{
				char a[1000];
				sprintf(a,"%d",arr[i]);
				strcat(code[root->data],a);
			}
			//cout<<code[root->data]<<endl;
		}
		root->visited=1;
	}

	if (root->left)
	{
		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}

	if (root->right)
	{
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}
}

int main()
{
	//FREQ COUNTING

	freopen("source.txt","r",stdin);
	char ch=0;
	int freq[128]={0};
	while(scanf("%c",&ch)!=EOF)
	{
		freq[ch]++;
	}
	fclose(stdin);


	//INITIALIZING TREE
	struct node* store[128];

	struct node * now;

	now=(struct node*)malloc(sizeof(struct node));
	now->data=' ';
	now->freq=freq[(int)' '];
	now->left=now->right=NULL;
	store[0]=now;

	int j=1;
	for(int i=97;i<=122;i++)
	{
		now=(struct node*)malloc(sizeof(struct node));
		now->data=(char)i;
		now->freq=freq[i];
		now->left=now->right=NULL;
		store[j++]=now;
	}
	/*for(int i=0;i<j;i++)
	{
	cout<<store[i]->data<<store[i]->freq<<endl;
	}*/

	// HUFFMAN TREE
	int counter=j;
	int l;
	while(counter--)
	{
		struct node * min1, * min2;
		int min=1000000, min_index=0;

		// MIN 1

		for(int i=0;i<j;i++)
		{
			if(store[i])
			{

				if((store[i]->freq) < min)
				{
					min=store[i]->freq;
					min1=store[i];
					min_index=i;
				}
			}
		}
		store[min_index]=0;
		//cout<<"min1: "<<min1->data<<" "<<min1->freq<<endl;


		// MIN 2
		min=1000000;
		min_index=0;
		for(int i=0;i<j;i++)
		{
			if(store[i])
			{
				if((store[i]->freq) < min)
				{
					min=store[i]->freq;
					min2=store[i];
					min_index=i;
				}
			}
		}
		store[min_index]=0;
		//cout<<"min2: "<<min2->data<<" "<<min2->freq<<endl;


		struct node * now;
		now=(struct node *) malloc(sizeof(struct node));
		now->data=NULL;
		now->freq=(min1->freq) + (min2->freq);
		now->left=min1;
		now->right=min2;

		for(int i=0;i<j;i++)
		{
			if(store[i]==0)
			{
				store[i]=now;
				l=i;
				break;
			}
		}

	}

	//count code
	int a[100], v[100];
	printCodes(store[l],a,0);

	freopen("source.txt","r",stdin);
	freopen("output_for_source.txt","w",stdout);
	ch=0;
	while(scanf("%c",&ch)!=EOF)
	{
		cout<<code[ch];
	}
}
