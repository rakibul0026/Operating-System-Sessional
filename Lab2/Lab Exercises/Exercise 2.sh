
#!/bin/bash

echo "Enter first number:"
read num1

echo "Enter second number:"
read num2

echo "-----------------------------------"

if [ $num1 -gt $num2 ]; then
    echo "$num1 is greater than $num2"
elif [ $num2 -gt $num1 ]; then
    echo "$num2 is greater than $num1"
else
    echo "Both numbers are equal"
fi

echo "-----------------------------------"


sum=$((num1 + num2))
diff=$((num1 - num2))
product=$((num1 * num2))

if [ $num2 -ne 0 ]; then
    quotient=$((num1 / num2))
else
    quotient="Undefined (Cannot divide by zero)"
fi

echo "Sum: $sum"
echo "Difference: $diff"
echo "Product: $product"
echo "Quotient: $quotient"
