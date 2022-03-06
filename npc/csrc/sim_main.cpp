#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
int main(int argc, char **argv, char **env){
	VerilatedContext* contextp = new VerilatedContext;
	//const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
	contextp->commandArgs(argc, argv);
	Vtop* top = new Vtop{contextp};
	//const std::unique_ptr<Vtop> top{new Vtop{contextp.get(), "TOP"}};
	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	top->trace(tfp, 99);
	tfp->open("obj_dir/test/simx.vcd");
	int n = 0;
	while(n < 100){
		contextp->timeInc(1);
		int a = rand() & 1;
		int b = rand() & 1;
		top->a = a;
		top->b = b;
	       	top->eval(); 
		tfp->dump(contextp->time());
		printf("a = %d, b = %d, f = %d\n", a, b, top->f);
		assert(top->f == a ^ b);
		n++;
	}
	tfp->close();
	delete tfp;
	delete top;
	delete contextp;
	return 0;
}
