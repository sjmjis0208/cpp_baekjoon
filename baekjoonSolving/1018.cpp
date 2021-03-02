#include <iostream>
#include <limits.h>
using namespace std;
#define white = 'W';
#define black = 'B';
int main()
{
    int column, row = 0;
    cout << "행 열" << endl;
    cin >> column >> row;

    char **board = new char *[column];
    for (int i = 0; i < column; i++)
    {
        board[i] = new char[row];
    }
    cout << "체스판 상태" << endl;
    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cin >> board[i][j];
        }
    }
    /*char **new_board = new char *[column];
    for (int i = 0; i < column; i++)
    {
        new_board[i] = new char[row];
    }*/
    char new_board[8][8];

    /*아이디어:  크기가 8을 넘어가면 가능한 경우는 변 길이 - 8만큼 있다.
    문제 :왼쪽 위가 B였는데 이걸 기준으로 바꾸는 것보다 왼쪽 위를  W로 바꾸는 게 더 적은 횟수일 때
    */
    int col_dif = column - 7;
    int row_dif = row - 7;
    int count_1 = 0;
    int count_2 = 0;
    long long min = LLONG_MAX;
    for (int i = 0; i < col_dif; i++)
    {
        for (int j = 0; j < row_dif; j++)
        {

            for (int x = 0; x < 8; x++)
            {
                for (int y = 0; y < 8; y++)
                {
                    new_board[x][y] = board[x + i][y + j];
                }
            }
            count_1 = 0; //왼쪽 위 검정(아님 흰색)
            count_2 = 0; //왼쪽 위 흰색 (아님 검정)

            for (int x = 0; x < 7; x++)
            {
                for (int y = 0; y < 7; y++)
                {
                    if (new_board[x][y] == new_board[x][y + 1])
                    {
                        new_board[x][y + 1] = (new_board[x][y] == 'W') ? 'B' : 'W';
                        count_1++;
                    }
                    if (new_board[x][y] == new_board[x + 1][y])
                    {
                        new_board[x + 1][y] = (new_board[x][y] == 'W') ? 'B' : 'W';
                        count_1++;
                    }
                }
            }
            //맨 오른쪽 아래 칸 고려
            if(new_board[7][7] == new_board[7][6]){
                new_board[7][7] = (new_board[7][7] == 'W') ? 'B' : 'W';
                count_1++;
            }

            //왼쪽 위를 다른 색으로 칠할 경우
            for (int x = 0; x < 8; x++)
            {
                for (int y = 0; y < 8; y++)
                {
                    new_board[x][y] = board[x + i][y + j];
                }
            }
            //왼 쪽 위 다른 색으로 바꾸고 계산 시작
            new_board[0][0] = (new_board[0][0] == 'W') ? 'B' : 'W';
            for (int x = 0; x < 7; x++)
            {
                for (int y = 0; y < 7; y++)
                {
                    if (new_board[x][y] == new_board[x][y + 1])
                    {
                        new_board[x][y + 1] = (new_board[x][y] == 'W') ? 'B' : 'W';
                        count_2++;
                    }
                    if (new_board[x][y] == new_board[x + 1][y])
                    {
                        new_board[x + 1][y] = (new_board[x][y] == 'W') ? 'B' : 'W';
                        count_2++;
                    }
                }
            }
            //맨 오른쪽 아래 칸 고려
            if(new_board[7][7] == new_board[7][6]){
                new_board[7][7] = (new_board[7][7] == 'W') ? 'B' : 'W';
                count_2++;
            }

            if (count_1 < count_2)
                min = (count_1 < min) ? count_1 : min;
            else
                min = (count_2 < min) ? count_2 : min;
        }
    }
    cout << min << endl;
    
}