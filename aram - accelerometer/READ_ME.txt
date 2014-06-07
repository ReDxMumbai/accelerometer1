
Accelerometer MMA7361(with gyro) - to detect the orientation of the body(left, right and center)
**download the library AcceleroMMA7361.h and put it in Arduino/library folder

1.get acceleration in x y z directions - 
		this can be obtained by calculating voltagee from raw data
		or
		we can download and use a library called AcceleroMMA7361.h which has a function to get the 	accelerations

2.Obtain pitch and roll to get the orientations in the required axes. This is done using the following formula:
	float pitch = atan(x/sqrt(pow(y,2) + pow(z,2)));
	float roll = atan(y/sqrt(pow(x,2) + pow(z,2)));

3.Decide on a threshold for the pitch/roll values for the left, right, centre positions of the body.(orien.ino)

4.Obtain the graph for the same in Processing.(upload graph1.ino for pitch, graph2.ino for roll onto the arduino and run the file SimpleSerialArduinoscope.pde on Processing)
**Before doing this put the folders control5p and arduinoscope inside Proseccing/libraries.


