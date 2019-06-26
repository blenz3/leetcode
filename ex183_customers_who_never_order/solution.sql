/* Write your T-SQL query statement below */
SELECT
    c.Name as Customers
FROM
    Customers c LEFT JOIN Orders o ON c.Id = o.CustomerId
WHERE
    o.Id is NULL