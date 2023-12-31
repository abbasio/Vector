#include <iostream>
#include "./Vector.hpp"

template <typename T>
void LogVector(Vector<T>& v){
    std::cout << "Size = " << v.Size() << ", Capacity = " << v.Capacity() << "Is Empty? =" << v.IsEmpty() << std::endl;
    
    for (int i = 0; i < v.Size(); i++){
        std::cout << "items[" << i << "] = " << v[i] << std::endl;
    }
}

int main(){
    
    //Initialize a vector 
    Vector<float> v;
  
    //Initialize a vector with values
    Vector<float> w(10, 1);
    LogVector(w);

    //Initialize a vector that is a copy of another vector
    Vector<float> w2(w);
    LogVector(w2); 

    //Modify values within a vector
    w[5] = 0;
    LogVector(w);
 
    //Set one vector equal to another
    v = w;
    LogVector(v);
    
    //Push a value to the end of a vector
    v.PushBack(2);
    LogVector(v);

    //Pop the last value of a vector
    v.PopBack();
    LogVector(v);

    //Insert a value into a vector
    v.Insert(5, 11);
    LogVector(v);

    //Erase a value from a vector
    v.Erase(5);   
    LogVector(v);

    return 0;
}
