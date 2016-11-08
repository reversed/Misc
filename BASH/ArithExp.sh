z=0

z=`expr $z + 3`

echo $z

z=$((z+3))

echo $z

((z+=3))

echo $z

let z+=3

echo $z
