#include <bits/stdc++.h>
using namespace std;
void InsertionSort(vector<int> &elementos){
    int j;
    for(int i=1;i< elementos.size();i++){
        j=i;
        while(j > 0 && elementos[j-1] > elementos[j]){
            swap(elementos[j],elementos[j-1]);
            j--;
        }
    }
}
int main(){
    vector<int> elementos;
    srand(time(0));
    for(int i=0;i<1000;i++){
        int num = rand() % 2000;
        elementos.push_back(num);
    }
    InsertionSort(elementos);
    for(auto it= elementos.begin();it != elementos.end();it++){
        cout << *it << "\n";
    }
    return 0;
}