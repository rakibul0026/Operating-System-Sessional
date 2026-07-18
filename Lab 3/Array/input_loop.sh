echo "Enter the array size :"
read n

for((i=0;i<n;i++));do
   echo "Enter the array Element $((i+1))"
   read number[i]
done


echo "The array elements are: ${number[@]}"
echo "count of array elements are: ${#number[@]}"