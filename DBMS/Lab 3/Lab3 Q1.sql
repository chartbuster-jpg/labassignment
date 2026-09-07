CREATE DATABASE college;
USE college;
create table Student (
	RNo int primary key,
    Name varchar(100) not null,
    Age int,
    Gender varchar(100) not null
);

create table Course(
	Cid int primary key,
    Cname varchar(100) not null,
    Credit int
);

insert into Student(RNo,Name,Age,Gender)
values (101, 'Aditi', 20, 'Male'),
	   (102, 'Aryan', 20, 'Male'),
       (103, 'Yash', 19, 'Male'),
       (104, 'Jaishikhs', 19, 'Female'),
       (105, 'Khushi', 18, 'Female');
       
insert into Course(Cid,Cname,Credit)
values (201, 'DBMS', 4),
	   (202, 'PPL', 3),
       (203, 'CP', 4),
       (204, 'Maths', 2),
       (205, 'EG', 1);
       
create table Enroll (
	Eid int primary key,
	RNo int,
	Cid int unique,
    foreign key (RNo) references Student(RNo),
    foreign key (Cid) references Course(Cid)
);
insert into Enroll(Eid,RNo,Cid)
values (1,101,201),
	   (2,102,202),
       (3,103,203),
       (4,104,204),
       (5,105,205);

select*from Student;
select*from Course;
select*from Enroll;

select
    s.RNo, s.Name, s.Age, s.Gender, e.Eid, e.Cid
from Student s
join Enroll e
on s.RNo = e.RNo;

select
    c.Cid, c.cname, c.Credit, e.Eid, e.Cid
from Course c
join Enroll e
on c.Cid = e.Cid;

select
    s.RNo, s.Name, s.Age, s.Gender, e.Eid, c.Cid, c.Cname, c.Credit
from Student s
join Enroll e
on s.RNo = e.RNo
join Course c
on e.Cid = c.Cid;