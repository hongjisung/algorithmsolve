#include "bits/stdc++.h"

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    int len = w.size()-1;

    char cnt[26]={0,};
    char change=0;
    for(len; len>=0; len--){
        int now = w[len]-'a';
        cnt[now]++;
        for(now++; now<26; now++){
            if(cnt[now]>0){
                cnt[now]--;
                change = now+'a';
                break;
            }
        }   
        if(now<26){
            break;
        }
    }

    if(change == 0){
        return "no answer";
    }

    string output = "";
    for(int i=0; i<len; i++){
        output+=w[i];
    }
    output+=change;
    for(int i=0; i<26; i++){
        for(int j=0; j<cnt[i]; j++){
            output+=i+'a';
        }
    }
    return output;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        cout << result << "\n";
    }

    fout.close();

    return 0;
}
