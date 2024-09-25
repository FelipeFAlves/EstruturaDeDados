#include <bits/stdc++.h>
using namespace std;
vector<int> BubbleSort(vector<int> &elementos) {
    for (int i = 0; i < elementos.size() - 1; i++) {
        for (int j = 0; j < elementos.size() - i - 1; j++) {
            if (elementos[j] > elementos[j + 1]) {
                swap(elementos[j], elementos[j + 1]);
            }
        }
    }
    return elementos;
}

int main(){
    vector<int> elementos;
    srand(time(0));
    for(int i=0;i<1000;i++){
        int num = rand() % 2000;
        elementos.push_back(num);
    }
    auto ordenado = BubbleSort(elementos);
    for(auto it= ordenado.begin();it != ordenado.end();it++){
        cout << *it << "\n";
    }

    return 0;
}