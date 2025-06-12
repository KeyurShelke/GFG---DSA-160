class LRUCache {
        private:
        int capacity;
        list<pair<int,int>> lruList;
        unordered_map<int ,list<pair<int,int>>::iterator>cacheMap;
        
        public:
        LRUCache(int cap){
            capacity = cap;
            
        }
        
        int get(int key){
            if(cacheMap.find(key) == cacheMap.end())
                return -1;
            
            lruList.splice(lruList.begin(), lruList, cacheMap[key]);
            return cacheMap[key]->second;
        }
        
        void put(int key, int value){
            if(cacheMap.find(key) != cacheMap.end()){
                cacheMap[key]->second = value;
                lruList.splice(lruList.begin(), lruList, cacheMap[key]);
            }else{
                if(lruList.size() == capacity){
                    int keyToRemove = lruList.back().first;
                    lruList.pop_back();
                    cacheMap.erase(keyToRemove);
                }
                
                lruList.emplace_front(key, value);
                cacheMap[key] = lruList.begin();
            }
        }
    };

    