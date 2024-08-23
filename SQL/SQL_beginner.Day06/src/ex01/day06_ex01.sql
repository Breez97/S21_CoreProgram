INSERT INTO person_discounts (id, person_id, pizzeria_id, discount)
SELECT 
	ROW_NUMBER() OVER() as id, 
	po.person_id, 
	mn.pizzeria_id,
	CASE
		WHEN COUNT(po.person_id) = 1 THEN 10.5
		WHEN COUNT(po.person_id) = 2 THEN 22
		ELSE 30
	END as discount
FROM person_order po
JOIN menu mn ON po.menu_id = mn.id
GROUP BY po.person_id, mn.pizzeria_id
ORDER BY po.person_id;