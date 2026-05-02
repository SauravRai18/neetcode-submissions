class LRUCache {
public:

class Node {
    public:

    int key, val;
    Node* prev;
    Node* next;

   Node(int k, int v){
    key = k;
    val = v;;
    prev = next = nullptr;
   }
};

Node* head = new Node(-1, -1);
Node* tail = new Node(-1, -1);

unordered_map<int, Node*> mp;

int limit;

void addnode(Node* newnode){
      
    Node* oldnext = head->next;

    head->next = newnode;
    newnode->prev = head;

    newnode->next = oldnext;
    oldnext->prev = newnode;   
}

void delnode(Node* node){

    Node* oldprev = node->prev;
    Node* oldnext = node->next;

    oldprev->next = oldnext;
    oldnext->prev = oldprev;
}

    LRUCache(int capacity) {

        limit = capacity;
        head->next = tail;
        tail->prev = head;
       
    }
    
    int get(int key) {

        if(mp.find(key) == mp.end()){
            return -1;
        }

        Node* node = mp[key];
        int ans = node->val;

       
        delnode(node);

        addnode(node);
        


        return ans;
        
    }
    
    void put(int key, int val) {

        if(mp.find(key) != mp.end()){
            Node* oldnode = mp[key];
            delnode(oldnode);
            mp.erase(key);
        }

        if(mp.size() == limit){
        Node* lru = tail->prev;
        mp.erase(lru->key);
        delnode(lru);
    }

        Node* newnode = new Node(key, val);
        addnode(newnode);
        mp[key] = newnode;
        
    }
};
