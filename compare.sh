echo "                      STD RESULT \n"
clang++ main.cpp && ./a.out
echo "\n                      MY RESULT \n"
clang++ main.cpp -D MY && ./a.out