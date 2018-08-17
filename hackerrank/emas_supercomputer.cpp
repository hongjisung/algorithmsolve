#include "bits/stdc++.h"

using namespace std;

vector<string> split_string(string);

struct node{
    int k;
    int ceni;
    int cenj;
};

bool operator<(const node& n1, const node& n2){
    return n1.k > n2.k;
}

// Complete the twoPluses function below.
int twoPluses(vector<string> grid)
{
    multiset<node> mx;
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<int>> rowps(r + 1, vector<int>(c + 1, 0));
    vector<vector<int>> colps(r + 1, vector<int>(c + 1, 0));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 'G')
            {
                rowps[i + 1][j + 1] = rowps[i + 1][j] + 1;
            }
            if (grid[i][j] == 'G')
            {
                colps[i + 1][j + 1] = colps[i][j + 1] + 1;
            }
        }
    }

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c;j++){
            int rm = rowps[i][j];
            for(int k=1; k<=rm; k+=2){
                if( i+(k/2) <=r && j-(k/2) >=0 && colps[i+(k/2)][j-(k/2)]>=k){
                    mx.insert({(k/2), i, j-(k/2)});
                }
            }
        }
    }

    int result = 0;
    for(auto itr = mx.begin(); itr!=mx.end(); itr++){
        int diff = (*itr).k;
        int ir = (*itr).ceni;
        int ic = (*itr).cenj;
        auto sec = itr;
        sec++;
        for(sec; sec!=mx.end(); sec++){
            int diff2 = (*sec).k;
            int jr = (*sec).ceni;
            int jc = (*sec).cenj;
            if(ir == jr){
                if( abs(jc-ic)-1 >= diff+diff2){
                    if(result < (diff*4+1) * (diff2*4+1)){
                        result = (diff*4+1) * (diff2*4+1);
                        break;
                    }
                }
            }
            else if(ic == jc){
                if( abs(jr-ir)-1 >= diff+diff2){
                    if(result < (diff*4+1) * (diff2*4+1)){
                        result = (diff*4+1) * (diff2*4+1);
                        break;
                    }
                }
            }
            else{
                if( abs(jc-ic) -1 >= diff || abs(jr-ir) -1 >= diff ){
                    if(result < (diff*4+1) * (diff2*4+1)){
                        result = (diff*4+1) * (diff2*4+1);
                        break;
                    }
                }

                if( abs(jc-ic) -1 >= diff2 && abs(jr-ir) -1 >= diff2 ){
                    if(result < (diff*4+1) * (diff2*4+1)){
                        result = (diff*4+1) * (diff2*4+1);
                        break;
                    }
                }
            }
            
        }
    }

    
    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++)
    {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

    cout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
