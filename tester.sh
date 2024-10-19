#!/bin/bash
make fclean
make all
make clean
sleep 1
# Prueba 1 (esperado: éxito)
./push_swap 1 2 3
echo "push_swap 1 2 3"
if [ $? -eq 0 ]; then
    echo "Prueba 2: Exitosa (como se esperaba)"
else
    echo "Prueba 2: Fallida (no se esperaba fallo)"
fi
valgrind --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=1 ./push_swap 1 2 3 &> valgrind_output.txt
if grep -q "All heap blocks were freed -- no leaks are possible" valgrind_output.txt; then
    echo "No hay fugas de memoria."
else
    echo "Se encontraron fugas de memoria."
    cat valgrind_output.txt
fi
rm -rf valgrind_output.txt

echo "--------------------------------------------------------------------------------------------------"

# Prueba 2 (esperado: éxito)
./push_swap "1 3 2"
echo push_swap "1 3 2"
if [ $? -eq 0 ]; then
    echo "Prueba 2: Exitosa (como se esperaba)"
else
    echo "Prueba 2: Fallida (no se esperaba fallo)"
fi
valgrind --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=1 ./push_swap "1 3 2" &> valgrind_output.txt
if grep -q "All heap blocks were freed -- no leaks are possible" valgrind_output.txt; then
    echo "No hay fugas de memoria."
else
    echo "Se encontraron fugas de memoria."
    cat valgrind_output.txt
fi
rm -rf valgrind_output.txt

echo "--------------------------------------------------------------------------------------------------"

# Prueba 3 (esperado: error)
./push_swap 2 1 3
echo "push_swap 2 1 3"
if [ $? -ne 0 ]; then
    echo "Prueba 3: Exitosa (como se esperaba)"
else
    echo "Prueba 3: Fallida (no se esperaba éxito)"
fi
valgrind --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=1 ./push_swap 2 1 3 &> valgrind_output.txt
if grep -q "All heap blocks were freed -- no leaks are possible" valgrind_output.txt; then
    echo "No hay fugas de memoria."
else
    echo "Se encontraron fugas de memoria."
    cat valgrind_output.txt
fi
rm -rf valgrind_output.txt

echo "--------------------------------------------------------------------------------------------------"

# Prueba 4 (esperado: error)
./push_swap 2 3 1
echo "push_swap 2 3 1"
if [ $? -ne 0 ]; then
    echo "Prueba 4: Exitosa (como se esperaba)"
else
    echo "Prueba 4: Fallida"
fi
valgrind --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=1 ./push_swap 2 3 1 &> valgrind_output.txt
if grep -q "All heap blocks were freed -- no leaks are possible" valgrind_output.txt; then
    echo "No hay fugas de memoria."
else
    echo "Se encontraron fugas de memoria."
    cat valgrind_output.txt
fi
rm -rf valgrind_output.txt

echo "--------------------------------------------------------------------------------------------------"

# Prueba 5 (esperado: error)
./push_swap "3 1 2"
echo "push_swap 3 1 2"
if [ $? -ne 0 ]; then
    echo "Prueba 5: Exitosa (como se esperaba)"
else
    echo "Prueba 5: Fallida"
fi
valgrind --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=1 ./push_swap "3 1 2" &> valgrind_output.txt
if grep -q "All heap blocks were freed -- no leaks are possible" valgrind_output.txt; then
    echo "No hay fugas de memoria."
else
    echo "Se encontraron fugas de memoria."
    cat valgrind_output.txt
fi
rm -rf valgrind_output.txt

echo "--------------------------------------------------------------------------------------------------"

# Prueba 6 (esperado: error)
./push_swap 3 2 1
echo "push_swap 3 2 1"
if [ $? -ne 0 ]; then
    echo "Prueba 6: Exitosa (como se esperaba)"
else
    echo "Prueba 6: Fallida"
fi
valgrind --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=1 ./push_swap 3 2 1 &> valgrind_output.txt
if grep -q "All heap blocks were freed -- no leaks are possible" valgrind_output.txt; then
    echo "No hay fugas de memoria."
else
    echo "Se encontraron fugas de memoria."
    cat valgrind_output.txt
fi
rm -rf valgrind_output.txt

echo "--------------------------------------------------------------------------------------------------"
