# IOT-AIR-QUALITY-MONITOR

*COMPANY*: CODTECH IT SOLUTIONS

*NAME*: N.SUHEAL AHAMED

*INTERN ID*: CT04DM815

*DOMAIN*: Internet Of Things

*DURATION*: 4 WEEKS

*MENTOR*: NEELA SANTOSH

🌫️ Task 4: IoT Air Quality Monitor 

This project presents an IoT-based Air Quality Monitoring System that detects gas levels in the environment using an MQ2 gas sensor (simulated with a potentiometer) and alerts the user via Blynk IoT platform, LED indicators, buzzer, and a real-time LCD display.

📲 Overview:

The system continuously reads gas levels through the analog input (POT as MQ2) on ESP32.

⚠️ If gas levels rise above a set threshold:

  🔸 A red LED turns ON
  
  🔸 A buzzer is activated
  
  🔸 LCD displays “Gas Detected!”
  
  🔸 A notification is sent via Blynk app (Virtual Pin V2)

✅ If air quality returns to safe levels:

  🔹 The green LED turns ON
  
  🔹 Buzzer and red LED are turned OFF
  
  🔹 LCD displays “Air Clean”
  
  🔹 Updated reading is sent to Blynk

🧰 Components Used:

📦 ESP32 Dev Board

💨 MQ2 Gas Sensor (simulated with potentiometer)

💡 Red & Green LEDs

🔔 Buzzer

📟 16x2 I2C LCD Display

📱 Blynk IoT App

🧪 Wokwi Simulator (for testing and demonstration)

⚙️ Features:

✅ Real-time gas level monitoring

✅ Local visual and audio alerts

✅ Live LCD display of status

✅ Remote data visualization using Blynk app

✅ Periodic updates every 1 second

✅ Works seamlessly in simulation (Wokwi)

🔌 Connections:

🔧 Component  → 	⚡ ESP32 Pin
MQ2 Sensor (POT)	→ GPIO34
Red LED	→ GPIO2
Green LED	→ GPIO4
Buzzer	→ GPIO15
I2C LCD	SDA/SCL via default ESP32 pins

📱 Blynk Configuration:

🏷️ Template Name: IOT Air Quality Monitor Task 4

🆔 Template ID: TMPL3aOJXbl1f

🔐 Auth Token: ejAeVoYji8w04tDLaveR7GEFzkJhebvW

📊 Virtual Pin: V2 (linked to Super Chart or Gauge)

🔘 Widget Suggestion: Super Chart with 1s update interval

🖼️ Output Preview:

📷 Wokwi simulation screenshot with sensor, buzzer, LEDs, and LCD

📱 Blynk app screenshot with gas level graph

💡 LED ON/OFF and buzzer status photos

🖥️ Serial Monitor logs showing gas levels and status
