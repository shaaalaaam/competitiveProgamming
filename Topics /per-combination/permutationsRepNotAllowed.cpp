#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

//Modified
#define time(s)       (double(clock()-s)/double(CLOCKS_PER_SEC))
#define lcm(a, b)      (a * (b / __gcd(a,b)))
#define endl			"\n"


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

//clock
clock_t start;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

void _print(long long t) {cerr << t;}
void _print(string t) {cerr << t;}
//void _print(int t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(deque<T> d);
template <class T> void _print(queue<T> q);
template <class T> void _print(stack<T> s);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(deque<T> d) {cerr <<"["; while(!d.empty()) {_print(d.front()); cerr<<" "; d.pop_front();} cerr<< "]"; }
template <class T> void _print(queue<T> q) {cerr <<"["; while(!q.empty()) {_print(q.front()); cerr<<" "; q.pop();} cerr<< "]"; }
template <class T> void _print(stack<T> s) {cerr <<"["; while(!s.empty()) {_print(s.top()); cerr<<" "; s.pop();} cerr <<"]";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a) {in>>a.fr>>a.sc; return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a) {out<<a.fr<<" "<<a.sc; return out;}
template<typename T,typename T1>T amax(T &a,T1 b) {if(b>a)a=b; return a;}
template<typename T,typename T1>T amin(T &a,T1 b) {if(b<a)a=b; return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;
void permutationsWithoutRepetationsUtilRecursive(queue<int> givenArrayQ,int r,vector<int> tempV,int pos){
	//base condition when pos==r
	if(pos==r){
		//we have the vector here.
		debug(tempV);
		return ;
	}
	
	//main task //to fill the pos with all possible items 
	vector<int> allItemsInCurrentQ;
	//dummy q to give values in this allItemsInCurrentArray
	queue<int> dummyQ0=givenArrayQ;
	while(!dummyQ0.empty()){
		allItemsInCurrentQ.pb(dummyQ0.front());
		dummyQ0.pop();
	}

	for(int i=0;i<allItemsInCurrentQ.size();i++){
		//dummyQ which will delte the element currently used and pass it forward.
		queue<int> dummyQ1=givenArrayQ;
		tempV[pos]=allItemsInCurrentQ[i];

		//find this element in dummyQ and delte it. 
		while(dummyQ1.front()!=allItemsInCurrentQ[i]){
			dummyQ1.push(dummyQ1.front());
			dummyQ1.pop();
		}
		if(!dummyQ1.empty()) // which it will be not
		{
			dummyQ1.pop();
		}

		// now call recusively 
		permutationsWithoutRepetationsUtilRecursive(dummyQ1,r, tempV,pos+1);

	}


	}

void	permutationsWithoutRepetations(vector<int> givenArray,int r){
	//make tempV of r size;
	vector<int> tempV(r,-1);

	//since repetations are not allowed, we need to delete elements from the ____  so making a queue;
	queue<int> givenArrayQ;
	rep(i,0,givenArray.size()){
		givenArrayQ.push(givenArray[i]);
	}

	permutationsWithoutRepetationsUtilRecursive(givenArrayQ,r,tempV,0);
}

void solve() {
	// Problems: it prints duplicate peermutation when there are dupicate elements in the given string 
	//			It is where we neeed to divide by k (where k= number of duplicates of an elements);
	// TC: npr operations ... 
	vector<int> givenArray={1,2,3,4};
	int r=3;
	permutationsWithoutRepetations(givenArray,r);
}



signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// freopen("input.in", "r", stdin)c

	// freopen("output.in", "w", stdout);
	start = clock();
#ifndef ONLINE_JUDGE
	freopen("error.in", "w", stderr);
#endif

#ifdef SIEVE
	sieve();
#endif
#ifdef NCRk
	init();
#endif
	cout << fixed << setprecision(12);

	int t=1;
	//cin>>t;
	while(t--) solve();
	cerr <<"Time Taken: "<<time(start);
	return 0;
}