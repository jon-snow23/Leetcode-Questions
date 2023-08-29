//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
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



// } Driver Code Ends
/*

The structure of linked list is the following
/*
The structure of linked list is the following
struct Node
{
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    Node *reverse(Node *head) {
        Node *prev = NULL, *curr = head, *next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node *compute(Node *head)
    {
        // First, reverse the linked list
        head = reverse(head);

        Node *curr = head;
        Node *maxNode = head; // The first node is always the maximum
        Node *temp;

        while (curr != NULL && curr->next != NULL) {
            if (curr->next->data < maxNode->data) {
                temp = curr->next;
                curr->next = temp->next; // Remove the current node
                delete temp;
            } else {
                curr = curr->next;
                maxNode = curr; // Update the maximum node
            }
        }

        // Reverse the linked list again to bring it back to the original order
        head = reverse(head);

        return head;
    }
};

   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends