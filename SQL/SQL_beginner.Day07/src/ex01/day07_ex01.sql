SELECT
	ps.name,
	COUNT(pv.*) AS count_of_visits
FROM person_visits pv
JOIN person ps ON ps.id = pv.person_id
GROUP BY ps.name
ORDER BY count_of_visits DESC, ps.name
LIMIT 4;