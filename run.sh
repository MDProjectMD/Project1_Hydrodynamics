
export MATLAB="/Applications/MATLAB_R2019b.app/"

export DYLD_LIBRARY_PATH=$MATLAB/bin/maci64/:$MATLAB/sys/os/maci64/:$DYLD_LIBRARY_PATH

make -f Makefile

./run
