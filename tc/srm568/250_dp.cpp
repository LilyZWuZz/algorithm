#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN = 500;
#define pii pair<int, int> 
const int INF = 2100000000;
int dp[MAXN][10];
int data[MAXN][3];
int sz;

class BallsSeparating {
    public:
        
        int get_ans(int pos, int state){
            if(dp[pos][state]!=-1){
                return dp[pos][state];
            }
            if(pos == sz){
                if(state != (1<<3)-1){
                    return INF;
                }else{
                    return 0;
                }
            }

            int tmp = INF;
            for(int i=0; i<3; i++){
                int mask = (1<<i) | state;
                int add = data[pos][(i+1)%3] + data[pos][(i+2)%3];
                tmp = min(tmp, get_ans(pos+1, mask) + add);
            }
            dp[pos][state] = tmp;
            return tmp;
        }

        int minOperations(vector <int> red, vector <int> green, vector <int> blue) {
            memset(dp, -1, sizeof(dp));
            sz = red.size();
            for(int i=0; i<red.size(); i++){
                data[i][0] = red[i];
                data[i][1] = green[i];
                data[i][2] = blue[i];
            }
            int ans = get_ans(0, 0);
            if(ans == INF){
                return -1;
            }return ans;

        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, bool hasAnswer, int p3) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p1[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p2.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p2[i];
    }
    cout << "}";
    cout << "]" << endl;
    BallsSeparating *obj;
    int answer;
    obj = new BallsSeparating();
    clock_t startTime = clock();
    answer = obj->minOperations(p0, p1, p2);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p3 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p3;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;

    vector <int> p0;
    vector <int> p1;
    vector <int> p2;
    int p3;

    {
        // ----- test 0 -----
        int t0[] = {1,1,1};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {1,1,1};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {1,1,1};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 6;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        int t0[] = {5};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {6};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {8};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = -1;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {4,6,5,7};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {7,4,6,3};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {6,5,3,8};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 37;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        int t0[] = {7,12,9,9,7};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {7,10,8,8,9};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {8,9,5,6,13};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 77;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        int t0[] = {842398,491273,958925,849859,771363,67803,184892,391907,256150,75799};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {268944,342402,894352,228640,903885,908656,414271,292588,852057,889141};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {662939,340220,600081,390298,376707,372199,435097,40266,145590,505103};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 7230607;
        all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING