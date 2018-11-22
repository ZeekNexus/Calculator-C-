#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define ERRORMESSAGE printf("first enter (0)*sum (1)*subtract (2)*multiply (3)times tables \nand the variables being operated on if the operation requires it*\n"); return 0;
//#define NOINPUT argv[2] = "0\0"; argv[3] = "0\0"; argc = 4;

u_int64_t sum(u_int64_t a, u_int64_t b){
	printf("+ %li ", b);
	return a+b;
}

u_int64_t sub(u_int64_t a, u_int64_t b){
	printf("- %li ", b);	
	return a-b;
}

u_int64_t mul(u_int64_t a, u_int64_t b){
	printf("x %li ", b);
	return a*b;
}

u_int64_t timestables(u_int64_t a, u_int64_t b){
	for(int i = 1; i <= 12; i++) {
		if(i != 1) printf("\n");
		printf("     %i times tables\n",i);
		for(int j = 1; j <= 12; j++){
			printf("%i*%i = %i \t",i, j, i*j);
			if((j-1)%2) printf("\n");
		}	
	}
	return 0;
}

u_int64_t main(u_int64_t argc, char const *argv[])
{
	u_int64_t funct_count;
	char *p;
	u_int64_t (*arithmatic_operation_ptr[])(u_int64_t, u_int64_t) = {sum, sub, mul, timestables};
	u_int64_t op, a, b;
	if(!(argc > 1 )) {ERRORMESSAGE} 
	if(!strcmp(argv[1], "3")) {
		argv[2] = "0\0"; 
		argv[3] = "0\0"; 
		argc = 4;
	}
	else if(argc < 4) {ERRORMESSAGE}
	if(strcmp(argv[1], "0") && strcmp(argv[1], "1") 
	   	&& strcmp(argv[1], "2") && strcmp(argv[1], "3")) {ERRORMESSAGE}
    
    a = strtol(argv[2], &p, 10);
	
	if(argc > 6) printf("  ");
   		if(strcmp(argv[1], "3")) printf("%li ",a);
    	for(u_int64_t i = 1; i < argc-2; i++){
   			if(!(i%4)) printf("\n");
    
    		b = strtol(argv[i+2], &p, 10);	
    		a = (*arithmatic_operation_ptr[strtol(argv[1], &p, 10)])(a, b);
   		}
   	if(!strcmp(argv[1], "3")) return 0;

   	int vars = argc-2;
    printf("\n= %li\n", a);
    return 0;
}



