# ESP8266 Temperature and Humidity
Monitoring Room's Temperature and Humidity with NodeMCU

## The NodeMCU
NodeMCU microboard controler that comes with WiFi included, and it costs just $2 dolars.

Here is a good explanation of what NodeMCU is: https://developer.ibm.com/tutorials/iot-nodemcu-open-why-use/

# Summary
#### 1) Install IDE to communicate with the NodeMCU board.
#### 2) Connect the sensor to the NodeMCU board
#### 3) Write the program code
#### 4) Upload the program to the NodeMCU board
    
    
## 1) Installing IDE

1) Download and install the Arduino IDE: https://www.arduino.cc/en/Main/Software

2) Fill in "Additional Boards Manager URLs" field:
  http://arduino.esp8266.com/stable/package_esp8266com_index.json
  
  ![image](https://user-images.githubusercontent.com/2295468/60393529-3b0ac900-9aed-11e9-9e62-f122619368c1.png)

3) Now, install the package that will enable the IDE to interact with the NodeMCU board:

  ![image](https://user-images.githubusercontent.com/2295468/60393545-74433900-9aed-11e9-92ca-85a10812253a.png)

4) Select the board you will be working with:

  ![image](https://user-images.githubusercontent.com/2295468/60393553-a6ed3180-9aed-11e9-91b3-cef0aacd336c.png)

5) Select the "USB port" you currently have the NodeMCU connected:

  ![image](https://user-images.githubusercontent.com/2295468/60393562-cc7a3b00-9aed-11e9-9167-84c176cc474c.png)

Reference: https://www.instructables.com/id/Quick-Start-to-Nodemcu-ESP8266-on-Arduino-IDE/ 


## 2) Connect the sensors to the NodeMCU board

These two pictures below show how to wire the pin's board to the temperature sensor and to the display.
The sensor DHT11 is connected to the PIN D3, and the display's PINs (CLK and DIO) are connected to the PINs D7 and D6, respectively.

![image](https://user-images.githubusercontent.com/2295468/60403030-16a30100-9b6e-11e9-876f-1c22b747e579.png)

![IMG_3142_1](https://user-images.githubusercontent.com/2295468/60403086-3edf2f80-9b6f-11e9-874f-2e2648971b07.jpg)

## 3) Writing the program code

The program code is in the file "Temperature_and_Humidity.ino".

However, you need to install three libraries in the Arduino IDE, in order to write less code to interact with the sensor and the display.

Open the menu "Tools" >> "Manage Libraries...":

   ![image](https://user-images.githubusercontent.com/2295468/60403344-4ce27f80-9b72-11e9-90a3-017c6471f1e7.png)

1) Install the "DHT11 sensor library":

    ![image](https://user-images.githubusercontent.com/2295468/60403308-d6458200-9b71-11e9-9d3c-606ef05d4f70.png)

2) Install the "Adafruit Unified Sensor":

    ![image](https://user-images.githubusercontent.com/2295468/60403322-fffea900-9b71-11e9-8d9f-f1a8400a90f2.png)

3) Install the "TM1637" display's library:

    ![image](https://user-images.githubusercontent.com/2295468/60403488-80260e00-9b74-11e9-98fc-7a3af2e56cb2.png)


## 4) Upload the code to the board
