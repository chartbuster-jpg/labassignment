create database CompDetails ;
use CompDetails ;

create table Employee(
Eid int primary key,
Ename varchar(50)) ;

create table Child(
Eid int,
Name varchar(50),
Age int,
Gender varchar(30),
primary key(Eid,name),
foreign key(Eid) references Employee(Eid)
);

show tables ;

insert into Employee(Eid,Ename)
values
(101,'Anand'),
(102,'Ajay'),
(103,'Mitesh'),
(104,'Nikhil'),
(105,'Rahul');

insert into Child(Eid,name,Age,Gender)
values
(101,'Anandi',4,'Female'),
(101,'Harsh',2,'Male'),
(102,'Krish',3,'Male'),
(104,'Madhav',6,'Male'),
(105,'Ayush',8,'Male');

select * from Employee ;
select * from Child ;

