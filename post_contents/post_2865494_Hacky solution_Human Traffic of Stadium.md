
```
select distinct st.id,visit_date,st.people from stadium st join
(
    select * from
    (
        select id,people from stadium where people >= 100
    ) as T1
    inner join
    (
        select (id-1) as id2, people as people2 from stadium
    ) as T2
    inner join
    (
        select (id-2) as id3, people as people3 from stadium
    ) as T3
    on 
    T1.id = T2.id2 and T1.id=T3.id3
    where people2>=100 and people3>=100
) as T4
on st.id=T4.id or st.id-1=T4.id or st.id-2=T4.id
order by visit_date asc
```