This simplified branch significantly reduces the amount of clutter in the top Arduino module, as well as removes some of the redundancy with the on-off switch logic. I have yet to test it with the linear actuators, so I'm leaving it as a branch (hopefully temporarily). The remainder of the readme is identical:
--------------------------------------------

The Sensor-Enhanced Mechanical Fruit Cutter is an assistive device designed to enable individuals with limited fine motor skills to easily cut fruits. The primary goals for designing and manufacturing this product were to ensure ease of use and maintenance while adhering to a budget of $200 and maintaining a size comparable to a shoebox.
  
The product consists of three key components: a blade and pressing plate for slicing fruit, linear actuators to control the pressing plate's movement, and a front-mounted distance sensor that ensures the user is a safe distance away. The device operates using two linear actuators, connected with two motor drivers and powered by a 12 V supply. The SHARP IR distance sensor, powered by 5V from the Arduino Uno,  is mounted in the front of the device and returns an output voltage. The Arduino Uno is programmed to process this output and convert it to centimeters. Additionally, there is also a sliding button in the shaft where the sliced fruit is deposited which will detect when a container is present in the shaft. Finally, the user will activate the cutting by pressing a large button on the device.
  
To alert the user of the functioning of the device, the Arduino Uno board is also connected to three LED’s. The green LED indicates the device is safe to approach and insert fruit. The orange LED indicates the linear actuators are in motion. If 1 or more safety conditions are not being met (such as the user being too close or the drawer not present in the shaft), the actuators will pause their motion and the red LED activates. When the safety conditions are met the actuators will resume their motion and the LED will turn orange. 
  
To use the device, the user will first turn the device on by turning the switch to ON. The actuators, which are stored fully retracted, will immediately extend to their maximum height. Once they reach their peak, the LED will turn from orange to green and the user can place a fruit on top of the blades. When ready, the user will press the activation button and step away from the device. Once the distance sensor verifies the user is an appropriate distance from the device, the actuators will begin retracting, pushing the fruit through the blades. The actuators will immediately extend again once they are fully retracted, returning to their maximum height so the process can be repeated as needed. When the user is done with the device, they can simply flick the switch OFF. The actuators (while still checking for the safety conditions) will immediately attempt to retract to reach the smallest size possible for storage. Once they are fully retracted, the LED indicators will turn off, and the device is ready for storage.

Below is the circuit diagram for the device. Not shown are the 6 output pins to the motor drivers, 4 digital outputs to drive extension and retraction, and 2 analog outputs to control the speed.
<img width="1144" alt="circuitDiagram" src="https://github.com/user-attachments/assets/406c97e3-43d7-4707-924c-3769e92cbaa9">

Click [here](https://youtu.be/YY8EpCqgCA0) to watch a brief demonstration of the program working with a single linear actuator.
