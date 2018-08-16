#include "bits/stdc++.h"

using namespace std;

vector<string> split_string(string);

// Complete the gridSearch function below.
string gridSearch(vector<string> G, vector<string> P) {
    // G, P에 대하여 0,0 부터 x,y 사이에서의 0~9 까지의 개수를 세서 dp에 저장
    // P크기만큼 자르는 공간들에 대해서 0~9까지의 개수가 일치하는지 확인
    // 일치하면 같은 2차원배열인지 확인
    int gr = G.size(), gc = G[0].size(), pr = P.size(), pc = P[0].size();
    vector<vector<vector<int> > > gdp(gr+1, vector<vector<int> >(gc+1, vector<int>(10,0)));
    vector<vector<vector<int> > > pdp(pr+1, vector<vector<int> >(pc+1, vector<int>(10,0)));
    for(int r = 1; r<=gr; r++){
        for(int c=1; c<=gc; c++){
            for(int i=0; i<10; i++){
                gdp[r][c][i] = gdp[r][c-1][i]+gdp[r-1][c][i] - gdp[r-1][c-1][i];
            }
        }
    }
    for(int r = 1; r<=pr; r++){
        for(int c=1; c<=pc; c++){
            for(int i=0; i<10; i++){
                pdp[r][c][i] = pdp[r][c-1][i]+pdp[r-1][c][i] - pdp[r-1][c-1][i];
            }
        }
    }

    for(int r=0; r <= gr - pr ; r++){
        for(int c=0; c <= gc - pc ; c++){
            int i=0;
            for(i; i<10; i++){
                int icnt = gdp[r+pr][c+pc][i] - gdp[r+pr][c][i] - gdp[r][c+pc][i] +gdp[r][c][i];
                if(icnt != pdp[pr][pc][i]){
                    break;
                }
            }
            if(i==10){
                bool match = true;
                for(int rr = r+1; rr<=r+pr; rr++){
                    for(int cc = c+1; cc<=c+pc; cc++){
                        if(G[rr-1][cc-1] != P[rr-r-1][cc-c-1]){
                            match = false;
                            break;
                        }
                    }
                    if(!match){
                        break;
                    }
                }
                if(match){
                    return "YES";
                }
            }
        } 
    }
    

    return "NO";
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string RC_temp;
        getline(cin, RC_temp);

        vector<string> RC = split_string(RC_temp);

        int R = stoi(RC[0]);

        int C = stoi(RC[1]);

        vector<string> G(R);

        for (int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            G[i] = G_item;
        }

        string rc_temp;
        getline(cin, rc_temp);

        vector<string> rc = split_string(rc_temp);

        int r = stoi(rc[0]);

        int c = stoi(rc[1]);

        vector<string> P(r);

        for (int i = 0; i < r; i++) {
            string P_item;
            getline(cin, P_item);

            P[i] = P_item;
        }

        string result = gridSearch(G, P);

        cout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
