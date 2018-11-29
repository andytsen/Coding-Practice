// problem I got at google
// 11/4/2018


// andy::vector



int cap(vector<int>& arr, int k) {
    int cur = 2;
    pair<int,bool> p = arr.get(cur);
    while(p.second && p.first < k) {
        cur *= 2;
        p = arr.get(cur);
    }
    return cur;
}

/// vector arr is sorted, int k
bool find(vector<int>& arr, int k) {
    int lo = 0;
    int hi = cap(arr); 
    
    while(lo <= hi) {
        int mid = lo + (hi - low) >> 1;
        pair<int,bool> p = arr.get(mid);

        if(!p.second || p.first > k) {
            hi = mid - 1;
        } else if(p.first < k) {
            lo = mid + 1;
        } else { return true; }
    }
    return false;
}



