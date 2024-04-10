SELECT Emp.name AS Employee
FROM Employee Emp JOIN Employee Manager  
ON Emp.managerId = Manager.id
WHERE emp.salary > Manager.salary

