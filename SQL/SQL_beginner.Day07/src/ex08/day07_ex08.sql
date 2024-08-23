SELECT 
	ps.address AS address,
	pz.name AS name,
	COUNT(po.*) AS count_of_orders
FROM person_order po
JOIN person ps ON ps.id = po.person_id
JOIN menu mn ON mn.id = po.menu_id
JOIN pizzeria pz ON pz.id = mn.pizzeria_id
GROUP BY ps.address, pz.name
ORDER BY ps.address, pz.name;