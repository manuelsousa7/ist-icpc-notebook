// Example for using stringstreams and next_permutation
#include <bits/stdc++.h>

using namespace std;

struct C{
    bool operator()(const int &a, const int &b) const{
        return a > b;
    }
};

int main(void){
  vector<int> v = {1, 2, 3, 6};

  // upper_bound and lower_bound
  
  cout << *upper_bound(v.begin(), v.end(), 3) << endl; // exactly greater -> result = 6
  cout << *lower_bound(v.begin(), v.end(), 3) << endl; // equal or greater -> result = 3

  auto u = upper_bound(v.begin(), v.end(), 6);
  cout << (u == v.end() ? "end" : to_string(*u)) << endl; // if greater not available -> result = end
  cout << *lower_bound(v.begin(), v.end(), 7) << endl; // if greater or equal not available -> result = end

  cout << *upper_bound(v.begin(), v.end(), 3, less<int>()) << endl; // exactly greater -> result = 6
  cout << *lower_bound(v.begin(), v.end(), 3, less<int>()) << endl; // equal or greater -> result = 3

  // string to int, int to string

  cout << stoi("345") << " " << atoi("345") << " " << to_string(345) << endl;
  
  // Permutations

  // Expected output: 1 2 3 6
  //                  1 2 6 3
  //                  ...
  //                  6 3 2 1

  do {
    ostringstream oss;
    oss << v[0] << " " << v[1] << " " << v[2] << " " << v[3];
    
    // for input from a string s,
    //   istringstream iss(s);
    //   iss >> variable;
    
    cout << oss.str() << endl;
  } while (next_permutation (v.begin(), v.end()));
  
  v.clear();
  
  v.push_back(1);
  v.push_back(2);
  v.push_back(1);
  v.push_back(3);
  
  // To use unique, first sort numbers.  Then call
  // unique to place all the unique elements at the beginning
  // of the vector, and then use erase to remove the duplicate
  // elements.
  
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  
  // Expected output: 1 2 3
  for (size_t i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl; 

  // custom comparator

  set<int, C> s;
}
