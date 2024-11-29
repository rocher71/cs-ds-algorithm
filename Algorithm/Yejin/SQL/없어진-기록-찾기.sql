-- 코드를 입력하세요
SELECT B.animal_id, B.name
from animal_ins A
right join animal_outs B on A.animal_id = B.animal_id
where A.animal_id is null
order by B.animal_id
