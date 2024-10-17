#!/bin/bash
make fclean
make all
make clean
sleep 1

# Prueba 1 (esperado: éxito)
./push_swap 1 2 3 4 5 6 7 8 2147483647
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
