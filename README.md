#RFID_Reader
================

<img src = "http://i.imgur.com/Cym3HOT.jpg" alt = "Just another day at the workroom." height="480" width="800">

ID Card scanning system intended for system login.

#Current Project Goals
================
* Understand PySerial and communication between Arduino and Python.
  * Storing data in the Arduino's SRAM was too impractical. Because of this, we shouldl ldedicate the RFID scanner device on the Arduino as simply a scanning device and have the code (running via Python) do all the hard work on the computer, where memory is not a problem.
* Create an MVP demonstrating...
  * Being able to scan cards with LED feedback.
  * Scanned cards get compared into an ID Database on the computer, and returns a flag for the LED to give feedback (e.g. Card is not in the database, so the LED should blink red).
* Learn Windows administrative tasks.
  * e.g. winlogin32. This is a long-term goal.
* What creative applications can we use with card scanning systems and items like this?

Thanks for reading!
