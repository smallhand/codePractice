#include <iostream>
#include <string>
#include <algorithm>
#define MAX 200
typedef struct _tower{
  int L;
  int W;
  int H;        
} Tower;
int lis[MAX];  //表示tower[0]到tower[k]所能堆的最高高度 
Tower tower[MAX]; 
using namespace std;
int main() {
  int n,max,t=1;
  while((cin >> n) && n){
    for(int i=0;i<n;i++){ //每一種積木有無限多個 
      cin >> tower[i].L >>tower[i].W>>tower[i].H;         
      tower[i+n].L=tower[i+2*n].W=tower[i].H;
      tower[i+n].W=tower[i+2*n].H=tower[i].L; 
      tower[i+n].H=tower[i+2*n].L=tower[i].W;        
    }
    for(int i=0;i<3*n;i++){ //選擇排序 
      max=i;
      for(int j=i+1;j<3*n;j++){
        if (((tower[max].L<tower[j].L)&&(tower[max].W< tower[j].W))||
              ((tower[max].L<tower[j].W)&&(tower[max].W<tower[j].L))) 
            max=j;
      }
      int tmp;
      tmp=tower[max].L;
      tower[max].L=tower[i].L;
      tower[i].L=tmp;
      tmp=tower[max].W;
      tower[max].W=tower[i].W;
      tower[i].W=tmp;
      tmp=tower[max].H;
      tower[max].H=tower[i].H;
      tower[i].H=tmp;                        
    }
    for(int i=0;i<3*n;i++){  //LIS初始化為個別積木的高 
      lis[i]=tower[i].H;                    
    }      
    for(int i=0;i<3*n;i++){    //使用LIS演算法 
      for(int j=i+1;j<3*n;j++){
        if (((tower[i].L>tower[j].L)&&(tower[i].W>tower[j].W))||((tower[i].L>tower[j].W)&&(tower[i].W>tower[j].L))){   //比較積木的長與寬，可以轉換寬與長 
          lis[j]=(lis[j]>(lis[i]+tower[j].H))?lis[j]:(lis[i]+tower[j].H); //LIS 若lis[i]+tower[j].H較大就取代lis[j]                   
        }       
      }                    
    }
    int max=0;
    for(int j=0;j<3*n;j++){ //找出0到3*n-1的最高積木  
      if (max<lis[j]) max=lis[j];     
    }
    cout << "Case "<<t++<<": maximum height = "<<max <<endl;      
  }
  //system("pause");
}