select apnt_no, pt_name, a.pt_no, a.mcdp_cd, dr_name, apnt_ymd
from appointment a
join patient b on a.pt_no = b.pt_no
join doctor c on a.mddr_id = c.dr_id
where year(apnt_ymd) = 2022
        and month(apnt_ymd) = 4
        and day(apnt_ymd) = 13
        and apnt_cncl_yn = 'N'
order by apnt_ymd