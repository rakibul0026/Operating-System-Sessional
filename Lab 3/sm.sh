marks=(80 90 75 60 95)
total=0

for m in "${marks[@]}"; do
	total=$((total+m))
done

count=${#marks[@]}
average=$((total/count))

echo " Total Marks: $total"
echo " Number of Subjects: $count"
echo " Average Marks: $average"

