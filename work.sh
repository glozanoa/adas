#!/bin/bash
#SBATCH --nodes=1
#SBATCH --mem=10GB
#SBATCH --partition=strong
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1


echo -e "Testing bubble algorithm efficient:\n"
./bubble
