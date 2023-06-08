/*
 * Given number of pages in n different books and m students.
 * The books are arranged in any order (not necessarily ascending) of number
 * of pages. Every student is assigned to read some consecutive segment of
 * books. The task is to assign books in such a way that the maximum number of
 * pages assigned to a student is minimum.
 *
 * Find the maximum number of pages that a student will have to read.
 *
 * Sample Input:
 *   books = {10, 20, 30, 15}
 *   students = 2
 *
 * Sample Output: 45
 *
 * Explanation:
 *
 * There are 2 number of students. Books can be distributed in following
 * fashion:
 *
 * 1. [10] and [20, 30, 15]
 *    Max number of pages is allocated to student 2 with 65 pages.
 *
 * 2. [10, 20] and [30, 15]
 *    Max number of pages is allocated to student 2 with 45 pages.
 *
 * 3. [10, 20, 30] and [15]
 *    Max number of pages is allocated to student 1 with 60 pages.
 *
 * Of the 3 cases, Option 2 has the minium pages 45.
 */

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int> books, int k, int mid)
{
    int n = books.size(),
        currentStudent = 0,
        students = 1;

    for (int i = 0; i < n; i++)
    {
        if (currentStudent + books[i] > mid)
        {
            students++;
            currentStudent = books[i];

            if (students > k)
            {
                return false;
            }
        }
        else
        {
            currentStudent += books[i];
        }
    }

    return true;
}

int binarySearchApproach(vector<int> books, int k)
{
    int n = books.size(),
        start = 0, end = 0;

    for (int pages : books)
    {
        start = max(start, pages);
        end += pages;
    }

    int ans = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (isPossible(books, k, mid))
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> books = {10, 20, 30, 15};
    int students = 2;

    cout << binarySearchApproach(books, students) << endl;

    return 0;
}
