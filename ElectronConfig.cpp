#include<iostream>
#include<string>
#include<cmath>
#include<string>
#include<array>
namespace ElectronConfig{
//global vars
std::array <int,19> index = {2,2,6,2,6,2,10,6,2,10,6,2,14,10,6,2,14,10,6};
std::array<std::string,19> OrbitA = {"1s^","2s^","2p^","3s^","3p^","4s^","3d^","4p^","5s^","4d^","5p^","6s^","4f^","5d^","6p^","7s^","5f^","6d^","7p^"};
std::array<std::string,19> OrbitB = {"1s","2s","\\ \\ 2p\\ \\ ","3s","\\ \\ 3p\\ \\ ","4s","\\ \\ \\ 3d\\ \\ \\ ","\\ \\ 4p\\ \\ ","5s","\\ \\ \\ 4d\\ \\ \\ ","\\ \\ 5p\\ \\ ","6s","\\ \\ \\ \\ 4f\\ \\ \\ \\ ","\\ \\ \\ 5d\\ \\ \\ ","\\ \\ 6p\\ \\ ","7s","\\ \\ \\ \\ 5f\\ \\ \\ \\ ","\\ \\ \\ 6d\\ \\ \\ ","7p"};

std::array<int,19> electronConfigArray(int electron){
int i = electron;
if(i < 0 || i > 118){
std::cout<<"ERROR var electron out of bounds";  
}
// 1s2 2s2 2p6 3s2 3p6 4s2 3d10 4p6 5s2 4d10 5p6 6s2 4f14 5d10 6p6 7s2 5f14 6d10 7p6
std::array <int,19> config = {};

for(int a = 0; i > 0;){
    config.at(a)++;
    i--;
    if(!(config.at(a) < index.at(a))){
        a++;
        }
    }
    return config;
}  
std::array<int,19> electronConfigArrayPrint(int electron){
int i = electron;
if(i < 0 || i > 118){
std::cout<<"ERROR var electron out of bounds";  
}
// 1s2 2s2 2p6 3s2 3p6 4s2 3d10 4p6 5s2 4d10 5p6 6s2 4f14 5d10 6p6 7s2 5f14 6d10 7p6
std::array <int,19> config = {};


for(int a = 0; i > 0;){
    config.at(a)++;
    i--;
    if(!(config.at(a) < index.at(a))){
        a++;
        }
    }
int temps = 0;
for(int r = 0; r < (int)config.size(); r++){
    temps = temps + config.at(r);
 std::cout<<config.at(r)<<" ";
}
 std::cout<<"\n"<<temps<<"\n";
 return config;
}
std::string arrayToLATEX(std::array<int,19> Config){
    std::string sConfig = "";
    for(int i = 0; i < 19; i++){
        if(Config.at(i) > 0){
            sConfig += OrbitA.at(i);
            sConfig +=  "{" + std::to_string(Config.at(i)) + "}";
            sConfig += "\\ ";
        }
     
    }
    return sConfig;
}
std::string arrayToString(std::array<int,19> Config){
    std::string sConfig = "";
    for(int i = 0; i < 19; i++){
        if(Config.at(i) > 0){
            sConfig += OrbitA.at(i);
            sConfig += std::to_string(Config.at(i));
            sConfig += " ";
        }
     
    }
    return sConfig;
 }
std::string orbitalConfigDebug(std::array<int,19> config){
std::string sConfig = "";
std::cout<<"var\n";

//loop for each orbital
for(int i = 0; i < 19; i++){
if(config.at(i) > 0){
int stupid;
std::cout<<"orbit\n";
std::array<std::string,15> temp = {""};

//get a to be equal or less than the lower half of the capcity of the orbital
int a = (config.at(i) > index.at(i)/2) ? index.at(i)/2 : config.at(i);
      std::cout<<"if\n";
     
//fill up arrows every other spot in the array
  for(int j = 0; j < a; j++){
   std::cout<<"up\n";
   stupid = (2 * (j + 1)) - 2;
   std::cout<<stupid<<"\n";
   temp.at(stupid) = "\\uparrow";
  }
 

//fill down arrows in every other box that they should be in
for(int a = (config.at(i) - index.at(i)/2); a > 0; a--){
       std::cout<<"down\n";
       stupid = (2 * a) - 1;
       std::cout<<stupid<<"\n";
       temp.at(stupid) = "\\downarrow";
  }
 
  //putts all the data into one string and formats it
  std::string Arrows = "";
  for(int j = 0; j < (int)temp.size();j++){
   Arrows += temp.at(j);
   std::cout<<"format\n";  
   }
   for(int j = 0; j < index.at(i) - config.at(i); j++){
    Arrows += "\\ ";
  }
   sConfig += "\\frac{" + Arrows + "}{" + OrbitB.at(i) +"}\\ ";  
 }
}
 return sConfig;
}
std::string orbitalConfig(std::array<int,19> config){
std::string sConfig = "";

//loop for each orbital
for(int i = 0; i < 19; i++){
if(config.at(i) > 0){
int stupid;
std::array<std::string,15> temp = {""};

//get a to be equal or less than the lower half of the capcity of the orbital
int a = (config.at(i) > index.at(i)/2) ? index.at(i)/2 : config.at(i);
     
//fill up arrows every other spot in the array
  for(int j = 0; j < a; j++){
   stupid = (2 * (j + 1)) - 2;
   temp.at(stupid) = "\\uparrow";
  }
 

//fill down arrows in every other box that they should be in
for(int a = (config.at(i) - index.at(i)/2); a > 0; a--){
       stupid = (2 * a) - 1;
       temp.at(stupid) = "\\downarrow";
  }
 
  //putts all the data into one string and formats it
  std::string Arrows = "";
  for(int j = 0; j < (int)temp.size();j++){
   Arrows += temp.at(j);
   }
   for(int j = 0; j < index.at(i) - config.at(i); j++){
    Arrows += "\\ ";
  }
   sConfig += "\\frac{" + Arrows + "}{" + OrbitB.at(i) +"}\\ ";  
 }
}
 return sConfig;
}
};    
