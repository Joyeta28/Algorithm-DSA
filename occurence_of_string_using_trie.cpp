#include<bits/stdc++.h>
using namespace std;

struct trienode{
    bool endofword;
    struct trienode *children[26];
    int count;
    trienode(){
        endofword = false;
        count = 0;
        for(int i =0;i<26;i++){
            children[i] = NULL;
        }
    }
};

void insert(struct trienode *root,string s){
    struct trienode *ncrawl = root;
    int count = 0;
    for(auto ch:s){
        int index = ch - 'a';
        if(ncrawl->children[index] == NULL){
            ncrawl->children[index] = new trienode();
        }
        ncrawl = ncrawl->children[index];
        ncrawl->count++;
    }
    ncrawl->endofword = true;
}

int search(struct trienode *root,string s){
    struct trienode *ncrwal = root;
    for(auto ch : s){
        int index = ch-'a';
        if(ncrwal->children[index] == NULL){
            return 0;
        }
        ncrwal = ncrwal->children[index];
    }
    return ncrwal->count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    struct trienode *root = new trienode();
    while(n--){
        string s;
        cin>>s;
        insert(root,s);
    }
    while(q--){
        string s;
        cin>>s;
        cout<<search(root,s)<<endl;
    }
return 0;
}
