#include <string>
#include <iostream> 
#include <boost/lexical_cast.hpp>

#define numof(array) sizeof(array)/sizeof(array[0])
using namespace std;

int calc_y(int* x,double* w,int size){
	int y = 0;
	for(int i = 0;i < size;i++){
		if(w[i]){
			y += x[i] * w[i];
		}
	}
	return y;
}

void learning(double* w,int* x,int t,int size){
	int y = calc_y(x,w,size);
	
	if(y * t < 0){
		for(int i = 0;i < size;i++){
			w[i] += t * x[i];
		}
	}
}

int main(){
	//learning part
	int x_list[][4] = {  //[R,G,B,bais]
	  {100, 100, 100, 1},
      {127, 0, 0, 1},
	  {0, 200, 0, 1},
      {0, 0, 255, 1},
      {0, 0, 0, 1},
      {255, 255, 0, 1},
      {255, 0, 255, 1},
      {0, 255, 255, 1},
      {200, 200, 200, 1},
      {255, 255, 255, 1}   
      };
    int answer[] = {-1, -1, -1, -1, -1, 1, 1, 1, 1, 1};
    double weight[] = {0,0,0,1};//weight vector
    const int loop = 1000000;
    for(int i = 0;i < loop;i++){
    	for(int j = 0;j < numof(x_list);j++){
    		learning(weight,x_list[j],answer[j],numof(x_list[j]));
    	}
    }
    
    //estimate part
	string temp[3];
	int input[4];
	
	cin >> temp[0] >> temp[1] >> temp[2];
	
	input[0] = boost::lexical_cast<int>(temp[0]);
	input[1] = boost::lexical_cast<int>(temp[1]);
	input[2] = boost::lexical_cast<int>(temp[2]);
	input[3] = 1;//bais
	
	int t = calc_y(input,weight,numof(input));
	
	//test
	cout << "output: weight" << endl;
	for(int i = 0;i < numof(weight);i++){
		cout << weight[i] << " ";
	}
	cout << endl << endl;
	cout << "t = " << t << endl;
	if(t >= 0){
		cout << "White" << endl;
	}else{
		cout << "Black" << endl;
	}
	return 0;
}