/*
 * Usually, results of competitions are based on the scores of the participants.
 * However, we are planning a change for the next year of ICPC. During the
 * registration each team will be able to enter a single positive integer: their
 * preferred place in the rank-list. We would take all these preferences into
 * account, and at the end of the competition we will simply announce a
 * rank-list that would please all of you.
 *
 * But wait... How would that rank-list look like if it won't be possible to
 * satisfy all the requests?
 *
 * Suppose that we already have a rank-list. For each team, compute the distance
 * between their preferred place and their place in the rank-list. The sum of
 * these distances will be called the badness of this rank-list.
 *
 * Goal:
 * Given team names and their preferred placements find one rank-list with the
 * minimal possible badness.
 *
 * Input:
 * The input is stored in a vector<pair<string, int>> where each pair stores
 * the team name & its preferred rank.
 *   WinOrBooze 1
 *   BallOfDuty 2
 *   WhoKnows 2
 *   BholeChature 1
 *   DCECoders 5
 *   StangeCase 7
 *   WhoKnows 7
 *
 * Output:
 * 5
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int badness(vector<pair<string, int>> teams)
{
    int n = teams.size();
    vector<int> cnt(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cnt[teams[i].second]++;
    }

    int pos = 1, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        while (cnt[i])
        {
            sum += abs(pos - i);
            cnt[i]--;
            pos++;
        }
    }

    return sum;
}

int main()
{
    vector<pair<string, int>> teams = {
        {"WinOrBooze", 1},
        {"BallOfDuty", 2},
        {"WhoKnows", 2},
        {"BholeChature", 1},
        {"DCECoders", 5},
        {"StrangeCase", 7},
        {"WhoKnows", 7},
    };

    cout << badness(teams) << endl;

    return 0;
}
