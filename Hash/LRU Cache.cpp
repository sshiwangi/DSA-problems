/* Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:

SET x y : sets the value of the key x with value y
GET x : gets the key of x if present else returns -1.

The LRUCache class has two methods get() and set() which are defined as follows.

get(key)   : returns the value of the key if it already exists in the cache otherwise returns -1.
set(key, value) : if the key is already present, update its value. If not present, add the key-value pair to the cache. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.
In the constructor of the class the capacity of the cache should be intitialized.
 

Example 1:

Input:
cap = 2
Q = 2
Queries = SET 1 2 GET 1
Output: 2
Explanation: 
Cache Size = 2

SET 1 2 GET 1
SET 1 2 : 1 -> 2

GET 1 : Print the value corresponding
to Key 1, ie 2.

Your Task:
You don't need to read input or print anything . Complete the constructor and get(), set() methods of the class LRUcache. 


Expected Time Complexity: O(1) for both get() and set().
Expected Auxiliary Space: O(1) for both get() and set(). 
(Although, you may use extra space for cache storage and implementation purposes).


Constraints:
1 <= cap <= 1000
1 <= Q <= 100000
1 <= x, y <= 1000 */

// code
class LRUCache
{
    private:
    
    public:
    // creating a doubly ll 
    class node{
        public:
             int key;
             int val;
             node* next;
             node* prev;
             node(int k, int value){
                 key = k;
                 val = value;
             }
    };
    // initializing head and tail of dll
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    // stores the size of cache
    int size;
    unordered_map<int, node*> mp;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        size = cap;
        head->next = tail;
        tail->prev =  head;
 
    }
    // Function to add node in dll
    void addnode(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    //Function to delete node from dll
    void deletenode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(mp.find(key)!=mp.end()){// if key is present in map
            node* resnode = mp[key]; // find it's address
            int res = resnode->val; // get the value
            mp.erase(key); // erase it from map as it wil become the last recently used element
            deletenode(resnode); // delete it from dll
            addnode(resnode); // add it right after the head
            mp[key] = head->next; // store the key and it's new address in the map
            return res; 
        }
        // if key not found in the map
        return -1;
        
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if(mp.find(key)!=mp.end()){// if key present in the map
            node* existingnode = mp[key]; // find it's address in the dll
            mp.erase(key); // erase it from map
            deletenode(existingnode);// delete the node from dll too
        }
        if(mp.size() == size){// if cache is full
            mp.erase(tail->prev->key); // erase the least recently used element
            deletenode(tail->prev); // and delete it too from the dll
            
        }
        addnode(new node(key, value)); // add it's new value in the dll
        mp[key] = head->next; // as well as in map
        
    }
};
