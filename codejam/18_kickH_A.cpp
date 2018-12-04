#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
// total - forbiddens
// overlap prefixes

struct newstr{
    string s;
};

bool operator<(newstr s1, newstr s2){
    if( s1.s.size() < s2.s.size() ){
        return true;
    }
    if( s1.s.size() > s2.s.size() ){
        return false;
    }

    return s1.s<s2.s;
}

int main(){
    int T=0;
    cin>>T;
    for(int tc=1; tc<=T; tc++){
        int N=0,P=0;
        cin>>N>>P;

        // cout<<tc<<" "<<N<<" "<<P<<"\n";
        // make prefix list
        set<newstr> pre;
        string s="";
        for(int i=0; i<P; i++){
            cin>>s;
            // cout<<s<<"\n";
            pre.insert(newstr{s});
        }

        // for( set<newstr>::iterator itr = pre.begin(); itr!=pre.end(); itr++){
        //     cout<<(*itr).s<<"\n";    
        // }

        // eliminate subprefix
        set<newstr>::iterator back = pre.end();
        back--;
        while(back!=pre.begin()){
            string strback = (*back).s;
            // cout<<strback<<"\n";

            set<newstr>::iterator itr = pre.begin();
            bool iserase = false;
            for(itr; itr!=back; itr++){
                string stritr = (*itr).s;
                auto res = mismatch(stritr.begin(),stritr.end(), strback.begin());
                if(res.first == stritr.end()){
                    back--;
                    pre.erase(newstr{strback});
                    iserase = true;
                    break;
                }
            }
            if( !iserase){
                back--;
            }
        }
        

        // total count
        long long tot = (1ll<<N);
        // submit prefix
        for( set<newstr>::iterator itr = pre.begin(); itr!=pre.end(); itr++){
            tot = tot - (1ll<< (N - (*itr).s.size()) );
        }

        cout<<"Case #"<<tc<<": "<<tot<<"\n";
    }

    return 0;
}