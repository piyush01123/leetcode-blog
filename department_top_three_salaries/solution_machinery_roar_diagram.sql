# Write your MySQL query statement below

select dept as department,name as employee, salary from (
select *, dense_rank() over (partition by dept order by salary desc) as sal_rank from 
(select E.name,D.name as dept,E.salary from employee E inner join department D on E.departmentid = D.id) as T1
) as T2
where T2.sal_rank<=3