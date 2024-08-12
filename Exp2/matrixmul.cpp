#include <bits/stdc++.h>
using namespace std;

class Experiment2
{
private:
    vector<vector<int>> m1, m2;
    int i1, j1, i2, j2;

public:
    Experiment2(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2)
        : m1(matrix1), m2(matrix2), i1(matrix1.size()), j1(matrix1[0].size()), i2(matrix2.size()), j2(matrix2[0].size()) {}

    vector<vector<int>> getProduct()
    {

        vector<vector<int>> product(i1, vector<int>(j2, 0));

        for (int i = 0; i < i1; ++i)
        {
            for (int j = 0; j < j2; ++j)
            {
                for (int k = 0; k < j1; ++k)
                {
                    product[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }

        return product;
    }

    void printMatrix(const vector<vector<int>> &matrix)
    {
        for (const auto &row : matrix)
        {
            for (const auto &elem : row)
            {
                cout << elem << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int i1, j1, i2, j2;

    cout << "Enter dimensions of the first matrix:";
    cin >> i1 >> j1;
    vector<vector<int>> matrix1(i1, vector<int>(j1));

    cout << "Enter data for the first matrix:" << endl;
    for (int i = 0; i < i1; ++i)
    {
        for (int j = 0; j < j1; ++j)
        {
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter dimensions of the second matrix: ";
    cin >> i2 >> j2;
    vector<vector<int>> matrix2(i2, vector<int>(j2));

    cout << "Enter data for the second matrix:" << endl;
    for (int i = 0; i < i2; ++i)
    {
        for (int j = 0; j < j2; ++j)
        {
            cin >> matrix2[i][j];
        }
    }

    Experiment2 experiment(matrix1, matrix2);

    cout << "Product of the matrices:" << endl;
    vector<vector<int>> product = experiment.getProduct();
    experiment.printMatrix(product);

    return 0;
}
