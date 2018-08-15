#include "bits/stdc++.h"

using namespace std;

vector<string> split_string(string);

// Complete the bomberMan function below.
vector<string> bomberMan(int n, vector<string> grid) {
    // 짝수면 전부 폭탄
    // 홀수면 이전에 심었던거 폭팔
    // 결국 반복
    // n=1 초기상태, n=2 전부폭탄, n=3 1이 폭팔하고 주변것 빼고 남은데
    // n=4 전부 폭탄, n=5 n=3에서 폭팔하고 주변것 빼고 남은거
    
    int r = grid.size();
    int c = grid[0].size();
    
    vector<string> allbomb(r, "");
    vector<string> step3(r, "");
    vector<string> step1(r,"");
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            allbomb[i]+=char(79);
            step3[i]+=char(79);
            step1[i]+=char(79);
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(grid[i][j]==char(79)){
                step3[i][j] = '.';
                if(i-1>=0){
                    step3[i-1][j]='.';
                }
                if(j-1>=0){
                    step3[i][j-1]='.';
                }
                if(i+1<r ){
                    step3[i+1][j]='.';
                }
                if(j+1<c){
                    step3[i][j+1]='.';
                }
            }
        }
    }
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(step3[i][j]==char(79)){
                step1[i][j] = '.';
                if(i-1>=0){
                    step1[i-1][j]='.';
                }
                if(j-1>=0){
                    step1[i][j-1]='.';
                }
                if(i+1<r ){
                    step1[i+1][j]='.';
                }
                if(j+1<c){
                    step1[i][j+1]='.';
                }
            }
        }
    }

    if(n==1){
        return grid;
    }

    switch (n%4){
        case 1 : 
            return step1;
        case 0 : 
        case 2 :
            return allbomb;
        case 3:
            return step3;

    }

    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

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
