/*
 * You are actually a very busy person. You have a long list of activities. Your
 * aim is to finish much as activities as possible.
 *
 * In the given figure, if you go to date with crush, you cannot participate in
 * the coding contest and you can't watch the movie. Also if you play DotA, you
 * can't study for the exam. If you study for the exam you can't sleep
 * peacefully. The maximum number of activities that you can do for this
 * schedule is 3.
 *
 * Either you can:
 * - watch movie, play DotA and sleep peacefully (or)
 * - date witch crush, play DotA and sleep peacefully
 *
 * Given the start and finish times of activities, print the maximum number of
 * activities. Input is already stored in a vector of pairs. Each pair contains
 * the start and end of the activity.
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(pair<int, int> left, pair<int, int> right)
{
    return left.second < right.second;
}

int busyLife(vector<pair<int, int>> activities)
{
    int n = activities.size();
    if (n == 0)
        return 0;

    // Sort activities by end time
    sort(activities.begin(), activities.end(), compare);
    int i, total = 1;
    int end = activities[0].second;
    for (i = 1; i < n; i++)
    {
        if (activities[i].first >= end)
        {
            total++;
            end = activities[i].second;
        }
    }

    return total;
}

int main()
{
    vector<pair<int, int>> activities{{7, 9}, {0, 10}, {4, 5}, {8, 9}, {4, 10}, {5, 7}};
    cout << busyLife(activities) << endl;
    return 0;
}
