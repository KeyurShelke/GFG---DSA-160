/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  Node *rev(Node *head){
      Node *prev = nullptr;
    while(head){
        Node *next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    return prev;
  }
  Node *trimzero (Node *head){
      while(head && head -> next && head -> data == 0){
          head=head->next;
      }
      return head;
  }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        num1=trimzero(num1);
        num2=trimzero(num2);
        Node *l1=rev(num1);
        Node *l2=rev(num2); 
        Node *dummy=new Node(-1);
        Node *curr=dummy;
        int carry =0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=carry;
            if(l1){
                sum+=l1->data;
            }
            if(l2){
                sum+=l2->data;
            }
            Node *neW=new Node(sum%10);
            curr->next=neW;
            curr=curr->next;
            carry=sum/10;
            if(l1){
                l1=l1->next;
            }
            if(l2){
                l2=l2->next;
            }
        }
        return rev(dummy->next);
        
    }
};