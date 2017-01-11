#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cassert>
#include <tuple>
using namespace std;
 
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
 
int main() {
	vector<string> names = {
		"Name1  ",
		"Name2  ",
		"Name3  ",
		"Name4  ",
		"Name5  ",
		"Name6  ",
		"Name7  ",
	};
	vector<vector<int>> costTable = {
		{2,1,7,7,3,0,7},
		{0,0,7,7,7,7,7},
		{7,7,0,0,0,0,7},
		{0,0,7,7,7,7,7},
		{3,7,2,7,1,7,0},
		{1,7,3,7,2,7,0},
		{2,1,7,7,4,3,0},
	};

	vector<int> seats(names.size());
	REP(i, seats.size()) seats[i] = i+1;
	map<int, vector<tuple<vector<int>, vector<int>>>> ans;
	do {
		int cost = 0;
		vector<int> costs(names.size());
//		cout<<"seats "<<seats<<endl;
		REP(i, names.size()) {
			int co = costTable[i][seats[i]-1];
			co = co * co;
			costs[i] = co;
			cost += co;
//			cout<<i<<" "<<costs[i]<<endl;
		}
		ans[cost].push_back(make_tuple(seats, costs));
	} while(next_permutation(ALL(seats)));

	for(auto& kv : ans) {
		cout<<"Cost "<<kv.first<<endl;
		for(auto& cand : kv.second) {
			vector<string> b(names.size());
			auto& seats = get<0>(cand);
			auto& costs = get<1>(cand);
			REP(i, names.size()) {
				stringstream ss;
				ss<<names[i]<<" (Cost "<<costs[i]<<")";
				b[seats[i]-1] = ss.str();
			}
			REP(i, seats.size()) {
				cout<<b[i]<<"  ";
				if(i%2) cout<<endl;
			}
			cout<<endl<<endl;
		}
	}
	
    return 0;
}
