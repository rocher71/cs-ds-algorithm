-- 코드를 입력하세요
SELECT A.animal_id, A.animal_type, A.name
from animal_ins A
join animal_outs B on A.animal_id = B.animal_id
where substring(A.sex_upon_intake, 1, 6) = 'Intact'
    and (substring(B.sex_upon_outcome, 1, 6) = 'Spayed' 
        or substring(B.sex_upon_outcome, 1, 8) = 'Neutered')
order by A.animal_id
