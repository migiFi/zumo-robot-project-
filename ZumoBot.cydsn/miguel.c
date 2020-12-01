/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <xin.h>
#include <miguel.h>
#define STOP 5

void make3_1(void)  // motor starts, run, turns and stop function 
{
    motor_start();      
    motor_forward(0,0);
    vTaskDelay(1500);
    
    motor_forward(167,2000);
    motor_turn(26,0,2010);
    
    motor_forward(129,2000);  
    motor_turn(26,0,2010);
    
    motor_forward(135,2000);  
    motor_turn(28,0,2000);
    motor_turn(122,100,2000);
    motor_turn(15,0,350);
    
    motor_forward(50,1600);
    
    motor_forward(0,0);  
    motor_stop();             

}   

void make3_2(void)
{

    Ultra_Start();                          // Ultra Sonic Start function
    motor_start();      
    motor_forward(0,0);
    vTaskDelay(1500);
    
    motor_forward(167,2000);
    motor_turn(26,0,2010);
    
    
    int d = Ultra_GetDistance();
    printf("distance = %d\r\n", d);
    vTaskDelay(200);
}

void make3_3(void) 
{
    printf("Robot starts!");
    Ultra_Start();                          // Ultra Sonic Start function
    motor_start();      
    motor_forward(0,0);
    
    
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    printf("Light off");
    BatteryLed_Write(0);
    vTaskDelay(1000);
    
    
    
    while (SW1_Read()==1){
        
        int d = Ultra_GetDistance();
        if (d < 10){
            motor_backward(100,800);
            int angle = rand()%180 +90 ;
            tank_turn(angle);
        }

        motor_forward(200,50);
    }
    motor_stop();
}
    

void make4_1(void)  // this function makes zumoBot count 5 lines from the start point and then stops
{
    printf("\n Count to five Mr. Zumo\n");
    struct sensors_ dig;
    int count = 0;
    int first = 0;
    
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    
    reflectance_start();
    IR_Start();
    motor_start();
    motor_forward(0,0);
    
    while (SW1_Read()== 1);  //waits for SW1 button to give it the signal 
    BatteryLed_Write(1);
    vTaskDelay(1000);
    BatteryLed_Write(0);
    
    reflectance_digital(&dig);
    motor_forward(100,0);
    
    while(count < STOP){ //STOP is define on the top of this file to 5
        reflectance_digital(&dig);
        if(dig.L3 == 1 && dig.L2 == 1 &&dig.L1 == 1 &&dig.R1 == 1 &&dig.R2 == 1 &&dig.R3 == 1){
            count++;
            if (count == 1) {
                first = 1;
            }
            while((dig.L3 == 1 && dig.L2 == 1 &&dig.L1 == 1 &&dig.R1 == 1 &&dig.R2 == 1 &&dig.R3 == 1) && count < STOP){
                reflectance_digital(&dig);
            }
        }
        if(first == 1) {
            motor_forward(0, 0);
            IR_wait();
            motor_forward(100, 0);
            first = 0;
        }
    }
    motor_forward(0,0);
    motor_stop();
    while(true) { 
        
        vTaskDelay(100);
    }

}
void make4_2(void)
{
    printf("Place Mr.Zumo at the start line\n");
    struct sensors_ dig;
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    
    reflectance_start();
    IR_Start();
    motor_start();
    motor_forward(0,0);
    
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    printf("Here we go");
    BatteryLed_Write(0);
    vTaskDelay(1000);
    
    int count = 0;
    
    
    reflectance_digital(&dig);
    motor_forward(60,0);
    
    while(count < 2) {
        reflectance_digital(&dig);
        if ((dig.L3 == 1)&&(dig.R3 == 1)) {
            count++;
            if (count == 1) {
               
            }
            while (dig.L3== 1 && dig.R3 == 1){
                reflectance_digital(&dig);
                motor_forward(60,10);
            }
        }
        
        if(dig. L2 == 0){
            motor_turn(60,0,10);
        }
        if(dig.R2 == 0){
            motor_turn(0,60,10);
        }
        if((dig.L1 == 1)&&(dig.R1 == 1))
           motor_forward(60,0);
       
    }
  
    motor_forward(0,0);
    motor_stop();
    while(true) {
        vTaskDelay(100);
    }

}

void make4_3(void) {
    
      printf("Place Mr.Zumo at the start line\n");
    struct sensors_ dig;
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    
    reflectance_start();
    IR_Start();
    motor_start();
    motor_forward(0,0);
    
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    printf("Here we go");
    BatteryLed_Write(0);
    vTaskDelay(1000);
    
    int count = 0;
    int turns = 0; 
    
    reflectance_digital(&dig);
    motor_forward(60,0);
    
    while(count < 5) {
        reflectance_digital(&dig);
            while ((dig.L3 == 1 && dig.L2 == 1 &&dig.L1 == 1 &&dig.R1 == 1 &&dig.R2 == 1 &&dig.R3 == 1) && count == 2){
                printf("\n Turning left\n");
                reflectance_digital(&dig);
               
                
            }
                if(dig.L2 == 0 && dig.R2 == 1){
                motor_turn(60,0,10);
                }
                if(dig.R2 == 0 && dig.L2 == 1){
                motor_turn(0,60,10);
                }
                if(dig.L3 == 0 && dig.R3 == 1){
                motor_turn(60,0,10);
                }
                if(dig.R3 == 0 && dig.L3 == 1){
                motor_turn(0,60,10);
                }
                if((dig.L1 == 1)&&(dig.R1 == 1))
                motor_forward(60,0);
    
                

        }
    
    motor_forward(0,0);
    motor_stop();
    while(true) {
        vTaskDelay(100);
    }
}





