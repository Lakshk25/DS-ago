// 4
// 1 9 10 1
// 3 3 6 7 7 9 12 14 16 16 18 21 21 22 25 26 27 29 30 32 36

//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
    // add nodes to bottom in ascending order 
    Node* merge(Node* first , Node* second){
        if(first == NULL){
            return second;
        }
        if(second == NULL){
            return first;
        }
        Node* ans = new Node(-1);
        Node* temp = ans;
        temp -> next = NULL;
        while(first != NULL && second != NULL){
            if(first -> data <= second -> data){
                temp -> bottom = first;
                temp = first;
                first = first -> bottom;
            }
            else{
                temp -> bottom = second;
                temp = second;
                second = second -> bottom;
            }
        }
        while(first != NULL){
            temp -> bottom = first;
            temp = first;
            first = first -> bottom;
        }
        while(second != NULL){
           temp -> bottom = second;
            temp = second;
            second = second -> bottom; 
        }
        ans = ans -> bottom;
        return ans;
    }
Node *flatten(Node *root)
{
    // check if root next is NULL return 
    if(root -> next == NULL){
        return root;
    }
    
    Node* curr = root;
    Node* next = curr -> next;
    Node* next_next = next -> next;
   while(next -> next != NULL && next != NULL){
       curr -> next = NULL;
       next -> next = NULL;
       
       // merge all nodes to single bottom node
       curr = merge(curr , next);
      if(next_next != NULL)
            next = next_next;
       next_next = next_next -> next;
   }
   curr = merge(curr , next);
   return root;
}

