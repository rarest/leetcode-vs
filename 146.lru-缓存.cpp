/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
struct Node {
    int key;
    int val;
    Node(int key_,int val_):key(key_),val(val_){}
};

class LRUCache {

private:
    int cap_;
    std::list<Node> nodeList_;
    std::map<int, std::list<Node>::iterator> itrMap_;
    
public:
    LRUCache(int capacity):cap_(capacity) {

    }
    
    int get(int key) {
        auto itr = itrMap_.find(key);
        if(itr == itrMap_.end()) {
            return -1;
        }        
        nodeList_.splice(nodeList_.begin(), nodeList_, itr->second);
        return nodeList_.front().val;
    }
    
    void put(int key, int value) {
        if(cap_ <= 0) return;
        auto itr = itrMap_.find(key);
        if(itr == itrMap_.end()) {  
            if(nodeList_.size()== cap_) {                
                itrMap_.erase(nodeList_.back().key);
                nodeList_.pop_back();
            }
            nodeList_.insert(nodeList_.begin(), Node(key,value));
            itrMap_[key] = nodeList_.begin();
        } else {
            itr->second->val = value;
            nodeList_.splice(nodeList_.begin(), nodeList_, itr->second);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

