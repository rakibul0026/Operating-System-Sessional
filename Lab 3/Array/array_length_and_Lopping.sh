fruits=("Apple" "Banana" "Mango" "Orange")

echo "Total fruits: ${fruits[@]}"
for i in " ${fruits[@]} ";do
   echo "Fruits: $i"
done