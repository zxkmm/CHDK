#include "conf.h"

int *video_quality = &conf.video_quality;
int *video_mode    = &conf.video_mode;

long def_table1[9]={0x2000,0x38D,0x788,0x5800,0x9C5,0x14B8,0x10000,0x1C6A,0x3C45};
long def_table2[9]={0x1CCD,-0x2E1,-0x579,0x4F33,-0x7EB,-0xF0C,0xE666,-0x170A,-0x2BC6};

long table1[9], table2[9];

void change_video_tables(int a, int b){
 int i;
 for (i=0;i<9;i++) {table1[i]=(def_table1[i]*a)/b; table2[i]=(def_table2[i]*a)/b;}
}

long CompressionRateTable[]={0x60, 0x5D, 0x5A, 0x57, 0x54, 0x51, 0x4D, 0x48, 0x42, 0x3B, 0x32, 0x29, 0x22, 0x1D, 0x17, 0x14, 0x10, 0xE, 0xB, 9, 7, 6, 5, 4, 3, 2, 1};


void __attribute__((naked,noinline)) movie_record_task(){ //FFD3ACA8 done

 asm volatile(
                "STMFD   SP!, {R4,LR}\n"    
                "SUB     SP, SP, #4\n"      
                "MOV     R4, SP\n"          
                "B       loc_FFD3AD5C\n"    
"loc_FFD3ACB8:\n"                           
                "LDR     R3, =0x64778\n"    
                "LDR     R2, [R3]\n"        
                "CMP     R2, #0\n"          
                "BNE     loc_FFD3AD48\n"    
                "SUB     R3, R12, #2\n"     
                "CMP     R3, #9\n"          
                "LDRLS   PC, [PC,R3,LSL#2]\n" 
                "B       loc_FFD3AD48\n"    
                ".long loc_FFD3AD08\n"
                ".long loc_FFD3AD20\n"
                ".long loc_FFD3AD28\n"
                ".long loc_FFD3AD30\n"
                ".long loc_FFD3AD10\n"
                ".long loc_FFD3AD38\n"
                ".long loc_FFD3AD18\n"
                ".long loc_FFD3AD48\n"
                ".long loc_FFD3AD40\n"
                ".long loc_FFD3AD00\n"
"loc_FFD3AD00:\n"                           
                "BL      sub_FFD3ADF4\n"    
                "B       loc_FFD3AD44\n"    
"loc_FFD3AD08:\n"                           
                "BL      sub_FFD3AFA8\n"    
                "B       loc_FFD3AD44\n"    
"loc_FFD3AD10:\n"                           
                "BL      sub_FFD3B37C_my\n"   //----------------> 
                "B       loc_FFD3AD44\n"    
"loc_FFD3AD18:\n"                           
                "BL      sub_FFD3B7B0\n"    
                "B       loc_FFD3AD44\n"    
"loc_FFD3AD20:\n"                           
                "BL      sub_FFD3B614\n"    
                "B       loc_FFD3AD44\n"    
"loc_FFD3AD28:\n"                           
                "BL      sub_FFD3B920\n"    
                "B       loc_FFD3AD44\n"    
"loc_FFD3AD30:\n"                           
                "BL      sub_FFD3BAE4\n"    
                "B       loc_FFD3AD44\n"    
"loc_FFD3AD38:\n"                           
                "BL      sub_FFD3B838\n"    
                "B       loc_FFD3AD44\n"    
"loc_FFD3AD40:\n"                           
                "BL      sub_FFD3B664\n"    
"loc_FFD3AD44:\n"                           
                "LDR     R1, [SP]\n"      
"loc_FFD3AD48:\n"                           
                "LDR     R3, =0x646AC\n"    
                "MOV     R2, #0\n"          
                "STR     R2, [R1]\n"        
                "LDR     R0, [R3]\n"        
                "BL      sub_FFC104D8\n" 
"loc_FFD3AD5C:\n"                           
                "LDR     R3, =0x646A8\n"    
                "MOV     R1, R4\n"          
                "LDR     R0, [R3]\n"        
                "MOV     R2, #0\n"          
                "BL      sub_FFC100C0\n" 
                "LDR     R0, [SP]\n"        
                "LDR     R12, [R0]\n"       
                "CMP     R12, #0xC\n"       
                "MOV     R1, R0\n"          
                "BNE     loc_FFD3ACB8\n"    
                "LDR     R3, =0x646A4\n"    
                "LDR     R0, [R3]\n"        
                "BL      sub_FFC10E54\n"   
                "BL      sub_FFC1161C\n"        
                "ADD     SP, SP, #4\n"      
                "LDMFD   SP!, {R4,PC}\n"    

 );
}


void __attribute__((naked,noinline)) sub_FFD3B37C_my(){
 asm volatile(
                "STMFD   SP!, {R4-R11,LR}\n" 
                "LDR     R5, =0x64794\n"    
                "SUB     SP, SP, #0x34\n"   
                "LDR     R3, [R5]\n"        
                "CMP     R3, #3\n"          
                "MOV     R4, R0\n"          
                "MOVEQ   R3, #4\n"          
                "STREQ   R3, [R5]\n"        
                "LDR     R3, =0x64844\n"    
                "MOV     LR, PC\n"          
                "LDR     PC, [R3]\n"        
                "LDR     R2, [R5]\n"        
                "CMP     R2, #4\n"          
                "BNE     loc_FFD3B540\n"    
                "ADD     R0, SP, #0x30\n"   
                "ADD     R1, SP, #0x2C\n"   
                "ADD     R2, SP, #0x28\n"   
                "ADD     R3, SP, #0x24\n"   
                "BL      sub_FFD3CA50_my\n"   //----------------> 
                "CMP     R0, #0\n"          
                "BNE     loc_FFD3B3F8\n"    
                "LDR     R3, =0x64780\n"    
                "LDR     R2, [R3]\n"        
                "CMP     R2, #1\n"          
                "BNE     loc_FFD3B40C\n"    
                "LDR     R2, =0x647D8\n"    
                "LDR     R1, =0x647AC\n"    
                "LDR     R12, [R2]\n"       
                "LDR     R3, [R1]\n"        
                "CMP     R12, R3\n"         
                "BCC     loc_FFD3B40C\n"    

"loc_FFD3B3F8:\n"                           
                "BL      sub_FFD3B58C\n"    
                "BL      sub_FFD3B78C\n"    
                "MOV     R3, #5\n"          
                "STR     R3, [R5]\n"        
                "B       loc_FFD3B540\n"    

"loc_FFD3B40C:\n"                           
                                        
                "LDR     R12, =0x647E0\n"   
                "LDR     R11, =0x647EC\n"   
                "LDMIB   R4, {R0-R2}\n"     
                "LDR     R10, [R12]\n"      
                "LDR     R7, [R11]\n"       
                "LDR     R4, [SP,#0x2C]\n"  
                "LDR     R5, [SP,#0x28]\n"  
                "LDR     R6, [SP,#0x24]\n"  
                "LDR     R8, =0x64784\n"    
                "LDR     R3, [SP,#0x30]\n"  
                "ADD     R12, SP, #0x20\n"  
                "ADD     LR, SP, #0x1C\n"   
                "MOV     R9, #1\n"          
                "STMEA   SP, {R4-R6,R12}\n" 
                "STR     R10, [SP,#0x10]\n" 
                "STR     R7, [SP,#0x14]\n"  
                "STR     LR, [SP,#0x18]\n"  
                "STR     R9, [R8]\n"        
                "BL      sub_FFC84D70\n"    
                "LDR     R3, =0x6469C\n"    
                "MOV     R1, #0x3E8\n"      
                "LDR     R0, [R3]\n"        
                "BL      sub_FFC10C6C\n"   
                "CMP     R0, #9\n"          
                "BNE     loc_FFD3B480\n"    
                "BL      sub_FFD3D260\n"    
                "LDR     R3, =0x64794\n"    
                "LDR     R0, =0xFFD3B364\n" 
                "B       loc_FFD3B498\n"    
"loc_FFD3B480:\n"                           
                "LDR     R5, [SP,#0x1C]\n"  
                "CMP     R5, #0\n"          
                "BEQ     loc_FFD3B4A4\n"    
                "BL      sub_FFD3D260\n"    
                "LDR     R3, =0x64794\n"    
                "LDR     R0, =0xFFD3B37\n" 

"loc_FFD3B498:\n"                           
                "STR     R9, [R3]\n"        
                "BL      sub_FFD50170\n"    
                "B       loc_FFD3B540\n"    

"loc_FFD3B4A4:\n"                           
                "BL      sub_FFC84EDC\n"    
                "LDR     R0, [SP,#0x30]\n"  
                "LDR     R1, [SP,#0x20]\n"  
                "BL      sub_FFD3CF84\n"    
                "LDR     R4, =0x647D8\n"    
                "LDR     R3, [R4]\n"        
                "ADD     R3, R3, #1\n"      
                "LDR     R0, [SP,#0x20]\n"  
                "MOV     R1, R11\n"         
                "STR     R3, [R4]\n"        
                "MOV     R2, R5\n"          
                "BL     sub_FFD3BE40_my\n"    //--------------->
                "LDR     R3, =0x647F8\n"    
                "LDR     R1, [R4]\n"        
                "LDR     R2, [R3]\n"        
                "LDR     R12, =0x647F4\n"   
                "MUL     R0, R2, R1\n"      
                "LDR     R1, [R12]\n"       
                "BL      sub_FFED4B98\n"       
                "LDR     R7, =0x647F0\n"    
                "LDR     R3, [R7]\n"        
                "MOV     R4, R0\n"          
                "CMP     R3, R4\n"          
                "BNE     loc_FFD3B518\n"    
                "LDR     R6, =0x64788\n"    
                "LDR     R3, [R6]\n"        
                "CMP     R3, #1\n"          
                "BNE     loc_FFD3B534\n"    
                "B       loc_FFD3B51C\n"    

"loc_FFD3B518:\n"                           
                "LDR     R6, =0x64788\n"    

"loc_FFD3B51C:\n"                           
                "LDR     R3, =0x64828\n"    
                "MOV     R0, R4\n"          
                "MOV     LR, PC\n"          
                "LDR     PC, [R3]\n"        
                "STR     R5, [R6]\n"        
                "STR     R4, [R7]\n"        

"loc_FFD3B534:\n"                           
                "LDR     R2, =0x64784\n"    
                "MOV     R3, #0\n"          
                "STR     R3, [R2]\n"        

"loc_FFD3B540:\n"                           
                                        
                "ADD     SP, SP, #0x34\n"   
                "LDMFD   SP!, {R4-R11,PC}\n" 

                "MOV     PC, LR\n"          
 );
}

void __attribute__((naked,noinline)) sub_FFD3CA50_my(){ // done
 asm volatile(
                "STMFD   SP!, {R4-R11,LR}\n" 
                "LDR     R5, =0x64AEC\n"    
                "SUB     SP, SP, #0x14\n"   
                "LDR     LR, [R5]\n"        
                "LDR     R12, =0x64B04\n"   
                "ADD     LR, LR, #1\n"      
                "LDR     R4, [R12]\n"       
                "STR     LR, [R5]\n"        
                "LDR     R12, =0x64B84\n"   
                "STR     R0, [SP,#0x10]\n"  
                "STR     R1, [SP,#0xC]\n"   
                "STR     R2, [SP,#8]\n"     
                "STR     R3, [SP,#4]\n"     
                "CMP     LR, R4\n"          
                "LDR     R11, [R12]\n"      
                "MOVHI   R0, #0x80000001\n"  // remove frame
                "BHI     loc_FFD3CF38\n"     // (time) limit
                "LDR     R3, =0x64B68\n"    
                "MOV     R0, LR\n"          
                "LDR     R1, [R3]\n"        
                "BL      sub_FFED5228\n"       
                "CMP     R0, #1\n"          
                "BNE     loc_FFD3CC70\n"    
                "LDR     R0, =0x64B8C\n"    
                "LDR     R1, =0x64AD8\n"    
                "LDR     R3, [R0]\n"        
                "LDR     R2, [R1]\n"        
                "CMP     R3, R2\n"          
                "LDREQ   R3, =0x64B88\n"    
                "LDREQ   R5, [R3]\n"        
                "MOVNE   R5, R2\n"          
                "LDR     R3, =0x64AEC\n"    
                "LDR     R2, =0x64B68\n"    
                "LDR     R0, [R3]\n"        
                "LDR     R1, [R2]\n"        
                "BL      sub_FFED4B98\n"       
                "LDR     R3, =0x64AE0\n"    
                "ADD     R0, R0, #1\n"      
                "AND     R0, R0, #1\n"      
                "STR     R5, [R3,R0,LSL#2]\n" 
                "LDR     R3, =0x64AD4\n"    
                "LDR     R2, [R3]\n"        
                "CMP     R5, R2\n"          
                "BHI     loc_FFD3CB20\n"    
                "LDR     R4, =0x64B24\n"    
                "LDR     R3, [R4]\n"        
                "ADD     R3, R5, R3\n"      
                "ADD     R3, R3, #8\n"      
                "CMP     R2, R3\n"          
                "BCS     loc_FFD3CB24\n"    

"loc_FFD3CB18:\n"                            
                                        
                "MOV     R0, #0x80000003\n" 
                "B       loc_FFD3CF38\n"    


"loc_FFD3CB20:\n"                            
                "LDR     R4, =0x64B24\n"    

"loc_FFD3CB24:\n"                            
                "LDR     R3, [R4]\n"        
                "LDR     R2, =0x64B8C\n"    
                "ADD     R1, R5, R3\n"      
                "LDR     R3, [R2]\n"        
                "ADD     R2, R1, #8\n"      
                "CMP     R2, R3\n"          
                "BLS     loc_FFD3CB70\n"    
                "LDR     R2, =0x64B88\n"    
                "LDR     R0, =0x64AD4\n"    
                "RSB     R3, R3, R1\n"      
                "LDR     R1, [R2]\n"        
                "ADD     R3, R3, #8\n"      
                "LDR     R2, [R0]\n"        
                "ADD     R1, R1, R3\n"      
                "CMP     R2, R1\n"          
                "BCC     loc_FFD3CB18\n"    
                "LDR     R3, =0x64AD8\n"    
                "STR     R1, [R3]\n"        
                "B       loc_FFD3CB78\n"    


"loc_FFD3CB70:\n"                            
                "LDR     R3, =0x64AD8\n"    
                "STR     R2, [R3]\n"        

"loc_FFD3CB78:\n"                            
                "LDR     R3, [R4]\n"        
                "LDR     R12, =0x64B38\n"   
                "ADD     R3, R3, #0x18\n"   
                "LDR     R2, [R12,#4]\n"    
                "MOV     R0, R3\n"          
                "MOV     R1, #0\n"          
                "CMP     R1, R2\n"          
                "BHI     loc_FFD3CDBC\n"    
                "BNE     loc_FFD3CBA8\n"    
                "LDR     R3, [R12]\n"       
                "CMP     R0, R3\n"          
                "BHI     loc_FFD3CDBC\n"    

"loc_FFD3CBA8:\n"                            
                "LDR     R4, [R4]\n"        
                "LDR     LR, =0x64B40\n"    
                "STR     R4, [SP]\n"        
                "LDR     R12, =0x64B38\n"   
                "LDR     R3, =0x64AEC\n"    
                "LDMIA   LR, {R7,R8}\n"     
                "LDMIA   R12, {R5,R6}\n"    
                "LDR     R10, [R3]\n"       
                "LDR     R2, =0x64B68\n"    
                "MOV     R3, R4\n"          
                "MOV     R4, #0\n"          
                "ADDS    R7, R7, R3\n"      
                "ADC     R8, R8, R4\n"      
                "LDR     R9, [R2]\n"        
                "SUBS    R5, R5, R3\n"      
                "SBC     R6, R6, R4\n"      
                "MVN     R2, #0\n"          //diff ? BB
                "MVN     R1, #0x17\n"       //diff ? bb
                "ADDS    R5, R5, R1\n"      
                "MOV     R4, #0\n"          
                "MOV     R3, #0x18\n"       
                "ADC     R6, R6, R2\n"      
                "ADDS    R7, R7, R3\n"      
                "ADC     R8, R8, R4\n"      
                "STMIA   R12, {R5,R6}\n"    
                "SUB     R0, R10, #1\n"     
                "MOV     R1, R9\n"          
                "STMIA   LR, {R7,R8}\n"     
                "BL      sub_FFED4B98\n"       
                "CMP     R10, #1\n"         
                "MLA     R0, R9, R0, R0\n"  
                "BEQ     loc_FFD3CC70\n"    
                "SUB     R3, R0, #1\n"      
                "MOV     R3, R3,LSL#4\n"    
                "ADD     R4, R11, #0x10\n"  
                "ADD     R5, R11, #0x14\n"  
                "LDR     R1, [R5,R3]\n"     
                "LDR     R2, [R4,R3]\n"     
                "LDR     LR, =0x62773130\n" 
                "ADD     R2, R2, R1\n"      
                "MOV     R3, R0,LSL#4\n"    
                "ADD     R2, R2, #8\n"      
                "MOV     R0, #0\n"          
                "ADD     R12, R11, #0xC\n"  
                "ADD     R1, R11, #8\n"     
                "STR     LR, [R1,R3]\n"     
                "STR     R0, [R12,R3]\n"    
                "STR     R2, [R4,R3]\n"     
                "LDR     R0, [SP]\n"        
                "STR     R0, [R5,R3]\n"     

"loc_FFD3CC70:\n"                            
                                        
                "LDR     R2, =0x64AD8\n"    
                "LDR     R3, =0x64B8C\n"    
                "LDR     R1, [R2]\n"        
                "LDR     R0, [R3]\n"        
                "ADD     R3, R1, #9\n"      
                "CMP     R3, R0\n"          
                "BLS     loc_FFD3CCAC\n"    
                "LDR     R2, =0x64B88\n"    
                "LDR     R3, [R2]\n"        
                "ADD     R3, R3, R1\n"      
                "RSB     R3, R0, R3\n"      
                "LDR     R0, [SP,#0x10]\n"  
                "ADD     R3, R3, #8\n"      
                "STR     R3, [R0]\n"        
                "B       loc_FFD3CCB8\n"    


"loc_FFD3CCAC:\n"                            
                "ADD     R3, R1, #8\n"      
                "LDR     R1, [SP,#0x10]\n"  
                "STR     R3, [R1]\n"        

"loc_FFD3CCB8:\n"                            
                "LDR     R2, [SP,#0x10]\n"  
                "LDR     R1, =0x64B34\n"    
                "LDR     R3, =0x64B8C\n"    
                "LDR     R12, [R2]\n"       
                "LDR     R2, [R1]\n"        
                "LDR     R0, [R3]\n"        
                "ADD     R3, R12, R2\n"     
                "CMP     R3, R0\n"          
                "BLS     loc_FFD3CD0C\n"    
                "LDR     R2, [SP,#0xC]\n"   
                "RSB     R0, R12, R0\n"     
                "STR     R0, [R2]\n"        
                "LDR     R2, =0x64B88\n"    
                "LDR     R3, [R1]\n"        
                "LDR     R1, [R2]\n"        
                "RSB     R3, R0, R3\n"      
                "LDR     R0, [SP,#8]\n"     
                "STR     R1, [R0]\n"        
                "LDR     R1, [SP,#4]\n"     
                "STR     R3, [R1]\n"        
                "B       loc_FFD3CD28\n"    


"loc_FFD3CD0C:\n"                            
                "LDR     R0, [SP,#0xC]\n"   
                "STR     R2, [R0]\n"        
                "LDR     R1, [SP,#4]\n"     
                "MOV     R3, #0\n"          
                "STR     R3, [R1]\n"        
                "LDR     R2, [SP,#8]\n"     
                "STR     R3, [R2]\n"        

"loc_FFD3CD28:\n"                            
                "LDR     R0, =0x64AD8\n"    
                "LDR     R1, =0x64AD4\n"    
                "LDR     R3, [R0]\n"        
                "LDR     R2, [R1]\n"        
                "CMP     R3, R2\n"          
                "BHI     loc_FFD3CD54\n"    
                "LDR     R0, [SP,#0xC]\n"   
                "LDR     R3, [R0]\n"        
                "ADD     R3, R12, R3\n"     
                "CMP     R2, R3\n"          
                "BCC     loc_FFD3CB18\n"    

"loc_FFD3CD54:\n"                            
                "LDR     R1, [SP,#8]\n"     
                "LDR     R2, [R1]\n"        
                "CMP     R2, #0\n"          
                "BEQ     loc_FFD3CD88\n"    
                "LDR     R3, =0x64AD4\n"    
                "LDR     R1, [R3]\n"        
                "CMP     R2, R1\n"          
                "BHI     loc_FFD3CD88\n"    
                "LDR     R0, [SP,#4]\n"     
                "LDR     R3, [R0]\n"        
                "ADD     R3, R2, R3\n"      
                "CMP     R1, R3\n"          
                "BCC     loc_FFD3CB18\n"    

"loc_FFD3CD88:\n"                            
                                        
                "LDR     R3, =0x64B34\n"    
                "LDR     R0, =0x64B38\n"    
                "LDR     R2, [R3]\n"        
                "LDR     R3, [R0,#4]\n"     
                "ADD     R2, R2, #0x18\n"   
                "MOV     R1, R2\n"          
                "MOV     R2, #0\n"          
                "CMP     R2, R3\n"          
                "BHI     loc_FFD3CDBC\n"    
                "BNE     loc_FFD3CDC4\n"    
                "LDR     R3, [R0]\n"        
                "CMP     R1, R3\n"          
                "BLS     loc_FFD3CDC4\n"    

"loc_FFD3CDBC:\n"                            
                                        
                "MOV     R0, #0x80000005\n" 
                "B       loc_FFD3CF38\n"    


"loc_FFD3CDC4:\n"                            
                                        
                "LDR     R1, =0x64B1C\n"    
                "LDR     R0, =0x64B68\n"    
                "LDR     R3, [R1]\n"        
                "LDR     R2, [R0]\n"        
                "ADD     R3, R3, R2,LSL#4\n" 
                "ADD     R3, R3, R3,LSL#2\n" 
                "LDR     R12, =0x64B38\n"   
                "MOV     R3, R3,LSL#1\n"    
                "ADD     R3, R3, #0xA0\n"   
                "LDR     R2, [R12,#4]\n"    
                "MOV     R0, R3\n"          
                "MOV     R1, #0\n"          
                "CMP     R1, R2\n"          
                "BHI     loc_FFD3CE0C\n"    
                "BNE     loc_FFD3CE30\n"    
                "LDR     R3, [R12]\n"       
                "CMP     R0, R3\n"          
                "BLS     loc_FFD3CE30\n"    

"loc_FFD3CE0C:\n"                            
                "LDR     R4, =0x64B50\n"    
                "LDR     R1, [R4]\n"        
                "CMP     R1, #0\n"          
                "BNE     loc_FFD3CE30\n"    
               	"MOV     R0, #0x3140\n"   //3148 fixup?   
                "ADD     R0, R0, #8\n"      
                "BL      sub_FFD546AC\n"    
                "MOV     R3, #1\n"          
                "STR     R3, [R4]\n"        

"loc_FFD3CE30:\n"                            
                                        
                "LDR     R1, =0x64B1C\n"    
                "LDR     R0, =0x64B68\n"    
                "LDR     R2, [R1]\n"        
                "LDR     R3, [R0]\n"        
                "LDR     R0, =0x64B40\n"    
                "ADD     R2, R2, R3,LSL#4\n" 
                "MVN     R3, #0x9F\n"             // diff b
                "ADD     R2, R2, R2,LSL#2\n" 
                "ADD     R3, R3, #0x40000000\n" 
                "SUB     R3, R3, R2,LSL#1\n" 
                "LDR     R1, [R0,#4]\n"     
                "MOV     R4, R3\n"          
                "MOV     R5, #0\n"          
                "CMP     R1, R5\n"          
                "BHI     loc_FFD3CE7C\n"    
                "BNE     loc_FFD3CEA0\n"    
                "LDR     R3, [R0]\n"        
                "CMP     R3, R4\n"          
                "BLS     loc_FFD3CEA0\n"    

"loc_FFD3CE7C:\n"                            
                "LDR     R4, =0x64B50\n"    
                "LDR     R1, [R4]\n"        
                "CMP     R1, #0\n"          
                "BNE     loc_FFD3CEA0\n"    
                "MOV     R0, #0x3140\n"   //3148 fixup?  
                "ADD     R0, R0, #8\n"      //?+
                "BL      sub_FFD546AC\n"    
                "MOV     R3, #1\n"          
                "STR     R3, [R4]\n"        

"loc_FFD3CEA0:\n"                            
                                        
                "LDR     R3, =0x64B68\n"    
                "LDR     R0, =0x64B04\n"    
                "LDR     R2, [R3]\n"        
                "LDR     R12, =0x64AEC\n"   
                "LDR     R1, [R0]\n"        
                "ADD     R3, R2, R2,LSL#2\n" 
                "ADD     R2, R2, R3,LSL#1\n" 
                "LDR     R0, [R12]\n"       
                "RSB     R1, R2, R1\n"      
                "CMP     R0, R1\n"          
                "BLS     loc_FFD3CEF0\n"    
                "LDR     R4, =0x64B50\n"    
                "LDR     R1, [R4]\n"        
                "CMP     R1, #0\n"          
                "BNE     loc_FFD3CEF0\n"    
                "MOV     R0, #0x3140\n"     
                "ADD     R0, R0, #8\n"      
                "BL      sub_FFD546AC\n"    
                "MOV     R3, #1\n"          
                "STR     R3, [R4]\n"        

"loc_FFD3CEF0:\n"                            
                                        
                "LDR     R3, =0x64B40\n"    
                "LDR     R12, =0x64B34\n"   
                "LDMIA   R3, {R1,R2}\n"     
                "LDR     R0, [R12]\n"       
                "MOV     R4, #0\n"          
                "MOV     R3, #0x18\n"       
                "ADDS    R1, R1, R0\n"      
                "ADC     R2, R2, #0\n"      
                "ADDS    R1, R1, R3\n"      
                "ADC     R2, R2, R4\n"      
                "CMP     R2, #0\n"          
                "BHI     loc_FFD3CF2C\n"    
                "BNE     loc_FFD3CF34\n"    
                "CMP     R1, #0x40000000\n" 
//                "BLS     loc_FFD53D20\n"    
                 "B       loc_FFD3CF34\n"    

"loc_FFD3CF2C:\n"                            
                "MOV     R0, #0x80000007\n" 
                "B       loc_FFD3CF38\n"    


"loc_FFD3CF34:\n"                            
                                        
                "MOV     R0, #0\n"          

"loc_FFD3CF38:\n"                            
                                        
                "ADD     SP, SP, #0x14\n"   
                "LDMFD   SP!, {R4-R11,PC}\n" 
 );
}





void __attribute__((naked,noinline)) sub_FFD3BE40_my(){ // done
 asm volatile(
                "CMP     R2, #1\n"          
                "STMFD   SP!, {R4-R7,LR}\n" 
                "MOV     R7, R0\n"          
                "MOV     R6, R1\n"          
                "MOVEQ   R3, #0x79\n"       
                "STREQ   R3, [R6]\n"        
                "LDMEQFD SP!, {R4-R7,PC}\n" 
                "LDR     R12, =0x64850\n"   
                "LDR     R0, [R12]\n"       
                "LDR     R3, =0x64858\n"    
                "CMP     R0, #0\n"          
                "LDR     R1, [R3]\n"        
                "BEQ     loc_FFD3BE88\n"    
                "LDR     R2, =0x6485C\n"    
                "LDR     R3, [R2]\n"        
                "CMP     R3, #1\n"          
                "BNE     loc_FFD3BE9C\n"    
                "B       loc_FFD3BE8C\n"    


"loc_FFD3BE88:\n"                           
                "LDR     R2, =0x6485C\n"    

"loc_FFD3BE8C:\n"                           
                "MOV     R3, #0\n"          
                "STR     R3, [R2]\n"        
                "STR     R7, [R12]\n"       
                "B       loc_FFD3BF54\n"    


"loc_FFD3BE9C:\n"                           
                "LDR     R2, =0x64854\n"    
                "LDR     R3, [R2]\n"        
                "LDR     R5, =table1\n"        //+ 0xFFD52A9C
                "ADD     R3, R3, R3,LSL#1\n" 
                "MOV     LR, R3,LSL#2\n"    
                "LDR     R2, [R5,LR]\n"     
                "LDR     R4, =table2\n"        //+ 0xFFD52AC0
                "RSB     R12, R2, R0\n"     
                "LDR     R3, [R4,LR]\n"     
                "CMP     R12, #0\n"         
                "RSB     R0, R3, R0\n"      
                "BLE     loc_FFD3BF00\n"    
                "ADD     R3, R5, #4\n"      
                "LDR     R2, [R3,LR]\n"     
                "CMP     R2, R12\n"         
                "ADDGE   R1, R1, #1\n"      
                "BGE     loc_FFD3BEF4\n"    
                "ADD     R3, R5, #8\n"      
                "LDR     R2, [R3,LR]\n"     
                "CMP     R2, R12\n"         
                "ADDGE   R1, R1, #2\n"      
                "ADDLT   R1, R1, #3\n"      

"loc_FFD3BEF4:\n"                           
//             "CMP     R1, #0xE\n"  //-      
//             "MOVGE   R1, #0xE\n"  //-      

                "CMP     R1, #0x1A\n"  //+      
                "MOVGE   R1, #0x1A\n"  //+      

                "B       loc_FFD3BF38\n"    


"loc_FFD3BF00:\n"                           
                "CMP     R0, #0\n"          
                "BGE     loc_FFD3BF38\n"    
                "ADD     R3, R4, #4\n"      
                "LDR     R2, [R3,LR]\n"     
                "CMP     R2, R0\n"          
                "SUBLE   R1, R1, #1\n"      
                "BLE     loc_FFD3BF30\n"    
                "ADD     R3, R4, #8\n"      
                "LDR     R2, [R3,LR]\n"     
                "CMP     R2, R0\n"          
                "SUBLE   R1, R1, #2\n"      
                "SUBGT   R1, R1, #3\n"      

"loc_FFD3BF30:\n"                           
                "CMP     R1, #0\n"          
                "MOVLT   R1, #0\n"          

"loc_FFD3BF38:\n"                           
                                        
                "LDR     R0, =0x64858\n"    
                "LDR     R3, [R0]\n"        
                "CMP     R1, R3\n"          
                "LDRNE   R2, =0x6485C\n"    
                "MOVNE   R3, #1\n"          
                "STRNE   R1, [R0]\n"        
                "STRNE   R3, [R2]\n"        

"loc_FFD3BF54:\n"                           
                "LDR     R3, =0x64858\n"    
                "LDR     R1, =video_mode\n"  //+
                "LDR     R0, [R3]\n"        
                "LDR     R2, =CompressionRateTable\n" //+ 0xFFD52A60
                "LDR     R12, [R1]\n"                       
                "LDR     R12, [R12]\n"    //+
                "LDR     LR, [R2,R0,LSL#2]\n" 
                "LDR     R3, =0x64850\n"    
                "CMP     R12, #1\n"         
                "STR     R7, [R3]\n"        
                "STR     LR, [R6]\n"        
                "LDREQ   R3, =video_quality\n"   //+     
                "LDREQ   R3, [R3]\n"   //+     
                "LDREQ   R3, [R3]\n"   //+     
                "STREQ   R3, [R6]\n"        
                "LDMFD   SP!, {R4-R7,PC}\n" 

 );
}




