/* Write your T-SQL query statement below */
SELECT
    e.Name as Employee
FROM Employee e LEFT JOIN (
    SELECT 
        Id as managerId2,
        Salary as managerSalary
    FROM
        Employee
    ) as t
    on e.ManagerId = t.managerId2
WHERE
    Salary > managerSalary
