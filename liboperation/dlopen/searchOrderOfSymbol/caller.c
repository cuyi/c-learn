/*
    The constructor attribute causes the function 
    to be called automatically before execution 
    enters main (). Similarly, the destructor 
    attribute causes the function to be called 
    automatically after main () completes or 
    exit () is called. Functions with these 
    attributes are useful for initializing data 
    that is used implicitly during the execution 
    of the program.
*/
void __attribute__((constructor)) caller(void)
{
    extern void callee(void);
    callee();
}