To understand this, you need to understand rank and dense rank.
# Rank
Say you have these `(name,salary)` rows in table T as
```
(A,100), (B,200), (C,200)
```
Then
the result of query
```
select *,rank() over(order by salary desc) as sal_rank from T
```
will be
```
(B,200,1),(C,200,1),(A,100,3)
```
ie in case of clash same rank is given to all clashing and some ranks will be skipped.

However `dense_rank` query
```
select *,dense_rank() over(order by salary desc) as sal_rank from T
```
will give following output
```
(B,200,1),(C,200,1),(A,100,2)
```
ie same rank is given for clash similar to `rank()` but no ranks are skipped.

Other trick to know is `partition by` inside the `over()` argument in `dense_rank()` function, just add `partition by dept` then, the ranks will be for people having same value of `dept`.

# SQL code:

```
select department,employee,salary from (
select *, dense_rank() over (partition by department order by salary desc) as sal_rank from 
(select E.name as employee,D.name as department,E.salary from employee E inner join department D on E.departmentid = D.id) as T1
) as T2
where T2.sal_rank<=3
```