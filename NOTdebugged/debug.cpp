//to debug codes

// Maybe the method is wrong // but still where is the memory error


// / The main function that prints
// // all combinations of size r
// // in arr[] of size n. This function
// // mainly uses combinationUtil()
// void printCombination(int arr[], int n, int r)
// {
// 	// A temporary array to store
// 	// all combination one by one
// 	int data[r];

// 	// Print all combination using
// 	// temporary array 'data[]'
// 	combinationUtil(arr, data, 0, n-1, 0, r);
// }

// /* arr[] ---> Input Array
// data[] ---> Temporary array to
// store current combination
// start & end ---> Starting and
// Ending indexes in arr[]
// index ---> Current index in data[]
// r ---> Size of a combination to be printed */
// void combinationUtil(int arr[], int data[],
// 					int start, int end,
// 					int index, int r)
// {
// 	// Current combination is ready
// 	// to be printed, print it
// 	if (index == r)
// 	{
// 		for (int j = 0; j < r; j++)
// 			cout << data[j] << " ";
// 		cout << endl;
// 		return;
// 	}

// 	// replace index with all possible
// 	// elements. The condition "end-i+1 >= r-index"
// 	// makes sure that including one element
// 	// at index will make a combination with
// 	// remaining elements at remaining positions
// 	for (int i = start; i <= end &&
// 		end - i + 1 >= r - index; i++)
// 	{
// 		data[index] = arr[i];
// 		combinationUtil(arr, data, i+1,
// 						end, index+1, r);
// 	}
// 	// for (int i = start; i <= end; i++)
// 	// {
// 	// 	data[index] = arr[i];
// 	// 	combinationUtil(arr, data, i+1,
// 	// 					end, index+1, r);
// 	// }
// }



// // Driver code
// void solve()
// {
// 	int arr[] = {1, 2, 3, 4, 5};
// 	int r = 3;
// 	int n = sizeof(arr)/sizeof(arr[0]);

// 	printCombination(arr, n, r);
// }


///////////////////////////
// codechef code 
// https://www.codechef.com/CDRV21C/problems/KLXOR

// debug this approach , without bfs

// question and or of this contest
#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                  push_front
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
//
#define time(s)       (double(clock()-s)/double(CLOCKS_PER_SEC))
#define lcm(a, b)      (a * (b / __gcd(a,b)))


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
// vector<int> arrB;
deque<int> q;
int whileCount=0;

//using set // unique nhi chiy


//now recursive function final

// int recursiveFinal() {


// 	if(q.size()==0) return 0;
// 	while(q.size()!=1) {

// 		deque<int> :: iterator it=q.end();
// 		it--;

// 		int a=q.front();
// 		int b=*it;
// 		//check this afterwards

// 		//erase these elemeents

// 		q.pop_front();
// 		q.pop_back();

// 		q.push_back(a|b);



// 	}

// 	return q.front();
// }
// void realApplicationFunction(vector<int> v) {
// 	int a=v[0];
// 	int b=v[v.size()-1];

// 	q.push_back(a&b);

// }

void recursiveCombinationFunction(queue<int > q1, vector<int> tempVec , int frameSize, int pos) {

	// base condition
	if (pos == frameSize) {
		//print the arrray
		debug(tempVec);

		//realApplicationFunction(tempVec);
	}
	// if (q1.empty()) {
	// 	//print the arrray
	// 	// debug(tempVec);

	// 	//realApplicationFunction(tempVec);
	// 	return ;
	// }

	queue<int> tempQ = q1;
	queue<int> tempQ2 = q1;
	if(!tempQ.empty()) {
		// debug(tempQ);

	}

	//in this loop
	//fill in the first(nth place)

	while(!tempQ.empty()) {
		// debug(tempQ);
		debug(whileCount++);

		int a=-2;
		if(!tempQ.empty()) {
			a=tempQ.front();
		}
		tempVec[pos] = a;

		//recursevely call for

		if (!tempQ.empty()) {
			tempQ.pop();
		}

		//find a in q1 and remove it and sent the queue forward.
		while(!tempQ2.empty() && tempQ2.front()!=a) {
			int b=tempQ2.front();
			tempQ2.pop();
			tempQ2.push(b);
		}
		if(!tempQ2.empty()) {
			tempQ2.pop();
		}

		debug(tempQ2); debug(tempVec);

		recursiveCombinationFunction(tempQ2, tempVec, frameSize, pos + 1);
	}
}

void printAllPermutations(queue<int> q1, int frameSize) {

	vector<int> tempVec(frameSize, -1);

	recursiveCombinationFunction(q1, tempVec, frameSize, 0);

}



void solve() {

	//clear global variables 
	q.clear();
	int n;
	cin>>n;

	vector<int> arrA(n,-1);

	rep(i,0,n) {
		cin>>arrA[i];
	}
	debug(arrA);

	queue<int> qq;

	rep(i,0,arrA.size()) {
		qq.push(arrA[i]);
	}

	debug(qq);

	int frameSize = 4;

	printAllPermutations(qq,frameSize);

	// debug(q);

	// //cout<<recursiveFinal()<<endl;

}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//
	// freopen("input.in", "r", stdin);
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
	cin>>t;
	while(t--) solve();
	cerr <<"Time Taken: "<<time(start);
	return 0;
}