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

    vector<pair<string, double>> sort_teacher, sort_lecture;

    for(auto each: teacher) {
        double review = (each.second.first + 0.0) / each.second.second;
        sort_teacher.emplace_back(each.first, review);
    }

    for(auto each: lecture) {
        double review = (each.second.first + 0.0) / each.second.second;
        sort_lecture.emplace_back(each.first, review);
    }

    sort(sort_lecture.begin(), sort_lecture.end());
    sort(sort_teacher.begin(), sort_teacher.end());

    for(auto each: sort_lecture) {
        cout << each.first << " " << each.second << "\n";
    }

    for(auto each: sort_teacher) {
        cout << each.first << " " << each.second << "\n";
    }

}