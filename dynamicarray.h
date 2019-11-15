
class DynamicArray {
   public:
      DynamicArray();
      DynamicArray(const DynamicArray& other);
      ~DynamicArray();
      void append(int newVal);

      int at(int index) const;

      int sum() const;

      bool remove(int valToDelete);

      void print(std::ostream& s) const;
      int cap() const { return capacity; }
      bool operator==(DynamicArray& source) const;
      DynamicArray& operator= (const DynamicArray& other);


   private:
      int* arr;
      int len; // Number of elements actually populated
      int capacity; // New variable - this is the current capacity of the array

};
