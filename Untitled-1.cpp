/*
    Conversion of Mealy to Moore Machine
    ====================================
    by armag-pro [https://github.com/armag-pro]

    Language: C++
    Takes a Mealy machine transiton matrix as input. Outputs the Moore machine matrix.

    Also find DFA minimisation code here
         https://gist.github.com/armag-pro/8d3c6114729b40ba2a535bada54d1ccd
         
*/

#include <iostream>
using namespace std;

const int N=109;
int n, m;
bool oc[N]; // a transition from a particular symbol is present or not
int t[N][N], s[N][N]; // transitions of states and corresponding symbols 
                        // leading to them in Mealy machine
int cnt[N]; // count of the no of symbols which lead to a state in the given Mealy machine

void print_moore() {
   cout << "\nMoore Machine\n";
   cout << "===============\n";
   cout << "Q\t";
   for(int j=0; j<m; j++) cout << j << "\t";
   cout << "o/p\n\n";
   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         if(oc[i][j]) {
            cout << i;
            if(cnt[i] > 1)
               cout << j;
            cout << "\t";
            for(int jj=0; jj<m; jj++) {
               cout << t[i][jj];
               if(cnt[t[i][jj]] > 1) cout << s[i][jj];
               cout << "\t";
            }

            cout << j << endl;
         }
      }
   }
   cout << endl;
}

int main() {

    // set no of states ans symbols
      n = 4, m = 2;

      /*
         Input:
            2 0 1 0
            0 1 3 0
            1 1 0 1
            3 1 1 0
      */

      // input Mealy machine
      for(int i=0; i<n; i++) {
         for(int j=0; j<m; j++) {
            cin >> t[i][j]; cin >> s[i][j];
         }
      }

      // count the no of symbols which go to a particular state
      for(int i=0; i<n; i++) {
         oc[i].resize(m);
         for(int ii=0; ii<n; ii++) {
            for(int j=0; j<m; j++) {
               if(t[ii][j] == i) oc[i][s[i][j]] = 1;
            }
         }
      }
      for(int i=0; i<n; i++) {
         for(int j=0; j<m; j++) if(oc[i][j]) cnt[i]++;
      }
      
      print_moore();
 
    return 0; 
} 
  
