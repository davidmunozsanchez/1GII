touch tests//.timeout
CMD="valgrind --leak-check=full  valgrind --leak-check=full /home/davidms_83/Documentos/MP/PRACTICAS/practica6_final/dist/Debug/GNU-Linux/practica6_final  -open data/OPEN_ERROR.data 1> tests//.out9 2>&1"
eval $CMD
rm tests//.timeout
