#include <bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> A, vector<int> B){
    vector<int> C;
    int i=0,j=0;
    while(i < A.size() && j < B.size()){
        if (A[i] <= B[j]) {
            C.push_back(A[i]);
            i++;
        } else {
            C.push_back(B[j]);
            j++;
        }
    }

    while(i < A.size()){
        C.push_back(A[i]);
        i++;
    }
    while(j < B.size()){
        C.push_back(B[j]);
        j++;
    }
    return C;
}

vector<int> mergeSort(vector<int> &elementos){
    if(elementos.size() == 1) return elementos;

    vector<int> pMetade(elementos.begin(), elementos.begin() + elementos.size() / 2);
    vector<int> sMetade(elementos.begin() + elementos.size() / 2, elementos.end());

    pMetade = mergeSort(pMetade);
    sMetade = mergeSort(sMetade);
    auto C = merge(pMetade,sMetade);
    return C;

}
int main(){
    vector<int> elementos;
    srand(time(0));
    for(int i=0;i<1000;i++){
        int num = rand() % 2000;
        elementos.push_back(num);
    }
    auto x = mergeSort(elementos);
    for(auto it= x.begin();it != x.end();it++){
        cout << *it << "\n";
    }
    return 0;
}