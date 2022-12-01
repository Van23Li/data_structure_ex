#ifndef arrayList_
#define arrayList_

#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include "linearList.h"
#include "myExceptions.h"
#include "changeLength1D.h"
#include<iterator>

using namespace std;

template <class T>
class arrayList : public linearList <T>{
    public:
        // 构造函数，复制构造函数和解析函数
        arrayList (int initialCapacity = 10);
        arrayList (const arrayList<T> &);
        ~arrayList () {delete [] element;}

        // ADT方法
        bool empty() const {return listSize == 0;}
        int size() const {return listSize;}
        T& get(int theIndex) const;
        int indexOf(const T& theElement) const;
        void erase(int theIndex);
        void insert(int theIndex, const T& theElement);
        void output(ostream& out) const;

        // 其他方法
        int capacity() const {return arrayLength;}
        void trimToSize();
        T& operator[](int theIndex);
        bool operator != (const arrayList<T>& theList);
        bool operator == (const arrayList<T>& theList);
        void swapl(arrayList <T> & theList);
        void set(int theIndex, const T & theElement);
        void removeRange(int startIndex, int endIndex);


    protected:
        void checkIndex (int theIndex) const;   // 若索引theIndex无效，则抛出异常；
        T* element;     // 储存线性表元素的一维数组
        int arrayLength;        // 一维数组的容量
        int listSize;       // 线性表的元素个数
};

template <class T>
arrayList <T> :: arrayList (int initialCapacity){
    // 构造函数
    if (initialCapacity < 1){
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0 ";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity;
    element = new T [initialCapacity];
    listSize = 0;
}

template <class T>
arrayList <T> :: arrayList (const arrayList<T> & theList){
    // 复制构造函数
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T [arrayLength];
    copy (theList.element, theList.element + listSize, element);
}

template <class T>
void arrayList <T> :: checkIndex (int theIndex) const{
    // 确定索引theIndex在0和listSize - 1之间
    if (theIndex < 0 || theIndex > listSize){
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex (s.str());
    }
}

template <class T>
T& arrayList <T> :: get(int theIndex) const{
    //返回索引为theIndex的元素
    //若此元素不存在，则抛出异常
    checkIndex (theIndex);
    return element[theIndex];
}

template <class T>
int arrayList <T> ::indexOf(const T& theElement) const{
    // 返回元素theElement第一次出现时的索引
    // 若该元素不存在，则返回-1
    int theIndex = (int) (find(element, element + listSize, theElement) - element);

    if (theIndex == listSize)
        return -1;
    else
        return theIndex;
}

template <class T>
void arrayList <T> ::erase(int theIndex){
    // 删除其索引为theIndex的元素
    // 如果该元素不存在，则抛出异常illegalIndex
    checkIndex (theIndex);

    copy(element + theIndex + 1, element + listSize, element + theIndex);
    element[--listSize].~T();   // 清空element[listSize]内存，注意优先级
}

template <class T>
void arrayList <T> ::insert(int theIndex, const T& theElement){
    checkIndex (theIndex);
    if (listSize == arrayLength){
        changeLength1D (element, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }

    copy_backward (element + theIndex, element + listSize, element + listSize + 1);
    element[theIndex] = theElement;

    listSize ++;
}

template <class T>
void arrayList <T> ::output(ostream& out) const{
    // 把线性表插入输出流；
    copy (element, element + listSize, ostream_iterator <T> (cout, "  "));
}

// overload <<
template <class T>
ostream& operator<<(ostream& out, const arrayList<T>& x)
   {x.output(out); return out;}

// overload []
template <class T>
T& arrayList<T>::operator[](int theIndex){
    checkIndex (theIndex);
    return element[theIndex];
}

// overload ==
template <class T>
bool arrayList<T>::operator ==(const arrayList <T> & theList){
    return !(*this != theList);
}

// overload !=
template <class T>
bool arrayList<T>::operator !=(const arrayList <T> & theList){
    if (listSize != theList.size()) return true;
    
    for (int i = 0; i < listSize; i++){
        if (element[i] != theList.element[i])
            return true;
    }

    return false;
}

// 交换
template <class T>
void arrayList<T>::swapl(arrayList <T> & theList){
    // T* temp = new T [arrayLength];
    // copy (element, element + listSize, temp);
    // // delete [] element;
    // copy (theList.element, theList.element + theList.listSize, element);
    // // delete [] theList.element;
    // copy (temp, temp + listSize, theList.element);
    swap(arrayLength, theList.arrayLength);
    swap(listSize, theList.listSize);
    swap(element, theList.element);
}

template <class T>
void arrayList<T>::set(int theIndex, const T & theElement){
    checkIndex(theIndex);
    element[theIndex] = theElement;
}

template <class T>
void arrayList<T>::removeRange(int startIndex, int endIndex){
    if (startIndex < 0 || endIndex > listSize)
      throw illegalIndex();

   if (startIndex >= endIndex)
      // nothing to remove
      return;


    // shift elements with higher index
    copy(element + endIndex, element + listSize, element + startIndex);

    // destroy uneeded elements
    int newSize = listSize - endIndex + startIndex;
    for (int i = newSize; i < listSize; i++)
        element[i].~T(); 

    listSize = newSize;

    // for (int i = startIndex; i < endIndex; i ++){
    //     erase(i);
    // }            错了，因为erase会同时改变数组长度
}

#endif