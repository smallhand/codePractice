/*
1. build primes array
2. use binaray search to find the index of N
3. count the # of output need print
    Notice: C*2 or C*2-1 may out of the # of the index of N
Date: 2019/02/28
*/
#include <iostream>
#include <string.h>
#define NUM 1000
using namespace std;

int prime[NUM];
int visit[NUM];

int buildPrime(){
    memset(visit, 0, sizeof(visit));

    prime[0]=1;
    int index=1;

    for (int i=2; i<NUM; i++) { // prime[1]=2
        if(!visit[i]){
            prime[index++] = i;
            for (int j=i+i; j<NUM; j+=i) {
                visit[j] = 1;
            }
        }
    }
    return index-1;
}

int binarySearch(int target, int right){
    int left=0, middle;

    while (left<=right) {
        middle = (left+right)/2;
        if (target == prime[middle]) {
            return middle;
        }
        else if (target < prime[middle]) {
            right = middle-1;
        }
        else { // target > prime[middle]
            left = middle+1;
        }
    }
    return left-1;
}

int main(){
    int index = buildPrime();
    int N, C;
    int total, start, tmp;
    while (cin >> N >> C) {
        total = binarySearch(N, index)+1; // 小於N的primes數量 

        if (total%2) {// 奇數
            tmp = (C*2)-1;
        }
        else {
            tmp = C*2;
        }
        printf("%d %d: ", N, C);

        if (tmp>total) { // if out of the range
            for (int i=0; i<total; i++) {
                if (i==total-1) {
                    cout << prime[i] << endl << endl;
                }
                else {
                    cout << prime[i] << " ";
                }
            }
        }

        else {
            start =  (total-tmp)/2;
            for (int i=start; i<start+tmp; i++) {
                if (i==start+tmp-1) {
                    cout << prime[i] << endl << endl;
                }
                else {
                    cout << prime[i] << " ";
                }
            }
        }
    }
    return 0;
}