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

Node* deletehead(Node* head){

   if(head == nullptr || head -> next == nullptr){
      return nullptr;
   }

      Node* prev = head;
      head = head->next;

      head->back= nullptr;
      prev->next = nullptr;

      delete prev;
      return head;
}

Node* deletetail(Node* head){

	Node* store = head;

	if(head == nullptr || head -> next == nullptr){
      return nullptr;
   }
   while(store-> next ->next != nullptr){
   	store = store-> next;
   }
   if(store -> next ->next == nullptr ){
   	Node* temp = store->next;
      store->next = nullptr;
  	   temp->back = nullptr;
  	   delete temp;
  	   return head;
   }

}

Node* deleteKth(Node* head,int k,int n){

	int i =1;
	Node* store = head;

	if(k == 1){
		head = deletehead(head);
		return head;
	}
	else if(k == n){
		head = deletetail(head);
		return head;
	}
	else{

		while(i != k-1){
			store = store-> next;
			i++;
		}
		Node * temp = store->next;
		store->next = temp -> next;
		store->next->back = store;
		temp->back = nullptr;
		temp->next = nullptr;
		delete temp;
		return head;
	}

}

void deletenode(Node* head, Node* temp) {
   if (temp == nullptr)
      return;

   if (temp == head) {
        // Special case: deleting head
      head = head->next;
      if (head != nullptr)
         head->back = nullptr;
         temp->next = nullptr;
         delete temp;
         return;
   }

   Node* prev = temp->back;
   Node* front = temp->next;

   if (prev != nullptr)
      prev->next = front;

   if (front != nullptr)
      front->back = prev;

   temp->next = temp->back = nullptr;
      delete temp;
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

   // int k;
   // cin >> k;
   Node* head = convert2DLL(nums);
   // head = deletehead(head);
   // head = deletetail(head);
   // head = deleteKth(head,k,n);
   deletenode(head,head->next);
   print(head);
   return 0;
}
