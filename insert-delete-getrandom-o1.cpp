/*
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. 
Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. 
Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements 
(it's guaranteed that at least one element exists when this method is called). 
Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in 
average O(1) time complexity.

 
*/
class RandomizedSet {
    unordered_set<int>s;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.find(val)!=s.end()){
            return 0;    
        } 
        else{
            s.insert(val);
            return 1;
        }
    }
    
    bool remove(int val) {
        if(s.find(val)==s.end()){
            return 0;
        }
        else{
            s.erase(val);
            return 1;
        }
    }
    
    int getRandom() {
        return *next(s.begin(),rand()%s.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */