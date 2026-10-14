# Haya Trip 2A28

A travel management desktop application developed with C++ and Qt for managing clients, reservations, trips, transport, employee workflows, notifications, and reporting.

## Overview

This project is an integrated travel management system designed to support the core operations of a travel agency, including:

- Client management
- Reservation management
- Voyage and transport management
- Employee management
- Email and notification features
- Statistics and reporting
- QR code generation
- Arduino/serial device integration

The main application is located in:

- `Haya_Trip_2A28-INTEGRATION/Haya_Trip_2A28-integration3 avec transport/`

The repository also contains separate module folders for different team responsibilities, including:

- `GestionDesReservations/`
- `sara gestion_voyage/`
- `yosri gestion_clients/`

## Main project structure

```text
Haya_Trip_2A28/
├── GestionDesReservations/
├── Haya_Trip_2A28-INTEGRATION/
│   └── Haya_Trip_2A28-integration3 avec transport/
│       ├── INTEGRATION APP HAYATRIP.pro
│       ├── main.cpp
│       ├── mainwindow.cpp
│       ├── mainwindow.h
│       ├── connection.cpp
│       ├── reservation.cpp
│       ├── voyage.cpp
│       ├── transport.cpp
│       ├── client.cpp
│       ├── employe.cpp
│       ├── smtp.cpp
│       ├── qrcode.cpp
│       ├── arduino.cpp
│       └── ...
├── sara gestion_voyage/
├── yosri gestion_clients/
├── sketch_nov20a.ino
├── README.md
└── .gitignore
```

## Technologies used

- C++
- Qt / Qt Creator
- Qt SQL
- Qt Widgets
- Qt Charts
- Qt Network
- Qt Serial Port
- QR code components
- Arduino serial communication

## Features

- User authentication and login flow
- Reservation creation and management
- Trip and transport management
- Client and employee records
- Mail notification support
- Statistics dashboards and reporting
- QR code generation for travel-related data
- Data export and Excel support
- Integration with hardware/embedded components

## Getting started

1. Open Qt Creator.
2. Open the project file:
   - `Haya_Trip_2A28-INTEGRATION/Haya_Trip_2A28-integration3 avec transport/INTEGRATION APP HAYATRIP.pro`
3. Configure the Qt kit and build environment.
4. Build and run the application.

## Notes

- The project uses Qt SQL and connection classes for database access.
- Some modules include networking, mail, and serial communication support.
- The Arduino sketch (`sketch_nov20a.ino`) suggests hardware interaction or sensor/embedded device integration.

## Contributors

This repository appears to be a collaborative project that combines multiple modules developed by different team members, with a final integrated application assembled under the `Haya_Trip_2A28-INTEGRATION` folder.

## License

This project does not currently specify a license in the repository. If needed, add one before publishing or sharing externally.
