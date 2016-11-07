read -p "enter the dir: " dir
filelist=`ls $dir`

for filename in $filelist
do
    perm=""
    if [ -x "$dir/$filename" ] 
    then
        echo "$filename excutable"
    else
        echo "$filename not excutable"
    fi
done
