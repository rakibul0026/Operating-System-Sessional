echo "Enter a number: "
read num
if [ $num -gt 0 ] ; then
	echo " $num Number is positive"
elif [ $num -lt 0 ] ; then
echo " $num is negative"
else echo" number is zero"
fi

