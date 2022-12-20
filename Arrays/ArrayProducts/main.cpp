/*
 * Implement a function that takes in a vector of integers, and returns a vector
 * of the same length, where each element in the output array is equal to the
 * product of every other number in the input array. Solve this problem without
 * using division.
 *
 * In other words, the value at output[i] is equal to the product of every other
 * number in the input array other than input[i]. You can assume that answer can
 * be stored inside int datatype and no-overflow will occur due to products.
 */
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << arr[i];
        else
            cout << arr[i] << ", ";
    }

    cout << endl;
}

vector<int> arrayProductsBruteForce(vector<int> arr)
{
    int n = arr.size();
    if (n == 1)
        return {0};

    vector<int> products(n, 0);
    for (int i = 0; i < n; i++)
    {
        int product = 1;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            product *= arr[j];
        }

        products[i] = product;
    }

    return products;
}

vector<int> arrayProductsPrecomputed(vector<int> arr)
{
    int n = arr.size();
    if (n == 1)
        return {0};

    vector<int> lefts(n, 1), rights(n, 1), products(n, 1);

    int i, temp = 1;
    for (i = 0; i < n; i++)
    {
        lefts[i] *= temp;
        temp *= arr[i];
    }

    temp = 1;
    for (i = n - 1; i >= 0; i--)
    {
        rights[i] *= temp;
        temp *= arr[i];
    }

    for (i = 0; i < n; i++)
        products[i] = lefts[i] * rights[i];

    return products;
}

// Best Solution!
vector<int> arrayProductsPrecomputedTemp(vector<int> arr)
{
    int n = arr.size();

    if (n == 1)
        return {0};

    /* In this loop, temp variable contains product of
       elements on left side excluding arr[i] */
    int i, temp = 1;
    vector<int> products(n, 1);
    for (i = 0; i < n; i++)
    {
        products[i] = temp;
        temp *= arr[i];
    }

    // Initialize temp to 1 for product on right side
    temp = 1;

    /* In this loop, temp variable contains product of
       elements on right side excluding arr[i] */
    for (i = n - 1; i >= 0; i--)
    {
        products[i] *= temp;
        temp *= arr[i];
    }

    return products;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5};

    vector<int> first = arrayProductsBruteForce(arr);
    printVector(first);

    vector<int> second = arrayProductsPrecomputed(arr);
    printVector(second);

    vector<int> third = arrayProductsPrecomputedTemp(arr);
    printVector(third);

    return 0;
}
