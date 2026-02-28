select d.author_id, d.author_name, category, sum(c.price * c.sales) as TOTAL_SALES
from author d
join (
    select a.book_id, b.author_id, sales_date, category, price, sales
    from book_sales a
    join book b on a.book_id = b.book_id
    ) c on c.author_id = d.author_id
where year(sales_date) = 2022
    and month(sales_date) = 1
group by author_name, category
order by d.author_id, category desc