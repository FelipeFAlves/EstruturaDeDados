#include <bits/stdc++.h>
using namespace std;
int Partition(vector<int> &elementos,int left, int right){
    int pivo = elementos[left];
    int i = left + 1, j = right;
    while (i <= j) {
        while (i <= right && elementos[i] <= pivo) i++;
        while (elementos[j] > pivo) j--;
        if (i < j) swap(elementos[i], elementos[j]);
    }
    swap(elementos[left], elementos[j]);
    return j;
}
void quickSort(vector<int> &elementos,int left, int right){
    if(left < right){
        int pivo = Partition(elementos,left,right);
        quickSort(elementos,left,pivo-1);
        quickSort(elementos,pivo+1,right);
    }
}

int main(){
    vector<int> elementos;
    srand(time(0));
    for(int i=0;i<1000;i++){
        int num = rand() % 2000;
        elementos.push_back(num);
    }
    quickSort(elementos,0,elementos.size()-1);
    for(auto it= elementos.begin();it != elementos.end();it++){
        cout << *it << "\n";
    }
    return 0;
}