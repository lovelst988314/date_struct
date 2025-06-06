#include <iostream>
#include <string>
#include "seqList.h"

using namespace std;

int main(){
    SeqList<int> seq(10);
    cout << "请输入10个数字：" << endl;
    seq.input();
    seq.output();
    string str = "修改";
    int m = 0;
    seq.Remove(2, m);
    seq.output();
}