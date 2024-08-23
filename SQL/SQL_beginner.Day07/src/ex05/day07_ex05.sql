SELECT 
	DISTINCT ps.name AS name 
FROM person_order po
JOIN person ps ON ps.id = po.person_id
ORDER BY ps.name;