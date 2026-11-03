CREATE DATABASE Hospital_View_DB;
USE Hospital_View_DB;
CREATE TABLE Patient (
    Patient_ID INT PRIMARY KEY,
    Patient_Name VARCHAR(50) NOT NULL,
    Department VARCHAR(30) NOT NULL,
    Age INT NOT NULL,
    Treatment_Cost DECIMAL(10,2) NOT NULL
);

DESCRIBE Patient;
INSERT INTO Patient
(Patient_ID, Patient_Name, Department, Age, Treatment_Cost)
VALUES
(101, 'Amit', 'Cardiology', 45, 25000.00),
(102, 'Neha', 'Neurology', 32, 18000.00),
(103, 'Rahul', 'Cardiology', 50, 12000.00),
(104, 'Pooja', 'Orthopedics', 28, 30000.00),
(105, 'Arjun', 'Cardiology', 60, 40000.00),
(106, 'Kavya', 'Neurology', 38, 22000.00),
(107, 'Rohan', 'Orthopedics', 25, 10000.00),
(108, 'Priya', 'Cardiology', 42, 16000.00),
(109, 'Meera', 'Neurology', 55, 35000.00),
(110, 'Karan', 'Orthopedics', 48, 14000.00);

SELECT * FROM Patient
ORDER BY Patient_ID ASC;
CREATE VIEW Patient_Basic_View AS
SELECT Patient_ID, Patient_Name, Department
FROM Patient;

SELECT * FROM Patient_Basic_View;
CREATE VIEW Cardiology_Patient_View AS
SELECT *
FROM Patient
WHERE Department = 'Cardiology';

SELECT * FROM Cardiology_Patient_View
ORDER BY Patient_ID ASC;
CREATE VIEW High_Cost_View AS
SELECT Patient_ID, Patient_Name, Department, Treatment_Cost
FROM Patient
WHERE Treatment_Cost >= 20000;

SELECT * FROM High_Cost_View
ORDER BY Treatment_Cost DESC;
UPDATE Cardiology_Patient_View
SET Treatment_Cost = 28000
WHERE Patient_Name = 'Amit';

SELECT * FROM Patient
WHERE Patient_Name = 'Amit';
UPDATE Patient
SET Treatment_Cost = 23000
WHERE Patient_ID = 103;

SELECT * FROM High_Cost_View
ORDER BY Treatment_Cost DESC;
CREATE OR REPLACE VIEW Patient_Basic_View AS
SELECT Patient_ID, Patient_Name, Department, Age
FROM Patient;

SELECT * FROM Patient_Basic_View;

SHOW CREATE VIEW Patient_Basic_View;
DROP VIEW Patient_Basic_View;

SELECT * FROM Patient;