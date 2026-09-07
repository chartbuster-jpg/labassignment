create database StudentDB ;
use StudentDB ;
create table Student(
StudentID int primary key unique not null ,
Name varchar(50) not null ,
Gender Enum ('Male','Female','Other'),
Age tinyint ,
cgpa decimal(4,2),
JoiningDate date ,
LoginTime time
);

insert into Student(StudentID,Name,Gender,Age,cgpa,JoiningDate,LoginTime)
values
(1,'Rahul Sharma','Male',23,8.45,'2024-06-15','09:15:00'),
(2,'Priya Verma','Female',22,9.10,'2023-08-20','10:05:00'),
(3,'Amit Patel','Male',24,7.85,'2022-01-10','08:45:00'),
(4,'Neha Singh','Female',21,8.75,'2025-01-25','11:20:00'),
(5,'Karan Rao','Male',25,7.40,'2021-09-05','09:50:00'),
(6,'Anjali Mehta','Female',23,8.95,'2024-11-12','12:10:00');

select * from Student ;

select * from Student 
where Gender = 'Female' and age<24 ;

select name, year(JoiningDate) from student ;
select Name, month(JoiningDate) , monthname(JoiningDate), day(JoiningDate), dayname(JoiningDate) from student ;
select curdate() ;
select name, datediff(curdate(),JoiningDate) from student ;
select StudentID , Name , JoiningDate , year(joiningDate) from student
where joiningdate > '2023-12-31' ;
select StudentID,name,joiningDate , datediff(curdate(),joiningDate) from student 
where datediff(curdate(),joiningDate) > 1000 ;