# accel_Magnitude

Library that compute the vector magnitude of data comming from an accelerometer, for speed reasone all the computation are done on 32 bit data
the library return the magnitude value if correct or -1 if an error or an overflow occured

Data are passed to the function trought the accelData_t structure that contain the x,y,z value
