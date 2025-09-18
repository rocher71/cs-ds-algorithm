select count(*) as FISH_COUNT
from fish_info a
join fish_name_info b on a.fish_type = b.fish_type
where fish_name in ('BASS', 'SNAPPER')