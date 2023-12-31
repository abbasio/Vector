#include <iostream>
#include "./Vector.hpp"

int main(){
   Vector<float> v;
   v.PushBack(30);
   v.PushBack(40);
   v.PushBack(50);
   v.PushBack(60);
   v.PushBack(70);
   v.PushBack(80);
   v.PushBack(90);
   v.PushBack(100);
   v.PushBack(999);
   v.PopBack();
   v.Erase(0);

   v.Insert(7, 11);

   Vector<float> w;
   w = v;

   for (int i = 0; i < w.Size(); i++){
       std::cout << "items[" << i << "] = " << w[i] << std::endl;
   }

   std::cout << "Size = " << w.Size() << ", Capacity = " << w.Capacity() << std::endl;

    return 0;
}
