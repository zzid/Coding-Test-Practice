#include <bits/stdc++.h>
using namespace std;
int n; 
int arr[100][100];
bool visited[100][100];
const int dy[4] = {1,-1,0,0}, dx[4] = {0,0,-1,1};
typedef pair<int, int> p;
void bfs(p start){
    queue<p> q;
    q.push(start);
    while(!q.empty()){
        auto idx = q.front(); q.pop();
        int y = idx.first, x = idx.second;
        if(visited[y][x]) continue;
        visited[y][x] = 1;
        for(int i=0; i<4; i++){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny <0 || ny >=n || nx < 0 || nx >=n) continue;
            if(arr[ny][nx] == arr[y][x]) q.push({ny,nx});
        }
    }
}
p visitTest(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]) return {i,j};
        }
    }
    return {-1,-1};
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char color;
            scanf(" %c", &color);
            if(color == 'R') arr[i][j] = 1;
            else if(color == 'G') arr[i][j] = 2;
            else if(color == 'B') arr[i][j] = 3;
        }
    }
    // R == G << weak
    p next = {0,0};
    int answer1 =0, answer2 =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                bfs({i,j});
                answer1++;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 2) arr[i][j] = 1;
            visited[i][j] = 0;
        }   
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                bfs({i,j});
                answer2++;
            }
        }
    }
    printf("%d", answer1, answer2);
    return 0;
}