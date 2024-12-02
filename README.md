# RFID-Based Lab Entry and Exit Management System

This project is a **real-time student attendance system** designed to track entry and exit events in a lab using RFID cards. The system logs attendance, displays real-time updates on a web app, and stores all data in a Firebase Realtime Database. It is an automated solution for managing lab access with enhanced visibility and security.

---

## **Features**
- **Real-Time Updates**: Tracks students entering or leaving the lab and updates their status (`in`/`out`) in real-time.
- **Web App Dashboard**: Displays the current status of all students (e.g., who is in the lab).
- **Attendance Logs**: Stores detailed logs of all entries and exits, including timestamps.
- **RFID Card Authentication**: Uses RFID cards for student identification, ensuring secure and automated logging.
- **Scalable Design**: Easily extendable for multiple labs or large-scale usage.

---

## **System Components**
1. **ESP8266 Microcontroller**: Reads RFID cards and communicates with the Firebase Realtime Database over Wi-Fi.
2. **Firebase Realtime Database**: Stores student data, statuses, and attendance logs.
3. **Web App**: Displays real-time student status using Firebase SDK.
4. **RFID Reader**: Captures the UID of RFID cards for authentication.

---

## **How It Works**

### **RFID Card Scan**
- A student scans their RFID card at the lab entrance.  
- The RFID UID is sent to the ESP8266 microcontroller.

### **Firebase Query**
- The ESP8266 checks the student's current status in Firebase (`in` or `out`).

### **Status Update**
- If the student is marked as `in`, their stat# RFID-Based Lab Entry and Exit Management System

## **Setup Instructions**

### **Hardware Setup**
1. Connect the RFID reader to the ESP8266 as per the wiring diagram.  
2. Power the ESP8266 and ensure the RFID reader is functional.

### **Firebase Configuration**
1. Create a Firebase Realtime Database and note the project URL and secret key.  
2. Update the `FIREBASE_HOST` and `FIREBASE_AUTH` variables in the ESP8266 code.

### **ESP8266 Code**
1. Flash the Arduino code onto the ESP8266.  
2. Connect the ESP8266 to your Wi-Fi network.

### **Web App**
1. Use the provided `index.html` file to display the student status dashboard.  
2. Update the Firebase configuration in the JavaScript file.

---

## **Future Enhancements**
- **Database Migration**: Transition from Firebase to MongoDB Atlas or another database for cost-effective and scalable storage.  
- **Mobile App Integration**: Develop an Android/iOS app for real-time updates and attendance tracking.  
- **Offline Functionality**: Implement data caching to allow offline use, with auto-sync upon reconnection.  
- **Visual Analytics**: Add dashboards for analyzing attendance trends and patterns over time.  
- **Enhanced Security**: Introduce role-based access and encryption for sensitive data.

---

## **Limitations**
- **Firebase Free Tier**: Current Firebase implementation is limited to a one-month free trial. Future plans include transitioning to MongoDB Atlas or an alternative database.  
- **Internet Dependency**: The system relies on stable Wi-Fi for real-time updates, which may limit offline capabilities.

---

## **Acknowledgments**
This project was developed to automate and simplify the process of managing lab attendance using RFID technology. Special thanks to the open-source community for tools and resources.

---

## **License**
This project is licensed under the MIT License.
s is updated to `out` (exit).  
- If marked as `out`, their status is updated to `in` (entry).  
- The attendance log is updated with the action and timestamp.

