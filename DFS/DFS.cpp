#include<iostream>
#include<stack>
#include<vector>
using namespace std; 


int main(){
    int numberNode, numberPath;
    cin >> numberNode >> numberPath; 
    vector<int> path[numberNode + 1];
    
    for(int i = 0 ; i < numberPath ; ++i){
        int u, v; 
        cin >> u >> v; 
        path[u].push_back(v);
        path[v].push_back(u);
    }

   stack<int> listNode; 
   bool dd[numberNode];
   for(int i = 0 ; i < numberNode ; ++i){
       dd[i] = false;
   }
   listNode.push(1);
   while(!listNode.empty()){
       int node = listNode.top();
       if(dd[node] == true){
           listNode.pop();
           continue;
       }
       for(int i = 0 ; i < path[node].size(); ++i){
           if(dd[path[node][i]] == false){
               listNode.push(path[node][i]);
           }
       }
       dd[node] = true;
   }
   for(int i = 1 ;i <= numberNode ; ++i){
       cout << dd[i] << " ";
   }
}
