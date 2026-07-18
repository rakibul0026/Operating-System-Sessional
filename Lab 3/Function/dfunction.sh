greet() {
	echo " Hello, welcome to the OS Lab!"
}
greet

greetUser () {
	echo " Hello, $1! You are $2 years old."
}

greetUser "Rahim" 21

square() { 
	echo $(( $1 * $1 ))
}

answer=$(square 6)
echo " Square: $answer"

count=10
myFunc() {
	local count=t
	echo "Inside function: $count"
}
myFunc
echo "Outside function: $count"

factorial() {
	if [ "$1" -le 1 ]; then
		echo 1
	else 
		prev=$(factorial $(( $1 - 1 )))
		echo $(($1 * prev ))
	fi
}

echo "Enter a number:"
read n
result=$(factorial $n)
echo "Facotorial of $n is $result"

isEven() {
	if [ $(( $1 % 2 )) -eq 0 ]; then
		echo "$1 is Eeven"
	else 
		echo "$1 is Odd"
	fi
}
isEven 7
isEven 10

showMenu() {
	echo "1. Add"
	echo "2. Subtract"
}

add() {
	echo $(( $1 + $2 ))
}
subtract() {
	echo $(( $1 - $2))
}

showMenu
echo "Sum: $(add 10 4)"
echo "Difference: $(subtract 10 4)"

greet() {
	echo "Hello, $1!"
}
calculateSum() {
	echo $(( $1 + $2 ))
}

main() {
	greet "Rahim"
	result=$(calculateSum 5 10)
	echo "Sum: $result"
}
main
