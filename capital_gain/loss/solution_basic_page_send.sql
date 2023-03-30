# Write your MySQL query statement below
select buys.stock_name, tot_sell-tot_buy as capital_gain_loss  from
(
    (select stock_name, sum(price) as tot_buy from stocks where operation='Buy' group by stock_name) as buys
    inner join
    (select stock_name, sum(price) as tot_sell from stocks where operation='Sell' group by stock_name) as sells
    on buys.stock_name = sells.stock_name
)
