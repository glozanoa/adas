#!/bin/bash
#SBATCH --job-name=bibubble
#SBATCH --nodes=1
#SBATCH --mem=10GB
#SBATCH --partition=strong
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1


#echo -e "Testing bubble algorithm efficiency:\n"
#./bubble

# echo -e "Testing insertion algorithm efficiency:\n"
# ./insertion

# echo -e "Testing selection algorithm efficiency:\n"
# ./selection

echo -e "Testing bidirectional bubble algorithm efficiency:\n"
./bidirectional_bubble
