# Write your MySQL query statement below
SELECT D.name AS Department, E.name AS Employee, (E.salary) AS Salary
FROM Employee E, Department D
WHERE E.departmentId = D.id AND (E.departmentId, E.salary) IN (SELECT departmentID, MAX(salary) FROM Employee GROUP BY departmentId);