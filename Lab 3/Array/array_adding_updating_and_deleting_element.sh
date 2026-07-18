fruits=("Apple" "Banana" "Mango" "Orange")
fruits[4]="Grapes"
fruits[7]="Mango"
echo " ${fruits[@]}"

unset  fruits[0]
echo "After deleting :, ${fruits[@]}"