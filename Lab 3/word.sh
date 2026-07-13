name="Bangladesh"
echo "Country: $name"

echo " Length: ${#name}"

echo "${name:0:4}"
echo "${name:4}"

first="Computer"
second="Science"
full="$first $second"
echo "$full"

sentence="I like Java, Java is powerfull"
echo "${sentence/Java/Python}"
echo "${sentence//Java/Python}"

str1="abc"
str2="xyz"
if [ "$str1" = "$str2" ]; then
	echo "Strings are equal"
else 
	echo "Strings are not euqal"
fi

word="Hello"
echo "${word^^}"
echo "${word,,}"

echo "Enter a word:"
read word
reverse=""
length=${#word}

for(( i=length-1; i>=0; i--)); do
	reverse="$reverse${word:i:1}"
done

if [ "$word" = "$reverse" ]; then
	echo "$word is a palindrome"
else
	echo "$word is not a palindrome"
fi

