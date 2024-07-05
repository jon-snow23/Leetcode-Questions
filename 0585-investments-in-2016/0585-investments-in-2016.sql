# Write your MySQL query statement below
SELECT ROUND(SUM(x.tiv_2016),2) as tiv_2016
FROM(
    SELECT *, count(pid) over(partition by tiv_2015) as countpid, 
    COUNT(pid) over(partition by lat, lon) as countloc
    FROM Insurance
) x
WHERE x.countpid>1 and x.countloc=1;