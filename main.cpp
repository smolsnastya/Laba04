//Условие задачи: В массиве A(N,M) найти номер строки,среднее арифмитическое положительных элементов которой является наименьшей
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;
int const m=5;//количество столбцов
//void input (int n,double A[][m]);//ввод массива с клавиатуры
void output (int n,double A[][m]);
void average(int n,double A[][m],double*S);
double minaverage(int n,double A[][m]);
void inputrandom( int n,double A[][m]);



int main()
{
    int const n=3;
    double A[n][m];
    //input(n,A);
    inputrandom (n,A);
    output(n,A);
    cout<<endl<<minaverage (n,A);

    return 0 ;
}
void inputrandom( int n,double A[][m] )
{
    srand(time(NULL));
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < m; j++)
        {
            A[i][j] = (rand( ) % 20)-10;
        }
    }
}
/*void input (int n,double A[][m])//n-количество строк
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>A[i][j];
        }
    }
}*/
void output (int n,double A[][m])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {

            printf( " %5.1f ", A[i][j] );
            if(j==m-1)
            {
                cout<<endl;
            }

        }
    }
}
void average(int n,double A[][m],double*S)
{

    for(int i=0; i<n; i++)
    {
        double Sum=0,kp=0;//kp- количество положительных элементов в одной строке
        for(int j=0; j<m; j++)
        {
            if(A[i][j]>0)
            {
                Sum=Sum+A[i][j];
                kp++;

            }
        }
        S[i]=Sum/kp;
    }


}
double minaverage(int n,double A[][m])
{
    double S[n],numberline;
    average(n,A,S);
    double a=S[0];
    for(int i=0; i<n; i++)
    {

        if(S[i]<=a)
        {
            a=S[i];
            numberline=i;
        }

    }
    return  numberline;
}


