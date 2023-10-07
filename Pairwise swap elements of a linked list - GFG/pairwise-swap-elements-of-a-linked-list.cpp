//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/

class Solution {
public:
    Node* pairWiseSwap(struct Node* head) {
        // If the list is empty or has only one node, no swapping needed
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Initialize pointers for swapping
        Node* prev = head;
        Node* curr = head->next;

        // Update the head of the new list after swapping
        head = curr;

        while (true) {
            Node* nextNode = curr->next;
            curr->next = prev; // Swap nodes

            // If the next pair is NULL or reached the end of the list
            if (nextNode == NULL || nextNode->next == NULL) {
                prev->next = nextNode; // Connect the last odd node (if exists) to the new list
                break;
            }

            // Connect the previous swapped pair to the next pair
            prev->next = nextNode->next;

            // Move pointers to the next pair
            prev = nextNode;
            curr = prev->next;
        }

        return head;
    }
};


//{ Driver Code Starts.

void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		map<Node*, int> mp;
		mp[head] = head->data;
		for (int i = 0; i<n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
			mp[tail] = tail->data;
		}
		struct Node *failure = new Node(-1);
		Solution ob;
		head = ob.pairWiseSwap(head);
		int flag = 0;
		struct Node *temp = head;
		while(temp){
		    if(mp[temp] != temp->data){
		        flag = 1;
		        break;
		    }
		    temp = temp->next;
		}
		if(flag)
		    printList(failure);
		else
		    printList(head);
	}
	return 0; 
}

// } Driver Code Ends