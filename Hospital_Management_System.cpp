#include <iostream>
#include <string>//
#include <stdbool.h>//
#include <stdio.h>//
#include <stdlib.h>//
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

//LOGIN PROCESS
//Login function

void login() 
{
	string UserName,Password;
	string UseEnter,PassEnter;
	bool On_Off = true;
	bool Off = true;
	int countt = 0;
	int left = 3;

	char c;

	cout << "\n**** Login to your Account **** \n";
	while(On_Off) {
		//********************************************
		fstream user;
		user.open("users.txt", ios::in);
		if(countt < 3 && Off && user.is_open()) {
			if(countt > 0) {
				cout << "\nPassword or UserName are not correct!!" << endl;
				left--;
				cout << "You have *" << left << "* attempts left \n" << endl;
			}
			cout << "Enter UserName: ";
			getline(cin,UseEnter);
			cout << "Enter Password: ";
			while ((c = getch()) != '\r') { // '\r' is the Enter key
				PassEnter += c;
				cout << "*";
			}
			countt++;
			string read;

			while(getline(user,read)) {
				stringstream convertor(read);
				convertor >> UserName >> Password;
				if(UseEnter == UserName && PassEnter == Password) {
					Off = false;
				}
			}

		} else if(!Off) {
			cout << "\n**** Welcome! ****\n\n";
			user.close();
			On_Off = false;
		} else {
			cout << "\n**** try again later!! **** \n\n";
			user.close();
			On_Off = false;
		}
	}
}
// Registration function
void registry() {
	string newName,checkName,newPass,confirmPass;
	int MiniPass ;
	bool if_ON = true;
	bool oo = true;

	cout << "\n**** Create New Account **** \n";
//UserName Validation
	while(oo) {
		cout << "Enter New UserName: ";
		getline(cin, newName);
		MiniPass = newName.length();
		fstream yusers;
		yusers.open("Users.txt",ios::in);
		if(if_ON && MiniPass >= 1 && yusers.is_open()) {
			string readd;
			while(getline(yusers,readd)) {
				stringstream OnlyUsers(readd);
				OnlyUsers >> checkName;
				if(newName == checkName) {
					cout <<"\n*"<< newName <<"* UserName already exists Try another one\n" << endl;
					if_ON = false;
				}
			}
			yusers.close();
			if(!if_ON) {
				if_ON = true;
			} else {
				oo = false;
			}
		}
	}
//Password Validation
	while(true) {
		cout << "Enter New password: ";
		getline(cin,newPass);
		cout << "Confirm the password: ";
		getline(cin,confirmPass);
		MiniPass = newPass.length();

		if (MiniPass < 5) {
			cout << "\nYour password is weak at least 5 letters\n \n";
		} else if(confirmPass == newPass) {
			fstream users;
			users.open("Users.txt",ios::app);
			if(users.is_open()) {
				users << newName +" "+ newPass << endl;
				users.close();
			}
			cout << "\n===================================\n";
			cout << "\nSuccessfully new account created! \n \n";
			cout << "===================================\n";
			break;
		} else {
			cout << "\nPassword confirmation not correct! \n" << endl;

		}
	}
	login();
}
void checkin() {
	string LoR;
	cout << "\n***** Login or Register *****\n\n";
	cout << "===================================\n";
	cout << "\n***** Please write (login) or (register) *****\n\n";

	while(true) {

		getline(cin,LoR);
		if(LoR == "login") {
			login();
			break;
		} else if(LoR == "register") {
			registry();
			break;
		} else {
			cout << "\n*Please write (login) or (register) correctly*\n" ;
		}
	}
}
//hospital
class doctor {
		int id;
		int code;
		char name[50];
		int age;
		char qualification[10];
		char specilization[10];
		int experience;
		char state[50];
		char city[50];
	public:
		int get_ID();
		void get_info();
		void get_name();
		void get_age();
		void get_code();
		void get_qualification();
		void get_specilization();
		void get_experience();
		void get_state();
		void get_city();
		int verify_specilization(int opt,int flag);
		void display_all(doctor d);
		void display_info(doctor d);
		void modify_info(doctor d, int number,int size);

};
void add_doctor_data();
int  verify_alphabet(char* arr,int size);
void modify_doctor_data();
void delete_contents();
void delete_contents1();
void display();
void delete_doctor_data();
int display_doctor_data();
int doctor_number();
long int get_size_of_the_file();

int verify_alphabet(char* arr, int size) {
	int i = 0;
	for (i = 0; i < size; i++) {
		if (isdigit(arr[i])) {
			return(1);
		}
	}
}
int doctor_number() {
	long int size;
	size = get_size_of_the_file();
	doctor d;
	size = size / (sizeof(d));
	return(size);
}

int doctor::verify_specilization(int opt,int flag) {
	if (opt == code) {
		flag++;
		cout <<"\n"<<"ID------------->\t"<< get_ID();
		return(flag);
	} else {
		return(flag);
	}
}
int doctor::get_ID() {
	return(id);
}
void doctor::get_info() {
	cout << "\nEnter Doctor's ID               :";
	cin >> id;
NAME:
	cout << "\nEnter Doctor's Name             :";
	cin.ignore();
	cin.getline(name, 50);
	int flag;
	int size=strlen(name);
	flag=verify_alphabet(name,size);
	if (flag == 1) {
		cout << "\n\nName should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto NAME;
	}
	cout << "\nEnter Doctor's Age              :";
	cin >> age;
QUALIFICATION:
	cout << "\nEnter Doctor's Qualification    :";
	cin.ignore();
	cin.getline(qualification, 50);
	size = strlen(qualification);
	flag = verify_alphabet(qualification, size);
	if (flag == 1) {
		cout << "\nQualification should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto QUALIFICATION;
	}
SPECILIZATION:
	cout << "\nEnter Doctor's Specialization   :";
	cin.getline(specilization, 50);
	size = strlen(specilization);
	flag = verify_alphabet(specilization, size);
	if (flag == 1) {
		cout << "\nSpecilization should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto SPECILIZATION;
	}
	cout << "********************************************************************************";
	cout << "\n\t\t\tCodes For Various Specilizations\n";
	cout << "********************************************************************************";
	cout << "1.General Medicine\n2.Cardiology\n3.Neurology\n4.ENT\n";
	cout << "********************************************************************************";
	cout << "\nSelect The Code Basing On The Specilization :";
	cin >> code;
	cout << "********************************************************************************";
	cout << "\nEnter Doctor's Experience       :";
	cin >> experience;
STATE:
	cout << "\nEnter Doctor's State            :";
	cin.ignore();
	cin.getline(state, 30);
	size = strlen(state);
	flag = verify_alphabet(state, size);
	if (flag == 1) {
		cout << "\nState should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto STATE;
	}
CITY:
	cout << "\nEnter Doctor's City             :";
	cin.getline(city, 30);
	size = strlen(city);
	flag = verify_alphabet(city, size);
	if (flag == 1) {
		cout << "\nCity should consist of only alphabets!!! or min of three alphabets\n";
		cout << "\n";
		system("PAUSE");
		goto CITY;
	}
}

void doctor::get_name() {
NAME:
	cin.ignore();
	cout << "\nEnter New Name :";
	cin >> name;
	int flag;
	int size = strlen(name);
	flag = verify_alphabet(name, size);
	if (flag == 1) {
		cout << "\nName should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto NAME;
	}

}
void doctor::get_age() {
	cin.ignore();
	cout << "\nEnter New Age :";
	cin >> age;
}
void doctor::get_qualification() {
QUALIFICATION:
	cin.ignore();
	cout << "\nEnter New Qualification :";
	cin >> specilization;
	int flag;
	int size = strlen(qualification);
	flag = verify_alphabet(qualification, size);
	if (flag == 1) {
		cout << "\nQualification should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto QUALIFICATION;
	}
}
void doctor::get_specilization() {
SPECILIZATION:
	cin.ignore();
	cout << "\nEnter New Specilization :";
	cin >> specilization;
	int flag;
	int size = strlen(specilization);
	flag = verify_alphabet(specilization, size);
	if (flag == 1) {
		cout << "\nSpecilization should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto SPECILIZATION;
	}
	cout << "********************************************************************************";
	cout << "\nCodes For Various Specilizations\n";
	cout << "********************************************************************************";
	cout << "1.General Medicine\n2.Cardiology\n3.Neurology\n4.ENT\n";
	cout << "********************************************************************************";
	cout << "\nSelect The Code Basing On The Specilization ";
	cin >> code;
}
void doctor::get_experience() {
	cin.ignore();
	cout << "\nEnter New Experience :";
	cin >> experience;
}
void doctor::get_state() {
STATE:
	cin.ignore();
	cout << "\nEnter New State :";
	cin >> state;
	int flag;
	int size = strlen(state);
	flag = verify_alphabet(state, size);
	if (flag == 1) {
		cout << "\nState should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto STATE;
	}
}
void doctor::get_city() {
CITY:
	cin.ignore();
	cout << "\nEnter New City :";
	cin >> city;
	int flag;
	int size = strlen(city);
	flag = verify_alphabet(city, size);
	if (flag == 1) {
		cout << "\nCity should consist of only alphabets(or)min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto CITY;
	}
}
void doctor::display_info(doctor d) {
	cout << "\nDoctor's ID                :\t "<< d.id;
	cout << "\nDoctor's Name              :\t" << d.name;
	cout << "\nDoctor's Age               :\t" << d.age;
	cout << "\nDoctor's Qualification     :\t" << d.qualification;
	cout << "\nDoctor's Specilization     :\t" << d.specilization;
	cout << "\nDoctor's Experience        :\t" << d.experience;
	cout << "\nDoctor's State             :\t" << d.state;
	cout << "\nDoctor's City              :\t" << d.city;
}
void doctor::display_all(doctor d) {
	cout <<"\t"<< d.id << "\t\t" << d.specilization << "\t\t\t" << d.qualification << "\t\t\t" << d.age<<"\n";
}
void doctor::modify_info(doctor d, int number,int size) {
	if (number == 1) {
		fstream myfile6("doctor8.txt",ios::in|ios::out);
		doctor d1 = d;
		d1.get_name();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		cout << "\n";
		cout << "\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << " \n";
		system("PAUSE");
	} else if (number == 2) {
		fstream myfile6("doctor8",ios::in|ios::out);
		doctor d1 = d;
		d1.get_age();
		myfile6.seekp(size,ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	} else if (number == 3) {
		fstream myfile6("doctor8.txt", ios::in | ios::out);
		doctor d1 = d;
		d1.get_qualification();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}

	else if (number == 4) {
		fstream myfile6("doctor8.txt", ios::in | ios::out);
		doctor d1 = d;
		d1.get_specilization();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	} else if (number == 5) {
		fstream myfile6("doctor8.txt", ios::in | ios::out);
		doctor d1 = d;
		d1.get_experience();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	} else if (number == 6) {
		fstream myfile6("doctor8.txt", ios::in | ios::out);
		doctor d1 = d;
		d1.get_state();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	} else if (number == 7) {
		fstream myfile6("doctor8.txt", ios::in | ios::out);
		doctor d1 = d;
		d1.get_city();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}

}
void add_doctor_data() {
	doctor d;
	ofstream myfile("doctor8.txt",ios::in|ios::app);
	d.get_info();
	myfile.write((char*)&d, sizeof(d));
	myfile.close();
}
void display() {
	long int size = 0;
	size = get_size_of_the_file();
	int i = 0;
	doctor d;
	size = size / (sizeof(d));
	if (size == 0) {
		cout << "\nDatabase Empty!!!";
		cout << "\n";
	} else {
		cout << "\n" ;
		cout << "********************************************************************************";
		cout << "\n\t\t\tDetails Of All The Doctors In The Hospital\n";
		cout << "********************************************************************************";
		cout <<"\t"<< "ID" << "\t\t" << "Specilization" << "\t\t" << "Qualification" << "\t\t" << "Age" << "\n";
		ifstream myfile("doctor8.txt");
		myfile.seekg(0);
		for (i = 0; i < size; i++) {
			cout << "\n\n";
			myfile.read((char*)&d, sizeof(d));
			d.display_all(d);
		}
		cout << "********************************************************************************";
	}
}
int display_doctor_data() {
	long int size = 0;
	size = get_size_of_the_file();
	int i = 0, id, id1, count = 0;
	doctor d1;
	size = size / (sizeof(d1));
	if (size == 0) {
		cout << "\nDatabase Empty!!!";
		cout << "\n";
	} else {

		cout << "\nEnter The ID Of the Doctor You require :";
		cin >> id;
		ifstream myfile1("doctor8.txt");
		for (i = 0; i < size; i++) {
			myfile1.clear();
			myfile1.read((char*)&d1, sizeof(d1));
			id1 = d1.get_ID();
			if (id == id1) {
				count = 1;
				d1.display_info(d1);
				cout << "\n";
				cout << "\n";
				system("PAUSE");
				cout << "\n";
				break;
			}

		}

		myfile1.close();
		return(count);
	}
}

void modify_doctor_data() {
	int id1;
	long int size = 0;
	size = get_size_of_the_file();
	int i = 0, count = 0, id;
	doctor d2;
	size = size / (sizeof(d2));
	if (size == 0) {
		cout << "\nDatabase Empty!!!\n";
		cout << "\nNo Record To Modify!!!";
		cout << "\n\n";
		system("PAUSE");
	} else {
		cout << "\nEnter The ID Of The Doctor To Modify Data :";
		cin >> id1;
		ifstream myfile2("doctor8.txt");
		for (i = 0; i < size; i++) {
			myfile2.clear();
			myfile2.read((char*)&d2, sizeof(d2));
			id = d2.get_ID();
			if (id == id1) {
				size = myfile2.tellg();
				size = size - sizeof(d2);
				count = 1;
				d2.display_info(d2);
				cout << "\n\n";
				system("PAUSE");
				cout << "\n";
				cout << "\nField's Which Can Be Modified\n";
				cout << "\n1.Name\n2.Age\n3.Qualification\n";
				cout << "4.Specilization\n5.Experience\n6.State\n";
				cout << "7.City\n";
				int opt2;
				cout << "\nSelect The Field Which You Want To Modify :";
				cin >> opt2;
				switch (opt2) {
					case 1:
						d2.modify_info(d2, opt2, size);
						break;
					case 2:
						d2.modify_info(d2, opt2, size);
						break;
					case 3:
						d2.modify_info(d2, opt2, size);
						break;
					case 4:
						d2.modify_info(d2, opt2, size);
						break;
					case 5:
						d2.modify_info(d2, opt2, size);
						break;
					case 6:
						d2.modify_info(d2, opt2, size);
						break;
					case 7:
						d2.modify_info(d2, opt2, size);
						break;
					default:
						cout << "\nWrong Choice ";
				}
				break;
			}
		}

		myfile2.close();
		if (count == 0) {
			cout << "\nRecord Does'nt Exist!!!";
			cout << "\n";
			system("PAUSE");
		}
	}
}

void delete_contents() {
	ofstream myfile("doctor8.txt");
	myfile.close();
}
void delete_contents1() {
	ofstream myfile("patient11.txt");
	myfile.close();
}

void delete_doctor_data() {
	long int size;
	size = get_size_of_the_file();
	doctor d;
	size = size / (sizeof(d));
	if (size == 0) {
		cout << "\nDatabase Empty!!!";
		cout << "\n\nNo Record To Delete!!!";
		cout << "\n";
	} else {
		ifstream  myfile6("doctor8.txt");
		ofstream myfile7("temp1.txt");
		int id, count = 0, id1, i;
		cout << "\nEnter The ID Of The Doctor Whose Data You Want To Delete :";
		cin >> id;
		for (i = 0; i < size; i++) {
			myfile6.read((char*)&d, sizeof(d));
			id1 = d.get_ID();
			if (id != id1) {
				myfile7.write((char*)&d, sizeof(d));
			} else {
				count = 1;

			}
		}
		myfile6.close();
		myfile7.close();
		ofstream myfile9("doctor8.txt");
		ifstream myfile8("temp1.txt");
		for (i = 0; i < size - 1; i++) {
			myfile8.read((char*)&d, sizeof(d));
			myfile9.write((char*)&d, sizeof(d));
		}
		if (count == 0) {
			cout << "\nNo Data Found ";
			cout << "\n\n";
			system("PAUSE");
		} else {
			cout << "\nData Successfully Deleted\n";
		}
	}
}


long int get_size_of_the_file() {
	long int size=0;
	ifstream ifile("doctor8.txt");
	ifile.seekg(0, ios::end);
	size = ifile.tellg();
	ifile.close();
	return(size);

}

//patient
class patient {
		int id;
		int doc_id;
		char name[50];
		int age;
		char occupation[30];
		char state[10];
		char symptoms[70];
		char disease[50];
		char city[10];
		char consultation_date[30];
		char nationality[20];
		char phone_no[20];
		char street[30];
		char door_no[20];
		char condition[30];
		char date_admitted[20];
		char date_discharged[20];
		char discharge_condition[50];
		int bill;
	public:
		int  get_ID();
		void set_doc_ID();
		void get_info();
		void get_name();
		void get_age();
		void get_occupation();
		void get_state();
		void get_city();
		void get_phone_no();
		void get_nationality();
		void get_street();
		void get_door_no();
		void get_condition();
		void report1(patient);
		void get_discharge_condition();
		void get_date_admitted();
		void get_date_discharged();
		void get_bill();
		void bill1(patient);
		void assign_patient_to_doctor(patient p, int size);
		void display_all(patient p);
		void display_info(patient p);
		void modify_info(patient p, int number, int size);
};

void add_patient_data();
void modify_patient_data();
void delete_patient_data();
void assign_patient();
void display1();
void report();
void bill();
int display_patient_data();
int number();
long int get_size_of_the_file1();
void patient::bill1(patient p) {
	system("CLS");
	int total;
	cout << "********************************************************************************";
	cout << "\n\n\t\t\t\tPatient Fee Charge\n\n ";
	cout << "*******************************************************************************";
	cout << "\nHospital Room Charges                      :\t  1000";
	cout << "\nHospital Care Charges                      :\t  500";
	cout << "\nHospital Maintaince Charges                :\t  500";
	cout << "\nPatient Individual  Charges                :\t " << p.bill;
	total = 1000 + 500 + 500 + p.bill;
	cout << "\nTotal Fee Charge                           :\t"  << total<<"\n";
	cout << "********************************************************************************";
}
void patient::report1(patient p) {
	system("CLS");
	cout << "********************************************************************************";
	cout << "\n\t\t\tPatient Report\n";
	cout << "********************************************************************************";
	cout << "\nPatient Name                                                :" << p.name;
	cout << "\nPatient Age                                                 :" << p.age;
	cout << "\nPatient Symptoms                                            :" << p.symptoms;
	cout << "\nPatient Disease                                             :" << p.disease;
	cout << "\nPatient Admission Date                                      :" << p.date_admitted;
	cout << "\nPatient Discharge Date                                      :" << p.date_discharged;
	cout << "\nPatient Condition At The Time Of Discharge                  :" << p.discharge_condition;
	cout << "\npatient Consulation Date                                    :" << p.consultation_date;
	cout << "\n";
	cout << "********************************************************************************";
}
int patient::get_ID() {
	return(id);
}
void patient::set_doc_ID() {
	cout << "\nPlease Select Your Choice :";
	cin >> doc_id;
}
void patient::get_info() {
	cout << "\nEnter Patient's ID                                          :";
	cin >> id;
NAME:
	cout << "\nEnter Patient's Name                                        :";
	cin.ignore();
	cin.getline(name, 50);
	int flag;
	int size = strlen(name);
	flag = verify_alphabet(name, size);
	if (flag == 1) {
		cout << "\n\nName should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto NAME;
	}
	cout << "\nEnter Patient's Age                                         :";
	cin >> age;
OCCUPATION:
	cout << "\nEnter Patient's Occupation                                  :";
	cin.ignore();
	cin.getline(occupation, 30);

	size = strlen(occupation);
	flag = verify_alphabet(occupation, size);
	if (flag == 1) {
		cout << "\n\nOccupation should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto OCCUPATION;
	}
STATE:
	cout << "\nEnter Patient's state                                       :";
	cin.getline(state, 30);
	size = strlen(state);
	flag = verify_alphabet(state, size);
	if (flag == 1) {
		cout << "\n\nState should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto STATE;
	}
CITY:
	cout << "\nEnter Patient's City                                        :";
	cin.getline(city, 30);
	size = strlen(city);
	flag = verify_alphabet(city, size);
	if (flag == 1) {
		cout << "\n\nCity should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto CITY;
	}
NATIONALITY:
	cout << "\nEnter Patient's Nationality                                 :";
	cin.getline(nationality, 30);
	size = strlen(nationality);
	flag = verify_alphabet(nationality, size);
	if (flag == 1) {
		cout << "\n\nNationality should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto NATIONALITY;
	}
	cout << "\nEnter Patient's Phone Number                                :";
	cin.getline(phone_no, 20);
	cout << "\nEnter Patient's Street Name                                 :";
	cin.getline(street, 30);
	cout << "\nEnter Patient's Symptoms                                    :";
	cin.getline(symptoms, 70);
	cout << "\nEnter Patient's Disease                                     :";
	cin.getline(disease, 30);
	cout << "\nEnter Patient's Door Number                                 :";
	cin.getline(door_no, 20);
	cout << "\nEnter Patient's Condition                                   :";
	cin.getline(condition, 30);
	cout << "\nEnter Admission Date Of The Patient                         :";
	cin.getline(date_admitted, 20);
	cout << "\nEnter Discharge Date Of The Patient                         :";
	cin.getline(date_discharged, 20);
	cout << "\nEnter Condition Of The Patient At The Time Of The Discharge :";
	cin.getline(discharge_condition, 50);
	cout << "\nEnter The Patient's Next Consultation Date                  :";
	cin.getline(consultation_date, 30);
	cout << "\nEnter The Patient's Bill Charges                             :";
	cin >> bill;

}
void patient::assign_patient_to_doctor(patient p, int size) {
	long int size1 = size;
	ifstream myfile1("doctor8.txt");
	size = get_size_of_the_file();
	doctor d;
	size = size / (sizeof(d));
	cout << "********************************************************************************";
	cout << "\n\t The Following Are The Specilizations Available In The Hospital\n";
	cout << "********************************************************************************";
	cout << "\n1.General Medicine\n2.Cardiology\n3.Neurology\n4.ENT\n";
	cout << "********************************************************************************";
	cout << "\n\nPlease Select Your Choice :";
	int opt,flag=0;
	int cho;
	cin >> opt;
	myfile1.seekg(0);
	switch (opt) {
		case 1:
			system("CLS");
			cout << "********************************************************************************";
			cout << "\n\t\tID's Of The Doctors With The General Medicine Specilization\n";
			cout << "********************************************************************************";
			for (int i = 0; i < size; i++) {
				cout << "\n";
				myfile1.read((char*)&d, sizeof(d));
				flag = d.verify_specilization(opt,flag);

			}
			myfile1.close();
			if (flag == 0) {
				system("CLS");
				cout << "********************************************************************************";
				cout << "\nSorry!No Doctors Are Available With The Required Specilization\n";
				cout << "********************************************************************************";
				cout << "\n\n";
				system("PAUSE");
			} else {
				cout << "\n";
				cout << "***********************************************************************************";
				fstream myfile6("patient11.txt", ios::in | ios::out);
				patient p1 = p;
				myfile6.seekp(0);
				myfile6.seekg(0);
				p1.set_doc_ID();
				myfile6.seekp(size1, ios::beg);
				myfile6.write((char*)&p1, sizeof(p1));
				system("CLS");
				cout << "\nPatient Has Been Assigned A Doctor Successfully";
				cout << "\n";
				cout << "\n*****************************************************************************";
				cout << "\n\n";
				system("PAUSE");
			}
			break;
		case 2:
			system("CLS");
			cout << "********************************************************************************";
			cout << "\n\t\tID's Of The Doctors With The Cardiology Specilization\n";
			cout << "********************************************************************************";
			for (int i = 0; i < size; i++) {
				cout << "\n";
				myfile1.read((char*)&d, sizeof(d));
				flag = d.verify_specilization(opt,flag);
			}
			if (flag == 0) {
				system("CLS");
				cout << "********************************************************************************";
				cout << "\nSorry!No Doctors Are Available With The Required Specilization\n";
				cout << "********************************************************************************";
				cout << "\n\n";
				system("PAUSE");
			} else {
				cout << "\n";
				cout << "********************************************************************************";
				fstream myfile6("patient11.txt", ios::in | ios::out);
				patient p1 = p;
				myfile6.seekp(0);
				myfile6.seekg(0);
				p1.set_doc_ID();
				myfile6.seekp(size1, ios::beg);
				myfile6.write((char*)&p1, sizeof(p1));
				system("CLS");
				cout << "\nPatient Has Been Assigned A Doctor Successfully";
				cout << "\n";
				cout << "\n*****************************************************************************";
				cout << "\n\n";
				system("PAUSE");
			}
			break;
		case 3:
			system("CLS");
			cout << "********************************************************************************";
			cout << "\n\t\tID's Of The Doctors With The Neurology Specilization\n";
			cout << "********************************************************************************";
			for (int i = 0; i < size; i++) {
				cout << "\n";
				myfile1.read((char*)&d, sizeof(d));
				flag = d.verify_specilization(opt,flag);
			}
			if (flag == 0) {
				system("CLS");
				cout << "********************************************************************************";
				cout << "\nSorry!No Doctors Are Available With The Required Specilization\n";
				cout << "********************************************************************************";
				cout << "\n\n";
				system("PAUSE");
			} else {
				cout << "\n";
				cout << "********************************************************************************";
				fstream myfile6("patient11.txt", ios::in | ios::out);
				patient p1 = p;
				myfile6.seekp(0);
				myfile6.seekg(0);
				p1.set_doc_ID();
				myfile6.seekp(size1, ios::beg);
				myfile6.write((char*)&p1, sizeof(p1));
				system("CLS");
				cout << "\nPatient Has Been Assigned A Doctor Successfully";
				cout << "\n";
				cout << "\n*****************************************************************************";
				cout << "\n\n";
				system("PAUSE");
			}

			break;
		case 4:
			system("CLS");
			cout << "********************************************************************************";
			cout << "\n\t\tID's Of The Doctors With The ENT Specilization\n";
			cout << "********************************************************************************";
			for (int i = 0; i < size; i++) {
				cout << "\n";
				myfile1.read((char*)&d, sizeof(d));
				flag = d.verify_specilization(opt,flag);
			}
			if (flag == 0) {
				system("CLS");
				cout << "********************************************************************************";
				cout << "\nSorry!No Doctors Are Available With The Required Specilization\n";
				cout << "********************************************************************************";
				cout << "\n\n";
				system("PAUSE");
			} else {
				cout << "\n";
				cout << "********************************************************************************";
				fstream myfile6("patient11.txt", ios::in | ios::out);
				patient p1 = p;
				myfile6.seekp(0);
				myfile6.seekg(0);
				p1.set_doc_ID();
				myfile6.seekp(size1, ios::beg);
				myfile6.write((char*)&p1, sizeof(p1));
				system("CLS");
				cout << "\nPatient Has Been Assigned A Doctor Successfully";
				cout << "\n";
				cout << "\n*****************************************************************************";
				cout << "\n\n";
				system("PAUSE");
			}
			break;
		default:
			cout << "\nWrong Choice!!!";
	}

}

void patient::get_name() {
	cout << "\nEnter New Name :";
	cin.ignore();
	cin.getline(name, 50);
}
void patient::get_age() {
	cout << "\nEnter New Age :";
	cin.ignore();
	cin >> age;
}
void patient::get_occupation() {
	cout << "\nEnter New Occupation :";
	cin.ignore();
	cin.getline(occupation, 50);
}
void patient::get_state() {
	cin.ignore();
	cout << "\nEnter New State :";
	cin.getline(state, 20);
}
void patient::get_city() {
	cin.ignore();
	cout << "\nEnter New City :";
	cin.getline(city, 20);
}
void patient::get_phone_no() {
	cin.ignore();
	cout << "\nEnter New Phone Number :";
	cin.getline(phone_no, 30);
}
void patient::get_nationality() {
	cin.ignore();
	cout << "\nEnter New Nationality :";
	cin.getline(nationality, 30);
}
void patient::get_street() {
	cin.ignore();
	cout << "\nEnter New Street :";
	cin.getline(street, 50);
}
void patient::get_door_no() {
	cin.ignore();
	cout << "\nEnter New Door Number :";
	cin.getline(door_no, 30);
}
void patient::get_condition() {
	cin.ignore();
	cout << "\nEnter New Condition :";
	cin.getline(condition, 50);
}
void patient::get_discharge_condition() {
	cin.ignore();
	cout << "\nEnter New Condition Of The Patient At The Time Of Discharge :";
	cin.getline(discharge_condition, 50);
}
void patient::get_date_admitted() {
	cin.ignore();
	cout << "\nEnter New Admission Date Of The Patient :";
	cin.getline(date_admitted, 30);
}
void patient::get_date_discharged() {
	cin.ignore();
	cout << "\nEnter New Discharge Date Of The Patient :";
	cin.getline(date_discharged, 30);
}
void patient::get_bill() {
	cin.ignore();
	cout << "\nEnter New Bill Charge Of The Patient    :";
	cin >> bill;
}
void patient::display_all(patient p) {
	cout  << p.id << "\t" << p.age << "\t" << p.symptoms << "\t" << p.date_admitted << "\t\t\t"<<p.doc_id<<"\n";
}
void patient::display_info(patient p) {
	cout << "\nPatient's ID                                       :" << p.id;
	cout << "\nPatient's Name                                     :" << p.name;
	cout << "\nPatient's Age                                      :" << p.age;
	cout << "\nPatient's Occupation                               :" << p.occupation;
	cout << "\nPatient's State                                    :" << p.state;
	cout << "\nPatient's City                                     :" << p.city;
	cout << "\nPatient's Phone Number                             :" << p.phone_no;
	cout << "\nPatient's Nationality                              :" << p.nationality;
	cout << "\nPatient's Street                                   :" << p.street;
	cout << "\nPatient's Door Number                              :" << p.door_no;
	cout << "\nPatient's Condtion                                 :" << p.condition;
	cout << "\nPatient's Condition At The Time Of Discharge       :" << p.discharge_condition;
	cout << "\nPatient's Admission Date                           :" << p.date_admitted;
	cout << "\nPatient's Discharge Date                           :" << p.date_discharged;
	cout << "\nID Of The Doctor Who Is Treating The Patient       :" << p.doc_id;
}
void patient::modify_info(patient p, int number, int size) {
	if (number == 1) {
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_name();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	} else if (number == 2) {
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_age();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	} else if (number == 3) {
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_occupation();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	} else if (number == 4) {
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_state();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	} else if (number == 5) {
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_city();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	} else if (number == 6) {
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_phone_no();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	} else if (number == 7) {
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_nationality();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	} else if (number == 8) {
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_street();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	} else if (number == 9) {
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_door_no();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	} else if (number == 10) {
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_condition();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	} else if (number == 11) {
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_discharge_condition();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	} else if (number == 12) {
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_date_admitted();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	} else if (number == 13) {
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_date_discharged();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	} else if (number == 14) {
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_bill();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
}
void add_patient_data() {
	patient p;
	ofstream myfile("patient11.txt", ios::in | ios::app);
	p.get_info();
	myfile.write((char*)&p, sizeof(p));
	myfile.close();
}
void display1() {
	long int size = 0;
	size = get_size_of_the_file1();
	int i = 0;
	patient p;
	size = size / (sizeof(p));
	if (size == 0) {
		cout << "\nDatabase Empty!!!";
		cout << "\n";
	} else {
		cout << "\n";
		cout << "********************************************************************************";
		cout << "\n\t\t\tDetails Of All The Patients In The Hospital\n";
		cout << "********************************************************************************";
		cout  << "ID" << "\t" << "Age" << "\t" << "Illness" << "\t\t" << "Date Admitted" << "\t\t"<<"Doctor's ID"<<"\n";
		ifstream myfile("patient11.txt");
		myfile.seekg(0);
		for (i = 0; i < size; i++) {
			cout << "\n\n";
			myfile.read((char*)&p, sizeof(p));
			p.display_all(p);
		}
		cout << "********************************************************************************";
	}
}

int display_patient_data() {
	long int size = 0;
	size = get_size_of_the_file1();
	int i = 0, id, id1, count1 = 0;
	patient p1;
	size = size / (sizeof(p1));
	if (size == 0) {
		cout << "\nDatabase Empty!!!";
		cout << "\n";
	}


	else {
		cout << "\nEnter The ID Of The Patient You Require :";
		cin >> id;
		ifstream myfile1("patient11.txt");
		for (i = 0; i < size; i++) {
			myfile1.clear();
			myfile1.read((char*)&p1, sizeof(p1));
			id1 = p1.get_ID();
			if (id == id1) {
				count1 = 1;

				p1.display_info(p1);
				cout << "\n\n";
				system("PAUSE");
				cout << "\n";
				break;
			}
		}
		myfile1.close();
		return(count1);

	}
}

void assign_patient() {
	patient p;
	int id;
	long int size;
	size = get_size_of_the_file1();
	int i = 0, count = 0, id1;
	size = size / (sizeof(p));
	if (size == 0) {
		cout << "\n Database Empty!!!\n";
		cout << "\nYou Need To Add Patient's Information First!!!";
		cout << "\n\n";
		system("PAUSE");
	} else {
		cout << "\nEnter ID Of The Patient :";
		cin >> id;
		ifstream myfile("patient11.txt");
		myfile.seekg(0);
		for (i = 0; i < size; i++) {
			myfile.read((char*)&p, sizeof(p));
			id1 = p.get_ID();
			if (id == id1) {
				count = 1;
				size = myfile.tellg();
				size = size - sizeof(p);
				p.assign_patient_to_doctor( p, size);
				break;
			}
		}
		if (count == 0) {
			system("CLS");
			cout << "********************************************************************************";
			cout << "\nSorry!No Data Is Available Related To The Given ID\n";
			cout << "********************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}
	}
}


void modify_patient_data() {
	int id1;
	long int size = 0;
	size = get_size_of_the_file1();
	int i = 0, count = 0, id;
	patient p2;
	size = size / (sizeof(p2));
	if (size == 0) {
		cout << "\nDatabase Empty!!!\n";
		cout << "\nNo Record To Modify!!!";
		cout << "\n\n";
		system("PAUSE");
	} else {
		cout << "\nEnter The ID Of The Patient To Modify Data :";
		cin >> id1;
		ifstream myfile2("patient11.txt");
		myfile2.seekg(0);
		for (i = 0; i < size; i++) {
			myfile2.read((char*)&p2, sizeof(p2));
			id = p2.get_ID();
			if (id == id1) {
				size = myfile2.tellg();
				size = size - sizeof(p2);
				count = 1;
				p2.display_info(p2);
				cout << "\n";
				system("PAUSE");
				cout << "\n";
				cout << "\nField's Which Can Be Modified\n";
				cout << "\n1.Name\n2.Age\n3.Occupation\n4.State\n";
				cout << "5.City\n6.Phone Number\n7.Nationality\n";
				cout << "\n8.Street\n9.Door Number\n10.Condition\n";
				cout << "11.Discharge Condition\n12.Date Admitted\n";
				cout << "13.Date Discharged\n14.Patient Bill";
				int opt2;
				cout << "\nSelect The Field Which You Want To Modify :";
				cin >> opt2;
				switch (opt2) {
					case 1:
						p2.modify_info(p2, opt2, size);
						break;
					case 2:
						p2.modify_info(p2, opt2, size);
						break;
					case 3:
						p2.modify_info(p2, opt2, size);
						break;
					case 4:
						p2.modify_info(p2, opt2, size);
						break;
					case 5:
						p2.modify_info(p2, opt2, size);
						break;
					case 6:
						p2.modify_info(p2, opt2, size);
						break;
					case 7:
						p2.modify_info(p2, opt2, size);
						break;
					case 8:
						p2.modify_info(p2, opt2, size);
						break;
					case 9:
						p2.modify_info(p2, opt2, size);
						break;
					case 10:
						p2.modify_info(p2, opt2, size);
						break;
					case 11:
						p2.modify_info(p2, opt2, size);
						break;
					case 12:
						p2.modify_info(p2, opt2, size);
						break;
					case 13:
						p2.modify_info(p2, opt2, size);
						break;
					case 14:
						p2.modify_info(p2, opt2, size);
						break;
					default:
						cout << "\nWrong Choice ";
				}
				break;
			}
		}
		myfile2.close();
		if (count == 0) {
			cout << "\nRecord Does'nt Exist!!!";
			cout << "\n";
			system("PAUSE");

		}
	}

}
void delete_patient_data() {
	long int size;
	size = get_size_of_the_file1();
	patient p;
	size = size / (sizeof(p));
	if (size == 0) {
		cout << "\nDatabase Empty!!!";
		cout << "\n\nNo Record To Delete!!!";
		cout << "\n";
	} else {
		ifstream myfile6("patient11.txt");
		ofstream myfile7("temp4.txt");
		int id, count = 0, id1, i;
		cout << "\nEnter The ID Of The Patient Whose Data You Want To Delete :";
		cin >> id;
		for (i = 0; i < size; i++) {
			myfile6.read((char*)&p, sizeof(p));
			id1 = p.get_ID();
			if (id != id1) {
				myfile7.write((char*)&p, sizeof(p));
			} else {
				count = 1;

			}
		}
		myfile6.close();
		myfile7.close();
		ofstream myfile9("patient11.txt");
		ifstream myfile8("temp4.txt");
		for (i = 0; i < size - 1; i++) {
			myfile8.read((char*)&p, sizeof(p));
			myfile9.write((char*)&p, sizeof(p));
		}

		if (count == 0) {
			cout << "\nNo Data Found ";
			cout << "\n\n";

		}

		else {
			cout << "\nData Successfully Deleted ";
			cout << "\n\n";

		}
	}


}
long int get_size_of_the_file1() {
	long int size = 0;
	ifstream ifile("patient11.txt");
	ifile.seekg(0, ios::end);
	size = ifile.tellg();
	ifile.close();
	return(size);
}

int number() {
	long int size;
	patient p;
	size = get_size_of_the_file1();
	size = size / (sizeof(p));
	return(size);

}

void report() {
	patient p;
	int id, id1, count = 0;
	long int size;
	size = get_size_of_the_file1();
	size = size / (sizeof(p));
	if (size == 0) {
		cout << "\nPatient Database Empty!!!";
		cout << "\nAdd Some Patient's Info First!!!";
		cout << "\n\n";
		system("PAUSE");
	} else {

		cout << "\nEnter The ID Of The Patient You Require :";
		cin >> id;
		ifstream myfile1("patient11.txt");
		for (int i = 0; i < size; i++) {
			myfile1.clear();
			myfile1.read((char*)&p, sizeof(p));
			id1 = p.get_ID();
			if (id == id1) {
				count = 1;

				p.report1(p);
				break;
			}

		}
		if (count == 0) {
			cout << "\nData Not Available!!!";
		}
	}
}
void bill() {
	long int size = 0;
	size = get_size_of_the_file1();
	int i = 0, id, id1, count1 = 0;
	patient p1;
	size = size / (sizeof(p1));
	if (size == 0) {
		cout << "\nDatabase Empty!!!";
		cout << "\n";
	}


	else {
		cout << "\nEnter The ID Of The Patient You Require :";
		cin >> id;
		ifstream myfile1("patient11.txt");
		for (i = 0; i < size; i++) {
			myfile1.clear();
			myfile1.read((char*)&p1, sizeof(p1));
			id1 = p1.get_ID();
			if (id == id1) {
				count1 = 1;

				p1.bill1(p1);
				break;
			}
		}
		if (count1 == 0) {
			cout << "\nData Not Found!!!";
		}
		myfile1.close();

	}
}


//cafe

struct r {
	char dish[100];
	int key;
	float price;
	int quantity;
} r;

class cafeteria {
	public:
		void create();
		void query();
		void display();
		void update();
		void delet();
		void admin();
};
void cafeteria::create() {
	char a;
	int k;
	fstream obj;
top:
	do {
		obj.open("cafeteria.txt", ios::in | ios::binary);
		cout << "Enter the Dish key:";
		cin >> k;
		while (obj.read((char *)&r, sizeof(r))) {
			if (r.key == k) {
				cout << "Key already exists." << endl;
				obj.close();
				goto top;
			}
		}
		obj.close();
		obj.open("cafeteria.txt", ios::app | ios::binary);
		r.key = k;
		cin.ignore();
		cout << "Enter the Dish Name:";
		gets(r.dish);
		cout << "Enter the Dish Price:";
		cin >> r.price;
		cout << "Enter the Dish Quantity:";
		cin >> r.quantity;
		obj.write((char *)&r, sizeof(r));
		cout << "Would you like to add another Dish?[y/n]:";
		cin >> a;
		obj.close();
	} while (a != 'n');
}
void cafeteria::display() {
	int c = 0;
	fstream obj;
	obj.open("cafeteria.txt", ios::in | ios::binary);
	cout << "\tKey\t\tDISH NAME\t\tPRICE\t\tQUANTITY" << endl;
	while (obj.read((char *)&r, sizeof(r))) {
		cout << "\t" << r.key << "\t\t" << r.dish << "\t\t\t" << r.price << "\t\t\t\t" << r.quantity << endl;
		c++;
	}
	if (c == 0) {
		cout << "List is empty at the moment." << endl;
	}
	obj.close();
}
void cafeteria::query() {
	int a, c = 0;
	fstream obj;
	obj.open("cafeteria.txt", ios::in);
	cout << "Enter the Dish key:";
	cin >> a;
	while (obj.read((char *)&r, sizeof(r))) {
		if (r.key == a) {
			cout << "\t" << r.key << "\t\t" << r.dish << "\t\t\t" << r.price << "\t\t\t\t" << r.quantity << endl;
			c++;
		}
	}
	if (c == 0) {
		cout << "Not found" << endl;
	}
	obj.close();
}
void cafeteria::update() {
	int a,p,c=0;
	fstream obj;
	obj.open("cafeteria.txt",ios::in|ios::out|ios::binary);
	cout<<"Enter the Dish key:";
	cin>>a;
	obj.seekg(0);
	while(obj.read((char*)&r,sizeof(r))) {
		if(r.key==a) {
			cout<<"Seek Record:"<<endl;
			cout<<"\t"<<r.key<<"\t\t"<<r.dish<<"\t\t\t"<<r.price<<"\t\t\t"<<r.quantity<<endl;
			p=obj.tellg()-(sizeof(r));
			obj.seekp(p);
			cout<<"Enter the Dish Key:";
			cin>>r.key;
			cin.ignore();
			cout<<"Enter the Dish Name:";
			gets(r.dish);
			cout<<"Enter the Dish Price:";
			cin>>r.price;
			cout<<"Enter the Dish Quantity:";
			cin>>r.quantity;
			obj.write((char*)&r,sizeof(r));
			c++;
		}

	}
	if(c==0) {
		cout<<"Not Found."<<endl;
	}

	obj.close();
}
void cafeteria::delet() {
	int a, c;
	fstream obj, obj1;
	obj.open("cafeteria.txt", ios::in | ios::binary);
	obj1.open("temp.txt", ios::app | ios::binary);
	cout << "Enter the Dish key:";
	cin >> a;
	while (obj.read((char *)&r, sizeof(r))) {
		if (r.key == a) {
			c++;
			cout << "\t" << r.key << "\t\t" << r.dish << "\t\t\t" << r.price << "\t\t\t\t" << r.quantity << endl;
			cout << "The Entered Record is Now Deleted." << endl;
		}
		if (r.key != a) {
			obj1.write((char *)&r, sizeof(r));
		}
	}
	obj.close();
	obj1.close();
	if (c == 0) {
		cout << "Not found" << endl;
	}
	remove("cafeteria.txt");
	rename("temp.txt", "cafeteria.txt");
}
void cafeteria::admin() {
	char a;
	do {

		cout << "\n\t\t\t\t\t         _________________________" << endl;
		cout << "\t\t\t\t\t\t|                       |" << endl;
		cout << "\t\t\t\t\t\t|  1) ADD DISH          |" << endl;
		cout << "\t\t\t\t\t\t|  2) DISPLAY           |" << endl;
		cout << "\t\t\t\t\t\t|  3) QUERY             |" << endl;
		cout << "\t\t\t\t\t\t|  4) UPDATE            |" << endl;
		cout << "\t\t\t\t\t\t|  5) DELETE            |" << endl;
		cout << "\t\t\t\t\t\t|  0) EXIT TO MAIN MANU |" << endl;
		cout << "\t\t\t\t\t\t|                       |" << endl;
		cout << "\t\t\t\t\t\t_________________________" << endl;
		cout << "\t\t\t\t\t\t Select the key";
		cin >> a;
		switch (a) {
			case '0':
				break;
			case '1':
				system("CLS");
				create();
				break;
			case '2':
				system("CLS");
				display();
				break;
			case '3':
				system("CLS");
				query();
				break;
			case '4':
				system("CLS");
				update();
				break;
			case '5':
				system("CLS");
				delet();
				break;
		}
	} while (a != '0');
}
struct rd {
	char d[50];
	float p, amount;
	int qty;
} rd;
class customer : public cafeteria {
	public:
		void bill();
		void showbill();
		void dish_menu();
};
void customer::bill() {
	int a;
	int n;
	int check=0;
	char ch;
	float total = 0;
	fstream obj, obj1;
	dish_menu();
	obj1.open("bill.txt", ios::out | ios::binary);
	do {
		obj.open("cafeteria.txt", ios::in | ios::out | ios::binary);
		cout << "Enter the Dish key:";
		cin >> a;

		while (obj.read((char *)&r, sizeof(r))) {

			if (r.key == a) {
				cout << "Dish Found.." << endl;
				cout << "Enter the Quantity:";
				cin >> n;
				if (r.quantity >= n) {
					check++;
					rd.qty = n;
					cout << "Dish Available.." << endl;
					cout << "Dish Name:" << r.dish << endl;
					cout << "Dish Price:" << r.price << endl;
					cout << "Dish Quantity:" << r.quantity << endl;
					cout << "Dish Amount:" << r.price * rd.qty << endl;
					rd.amount = r.price * rd.qty;
					total = total + rd.amount;
					obj1.write((char *)&rd, sizeof(rd));
					r.quantity = r.quantity - rd.qty;
					obj.seekp(-sizeof(r), ios::cur);
					obj.write((char *)&r, sizeof(r));
				} else if (r.quantity < n) {
					cout << "Required Quantity Unavailable.." << endl;
				}
			}
		}
		if(check==0) {
			cout << "Dish Not Found.." << endl;
		}
		cout << "Would you like to add to your order?[y/n]";
		cin >> ch;
		obj.close();
		check=0;
	} while (ch != 'n');

	obj1.close();
	cout << "|||||||||||||||||||||||||||||||||||||||||||||||| BILL  |||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	showbill();
	cout << "|||\t\t\t\t\t\t\t   TOTAL=" << total << "\t\t\t\t\t   |||" << endl;
}
void customer::showbill() {
	fstream obj;
	obj.open("bill.txt", ios::in | ios::binary);
	cout << "\tDish\t\tPrice\t\tQuantity\t\tAmount" << endl;
	while (obj.read((char *)&rd, sizeof(rd))) {

		cout << "\t" << r.dish << "\t\t\t" << r.price << "\t\t" << rd.qty << "\t\t" << rd.amount << endl;
	}
	obj.close();
}
void customer::dish_menu() {
	fstream obj;
	obj.open("cafeteria.txt", ios::in | ios::binary);
	while (obj.read((char *)&r, sizeof(r))) {

		cout << "\t\t" << r.key << ") " << r.dish << "-------RS  " << r.price << "\t\t\t\t" << r.quantity << endl;
	}
	obj.close();
}

//Pharmacy
struct r1 {
	char medicine[100];
	int key;
	float price;
	int quantity;
} r1;
class pharmacy {
	public:
		void create();
		void query();
		void display();
		void update();
		void delet();
		void admin();
};
void pharmacy::create() {
	char a;
	int k;
	fstream obj;
top:
	do {
		obj.open("pharmacy.txt", ios::in | ios::binary);
		cout << "Enter the Medicine key:";
		cin >> k;
		while (obj.read((char *)&r1, sizeof(r1))) {
			if (r1.key == k) {
				cout << "Key already exists." << endl;
				obj.close();
				goto top;
			}
		}
		obj.close();
		obj.open("pharmacy.txt", ios::app | ios::binary);
		r1.key = k;
		cin.ignore();
		cout << "Enter the Medicine Name:";
		gets(r1.medicine);
		cout << "Enter the Medicine Price:";
		cin >> r1.price;
		cout << "Enter the Medicine Quantity:";
		cin >> r1.quantity;
		obj.write((char *)&r1, sizeof(r1));
		cout << "Would you like to add another Medicine?[y/n]:";
		cin >> a;
		obj.close();
	} while (a != 'n');
}
void pharmacy::display() {
	int c = 0;
	fstream obj;
	obj.open("pharmacy.txt", ios::in | ios::binary);
	cout << "\tKey\t\tMEDICINE NAME\t\tPRICE\t\tQUANTITY" << endl;
	while (obj.read((char *)&r1, sizeof(r1))) {
		cout << "\t" << r1.key << "\t\t" << r1.medicine << "\t\t\t" << r1.price << "\t\t\t\t" << r1.quantity << endl;
		c++;
	}
	if (c == 0) {
		cout << "List is empty at the moment." << endl;
	}
	obj.close();
}
void pharmacy::query() {
	int a, c = 0;
	fstream obj;
	obj.open("pharmacy.txt", ios::in);
	cout << "Enter the Medicine key:";
	cin >> a;
	while (obj.read((char *)&r1, sizeof(r1))) {
		if (r1.key == a) {
			cout << "\t" << r1.key << "\t\t" << r1.medicine << "\t\t\t" << r1.price << "\t\t\t\t" << r1.quantity << endl;
			c++;
		}
	}
	if (c == 0) {
		cout << "Not found" << endl;
	}
	obj.close();
}
void pharmacy::update() {
	int a,p,c=0;
	fstream obj;
	obj.open("pharmacy.txt",ios::in|ios::out|ios::binary);
	cout<<"Enter the Medicine key:";
	cin>>a;
	obj.seekg(0);
	while(obj.read((char*)&r1,sizeof(r1))) {
		if(r1.key==a) {
			cout<<"Seeked Record:"<<endl;
			cout<<"\t"<<r1.key<<"\t\t"<<r1.medicine<<"\t\t\t"<<r1.price<<"\t\t\t\t"<<r1.quantity<<endl;
			p=obj.tellg()-(sizeof(r1));
			obj.seekp(p);
			cout<<"Enter the Medicine key:";
			cin>>r1.key;
			cin.ignore();
			cout<<"Enter the Medicine Name:";
			gets(r1.medicine);
			cout<<"Enter the Medicine Price:";
			cin>>r1.price;
			cout<<"Enter the Medicine Quantity:";
			cin>>r1.quantity;
			obj.write((char*)&r1,sizeof(r1));
			c++;
		}

	}
	if(c==0) {
		cout<<"Not Found."<<endl;
	}

	obj.close();
}
void pharmacy::delet() {
	int a, c;
	fstream obj, obj1;
	obj.open("pharmacy.txt", ios::in | ios::binary);
	obj1.open("temp.txt", ios::app | ios::binary);
	cout << "Enter the Medicine key:";
	cin >> a;
	while (obj.read((char *)&r1, sizeof(r1))) {
		if (r1.key == a) {
			c++;
			cout << "\t" << r1.key << "\t\t" << r1.medicine << "\t\t\t" << r1.price << "\t\t\t\t" << r1.quantity << endl;
			cout << "The Entered Record is Now Deleted." << endl;
		}
		if (r1.key != a) {
			obj1.write((char *)&r1, sizeof(r1));
		}
	}
	obj.close();
	obj1.close();
	if (c == 0) {
		cout << "Not found" << endl;
	}
	remove("pharmacy.txt");
	rename("temp.txt", "pharmacy.txt");
}
void pharmacy::admin() {
	char a;
	do {

		cout << "\n\t\t\t\t\t         _________________________" << endl;
		cout << "\t\t\t\t\t\t|                       |" << endl;
		cout << "\t\t\t\t\t\t|  1) ADD MEDICINE      |" << endl;
		cout << "\t\t\t\t\t\t|  2) DISPLAY           |" << endl;
		cout << "\t\t\t\t\t\t|  3) QUERY             |" << endl;
		cout << "\t\t\t\t\t\t|  4) UPDATE            |" << endl;
		cout << "\t\t\t\t\t\t|  5) DELETE            |" << endl;
		cout << "\t\t\t\t\t\t|  0) EXIT TO MAIN MANU |" << endl;
		cout << "\t\t\t\t\t\t|                       |" << endl;
		cout << "\t\t\t\t\t\t_________________________" << endl;
		cout << "\t\t\t\t\t\t Select the key";
		cin >> a;
		switch (a) {
			case '0':
				break;
			case '1':
				system("CLS");
				create();
				break;
			case '2':
				system("CLS");
				display();
				break;
			case '3':
				system("CLS");
				query();
				break;
			case '4':
				system("CLS");
				update();
				break;
			case '5':
				system("CLS");
				delet();
				break;
		}
	} while (a != '0');
}
struct s {
	char d[50];
	float p, amount;
	int qty;
} rd1;
class custmer : public pharmacy {
	public:
		void bill();
		void showbill();
		void dish_menu();
};
void custmer::bill() {
	int a;
	int n;
	int check=0;
	char ch;
	float total = 0;
	fstream obj, obj1;
	dish_menu();
	obj1.open("bill.txt", ios::out | ios::binary);
	do {
		obj.open("pharmacy.txt", ios::in | ios::out | ios::binary);
		cout << "Enter the Medicine key:";
		cin >> a;

		while (obj.read((char *)&r1, sizeof(r1))) {

			if (r1.key == a) {
				cout << "Medicine Found.." << endl;
				cout << "Enter the Quantity:";
				cin >> n;
				if (r1.quantity >= rd1.qty) {
					check++;
					rd1.qty = n;
					cout << "Medicine Available.." << endl;
					cout << "Medicine Name:" << r1.medicine << endl;
					cout << "Medicine Price:" << r1.price << endl;
					cout << "Medicine Quantity:" << r1.quantity << endl;
					cout << "Medicine Amount:" << r1.price * rd1.qty << endl;
					rd1.amount = r1.price * rd1.qty;
					total = total + rd1.amount;
					obj1.write((char *)&rd1, sizeof(rd1));
					r1.quantity = r1.quantity - rd1.qty;
					obj.seekp(-sizeof(r1), ios::cur);
					obj.write((char *)&r1, sizeof(r1));
				} else if (r1.quantity < n) {
					cout << "Required Quantity Unavailable.." << endl;
				}
			}
		}
		if(check==0) {
			cout << "Medicine Not Found.." << endl;
		}
		cout << "Would you like to add to your order?[y/n]";
		cin >> ch;
		obj.close();
		check=0;
	} while (ch != 'n');

	obj1.close();
	cout << "|||||||||||||||||||||||||||||||||||||||||||||||| BILL  |||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	showbill();
	cout << "|||\t\t\t\t\t\t\t   TOTAL=" << total << "\t\t\t\t\t   |||" << endl;
}
void custmer::showbill() {
	fstream obj;
	obj.open("bill.txt", ios::in | ios::binary);
	cout << "\tMedicine\t\tPRICE\t\tQTY\t\tAMOUNT" << endl;
	while (obj.read((char *)&rd1, sizeof(rd1))) {

		cout << "\t" << r1.medicine << "\t\t\t" << r1.price << "\t\t" << rd1.qty << "\t\t" << rd1.amount << endl;
	}
	obj.close();
}
void custmer::dish_menu() {
	fstream obj;
	obj.open("pharmacy.txt", ios::in | ios::binary);
	while (obj.read((char *)&r1, sizeof(r1))) {

		cout << "\t\t" << r1.key << ") " << r1.medicine << "-------RS  " << r1.price << "\t\t\t\t" << r1.quantity << endl;
	}
	obj.close();
}


//BloodBank
struct Donation {
	string donorName;
	string bloodType;
	bool available;
};
void readDonations(vector<Donation>& donations, const string& filename) {
	ifstream infile(filename);

	Donation donation;
	while (infile >> donation.donorName >> donation.bloodType >> donation.available) {
		donations.push_back(donation);
	}
	infile.close();
}
void writeDonations(const vector<Donation>& donations, const string& filename) {
	ofstream outfile(filename);

	for (const auto& donation : donations) {
		outfile << donation.donorName << " " << donation.bloodType << " " << donation.available << endl;
	}
	outfile.close();
}
void addDonation(vector<Donation>& donations, const string& filename) {
	Donation donation;
	cout << "Enter donor's name: ";
	cin >> donation.donorName;
	cout << "Enter blood type: ";
	cin >> donation.bloodType;
	donation.available = true;
	donations.push_back(donation);

	writeDonations(donations, filename);
	cout << "Donation added." << endl;
}
//Staff(Cleaning,Security)
struct Staff {
	string staffName;
	string staffType;
	bool available;
};
void readStaff(vector<Staff>& staffs, const string& filename) {
	ifstream infile(filename);

	Staff Staff;
	while (infile >> Staff.staffName >> Staff.staffType >> Staff.available) {
		staffs.push_back(Staff);
	}
	infile.close();
}
void writeStaff(const vector<Staff>& staffs, const string& filename) {
	ofstream outfile(filename);

	for (const auto& staff : staffs) {
		outfile << staff.staffName << " " << staff.staffType << " " << staff.available << endl;
	}
	outfile.close();
}
void addStaff(vector<Staff>& staffs, const string& filename) {
	Staff staff;
	cout << "Enter Staff Member's' name: ";
	cin >> staff.staffName;
	cout << "Enter Staff Member's type: ";
	cin >> staff.staffType;
	staff.available = true;
	staffs.push_back(staff);

	writeStaff(staffs, filename);
	cout << "Staff Member added." << endl;
}
//DONE

class MainMenu {
	public:
		int choice;
		MainMenu() {
			Sleep(50);
			cout << "\n\n\n\n";
			Sleep(50);
			cout << "\t\t\t_________________________________________________________________" << endl;
			Sleep(50);
			cout << "\t\t\t|                        WELCOME TO                              |" << endl;
			Sleep(50);
			cout << "\t\t\t|                   HOSPITAL MANAGEMENT SYSTEM                   |" << endl;
			Sleep(50);
			cout << "\t\t\t|            ======================================              |" << endl;
			Sleep(50);
			cout << "\t\t\t|                      DEVELOPED BY:                             |" << endl;
			Sleep(50);
			cout << "\t\t\t|                  Aarij Ali 22K-4264                            |" << endl;
			Sleep(50);
			cout << "\t\t\t|                   Muhammad Qasim 22K-4380                      |" << endl;
			Sleep(50);
			cout << "\t\t\t|                    Muhammad Haris 22K-4660                     |" << endl;
			Sleep(50);
			cout << "\t\t\t|________________________________________________________________|" << endl;
			Sleep(50);
			cout << "\n\n\n\n";
			system("pause");
			system("CLS");
			int j = 0;
			while (j == 0) {
				cout << "\n\n\t\t*************************************\n";
				cout << "\n\t\t\t\tMAIN MENU\n";
				cout << "\n\t\t*************************************\n";
				cout << "\n\t\tSELECT USER:";
				cout << "\n\n\n\t\tDOCTOR'S DATABASE\t\t[1]";
				cout << "\n\n\t\tPATIENT'S' DATABASE'\t\t[2]";
				cout << "\n\n\t\tGENERATE REPORT\t\t\t[3]";
				cout << "\n\n\t\tGENERATE BILL\t\t\t[4]";
				cout << "\n\n\t\tPHARMACY\t\t\t[5]";
				cout << "\n\n\t\tCAFETERIA\t\t\t[6]";
				cout << "\n\n\t\tBLOODBANK\t\t\t[7]";
				cout << "\n\n\t\tSTAFF\t\t\t\t[8]";
				cout << "\n\n\t\tEXIT\t\t\t\t[9]";
				cout << "\n\n\n\t\tYour Choice: ";
				cin >> choice;
				switch (choice) {
					case 1:
						system("CLS");
						checkin();
						system("CLS");
						while (1) {
							system("CLS");
							cout << "********************************************************************************\n";
							cout << "\n\t\t\tWelcome to Doctor's Database\n";
							cout << "\n********************************************************************************\n";
							cout << "\n\t\t1.Add New Doctor's Information\n";
							cout << "\n\t\t2.Edit Doctor's Information\n";
							cout << "\n\t\t3.Display Doctor's Information\n";
							cout << "\n\t\t4.Delete Doctor's Information\n";
							cout << "\n\t\t5.Number Of Doctors In The Hospital\n";
							cout << "\n\t\t6.Clear All The Information In The Database\n";
							cout << "\n\t\t7.Display The Details Of All The Doctors\n";
							cout << "\n\t\t8.Exit\n";
							cout << "\n********************************************************************************\n";
							int opt;
							cout << "Please Choose Your Choice :";
							cin >> opt;
							int y;
							switch (opt) {

								case 1:
									system("CLS");
									add_doctor_data();
									break;
								case 2:

									system("CLS");
									modify_doctor_data();

									break;
								case 3:
									system("CLS");
									y = display_doctor_data();
									if (y != 1) {
										cout << "\nNo Record To Display!!!\n";
										cout << "\n";
										system("PAUSE");
									}

									break;
								case 4:

									system("CLS");
									delete_doctor_data();
									cout << "\n";
									system("PAUSE");

									break;
								case 5:
									system("CLS");
									cout << "\nNumber Of Doctors In The Hospital are :" << doctor_number();
									cout << "\n\n";
									system("PAUSE");
									break;
								case 6:
									system("CLS");
									delete_contents();
									cout << "\nAll The Contents Of The Database Are Deleted ";
									cout << "\n\n";
									system("PAUSE");
									break;
								case 7:
									system("CLS");
									display();
									cout << "\n\n";
									system("PAUSE");
									break;
								case 8:
									system("CLS");

									_getch();
							}
						}

					case 2:
						system("CLS");
						checkin();
						while (1) {
							system("CLS");
							cout << "********************************************************************************\n";
							cout << "\n\t\t\tWelcome To Patient's Database\n\n";
							cout << "********************************************************************************\n";
							cout << "\n\t\t1.Add Patient's Information\n";
							cout << "\n\t\t2.Assign A Patient To A Doctor\n";
							cout << "\n\t\t3.Edit Patient's Information\n";
							cout << "\n\t\t4.Display Patient's Information\n";
							cout << "\n\t\t5.Delete Patient's Information\n";
							cout << "\n\t\t6.No.Of Patients In The Hospital\n";
							cout << "\n\t\t7.Delete All The Contents In The Database\n";
							cout << "\n\t\t8.Display The Details Of All The Patients In The Hospital\n";
							cout << "\n\t\t9.Exit\n\n";
							cout << "********************************************************************************\n";
							int opt;
							cout << "\nPlease Choose Your Choice :";
							cin >> opt;
							int y;
							switch (opt) {
								case 1:
									system("CLS");
									add_patient_data();
									break;
								case 2:
									system("CLS");
									assign_patient();
									break;
								case 3:
									system("CLS");
									modify_patient_data();
									break;
								case 4:
									system("CLS");
									y = display_patient_data();
									if (y != 1) {
										cout << "\nNo Record To Display!!!\n";
										cout << "\n";
										system("PAUSE");
									}
									break;
								case 5:
									system("CLS");
									delete_patient_data();
									cout << "\n";
									system("PAUSE");
									break;
								case 6:
									system("CLS");
									cout << "\nNo.Of Patient's In The Hospital are :" << number();
									cout << "\n\n";
									system("PAUSE");
									break;
								case 7:
									system("CLS");
									delete_contents1();
									cout << "\nAll The Contents Of The Database Are Deleted";
									cout << "\n\n";
									system("PAUSE");
									break;
								case 8:
									system("CLS");
									display1();
									cout << "\n\n";
									system("PAUSE");
									break;
								case 9:
									system("CLS");

									_getch();

							}
						}

					case 3:
						checkin();
						system("CLS");
						cout << "\n\n";
						report();
						cout << "\n\n";
						system("PAUSE");

						break;
					case 4:
						checkin();
						system("CLS");
						bill();
						cout << "\n\n";
						system("PAUSE");
						system("CLS");

						break;

					case 9: {
						j = 1;
						system("pause");
						break;
					}
					default: {
						cout << "\n\n\t\tINVALID SELECTION!" << endl;
						MainMenu();

						break;
					}
					case 5: {
						char a;
						custmer obj;
						do {
							cout<<"\n\t\t\t\t\t        ___________________"<<endl;
							cout<<"\t\t\t\t\t\t|                  |"<<endl;
							cout<<"\t\t\t\t\t\t|    1)Admin       |"<<endl;
							cout<<"\t\t\t\t\t\t|    2)Customer    |"<<endl;
							cout<<"\t\t\t\t\t\t|    0)Exit        |"<<endl;
							cout<<"\t\t\t\t\t\t|                  |"<<endl;
							cout<<"\t\t\t\t\t\t|__________________|"<<endl;
							cout<<"\t\t\t\t\t\tPress 1 for Admin, 2 for Customer:";
							cin>>a;
							switch(a) {
								case '0':
									break;
								case '1':
									system("CLS");
									checkin();
									obj.admin();
									break;
								case '2':
									system("CLS");
									obj.bill();
									break;
							}
						} while(a!='0');

					}

					case 7: {
						system("CLS");
						checkin();
						system("CLS");
						vector<Donation> donations;
						readDonations(donations, "bloodbank.txt");
						cout << "Available blood types: ";
						vector<string> bloodTypes;
						for (const auto& donation : donations) {
							if (donation.available) {
								if (find(bloodTypes.begin(), bloodTypes.end(), donation.bloodType) == bloodTypes.end()) {
									bloodTypes.push_back(donation.bloodType);
									cout << donation.bloodType << " ";
								}
							}
						}
						cout << endl;
						string patientBloodType;
						cout << "Enter patient's blood type: ";
						cin >> patientBloodType;

						bool foundDonation = false;
						for (auto& donation : donations) {
							if (donation.available && donation.bloodType == patientBloodType) {
								donation.available = false;
								cout << "Donation given to patient." << endl;
								foundDonation = true;
								break;
							}
						}

						if (!foundDonation) {
							cout << "No matching donation found." << endl;
						} else {
							writeDonations(donations, "bloodbank.txt");
						}

						// Ask for new donation
						char response;
						cout << "Do you want to add a donation? (Y/N): "<<endl;
						cin>>response;
						{
							if(response=='Y') {
								do {
									addDonation(donations, "bloodbank.txt");
									cout << "Do you want to add a new donation? (Y/N): "<<endl;
									cin >> response;
								} while(response=='Y');
							}
							system("CLS");
							continue;
						}
						break;
					}

					case 8: {
						system("CLS");
						checkin();
						system("CLS");
						vector<Staff> staffs;
						readStaff(staffs, "stafff.txt");
						cout << "Available staff types: ";
						vector<string> staffTypes;
						for (const auto& staff : staffs) {
							if (staff.available) {
								if (find(staffTypes.begin(), staffTypes.end(), staff.staffType) == staffTypes.end()) {
									staffTypes.push_back(staff.staffType);
									cout << staff.staffType << " ";
								}
							}
						}
						cout << endl;
						string patientstaffType;
						cout << "Enter Required Staff Type for the Task: ";
						cin >> patientstaffType;

						bool foundstaff = false;
						for (auto& staff : staffs) {
							if (staff.available && staff.staffType == patientstaffType) {
								staff.available = false;
								cout << "Staff Member Assigned." << endl;
								foundstaff = true;
								break;
							}
						}

						if (!foundstaff) {
							cout << "Staff Type Unavailable." << endl;
						} else {
							writeStaff(staffs, "stafff.txt");
						}

						// Ask for new donation
						char response;
						cout << "Do you want to add a new Staff Member? (Y/N): "<<endl;
						cin>>response;
						{
							if(response=='Y') {
								do {
									addStaff(staffs, "stafff.txt");
									cout << "Do you want to add a new Staff Member? (Y/N): "<<endl;
									cin >> response;
								} while(response=='Y');
							}
							system("CLS");
							continue;
						}
						break;
					}



					case 6: {
						char a;
						customer obj;
						do {
							cout<<"\n\t\t\t\t\t        ___________________"<<endl;
							cout<<"\t\t\t\t\t\t|                  |"<<endl;
							cout<<"\t\t\t\t\t\t|    1)Admin       |"<<endl;
							cout<<"\t\t\t\t\t\t|    2)Customer    |"<<endl;
							cout<<"\t\t\t\t\t\t|    0)Exit        |"<<endl;
							cout<<"\t\t\t\t\t\t|                  |"<<endl;
							cout<<"\t\t\t\t\t\t|__________________|"<<endl;
							cout<<"\t\t\t\t\t\tPress 1 for Admin, 2 for Customer:";
							cin>>a;
							switch(a) {
								case '0':
									break;
								case '1':
									system("CLS");
									checkin();
									obj.admin();
									break;
								case '2':
									system("CLS");
									obj.bill();
									break;
							}
						} while(a!='0');

						break;
					}
				}
			}
			system("CLS");
		}

};
int main()
{
	system("color F");
	MainMenu obj;
	return 0;
};
