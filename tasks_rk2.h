#include <vector>
#include <map>
#include <tuple>
#include <string>
#include <list>

#ifndef RK2_TASKS_RK2_H
#define RK2_TASKS_RK2_H

#endif //RK2_TASKS_RK2_H

//task 3
template<class T>
class Filo {
private :
    T* ar;	//массив
    int size;	//размер массива
    int countData;	//число элементов в массиве
public :
    void showElements();
    Filo();
    Filo(int _size);
    ~Filo();
    /*
        input		:	элемент который надо добавить
        output		:	1 - элемент добавлен, 0 - элемент не добавлен
        description	:	добавление элемента в конец массива
    */
    int push_back(T el);
    /*
        input		:	элемент который надо извлечь
        output		:	пара значений:
                            1ый аргумент пары -- 1 - элемент успешно извлечён, 0 - элементов в массиве нет
                            2ой аргумент пары -- это извлечённый элемент
        description	:	извлечение элемента из массива
    */
    std::pair<int,T> pop_back();
};
template<typename  T>
Filo<T>::Filo() {
    this->size=256;
    this->countData=0;
    this->ar=new T[this->size];
}
template<typename  T>
Filo<T>::Filo(int _size) {
    size=_size;
    countData=0;
    ar=new T[_size];
}
template<typename  T>
Filo<T>::~Filo<T>() {
    delete[] ar;
}
template<typename  T>
int Filo<T>::push_back(T el) {
    if(countData>=size||countData<0) {
        return 0;
    }
    if(countData==0){
        ar[0]=el;
        countData++;
    }
    else{
        ar[countData++]=el;
        return 1;
    }
}
template<typename  T>
std::pair<int, T> Filo<T>::pop_back() {
    if(countData==0){
        std::pair<int, T> pairForReturn;
        pairForReturn.first=0;
        return pairForReturn;
    }
    else{
        std::pair<int, T> pairForReturn;
        pairForReturn.first=1;
        pairForReturn.second=ar[countData-1];
        countData--;
        return pairForReturn;
    }
}
template<typename  T>
void Filo<T>::showElements() {
    for(int i=0;i<countData;i++){
        std::cout<<ar[i];
    }
}
//

//task 2
std::pair<int/*index el*/,int /*count call*/> binSearch(int* ar, int sizeAr, int el);
//task 5
template<class T>
class CheckBrackets : public Filo<char> {
private:

public :
    CheckBrackets() : Filo<char>() { }
    ~CheckBrackets()=default;
    /*
        input		:	строка со скобками
        output		:	0 - всё хорошо, -1 - скобок не хватает
        description	:	проверка скобок,
    */
    int checkBrackets(const char* strBrackets);
};
template<typename T>
int CheckBrackets<T>::checkBrackets(const char *strBrackets) {
    Filo<char> tempArray;
    int counter=0;
    for(int i=0; strBrackets[i]!=NULL;i++ ){
        switch (strBrackets[i]) {
            case '(':{

                tempArray.push_back('(');
            }
                break;
            case '{':{
                tempArray.push_back('{');

            }
                break;
            case '[':{
                tempArray.push_back('[');
            }
                break;
            case ')':{

                if(tempArray.pop_back().second!='('){
                    return -1;
                }
            }
                break;
            case '}':{
                if(tempArray.pop_back().second!='{'){
                    return -1;
                }

            }
                break;
            case ']':{
                if(tempArray.pop_back().second!='['){
                    return -1;
                }

            }
                break;
        }
        counter++;
    }
    return 0;
}

template <typename T>
std::ostream& operator << (std::ostream& ostr, const std::pair<int, T> t) {
    ostr << "("<< t.first << ", "<< t.second << ")\n";
    return ostr;
}

