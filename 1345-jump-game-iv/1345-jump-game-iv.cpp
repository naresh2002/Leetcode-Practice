class Solution {
public:
  // Daily Challenge
  
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int,vector<int>> map;
        for(int i=0; i<n; ++i){
            map[arr[i]].push_back(i);
        }
        
        queue<int> q;
        q.push(0);
        int steps = 0;
        unordered_set<int> vis;
        vis.insert(0);
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i = q.front(); q.pop();
                
                //i+1 step
                if(i+1<n && vis.count(i+1)==0){
                    if(i+1==n-1) return steps+1;
                    q.push(i+1);
                    vis.insert(i+1);
                }
                
                //i-1 step
                if(i-1>=0 && vis.count(i-1)==0){
                    if(i-1==n-1) return steps+1;
                    q.push(i-1);
                    vis.insert(i-1);
                }
                
                //j step where arr[i] == arr[j] step
                int val = arr[i];
                for(auto &j : map[val]){
                    if(i == j) continue;
                    if(vis.count(j)>0) continue;
                    if(j == n-1) return steps+1;
                    
                    q.push(j);
                    vis.insert(j);
                }
                map.erase(val);
            }
            steps++;
        }
        return 0;
    }
};