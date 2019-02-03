#!/bin/bash
#SBATCH -p slurm_shortgpu
#SBATCH --job-name=HW2-1
#SBATCH -N 1 -n 1 --gres=gpu:1	# 1 node
#SBATCH -o job_out
#SBATCH -e job_err

cd $SLURM_SUBMIT_DIR
for i in {10..19}
do
	printf "2^%i:\n";
	./test_file_gen1 $i;
	printf "1a:\n"
	./problem1a;
	printf "1b:\n"
	./problem1b;
	printf "\n";
done

mv job_out problem1.o$SLURM_JOB_ID
mv job_err problem1.e$SLURM_JOB_ID
