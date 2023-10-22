#include <string>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    
    for (int i = 0; i < delete_list.size(); ++i) {
            for (vector<int>::iterator it = arr.begin(); it != arr.end(); ) {
                if (*it == delete_list[i]) {
                    it = arr.erase(it);  // Erase the element and update the iterator.
                } else {
                    ++it;
                }
            }
        }
    
    return arr;
}

int main(int argc, const char * argv[]) {
   
//    solution({293, 1000, 395, 678, 94}, {94, 777, 104, 1000, 1, 12});
       for(int n : solution({110, 66, 439, 785, 1}, {377, 823, 119, 43}))
           cout<<n<<endl;
    
    return 0;
}
