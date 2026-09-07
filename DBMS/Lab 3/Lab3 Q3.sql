create database HospitalDB ;
use HospitalDB ;

create table Doctor(
DoctorID varchar(50) primary key,
DoctorName varchar(50),
Specialization varchar(50));


create table Patient(
PatientID int primary key,
PatientName varchar(50),
Age int,
DoctorID varchar(50),
foreign key(DoctorID) references Doctor(DoctorID) );

show tables ;

insert into Doctor(DoctorID,DoctorName,Specialization)
values 
('D101','Dr.Sharma','Physician'),
('D102','Dr.Mehta','Neurologist'),
('D103','Dr.Patel','Orthopedic'),
('D104','Dr.Singh','Pediatrician'),
('D105','Dr.Rao','Dermatologist') ;

insert into Patient(PatientID ,PatientName ,Age ,DoctorID)
values 
(101,'Rahul',22,'D101'),
(102,'Priya',20,'D102'),
(103,'Amit',24,'D103'),
(104,'Neha',23,'D104'),
(105,'Karan',21,'D105') ;

select * from Doctor ;
select * from Patient ;

select 
 Patient.PatientID ,
  Patient.PatientName,
   Patient.Age,
Doctor.DoctorName,
Doctor.Specialization
From Patient
inner join Doctor  on Doctor.DoctorID = Patient.DoctorID ;

update Doctor
set Specialization = 'Cardiologist'
where DoctorID = 'D101' ;

select 
 Patient.PatientID ,
  Patient.PatientName,
   Patient.Age,
Doctor.DoctorName,
Doctor.Specialization
From Patient
inner join Doctor  on Doctor.DoctorID = Patient.DoctorID ;

delete from Patient 
where PatientID = 105 ;

select 
 Patient.PatientID ,
  Patient.PatientName,
   Patient.Age,
Doctor.DoctorName,
Doctor.Specialization
From Patient
inner join Doctor  on Doctor.DoctorID = Patient.DoctorID ;