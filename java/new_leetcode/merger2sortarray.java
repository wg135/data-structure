class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int indexA = m-1;
        int indexB = n-1;
        int last = m + n - 1;
        while(indexA>=0 && indexB >= 0){
            if(A[indexA] > B[indexB])
              A[last--] = A[indexA--];
            else
              A[last--] = B[indexB--];
        }
        
        while(indexB >=0)
          A[last--] = B[indexB--];
        
    }
};
