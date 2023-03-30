# Write your MySQL query statement below

select department,employee,salary from (
select *, dense_rank() over (partition by department order by salary desc) as sal_rank from 
(select E.name as employee,D.name as department,E.salary from employee E inner join department D on E.departmentid = D.id) as T1
) as T2
where T2.sal_rank<=3