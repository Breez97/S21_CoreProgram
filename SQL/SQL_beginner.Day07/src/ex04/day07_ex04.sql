SELECT 
	ps.name AS name,
	COUNT(pv.*) AS count_of_visits
FROM person_visits pv
JOIN person ps ON ps.id = pv.person_id
GROUP BY ps.name
HAVING COUNT(pv.*) > 3;