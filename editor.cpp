#include<stdio.h>
#include<iostream>
#include<list>
#include<string>
using namespace std;
main() {
    int N;
    char c;
    list<string> v;
    string str;
    list<string>::iterator it = v.end();

    cin >> N;
    while(N--) {
        cin>>c;
        if(c=='i') {
            cin>>str;
            v.insert(it,str);
            
        }
        else if(c=='l') {
            if(it!=v.begin())
                it--;
        }
        else if(c=='r') {
            if(it!=v.end())
                it++;
        }
        else if(c=='b'){
            list<string>::iterator it2 = it;
            
            if(it!=v.begin()){
                v.erase(--it);
                it = it2;
            }
        }
        else if(c=='d'){
            list<string>::iterator it2 = it;
            it2++;
            if(it!=v.end()) {
                v.erase(it);
                it = it2;
            }
        }
    }
    
        for(list<string>::iterator it2 = v.begin(); it2 != v.end(); it2++) {
            cout << *it2 << " ";
        }
}