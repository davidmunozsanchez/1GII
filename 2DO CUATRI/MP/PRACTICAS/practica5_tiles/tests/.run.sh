touch tests//.timeout
CMD="valgrind --leak-check=full  valgrind --leak-check=full /home/davidms_83/Documentos/MP/PRACTICAS/practica5_tiles/dist/Debug/GNU-Linux/practica5_tiles  1> tests//.out17 2>&1"
eval $CMD
rm tests//.timeout
