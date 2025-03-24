select a.id, count(b.id) as child_count
    # case 
    #     when b.id is null then 0
    #     else count(b.id)
    # end
-- select a.id, a.parent_id, b.id, b.parent_id
from ecoli_data a
left join ecoli_data b on a.id = b.parent_id
group by a.id