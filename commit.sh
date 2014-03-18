git pull
git add .
read -p "Please input your commit: " com
echo $com
git commit -m $com
git push
