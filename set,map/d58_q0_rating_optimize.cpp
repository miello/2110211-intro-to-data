#include <iomanip>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cout << std::fixed << std::setprecision(2);
    map<string, pair<int, int>> teacher, lecture;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string _lecture, _teacher;
        int review;
        cin >> _lecture >> _teacher >> review;

        auto prev_teacher = teacher[_teacher];
        auto prev_lecture = lecture[_lecture];

        teacher[_teacher] = make_pair(prev_teacher.first + review, prev_teacher.second + 1);
        lecture[_lecture] = make_pair(prev_lecture.first + review, prev_lecture.second + 1);
    }
    
    for(auto each: lecture) {
        double review = (each.second.first + 0.0) / each.second.second;
        cout << each.first << " " << review << "\n";
    }

    for(auto each: teacher) {
        double review = (each.second.first + 0.0) / each.second.second;
        cout << each.first << " " << review << "\n";
    }
}