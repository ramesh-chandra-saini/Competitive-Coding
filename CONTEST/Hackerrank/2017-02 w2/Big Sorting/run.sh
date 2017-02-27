clear

#generate testCase
g++ testCase.cpp -o testCase
./testCase > in.txt

#start
start=$(date +%s.%N)

#run ramesh's code
echo '***************new Sol************'
g++ 2.cpp -o ramesh
./ramesh < in.txt > ramesh.txt
echo ans
cat ramesh.txt

#end
end=$(date +%s.%N)
runtime=$(python -c "print(${end} - ${start})")

echo "Runtime : $runtime"

exit

#start
start=$(date +%s.%N)

#run lalit's code
echo '*************old Sol************'
g++ bf.cpp -o lalit
./lalit < in.txt > lalit.txt
echo ans
cat lalit.txt

#end
end=$(date +%s.%N)
runtime=$(python -c "print(${end} - ${start})")
echo "Runtime : $runtime"





if cmp -s lalit.txt ramesh.txt
    then
       echo "Verdict : AC"
    else
       echo "Verdict : WA"
       #diff bf.txt partial.txt
       #gedit bf.txt &
       #gedit partial.txt &
    fi
