./bin/bash
make fclean
rm -rf *.txt
git add . ':!trash/'
git commit -m "Update"
git push