


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

int mag_sensor_n = 100;
int mag_sensor_count = 0;
float mag_sensor_sum = 0;
int mag_sensor_heading_average;

void update_mag() {
  mag_sensor_sum += read_mag_heading();
  mag_sensor_count++;

  if (mag_sensor_count > mag_sensor_n) {
    mag_sensor_heading_average = (int)(mag_sensor_sum / mag_sensor_count);
    log(mag_sensor_heading_average);
    mag_sensor_sum = 0;
    mag_sensor_count = 0;
    // Report new average.
  }
}

int get_mag_heading() {
  return mag_sensor_heading_average;
}


