# Haya Trip (Haya_Trip_2A28)

Authors: Yosri Hamrouni and project team
Course / Project: Software Engineering / Integrated Systems (Academic Project)
Supervisor: [Supervisor name]
Academic Year: 2025–2026

## Abstract

Haya Trip is a desktop travel management application implemented in C++ using the Qt framework. The system integrates client and employee management, reservation and trip planning, transport scheduling, notification and email services, QR-code generation, basic analytics, and hardware integration (Arduino). This repository contains module-level code and an integrated application used as the final demonstrator.

## Objectives

- Design and implement a modular desktop application to support travel agency operations.
- Demonstrate integration between GUI components, persistent storage (Qt SQL), networking, and embedded device communication.
- Provide reporting and analytics for business decisions and user workflows.
- Produce a maintainable codebase suitable for demonstration and further academic extension.

## System Overview

Haya Trip is organized as an integrated Qt application with the following high-level components:

- GUI: Qt Widgets based user interface (mainwindow, dialogs, forms).
- Persistence: Qt SQL based access for client, reservation, and voyage data (database configuration is project-dependent).
- Networking & Mail: SMTP modules for email notifications and reporting.
- QR Codes: Generation and rendering modules for travel documents and tickets.
- Hardware: Arduino sketch and serial-port integration for peripheral interaction (e.g., sensors or card readers).
- Utilities: Excel export, statistics, and plotting (Qt Charts / QCustomPlot used in the project).

The integrated application is assembled under the Haya_Trip_2A28-INTEGRATION folder and built with QtCreator/qmake.

## Repository layout (selected)

Haya_Trip_2A28/

- Haya_Trip_2A28-INTEGRATION/
  - Haya_Trip_2A28-integration3 avec transport/
    - INTEGRATION APP HAYATRIP.pro  — Qt project file used to build the integrated application.
    - Sources (.cpp) and headers (.h) — core modules: mainwindow, reservation, voyage, transport, client, employe, qrcode, smtp, smtp2, arduino, connection, etc.
    - UI forms (.ui) — Qt Designer form files for dialogs and main window.
    - Third-party binaries/libraries — e.g., libeay32.dll, ssleay32.dll (for SSL/crypto support on Windows).
- GestionDesReservations/ — reservation module(s) (team-specific folders).
- sara gestion_voyage/ — voyage module(s).
- yosri gestion_clients/ — client management module(s).
- sketch_nov20a.ino — Arduino sketch used for hardware integration.

## Technologies and Tools

- Language: C++ (GNU++14 / C++11 features used where indicated in project file)
- Framework: Qt (Qt Widgets, Qt SQL, Qt Network, Qt Serial Port, Qt Charts)
- Build tools: Qt Creator / qmake
- Optional libraries: QCustomPlot (bundled), OpenSSL DLLs (bundled for Windows builds)
- Hardware: Arduino (sketch included)

## Build and Run (Academic / Reproducibility instructions)

Prerequisites
- Qt 5.x or Qt 6.x (ensure compatibility with the project; project is configured for qmake and Qt Creator)
- A C++ compiler compatible with the selected Qt kit (e.g., g++, MSVC)
- (Optional) Arduino IDE for uploading the included sketch to a device
- (Optional) OpenSSL runtime on Windows; project includes libeay32.dll and ssleay32.dll shipped in the integration folder

Steps
1. Clone the repository and checkout the INTEGRATION branch:  
   git clone https://github.com/yosriHamrouni/Haya_Trip_2A28.git
   cd Haya_Trip_2A28
   git checkout INTEGRATION

2. Open Qt Creator and load the project file:  
   Haya_Trip_2A28-INTEGRATION/Haya_Trip_2A28-integration3 avec transport/INTEGRATION APP HAYATRIP.pro

3. Configure a Qt kit (Qt version + compiler) and ensure Qt modules required by the .pro file are installed (Sql, Network, SerialPort, Charts, Widgets).

4. Build the project and run from Qt Creator. On Windows, ensure the DLLs (libeay32.dll, ssleay32.dll) are accessible in PATH or placed beside the executable.

5. (Optional) To test Arduino integration, upload sketch_nov20a.ino to the Arduino device and configure serial port settings used by the application.

## Data and Configuration

- Database configuration is not embedded in the project code; the application expects a database to be configured via the connection module. Inspect connection.cpp / connection.h for the connection parameters and adapt for your local DB (SQLite, MySQL, or other Qt-supported driver).

- Email (SMTP) configuration: update credentials and server settings in smtp/smtp2 modules before using mail features.

## Evaluation and Testing

This academic project includes manual and ad-hoc functional tests performed via the GUI. Recommended steps for reproducible evaluation:

- Create a local development database (SQLite) and populate with sample data.
- Run the application and exercise use cases: create clients, create reservations, generate QR codes, export data to Excel, and trigger notification workflows.
- Review logs and ui behaviour; unit tests are not included in this version.

## Limitations and Known Issues

- No explicit automated test-suite is present in the repository.
- Some third-party sources and large generated files (qcustomplot sources, Windows DLLs) are included in the tree — licensing and redistribution should be verified before release.
- Database schema and credentials are project-specific and must be configured before first run.

## Suggested Future Work (for academic extension)

- Add automated unit and integration tests (Qt Test framework).
- Replace bundled DLLs with system-managed dependencies or document required runtime versions.
- Add a configuration file and secure storage for credentials.
- Implement role-based access control and audit logging.
- Containerize back-end components or provide a portable packaging strategy.

## How to cite

If you use this project in academic work, cite as: Haya Trip (Haya_Trip_2A28), Y. Hamrouni et al., 2026. Repository: https://github.com/yosriHamrouni/Haya_Trip_2A28

## License

No license is specified in the repository. Add a LICENSE file (e.g., MIT, Apache-2.0) to clarify usage and distribution rights.

## Acknowledgements

This project is a collaborative student project. Thanks to the project supervisors and team members for contributions.