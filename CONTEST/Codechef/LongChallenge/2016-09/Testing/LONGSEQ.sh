
clear;
# Generate Test Cases
# echo -e "\e[34m\e[1mGenerate Test Cases\e[0m";

g++  LONGSEQ_TestCases.cpp -o LONGSEQ_TestCases;

./LONGSEQ_TestCases > testCases.txt;

# Run BruteForece Solution
# echo -e "\e[46m\e[1mRun BruteForece Solution\e[0m";

g++  LONGSEQ_BF.cpp -o LONGSEQ_BF;

./LONGSEQ_BF < testCases.txt > output_BF.txt;

# Run Optimized Solution
# echo -e "\e[45m\e[1mRun Optimized Solution\e[0m";

g++  LONGSEQ.cpp -o LONGSEQ;

./LONGSEQ  < testCases.txt > output.txt;

if cmp -s "output_BF.txt" "output.txt"
then
   echo -e "\e[32m\e[1mVerdict : AC\e[0m";
else
     echo -e "\e[31m\e[1mVerdict : WA\e[0m";
fi

