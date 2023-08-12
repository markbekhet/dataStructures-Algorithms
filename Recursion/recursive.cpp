#include "recursive.h"
#include <stdio.h>

void fun(int n)
{
    if(n > 0){
        printf("%d\n", n);
        fun(n-1);
    }
}

int recursiveAddition(int n){
    if (n > 0){
        return recursiveAddition(n-1) + n;
    }
    return 0;
}


int recursiveAdditionWithStatic(int n){
    static int i = 0;
    if (n > 0){
        i++;
        return recursiveAdditionWithStatic(n-1) + i;
    }
    return 0;
}

int x = 0;
int recursiveAdditionWithGlobale(int n){
    if (n > 0){
        x++;
        return recursiveAdditionWithGlobale(n-1) + x;
    }
    return 0;
}

void treeRecursion(int n)
{
    if(n > 0){
        printf("%d ", n);
        treeRecursion(n-1);
        treeRecursion(n-1);
    }
}

void indirectRecursionMainFun(int n)
{
    if(n > 0){
        printf("%d ",n);
        indirectRecursionSecondFun(n-1);
    }
}

void indirectRecursionSecondFun(int n)
{
    if(n > 1){
        printf("%d ", n);
        indirectRecursionMainFun(n/2);
    }
}

int sumNNaturalNumber(int n)
{
    if(n == 0) return 0;
    else return sumNNaturalNumber(n-1) + n;
}

int recursiveFactorial(int n)
{
    if(n == 0) return 1;
    return recursiveFactorial(n-1)*n;
}

int iterativeFactorial(int n)
{
    int s = 1;
    for(int i = 1; i<= n; i++){
        s *= i;
    }
    return s;
}

int recursivePower(int base, int power)
{
    if(power==0) return 1;
    return recursivePower(base, power-1) * base;
}

int recursivePowerV2(int base, int power)
{
    if(power == 0 ) return 1;
    else if(power % 2 == 0) return recursivePowerV2(base * base, power/2);
    else return base * recursivePowerV2(base * base, (power - 1)/2);
}

int iterativePower(int base, int power)
{
    int p = 1;
    for(int i = power; i >= 1; i--) p*= base;
    return p;
}

double taylorSeries(int b, int n)
{
    static double p = 1 , f = 1;
    double r;
    if(n == 0) return 1;
    else{
        r= taylorSeries(b, n - 1);
        p = p * b;
        f = f* n;
        return r + p/f;
    }
    return 0;
}

double HornerRecursiveTaylorSeries(int b, int n)
{
    static double s = 1;
    if(n==0) return s;
    s = 1 +b*s/n;
    return HornerRecursiveTaylorSeries(b, n-1);
}

double HornerIterativeTaylorSeries(int b, int n)
{
    double s = 1;
    for(;n>0; n--){
        s = 1 + b*s/n;
    }
    return s;
}

int fibIter(int n)
{
    int t0=0, t1 = 1,s = 0, i;

    if(n<=1) return n;

    for(i=2; i<=n;i++){
        s = t0+t1;
        t0 = t1;
        t1 = s;
    }

    return s;
}

int fibRec(int n)
{
    if(n <= 1) return n;
    return fibRec(n-2) + fibRec(n-1);
}

int nCr(int n, int r){
    return iterativeFactorial(n)/ (iterativeFactorial(r)*iterativeFactorial(n-r));
}

int nCrPascalTriangle(int n, int r)
{
    if(r == 0 || n==r){
        return 1;
    }
    return nCrPascalTriangle(n-1, r-1) + nCrPascalTriangle(n-1, r);
}

void towerOfHanoi(int n, char a, char b, char c){
    if(n > 0){
        towerOfHanoi(n-1, a, c, b);
        printf("%c to %c \n", a, c);
        towerOfHanoi(n-1, b, a, c);
    }
}