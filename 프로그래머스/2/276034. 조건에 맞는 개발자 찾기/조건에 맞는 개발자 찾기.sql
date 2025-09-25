# select id, conv(skill_code, 10, 2), name, conv(code, 10, 2), skill_code & code
# from developers
# join skillcodes
# where (name = 'C#' or name = 'Python') and (skill_code & code) != 0
# order by id

select distinct ID, EMAIL, FIRST_NAME, LAST_NAME
from developers
join skillcodes
where (name = 'C#' and ((skill_code & code) != 0))
    or (name = 'Python' and ((skill_code & code) != 0))
order by id