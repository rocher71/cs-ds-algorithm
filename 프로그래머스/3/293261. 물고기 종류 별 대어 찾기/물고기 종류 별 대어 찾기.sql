select id, fish_name, length
from (
    select id, fish_type, rank() over(partition by fish_type order by length desc, length) as ranking, length
    from fish_info
) a
join fish_name_info b on a.fish_type = b.fish_type
where a.ranking = 1
order by id