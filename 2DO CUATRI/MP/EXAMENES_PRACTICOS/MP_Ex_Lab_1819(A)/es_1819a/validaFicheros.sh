#!/bin/bash
BASE=data

function Compara() {
    echo "Comparando ficheros de datos "$1" y "$2
    sort $1 > $1".sort"
    sort $2 > $2".sort"
    if diff $1".sort" $2".sort"; then
            echo "CORRECTO!"
    else
            echo "ERROR: Fichero $1 incorrecto"
    fi

}

for i in {0..9} 
do
    if test -f "data/salida_$i.in"; 
    then
        Compara "$BASE/salida_$i.in" "$BASE/val_salida_$i.in"
        Compara "$BASE/salida_$i.out" "$BASE/val_salida_$i.out"
        rm $BASE/*.sort
        exit
    fi
done
echo "ERROR: Ficheros de salida no encontrados"
