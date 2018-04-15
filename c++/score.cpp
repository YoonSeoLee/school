#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>

using namespace std;

int main(void)
{
    ifstream inStream;
    int numTestCases;

    inStream.open("test3.txt");

    if(inStream.fail())
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }

    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        int cases;
        int count;
        int size = 0;

        inStream >> cases;
        int score_array[cases];
        int score_array2[cases][2];

        for (int j = 0; j < cases; j++)
        {
            inStream >> score_array[j];
        }

        sort(score_array, score_array + cases);

        for (int k = 0; k < cases; k++)
        {
            count = 1;
            for (int l = k + 1; l < cases; l++)
            {
                if (score_array[k] == score_array[l])
                    count++;
            }
            score_array2[k][0] = score_array[k];
            score_array2[k][1] = count;
        }

        for (int m = 0; m < cases; m++)
        {
            if (score_array2[m][1] == 1)
                size++;
        }

        int real_score[size][2];
        real_score[0][0] = score_array2[0][0];
        real_score[0][1] = score_array2[0][1];

        int index1 = 1;
        int tmp = score_array2[0][1];
        int index2 = tmp;

        for (index1; index1 <= size; index1++)
        {
            real_score[index1][0] = score_array2[index2][0];
            real_score[index1][1] = score_array2[index2][1];
            tmp = score_array2[index2][1];
            index2 += tmp;
        }

        for (int a = 0; a < size; a++)
        {
            cout << real_score[a][0] << ' ' << real_score[a][1] << ' ';
        }

        cout << endl;
    }
    inStream.close();
    return 0;
}