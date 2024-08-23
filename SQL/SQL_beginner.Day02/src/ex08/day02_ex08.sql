SELECT
	ps.name AS name
FROM
	person ps
	JOIN person_order po ON po.person_id = ps.id
	JOIN menu mn ON po.menu_id = mn.id
WHERE
	ps.gender = 'male'
	AND (
		ps.address = 'Moscow'
		OR ps.address = 'Samara'
	)
	AND (
		mn.pizza_name = 'pepperoni pizza'
		OR mn.pizza_name = 'mushroom pizza'
	)
ORDER BY
	name DESC;