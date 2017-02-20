echo "=====Generate TestFile====="
g++ testCaseGenarator.cpp ;
./a.out > TestCases.txt ;
#echo "=====Run Tester Solution====="
#g++ 5_1.cpp ;
#start=$(date +%s.%N); \
#./a.out < TestCases.txt > testerFile.txt; \
#dur=$(echo "$(date +%s.%N) - $start" | bc); \
#printf "====Time: %.6f seconds====\n" $dur 
echo "=====Run  User  Solution====="
g++ 5_4.cpp ;
start=$(date +%s.%N); \
./a.out < TestCases.txt > myFile.txt; \
dur=$(echo "$(date +%s.%N) - $start" | bc); \
printf "====Time: %.6f seconds====\n" $dur 
g++ 5_5.cpp ;
start=$(date +%s.%N); \
./a.out < TestCases.txt > myFile.txt; \
dur=$(echo "$(date +%s.%N) - $start" | bc); \
printf "====Time: %.6f seconds====\n" $dur 

#echo "===== Check  Difference ====="
#diff --brief testerFile.txt myFile.txt
#cmp --silent testerFile.txt myFile.txt || echo "files are different"
#if cmp -s testerFile.txt myFile.txt ; then
#   echo "=====Verdict : AC====="
#else
#   echo "=====Verdict : WA====="
#fi
echo "=====Done!====="
