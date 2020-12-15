// my_string.cpp
#include <iostream>
#include "my_string.h"

using std::cout, std::cin, std::endl, std::ostream; 
// TODO(student): define all necessary my_string methods
// NOTE: some methods suggested here may not be required for you.
//       if you don't need a method, then you are not required to implement it
// NOTE: some methods not suggested here may be required for you.
//       if you need a method, then you are required to implement it (or re-engineer your solution to no longer need the method).

// my_string methods
// constructors
//   default (done for you.  you're welcome.)
my_string::my_string() : _data(new char[1]{0}), _capacity(1), _size(0) {}
//   rule of "3"
//     my_string copy constructor
std::ostream& operator<<(std::ostream& os, const my_string& str){
    my_string a; 
    a = str;
    for(size_t i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl; 
    os << "Size " <<  a.size() << endl;

    return os;
}
my_string::my_string(const my_string& other) : _data(new char[other._size]{0}), _capacity(other._capacity),  _size(other._size){
    for(size_t i = 0; i < _size; i++){
        _data[i] = other._data[i];
    }
}

char& my_string::operator[](my_string::size_type index)
{

    return this->_data[index];
}
const char& my_string::operator[](my_string::size_type index) const
{
    return this->_data[index];
}

my_string& my_string::operator+=(const char* rhs){
    my_string rhs1;
    rhs1 = rhs; 
    char* arr = new char[this->_size + rhs1._size];
    size_t sum = this->_size + rhs1._size;
    size_t holder = 0; 
    for(size_t i =0; i < sum; i++){
        if(i >= this->_size){
            arr[i] = rhs1[holder];
            holder++;
        }
        else{
            arr[i] = this->_data[i];
        }
    }
    delete[] this->_data;
    this->_data = arr; 
    this->_size= sum; 
    return *this;
}
//     my_string copy assignment
my_string& my_string::operator+=(my_string const& rhs){
    size_t sum = rhs._size + this->_size;
    char* arr = new char[sum];
    size_t holder =0; 
    for(size_t i = 0; i < sum; i++){
        if(i < this->_size){
            arr[i] = this->_data[i];
        }
        else{
            arr[i] = rhs._data[holder];
            holder++;
        }
        
    }
    delete[] this->_data;
    this->_data = arr;
    this->_size = sum; 
    return *this;
}

my_string& my_string::operator+=(char rhs){
    char* arr = new char[1 + this->_size];
    for(size_t i = 0; i < this->_size; i++){
        arr[i] = _data[i];
    }
    arr[this->_size] = rhs;
    delete[] this->_data;
    this->_data = arr;
    this->_size = 1 + this->_size;
    return *this;
}

bool operator==(const my_string& lhs, const my_string& rhs){
    
    my_string lhs1; 
    lhs1 = lhs; 
    my_string rhs1;
    rhs1  = rhs;
    if((lhs1.size() - rhs1.size()) != 0){
        return false; 
    }
    for(size_t i = 0; i < lhs1.size(); i++){
        if((lhs1[i]-48) == (rhs1[i]- 48)){
            continue;
        }
        return false; 
    }
    return true; 
}

bool operator==(const my_string& lhs, const char* rhs){
    my_string rhs1;
    rhs1 =rhs;
    my_string lhs1;
    lhs1 = lhs; 
    if(lhs1.size()- rhs1.size() != 0 ){
        return false;
    }
    for(size_t i= 0; i < lhs1.size(); i++){
        if((lhs1[i]-48) == (rhs1[i]- 48)){
            continue;
        }
        return false; 
    }
    return true;
}
/* INSIDE THE CLASS HEADER FILE*/

//     destructor
my_string::~my_string(){
    delete[] this->_data;
}



//   c-string constructor
my_string::my_string(const char* other) : _data(new char[1]{0}), _capacity(0), _size(0)
{
    _size = 0;
    while(other[_size] != '\0'){
        _size++;
        
    }
    delete[] _data;
    _data = new char[_size];
    for(size_t i = 0; i < _size; i++){
        _data[i] = other[i];
    }
}

my_string& my_string::operator =(const my_string& rhs)
{
    if(this != &rhs){
        delete[] _data;
        _size = rhs._size;
        _data = new char[rhs._size]; 
        for(size_t i = 0; i < rhs._size; i++){
            _data[i] = rhs._data[i];
        }  
    }
    return *this; 
}





// element access
//   at
//   front
//   operator[]
my_string::size_type my_string::find(const my_string& string_element, const my_string::size_type pos) const
{
    for(size_t i = pos; i < this->_size; i++){
        if(this->_data[i] == string_element[0]){
            return i; 
        }
    }   
    return npos; 
}
using size_type = size_t;
my_string& my_string::insert(size_type pos, const my_string& str)
{
    
    char* new_arr = new char[str._size + this->_size];
    size_t sum = str._size + this->_size;
    size_t holder = 0;  
    size_t holder2 = 0;
    for(size_t i = 0; i < sum ; i++)
    {
        if(i < pos){
            new_arr[i] = this->_data[i];
            holder2++;
        }
        else if(i >= pos && i < (str._size + pos)){
            new_arr[i] = str._data[holder];
            holder++;
        }
        else if(i >= str._size + pos){
            new_arr[i] = this->_data[holder2];
            holder2++;
        }
    }       


    delete[] this->_data;
    this->_data = new_arr;
    _size = sum; 
    return *this ;                

    
}                                                                   

my_string to_string(int val){
    int num = val; 
    size_t cnt = 0;
    if(num == 0){
        return "0";
    }
    while(num != 0){
        num /=10; 
        cnt++;
    }
    char* arr = new char[cnt];
    for(size_t i = 0; i < cnt; i++){
        arr[i] = (val % 10) + '0';
        val /= 10; 
    }
    char* new_arr = new char[cnt]; 
    size_t pos = 0; 
    for(int j = cnt-1; j >= 0; j--){
        new_arr[pos] = arr[j]; 
        pos++;
    }
    delete[] arr; 
    my_string str;
    delete[] str._data;
    str._data = new_arr;
    str._size = cnt; 
    return str; 
}
my_string& my_string::substr(const int start,const int end)
{
    char* new_arr = new char[end-start];
    int runner = 0; 
    for(int i = start; i < end; i++){
        new_arr[runner] = this->_data[i];
        runner++; 
    }
    delete[] this->_data;
    this->_data = new_arr;
    this->_size = end-start; 
    return *this; 
}



