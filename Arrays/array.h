class Array{
    private:
        int* A;
        int size;
        int len;
    public:
        Array(int size);

        ~Array();
        void insert(int index, int x);

        void append(int x);

        void display();

        int remove(int index);

        int linearSearch(int key);

        //Assume that the array is sorted for binary search

        int binarySearch(int key);

        int binarySearchHelper(int key, int low, int high);

        int get(int index);

        void set(int index, int value);

        int max();

        int min();
        int sum();

        float avg();

        void reverse();

        void insertSort(int x);

        bool isSorted();

        void rearrange();

        /*
            Those functions assume that the array is sorted
        */
        Array* merge(Array* arr);

        Array* uni(Array* arr);

        Array* inter(Array* arr);

        Array* diff(Array* arr);

        /*==========================================================*/
        void findMissingElementSortedArray();
        void findMissingElementUnsortedArray(int low, int high, int len);
        void findDup(int high);
        void findSumUnsorted(int k);
        void findSumSorted(int k);

};