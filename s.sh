read -p "Enter 1 2 or 3||4: " n
case $n in
1)
echo "You entered 1"
;;
2)
echo"You entered 2"
;;
3|4)
echo"You entered either 3 or 4"
;;
*)
echo "Lode sahi number daal na bc"
esac
