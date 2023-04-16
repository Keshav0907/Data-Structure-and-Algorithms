class Node {
  public:
    int val;
    Node* next;
    // Constructor of Node
    Node(int val) {
        this->val = val;
        next = NULL;
    }
	
};

class MyLinkedList {
    
public:
    Node* head;
    int size;
    MyLinkedList() {
     
        head = NULL;
        size = 0;
         
    }
    
    int get(int index) {
        
         Node* currentNode = head;
        if(index >= size || index<0 ){
            return -1;
        } else {
           
            for(int i=0; i<index; i++){
                currentNode = currentNode->next;
            }
        
        }
        
        return currentNode->val;
        
    }
    

    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > size || size < 0) {
            return;
        }
        Node* temp = new Node(val);
        Node* currentNode = head;
        if(index==0) {
        temp->next = head;
        head = temp;
        } else {
            
           
            for(int i=0; i<index-1; i++){
                currentNode = currentNode->next;
            }
            
            temp->next = currentNode->next;
            currentNode->next = temp;
            
            
        }
        size++;
    }
    

    void deleteAtIndex(int index) {
     
        if(index >= size || index<0) {
            return;
        } else if(index==0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            
            Node* currentNode = head;
            
            for(int i=0; i<index-1; i++) {
                currentNode = currentNode->next;
            }
            
            Node* nextNode = currentNode->next->next;
            delete currentNode->next;
            currentNode->next = nextNode;
            
            
        }
        
        size--;
    }
    
      ~MyLinkedList()
    {
        Node *p = head;
        // Delete node at head while head is not null
        while (head!=nullptr)
        {
            head= head->next;
            delete p;
            p=head;
        }
    }
};

