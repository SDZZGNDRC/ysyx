#include <stdlib.h>
#include <ctype.h>
#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <common.h>
#include <memory/paddr.h>
#include "sdb.h"

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}
vaddr_t str2pc(char *str){
  /*Convert the string in hex to number in dec*/
  int slen = strlen(str);
  vaddr_t pc;
  int i;
  for(i = 0, pc = 0; i<slen; i++){
	  if(isalpha(str[i])){
		  if(isupper(str[i])){
			  pc = pc*16 + str[i] - 'A' + 10;
		  }else{
			  pc = pc*16 + str[i] - 'a' + 10;
		  }
	  }else if(isdigit(str[i])){
			  pc = pc*16 + str[i] - '0';
	  }else{
	  	printf("str2pc: input error!\n");
		return 0;
	  }
  }
  printf("str2pc: pc = %lu\n", pc);
  return pc;
}
static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  return -1;
}
static int cmd_si(char *args){
  cpu_exec(atoi(args));
  //printf("cmd_si: %s\n", args);
  return 0;
}

static int cmd_info(char *args){
  if(strcmp(args,"r") == 0){
	  isa_reg_display();
	  return 0;
  }else{
	  printf("cmd_info: args error!\n");
	  return -1;
  }
  return -1;
}
static int cmd_x(char *args){
  int n = atoi(strtok(args, " "));
  vaddr_t pc;
  char *str = strtok(NULL, " ");
  if(strlen(str)<4){
	  printf("cmd_x: input error!\n");
	  return -1;
  }
  pc = str2pc(str+2);
  printf("1: %d\n", n);
  printf("2: %lu\n", pc);
  return 0;
}
static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display informations about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Execution by n steps", cmd_si },
  { "info", "Printf all the global regs", cmd_info },
  { "x", "scanf the memory", cmd_x },
  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
