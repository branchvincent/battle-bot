


Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

void display_magsensor() {
  sensor_t sensor;
  mag.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" uT");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" uT");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" uT");  
  Serial.println("------------------------------------");
  Serial.println("");

}

void init_magsensor() {
  if(!mag.begin())
  {
    /* There was a problem detecting the HMC5883 ... check your connections */
    Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
    while(1);
  }
  
}

float read_mag_heading() {
  sensors_event_t event;
  mag.getEvent(&event);

//  log("X: ", event.magnetic.x); 
//  log("Y: ", event.magnetic.y);
//  log("Z: ", event.magnetic.z);

  // Hold the module so that Z is pointing 'up' and you can measure the heading with x&y
  // Calculate heading when the magnetometer is level, then correct for signs of axis.
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  
  // Once you have your heading, you must then add your 'Declination Angle', which is the 'Error' of the magnetic field in your location.
  // Find yours here: http://www.magnetic-declination.com/
  // Mine is: -13* 2' W, which is ~13 Degrees, or (which we need) 0.22 radians
  // If you cannot find your Declination, comment out these two lines, your compass will be slightly off.
  float declinationAngle = 0.22;
  heading += declinationAngle;
  
  // Correct for when signs are reversed.
  if(heading < 0)
    heading += 2*PI;
    
  // Check for wrap due to addition of declination.
  if(heading > 2*PI)
    heading -= 2*PI;
   
  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180/M_PI; 
  
  //Serial.print("Heading (degrees): "); Serial.println(headingDegrees); //log("");

  return headingDegrees;
  
}
//
//int mag_sensor_n = 100;
//int mag_sensor_count = 0;
//float mag_sensor_sum = 0;
//int mag_sensor_heading_average;
//
//void update_mag() {
//  mag_sensor_sum += read_mag_heading();
//  mag_sensor_count++;
//
//  if (mag_sensor_count > mag_sensor_n) {
//    mag_sensor_heading_average = (int)(mag_sensor_sum / mag_sensor_count);
//    log(mag_sensor_heading_average);
//    mag_sensor_sum = 0;
//    mag_sensor_count = 0;
//    // Report new average.
//  }
//}

const int mag_length = 50;
float mag_sensor_values[mag_length];
int mag_kickout_index = 0;
int mag_sensor_heading_average;

void update_mag_running() {

  mag_sensor_values[mag_kickout_index] = read_mag_heading();
  mag_kickout_index++;
  mag_kickout_index%=mag_length;
  int sum = 0;
  for (int i = 0; i < mag_length; i++) {
    sum+=mag_sensor_values[i];
  }
  mag_sensor_heading_average = sum / mag_length;
  //log(mag_sensor_values[mag_kickout_index]);
  //log(mag_sensor_heading_average);
}

int get_mag_heading() {
  return mag_sensor_heading_average;
}


int linear_interpolate(int source_a, int source_b, int out_a, int out_b, int source) {
  return (out_b - out_a) / (source_b - source_a) * (source - source_a) + out_a;
}

int mag_raw[]  = { -20, 82, 130, 153, 171, 186, 198, 211, 219, 230, 239, 247, 255, 264, 274, 283, 295, 313, 340, 442 };
int mag_true[] = { -20,  0,  20,  40,  60,  80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360 };

int mag_raw_to_true(int r) {

  int index = 0;

  while(r <= mag_raw[index]) {
    index++;
  }

  int raw_a = mag_raw[index-1];
  int raw_b = mag_raw[index];

  int true_a = mag_true[index-1];
  int true_b = mag_true[index];

  //return (true_b - true_a) / (raw_b - raw_a) * (r - raw_a) + true_a;
  return linear_interpolate(raw_a, raw_b, true_a, true_b, r);
  
}

int mag_true_to_raw(int t) {
  
}


