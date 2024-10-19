./bin/bash
make fclean
rm -rf *.txt
rm -rf a.out
git add . ':!trash/'
git commit -m "Update"
git push