#include <iostream>
#include "src/lib/trojanmap.h"

int main() {

  TrojanMap x;
  x.CreateGraphFromCSVFile();
  x.PrintMenu();
    
    /*
  std::vector<std::string> location_ids={"A", "B", "C", "D", "E", "F"};
  int size = location_ids.size();
  int maxCount = pow(size,2) + 10;

  std::vector<std::string> path=location_ids;
  std::vector<std::string> tmp=path;
  tmp.push_back(path[0]);
  for(auto n : tmp){
    std::cout << n << " ";
  }std::cout << std::endl;

  for(int j=0; j<5; j++){
    int i = rand()%(size-1);
    int k = rand()%(size-1);
    if(i>k){
      int l = i;
      i = k;
      k = l;
    }
    std::cout << "i = " <<i << " ,k = " << k <<std::endl;
    tmp.pop_back();
    std::cout << "initial tmp: "<< std::endl;
    for(auto n: tmp){std::cout << n << " ";} std::cout << std::endl;

    //std::copy( path.begin(), path.begin()+i, tmp.begin());//copy 0 to i-1 to tmp

    std::vector<std::string> rev(k-i+1);
    std::copy(path.begin()+i, path.begin()+k+1, rev.begin());//reverse i to k
    std::reverse(rev.begin(), rev.end());
    std::copy(rev.begin(), rev.end(), tmp.begin()+i);//copy reverse to tmp

    //std::copy(path.begin()+k+1, path.end(), tmp.begin()+k+1);//copy k+1 to end to tmp



    tmp.push_back(path[0]);

        std::cout << "tmp after push: "<< std::endl;
    for(auto n: tmp){std::cout << n << " ";} std::cout << std::endl;


    std::copy(tmp.begin(), tmp.end()-1, path.begin());//renew the path
    std::cout << "the path renew: "<< std::endl;
    for(auto n: path){std::cout << n << " ";} std::cout << std::endl;
    std::cout << std::endl;
  }*/

  return 0;
}