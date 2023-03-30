CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      select case when ctr<N then NULL else (select min(salary) from (select distinct salary from Employee order by salary desc limit N) as E) end as col from (select count(distinct salary) as ctr  from Employee) as E
  );
END