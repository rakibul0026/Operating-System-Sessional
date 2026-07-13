fruits=("Apple" "Banana" "Mango" "Orange")
echo "${fruits[0]}"
echo "${fruits[2]}"
echo "${fruits[@]}"

echo "Total fruits: ${#fruits[@]}"

for fruit in "${fruits[@]}";do
	echo " Fruit: $fruit"
done

fruits[4]="Grapes"
fruits[1]="Blueberry"
unset fruits[0]
echo "${fruits[@]}"

numbers=(10 20 30 40 50 60 70)
echo " ${numbers[@]:1:3}"

echo " Enter 5 numbers separated by space:"
read -a numbers
echo " You entered: ${numbers[@]}"

echo " How many elements do you want to enter?"
read n

for (( i=0; i<n; i++ )); do
	echo " Enter element $ ((i+1)):"
	read numbers[i]
done

echo "Array elements: ${numbers[@]}"

numbers=()
echo "How many elements do you want to enter?"
read n
for (( i=0; i<n; i++)); do
	echo " Enter a number:"
	read value
	numbers+=("$value")
done

echo " Array elements: ${numbers[@]}"


