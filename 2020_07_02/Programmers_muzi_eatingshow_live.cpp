#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
bool comp(p a, p b){
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int size = food_times.size();
	vector<p> pq;
    for(int i=0; i<size; i++)   pq.push_back({food_times[i],i+1});
	sort(pq.begin(),pq.end());
	long long sum =0;
	int before= -1;
	for(auto i =pq.begin(); i<pq.end(); i++, size--){
		if(k >= (i->first- sum) * size){
			k -= (i->first- sum) * size;
			if(before != i->first) sum += (i->first-sum);
		}else{
			k %= size;
            //cout<< k << " " << food_times.size()-size <<endl;
			sort(i,pq.end(),comp);
            //cout << k+food_times.size()-size<<endl;
			return (k+i)->second;
		}
		before = i->first;
	}
	return -1;
}