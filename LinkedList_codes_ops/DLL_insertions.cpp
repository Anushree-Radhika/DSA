#include<bits/stdc++.h>
using namespace std;
class Node{

    public:
      int data;
      Node* next;
      Node* back;

    public:
        Node(int data1,Node* next1,Node* back1){
           data = data1;
           next = next1;
           back = back1;
      }

    public:
      Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node* convert2DLL(vector<int> &nums){

	Node* head = new Node(nums[0]);
	Node* prev = head;
	for(int i=1;i<nums.size();i++){
 		Node* temp = new Node(nums[i],nullptr,prev);
		prev->next = temp;
		prev = temp;
	}
	return head;

}
Node* inserthead(Node* head, int val){

	Node* temp = new Node(val);
	temp->next = head;
	temp->back = nullptr;
	head->back = temp;
	return temp;

}
Node* inserttail(Node* head,int val){

	Node* temp = new Node(val);
	Node* store = head;
	if(head == nullptr ){
		return temp;
    }
    while(store-> next != nullptr){
   	  store = store-> next;
    }
    
    store->next = temp;
    temp->back = store;
    temp->next = nullptr;
    return head;
}


Node* insertKth(Node* head,int k,int n,int val){

	int i=1;
	Node* store = head;

	if(k == 1){
		head= inserthead(head,val);
		return head;
	}
	else if(k == n+1){
		head =  inserttail(head,val);
		return head;
	}
	else{

		while(i != k-1){
			store = store-> next;
			i++;
		}
		Node* temp = new Node(val);
		Node* front = store->next;
		store->next = temp;
		temp ->next= front;
		front->back = temp;
		temp->back = store;
		return head;
	}
}


Node* insertNode(Node* head,Node* temp,int val){

	if (temp == nullptr){
		return inserttail(head,val);
	}
      
  if (temp == head) {
    return inserthead(head,val);
  }
  Node* prev = temp->back;

  if(temp->next != nullptr){
  	Node* front = temp->next;
  	Node* new_val = new Node(val);
    prev->next = new_val;
    new_val->next = temp;
    temp->next = front;
    front-> back = temp;
    temp->back = new_val;
    new_val-> back = prev;
  }
  else{
  	Node* new_val = new Node(val);
    prev->next = new_val;
    new_val->next = temp;
    temp->back = new_val;
    new_val-> back = prev;
  }
   
  return head;
}
void print(Node* head){
	while(head != nullptr){
		cout << head->data << " ";
		head = head->next;
	}

}

int main(){

	int n;
	cin >> n;
    vector<int> nums(n);
    for(int j=0;j<n;j++){
   	    cin >> nums[j];
    }

    int val,k;
    cin >> val >> k;
    Node* head = convert2DLL(nums);
    // head = inserthead(head,val);
    // head = inserttail(head,val);
    // head = insertKth(head,k,n,val);
    insertNode(head,head->next->next,val);
    print(head);
    return 0;
}
