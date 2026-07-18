#Total Marks
#Number of subject
#Average Marks

marks=(30 50 60 65 89 90)
total=0

for i in ${marks[@]};do
   total=$((total+i))
done

count=${#marks[@]}
average=$((total/count))

echo "Total Marks:$total"
echo "Number of subject:$count"
echo "Average Marks is:$average"
