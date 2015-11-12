#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

void randnum(double* p, const int N);
void print(double* p, const int N);
double meannum(double* p, const int N);
double varnum(double* p, const int N);

int main(){
   const int N = 100;
   double p[N];
   double mean, var;
   
   srand(time(NULL));

   randnum(p,N);
   //print(p,N);
   mean = meannum(p,N);
   var = varnum(p,N);

   cout << "Mean = " << mean << endl;
   cout << "Variance = " << var << endl;

   return 0;
}

void randnum(double* p, const int N){
  for(int i=1; i<N; i++){
    p[i] = rand() / double(RAND_MAX); 
  }
}

void print(double* p, const int N){
  for(int i=1; i<N; i++){
    cout << p[i] << endl;
  }
}

double meannum(double* p, const int N){
  double m = 0.0;
  for(int i=1; i<N; i++){
     m += p[i];
  }
  return m /= N;
}

double varnum(double* p, const int N){
  double v = 0.0;
  double m = meannum(p, N);
  for(int i=1; i<N; i++){
     v += pow((p[i]-m),2.0);
  }
  return v /= N;
}