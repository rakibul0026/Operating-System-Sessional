square(){
     echo  $(( $1 * $2 ))
}
answer=$(square 6 7)
echo "Square: $answer"
