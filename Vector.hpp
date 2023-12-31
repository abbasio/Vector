#pragma once

const int DEFAULT_VECTOR_SIZE = 10;

template<typename T>
class Vector{
    private:
        int size;
        int capacity;
        T* elements;                             //Pointer to the array in the heap

    public:
       
        //Vector<float> v -- Initialize a vector of floats (v)
        Vector(){
            size = 0;
            capacity = DEFAULT_VECTOR_SIZE;
            elements = new T[DEFAULT_VECTOR_SIZE];
        }
       
        //Vector<float> v(10, 3.2f) -- Initialize a vector of floats (v) with 10 entries, each one initialized to 3.2f
        Vector(int n, const T& value){
            size = n;
            capacity = n * 2;
            elements = new T[capacity];

            for (int i = 0; i < size; i++){
                elements[i] = value;
            }
        }           
       
        //Vector<float> v(w) -- Initialize a vector of floats (v) that is a copy of another vector (w)
        Vector(const Vector& ogVector){
            size = ogVector.size;
            capacity = ogVector.capacity;
            elements = new T[capacity];

            for (int i = 0; i < ogVector.size; i++){
                elements[i] = ogVector.elements[i];
            }
        }               
        
        //Destructor class - deletes the array of elements from the heap
        ~Vector(){
            delete []elements;
        }
        
        //v.Size() -- Returns the size of a vector v
        int Size() const{
            return size;
        } 

        //v.Capacity() -- Returns the capacity of a vector v        
        int Capacity() const{
            return capacity;
        }                 
      
        //v.IsEmpty() -- Returns true if vector v is empty, otherwise false
        bool IsEmpty() const{
            return size == 0;
        }                   
         
        // v[5] = x  -- modifies the element at index 5 in vector v 
        T& operator [](unsigned int index){
            if (index < size){
                return elements[index];
            }
        }              
      
        // x = v[5] -- sets x equal to the element at index 5 in vector v   
        const T& operator [](unsigned int index) const{ 
            if (index < size){
                return elements[index];
            }
        }  
      
        // v = w -- set vector v equal to vector w by copying all contents from vector w                                         
        Vector& operator =(const Vector& other){
            if(other.size > size){
                delete[] elements;
                capacity = other.size * 2;
                elements = new T[capacity];
            }

            for(int i = 0; i < other.size; i++){
                elements[i] = other.elements[i];
            }
            size = other.size;
            return *this;
        }   
      
        // Increase capacity if we need more overhead
        void IncreaseCapacity(){ 
            if(size == capacity){
                T* newArray = new T[capacity * 2];
                for (int i = 0; i < size; i++){
                    newArray[i] = elements[i];
                }
                delete[] elements;
                elements = newArray;
                capacity *= 2;
            }
        } 
        // Reduce capacity if we have more overhead than we need
        void ReduceCapacity(){ 
            if (size < (capacity / 4)){
                capacity = capacity / 2;
            }
        }
                
        // v.PushBack(3) -- Appends the value 3 to vector v  
        void PushBack(const T& object){
            IncreaseCapacity();
            elements[size] = object;
            size++;
        }         
      
        // v.PopBack() -- Removes the last value of vector v
        void PopBack(){
            if (size > 0){
                size--;
                ReduceCapacity();
            }
        }                         
      
        // v.Erase(2) -- Removes the element at position 2 from vector v
        void Erase(unsigned int index){
            if (index < size){
                for (int i = index; i < size - 1; i++){
                    elements[i] = elements[i + 1];
                }
                size--; 
                ReduceCapacity();
            }
        }                   
      
        // v.Insert(4, x) -- Inserts the value x into vector v at index 4
        void Insert(int index, T value){
            IncreaseCapacity();

            size++;
           
            for(int i = size - 1; i >= index; i--){
                elements[i + 1] = elements[i];
            }
            
            elements[index] = value;
        }        
      
        // v.Clear() -- remove all values from vector v
        void Clear(){
            size = 0;
        }                            
};
