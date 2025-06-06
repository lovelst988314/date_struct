# include <iostream>
# include <stdlib.h> 
# include "LinkedList.h"

using namespace std;     


int main(){
    List<int> list(10);
    cout << "hello world" << endl;
    int i = 0;
//    int m = 2;
    list.input(i);  // i为输入结束标志
    list.output();
    int m = 2;
    list.Remove(3,m);
    cout<<"m:"<<m<<endl;
    list.output();
}