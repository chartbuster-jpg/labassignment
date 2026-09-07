create database DB_Student;

use DB_Student;

create table Student(
    Sid varchar(30) primary key,
    Sname varchar(30),
    DOB varchar(30)
);

create table Course(
    Cid varchar(30) primary key,
    Cname varchar(30),
    Instructor varchar(30)
);

create table Enroll(
    Sid varchar(30),
    Cid varchar(30),
    Grade varchar(30),
    foreign key (Sid) references Student(Sid),
    foreign key (Cid) references Course(Cid)
);

insert into Student values
('S1', 'Rahul', '2003-05-10'),
('S2', 'Neha', '2004-02-15'),
('S3', 'Amit', '2001-11-20'),
('S4', 'Priya', '2002-08-12'),
('S5', 'Rohan', '2003-01-25'),
('S6', 'Kavya', '2000-06-18');

insert into Course values
('C1', 'DBMS', 'Navathe'),
('C2', 'CN', 'Korth'),
('C3', 'OS', 'Navathe'),
('C4', 'AI', 'Ullman'),
('C5', 'IS', 'Stallings');

insert into Enroll values
('S1','C1','A'),
('S1','C2','A'),
('S1','C3','B'),
('S1','C4','A'),
('S1','C5','B'),
('S2','C1','A'),
('S2','C2','B'),
('S2','C3','A'),
('S3','C1','B'),
('S3','C3','A'),
('S3','C5','A'),
('S4','C2','A'),
('S4','C4','A'),
('S4','C5','B'),
('S5','C1','C'),
('S5','C2','B'),
('S5','C3','A'),
('S5','C5','B'),
('S6','C4','C'),
('S6','C5','A');


select count(*)
from Student;

select count(*)
from Course;

select count(*)
from Enroll;


select C.Cid, C.Cname, count(E.Sid) count
from Course C
join Enroll E
where C.Cid = E.Cid
group by C.Cid, C.Cname;


select avg(
    case
        when Grade = 'A' then 90
        when Grade = 'B' then 80
        when Grade = 'C' then 70
    end
) average
from Enroll;


select C.Cid, C.Cname,
max(
    case
        when Grade = 'A' then 90
        when Grade = 'B' then 80
        when Grade = 'C' then 70
    end
) ,
min(
    case
        when Grade = 'A' then 90
        when Grade = 'B' then 80
        when Grade = 'C' then 70
    end
)
from Course C
join Enroll E on C.Cid = E.Cid
group by C.Cid, C.Cname;


select C.Instructor, count(C.Instructor)
from Course C
group by C.Instructor;


select C.Instructor, count(E.Sid)
from Course C
join Enroll E on C.Cid = E.Cid
group by C.Instructor;


