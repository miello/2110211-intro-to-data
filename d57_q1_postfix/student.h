#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>
#include <stack>

using namespace std;

int eval_postfix(vector<pair<int,int> > v) {
  stack<int> s;
  for(auto &i: v) {
    if (i.first) {
      s.push(i.second);
    } else {
      int b = s.top();
      s.pop();

      int a = s.top();
      s.pop();

      int result;
      if(i.second == 0) {
        result = a + b;
      } else if(i.second == 1) {
        result = a - b;
      } else if(i.second == 2) {
        result = a * b;
      } else if(i.second == 3) {
        result = a / b;
      }

      s.push(result);
    }
  }

  return s.top();
}

#endif
