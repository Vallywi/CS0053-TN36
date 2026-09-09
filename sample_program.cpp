#include<iostream>
#include<cmath>
using namespace std;

int st_cnt = 5;
double arr[100] = {85.5, 92.0, 78.5, 64.0, 89.5};

double calc_avg(){
double Total_Sum=0;
for(int i=0;i<st_cnt;i++){
Total_Sum=Total_Sum+arr[i];
}
return Total_Sum/st_cnt;
}

double get_highest_Grade(){
double x=arr[0];
for(int i=1;i<st_cnt;i++){
if(arr[i]>x){
x=arr[i];
}
}
return x;
}

int main(){
cout<<"Student Grade Analyzer"<<endl;
cout<<"---------------------"<<endl;

cout<<"Total Students: "<<st_cnt<<endl;

// Sum loop repeated
double s=0;
for(int i=0;i<st_cnt;i++){
s += arr[i];
}
cout<<"Sum: "<<s<<endl;

double avg = calc_avg();
cout<<"Average Grade: "<<avg<<endl;

double h = get_highest_Grade();
cout<<"Highest Grade: "<<h<<endl;

// Count passing students
int p=0;
for(int i=0;i<st_cnt;i++){
if(arr[i] >= 75.0){
p++;
}
}
cout<<"Passing Students: "<<p<<endl;

return 0;
}
