# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary FROM EMPLOYEE where salary < (SELECT MAX(salary) FROM EMPLOYEE);