#include "bits/stdc++.h"

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    int n  = container.size();
    vector<long long> rowsum(n,0);
    vector<long long> colsum(n,0);
    for(int i=0; i<n; i++){
        long long row=0;
        long long col=0;
        for(int j=0; j<n; j++){
            row+=container[i][j];
            col+=container[j][i];
        }
        rowsum[i] = row;
        colsum[i] = col;
    }
    sort(rowsum.begin(), rowsum.end());
    sort(colsum.begin(), colsum.end());
    for(int i=0; i<n; i++){
        if(rowsum[i]!=colsum[i]){
            return "Impossible";
        }
    }
    return "Possible";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        cout << result << "\n";
    }

    fout.close();

    return 0;
}
