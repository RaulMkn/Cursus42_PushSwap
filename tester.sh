#!/bin/bash

make fclean
make all
make clean
sleep 1

# Prueba 1 (esperado: éxito)
./push_swap -2147483648 116 955 82 440 894 243 46 600 648 982 692 223 295 71 170 956 435661 747 952 302 1 514 229 431 89 209 665 43 610 412 910 489 87 2739 969 768 55 777 608 484 430 666 893 123 103 583 358 493 512 787319 558 332 471 248 498 339 615 202 470 685 449 372 373 331 23 325526 532 645 837 702 675 638 178 626 603 798 306 327 413 863 990 520208 587 137 975 348 699 14 607 602 773 892 238 260 342 888 153 548404 292 105 733 646 577 456 318 416 393 476 225 559 98 758 921 87259 891 272 897 283 424 886 925 973 144 479 870 560 710 38 303 540854 130 39 945 405 361 721 410 834 900 128 77 506 609 789 377 637971 752 968 570 224 155 199 463 814 846 965 114 642 731 236 464 874601 85 800 869 958 63 446 941 111 991 94 563 755 394 657 359 547274 310 594 916 627 294 246 411 769 519 531 976 190 126 376 469 1367 8 244 457 384 143 436 168 719 614 812 737 251 522 336 683 895 652781 691 102 502 60 736 369 422 286 345 220 324 326 867 30 791 725836 928 354 625 312 214 477 494 562 757 24 468 121 49 599 967 545935 51 406 432 765 169 528 592 521 395 673 347 729 316 525 232 51078 653 288 392 885 799 855 697 782 442 401 841 11 90 844 655 786284 597 700 963 774 544 346 884 920 620 322 277 970 630 333 335 1724 804 221 210 978 201 811 843 69 363 743 28 235 216 152 631 12 96166 576 995 448 125 660 953 433 718 109 556 696 76 390 750 193 831641 582 954 701 497 27 353 305 54 880 204 890 350 141 64 253 79345 795 849 13 766 984 56 567 596 25 279 352 6 194 896 171 715 857759 110 807 40 634 320 398 127 162 364 297 328 407 254 669 74 53933 838 934 889 853 366 639 979 270 386 649 315 177 408 329 716 441301 452 695 47 764 640 206 365 491 922 135 746 762 546 845 117 82992 75 581 944 882 417 459 650 815 351 259 574 371 93 727 276 215551 917 269 360 554 138 84 662 585 818 552 988 905 960 409 796 753261 656 104 36 146 667 481 707 382 927 419 516 480 337 633 923 443119 981 212 278 772 946 73 113 281 876 819 654 483 165 179 139 96461 824
if [ $? -eq 0 ]; then
    echo "Prueba 1: Fallida (como se esperaba)"
else
    echo "Prueba 1: Exitosa (no se esperaba fallo)"
fi
valgrind --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=1 ./push_swap 000000000000012345678900 116 955 82 440 894 243 46 600 648 982 692 223 295 71 170 956 435661 747 952 302 1 514 229 431 89 209 665 43 610 412 910 489 87 2739 969 768 55 777 608 484 430 666 893 123 103 583 358 493 512 787319 558 332 471 248 498 339 615 202 470 685 449 372 373 331 23 325526 532 645 837 702 675 638 178 626 603 798 306 327 413 863 990 520208 587 137 975 348 699 14 607 602 773 892 238 260 342 888 153 548404 292 105 733 646 577 456 318 416 393 476 225 559 98 758 921 87259 891 272 897 283 424 886 925 973 144 479 870 560 710 38 303 540854 130 39 945 405 361 721 410 834 900 128 77 506 609 789 377 637971 752 968 570 224 155 199 463 814 846 965 114 642 731 236 464 874601 85 800 869 958 63 446 941 111 991 94 563 755 394 657 359 547274 310 594 916 627 294 246 411 769 519 531 976 190 126 376 469 1367 8 244 457 384 143 436 168 719 614 812 737 251 522 336 683 895 652781 691 102 502 60 736 369 422 286 345 220 324 326 867 30 791 725836 928 354 625 312 214 477 494 562 757 24 468 121 49 599 967 545935 51 406 432 765 169 528 592 521 395 673 347 729 316 525 232 51078 653 288 392 885 799 855 697 782 442 401 841 11 90 844 655 786284 597 700 963 774 544 346 884 920 620 322 277 970 630 333 335 1724 804 221 210 978 201 811 843 69 363 743 28 235 216 152 631 12 96166 576 995 448 125 660 953 433 718 109 556 696 76 390 750 193 831641 582 954 701 497 27 353 305 54 880 204 890 350 141 64 253 79345 795 849 13 766 984 56 567 596 25 279 352 6 194 896 171 715 857759 110 807 40 634 320 398 127 162 364 297 328 407 254 669 74 53933 838 934 889 853 366 639 979 270 386 649 315 177 408 329 716 441301 452 695 47 764 640 206 365 491 922 135 746 762 546 845 117 82992 75 581 944 882 417 459 650 815 351 259 574 371 93 727 276 215551 917 269 360 554 138 84 662 585 818 552 988 905 960 409 796 753261 656 104 36 146 667 481 707 382 927 419 516 480 337 633 923 443119 981 212 278 772 946 73 113 281 876 819 654 483 165 179 139 96461 824 &> valgrind_output.txt
if grep -q "All heap blocks were freed -- no leaks are possible" valgrind_output.txt; then
    echo "No hay fugas de memoria."
else
    echo "Se encontraron fugas de memoria."
    cat valgrind_output.txt
fi
rm -rf valgrind_output.txt

echo "--------------------------------------------------------------------------------------------------"

# Prueba 2 (esperado: éxito)
./push_swap "1 2 3 4 5 6 7 8 2147483647"
if [ $? -eq 0 ]; then
    echo "Prueba 2: Exitosa (como se esperaba)"
else
    echo "Prueba 2: Fallida (no se esperaba fallo)"
fi
valgrind --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=1 ./push_swap "1 2 3 4 5 6 7 8 2147483647" &> valgrind_output.txt
if grep -q "All heap blocks were freed -- no leaks are possible" valgrind_output.txt; then
    echo "No hay fugas de memoria."
else
    echo "Se encontraron fugas de memoria."
    cat valgrind_output.txt
fi
rm -rf valgrind_output.txt

echo "--------------------------------------------------------------------------------------------------"

# Prueba 3 (esperado: error)
./push_swap 1 3 dog 35 80 -3
if [ $? -ne 0 ]; then
    echo "Prueba 3: Fallida (como se esperaba)"
else
    echo "Prueba 3: Exitosa (no se esperaba éxito)"
fi
valgrind --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=1 ./push_swap 1 3 dog 35 80 -3 &> valgrind_output.txt
if grep -q "All heap blocks were freed -- no leaks are possible" valgrind_output.txt; then
    echo "No hay fugas de memoria."
else
    echo "Se encontraron fugas de memoria."
    cat valgrind_output.txt
fi
rm -rf valgrind_output.txt

echo "--------------------------------------------------------------------------------------------------"

# Prueba 4 (esperado: error)
./push_swap 1 2 3 5 67b778 947
if [ $? -ne 0 ]; then
    echo "Prueba 4: Fallida (como se esperaba)"
else
    echo "Prueba 4: Exitosa (no se esperaba éxito)"
fi
valgrind --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=1 ./push_swap 1 2 3 5 67b778 947 &> valgrind_output.txt
if grep -q "All heap blocks were freed -- no leaks are possible" valgrind_output.txt; then
    echo "No hay fugas de memoria."
else
    echo "Se encontraron fugas de memoria."
    cat valgrind_output.txt
fi
rm -rf valgrind_output.txt

echo "--------------------------------------------------------------------------------------------------"

# Prueba 5 (esperado: error)
./push_swap " 12 4 6 8 54fhd 4354"
if [ $? -ne 0 ]; then
    echo "Prueba 5: Fallida (como se esperaba)"
else
    echo "Prueba 5: Exitosa (no se esperaba éxito)"
fi
valgrind --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=1 ./push_swap " 12 4 6 8 54fhd 4354" &> valgrind_output.txt
if grep -q "All heap blocks were freed -- no leaks are possible" valgrind_output.txt; then
    echo "No hay fugas de memoria."
else
    echo "Se encontraron fugas de memoria."
    cat valgrind_output.txt
fi
rm -rf valgrind_output.txt

echo "--------------------------------------------------------------------------------------------------"

# Prueba 6 (esperado: error)
./push_swap 1 -- 45 32
if [ $? -ne 0 ]; then
    echo "Prueba 6: Fallida (como se esperaba)"
else
    echo "Prueba 6: Exitosa (no se esperaba éxito)"
fi
valgrind --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=1 ./push_swap 1 -- 45 32 &> valgrind_output.txt
if grep -q "All heap blocks were freed -- no leaks are possible" valgrind_output.txt; then
    echo "No hay fugas de memoria."
else
    echo "Se encontraron fugas de memoria."
    cat valgrind_output.txt
fi
rm -rf valgrind_output.txt

echo "--------------------------------------------------------------------------------------------------"
