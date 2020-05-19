#include <bits/stdc++.h>

using namespace std;

int main(){
    string input; int answer=0, i=0;
    cin >> input;
    // input = "ddz=z=";
    while(i<input.length()){
        if(input[i] == 'c'){
            if(input[i+1] =='=' || input[i+1] =='-'){ i +=2; answer++; continue;}
            i++; answer++;
        }else if(input[i] == 'd'){
            if(input[i+1] =='z' && input[i+2] == '='){ i+=3; answer++; continue;}
            else if(input[i+1] =='-'){ i+=2; answer++; continue;}
            i++; answer++;
        }else if(input[i] == 'l'){
            if(input[i+1] == 'j'){ i+=2; answer++; continue;}
            i++; answer++;
        }else if(input[i] == 'n'){
            if(input[i+1] == 'j'){ i+=2; answer++; continue;}
            i++; answer++;
        }else if(input[i] == 's'){
            if(input[i+1] == '='){ i+=2; answer++; continue;}
            i++; answer++;
        }else if(input[i] == 'z'){
            if(input[i+1] == '='){ i+=2; answer++; continue;}
            i++; answer++;
        }else{ i++; answer++; }
    }
    cout <<answer <<endl;
    return 0;
}