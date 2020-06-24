#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> p;
// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    int n = container.size();
    vector<int> types(n,0), container_size(n,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            types[j] += container[i][j];
            container_size[i] += container[i][j];
        }
    }
    sort(types.begin(), types.end());
    sort(container_size.begin(), container_size.end());
    for(int i=0; i<n; i++){
        if(types[i] != container_size[i]) return "Impossible";
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

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
