class Fenwick{
    public :
    int n;
    vector<int> bit;
    void init(int sz){
        bit.assign(sz+1,0);
        n = sz+1;
    }
    void upd(int id){
        while(id <= n){
            bit[id]++;
            id += id&-id;
        }
    }
    int get(int id){
        int tot = 0;
        while(id){
            tot += bit[id];
            id -= id&-id;
        }
        return tot;
    }
    int search(int val){
        int num = 0;
        for(int j = 19; j >= 0;j--){
            if((num|(1<<j)) <= n && bit[num|(1<<j)] >= val){
                num = num|(1<<j);
                val -= bit[num];
            }
        }
        return num;
    }
};
