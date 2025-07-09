/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        auto cmp = [](Node* a, Node* b) {return a->data > b->data;};
        priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);
        for(auto node : arr){
            if(node) pq.push(node);
        }
        Node* dummy = new Node(0);
        Node* tail = dummy;
        while(!pq.empty()){
            Node* curr = pq.top();
            pq.pop();
            tail->next = curr;
            tail = curr;
            if(curr->next) pq.push(curr->next);
        }
        return dummy->next;    
        
    }
};