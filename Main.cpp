#include <iostream>
#include "./Vector.hpp"

int main(){
   Vector<float> v;
   v.PushBack(0);
   v.PushBack(10);
   v.PushBack(20);
   v.PushBack(30);
   v.PushBack(40);
   v.PushBack(50);
   v.PushBack(60);
   v.PushBack(70);
   v.PushBack(80);
   v.PushBack(90);
   v.PushBack(100);
   v.PushBack(110);
   v.PushBack(120);
   v.PushBack(130);
   v.PushBack(999);
   v.PopBack();
   v.Erase(5);

   v.Insert(10, 500);

   Vector<float> w;
   w = v;

   for (int i = 0; i < w.Size(); i++){
       std::cout << "items[" << i << "] = " << w[i] << std::endl;
   }

   std::cout << "Size = " << w.Size() << ", Capacity = " << w.Capacity() << std::endl;

    return 0;
}
