select a.id, b.fish_name, a.length
from fish_info a
join fish_name_info b on a.fish_type = b.fish_type
where (a.fish_type, a.length) in (select fish_type, max(length)
                                    from fish_info
                                    group by fish_type)
order by a.id