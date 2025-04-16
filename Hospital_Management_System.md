# Hospital Management System

This project is a console-based **Hospital Management System** written in C++. It allows administrative control and record management of hospital data such as doctor information, patient admissions, cafeteria management, and pharmacy services.

## Features

- **User Authentication**
  - Login and registration system using `users.txt`
  - Password-masked input

- **Doctor Management**
  - Add, modify, display, or delete doctor records
  - Supports search by specialization
  - Validation for string inputs
  - Stored in `doctor8.txt`

- **Patient Management**
  - Add, modify, display, or delete patient records
  - Assign doctors based on specialization
  - Generate patient reports and billing
  - Stored in `patient11.txt`

- **Cafeteria Management**
  - Add, modify, display, query, or delete dish items
  - Generate itemized customer bills
  - Stored in `cafeteria.txt`

- **Pharmacy Management**
  - Add, modify, display, query, or delete medicine records
  - Generate pharmacy bills
  - Stored in `pharmacy.txt`

## File Storage

The system uses text and binary files for persistent storage:
- `users.txt` – stores user credentials
- `doctor8.txt` – doctor records
- `patient11.txt` – patient records
- `cafeteria.txt` – cafeteria dish inventory
- `pharmacy.txt` – pharmacy inventory
- `bill.txt` – temporary bill record for cafeteria and pharmacy
- `temp*.txt` – used for deletion and temporary modifications

## Compilation

To compile the code on Windows:
```bash
g++ Hospital_Management_System.cpp -o hospital -lws2_32
```

## How to Run

```bash
./hospital
```

Follow the CLI prompts to login or register and choose from the hospital modules (Doctors, Patients, Cafeteria, Pharmacy).

## Limitations

- Platform-specific: Windows console-based (uses `conio.h`, `windows.h`)
- Not suitable for large-scale hospital data without further optimization
- Basic file-based storage (no database)
- Some deprecated functions like `gets()` are used

## License

This project is for educational purposes only.
