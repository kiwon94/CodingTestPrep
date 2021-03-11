#include <iostream>
using namespace std;

int white = 0;
int blue = 0;

int N;
int **M;

void paper(int N, int rowstart, int colstart)
{
    int whole_plane = 0;
    int first_plane = 0;
    int second_plane = 0;
    int third_plane = 0;
    int fourth_plane = 0;

    for (int i = rowstart; i < rowstart + N; i++)
    {
        for (int j = colstart; j < colstart + N; j++)
        {
            if (M[i][j] == 1)
                whole_plane++;
        }
    }

    if (whole_plane == 0)
    {
        white++;
        return;
    }
    else if (whole_plane == N * N)
    {
        blue++;
        return;
    }
    else
    {
        for (int i = rowstart; i < rowstart + N / 2; i++)
        {
            for (int j = colstart; j < colstart + N / 2; j++)
            {
                if (M[i][j] == 1)
                    first_plane++;
            }
        }

        for (int i = rowstart; i < rowstart + N / 2; i++)
        {
            for (int j = colstart + N / 2; j < colstart + N; j++)
            {
                if (M[i][j] == 1)
                    second_plane++;
            }
        }

        for (int i = rowstart + N / 2; i < rowstart + N; i++)
        {
            for (int j = colstart; j < colstart + N / 2; j++)
            {
                if (M[i][j] == 1)
                    third_plane++;
            }
        }

        for (int i = rowstart + N / 2; i < rowstart + N; i++)
        {
            for (int j = colstart + N / 2; j < colstart + N; j++)
            {
                if (M[i][j] == 1)
                    fourth_plane++;
            }
        }

        if (first_plane == 0)
            white++;
        else if (first_plane == N * N / 4)
            blue++;
        else
            paper(N / 2, rowstart, colstart);

        if (second_plane == 0)
            white++;
        else if (second_plane == N * N / 4)
            blue++;
        else
            paper(N / 2, rowstart, colstart + N / 2);

        if (third_plane == 0)
            white++;
        else if (third_plane == N * N / 4)
            blue++;
        else
            paper(N / 2, rowstart + N / 2, colstart);

        if (fourth_plane == 0)
            white++;
        else if (fourth_plane == N * N / 4)
            blue++;
        else
            paper(N / 2, rowstart + N / 2, colstart + N / 2);
    }
}

int main()
{
    cin >> N;
    M = new int *[N];
    for (int i = 0; i < N; i++)
    {
        M[i] = new int[N];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> M[i][j];
        }
    }
    paper(N, 0, 0);
    cout << white << endl;
    cout << blue << endl;
    for (int i = 0; i < N; i++)
    {
        delete M[i];
    }
    return 0;
}