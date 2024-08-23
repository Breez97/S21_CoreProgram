SELECT total_cost, '{' || full_path || '}' AS tour
FROM result_tour
WHERE total_cost = (SELECT MIN(total_cost) FROM result_tour)
UNION
SELECT total_cost, '{' || full_path || '}' AS tour
FROM result_tour
WHERE total_cost = (SELECT MAX(total_cost) FROM result_tour)
ORDER BY total_cost, tour;