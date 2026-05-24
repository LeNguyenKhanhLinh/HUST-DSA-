/*Viết chương trình thực hiện công việc sau:
Một biểu thức chứa các kí tự ngoặc mở '(' hoặc ngoặc đóng ')' được gọi là biểu thức ngoặc đúng nếu chúng đóng mở hợp lý, ví dụ biểu thức (()) hoặc ()() đều là biểu thức ngoặc đúng. Với đầu vào là một xâu kí tự độ dài n lưu trong dãy a
1
, a
2
, ..., a
n
 gồm 3 số 0, 1, 2 ứng với 3 loại kí tự là dấu hỏi '?' hoặc  kí tự ngoặc mở '(' hoặc ngoặc đóng ')' , yêu cầu in ra tất cả các trường hợp là biểu thức ngoặc đúng khi thay kí tự dấu hỏi bằng ngoặc đóng hoặc ngoặc mở dưới dạng các con số tương ứng.
Ví dụ 1002 ứng với (??) sẽ in ra 1122 và 1212 ứng với (()) và ()().
Input
Dòng 1: ghi số nguyên dương n (1 <= n <= 100)
Dòng 2: ghi các số nguyên dương a
Output
Ghi ra dãy các biểu thức ngoặc đúng
-----------------------------------
Example:
Input
4
1 0 0 2
Output
1122 1212
*/
#include <stdio.h>
int n;
int a[1000000];
int tong=0;
int sl0=0;

void print(){
  int s1=0;
  int s2=0;
  for(int i=0;i<n;i++){
    if(a[i]==-3){
      s1=s1+1;
    }
    if(a[i]==3){
      s2=s2+1;
      if(s1<s2){
        return;
      }
    }
  }
  for(int i=0;i<n;i++){
    if(a[i]==-3) printf("1");
    if(a[i]==3) printf("2");
  }
  printf(" ");
}
void Try(int k){
  if(k==n){
    if(tong==0){
    print();
    return;
  }}
  else if(k==0&&a[k]==0){
    a[k]=-3;
    tong=tong+a[k];
    sl0=sl0-1;
  }
  if(a[k]==0){
      if (tong>0){
        if(sl0*(-3)+tong<0){
          for(int v=-3;v<=3;v=v+6){
            a[k]=v;
            tong=tong+a[k];
            sl0=sl0-1;
            Try(k+1);
            tong = tong - a[k];
            sl0 = sl0 + 1;
            a[k] = 0;
          }
        }
        else{
          a[k]=-3;
          tong=tong+a[k];
          sl0=sl0-1;
          Try(k+1);
          tong = tong - a[k];
          sl0 = sl0 + 1;
          a[k] = 0;
        }
      }
      else if(tong==0){
        for(int v=-3;v<=3;v=v+6){
            a[k]=v;
            tong=tong+a[k];
            sl0=sl0-1;
            Try(k+1);
            tong = tong - a[k];
            sl0 = sl0 + 1;
            a[k] = 0;
      }}
      else{

        if(sl0*(3)+tong>0){
          for(int v=-3;v<=3;v=v+6){
            a[k]=v;
            tong=tong+a[k];
            sl0=sl0-1;
            Try(k+1);
            tong = tong - a[k];
            sl0 = sl0 + 1;
            a[k] = 0;
          }
        }
        else{
          a[k]=3;
          tong=tong+a[k];
          sl0=sl0-1;
          Try(k+1);
          tong = tong - a[k];
          sl0 = sl0 + 1;
          a[k] = 0;
    }

}}
  if(a[k]!=0){
    Try(k+1);

  }
}
int main(){
    scanf("%d",&n);
    if(n%2!=0){
      return 0;
    }
    for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
      if(a[i]==1){
        a[i]=-3;
      }
      else if(a[i]==2){
        a[i]=3;
      }
      else if(a[i]==0){
        sl0++;
      }
      tong=tong+a[i];
    }
    if (sl0==0&&tong!=0){
      printf("\n");
      return 0;
    }
    Try(0);
    return 0;
}

