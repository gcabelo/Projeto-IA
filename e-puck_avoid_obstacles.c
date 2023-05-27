/*

 * File:          Controlador.c

 * Date:

 * Description:

 * Author:

 * Modifications:

 */



/*

 * You may need to add include files like <webots/distance_sensor.h> or

 * <webots/motor.h>, etc.

 */

#include <stdio.h>

#include <webots/robot.h>

#include <webots/motor.h>

#include <webots/distance_sensor.h>

#include <webots/led.h>

#include <webots/supervisor.h>



/*

 * You may want to add macros here.

 */

#define TIME_STEP 256

#define QtddSensoresProx 8

#define QtddLeds 10



/*

 * This is the main program.

 * The arguments of the main function can be specified by the

 * "controllerArgs" field of the Robot node

 */

int main(int argc, char **argv) {

  
  
  int i=0;

  char texto[256];

  double LeituraSensorProx[QtddSensoresProx];

  double AceleradorDireito=1.0, AceleradorEsquerdo=1.0;
  
  bool ViraRobo = false;
  bool PrimeiroMov = true;
  
  double InicialCaixaX = 0;
  double InicialCaixaY = 0;
  double InicialCaixaZ = 0;
  /* necessary to initialize webots stuff */

  double FinalCaixaX = 0;
  double FinalCaixaY = 0;
  double FinalCaixaZ = 0;
  
  int contador = 0;
  
  
  for(i=0;i<257;i++) texto[i]='0';

  

  wb_robot_init();

  
 

  // Get the translation field
  //WbFieldRef translationField = wb_supervisor_node_get_field(woodenBox, "translation");
  
  // Get the translation values
   
    
    printf("Default controller of the e-puck robot started...\n");
    
   
    
    WbDeviceTag MotorEsquerdo, MotorDireito;

  

  MotorEsquerdo = wb_robot_get_device("left wheel motor");

  MotorDireito = wb_robot_get_device("right wheel motor");

  

  wb_motor_set_position(MotorEsquerdo, INFINITY);

  wb_motor_set_position(MotorDireito, INFINITY);

  

  wb_motor_set_velocity(MotorEsquerdo,0);

  wb_motor_set_velocity(MotorDireito,0);

  

  

   //configurei Sensores de Proximidade

   WbDeviceTag SensorProx[QtddSensoresProx];

   

   SensorProx[0] = wb_robot_get_device("ps0");

   SensorProx[1] = wb_robot_get_device("ps1");

   SensorProx[2] = wb_robot_get_device("ps2");

   SensorProx[3] = wb_robot_get_device("ps3");

   SensorProx[4] = wb_robot_get_device("ps4");

   SensorProx[5] = wb_robot_get_device("ps5");

   SensorProx[6] = wb_robot_get_device("ps6");

   SensorProx[7] = wb_robot_get_device("ps7");

   

   wb_distance_sensor_enable(SensorProx[0],TIME_STEP);

   wb_distance_sensor_enable(SensorProx[1],TIME_STEP);

   wb_distance_sensor_enable(SensorProx[2],TIME_STEP);

   wb_distance_sensor_enable(SensorProx[3],TIME_STEP);

   wb_distance_sensor_enable(SensorProx[4],TIME_STEP);

   wb_distance_sensor_enable(SensorProx[5],TIME_STEP);

   wb_distance_sensor_enable(SensorProx[6],TIME_STEP);

   wb_distance_sensor_enable(SensorProx[7],TIME_STEP);



    //config leds

    WbDeviceTag Leds[QtddLeds];

    Leds[0] = wb_robot_get_device("led0");
    wb_led_set(Leds[0],-1);
    
    Leds[1] = wb_robot_get_device("led1");
    wb_led_set(Leds[1], -1);
    
    Leds[2] = wb_robot_get_device("led2");
    wb_led_set(Leds[2], -1);
    
    Leds[3] = wb_robot_get_device("led3");
    wb_led_set(Leds[3], -1);
    
    Leds[4] = wb_robot_get_device("led4");
    wb_led_set(Leds[4],-1);
    
    Leds[5] = wb_robot_get_device("led5");
    wb_led_set(Leds[5], -1);
    
    Leds[6] = wb_robot_get_device("led6");
    wb_led_set(Leds[6], -1);
    
    Leds[7] = wb_robot_get_device("led7");
    wb_led_set(Leds[7], -1);
    
    Leds[8] = wb_robot_get_device("led8");
    wb_led_set(Leds[8], -1);
    
    Leds[9] = wb_robot_get_device("led9");
    wb_led_set(Leds[9], -1);
    

     WbNodeRef woodenBox = wb_supervisor_node_get_from_def("WOODEN_BOX");
    // Print the position values
    //printf("Wooden box position: (%f, %f, %f)\n", translation[0], translation[1], translation[2]);
    //configurei MOTORES
     //const double *translation = wb_supervisor_node_get_position(woodenBox);
      
     //InicialCaixaX = translation[0];
     //InicialCaixaY = translation[1];
     //InicialCaixaZ = translation[2];
     
      //printf("Variavel nova \n: (%f, %f, %f)\n", InicialCaixaX, InicialCaixaY, InicialCaixaZ);

  /*

   * You should declare here WbDeviceTag variables for storing

   * robot devices like this:

   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");

   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");

   */



  /* main loop

   * Perform simulation steps of TIME_STEP milliseconds

   * and leave the loop when the simulation is over

   */

  while (wb_robot_step(TIME_STEP) != -1) {

    for(i=0;i<256;i++) texto[i]=0;

    //memcpy(texto,0,10);

    /*

     * Read the sensors :

     * Enter here functions to read sensor data, like:

     *  double val = wb_distance_sensor_get_value(my_sensor);

     */

  // Get the translation field
  //WbFieldRef translationField = wb_supervisor_node_get_field(woodenBox, "translation");
  
  // Get the translation values

    /* Process sensor data here */

    for(i=0;i<QtddSensoresProx;i++){

       LeituraSensorProx[i]= wb_distance_sensor_get_value(SensorProx[i]);
       if(LeituraSensorProx[0] >= 300 || LeituraSensorProx[1] >= 300 || LeituraSensorProx[6] >= 300 || LeituraSensorProx[7] >= 300){
           ViraRobo = true;
       }
       //sprintf(texto,"%s|%d: %5.2f  ",texto,i,LeituraSensorProx[i]);

    }

    //printf("%s\n",texto);

    wb_led_set(Leds[0], wb_led_get(Leds[0])*-1);

    /*

     * Enter here functions to send actuator commands, like:

     * wb_motor_set_position(my_actuator, 10.0);

     */

    
    
    if(ViraRobo == true){

      AceleradorDireito = -0.5;
      //printf("entrei 1 \n");
      AceleradorEsquerdo = 1;
      ViraRobo = false;
      }
   
      
    else {

      AceleradorDireito = 1;
      //printf("sai 2 \n");
      AceleradorEsquerdo = 0.80;}

   if(PrimeiroMov == true){
     const double *translation = wb_supervisor_node_get_position(woodenBox);

     contador = contador + 1;
     
     printf("PRIMEIRAs INTERAÇões \n");
     InicialCaixaX = translation[0];
     InicialCaixaY = translation[1];
     InicialCaixaZ = translation[2];
     
     if(contador == 5){
       PrimeiroMov = false;
     }
      printf("INICIAL \n: (%f, %f, %f)\n", InicialCaixaX, InicialCaixaY, InicialCaixaZ);
   }

    

    wb_motor_set_velocity(MotorEsquerdo,6.28*AceleradorEsquerdo);

    wb_motor_set_velocity(MotorDireito, 6.28*AceleradorDireito);

   const double *translation2 = wb_supervisor_node_get_position(woodenBox);
    
    FinalCaixaX = translation2[0];
    FinalCaixaY = translation2[1];
    FinalCaixaZ = translation2[2];
    // Print the position values
    printf("Variavel nova \n: (%f, %f, %f)\n", FinalCaixaX, FinalCaixaY, FinalCaixaZ);
    
    if(InicialCaixaX != FinalCaixaX || InicialCaixaY != FinalCaixaY){
      printf("MOVI \n");
      
      wb_motor_set_velocity(MotorEsquerdo, 0);
      wb_motor_set_velocity(MotorDireito, 0);
      
      for (int i = 0; i < QtddLeds; i++) {
        wb_led_set(Leds[i], 1); // Define o estado do LED como ligado
    }
    
      break;
    }

  };



  /* Enter your cleanup code here */



  /* This is necessary to cleanup webots resources */

  wb_robot_cleanup();



  return 0;

}