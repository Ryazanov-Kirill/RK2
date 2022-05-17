#include <iostream>
#include <iterator>
#include "tasks_rk2.h"

std::pair<int/*index el*/,int /*count call*/> binSearch(int* ar, int sizeAr, int el) {
    int halfOfAr = sizeAr / 2;
    if(sizeAr%2==1){
        halfOfAr++;
    }
    static int countCall;
    static int index=halfOfAr;
    if (ar[halfOfAr-1] != el && halfOfAr!=0) {
        if (ar[halfOfAr-1] > el) {

            if((halfOfAr-1)%2==0){
                index--;
            }
            index-=halfOfAr/2;
            countCall++;
            binSearch(ar, halfOfAr-1, el);
        }
        if (ar[halfOfAr-1] < el) {
            if((sizeAr-halfOfAr)%2==1){
                index++;
            }
            index+=halfOfAr/2;
            countCall++;
            binSearch(ar + halfOfAr, sizeAr - halfOfAr, el);
        }
    }
    if(ar[halfOfAr-1]==el){
        countCall++;
        index--;
    }
    std::pair<int, int> pairForReturn;
    pairForReturn.first=index;
    pairForReturn.second=countCall;
    return pairForReturn;
}




