with recursive t as (
    select id, parent_id, 1 as gen
    from ecoli_data
    where parent_id is null
    
    union all
    
    select b.id, b.parent_id, t.gen + 1
    from ecoli_data b
    join t on b.parent_id = t.id
)
select count(distinct case when c.id is null then t.id end) as COUNT, gen as GENERATION
from t
left join ecoli_data c on t.id = c.parent_id
group by gen
order by gen