#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 501
using namespace std;

int n;
int indeg[MAX], buildTime[MAX], minBuildTime[MAX];
vector<int> g[MAX], buildNeeded[MAX];

void topology(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indeg[i] != 0) continue;
        q.push(i);
        minBuildTime[i] = buildTime[i];
    }
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(int i = 0; i < g[curr].size(); i++){
            int next = g[curr][i];
            if(--indeg[next] != 0) continue;
            
            for(int j = 0; j < buildNeeded[next].size(); j++){
                minBuildTime[next] = max(minBuildTime[next], 
                    minBuildTime[buildNeeded[next][j]]);
            }
            minBuildTime[next] += buildTime[next];
            q.push(next);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        int needed;
        cin >> buildTime[i] >> needed;
        while(needed != -1){
            indeg[i]++;
            buildNeeded[i].push_back(needed);
            g[needed].push_back(i);
            cin >> needed;
        }
    }
    
    // for(int i = 1; i <= n; i++){
    //     cout << "\ng[" << i << "]: ";
    //     for(int j = 0; j < g[i].size(); j++){
    //         cout << g[i][j] << " ";
    //     }
    // }
    
    // for(int i = 1; i <= n; i++){
    //     cout << "\nbuilNeeded[" << i << "]: ";
    //     for(int j = 0; j < buildNeeded[i].size(); j++){
    //         cout << buildNeeded[i][j] << " ";
    //     }
    // }
    
    topology();
    
    for(int i = 1; i <= n; i++){
        cout << minBuildTime[i] << "\n";
    }
    
    return 0;
}



