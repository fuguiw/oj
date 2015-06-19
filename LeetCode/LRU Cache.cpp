#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

class LRUCache{
public:
    LRUCache(int capacity)
        : capacity_(capacity), num_(0) {
        
    }
    
    int get(int key) {
        auto it_num = num_map_.find(key);
        if (it_num == num_map_.end())
            return -1;

        auto it_used = used_map_.find(it_num->second);
        used_map_.insert(make_pair(++num_, it_used->second));
        used_map_.erase(it_used);
        it_num->second = num_;

        return value_map_[key];
    }
    
    void set(int key, int value) {
        auto it_value = value_map_.find(key);
        if (it_value == value_map_.end()) {
            if (value_map_.size() == capacity_) {
                auto it_used = used_map_.begin();
                value_map_.erase(it_used->second);
                num_map_.erase(it_used->second);
                used_map_.erase(it_used);
            }

            value_map_.insert(make_pair(key, value));
            num_map_.insert(make_pair(key, ++num_));
            used_map_.insert(make_pair(num_, key));
        } else {
            auto it_num = num_map_.find(key);
            auto it_used = used_map_.find(it_num->second);
            used_map_.insert(make_pair(++num_, it_used->second));
            used_map_.erase(it_used);
            it_num->second = num_;
            
            value_map_[key] = value;
        }

    }

private:
    int capacity_;
    long long num_;
    unordered_map<int, int> value_map_;
    unordered_map<int, long long> num_map_;
    map<long long, int> used_map_;
};

int main(int argc, char *argv[])
{
    LRUCache cache(4);

    for (int i = 0; i < 10; i++)
        cache.set(i,i);

    cache.get(6);
    cache.set(1, 1);

    for (int i = 0; i < 10; i++)
        cout << cache.get(i) << endl;

    return 0;
}
