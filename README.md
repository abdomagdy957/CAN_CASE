## NTI - National Telecommunication Institute


  <div align="center">
  <a href="">
    <img src="https://github.com/ahmedatef1496/NTI_GP_CAN_CASE/blob/main/pic/header.jpg" alt="Logo" width="800" height="400">
  </a>
  </div>
  

### Team Members
- Abdelrahman Magdy -  [![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=flat&logo=github&logoColor=white)](https://github.com/abdomagdy957) [![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=flat&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/abdelrahman-magdy-4a01bb199/)
- Ahmed Atef -         [![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=flat&logo=github&logoColor=white)](https://github.com/ahmedatef1496) [![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=flat&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/ahmedatef14596/)
- Hazem Emad -         [![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=flat&logo=github&logoColor=white)](https://github.com/HardcoreBudget) [![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=flat&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/hazim-emad-46589a207/)
- Ahmed Mohammed -     [![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=flat&logo=github&logoColor=white)](https://github.com/AhmedSheikh0) [![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=flat&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/ahmed-mohammed-930337146/)
- Ahmed Magdy -        [![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=flat&logo=github&logoColor=white)](http://Github.com/AhmedMagdy279) [![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=flat&logo=linkedin&logoColor=white)](http://Linkedin.com/in/ahmed-magdy-dawam)
- Abdelaziz Tarek -    [![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=flat&logo=github&logoColor=white)]() [![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=flat&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/abdelaziz-tarek?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=android_app)

  
### CAN Case

- In the first part of the project, we introduce the Unity Testing APP. This powerful tool not only provides a user-friendly interface for testing but also seamlessly reads and stores JSON files. The APP communicates with the CAN case via UART, paving the way for efficient and intuitive testing.
- Now, let's explore the brain of our system - the CAN case. It receives frames from the APP via UART, performs the necessary conversions, and communicates with the CAR ECU. This two-way communication allows for real-time testing and feedback.
The CAR ECU, the muscles of our system, is divided into three key components. The ARM hub serves as the central hub, orchestrating communication between the two AVR nodes. AVR node 1 controls LEDs, Motors, and Seatbelts, while AVR node 2 handles LM35 and LDR Sensors. The result? A comprehensive and responsive automotive control system.  


### PARTS
| PART | APP               | MC           | Description                                                                                                                         | HEX File        |  
|------|-------------------|--------------|-------------------------------------------------------------------------------------------------------------------------------------|-----------------|
| 1    | [Unity App](https://github.com/ahmedatef1496/NTI_GP_CAN_CASE/tree/main/project/final_code/Unity%20Application)     | Unity3D SW           |- It communicates with the CAN case using the serial port (UART)<br>- It reads the CAN frame configurations (Identifier, DLC, and Data) from a user-written JSON file<br>- It receives the actual results and displays them on the GUI<br>- It compares the actual result with the expected one for each test and saves a status report as a JSON file| [hex]()         |
| 2    | [CAN Case](https://github.com/ahmedatef1496/NTI_GP_CAN_CASE/tree/main/project/final_code/CAN_CASE/M_CAN)      | STM32F103C8T6  |- An ARM-based converter that reads the CAN configuration over a UART,<br>- It utilizes FreeRTOS to start sending and receiving CAN frames on the command, <br>- It also sends back the final output of the test to be evaluated from the laptop.| [hex]()         |
| 3    | [ARM Node](https://github.com/ahmedatef1496/NTI_GP_CAN_CASE/tree/main/project/final_code/ARM_HUB/CAR_MCU)      | STM32F103C8T6  |- A simulation of a car's Node<br>- It receives the CAN frames sent by the CAN case <br>- It decides which AVR node should receive that message next<br>- It sends data to the AVR nodes using UART and receives the result using repeated SPI transfers to accommodate for any possible collisions| [hex]()         |
| 4    | [AVR Node 1](https://github.com/ahmedatef1496/NTI_GP_CAN_CASE/tree/main/project/final_code/CAR_ECU)    | ATMEGA32     |- It controls the motor (using PWM), seatbelt (using a HW switch), and light systems of the car<br>- It receives data from the ARM HUB over UART and decides which system should be targeted| [hex]()         |
| 5    | [AVR Node 2](https://github.com/ahmedatef1496/NTI_GP_CAN_CASE/tree/main/project/final_code/CAR_ECU)    | ATMEGA32     |- It contains the sensor readings of both the LM35 and LDR<br>- It receives data from the ARM HUB over UART and decides which system should be targeted| [hex]()         |

---
## Documentation
- PDF -> [uploading]()


## Videos
- Project video -> [Youtube](https://www.youtube.com/watch?v=qwrNJoF-X28)
 
## System Layout
![system_layout](https://github.com/ahmedatef1496/NTI_GP_CAN_CASE/blob/main/pic/design.jpg)