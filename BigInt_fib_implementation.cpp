#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

std::string add(const std::string&num1,const std::string&num2){
  std::string res;
  int carry=0,sum=0;
  int i=num1.size()-1,j=num2.size()-1;
  while(i>=0||j>=0||carry){
    sum=carry;
    if(i>=0)sum+=num1[i--]-'0';
    if(j>=0)sum+=num2[j--]-'0';
    res.push_back((sum%10)+'0');
    carry=sum/10;
  }
  reverse(res.begin(), res.end());
  return res;
}


std::string fib(int n){
  std::string a="0",b="1",c;
  for(int i=2;i<=n;i++){
    c=add(a,b);
    a=b;
    b=c;
  }
  return n==0?a:b;
}

int main(){
  int n=10000;
  std::string result=fib(n);
  std::cout << "The " << n << "th Fibonacci number is: " << result << std::endl;
}
