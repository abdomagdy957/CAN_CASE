# CAN_Case
  <div align="center">
  <a href="">
    <img src="https://github.com/ahmedatef1496/NTI_GP_CAN_CASE/blob/main/pic/header.jpg" alt="Logo" width="800" height="400">
  </a>
  </div>
  

### Team Members
- Abdelrahman Magdy - [![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=flat&logo=github&logoColor=white)](https://github.com/abdomagdy957) [![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=flat&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/abdelrahman-magdy-4a01bb199/)
- Ahmed Atef-[![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=flat&logo=github&logoColor=white)]() [![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=flat&logo=linkedin&logoColor=white)]()
- Hazem Emad-         [![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=flat&logo=github&logoColor=white)](https://github.com/HardcoreBudget) [![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=flat&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/hazim-emad-46589a207/)
- Ahmed Mohammed-     [![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=flat&logo=github&logoColor=white)](https://github.com/AhmedSheikh0) [![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=flat&logo=linkedin&logoColor=white)]()
- Ahmed Magdy-        [![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=flat&logo=github&logoColor=white)](http://Github.com/AhmedMagdy279) [![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=flat&logo=linkedin&logoColor=white)](http://Linkedin.com/in/ahmed-magdy-dawam)
- Abdelaziz Tarek-    [![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=flat&logo=github&logoColor=white)]() [![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=flat&logo=linkedin&logoColor=white)]()

  
### CAN Case

- In the first part of the project, we introduce the Unity Testing APP. This powerful tool not only provides a user-friendly interface for testing but also seamlessly reads and stores JSON files. The APP communicates with the CAN case via UART, paving the way for efficient and intuitive testing.
- Now, let's explore the brain of our system - the CAN case. It receives frames from the APP via UART, performs the necessary conversions, and communicates with the CAR ECU. This two-way communication allows for real-time testing and feedback.
The CAR ECU, the muscles of our system, is divided into three key components. The ARM hub serves as the central hub, orchestrating communication between the two AVR nodes. AVR node 1 controls LEDs, Motors, and Seatbelts, while AVR node 2 handles LM35 and LDR Sensors. The result? A comprehensive and responsive automotive control system.  


### PARTS
| PART | APP              | MC           | Description                                                                                                                         | HEX File        |  
|------|------------------|--------------|-------------------------------------------------------------------------------------------------------------------------------------|-----------------|
| 1    | [CAN Case]()     | STMF103C8T6  | DO..................................................................................................................................| [hex]()         |
| 2    | [ARM Node]()     | STMF103C8T6  | DO..................................................................................................................................| [hex]()         |
| 3    | [AVR Node 1]()   | ATMEGA32     | DO..................................................................................................................................| [hex]()         |
| 4    | [AVR Node 2]()   | ATMEGA32     | DO..................................................................................................................................| [hex]()         |

---
## Documentation
- PDF -> []()


## Videos
- Project Showcase -> (https://www.youtube.com/watch?v=qwrNJoF-X28)
 
## System Layout
![system_layout](https://github.com/ahmedatef1496/NTI_GP_CAN_CASE/blob/main/pic/design.jpg)



