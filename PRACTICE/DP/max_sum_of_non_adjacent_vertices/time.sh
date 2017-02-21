
#!/bin/bash
start=$(date +%s.%N)

# HERE BE CODE

end=$(date +%s.%N)    
runtime=$(python -c "print(${end} - ${start})")

echo "Runtime was $runtime"
