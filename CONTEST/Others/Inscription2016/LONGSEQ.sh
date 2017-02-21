
clear;
# Generate Test Cases
 echo -e "\e[34m\e[1mGenerate Test Cases\e[0m";

 g++  -std=c++11 t.cpp -o t;

 ./t ;

cat "t.txt"

# Run Optimized Solution
 echo -e "\e[45m\e[1mRun Optimized Solution\e[0m";

g++ -std=c++11  o.cpp -o o;

./o  ;

cat "o.txt"

# Run BruteForece Solution
 echo -e "\e[46m\e[1mRun BruteForce Solution\e[0m";

g++ -std=c++11 b.cpp -o b;

./b ;

cat "b.txt"


if cmp -s "su.txt" "out.txt"
then
   echo -e "\e[32m\e[1mVerdict : AC\e[0m";
else
     echo -e "\e[31m\e[1mVerdict : WA\e[0m";
fi

