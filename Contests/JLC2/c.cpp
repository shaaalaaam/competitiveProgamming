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

int findIndexInSum(int index,vector<int>* sumOfAllBinaryNumbers,vector<vector<int>>* sumIndexDependOnWhichIndex) {
	int indexInSum=-1;
	rep(i,0,(*sumIndexDependOnWhichIndex).size()) {
		rep(j,0,(*sumIndexDependOnWhichIndex)[i].size()) {
			if((*sumIndexDependOnWhichIndex)[i][j]==index) {
				indexInSum=i;
				break;
			}
		}
	}

	return indexInSum;
}

vector<int> convertDecimalToBinary(int numDecimal) {

	vector<int> numBinary(32,0);

	vector<int> tempV;
	while(numDecimal!=0) {
		int rem=numDecimal%2;
		tempV.pb(rem);
		numDecimal/=2;
	}
	// sort(tempV.begin(),tempV.end(),greater<int>());
	for(int i=0; i<tempV.size(); i++) {
		numBinary[i]=tempV[i];
	}
	return numBinary;

}

vector<int> addTwoBinaryNumbers(vector<int> bn1, vector<int> bn2) {
	//not actual proper sum
	// just for calculation
	vector<int> sumBn(32,0);
	//size must be 32
	rep(i,0,32) {
		sumBn[i]=bn1[i]+bn2[i];
	}

	return sumBn;
}

vector<pair<int,int>> mostSignificantBitUtil(vector<vector<int>> arrOrigionalBase2) {
	vector<pair<int,int>> mostSignificantBit;

	for(int i=0; i<arrOrigionalBase2.size(); i++) {
		//for each vector travel and see the significant bit
		for(int j=0; j<32; j++) {
			if(arrOrigionalBase2[i][j]==1) {
				//this index is significant one
				mostSignificantBit.pb(make_pair(i,j));
			}
		}
	}

	return mostSignificantBit;
}
pair<pair<bool,vector<pair<int,vector<int>>>>,vector<int>> sumBitOddUtilHelper(int oddNum,vector<int>* sumOfAllBinaryNumbers,vector<vector<int>>* sumIndexDependOnWhichIndex,int index,vector<int>arrOrigionalBase10) {
	//convert into binary and send a list of indexes the need to be empty
	vector<int> tempV;
	while(oddNum!=0) {
		int rem=oddNum%2;
		tempV.pb(rem);
		oddNum/=2;
	}
	vector<int> indexList;

	rep(i,0,tempV.size()) {
		if(tempV[i]==1) {
			indexList.pb(i);
		}
	}

	// now check if the places are empty in sumOfAllBinaryNumber
	bool flag=true;

	rep(i,0,indexList.size()) {
		if((*sumOfAllBinaryNumbers)[index+indexList[i]]!=0) {
			flag=false;
			break;
		}
	}

	//if flag=true
	vector<pair<int,vector<int>>> indexListAttacher;
	//should be in asencding order of power of 2 till now ********
	if(1) {
		vector<int> indexesAssociatedWithCurrentITemp=(*sumIndexDependOnWhichIndex)[index];


		debug(indexesAssociatedWithCurrentITemp);


		//sort in ascending indexesAssoxiatedwithCurrentITemp acording to size of arrOriginalBase10

		vector<int> tempVVV;
		vector<pair<int,int>> tempVForSorting;
		rep(i,0,indexesAssociatedWithCurrentITemp.size()) {
			tempVForSorting.pb(make_pair(arrOrigionalBase10[indexesAssociatedWithCurrentITemp[i]],indexesAssociatedWithCurrentITemp[i]));
		}
		debug(tempVForSorting);

		sort(tempVForSorting.begin(),tempVForSorting.end());
		indexesAssociatedWithCurrentITemp.clear();
		debug(tempVForSorting);

		rep(i,0,tempVForSorting.size()) {
			indexesAssociatedWithCurrentITemp.pb(tempVForSorting[i].sc);
		}

		int number=pow(2,index+indexList[0]);

		int sum=0;
		vector<int> tempVV;
		int j=0; //use for index of indexList;
		for(int i=0; i<indexesAssociatedWithCurrentITemp.size() && j<indexList.size(); i++)
			rep(i,0,indexesAssociatedWithCurrentITemp.size()) {

			// sum+=arrOrigionalBase10[indexesAssociatedWithCurrentITemp[i]];
			// int indexInSumOfAllBinaryForThisIndex=findIndexInSum(indexesAssociatedWithCurrentITemp[i],sumOfAllBinaryNumbers,sumIndexDependOnWhichIndex);
			// sum+=pow(2,indexInSumOfAllBinaryForThisIndex); //****
			number=pow(2,index+indexList[j]);
			debug(number);
			sum+=arrOrigionalBase10[indexesAssociatedWithCurrentITemp[i]]; //****
			tempVV.pb(indexesAssociatedWithCurrentITemp[i]);
			debug(sum);
			debug(tempVV);
			if(sum==number) {
				//now move to next indexList
				//update number

				sum=0;
				indexListAttacher.pb(make_pair(indexList[j],tempVV));
				tempVV.clear(); //**********
				j++;
				number=pow(2,index+indexList[j]);
				continue;
			}
		}
	}





	return make_pair(make_pair(flag,indexListAttacher),indexList);

}

void sumBitOddUtil(vector<int>* sumOfAllBinaryNumbers,int i,vector<vector<int>>* sumIndexDependOnWhichIndex,vector<int> arrOrigionalBase10) {

	int theOddNum=(*sumOfAllBinaryNumbers)[i];

	int start=3;
	bool flag=false;
	if(theOddNum!=1) {
		while(start<=theOddNum) {
			vector<int> indexList;
			flag=sumBitOddUtilHelper(start,sumOfAllBinaryNumbers,sumIndexDependOnWhichIndex,i,arrOrigionalBase10).fr.fr;
			indexList=sumBitOddUtilHelper(start,sumOfAllBinaryNumbers,sumIndexDependOnWhichIndex,i,arrOrigionalBase10).sc;
			vector<pair<int,vector<int>>> indexListAttacher=sumBitOddUtilHelper(start,sumOfAllBinaryNumbers,sumIndexDependOnWhichIndex,i,arrOrigionalBase10).fr.sc;

			debug(start);
			debug(indexList);
			debug(indexListAttacher);
			if(flag) {
				// decrease sum[i] by start
				(*sumOfAllBinaryNumbers)[i]-=start;

				//remove which indexes associated with this sumOfAll index
				// remove all
				(*sumIndexDependOnWhichIndex)[i].clear();

				//update values
				rep(j,0,indexList.size()) {
					(*sumOfAllBinaryNumbers)[i+indexList[j]]+=1;
				}

				//add new indexes associcated with incremented sumOfAll
				// incrementIndexUtil(indexList,);
				rep(k,0,indexListAttacher.size()) {
					rep(j,0,indexListAttacher[k].sc.size()) {

						(*sumIndexDependOnWhichIndex)[i+indexListAttacher[k].fr].push_back(indexListAttacher[k].sc[j]);//push back these too
					}

				}
			}

			//at end //for nextOddNum
			start+=2;
		}
	}

	//the loop ended and no value satisfied.
	// just do the addition

	if(flag==false) {
		theOddNum=(*sumOfAllBinaryNumbers)[i];

		vector<int> indexList;
		indexList=sumBitOddUtilHelper(theOddNum,sumOfAllBinaryNumbers,sumIndexDependOnWhichIndex,i,arrOrigionalBase10).sc;
		vector<pair<int,vector<int>>> indexListAttacher=sumBitOddUtilHelper(theOddNum,sumOfAllBinaryNumbers,sumIndexDependOnWhichIndex,i,arrOrigionalBase10).fr.sc;

		{
			// decrease sum[i] by theOddNum
			(*sumOfAllBinaryNumbers)[i]-=theOddNum;

			//remove which indexes associated with this sumOfAll index
			// remove all
			(*sumIndexDependOnWhichIndex)[i].clear();

			//update values
			rep(j,0,indexList.size()) {
				(*sumOfAllBinaryNumbers)[i+indexList[j]]+=1;
			}

			//add new indexes associcated with incremented sumOfAll
			// incrementIndexUtil(indexList,);
			rep(k,0,indexListAttacher.size()) {
				rep(j,0,indexListAttacher[k].sc.size()) {

					(*sumIndexDependOnWhichIndex)[i+indexListAttacher[k].fr].push_back(indexListAttacher[k].sc[j]);//push back these too
				}

			}
		}

		debug(theOddNum);
		debug(indexList);
		debug(indexListAttacher);
	}


}

pair<pair<bool,vector<pair<int,vector<int>>>>,vector<int>> sumBitevenUtilHelper(int evenNum,vector<int>* sumOfAllBinaryNumbers,vector<vector<int>>* sumIndexDependOnWhichIndex,int index,vector<int>arrOrigionalBase10) {
	//convert into binary and send a list of indexes the need to be empty
	vector<int> tempV;
	while(evenNum!=0) {
		int rem=evenNum%2;
		tempV.pb(rem);
		evenNum/=2;
	}
	vector<int> indexList;

	rep(i,0,tempV.size()) {
		if(tempV[i]==1) {
			indexList.pb(i);
		}
	}

	// now check if the places are empty in sumOfAllBinaryNumber
	bool flag=true;

	rep(i,0,indexList.size()) {
		if((*sumOfAllBinaryNumbers)[index+indexList[i]]!=0) {
			flag=false;
			break;
		}
	}

	//if flag=true
	vector<pair<int,vector<int>>> indexListAttacher;
	//should be in asencding order of power of 2 till now ********
	if(1) {
		vector<int> indexesAssociatedWithCurrentITemp=(*sumIndexDependOnWhichIndex)[index];


		debug(indexesAssociatedWithCurrentITemp);


		//sort in ascending indexesAssoxiatedwithCurrentITemp acording to size of arrOriginalBase10

		vector<int> tempVVV;
		vector<pair<int,int>> tempVForSorting;
		rep(i,0,indexesAssociatedWithCurrentITemp.size()) {
			tempVForSorting.pb(make_pair(arrOrigionalBase10[indexesAssociatedWithCurrentITemp[i]],indexesAssociatedWithCurrentITemp[i]));
		}
		debug(tempVForSorting);

		sort(tempVForSorting.begin(),tempVForSorting.end());
		indexesAssociatedWithCurrentITemp.clear();
		debug(tempVForSorting);

		rep(i,0,tempVForSorting.size()) {
			indexesAssociatedWithCurrentITemp.pb(tempVForSorting[i].sc);
		}

		int number=pow(2,index+indexList[0]);

		int sum=0;
		vector<int> tempVV;
		int j=0; //use for index of indexList;
		for(int i=0; i<indexesAssociatedWithCurrentITemp.size() && j<indexList.size(); i++)
			rep(i,0,indexesAssociatedWithCurrentITemp.size()) {

			// sum+=arrOrigionalBase10[indexesAssociatedWithCurrentITemp[i]];
			// int indexInSumOfAllBinaryForThisIndex=findIndexInSum(indexesAssociatedWithCurrentITemp[i],sumOfAllBinaryNumbers,sumIndexDependOnWhichIndex);
			// sum+=pow(2,indexInSumOfAllBinaryForThisIndex); //****
			number=pow(2,index+indexList[j]);
			debug(number);
			sum+=arrOrigionalBase10[indexesAssociatedWithCurrentITemp[i]]; //****
			tempVV.pb(indexesAssociatedWithCurrentITemp[i]);
			debug(sum);
			debug(tempVV);
			if(sum==number) {
				//now move to next indexList
				//update number

				sum=0;
				indexListAttacher.pb(make_pair(indexList[j],tempVV));
				tempVV.clear(); //**********
				j++;
				number=pow(2,index+indexList[j]);
				continue;
			}
		}
	}





	return make_pair(make_pair(flag,indexListAttacher),indexList);

}

void sumBitevenUtil(vector<int>* sumOfAllBinaryNumbers,int i,vector<vector<int>>* sumIndexDependOnWhichIndex,vector<int> arrOrigionalBase10) {

	int theevenNum=(*sumOfAllBinaryNumbers)[i];

	int start=2;
	bool flag=false;
	//will put condition of 2
	if(theevenNum!=1) {
		while(start<=theevenNum) {
			vector<int> indexList;
			flag=sumBitevenUtilHelper(start,sumOfAllBinaryNumbers,sumIndexDependOnWhichIndex,i,arrOrigionalBase10).fr.fr;
			indexList=sumBitevenUtilHelper(start,sumOfAllBinaryNumbers,sumIndexDependOnWhichIndex,i,arrOrigionalBase10).sc;
			vector<pair<int,vector<int>>> indexListAttacher=sumBitevenUtilHelper(start,sumOfAllBinaryNumbers,sumIndexDependOnWhichIndex,i,arrOrigionalBase10).fr.sc;

			debug(start);
			debug(indexList);
			debug(indexListAttacher);

			if(flag) {
				// decrease sum[i] by start
				(*sumOfAllBinaryNumbers)[i]-=start;

				//remove which indexes associated with this sumOfAll index
				// remove all
				(*sumIndexDependOnWhichIndex)[i].clear();

				//update values
				rep(j,0,indexList.size()) {
					(*sumOfAllBinaryNumbers)[i+indexList[j]]+=1;
				}

				//add new indexes associcated with incremented sumOfAll
				// incrementIndexUtil(indexList,);
				rep(k,0,indexListAttacher.size()) {
					rep(j,0,indexListAttacher[k].sc.size()) {

						(*sumIndexDependOnWhichIndex)[i+indexListAttacher[k].fr].push_back(indexListAttacher[k].sc[j]);//push back these too
					}

				}
				break; // I'll call this recursively
			}

			//at end //for nextevenNum
			start+=2;
		}
	}

	//the loop ended and no value satisfied.
	// just do the addition

	if(flag==false) {
		theevenNum=(*sumOfAllBinaryNumbers)[i];

		vector<int> indexList;
		indexList=sumBitevenUtilHelper(theevenNum,sumOfAllBinaryNumbers,sumIndexDependOnWhichIndex,i,arrOrigionalBase10).sc;
		vector<pair<int,vector<int>>> indexListAttacher=sumBitevenUtilHelper(theevenNum,sumOfAllBinaryNumbers,sumIndexDependOnWhichIndex,i,arrOrigionalBase10).fr.sc;

		{
			// decrease sum[i] by theevenNum
			(*sumOfAllBinaryNumbers)[i]-=theevenNum;

			//remove which indexes associated with this sumOfAll index
			// remove all
			(*sumIndexDependOnWhichIndex)[i].clear();

			//update values
			rep(j,0,indexList.size()) {
				(*sumOfAllBinaryNumbers)[i+indexList[j]]+=1;
			}

			//add new indexes associcated with incremented sumOfAll
			// incrementIndexUtil(indexList,);
			rep(k,0,indexListAttacher.size()) {
				rep(j,0,indexListAttacher[k].sc.size()) {

					(*sumIndexDependOnWhichIndex)[i+indexListAttacher[k].fr].push_back(indexListAttacher[k].sc[j]);//push back these too
				}

			}
		}
		debug(theevenNum)
		debug(indexList);
		debug(indexListAttacher);
	}


}
void solveUtilRecursive(vector<int>* sumOfAllBinaryNumbers,vector<pair<int,int>> mostSignificantBit,vector<pair<int,int>> indexPowerOf2, vector<int> arrOrigionalBase10,vector<vector<int>>* sumIndexDependOnWhichIndex) {

	//base condition
	//when all 10110101 types
	debug((vector<int>)(*sumOfAllBinaryNumbers));
	debug(*sumIndexDependOnWhichIndex);
	rep(i,0,32) {
		if((*sumOfAllBinaryNumbers)[i]>0) {
			//its a significantbit in use
			if((*sumOfAllBinaryNumbers)[i]&1) {
				// the sumbit is odd
				if((*sumOfAllBinaryNumbers)[i]>1) {
					sumBitOddUtil(sumOfAllBinaryNumbers,i,sumIndexDependOnWhichIndex,arrOrigionalBase10);
					solveUtilRecursive(sumOfAllBinaryNumbers,mostSignificantBit,indexPowerOf2,arrOrigionalBase10,sumIndexDependOnWhichIndex);
				}

			} else {
				//the sum bit is even
				//idk about 2 //lets skip it;
				sumBitevenUtil(sumOfAllBinaryNumbers,i,sumIndexDependOnWhichIndex,arrOrigionalBase10);
				solveUtilRecursive(sumOfAllBinaryNumbers,mostSignificantBit,indexPowerOf2,arrOrigionalBase10,sumIndexDependOnWhichIndex);


			}
		} else {
			//move forward in loop
		}
	}
}
pair<pair<bool,vector<pair<int,vector<int>>>>,vector<int>> makeLast2Helper(int evenNum,vector<int>* sumOfAllBinaryNumbers,vector<vector<int>>* sumIndexDependOnWhichIndex,int index,vector<int>arrOrigionalBase10) {
	//convert into binary and send a list of indexes the need to be empty
	// vector<int> tempV;
	// while(evenNum!=0) {
	// 	int rem=evenNum%2;
	// 	tempV.pb(rem);
	// 	evenNum/=2;
	// }
	vector<int> indexList;

	// rep(i,0,tempV.size()) {
	// 	if(tempV[i]==1) {
	// 		indexList.pb(i);
	// 	}
	// }

	indexList.pb(1);

	// // now check if the places are empty in sumOfAllBinaryNumber
	bool flag=true;

	// rep(i,0,indexList.size()) {
	// 	if((*sumOfAllBinaryNumbers)[index+indexList[i]]!=0) {
	// 		flag=false;
	// 		break;
	// 	}
	// }

	//if flag=true
	vector<pair<int,vector<int>>> indexListAttacher;
	//should be in asencding order of power of 2 till now ********
	if(1) {
		vector<int> indexesAssociatedWithCurrentITemp=(*sumIndexDependOnWhichIndex)[index];


		debug(indexesAssociatedWithCurrentITemp);


		//sort in ascending indexesAssoxiatedwithCurrentITemp acording to size of arrOriginalBase10

		vector<int> tempVVV;
		vector<pair<int,int>> tempVForSorting;
		rep(i,0,indexesAssociatedWithCurrentITemp.size()) {
			tempVForSorting.pb(make_pair(arrOrigionalBase10[indexesAssociatedWithCurrentITemp[i]],indexesAssociatedWithCurrentITemp[i]));
		}

		sort(tempVForSorting.begin(),tempVForSorting.end());
		indexesAssociatedWithCurrentITemp.clear();

		rep(i,0,tempVForSorting.size()) {
			indexesAssociatedWithCurrentITemp.pb(tempVForSorting[i].sc);
		}

		int number=pow(2,index+indexList[0]);

		int sum=0;
		vector<int> tempVV;
		int j=0; //use for index of indexList;
		for(int i=0; i<indexesAssociatedWithCurrentITemp.size() && j<indexList.size(); i++)
			rep(i,0,indexesAssociatedWithCurrentITemp.size()) {

			debug(number);
			// sum+=arrOrigionalBase10[indexesAssociatedWithCurrentITemp[i]];
			int indexInSumOfAllBinaryForThisIndex=findIndexInSum(indexesAssociatedWithCurrentITemp[i],sumOfAllBinaryNumbers,sumIndexDependOnWhichIndex);
			sum+=pow(2,indexInSumOfAllBinaryForThisIndex);
			tempVV.pb(indexesAssociatedWithCurrentITemp[i]);
			debug(sum);
			debug(tempVV);
			if(sum==number) {
				//now move to next indexList
				//update number

				sum=0;
				indexListAttacher.pb(make_pair(indexList[j],tempVV));
				tempVV.clear();
				j++;
				number=pow(2,index+indexList[j]);
				continue;
			}
		}
	}





	return make_pair(make_pair(flag,indexListAttacher),indexList);

}
int calculateMostSignificantBitIndex(vector<int>* sumOfAllBinaryNumbers) {
	int index=-1;
	rep(i,0,32) {
		if((*sumOfAllBinaryNumbers)[i]==1) {
			index=i;
		}
	}

	return index;
}
int calculateLeastSignificantBitIndex(vector<int>* sumOfAllBinaryNumbers) {
	int index=-1;
	rep(i,0,32) {
		if((*sumOfAllBinaryNumbers)[i]==1) {
			index=i;
			break;
		}
	}

	return index;
}



void incrementUpdaterPowerOf2(vector<pair<int,int>> vp,vector<pair<int,int>>* indexPowerOf2,vector<vector<int>>* sumIndexDependOnWhichIndex) {
	rep(i,0,vp.size()) {
		vector<int> sumIndexDependOnThisIndex=(*sumIndexDependOnWhichIndex)[vp[i].fr];
		rep(j,0,sumIndexDependOnThisIndex.size()) {

			rep(k,0,(*indexPowerOf2).size()) {
				if((*indexPowerOf2)[k].fr==sumIndexDependOnThisIndex[j]) {
					//update the value
					(*indexPowerOf2)[k].sc+=vp[i].sc;
				}
			}
		}

	}
	return;
}


void solveUtilUtil(vector<int>* sumOfAllBinaryNumbers,vector<pair<int,int>>* indexPowerOf2,vector<vector<int>>* sumIndexDependOnWhichIndex,vector<int> arrOrigionalBase10) {
	//make the last element 2
	debug((*sumOfAllBinaryNumbers));
	debug(*sumIndexDependOnWhichIndex);

	int mostSignificantBitIndex=calculateMostSignificantBitIndex(sumOfAllBinaryNumbers);
	debug(mostSignificantBitIndex);

	//calculate the zeros for each index and update the indexes associated with this index

	vector<pair<int,int>> vp;
	vector<int> v;

	rep(i,0,mostSignificantBitIndex+2) {
		v.pb((*sumOfAllBinaryNumbers)[i]);
	}
	debug(v);
	//stores index and 0's before them
	rep(i,0,v.size()) {
		vp.pb(make_pair(i,0));
	}
	debug(vp);
	int currentCount0=0;
	for(int i=v.size()-2; i>=0; i--) {
		if(v[i]==1) {
			vp[i].sc=currentCount0;
		}

		else
			if(v[i]==0) {
				currentCount0+=1;
			}
	}

	debug(vp);	//lets hope this is working



	//update the power of 2 of following indexes;
	incrementUpdaterPowerOf2(vp,indexPowerOf2,sumIndexDependOnWhichIndex);
	//+udate the power of indexes associated with least significant 1 by +1;
	int leastSignificantBitIndex=calculateLeastSignificantBitIndex(sumOfAllBinaryNumbers);
	debug(leastSignificantBitIndex);
	vp.clear();
	vp.push_back(make_pair(leastSignificantBitIndex,1));
	debug(vp);
	incrementUpdaterPowerOf2(vp,indexPowerOf2,sumIndexDependOnWhichIndex);

	//now we have all indexes with power of two to be incremented
	debug((*indexPowerOf2));

	// debug(*sumOfAllBinaryNumbers);
	// debug(*sumIndexDependOnWhichIndex);


}

vector<int> recursiveIndexPowerOf2Util(vector<pair<int,int>>* indexPowerOf2) {

	vector<int> thisAns;
	int minPow=INF;
	rep(i,0,(*indexPowerOf2).size()) {
		//find minimum power except 0;
		if((*indexPowerOf2)[i].sc<minPow && (*indexPowerOf2)[i].sc!=0 ) {
			minPow=(*indexPowerOf2)[i].sc;
		}
	}

	debug(minPow);

	rep(i,0,(*indexPowerOf2).size()) {
		//check which indexes have power greater than or equal to minPow
		//add them to the thisAns

		if((*indexPowerOf2)[i].sc>=minPow) {
			thisAns.pb((*indexPowerOf2)[i].fr);
			(*indexPowerOf2)[i].sc-=minPow;
		}
	}

	return thisAns;

}
bool checkArrayGood(vector<int>* sumOfAllBinaryNumbers) {
	bool flag=false;

	int count1=0;
	int countOfOthers=0;
	rep(i,0,(*sumOfAllBinaryNumbers).size()){
		if((*sumOfAllBinaryNumbers)[i]==1){
			count1++;
		}else if((*sumOfAllBinaryNumbers)[i]!=0){
			countOfOthers+=1;
		}
	}

	if(count1==1 && countOfOthers==0){
		//means only one 1 in whole array ie. array is already good
		flag=true;
	}

	return flag;
}
bool checkIndexPowerOf2AllSetToZero(vector<pair<int,int>>* indexPowerOf2) {

	bool flag=true;
	rep(i,0,(*indexPowerOf2).size()) {
		if((*indexPowerOf2)[i].sc!=0) {
			flag=false;
		}
	}
	return flag;
}
void indexPowerOf2Util(vector<pair<int,int>>* indexPowerOf2) {

	vector<vector<int>> ans;

	while(checkIndexPowerOf2AllSetToZero(indexPowerOf2)==false) {
		vector<int> thisAns;
		thisAns=recursiveIndexPowerOf2Util(indexPowerOf2);
		ans.pb(thisAns);
	}

	//now printAll the indexes

	debug(ans); // print it +1;

	rep(i,0,ans.size()){
		rep(j,0,ans[i].size()){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}


}
void solveUtil(vector<int> sumOfAllBinaryNumbers,vector<pair<int,int>> mostSignificantBit,vector<pair<int,int>> indexPowerOf2, vector<int> arrOrigionalBase10) {
	//can calcute the most significant bit of sumOfAllBinaryNumbers(if required)

	//calculate index on sumOfAllBinaryNums are associated with which index in origional array.
	vector<vector<int>> sumIndexDependOnWhichIndex(32);
	for(int i=0; i<mostSignificantBit.size(); i++) {
		sumIndexDependOnWhichIndex[mostSignificantBit[i].sc].pb(mostSignificantBit[i].fr);
	}

	debug(sumIndexDependOnWhichIndex);

	solveUtilRecursive(&sumOfAllBinaryNumbers,mostSignificantBit,indexPowerOf2,arrOrigionalBase10,&sumIndexDependOnWhichIndex);

	//now eveything is 101010101010 maybe 2
	if(checkArrayGood(&sumOfAllBinaryNumbers)) {
		//dont need to do anything further
		cout<<0<<endl;
	} else {
		solveUtilUtil(&sumOfAllBinaryNumbers,&indexPowerOf2,&sumIndexDependOnWhichIndex,arrOrigionalBase10);

		//now we have our info in the powers of 2
		debug(indexPowerOf2);

		indexPowerOf2Util(&indexPowerOf2);

		// debug(sumIndexDependOnWhichIndex);
		// debug(sumOfAllBinaryNumbers);

	}




}

void solve() {
	// cout<<"s"<<endl;
	int n;
	cin>>n;
	debug(n);

	vector<int> arrOrigionalBase10(n,-1);
	debug(arrOrigionalBase10);

	rep(i,0,n) {
		cin>>arrOrigionalBase10[i];
	}

	//debug arr
	debug(arrOrigionalBase10);

	// //arrOriginalBase2
	// vector<vector<int>> arrOrigionalBase2;
	// rep(i,0,n) {
	// 	arrOrigionalBase2.pb(convertDecimalToBinary(arrOrigionalBase10[i]));
	// }

	// //debug arrOrginanal Base 2
	// debug(arrOrigionalBase2);

	// vector<int> sumOfAllBinaryNumbers(32,0);

	// rep(i,0,n) {
	// 	sumOfAllBinaryNumbers=(addTwoBinaryNumbers(arrOrigionalBase2[i],sumOfAllBinaryNumbers));
	// }

	// //debug(sumOfAllBinaryNumbers);

	// debug(sumOfAllBinaryNumbers);

	// //most significantbit of all numbers .ie (index,significantPos)

	// vector<pair<int,int>> mostSignificantBit(n,make_pair(-1,-1));

	// mostSignificantBit=mostSignificantBitUtil(arrOrigionalBase2);

	// //debug most signigicant bit
	// debug(mostSignificantBit);

	// //index with power of two multiplication
	// vector<pair<int,int>> indexPowerOf2;
	// rep(i,0,n) {
	// 	indexPowerOf2.pb(make_pair(i,0));
	// }

	// debug(indexPowerOf2);

	// solveUtil(sumOfAllBinaryNumbers,mostSignificantBit,indexPowerOf2,arrOrigionalBase10);

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
	cin>>t;
	while(t--)solve();
	cerr <<"Time Taken: "<<time(start);
	return 0;
}