CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE M INT;
SET M = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT(salary) FROM Employee ORDER BY salary DESC LIMIT 1 OFFSET M
      
      # SELECT DISTINCT e1.salary EROM Employee e1 WHERE N-1 = (SELECT COUNT(DISTINCT e2.salary) from Employee e2 WHERE e1.salary < es.Salary)
  );
END