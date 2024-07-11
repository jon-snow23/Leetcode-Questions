# Write your MySQL query statement below
SELECT 
    "Low Salary" AS category, 
    SUM(if(income < 20000,1,0)) AS accounts_count
FROM 
    Accounts
UNION 
SELECT 
    "Average Salary" AS category, 
    SUM(if(income >= 20000 AND income <= 50000,1,0)) AS accounts_count
FROM 
    Accounts
UNION 
SELECT 
    "High Salary" AS category, 
    SUM(if(income > 50000,1,0)) AS accounts_count
FROM 
    Accounts
ORDER BY 
    accounts_count DESC;