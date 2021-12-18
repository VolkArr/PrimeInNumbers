#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class PrimeDecomp
{
public:
    static std::string factors(int lst);
};

std::string PrimeDecomp::factors(int lst){
  std::string final_str = " ";
  std::vector<int> simple_numbers_array;
  for(auto i = 2; i <= lst; i++ ){
    int simple = lst%i;
    if ( simple == 0){
      lst /= i;
      simple_numbers_array.push_back(i);
      i--;
    }
  }
  int counter = 1;
  std::stringstream ss;
  for(auto i = 0; i < simple_numbers_array.size(); i++){
    if(simple_numbers_array[i] == simple_numbers_array[i+1]){
      counter++;
      continue;
    }
    if(counter > 1){
      ss << "(" << simple_numbers_array[i] << "**" << counter << ")";
      counter = 1;
      continue;
    }
    ss << "(" << simple_numbers_array[i] << ")";
  }
  final_str = ss.str();
  return final_str;
}


int main(){

    std::cout << PrimeDecomp::factors(3242) << std::endl;
    std::cout << PrimeDecomp::factors(4128283) << std::endl;
    std::cout << PrimeDecomp::factors(52322) << std::endl;
    std::cout << PrimeDecomp::factors(1000) << std::endl;
    std::cout << PrimeDecomp::factors(324212) << std::endl;
    std::cout << PrimeDecomp::factors(65) << std::endl;
    std::cout << PrimeDecomp::factors(87) << std::endl;
    std::cout << PrimeDecomp::factors(6) << std::endl;
    std::cout << PrimeDecomp::factors(36) << std::endl;

    return 0;
}