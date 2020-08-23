/*i=3 n=4
    1-->2--> 3--> 4-->5-->6
    reverse(head)
    4-->3-->2-->1 6-->5
    1<--2  3<--4 5<--6
    2-->1-->4-->3-->6-->5
*/
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node *next;
    int data;
    
    Node(int d){
        next=NULL;
        data = d;
    }
};

Node *solve(Node *head,int k)
{
    if(head==NULL)
        return NULL;

    stack<Node *> st;
    int i=0;
    Node *temp = head;
    while(i<k && temp!=NULL){
        st.push(temp);
        temp= temp->next;
        i++;
    }

    head = st.top();
    Node *temp1 = head;
    st.pop();
    while(!st.empty()){
        Node *t = st.top();
        temp1->next = t;
        temp1 = temp1->next;
        st.pop();
    }
 
    if(temp!=NULL){

        temp1->next =solve(temp,k);
    }
    else{
        temp1->next = NULL;
    }
  
    return head;
}
int main(){
    
    
    int n;
    cin>>n;
    Node *head = new Node(0);
    Node *temp = head;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node *t = new Node(x);
        temp->next = t;
        temp = temp->next;
    }
    
    int k;
    cin>>k;
    head = head->next;
    temp = head;
    for(int i=0;i<n;i++){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
    temp=solve(head,k);
    
    cout<<"AFTER REVERSE: "<<temp->data<<endl;
    for(int i=0;i<n;i++){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}
