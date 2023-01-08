class DataStream {
public:
    int V, K;
    int cnt;
    DataStream(int value, int k) {
        V = value;
        K = k;
        cnt = 0;
    }
    
    bool consec(int num) {
        if (num != V) {
            cnt = 0;
        }
        else {
            cnt++;
        }
        if (cnt >= K) {
            return true;
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */