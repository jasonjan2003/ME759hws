#!/bin/bash
#SBATCH -p slurm_shortgpu
#SBATCH --job-name=HW1-1
#SBATCH -N 1 -n 1 --gres=gpu:1	# 1 node
#SBATCH -o job_out
#SBATCH -e job_err

cd $SLURM_SUBMIT_DIR
./problem2 "Hello"

mv job_out problem1.o$SLURM_JOB_ID
mv job_err problem1.e$SLURM_JOB_ID
