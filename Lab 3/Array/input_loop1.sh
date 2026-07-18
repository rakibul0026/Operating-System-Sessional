number=()
echo "How many element do you want to enter?"
read n

for ((i=0;i<n;i++));do
   echo "Enter the array Element $((i+1))"
   read value
   number+=("$value")
done
echo "The array elements are: ${number[@]}"