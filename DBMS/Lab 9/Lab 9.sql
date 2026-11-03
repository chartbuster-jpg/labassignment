
CREATE DATABASE University_Fee_DB;
USE University_Fee_DB;

CREATE TABLE Student_Fee (
    Student_ID INT PRIMARY KEY,
    Student_Name VARCHAR(50) NOT NULL,
    Total_Fee DECIMAL(10,2) NOT NULL,
    Paid_Fee DECIMAL(10,2) NOT NULL DEFAULT 0,
    Balance DECIMAL(10,2)
);

DESC Student_Fee;



CREATE TRIGGER calculate_balance_insert
BEFORE INSERT ON Student_Fee
FOR EACH ROW
SET NEW.Balance = NEW.Total_Fee - NEW.Paid_Fee;

CREATE TRIGGER calculate_balance_update
BEFORE UPDATE ON Student_Fee
FOR EACH ROW
SET NEW.Balance = NEW.Total_Fee - NEW.Paid_Fee;


INSERT INTO Student_Fee
(Student_ID, Student_Name, Total_Fee, Paid_Fee)
VALUES
(101, 'Amit', 50000, 30000),
(102, 'Neha', 50000, 50000),
(103, 'Rahul', 60000, 20000),
(104, 'Pooja', 45000, 15000),
(105, 'Arjun', 70000, 25000);

SELECT * FROM Student_Fee;


INSERT INTO Student_Fee
(Student_ID, Student_Name, Total_Fee, Paid_Fee, Balance)
VALUES
(106, 'Kavya', 50000, 10000, 99999);

SELECT * FROM Student_Fee;



UPDATE Student_Fee
SET Paid_Fee = 40000
WHERE Student_ID = 101;
select * from Student_fee 
where Student_ID = 101 ;

UPDATE Student_Fee
SET Paid_Fee = 35000
WHERE Student_ID = 103;
select * from Student_fee 
where Student_ID = 103 ;

UPDATE Student_Fee
SET Total_Fee = 55000
WHERE Student_ID = 102;
select * from Student_fee 
where Student_ID = 102 ;

UPDATE Student_Fee
SET Paid_Fee = Paid_Fee + 2000
WHERE Student_ID IN (104, 105);
select * from Student_fee 
WHERE Student_ID IN (104, 105);



UPDATE Student_Fee
SET Balance = 999
WHERE Student_ID = 101;
select * from Student_fee 
where Student_ID = 101 ;

SELECT * FROM Student_Fee;




SHOW TRIGGERS FROM University_Fee_DB;

SHOW CREATE TRIGGER calculate_balance_insert;

SHOW CREATE TRIGGER calculate_balance_update;




DELETE FROM Student_Fee
WHERE Student_ID = 106;

SELECT * FROM Student_Fee;