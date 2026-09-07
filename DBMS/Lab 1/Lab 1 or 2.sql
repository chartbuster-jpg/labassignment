create database if not exists StudentDB ;
use StudentDB ; 
show databases ; 
select database();
drop database StudentDB ; 
create database if not exists StudentDB  ;
use StudentDB ;
create table Student 
(
StudentID int primary key ,
Name varchar(50) ,
Branch varchar(50),
Semester int not null 
); 

describe Student ;
insert into Student(StudentID, Name, Branch , Semester) 
values
(1,'Aditya','CSE',3),
(2,'Aditya','Cse',3),
(3,'Aryan','cse',3),
(4,'Manas','ece',2),
(5,'Aryan','ece',1);

select * from Student ; 
insert into Student(StudentID, Name, Branch, Semester)
values(6,'Aadesh','mme',1) ;
update Student 
set Semester = 3
where StudentID = 5 ; 

delete from Student 
where StudentID = 2 ; 
select * from Student ; 

create table if not exists Student_Info(
StudentID int primary key,
Name varchar(50),
Branch varchar(50) 
);

create table if not exists Student_Marks(
StudentID int primary key,
Marks int
);

select * from Student_Info ; 