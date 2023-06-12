---
layout: mypost
title: "Department Top Three Salaries - Dense rank"
tags: ["Database", "Hard"]
---
# Problem Statement:
<p>Table: <code>Employee</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| id           | int     |
| name         | varchar |
| salary       | int     |
| departmentId | int     |
+--------------+---------+
id is the primary key column for this table.
departmentId is a foreign key of the ID from the <code>Department </code>table.
Each row of this table indicates the ID, name, and salary of an employee. It also contains the ID of their department.
</pre>

<p>&nbsp;</p>

<p>Table: <code>Department</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the ID of a department and its name.
</pre>

<p>&nbsp;</p>

<p>A company&#39;s executives are interested in seeing who earns the most money in each of the company&#39;s departments. A <strong>high earner</strong> in a department is an employee who has a salary in the <strong>top three unique</strong> salaries for that department.</p>

<p>Write an SQL query to find the employees who are <strong>high earners</strong> in each of the departments.</p>

<p>Return the result table <strong>in any order</strong>.</p>

<p>The query result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> 
Employee table:
+----+-------+--------+--------------+
| id | name  | salary | departmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 85000  | 1            |
| 2  | Henry | 80000  | 2            |
| 3  | Sam   | 60000  | 2            |
| 4  | Max   | 90000  | 1            |
| 5  | Janet | 69000  | 1            |
| 6  | Randy | 85000  | 1            |
| 7  | Will  | 70000  | 1            |
+----+-------+--------+--------------+
Department table:
+----+-------+
| id | name  |
+----+-------+
| 1  | IT    |
| 2  | Sales |
+----+-------+
<strong>Output:</strong> 
+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Max      | 90000  |
| IT         | Joe      | 85000  |
| IT         | Randy    | 85000  |
| IT         | Will     | 70000  |
| Sales      | Henry    | 80000  |
| Sales      | Sam      | 60000  |
+------------+----------+--------+
<strong>Explanation:</strong> 
In the IT department:
- Max earns the highest unique salary
- Both Randy and Joe earn the second-highest unique salary
- Will earns the third-highest unique salary

In the Sales department:
- Henry earns the highest salary
- Sam earns the second-highest salary
- There is no third-highest salary as there are only two employees
</pre>

# Solution:
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