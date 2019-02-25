/*
1. Record all prime numbers in an array
2. Build the sequence N as the equation in question
3. Search the index in sequence by Binary Search
Date: 2019/02/25
*/
#include <iostream>
#include <string.h>
using namespace std;

#define NUM 1000001

int prime[NUM];
int visit[NUM];
int N[NUM];

void fillPrimes(){
    memset(visit, 0, sizeof(visit));
    int index=0;
    for (int i=2; i<NUM; i++) {
        if (!visit[i]) {
            prime[index++] = i; 
            for (int j=i; j<NUM; j+=i) {
                visit[j]++;
            }
        }
    }
}

/*
某個數字的因數個數 為(次方+1)相乘: if n=(2^1)*(3^3)*(5*2)
ans: (1+1)*(3+1)*(2+1)
*/
int nod(int num) {
    int ans=1;
    int index=0;

    while (num>1) {
        int pow=0;
        while( !(num%prime[index]) ) {
            num /= prime[index];
            pow++;
        }
        index++;
        ans = ans*(pow+1);
    }    
    return ans;
}

int build(){
    int i;
    N[0] = 1; N[1] = 2; N[2] = 4;
    N[3] = 7; N[4] = 9; N[5] = 12;
    N[6] = 18;
    for (i=7; ; i++) {
        N[i] = N[i-1] + nod(N[i-1]);
        if (N[i]>NUM)
            break;
    }
    return i-1;
}

int binarySearch(int value, int bound, bool needIn){
    int low=0, high=bound;
    int index;

    while (low <= high) {
        index = (low+high)/2;
        if (value==N[index]) {
            return index;
        }
        else if (value < N[index]) {
            high = index-1;
        }
        else if (value > N[index]) {
            low = index+1;
        }
    }
    
    // 1, 2, 4, 7, 9
    // the low is larger than high, if value=5, then low is 3, N[3]=7 is in the sequence.
    if (needIn) {
        return low;
    }
    else { // if value is 8,  then low is 4, N[4]=9, is out of the sequnce should return index low-1
        return low-1;
    } 
}

int main(){
    int cases;
    int low, high;
    int lowIndex, highIndex, maxIndex;
    fillPrimes();
    maxIndex = build();
    while (cin>>cases){
        for (int i=0; i<cases; i++) {
            cin >> low >> high;
            lowIndex = binarySearch(low, maxIndex, true); // true: shoud choose the larger
            highIndex = binarySearch(high, maxIndex, false); // false: shoud choose the smaller
            
            printf("Case %d: %d\n", i+1, highIndex-lowIndex+1 );
        }
    }
    return 0;
}