#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top){
	nvboard_bind_pin(&top->f, false, true, 1, LD0);
	nvboard_bind_pin(&top->a, false, false, 1, SW0);
	nvboard_bind_pin(&top->b, false, false, 1, SW1);
}