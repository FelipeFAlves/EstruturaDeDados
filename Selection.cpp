#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int> &elementos){
    for(int i=0;i<elementos.size()-1;i++){
        int jMin = i;
        for(int j = i+1;j<elementos.size();j++){
            if(elementos[j] < elementos[jMin]) jMin = j;
        }
        if(jMin != i) swap(elementos[i],elementos[jMin]);
    }
}
int main(){
    vector<int> elementos;
    srand(time(0));
    for(int i=0;i<1000;i++){
        int num = rand() % 2000;
        elementos.push_back(num);
    }
    selectionSort(elementos);
    for(auto it= elementos.begin();it != elementos.end();it++){
        cout << *it << "\n";
    }
    return 0;
}