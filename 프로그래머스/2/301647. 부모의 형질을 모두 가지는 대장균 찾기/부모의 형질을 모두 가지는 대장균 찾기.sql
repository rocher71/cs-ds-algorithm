# select k.id, k.parent_id, k.genotype, conv(k.genotype, 10, 2), conv(p.genotype, 10, 2), 
#     right(conv(k.genotype, 10, 2), char_length(conv(p.genotype, 10, 2)))
# from ecoli_data k
# left join ecoli_data p on k.parent_id = p.id
# where conv(p.genotype, 10, 2) = right(conv(k.genotype, 10, 2), char_length(conv(p.genotype, 10, 2)))
# order by k.id

select k.id, k.genotype, p.genotype as parent_genotype
from ecoli_data k
join ecoli_data p on k.parent_id = p.id
where (k.genotype & p.genotype) = p.genotype
order by k.id