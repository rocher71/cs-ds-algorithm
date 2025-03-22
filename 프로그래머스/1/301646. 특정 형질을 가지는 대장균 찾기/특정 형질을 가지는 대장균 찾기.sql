select count(*) as count
from ecoli_data
where genotype = 1
    or conv(genotype, 10, 2) like '%01' 
         or conv(genotype, 10, 2) like '%10_'