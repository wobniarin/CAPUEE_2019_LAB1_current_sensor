// Program to measure consumed current by a load with the SCT013-30A current sensor

/***** Include constants for the Pin where the Sensor is connected to *******/ 
/*****____________WRITE HERE THE CODE_________________*******/
// const int SensorPin = , RefPin = ;
// const int Rshunt = ;

// Definition of auxiliary variables 
unsigned long time_ant = 0, difTime = 0, act_time = 0;
const int sampleDuration = 20;
int count_integral = 0;
double rawSquaredSum = 0;
double Iant = 0;

/***** Include constants for the grid frecuency and current transformer properties *******/
/*****____________WRITE HERE THE CODE_________________*******/
// Definition of constant grid frequency (50 Hz)
// double freq = ;
// Definition of transformer reduction relationship
// double n_trafo = ;

// Definition of measured current variable 
double Irms = 0;

/***** Write the void setup code command. Inside it, Set the data rate in bits per second for serial data transmission, 
so as to communicate with the computer. Use of the availables reates *******/
/*****____________WRITE HERE THE CODE_________________*******/
void setup() {
  // Initialize the serial port communications with a baudrate of 115200 bit/s

}

// Loop code
void loop()
{
  act_time = micros();
  difTime = act_time - time_ant;

  int RawValue = 0;

  if (difTime >= 1000) {
    time_ant = act_time + (difTime - 1000);

    /***** Read the ADC input from the sensor and the voltage reference point *******/
    /*****____________WRITE HERE THE CODE_________________*******/
    // ADC_sensor = 
    // ADC_ref = 

    
    /*****  Translate the ADC input measured to voltage values *******/
    /*****____________WRITE HERE THE CODE_________________*******/
    // V_sens = 
    // V_ref = 

    // Calculate the instantaneous current using the voltage diference and the burder resistor value
    double Iinst =  n_trafo * (V_sens - V_ref) / Rshunt;
      
    // Print the instantaneous current
    Serial.println(Iinst);
    
    // Calculate the integral
    rawSquaredSum += Iinst * Iinst * 0.001;
    
    // Count 20 ms
    count_integral++;
  }

  // Each 20 ms, calculte the RMS
  if (count_integral >= sampleDuration) 
  {
    // Calculate the RMS
    Irms = sqrt(freq * rawSquaredSum);
    // Counter and integral reset
    count_integral = 0;
    rawSquaredSum = 0;

    // Low-pass filter
    double Ifilt = 0.95 * Iant + 0.05 * Irms;
    Iant = Ifilt;
    
    // Print the RMS
    // Serial.print("Ifilt = ");
    // Serial.print(Ifilt);
  }
}
