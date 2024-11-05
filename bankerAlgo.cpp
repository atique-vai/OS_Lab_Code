#include<bits/stdc++.h>
using namespace std;

int main(){
    int processes = 5;
    int resources = 3;
    vector<string> pName(processes);
    vector<vector<int>> allocation(processes, vector<int>(resources));
    vector<vector<int>> maxNeed(processes, vector<int>(resources));
    vector<vector<int>> available;
    vector<int> sumAvailable(resources,0);
    vector<string> processesSequence;
    vector<vector<int>> remainingNeeds(processes, vector<int>(resources));
    vector<int> total(resources);
    for(int i = 0; i < resources; i++){
        // cout << "Total instances of " << i+1 << "th resources :";
        cin >> total[i];
        sumAvailable[i] = total[i];
    }
    // cout << "Resources of each process and instances :" << endl;
    for(int i = 0; i < processes; i++){
        cin>>pName[i];
        for(int j = 0; j < resources; j++){
            cin >> allocation[i][j];
            sumAvailable[j]-=allocation[i][j];
        }
        for(int j = 0; j < resources; j++){
            cin >> maxNeed[i][j];
        }
    }
    
    for(int i = 0; i < processes;  i++){
        for(int j =0; j  < resources; j++){
            remainingNeeds[i][j] = maxNeed[i][j]-allocation[i][j];
        }
    }
    available.push_back(sumAvailable);
    for(int i = 0; i <resources; i++){
        cout << available[0][i] << ' ';
    }
    cout << endl;
    while(processesSequence.size() < processes){
        bool safe = 0;
        for(int i = 0; i < processes; i++){
            bool possible = 1;
            if(remainingNeeds[i][0] == -1){
                continue;
            }
           for(int j = 0; j < resources; j++){
                if(remainingNeeds[i][j] > sumAvailable[j]){
                    possible = 0;
                    break;
                }
           }
           if(possible){
                // cout << "HERE" << endl;
                safe = 1;
                for(int j = 0; j < resources; j++){
                    sumAvailable[j] += allocation[i][j];
                    remainingNeeds[i][j] = -1;
                }
                processesSequence.push_back(pName[i]);
                available.push_back(sumAvailable);
           }
        }
           if(!safe){
            // for(auto x : available) cout << available[x] << ' ';
            cout << endl;
                cout << "This is not safe" << endl;
                return 0;
           }
    }
    cout << endl;
    for(auto x : processesSequence){
        cout << x << endl;
    }

}



// 10 5 7
// p1 0 1 0  7 5 3
// p2 2 0 0 3 2 2
// p3 3 0 2 9 0 2
// p4 2 1 1 4 2 2
// p5 0 0 2 5 3 3