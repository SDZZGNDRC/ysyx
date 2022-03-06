VPATH = csrc  vsrc
all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator --Wall --cc --trace --exe --build sim_main.cpp ./vsrc/top.v
	obj_dir/Vtop
	gtkwave obj_dir/simx.vcd	
include ../Makefile
