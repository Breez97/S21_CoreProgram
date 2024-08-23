SELECT 
	pz.name AS name,
	COUNT(po.*) AS count_of_orders,
	ROUND(AVG(mn.price), 2) AS average_price,
	MAX(mn.price) AS max_price,
	MIN(mn.price) AS min_price
FROM person_order po
JOIN menu mn ON mn.id = po.menu_id
JOIN pizzeria pz ON pz.id = mn.pizzeria_id
GROUP BY pz.name
ORDER BY pz.name;