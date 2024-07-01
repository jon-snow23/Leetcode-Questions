select  e1.name from Employee e1 ,employee e2
 where e1.id =e2.managerId  
GROUP BY e1.id 
HAVING COUNT(e2.id) >= 5;