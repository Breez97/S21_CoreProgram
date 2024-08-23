WITH orders AS (
	SELECT
		ps.name AS name,
		mn.pizza_name AS pizza_name
	FROM
		person_order po
		JOIN menu mn ON po.menu_id = mn.id
		JOIN person ps ON po.person_id = ps.id
	WHERE
		ps.gender = 'female'
)
SELECT
	name
FROM
	orders
WHERE
	pizza_name = 'pepperoni pizza'
INTERSECT
SELECT
	name
FROM
	orders
WHERE
	pizza_name = 'cheese pizza'
ORDER BY
	name;