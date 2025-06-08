/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        if(!head) return nullptr;
        unordered_map<Node*, int>dic;
        vector<Node*>new1;
        Node *temp=head;
        int c=0;
        while(temp){
            dic[temp]=c;
            new1.push_back(new Node(temp -> data));
            temp=temp->next;
            c++;
        }
        temp=head;
        while(temp){
            if(temp->next){
                new1[dic[temp]]->next=new1[dic[temp->next]];
            }
            if(temp->random){
                new1[dic[temp]]->random=new1[dic[temp->random]];
                }
                temp=temp->next;
            }
            return new1[0];
        }
};