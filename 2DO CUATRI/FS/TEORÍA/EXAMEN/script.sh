 #!/bin/bash
 
 user=`whoami`
 if ! [ $# == 2 ];
    then echo "Introduce argumentos válidos para saludar(saludo, fecha)" && exit 1
    
else
    echo $1", "$user". Hoy es "`date -d $2 +%A`".";fi
