#include<iostream>
#include<string.h>
#include<stack>
#include<vector>
using namespace std;

vector<int> nums;
int tree[1000000];
void buildTree(int i, int left, int right){
    if(left == right ){
        tree[i] = nums[left];
        return ; 
    }
    else{
        int mid = ( left + right) / 2; 
        buildTree(2 * i , left, mid );
        buildTree(2 * i + 1, mid + 1 , right);
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
}


int main(){
    int n ;
    cin >> n; 
    nums.push_back(0);
    for(int i = 0 ; i < n ; ++i){
        int data; 
        cin >> data; 
        nums.push_back(data);
    }

    buildTree(1, 1, nums.size() - 1);

    for(int i = 1; i < 4 * n ; ++i){
        cout << tree[i] << " ";
    }

}