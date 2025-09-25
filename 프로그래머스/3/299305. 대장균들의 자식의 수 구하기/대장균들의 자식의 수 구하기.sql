select a.id as ID, count(b.id) as CHILD_COUNT
from ecoli_data a
left join ecoli_data b on a.id = b.parent_id
group by a.id