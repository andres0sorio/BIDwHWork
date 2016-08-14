#pequeno script para llenar la DB con datos desde 2006-2008

EXE=llenar

MATRICULAS=(`ls matriculas_20*`)
NOTAS=(`ls notas_20*`)
DESERCION=(`ls deserciones_20*`)

tot=`echo ${#NOTAS[*]}`

for i in `seq 0 4`
  do
  
  if [ $i -lt 1 ]
      then
      OPT='1'
      else
      OPT='0'
  fi
  
  ###echo "${MATRICULAS[$i]} ${NOTAS[$i]} ${DESERCION[$i]} $OPT"
  ./$EXE ${MATRICULAS[$i]} ${NOTAS[$i]} ${DESERCION[$i]} $OPT
  
done
