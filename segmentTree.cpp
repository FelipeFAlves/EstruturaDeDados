#include<bits/stdc++.h>
using namespace std;
struct segmentTree{ //Arvore de soma em um intervalo
    segmentTree *right, *left;
    int from, to, value;

    segmentTree(int _from, int _to) : from(_from), to(_to), 
        right(NULL),left(NULL), value(0) {}
};

segmentTree* build(vector<int> &numeros,int left, int right){
    if(left > right) return NULL;
    segmentTree *no = new segmentTree(left,right);
    if(left == right) { //folha
        no->value = numeros[left];
    } else {
        int meio = (left + right) /2;
        no->left = build(numeros,left,meio);
        no->right = build(numeros,meio+1,right);
        if(no->left != NULL) no->value += no->left->value;
        if(no->right != NULL) no->value += no->right->value;
    }
    return no;
}
int query(segmentTree *tree, int l,int r){
    if(tree == NULL) return 0;
    if(l <= tree->from && r <= tree->to) return tree->value;
    if(tree->to < l) return 0;
    if(r < tree->from) return 0;
    return query(tree->left,l,r) + query(tree->right,l,r);
}

int update(segmentTree *tree,int achar, int val){
    if(tree = NULL) return 0;
    if(tree->to < achar) return tree->value;
    if(achar < tree->from) return tree->value;

    if(tree->from == tree->to && tree->from == achar) tree->value = val;
    else tree->value = update(tree->left, achar, val) + update(tree->right,achar,val);
    return tree->value;
}

int main(){
    vector<int> numeros;
    srand(time(0)); 
    for (int i = 0; i < 5; ++i) {
        numeros.push_back(rand() % 100);
    }

    auto raiz = build(numeros,0,numeros.size()-1);
    auto soma = query(raiz,1,4); // retorna a soma entre o segundo elemento e o quinto ([],[esse],[esse],[esse],[esse])
    cout << soma << "\n";


    return 0;
}