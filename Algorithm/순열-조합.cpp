#include <iostream>
using namespace std;

int n, r;
int arr[100];
bool visit[100];

// nPr, 중복 X
void permutation(int depth){
    if(depth == r){
        for(int i = 0; i < r; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; i++){
        if(visit[i]) continue;
        visit[i] = true;
        arr[depth] = i;
        permutation(depth+1);
        visit[i] = false;
    }
}

// nPr, 중복 O
void duplicatePermutation(int depth){
    if(depth == r){
        for(int i = 0 ; i < r; i++) cout << arr[i] <<" ";
        cout << "\n";
        return;
    }
    for(int i = 1; i<= n; i++){
        arr[depth] = i;
        duplicatePermutation(depth+1);
    }
}

// nCr, 중복 X
void combination(int depth, int next){
    if(depth == r){
        for(int i = 0; i< r ; i++) cout << arr[i] <<" ";
        cout <<"\n";
        return;
    }
    for(int i = next; i<= n ;i++){
        arr[depth] = i;
        combination(depth + 1, i + 1);
    }
}

// nCr, 중복 O
void duplicateCombination(int depth, int next){
    if(depth == r){
        for(int i = 0; i< r ; i++) cout << arr[i] << " ";
        cout <<"\n";
        return;
    }
    for(int i = next; i <= n; i++){
        arr[depth] = i;
        duplicateCombination(depth+1, next);
    }
}

int main(){
    cin >> n >> r;
    permutation(0);
    cout << "===========================================================================\n";
    duplicatePermutation(0);
    cout << "===========================================================================\n";
    combination(0, 1);
    cout << "===========================================================================\n";
    duplicateCombination(0, 1);
    cout << "===========================================================================\n";
}
/*
4 3
 
 
1 2 3 
1 2 4 
1 3 2 
1 3 4 
1 4 2 
1 4 3 
2 1 3 
2 1 4 
2 3 1 
2 3 4 
2 4 1 
2 4 3 
3 1 2 
3 1 4 
3 2 1 
3 2 4 
3 4 1 
3 4 2 
4 1 2 
4 1 3 
4 2 1 
4 2 3 
4 3 1 
4 3 2 
===========================================================================
1 1 1 
1 1 2 
1 1 3 
1 1 4 
1 2 1 
1 2 2 
1 2 3 
1 2 4 
1 3 1 
1 3 2 
1 3 3 
1 3 4 
1 4 1 
1 4 2 
1 4 3 
1 4 4 
2 1 1 
2 1 2 
2 1 3 
2 1 4 
2 2 1 
2 2 2 
2 2 3 
2 2 4 
2 3 1 
2 3 2 
2 3 3 
2 3 4 
2 4 1 
2 4 2 
2 4 3 
2 4 4 
3 1 1 
3 1 2 
3 1 3 
3 1 4 
3 2 1 
3 2 2 
3 2 3 
3 2 4 
3 3 1 
3 3 2 
3 3 3 
3 3 4 
3 4 1 
3 4 2 
3 4 3 
3 4 4 
4 1 1 
4 1 2 
4 1 3 
4 1 4 
4 2 1 
4 2 2 
4 2 3 
4 2 4 
4 3 1 
4 3 2 
4 3 3 
4 3 4 
4 4 1 
4 4 2 
4 4 3 
4 4 4 
===========================================================================
1 2 3 
1 2 4 
1 3 4 
2 3 4 
===========================================================================
1 1 1 
1 1 2 
1 1 3 
1 1 4 
1 2 1 
1 2 2 
1 2 3 
1 2 4 
1 3 1 
1 3 2 
1 3 3 
1 3 4 
1 4 1 
1 4 2 
1 4 3 
1 4 4 
2 1 1 
2 1 2 
2 1 3 
2 1 4 
2 2 1 
2 2 2 
2 2 3 
2 2 4 
2 3 1 
2 3 2 
2 3 3 
2 3 4 
2 4 1 
2 4 2 
2 4 3 
2 4 4 
3 1 1 
3 1 2 
3 1 3 
3 1 4 
3 2 1 
3 2 2 
3 2 3 
3 2 4 
3 3 1 
3 3 2 
3 3 3 
3 3 4 
3 4 1 
3 4 2 
3 4 3 
3 4 4 
4 1 1 
4 1 2 
4 1 3 
4 1 4 
4 2 1 
4 2 2 
4 2 3 
4 2 4 
4 3 1 
4 3 2 
4 3 3 
4 3 4 
4 4 1 
4 4 2 
4 4 3 
4 4 4 

Process finished with exit code 0

 */
