// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// ******************************************************************************************************
// Typedefs for common data types
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

// ******************************************************************************************************
// Constants
const int INF = 1e9; // Use LLONG_MAX for long long
const double EPS = 1e-9; // for doubles 
const double PI = acos(-1.0); 
const ll MOD = 1e9;
// ******************************************************************************************************
// Macros for shortcuts
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORD(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define deb(x) cout << #x << " = " << x << '\n' // Debug output
// ******************************************************************************************************
// stack - pop, push, empty, top. #### queue - push, empty, pop, front 
// ******************************************************************************************************
template<typename T> T gcd(T a,T b) {return (b?__(a,b):a);}
int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}
template<typename T> T lcm(T a,T b) {return (a*(b/__gcd(a,b)));}
template<typename T> T mod(T a,T b) {return (a<b ? a : a%b);}
// template<typename T> T add(T a, T b, T c){T x=a+b;return (x>=c ? x-c : x);}

// template<typename T> T mod_neg(T a,T b) {
//     a = mod(a, b);
//     if (a < 0) {
//         a += b;
//     }
//     return a;
// }

// fast exp. 
ll pow(ll x, ll n, int m) {
  if (n == 0) return 1; 
  ll a = pow(x, n/2, m); 
  if (n % 2 == 1) a = a * x % m; 
  return a; 
}
ll mod_sub(ll a, ll b) {return (((a - b) % MOD) + MOD) % MOD;}
ll mod_add(ll a, ll b) { return ((a + b) % MOD + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return (a*b) % MOD; }
// ******************************************************************************************************
// Debugging helpers
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(ll x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template<typename T> void __print(const vector<T>& v) { cerr << "{"; for (auto i : v) cerr << i << ", "; cerr << "}"; }
template<typename T1, typename T2> void __print(const pair<T1, T2>& p) { cerr << '(' << p.first << ", " << p.second << ')'; }
template<typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x); cerr << "]\n";
// ******************************************************************************************************
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

// find_by_order(x): Find the x-th element, 0-indexed.
// order_of_key(x): Output the number of elements that
// are < x.
// Both are O(log n) still!
// ******************************************************************************************************
// sorting 
void basicSort(vector<int>& vec) {
    sort(vec.begin(), vec.end());
}

void sortdesc(vector<int>& vec) {
    sort(vec.begin(), vec.end(), greater<int>());
}

// preserves order of equal elements
void stableSortVec(vector<int>& vec) {
    stable_sort(vec.begin(), vec.end());
}

//This function sorts a vector of pairs 
//based on the second element, but in case of ties, it sorts based on the first element in descending order using a lambda function.
void sortUsingLambda(vector<pair<int, int>>& vec) {
    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first > b.first; // descending order for the first element
    });
}

// This function sorts a vector of pairs (for instance, pair<int, int>) based on the second element of the pairs in ascending order.
bool customCompare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}
void sortWithCustomComparator(vector<pair<int, int>>& vec) {
    sort(vec.begin(), vec.end(), customCompare);
}

// extra functions 

// bool isPowerOfTwo(int x)
// {
// // x will check if x == 0 and !(x & (x — 1)) will check if x is a power of 2 or not
// return (x && !(x & (x — 1)));
// } 

// inline string IntToString(LL a){
//   char x[100];
//   sprintf(x,"%lld",a); string s = x;
//   return s;
// }

// inline LL StringToInt(string a){
//   char x[100]; LL res;
//   strcpy(x,a.c_str()); sscanf(x,"%lld",&res);
//   return res;
// }

// Set iterators
// for(set<int>::iterator it = s.begin(); it != s.end(); it++)
// for (auto it = s.begin(); it != s.end(); it++) {
// cout << *it << "\n";
// }

// priority_queue<int,vector<int>,greater<int>> q;

// ******************************************************************************************************
// ******************************************************************************************************
// ******************************************************************************************************


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0; 
}
