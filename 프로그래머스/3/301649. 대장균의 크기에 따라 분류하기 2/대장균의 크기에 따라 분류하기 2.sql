# select id, size_of_colony, NTILE(4) OVER (ORDER BY SIZE_OF_COLONY DESC)
# from ecoli_data
# order by id

select id, 
    case NTILE(4) OVER (ORDER BY SIZE_OF_COLONY DESC)
        when 1 then 'CRITICAL'
        when 2 then 'HIGH'
        when 3 then 'MEDIUM'
        when 4 then 'LOW'
    end as colony_name
from ecoli_data
order by id