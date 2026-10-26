SELECT (SELECT DISTINCT salary as SecondHighestSalary
FROM Employee
ORDER BY salary DESC
LIMIT 1 OFFSET 1)
as SecondHighestSalary