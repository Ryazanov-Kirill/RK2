#include <iostream>
#include "tasks_rk2.h"
void task_3(){
    Filo<int> lst;
    lst.push_back(3);
   lst.push_back(4);
   lst.push_back(6);
    lst.push_back(5);
    lst.showElements();
    lst.pop_back();
    lst.showElements();
}
void task_5() {
    CheckBrackets<char> check;
    std::cout << check.checkBrackets("[{(){}}(){()}]")<<"\n";
}
void task_2(){
int *array=new int[10]{1,2,3,4,5,6,7,8,9,10};
   std::pair<int,int> pairForTest=binSearch(array,10,8);
    std::cout<<pairForTest.first<<"  " << pairForTest.second;
}
void task_4(){
    std::pair<int,int> pair1;
    pair1.first=12;
    pair1.second=13;
    std::cout<<pair1<<"\n";
    std::pair<int,std::string> test;
    test.second="qwer";
    test.first=4;
    std::cout<<test;

}
int main() {
    task_5();
    task_2();
    task_4();
return 0;


}
