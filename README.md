# Smart_Factory_Monitoring_System
This IoT based Smart Factory Monitoring Project is developed as part of the Emertxe Online Internship.

Problem Statement: 
1) No Real time Visibility: Factory floors lack real time data in temperature and vibrations of the machine, the humidity in the surroundings, making early hazard detection impossible.
2) Lack of Remote Equipment Control: Operators must be physically present to check and toggle the equipment which makes it inefficient and risky during emergencies.
3) Delayed Incident Response: Without automated alerting, threshold breaches go unnoticed until physical damage or safety incidents occur.
4) Reactive Maintenance: Without data trends, factories rely on breakdown-based maintainence, increasing downtime and costs.

Proposed Solution for the system:
This project is a multi-node IoT system using Arduino Uno boards and sensor system comprosing of various sensors like temperature, humidity, PIR, light sensor to monitor the production line (machine) conditions as well as the warehouse (item) conditions.
Each node collects data and sends it through Ethernet via MQTT protocol. The data is then processed on Thingsboard Platform, where it is displayed on a web dashboard.
The system allows live monitoring of data, alerts for threshold breaches and remote control of devices. Overall, the system provides real time monitoring, alerts and basic automation.

Limitations:
1) Arduino Uno has less processing power and limited memory.
2) Not suitable for very large scale systems.
3) Lacks advanced security features for factory data.
4) Due to the use of Ethernet, it is less flexible than wireless systems.
