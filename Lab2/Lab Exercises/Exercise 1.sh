
#!/bin/bash

echo "Enter your name:"
read name


echo "Enter your age:"
read age

birth_year=$((2026 - age))

echo "Name: $name, Age: $age, Birth Year: $birth_year"
