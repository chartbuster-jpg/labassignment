create database CollegeDB ; 
use  CollegeDB ;
create table Student(
StudentID int primary key,
Name varchar(30),
Department varchar(30),
Semester int
);

create table Course(
CourseID int primary key,
CourseName varchar(30),
Credits float
);


insert into Student(StudentID,Name,Department,Semester)
values
(101,'Rahul','CSE',3),
(102,'Priya','ECE',3),
(103,'Rohan','IT',5),
(104,'Neha','ME',7),
(105,'Amit','CE',1),
(106,'Rahul','ECE',2);

insert into Course(CourseID,CourseName,Credits)
values
(201,'Database System',4),
(202,'Data Structures',4),
(203,'Operating Systems',3),
(204,'Computer Networks',3),
(205,'Discrete Mathematics',4);

select* from Student ;
select * from Course ;

show databases ;
show tables ;

describe Student ;
describe Course ;

update Student
set Department = 'MME'
where StudentID = 104 ;

delete from Student 
where StudentID = 105 ;
select * from Student ;


alter table Student
add PhoneNumber bigint ;
desc Student ;

alter table Student
modify Department varchar(50) ;
desc Student ;

alter table Student
change column Semester CurrentSemster int ;
desc Student ;

alter table Student 
drop column PhoneNumber ;
desc Student ;

alter table Student 
rename to Student_Record ;
show tables ;

truncate table Course ;
select * from Course ;

insert into Course
values
(201,'DBMS',4),
(202,'DSA',3) ;
select * from Course ;

drop table Student_Record ;
show tables ;

drop table Course;
show tables ;

drop database CollegeDB ;
show databases ;



