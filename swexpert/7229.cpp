#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long 

struct cake {
  ll data;
  int div;
};

struct cmp{
  bool operator()(cake a, cake b) {
    return (double)a.data / (double)a.div < (double)b.data / (double)b.div;
  }
};

double getdiv(cake c) {
  return (double)c.data/(double)c.div;
}

int main() {
  int T=0;
  cin>>T;
  for(int tc=1; tc<=T; tc++) {
    int N=0;
    cin>>N;

    priority_queue<cake, vector<cake>, cmp> cakes;
    double largest = -1.0, smallest = 10000000000.0;
    for(int i=0; i<N; i++) {
      ll data = 0;
      cin>>data;
      cakes.push(cake{data, 1});
      if((double)data > largest) {
        largest = (double)data;
      }
      if ((double)data < smallest) {
        smallest = (double)data;
      }
    }

    int M=0;
    cin>>M;
    
    double answer = largest - smallest;
    for(int i=0; i<M; i++) {
      cake c = cakes.top();
      cakes.pop();

      c.div++;
      cakes.push(c);

      largest = getdiv(cakes.top());
      if(getdiv(c) < smallest) {
        smallest = getdiv(c);
      }

      answer = min(answer, largest-smallest);
    }

    cout<<fixed;
    cout.precision(10);
    cout<<"#"<<tc<<" "<<answer<<"\n";
  }
  return 0;
}