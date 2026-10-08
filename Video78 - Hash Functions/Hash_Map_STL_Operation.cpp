#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    map<string,int> m;

    pair<string,int> p = make_pair("Shahnawaz" , 8);
    pair<string,int> q("Shoaib" , 1);
    
    m.insert(p);
    m.insert(q);
    m["Shaheen"] = 4;

    cout<<m["Shahnawaz"]<<endl;
    cout<<m.at("Shoaib")<<endl;

    cout<<m["unknown"]<<endl;
    cout<<m.at("unknown")<<endl;

    cout<<m.size()<<endl;
    
    cout<<m.count("Shoaib")<<endl;
    
    m.erase("Shoaib");
    cout<<m.size()<<endl;

    // for(auto it : m){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    map<string,int> :: iterator it = m.begin();

    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    return 0;
}