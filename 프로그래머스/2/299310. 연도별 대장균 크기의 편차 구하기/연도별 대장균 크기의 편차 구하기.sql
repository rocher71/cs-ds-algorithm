# select year(DIFFERENTIATION_DATE) as year_b
# from ecoli_data b
# join (
#     select *
#     from (select size_of_colony,
#           rank() over(partition by year(DIFFERENTIATION_DATE)
#                          order by size_of_colony desc) as ranking,
#           year(differentiation_date) as year_a
#         from ecoli_data) a
#     where a.ranking = 1) c on b.year_b = c.year_a
    
select 
year(b.differentiation_date) as YEAR, c.size_of_colony - b.size_of_colony as YEAR_DEV, id
from ecoli_data b
join (
    select *
    from (select size_of_colony,
          rank() over(partition by year(DIFFERENTIATION_DATE)
                         order by size_of_colony desc) as ranking,
          differentiation_date
        from ecoli_data) a
    where a.ranking = 1) c on year(b.differentiation_date) = year(c.differentiation_date)
order by YEAR, YEAR_DEV


