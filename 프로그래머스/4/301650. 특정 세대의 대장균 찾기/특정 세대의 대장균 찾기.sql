select c.id
from ecoli_data c
join (select a.id, a.parent_id
    from ecoli_data a
    join ecoli_data b on a.parent_id = b.id) d on c.parent_id = d.id
join ecoli_data e on d.parent_id = e.id
where e.parent_id is null
order by c.id