cat opt.txt
cat out.txt
if cmp -s "opt.txt" "out.txt"
then
   echo -e "\e[32m\e[1mVerdict : AC\e[0m";
else
     echo -e "\e[31m\e[1mVerdict : WA\e[0m";
fi

