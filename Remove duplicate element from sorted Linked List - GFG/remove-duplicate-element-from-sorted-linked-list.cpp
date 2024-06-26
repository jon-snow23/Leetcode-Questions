//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends


/* struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

Node *removeDuplicates(Node *head)
{
    Node *current = head;
    
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            Node *temp = current->next;
            current->next = temp->next;
            delete temp; // Free memory of duplicate node
        } else {
            current = current->next;
        }
    }
    return head;
}
