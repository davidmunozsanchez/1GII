#!/bin/bash

numero_para=$#

if ! [ $numero_para == 1 ] && ! [ $numero_para == 2 ];
    then echo "Introduce argumentos válidos"
    
elif [ $numero_para == 2 ];
    then if [ -d $2 ];
            then find -type f|cp $2;fi;fi
