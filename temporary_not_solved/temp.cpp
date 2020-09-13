// 구현
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int dy[4]= {1,-1,0,0}, dx[4] = {0,0,1,-1};
int answer =0;
vector<vector<int>> bo;
int cv;
int cnt=0;
class cur{
public:
    int y;
    int x;
    int cnt;
    int last_y=-1;
    int last_x=-1;
};
bool chk(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(bo[i][j]) return false;
        }
    }
    return true;
}

// void bfs(int a, int b){

//     queue<cur> q;
//     cur cu;
//     cu.y=a;
//     cu.x=b;
//     cu.cnt = 0;
//     q.push(cu);
//     while(!q.empty()){
//         auto c = q.front(); q.pop();
//         int cy= c.y, cx=c.x, cnt = c.cnt;
//         for(int i=0; i<4; i++){ // normal
//             int ny = cy + dy[i], nx = cx + dx[i];
//             if(ny < 0 || ny >=4 || nx <0 || nx >=4) continue;
//             cur next;
//             if(bo[ny][nx] !=0){
//                 if(c.last_y!=-1){
//                     next.last_y = ny;
//                     next.last_x = nx;
//                     next.cnt = cnt+1;
//                 }
//                 else{
//                     if(bo[c.last_y][c.last_x] ==bo[ny][nx]){
                        
//                     }
//                 }
//             }
//         }
//         for(int d=0;d<4; d++){
//             for(int t=2;t<=3;t++){
//                 int ny =cy+ (dy[d] * t), nx = cx +(dx[d]*t);
//                 if(ny < 0 || ny >=4 || nx <0 || nx >=4) continue;
                
//             }
//         }
//     }
// }
void dfs(cur cc){
    if(chk()){
        answer = answer > cc.cnt ? cc.cnt : answer;
        return;
    }
    int cy= cc.y, cx=cc.x, cnt = cc.cnt;
    for(int i=0; i<4; i++){ // normal
        int ny = cy + dy[i], nx = cx + dx[i];
        cout << ny <<' ' << nx<<endl;
        if(ny < 0 || ny >3 || nx <0 || nx >3) continue;
        cur next;
        next.cnt = cnt+1;
        if(bo[ny][nx] !=0){ // 카드 있을떄
            if(cc.last_y==-1){ // 뒤집은거 없을때ㅐ
                next.last_y = ny;
                next.last_x = nx;
                next.cnt = cnt+1;
                dfs(next);
            }
            else{ // 뒤집은거 있을떄
                if(bo[cc.last_y][cc.last_x] ==bo[ny][nx]){ //뒤집었던게 같은거
                    int og_1=bo[cc.last_y][cc.last_x],og_2=bo[ny][nx] ;
                    bo[cc.last_y][cc.last_x] = 0;
                    bo[ny][nx] = 0;
                    next.cnt = cnt+1;
                    dfs(next);
                    bo[cc.last_y][cc.last_x]= og_1;
                    bo[ny][nx] = og_2;
                }else{// 뒤집었던게 다른거
                    cc.last_y = -1;
                    cc.last_x = -1;
                }
            }
        }else{
            next.y= ny;
            next.x = nx;
            next.cnt = cnt+1;
            dfs(next);
        }
        }
        // for(int d=0;d<4; d++){
        //     for(int t=2;t<=3;t++){
        //         int ny =cy+ (dy[d] * t), nx = cx +(dx[d]*t);
        //         if(ny < 0 || ny >=4 || nx <0 || nx >=4) continue;
        //             cur next;
        //             next.cnt = cnt+1;
        //             if(bo[ny][nx] !=0){
        //                 if(cc.last_y!=-1){
        //                     next.last_y = ny;
        //                     next.last_x = nx;
        //                     next.cnt = cnt+1;
        //                     dfs(next);
        //                 }
        //                 else{
        //                     if(bo[cc.last_y][cc.last_x] ==bo[ny][nx]){
        //                         int og_1=bo[cc.last_y][cc.last_x],og_2=bo[ny][nx] ;
        //                         bo[cc.last_y][cc.last_x] = 0;
        //                         bo[ny][nx] = 0;
        //                         next.cnt = cnt+1;
        //                         dfs(next);
        //                         bo[cc.last_y][cc.last_x]= og_1;
        //                         bo[ny][nx] = og_2;
        //                     }else{
        //                         cc.last_y = -1;
        //                         cc.last_x = -1;
        //                     }
        //                 }
        //             }
        //     }
        // }
}
int solution(vector<vector<int>> board, int r, int c) {
    bo = board;
    cur start;
    start.y= r;
    start.x = c;
    start.cnt = 0;
    if(bo[r][c] != 0){
        start.cnt =1;
        start.last_y = r;
        start.last_x = c;
    }
    dfs(start);
    return answer;
}


/*1
import re
def solution(new_id):
#     1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    new_id = new_id.lower()
# 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    new_id = re.sub('[^0-9a-z._-]','',new_id)
# 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    new_id = re.sub('[.]{2,}','.',new_id)
# 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    new_id = re.sub('^\.','',new_id)
    new_id = re.sub('\.$','',new_id)
# 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    if len(new_id) == 0:
        new_id = 'a'
        
# 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
#      만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    if len(new_id) >= 16:
        new_id = new_id[:15]
        new_id = re.sub('\.$','',new_id)
# 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    if len(new_id) <=2:
        lc = new_id[len(new_id)-1]
        while len(new_id) <3:
            new_id += lc
    
    return new_id
*/
/*2
#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
map<int, int> cnts;
void pick(string og, string candi, int idx){
    if(og.size() <= idx){
        if(candi.size() !=0) m[candi] += 1;
        cnts[candi.size()] = cnts[candi.size()] > m[candi] ? cnts[candi.size()]: m[candi];
        return;
    }
    pick( og, candi+og[idx], idx+1);//select
    pick(og, candi,idx+1);// just next
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    int os = orders.size();
    bool want[11];
    for(auto a : course){
        want[a] = 1;
    }
    
    for(int i=0; i<os; i++){
        sort(orders[i].begin(), orders[i].end());
        pick(orders[i],"",0);
    }
    for(auto n : course){
        // cnts[n] == max
        for(auto i : m){
            if(i.first.size() == n &&  i.second == cnts[n] && cnts[n] >1){
                answer.push_back(i.first);
            }

        }
    }
    sort(answer.begin(), answer.end());
    // for(auto i : answer){
    //     cout << i <<endl;
    // }
    return answer;
}
*/