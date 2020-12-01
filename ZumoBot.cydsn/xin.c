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

#include "xin.h"
#define STOP 5

//Week3_assignment_1
void w3_a1(void){
    printf("Please put the robort to the start line");
    motor_start();      
    motor_forward(0,0);
    
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    printf("Moving starts");
    BatteryLed_Write(0);
    vTaskDelay(1000);
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


void w3_a2(void){
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
            motor_forward(0,0);
            motor_backward(100,800);
            motor_turn(250,0,350);
        }
        
        motor_forward(200,50);
    }
    motor_stop();
}


void w3_a3(void){
    printf("Robot starts!");
    Ultra_Start();                          
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




void w4_a1(void){
    printf("\n Count to five Mr. Zumo\n");
    struct sensors_ dig;
    int count = 0;
    int first = 0;
    
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    
    reflectance_start();
    IR_Start();
    motor_start();
    motor_forward(0,0);
    
    while (SW1_Read()== 1);
    BatteryLed_Write(1);
    vTaskDelay(1000);
    BatteryLed_Write(0);
    
    reflectance_digital(&dig);
    motor_forward(100,0);
    
    while(count < STOP){
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

void w4_a2(void){
    printf("Please put the robort at the start line\n");
    struct sensors_ dig;
    reflectance_set_threshold(15000, 15000, 18000, 18000, 15000, 15000);
    
    reflectance_start();
    IR_Start();
    motor_start();
    motor_forward(0,0);
    
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    printf("Move starts");
    BatteryLed_Write(0);
    vTaskDelay(1000);
    
    int count = 0;
    int touching = 0;
    
    while(count < 2){
        reflectance_digital(&dig);
        
        if (touching == 0 && dig.L3 == 1 && dig.L2 == 1 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 1 && dig.R3 == 1) {
            count++;
            touching = 1;
            if (count == 1) {
                printf("\nWaiting for IR signal.\n");
                motor_forward(0, 0);
                IR_wait();
                printf("\nIR signal received.\n");
            }
        }
        if (touching == 1 && dig.L3 == 0 && dig.L2 == 0 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 0 && dig.R3 == 0) {
            touching = 0;
        }
        while (dig.L2 == 1 && dig.R2 == 0){
            tank_turn(1);
            reflectance_digital(&dig);
        }
        
        while (dig.R2 == 1 && dig.L2 == 0){
            tank_turn(-1);
            reflectance_digital(&dig);
        }
        
        
        
        
        motor_forward(255, 0);
        
    }
    motor_stop();
    printf("\nHappy Birthday!");

}

void w4_a3(void){
    printf("Please put the robort at the start line\n");
    struct sensors_ dig;
    reflectance_set_threshold(15000, 15000, 18000, 18000, 15000, 15000);
    
    reflectance_start();
    IR_Start();
    motor_start();
    motor_forward(0,0);
    
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    printf("Move starts");
    BatteryLed_Write(0);
    vTaskDelay(1000);
    
    int count = 0;
    int touching =0;
    
     while(count < 5){
        reflectance_digital(&dig);
        
        if (touching == 0 && dig.L3 == 1 && dig.L2 == 1 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 1 && dig.R3 == 1) {
            count++;
            touching = 1;
            if (count == 1) {
                printf("\nWaiting for IR signal.\n");
                motor_forward(0, 0);
                IR_wait();
                printf("\nIR signal received.\n");
            }
        }
        if (touching == 1 && dig.L3 == 0 && dig.L2 == 0 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 0 && dig.R3 == 0) {
            touching = 0;
        }
        if (count == 2){
            while(! (dig.L2 == 0 && dig.L1 == 1 && dig.R1 ==1 && dig.R2 == 0)){
            motor_turn(5,160,0);
            reflectance_digital(&dig);
            }
            motor_forward(255, 0);
        }
        if(count == 3 || count == 4){
            while(!(dig.L2 == 0 && dig.L1 == 1 && dig.R1 ==1 && dig.R2 == 0)){
            motor_turn(160,5,0);
            reflectance_digital(&dig);
            }
            motor_forward(255, 0);
        }
        motor_forward(255, 0);
    }      
    motor_stop();
    printf("\nHappy Birthday!");
}

void w5_a1(void){
    send_mqtt("Zumo101/turn","Time recording");
    
    TickType_t time0;
    TickType_t time1;
    
    Ultra_Start();                         
    motor_start();      
    motor_forward(0,0);
    
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    printf("Light off");
    BatteryLed_Write(0);
    vTaskDelay(1000);
    time0 = xTaskGetTickCount();
    
    while(true){
        while (SW1_Read() == 1);
        time1 = xTaskGetTickCount();
        int t = time1 - time0;
        print_mqtt("Zumo101/button", "since last button push: %d s.\n", t/1000);
        while (SW1_Read() ==0);
        time0 = time1;
    }
}
    


void w5_a2(void){
    send_mqtt("Zumo101/turn","Turning");
    Ultra_Start();                         
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
            int t = rand()%2;
            if(t == 1){
            tank_turn(90);
            print_mqtt("Zumo101/turn","Turn left 90 degrees");
            }
            else if (t == 0){
            tank_turn(-90);
            print_mqtt("Zumo101/turn","Turn right 90 degrees");
            }
        }

        motor_forward(200,50);
    }
    motor_stop();
}
void w5_a3(void){
    send_mqtt("Zumo101/lap","Count time");
    struct sensors_ dig;
    reflectance_set_threshold(15000, 15000, 18000, 18000, 15000, 15000);
    
    reflectance_start();
    IR_Start();
    
    motor_start();
    motor_forward(0,0);
    
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    print_mqtt("Zumo101/lap","Move starts");
    BatteryLed_Write(0);
    vTaskDelay(1000);
    
    int count = 0;
    int touching = 0;
    TickType_t time;
    
    while(count < 2){
        reflectance_digital(&dig);
        
        if (touching == 0 && dig.L3 == 1 && dig.L2 == 1 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 1 && dig.R3 == 1) {
            count++;
            touching = 1;
            if (count == 1) {
                motor_forward(0, 0);
                print_mqtt("Zumo101/lap","Waiting to IR signal");
                IR_wait();
                time = xTaskGetTickCount();
                print_mqtt("Zumo101/lap","Time counting starts");
            }
        }
        if (touching == 1 && dig.L3 == 0 && dig.L2 == 0 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 0 && dig.R3 == 0) {
            touching = 0;
        }
        
        motor_forward(100, 0);
        
    }
    motor_stop();
    print_mqtt("Zumo101/lap","Time costs %d s", time/1000);

}

void tank_turn(int16 angle){
     uint8 left_wheel = 0,right_wheel =0;
    if (angle < 0 ){
        left_wheel = 0;
        right_wheel = 1;
    }
    else if(angle >= 0){
        left_wheel =1;
        right_wheel = 0;
    }
    uint16 correct_angle = (angle<0)? angle* -1:angle;
    uint32 delay =correct_angle % 360 *524 / 360;
    
    SetMotors(left_wheel,right_wheel, 200, 200, delay);
}














    

/* [] END OF FILE */
